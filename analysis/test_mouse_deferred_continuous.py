from pathlib import Path
import ctypes as C,struct,json,hashlib
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
class HW(C.Structure):_fields_=[('ram',Ptr),('radio',Ptr),('timer',Ptr),('rtc',Ptr),('aux',Ptr),('nvic',Ptr),('clock',C.POINTER(W)),('image',Ptr)]
class Pending(C.Structure):_fields_=[('entry',W),('args',W*5)]
f=C.CDLL(str(A/'libmouse_rtc_deferred.dylib'))
f.rr_mouse_work_thread_runtime.argtypes=[Ptr,Ptr,Ptr,W,C.POINTER(CPU)]
f.rr_mouse_delayed_work_schedule.argtypes=[Ptr,Ptr,W,W,C.c_uint64,C.c_int,C.POINTER(CPU),C.POINTER(C.c_int32)]
f.rr_mouse_rtc_dispatch_deferred.argtypes=[C.POINTER(HW),C.POINTER(CPU),C.POINTER(Pending)]
f.rr_mouse_timer_start.argtypes=[Ptr,Ptr,W,C.c_uint64,C.c_uint64]
def w(b,o,v):struct.pack_into('<I',b,o,v&0xffffffff)
def r(b,o):return struct.unpack_from('<I',b,o)[0]
def q(b,o):return struct.unpack_from('<Q',b,o)[0]
image=(U*201044).from_buffer_copy((R/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin').read_bytes())
results=[]
for channel in [7,13,14,15]:
 m=bytearray(65536);radio=bytearray(4096);timer=bytearray(1536);rtc=bytearray(4096);aux=bytearray(16);nvic=bytearray(4096);clock=(W*2)();cpu=CPU();pending=Pending();value=C.c_int32()
 for off,ptr in [(0x14f4,0x230014f4),(0x14f8,0x230014f4),(0x2530,0x23002530),(0x2534,0x23002530),(0x2538,0x23002538),(0x253c,0x23002538),(0x7668,0x23002498),(0x766c,0x23002498),(0x2498,0x23007668),(0x249c,0x23007668),(0x7654,0x23002498),(0x7658,0x23002378),(0x7664,0x23002498),(0x67c4,0x23025df1),(0x67c8,0x23002498),(0x67e8,0x23002498),(0x1b60,0x23001b60),(0x1b64,0x23001b60),(0x12fc,0x23028c09)]:w(m,off,ptr)
 m[0x24a5]=128;w(m,0x2540,0x101);m[0x1304]=channel;start=0xffffffe0 if channel==15 else 0;w(m,0x21c0,start);w(rtc,0x770,start)
 buffers=[(U*len(b)).from_buffer(b) for b in [m,radio,timer,rtc,aux,nvic]];hw=HW(*buffers,clock,image);mb,rb,ab=buffers[0],buffers[3],buffers[4]
 reschedules=0
 for cycle in range(32):
  cpu.exception_number=0;cpu.priority=0
  assert f.rr_mouse_work_thread_runtime(mb,rb,ab,0x23002498,C.byref(cpu))==1 and cpu.entry==0xe089d4c
  assert r(m,0x24a0)==0x23002530 and m[0x24a5]==2
  # Explicit external CPU handoff; exception/context switching is not tested here.
  w(m,0x7654,0x23002378);cpu.priority=0;cpu.exception_number=0
  delay=[1,2,8,32][cycle%4]
  assert f.rr_mouse_delayed_work_schedule(mb,rb,0x23002498,0x230067c0,delay,0,C.byref(cpu),C.byref(value))==0 and value.value==1
  if cycle%2==0:
   assert f.rr_mouse_delayed_work_schedule(mb,rb,0x23002498,0x230067c0,delay+3,1,C.byref(cpu),C.byref(value))==0 and value.value==1
   reschedules+=1
  assert r(m,0x67cc)==8 and r(m,0x67d0)!=0
  deadline=q(rtc,0x520+channel*16);assert deadline>q(rtc,0x770)
  # Supply compare event and INTENSET readback; dispatch executes all callbacks.
  w(rtc,0x770,deadline);w(rtc,0x774,deadline>>32);w(rtc,0x350,r(rtc,0x350)|r(rtc,0x354));w(rtc,0x100+channel*4,1);cpu.exception_number=125
  assert f.rr_mouse_rtc_dispatch_deferred(C.byref(hw),C.byref(cpu),C.byref(pending))==0
  assert pending.entry==0 and r(m,0x7680)==0 and r(m,0x67cc)==4 and r(m,0x67d0)==0
  assert r(m,0x2528)==r(m,0x252c)==0x230067c0 and m[0x24a5]==128
  assert r(m,0x2530)==r(m,0x2534)==0x23002530 and r(m,0x7664)==0x23002498
  w(m,0x7654,0x23002498);cpu.exception_number=0;cpu.priority=0
  assert f.rr_mouse_work_thread_runtime(mb,rb,ab,0x23002498,C.byref(cpu))==0
  assert r(m,0x67cc)==0 and r(m,0x2528)==r(m,0x252c)==0
  assert r(m,0x14f4)==r(m,0x14f8)==0x230014f4
 results.append({'channel':channel,'cycles':32,'active_reschedules':reschedules})
paths=[Path(__file__),P/'mouse_deferred_work.c',P/'mouse_deferred_work.h',P/'mouse_rtc_dispatch.c',P/'mouse_rtc_dispatch.h',A/'libmouse_rtc_deferred.dylib']
d={'status':'PASS','scenarios':4,'cycles':128,'active_reschedules':64,'explicit_RTC_events':128,'indirect_delayed_callbacks':128,'worker_next_loop_segments':128,'explicit_context_handoffs':256,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'results':results,'not_added_to_original_input_count':True,'limits':['Clock/event/INTENSET readback and CPU handoffs are explicit environmental inputs','No direct delayed callback invocation: actual schedule/rearm and RTC announce policy dispatch it','No hardware exception timing, live RF or complete firmware boot']}
(A/'mouse-deferred-continuous-comparison.json').write_text(json.dumps(d,indent=2)+'\n');print(json.dumps({k:v for k,v in d.items() if k not in ['sources','results']},indent=2))
