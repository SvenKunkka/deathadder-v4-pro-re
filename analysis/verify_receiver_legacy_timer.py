#!/usr/bin/env python3
import base64,ctypes as C,gzip,hashlib,json,subprocess,tempfile
from pathlib import Path
B=Path(__file__).resolve().parents[1];U=C.c_uint8;P=C.POINTER(U)
class HW(C.Structure):_fields_=[('radio',C.c_uint32*1024),('timer',C.c_uint32*512),('aux',C.c_uint32*512),('nvic_last',C.c_uint32),('nvic_requests',C.c_uint32)]
class CPU(C.Structure):_fields_=[('priority',C.c_uint32),('exception_number',C.c_uint32),('entry',C.c_uint32),('arg0',C.c_uint32)]
def uz(s):return gzip.decompress(base64.b64decode(s))
MODULES=['receiver_legacy_timer','receiver_legacy_radio','receiver_legacy_business','receiver_rtos_lifecycle','receiver_timeout','receiver_radio_timer','receiver_radio_irq','receiver_business_flow','business_dispatch','business_rx','business_cipher','business_control','business_tx','dongle_business_consumer','handshake']
def build(dest):subprocess.run(['/usr/bin/cc','-std=c11','-Wall','-Wextra','-Werror','-O2','-shared','-fPIC',*[str(B/f'recovered-code/portable/{m}.c') for m in MODULES],'-o',str(dest)],check=True)
def main():
 with tempfile.TemporaryDirectory(prefix='rlt-') as t:
  dest=Path(t)/'lib.dylib';build(dest);lib=C.CDLL(str(dest));lib.rr_receiver_legacy_timer.argtypes=[P,P,C.POINTER(HW),C.c_uint,P,C.POINTER(CPU),P]
  raw=(B/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();flash=(U*len(raw)).from_buffer_copy(raw)
  fail=[];counts={};steps=0;calls={k:0 for k in ['sem','puts','purges','aborts','starts','notices']};boundaries=0;bymode={}
  for line in (B/'analysis/receiver-legacy-timer-original.jsonl').read_text().splitlines():
   d=json.loads(line);ram=(U*131072).from_buffer_copy(uz(d['before_gzip']));h=HW();cpu=CPU(d['initial_priority'],d['exception'],0,0)
   for name,n in [('radio',4096),('timer',2048),('aux',2048)]:C.memmove(getattr(h,name),uz(d[name+'_before_gzip']),n)
   h.nvic_last=0x12345678;tail=(U*48).from_buffer_copy(bytes.fromhex(d['opaque_tails']));rtc=(U*4096).from_buffer_copy(uz(d['rtc_before_gzip']));err=[]
   def compare(actual,expect,stage,addr=0x23000000):
    if actual!=expect:
     diff=[i for i,(a,b) in enumerate(zip(actual,expect)) if a!=b];err.append({'stage':stage,'count':len(diff),'bytes':[(hex(addr+i),actual[i],expect[i]) for i in diff[:16]]})
   rc=lib.rr_receiver_legacy_timer(ram,flash,C.byref(h),d['mode'],rtc,C.byref(cpu),tail)
   if rc!=int(bool(d['boundary'])):err.append({'return':rc,'expected_boundary':d['boundary']})
   for name,actual,addr in [('after',bytes(ram),0x23000000),('radio_after',bytes(h.radio),0x5302c000),('timer_after',bytes(h.timer),0x53028000),('aux_after',bytes(h.aux),0x5300e000),('rtc_after',bytes(rtc),0x5f99c000)]:compare(actual,uz(d[name+'_gzip']),name,addr)
   if h.nvic_last!=d['nvic_after']:err.append({'nvic':h.nvic_last,'expected':d['nvic_after']})
   if cpu.entry!=d['boundary']:err.append({'boundary':cpu.entry,'expected':d['boundary']})
   if cpu.arg0!=d['arg0']:err.append({'arg0':cpu.arg0,'expected':d['arg0']})
   if cpu.priority!=d['final_priority']:err.append({'priority':cpu.priority,'expected':d['final_priority']})
   if err:fail.append({'case':d['case'],'op':d['op'],'mode':d['mode'],'event':d['event'],'variant':d['variant'],'errors':err})
   counts[str(d['op'])]=counts.get(str(d['op']),0)+1;bymode[str(d['mode'])]=bymode.get(str(d['mode']),0)+1;steps+=d['steps'];boundaries+=bool(d['boundary'])
   for k in calls:calls[k]+=d[k]
  sources={fn:hashlib.sha256((B/fn).read_bytes()).hexdigest() for fn in [*[f'recovered-code/portable/{m}.c' for m in MODULES],'recovered-code/portable/receiver_legacy_timer.h','analysis/verify_receiver_legacy_timer.py','analysis/receiver-legacy-timer-original.jsonl','ghidra-scripts/EmulateReceiverLegacyTimer.java']}
  report={'status':'PASS' if not fail else 'FAIL','cases':sum(counts.values()),'by_operation':counts,'by_mode':bymode,'original_steps':steps,'original_calls':calls,'full_returns':sum(counts.values())-boundaries,'context_switch_boundaries':boundaries,'checks':['all131072 RAM bytes','RADIO4096B TIMER2048B auxiliary2048B RTC4096B','NVIC last word','CPU BASEPRI and pending entry/arg0'],'failures':fail,'sources':sources,'limits':['snapshot MMIO; no PHY/DPPI/time/preemption simulation','notification unused24B stack tail supplied per peer with explicit original environment provenance','active timeout cancellation/timeslice/notification execute real instructions, no success stubs','context-switch boundary has no automatic model continuation; re-entering IRQ is not resume','direct TIMER entries; root global3230 gate is outside this API','no actual hardware operation']}
  (B/'analysis/receiver-legacy-timer-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']}));print(json.dumps(fail[:8],indent=2));assert not fail
if __name__=='__main__':main()
