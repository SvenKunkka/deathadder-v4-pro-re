#!/usr/bin/env python3
import base64,ctypes as C,gzip,hashlib,json,subprocess,tempfile
from pathlib import Path
B=Path(__file__).resolve().parents[1];U=C.c_uint8;P=C.POINTER(U)
class Pending(C.Structure):_fields_=[('active',U),('peer',U),('metadata',U),('reserved',U),('device',C.c_uint32)]
class HW(C.Structure):_fields_=[('radio',C.c_uint32*1024),('timer',C.c_uint32*512),('aux',C.c_uint32*512),('nvic_last',C.c_uint32),('nvic_requests',C.c_uint32)]
def uz(s):return gzip.decompress(base64.b64decode(s))
def main():
 modules=['receiver_radio_irq','receiver_business_flow','business_dispatch','business_rx','business_cipher','business_control','business_tx','dongle_business_consumer']
 with tempfile.TemporaryDirectory(prefix='rri-') as t:
  dest=Path(t)/'lib.dylib';subprocess.run(['/usr/bin/cc','-std=c11','-Wall','-Wextra','-Werror','-O2','-shared','-fPIC',*[str(B/f'recovered-code/portable/{m}.c') for m in modules],'-o',str(dest)],check=True)
  lib=C.CDLL(str(dest));lib.rr_receiver_radio_irq.argtypes=[P,P,C.POINTER(HW)];lib.rr_receiver_timer_cc1.argtypes=[P,C.POINTER(HW)];lib.rr_receiver_radio_swi4.argtypes=[P,P,C.POINTER(HW),C.POINTER(Pending)]
  raw=(B/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();flash=(U*len(raw)).from_buffer_copy(raw)
  fail=[];counts={};steps=0
  for line in (B/'analysis/receiver-radio-irq-original.jsonl').read_text().splitlines():
   d=json.loads(line);ram=(U*65536).from_buffer_copy(uz(d['before_gzip']));h=HW();C.memmove(h.radio,uz(d['radio_before_gzip']),4096);C.memmove(h.timer,uz(d['timer_before_gzip']),2048);h.nvic_last=0x12345678
   rc=lib.rr_receiver_timer_cc1(ram,C.byref(h)) if d['op']==1 else lib.rr_receiver_radio_irq(ram,flash,C.byref(h));err=[]
   if rc:err.append({'return':rc})
   if d['op']==2:
    p=Pending();rc=lib.rr_receiver_radio_swi4(ram,flash,C.byref(h),C.byref(p))
    if rc:err.append({'swi_return':rc})
   for name,actual,addr in [('after',bytes(ram),0x23000000),('radio_after',bytes(h.radio),0x5302c000),('timer_after',bytes(h.timer),0x53028000),('aux_after',bytes(h.aux),0x5300e000)]:
    expect=uz(d[name+'_gzip'])
    if actual!=expect:
     diff=[i for i,(a,b) in enumerate(zip(actual,expect)) if a!=b];err.append({'stage':name,'count':len(diff),'bytes':[(hex(addr+i),actual[i],expect[i]) for i in diff[:16]]})
   if h.nvic_last!=d['nvic_after']:err.append({'nvic':h.nvic_last,'expected':d['nvic_after']})
   if h.nvic_requests!=d['requests']:err.append({'requests':h.nvic_requests,'expected':d['requests']})
   if err:fail.append({'case':d['case'],'op':d['op'],'variant':d['variant'],'errors':err})
   counts[str(d['op'])]=counts.get(str(d['op']),0)+1;steps+=d['steps']
  sources={fn:hashlib.sha256((B/fn).read_bytes()).hexdigest() for fn in [*[f'recovered-code/portable/{m}.c' for m in modules],'analysis/receiver-radio-irq-original.jsonl','ghidra-scripts/EmulateReceiverRadioIrq.java']}
  report={'status':'PASS' if not fail else 'FAIL','cases':sum(counts.values()),'by_operation':counts,'original_steps':steps,'checks':['all65536 RAM bytes','RADIO4096B TIMER2048B auxiliary2048B','NVIC last word and notification masks'],'failures':fail,'sources':sources,'limits':['snapshot MMIO; no PHY/DPPI/time simulation','TIMER CC1 selected branch only','SWI4 invoked separately after original RADIO IRQ return; not automatic NVIC dispatch','no actual hardware operation']}
  (B/'analysis/receiver-radio-irq-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']}));print(json.dumps(fail[:8],indent=2));assert not fail
if __name__=='__main__':main()
