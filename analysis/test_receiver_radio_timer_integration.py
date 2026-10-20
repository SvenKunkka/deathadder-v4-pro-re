#!/usr/bin/env python3
"""Explicit event-sequence C integration, not original instructions or RF."""
import ctypes as C,json,tempfile,subprocess
from pathlib import Path
from verify_receiver_radio_timer import B,U,P,HW,Pending,TimerPending,uz
modules=['receiver_radio_timer','receiver_radio_irq','receiver_business_flow','business_dispatch','business_rx','business_cipher','business_control','business_tx','dongle_business_consumer']
def p16(r,a,v):r[a]=v&255;r[a+1]=(v>>8)&255
def p32(r,a,v):
 for i in range(4):r[a+i]=(v>>(i*8))&255
def u16(r,a):return r[a]|r[a+1]<<8
with tempfile.TemporaryDirectory(prefix='rrt-sequence-') as t:
 dest=Path(t)/'lib.dylib';subprocess.run(['/usr/bin/cc','-std=c11','-Wall','-Wextra','-Werror','-O2','-shared','-fPIC',*[str(B/f'recovered-code/portable/{m}.c') for m in modules],'-o',str(dest)],check=True)
 lib=C.CDLL(str(dest));lib.rr_receiver_timer_mode4.argtypes=[P,P,C.POINTER(HW),C.POINTER(TimerPending)];lib.rr_receiver_radio_irq.argtypes=[P,P,C.POINTER(HW)];lib.rr_receiver_radio_swi4.argtypes=[P,P,C.POINTER(HW),C.POINTER(Pending)]
 raw=(B/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();f=(U*len(raw)).from_buffer_copy(raw)
 baseline=next(json.loads(line) for line in (B/'analysis/receiver-radio-timer-original.jsonl').read_text().splitlines() if json.loads(line)['event']==0 and json.loads(line)['variant']==1)
 counts={'scenarios':0,'timer_events':0,'valid_rx_business':0,'disconnect_boundaries':0};details=[]
 for mode in range(4):
  for initial in [0,98]:
   for traffic in [False,True]:
    r=(U*65536).from_buffer_copy(uz(baseline['before_gzip']));h=HW();p16(r,0x3230,3);p16(r,0x3234,4);p16(r,0x323e,mode);p16(r,0x3470,initial);p16(r,0x5376,0);p16(r,0x32ca,0);p32(r,0x33e8,3);p32(r,0x52f0,3);p32(r,0x3468,11);p32(r,0x5370,13);r[0x325d]=0;p32(r,0x3474,0)
    def tick(event):
     for k in range(8):h.timer[(0x140+4*k)//4]=0
     h.timer[(0x140+4*event)//4]=1;h.timer[0x55c//4]=0
     pending=TimerPending();rc=lib.rr_receiver_timer_mode4(r,f,C.byref(h),C.byref(pending));counts['timer_events']+=1
     if rc==1:assert pending.entry==0x0e06d0d0 and pending.arg0==0x23001c54 and pending.active==1
     else:assert rc==0
     return rc
    end=0
    for period in range(1,121):
     assert tick(0)==0;assert tick(1)==0;assert u16(r,0x32d0)==1
     if traffic:
      # Explicit observed-environment packet/event; no automatic radio success.
      p32(r,0x3468,12);r[0x3050]=8;r[0x3051]=0x80|(((period-1)%7+1)<<4);r[0x3052]=1;r[0x3053]=0x2c;r[0x3054]=1;r[0x3055]=0;r[0x3056]=2;r[0x3057]=0;r[0x3058]=(-sum(r[0x3051:0x3058]))&255
      h.radio[0x218//4]=1;h.radio[0x22c//4]=1;h.radio[0x220//4]=1
      assert lib.rr_receiver_radio_irq(r,f,C.byref(h))==0
      pending=Pending();assert lib.rr_receiver_radio_swi4(r,f,C.byref(h),C.byref(pending))==0;assert u16(r,0x3470)==0;counts['valid_rx_business']+=1
     assert tick(2)==0;assert tick(1)==0;assert tick(2)==0;assert tick(1)==0;assert tick(2)==0;assert tick(1)==0;assert tick(2)==0;assert tick(1)==0
     end=tick(2);assert u16(r,0x5376)==period
     if end:assert not traffic and period==100-initial;counts['disconnect_boundaries']+=1;break
     assert u16(r,0x3470)==(1 if traffic else initial+period);assert tick(1)==0
    if traffic:assert period==120 and end==0
    else:assert end==1 and u16(r,0x3234)==2
    counts['scenarios']+=1;details.append({'mode':mode,'initial_failures':initial,'traffic':traffic,'periods':period,'disconnect':bool(end)})
 out={'status':'PASS','component_integration':counts,'cases':details,'original_instruction_cases_added':0,'limits':['events, CC7 and successful RX are explicit environment inputs','disconnect ends before actual RTOS semaphore-give','no time/RF/DPPI emulation']};(B/'analysis/receiver-radio-timer-integration.json').write_text(json.dumps(out,indent=2)+'\n');print(json.dumps(counts))
