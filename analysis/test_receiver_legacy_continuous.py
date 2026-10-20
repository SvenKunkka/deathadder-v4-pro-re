#!/usr/bin/env python3
"""C component composition, explicitly not an additional original/RF dataset."""
import ctypes as C,json,tempfile,hashlib
from pathlib import Path
import verify_receiver_legacy_timer as V
B=V.B;U=V.U;P=V.P;HW=V.HW;CPU=V.CPU
class Pending(C.Structure):_fields_=[('active',U),('selected_peer',U),('forward_peer',U),('metadata',U),('device',C.c_uint32)]
def main():
 with tempfile.TemporaryDirectory(prefix='rlt-chain-') as t:
  path=Path(t)/'lib.dylib';V.build(path);lib=C.CDLL(str(path))
  lib.rr_receiver_legacy_timer.argtypes=[P,P,C.POINTER(HW),C.c_uint,P,C.POINTER(CPU),P]
  lib.rr_receiver_legacy_radio.argtypes=[P,C.POINTER(HW),C.c_uint,C.POINTER(CPU),P,P]
  lib.rr_receiver_legacy_radio_swi.argtypes=[P,P,C.c_uint,C.POINTER(Pending)]
  lib.rr_bt_init.argtypes=[P,C.c_int,C.c_uint];lib.rr_bt_enqueue.argtypes=[P,C.c_int,C.c_uint,C.c_uint,P,C.c_uint32,C.c_uint16]
  raw=(B/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();f=(U*len(raw)).from_buffer_copy(raw);results=[]
  for scenario in range(24):
   mode=2 if scenario%3==2 else 1;interval=1 if scenario%3==0 else 4;r=(U*131072)();C.memmove(r,raw[0x1c854:0x1c854+0x1e08],0x1e08);h=HW();cpu=CPU(0,60,0,0);rtc=(U*4096)();tails=(U*48)();pad=(U*2)()
   def s16(a,n):r[a]=n&255;r[a+1]=n>>8&255
   def s32(a,n):
    for i in range(4):r[a+i]=n>>(i*8)&255
   def u16(a):return r[a]|r[a+1]<<8
   def u32(a):return sum(r[a+i]<<(8*i) for i in range(4))
   s16(0x3230,3);s16(0x3234,mode);s16(0x341c,interval);s16(0x323e,scenario%2);r[0x5353]=4
   for ch in range(2):
    for k in range(4):r[0x534b+4*ch+k]=2+ch*8+k*2
   for peer in range(3):
    b=0x33e8+peer*0xf84;lib.rr_bt_init(r,0,peer);s32(b,3);s32(b+0x80,13 if peer==2 else 12);r[b+0x69]=1;r[b+0x9b]=255;s16(b+0x96,0)
   timers=radios=swis=pops255=0
   def timer(e):
    nonlocal timers
    for i in range(8):h.timer[(0x140+4*i)//4]=int(i==e)
    assert lib.rr_receiver_legacy_timer(r,f,C.byref(h),mode,rtc,C.byref(cpu),tails)==0;assert not cpu.entry;timers+=1
   def receive(peer,seq,duplicate=False):
    nonlocal radios,swis,pops255
    b=0x33e8+peer*0xf84;assert u32(b+0x80)==12
    was=u16(b+0x96);oldseq=r[b+0x9b];off=b+255+0x15a;old=r[off];cap=r[b+255+0x160]
    # Inject one real input packet/event snapshot. No automatic task/event model.
    for i,x in enumerate([7,0x80|(seq<<4),1,0x17,0,0,0,0,0,0,0,0,0,0,0,0]):r[0x3050+i]=x
    for a in [0x218,0x220,0x22c]:h.radio[a//4]=1
    h.nvic_requests=0
    assert lib.rr_receiver_legacy_radio(r,C.byref(h),mode,C.byref(cpu),tails,pad)==0
    assert h.nvic_requests==0x10000000 and u16(0x71a4)==peer and u32(b+0x80)==11
    if was==255:
     want=old if oldseq==seq else (0 if ((old+1)&255)==cap else (old+1)&255)
     assert r[off]==want
     if oldseq!=seq:pops255+=1
    assert u16(b+0x96)==0
    p=Pending();assert lib.rr_receiver_legacy_radio_swi(r,f,mode,C.byref(p))==0;assert not p.active
    radios+=1;swis+=1
   # queue-free rounds force actual timer sentinel; populated rounds exercise peek/pop.
   for cycle in range(12):
    seq=1+cycle%7
    if cycle%3==0:
     for peer in range(2 if mode==2 else 1):
      body=(U*3)(0,0x44,cycle);assert lib.rr_bt_enqueue(r,0,peer,1,body,3,0xff)==1
    timer(0);receive(0,seq)
    if mode==2:
     timer(1);timer(2);receive(1,seq);timer(1);assert u16(0x32d0)==2
     assert h.radio[0xed0//4]==0x23003070;assert r[0x3070]>0
     timer(2);timer(1);assert u16(0x32d0)==0
    elif interval==1:
     for slot in [1,2,3]:
      timer(1);timer(2);assert u16(0x32d0)==slot;receive(0,seq if slot<3 else (1+seq%7))
     timer(3);timer(1);assert u16(0x32d0)==4;timer(2);timer(1)
    else:
     timer(1);timer(2);timer(1);timer(2);receive(0,seq);timer(3);timer(1);timer(2);timer(1)
    assert u16(0x32d0)==0 and u16(0x3234)==mode
   results.append({'scenario':scenario,'mode':mode,'interval':interval,'cycles':12,'timer_events':timers,'radio_events':radios,'business_calls':swis,'sentinel255_new_ack_pop_projections':pops255})
  report={'status':'PASS','scope':'C component integration, not new original-instruction samples or RF test','scenarios':24,'cycles':288,'timer_events':sum(x['timer_events'] for x in results),'radio_events':sum(x['radio_events'] for x in results),'business_calls':sum(x['business_calls'] for x in results),'sentinel255_new_ack_pop_projections':sum(x['sentinel255_new_ack_pop_projections'] for x in results),'results':results,'checks':['three complete slot schedules return to slot0','explicit incoming snapshots reach real selected peer SWI','queued ACK selection and actual timer-generated255 pop projection','no fabricated hardware events or scheduler success'],'sources':{str(p.relative_to(B)):hashlib.sha256(p.read_bytes()).hexdigest() for p in [Path(__file__),*[B/f'recovered-code/portable/{m}.c' for m in V.MODULES]]}}
  (B/'analysis/receiver-legacy-continuous-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print({k:v for k,v in report.items() if k not in ['results','sources']})
if __name__=='__main__':main()
