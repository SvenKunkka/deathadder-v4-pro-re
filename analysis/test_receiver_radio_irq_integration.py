#!/usr/bin/env python3
"""C component integration; not extra original instruction or radio tests."""
import ctypes as C,json,tempfile,subprocess
from pathlib import Path
from verify_receiver_radio_irq import B,U,P,HW,Pending,uz
modules=['receiver_radio_irq','receiver_business_flow','business_dispatch','business_rx','business_cipher','business_control','business_tx','dongle_business_consumer']
def put16(r,a,v):r[a]=v&255;r[a+1]=v>>8
def put32(r,a,v):
 for i in range(4):r[a+i]=(v>>(i*8))&255
with tempfile.TemporaryDirectory(prefix='rri-integration-') as t:
 dest=Path(t)/'lib.dylib';subprocess.run(['/usr/bin/cc','-std=c11','-Wall','-Wextra','-Werror','-O2','-shared','-fPIC',*[str(B/f'recovered-code/portable/{m}.c') for m in modules],'-o',str(dest)],check=True)
 lib=C.CDLL(str(dest));lib.rr_receiver_radio_irq.argtypes=[P,P,C.POINTER(HW)];lib.rr_receiver_timer_cc1.argtypes=[P,C.POINTER(HW)];lib.rr_receiver_radio_swi4.argtypes=[P,P,C.POINTER(HW),C.POINTER(Pending)]
 raw=(B/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();flash=(U*len(raw)).from_buffer_copy(raw)
 count=queued=sync=late=0
 for line in (B/'analysis/receiver-radio-irq-original.jsonl').read_text().splitlines():
  d=json.loads(line)
  if d['op']!=2:continue
  r=(U*65536).from_buffer_copy(uz(d['before_gzip']));h=HW();C.memmove(h.radio,uz(d['radio_before_gzip']),4096);C.memmove(h.timer,uz(d['timer_before_gzip']),2048);h.nvic_last=0x12345678
  assert lib.rr_receiver_radio_irq(r,flash,C.byref(h))==0
  pending=Pending();assert lib.rr_receiver_radio_swi4(r,flash,C.byref(h),C.byref(pending))==0
  assert bytes(r)==uz(d['after_gzip']) # proven original IRQ+SWI result reused
  # Explicit subsequent environment event: slot1/4 CC1 with CC7 at/after deadline.
  slot=1 if d['variant']%4<2 else 4;cutoff=5280 if slot==1 else 13280;is_late=d['variant']%2
  put16(r,0x32d0,slot);put32(r,0x5370,13);h.timer[0x140//4]=0;h.timer[0x144//4]=1;h.timer[0x55c//4]=cutoff+is_late
  base=0x33e8;q=next((q for q in range(6) if r[base+0x154+q]!=r[base+0x15a+q]),None);rd=bytes(r[base+0x15a:base+0x160]);oldseq=r[0x5397];oldflag=r[0x3488];ch=int.from_bytes(bytes(r[0x32ca:0x32cc]),'little');fail=r[base+2*(ch+0xfcc)]
  if q is not None:
   entry=int.from_bytes(bytes(r[base+0x16c+4*q:base+0x170+4*q]),'little')-0x23000000+r[base+0x15a+q]*r[base+0x166+q];expect=bytearray(r[entry+4:entry+20]);expect[1]=(0x80|0x40|fail)&255;queued+=1
  else:
   expect=bytearray(r[0x53e4:0x53f4]);expect[0]=5;expect[1]=(0x80|(oldflag<<6)|fail)&255;expect[2]=oldseq;expect[3]=0x1f;expect[4]=r[0x5377];expect[5]=r[0x5376];sync+=1
  assert lib.rr_receiver_timer_cc1(r,C.byref(h))==0
  assert bytes(r[0x3070:0x3080])==bytes(expect)
  assert bytes(r[base+0x15a:base+0x160])==rd # prepare/peek does not pop again
  assert h.radio[0xed0//4]==0x23003070 and r[0x3484]==0 and h.timer[0x144//4]==0
  assert int.from_bytes(bytes(r[0x347e:0x3480]),'little')==(q if q is not None else 255)
  if q is not None:assert r[entry+2]==1
  else:assert r[0x5397]==(1 if ((oldseq+1)&255)==8 else (oldseq+1)&255)
  if is_late:assert h.radio[0x10//4]==1 and h.aux[0]==0;late+=1
  else:assert h.aux[0]==1 and h.aux[0x440//4]==1
  count+=1
 # Regression: stale NVIC last-store values must not manufacture requests.
 # Includes same-value actual write and preservation of preexisting request bits.
 regression=0
 for old_last in [0x08000000,0x10000000]:
  for old_requests in [0,0x00004000]:
   for length in [0,1,127,128]:
    for opcode in [0x2b,0x2c,0x55]:
     r=(U*65536)();h=HW();h.nvic_last=old_last;h.nvic_requests=old_requests
     put16(r,0x3234,4);r[0x34fc]=length;r[0x34fe]=1;r[0x34ff]=opcode
     p=Pending();assert lib.rr_receiver_radio_swi4(r,flash,C.byref(h),C.byref(p))==0
     writes=length in [1,127] and opcode==0x2b
     assert h.nvic_last==(0x08000000 if writes else old_last)
     assert h.nvic_requests==(old_requests|(0x08000000 if writes else 0))
     regression+=1
 result={'status':'PASS','component_cases':count,'nvic_write_action_regressions':regression,'queued_ack':queued,'sync_fallback':sync,'late_tx_cancel':late,'scope':'C IRQ -> C SWI4 business -> explicitly supplied subsequent TIMER CC1 event','original_instruction_cases_added':0,'limitations':['explicit slot/event/capture inputs, not automatic hardware or NVIC','no RF operation']}
 (B/'analysis/receiver-radio-irq-integration.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result))
