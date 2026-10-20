#!/usr/bin/env python3
import base64,ctypes as C,gzip,hashlib,json,subprocess,tempfile
from pathlib import Path
B=Path(__file__).resolve().parents[1];U=C.c_uint8;P=C.POINTER(U)
class Pending(C.Structure):_fields_=[('active',U),('selected_peer',U),('forward_peer',U),('metadata',U),('device',C.c_uint32)]
class HW(C.Structure):_fields_=[('radio',C.c_uint32*1024),('timer',C.c_uint32*512),('aux',C.c_uint32*512),('nvic_last',C.c_uint32),('nvic_requests',C.c_uint32)]
class CPU(C.Structure):_fields_=[('priority',C.c_uint32),('exception_number',C.c_uint32),('entry',C.c_uint32),('arg0',C.c_uint32)]
def uz(s):return gzip.decompress(base64.b64decode(s))
def main():
 modules=['receiver_legacy_radio','receiver_legacy_business','receiver_rtos_lifecycle','receiver_radio_timer','receiver_radio_irq','receiver_business_flow','business_dispatch','business_rx','business_cipher','business_control','business_tx','dongle_business_consumer','handshake']
 with tempfile.TemporaryDirectory(prefix='rlr-') as t:
  dest=Path(t)/'lib.dylib';subprocess.run(['/usr/bin/cc','-std=c11','-Wall','-Wextra','-Werror','-O2','-shared','-fPIC',*[str(B/f'recovered-code/portable/{m}.c') for m in modules],'-o',str(dest)],check=True)
  lib=C.CDLL(str(dest));lib.rr_receiver_legacy_radio.argtypes=[P,C.POINTER(HW),C.c_uint,C.POINTER(CPU),P,P];lib.rr_receiver_legacy_radio_swi.argtypes=[P,P,C.c_uint,C.POINTER(Pending)];lib.rr_receiver_legacy_resume.argtypes=[P,C.c_int32,C.POINTER(Pending)]
  raw=(B/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();flash=(U*len(raw)).from_buffer_copy(raw)
  fail=[];counts={};steps=0;tails=0;tailsteps=0;puts=0;purges=0;bymode={}
  for line in (B/'analysis/receiver-legacy-radio-original.jsonl').read_text().splitlines():
   d=json.loads(line);ram=(U*131072).from_buffer_copy(uz(d['before_gzip']));h=HW();cpu=CPU(d['initial_priority'],60,0,0)
   for name,n in [('radio',4096),('timer',2048),('aux',2048)]:C.memmove(getattr(h,name),uz(d[name+'_before_gzip']),n)
   h.nvic_last=d['nvic_before'];tail=(U*24).from_buffer_copy(bytes.fromhex(d['opaque_tail']));pad=(U*2).from_buffer_copy(bytes.fromhex(d['opaque_padding']));err=[]
   def compare(actual,expect,stage,addr=0x23000000):
    if actual!=expect:
     diff=[i for i,(a,b) in enumerate(zip(actual,expect)) if a!=b];err.append({'stage':stage,'count':len(diff),'bytes':[(hex(addr+i),actual[i],expect[i]) for i in diff[:16]]})
   rc=lib.rr_receiver_legacy_radio(ram,C.byref(h),d['mode'],C.byref(cpu),tail,pad)
   if rc:err.append({'irq_return':rc,'boundary':cpu.entry})
   compare(bytes(ram),uz(d['irq_gzip']),'irq')
   if d['op']==3:
    p=Pending();rc=lib.rr_receiver_legacy_radio_swi(ram,flash,d['mode'],C.byref(p))
    if rc!=int(d['pending']):err.append({'swi_return':rc,'expected':d['pending']})
    if d['pending'] and p.device!=d['device']:err.append({'device':p.device,'expected':d['device']})
   for name,actual,addr in [('after',bytes(ram),0x23000000),('radio_after',bytes(h.radio),0x5302c000),('timer_after',bytes(h.timer),0x53028000),('aux_after',bytes(h.aux),0x5300e000)]:compare(actual,uz(d[name+'_gzip']),name,addr)
   if h.nvic_last!=d['nvic_after']:err.append({'nvic':h.nvic_last,'expected':d['nvic_after']})
   if h.nvic_requests!=d['requests']:err.append({'requests':h.nvic_requests,'expected':d['requests']})
   if cpu.priority!=d['final_priority']:err.append({'priority':cpu.priority,'expected':d['final_priority']})
   if d['pending']:
    rc=lib.rr_receiver_legacy_resume(ram,d['driver_result'],C.byref(p));assert rc==0 and p.active==0;compare(bytes(ram),uz(d['continuation_gzip']),'external_USB_result_continuation');tails+=1
   if err:fail.append({'case':d['case'],'op':d['op'],'mode':d['mode'],'variant':d['variant'],'errors':err})
   counts[str(d['op'])]=counts.get(str(d['op']),0)+1;bymode[str(d['mode'])]=bymode.get(str(d['mode']),0)+1;steps+=d['steps'];tailsteps+=d['tail_steps'];puts+=d['puts'];purges+=d['purges']
  sources={fn:hashlib.sha256((B/fn).read_bytes()).hexdigest() for fn in [*[f'recovered-code/portable/{m}.c' for m in modules],'recovered-code/portable/receiver_legacy_radio.h','analysis/receiver-legacy-radio-original.jsonl','ghidra-scripts/EmulateReceiverLegacyRadio.java']}
  report={'status':'PASS' if not fail else 'FAIL','cases':sum(counts.values()),'by_operation':counts,'by_mode':bymode,'original_steps':steps,'original_message_put_calls':puts,'original_message_purge_calls':purges,'full_returns':sum(counts.values())-tails,'real_USB_boundary_cases':tails,'explicit_USB_return_continuations':tails,'continuation_steps':tailsteps,'checks':['all131072 RAM bytes at IRQ return and final SWI return/boundary','RADIO4096B TIMER2048B auxiliary2048B','NVIC last word and actual write request masks','CPU BASEPRI','USB pointer and delayed business tail'],'failures':fail,'sources':sources,'limits':['snapshot MMIO; no PHY/DPPI/time simulation','same-state SWI invoked explicitly after original IRQ return; not automatic NVIC dispatch','notification unused stack bytes supplied as explicit original environment provenance','real notification queue executes; these IRQ fixtures use no-waiter ring and full/purge/retry','USB0E0622BC not executed; separate explicit external-result continuation','RTOS timer/scheduler pending propagated through existing lifecycle contract; no reentry-as-resume','no actual hardware operation']}
  (B/'analysis/receiver-legacy-radio-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']}));print(json.dumps(fail[:8],indent=2));assert not fail
if __name__=='__main__':main()
