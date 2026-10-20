from pathlib import Path
import ctypes as C,struct,json,hashlib
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
class HW(C.Structure):_fields_=[('ram',Ptr),('radio',Ptr),('timer',Ptr),('rtc',Ptr),('aux',Ptr),('nvic',Ptr),('clock',C.POINTER(W)),('image',Ptr)]
f=C.CDLL(str(A/'libmouse_rtc_dispatch.dylib'))
for n in ['rr_mouse_scan_work']:getattr(f,n).argtypes=[C.POINTER(HW),C.POINTER(CPU)]
class Pending(C.Structure):_fields_=[('entry',W),('args',W*5)]
f.rr_mouse_rtc_dispatch.argtypes=[C.POINTER(HW),C.POINTER(CPU),C.POINTER(Pending)]
f.rr_mouse_work_thread_scanning.argtypes=[C.POINTER(HW),W,C.POINTER(CPU)]
def w(b,o,v):struct.pack_into('<I',b,o,v&0xffffffff)
def h(b,o,v):struct.pack_into('<H',b,o,v&0xffff)
def r(b,o):return struct.unpack_from('<I',b,o)[0]
image=bytearray((R/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin').read_bytes());img=(U*len(image)).from_buffer(image)
expected=[image[0x2ca14+image[0x2ca3c+i]] for i in range(4)];assert expected==[2,26,50,80]
results=[]
for start in range(4):
 m=bytearray(65536);radio=bytearray(4096);timer=bytearray(1536);rtc=bytearray(4096);aux=bytearray(16);nvic=bytearray(4096);clock=(W*2)()
 for off,ptr in [(0x14f4,0x230014f4),(0x14f8,0x230014f4),(0x1558,0x23001558),(0x155c,0x23001558),(0x2530,0x23002530),(0x2534,0x23002530),(0x2538,0x23002538),(0x253c,0x23002538),(0x7668,0x23007668),(0x766c,0x23007668),(0x7654,0x23002498),(0x7658,0x23005900),(0x7664,0x23002498),(0x385c,0x23022621),(0x1548,0xe096951),(0x1560,0x23022311)]:w(m,off,ptr)
 w(m,0x12fc,0x23028c09);w(m,0x1300,0x13572468);w(m,0x2540,0x101);m[0x1304]=7;m[0x27bb]=1;m[0x76ef]=3;h(m,0x2a4c,start);w(m,0x27ac,0x1234abcd);m[0x774b]=1
 buffers=[(U*len(b)).from_buffer(b) for b in [m,radio,timer,rtc,aux,nvic]];hw=HW(*buffers,clock,img);cpu=CPU(0,0,0,0);assert f.rr_mouse_scan_work(C.byref(hw),C.byref(cpu))==0
 cycles=[]
 for cycle in range(2):
  assert r(m,0x2998)==1000 and r(m,0x2978)==2 and r(m,0x2a04)==19
  seen=[];deadlines=[];cpu.exception_number=125
  first_index=struct.unpack_from('<H',m,0x2a4c)[0]
  for tick in range(1000):
   deadline=r(rtc,0x590)|(r(rtc,0x594)<<32)
   now=r(rtc,0x770)|(r(rtc,0x774)<<32)
   assert deadline>now,(start,cycle,tick,deadline,now)
   deadlines.append(deadline)
   w(rtc,0x770,deadline);w(rtc,0x774,deadline>>32)
   # Explicit test input: emulate only compare event and INTENSET readback.
   w(rtc,0x350,r(rtc,0x350)|r(rtc,0x354));w(rtc,0x11c,1)
   pending=Pending();rc=f.rr_mouse_rtc_dispatch(C.byref(hw),C.byref(cpu),C.byref(pending))
   assert rc==0,(start,cycle,tick,rc,hex(pending.entry))
   assert r(rtc,0x11c)==0 and r(m,0x7680)==0
   assert r(m,0x2998)==(999-tick if tick<999 else 1000)
   if tick<999 and r(m,0x2a04)==20 and struct.unpack_from('<H',m,0x2a4e)[0]==1:seen.append(r(radio,0x708))
  assert seen[:8]==[expected[(first_index+i)%4] for i in range(8)]
  assert r(m,0x2998)==1000 and r(m,0x2978)==0 and r(m,0x2a04)==0
  assert r(m,0x2528)==0x23003858 and r(m,0x3864)&4 and m[0x27bb]==1 and r(m,0x1540)==0
  assert r(radio,0xe30)==0x1234abcd and r(radio,0x500)==4
  cpu.exception_number=0
  assert f.rr_mouse_work_thread_scanning(C.byref(hw),0x23002498,C.byref(cpu))==0
  assert r(m,0x2528)==0 and r(m,0x252c)==0 and not(r(m,0x3864)&5) and m[0x27bb]==0
  assert r(m,0x1540)!=0 and r(m,0x2998)==1000 and r(m,0x2a04)==19
  cycles.append({'explicit_RTC_events':1000,'first_deadline':deadlines[0],'last_deadline':deadlines[-1],'first_eight_frequencies':seen[:8],'scanning_restarted':True})
 results.append({'initial_scan_index':start,'cycles':cycles})
paths=[Path(__file__),P/'mouse_rtc_dispatch.c',P/'mouse_rtc_dispatch.h',P/'mouse_scanning.c',P/'mouse_scanning.h',A/'libmouse_rtc_dispatch.dylib']
d={'status':'PASS','scenarios':4,'complete_timeout_restart_cycles':8,'explicit_RTC_compare_events':8000,'indirect_application_timer_callbacks':8000,'actual_worker_segments':8,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'results':results,'not_added_to_original_input_count':True,'limits':['C component integration only, not new original-instruction evidence','RTC clock and compare event plus INTENSET readback supplied explicitly; C dispatch invokes announce, timeout expiry and scanning callback; no automatic peripherals or CPU scheduling','No receiver, no radio events/RX packets, no real RF verification']}
(A/'mouse-rtc-continuous-comparison.json').write_text(json.dumps(d,indent=2)+'\n');print(json.dumps({k:v for k,v in d.items() if k not in ['results','sources']},indent=2))
