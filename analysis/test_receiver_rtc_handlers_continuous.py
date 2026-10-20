from pathlib import Path
import ctypes as C,struct,json,hashlib
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;I=C.c_int32;Ptr=C.POINTER(U)
f=C.CDLL(str(A/'libreceiver_rtc_handlers.dylib'))
class CPU(C.Structure):_fields_=[('priority',W),('exception',W),('entry',W),('arg0',W)]
class State(C.Structure):_fields_=[('mutex',W),('changed',W),('phase',W)]
class HW(C.Structure):_fields_=[('ram',Ptr),('rtc',Ptr)]
class Pending(C.Structure):_fields_=[('entry',W),('args',W*5)]
f.rr_receiver_mutex_lock.argtypes=[Ptr,Ptr,W,C.c_uint64,C.POINTER(CPU),C.POINTER(State),C.POINTER(I)]
f.rr_receiver_rtc_dispatch.argtypes=[C.POINTER(HW),C.POINTER(CPU),C.POINTER(Pending)]
for name in ['rr_receiver_switch_request_inert','rr_receiver_pendsv_body']:getattr(f,name).argtypes=[Ptr,Ptr,Ptr,C.POINTER(W)]
def w(b,o,v):struct.pack_into('<I',b,o,v&0xffffffff)
def q(b,o,v):struct.pack_into('<Q',b,o,v&0xffffffffffffffff)
def r(b,o):return struct.unpack_from('<I',b,o)[0]
results=[]
for cycle in range(128):
 m=bytearray(131072);rtc=bytearray(4096);nv=bytearray(4096);scratch=bytearray(32)
 mb=(U*len(m)).from_buffer(m);rb=(U*len(rtc)).from_buffer(rtc);nb=(U*len(nv)).from_buffer(nv);sb=(U*32).from_buffer(scratch);hw=HW(mb,rb)
 base=10000*cycle;delay=1+cycle*3;ch=[7,13,14,15][cycle%4]
 q(m,0x2840,base);q(m,0x2c78,base);q(rtc,0x770,base);w(m,0x958,0xe0683a1);m[0x960]=ch
 w(m,0xb48,0x23000b48);w(m,0xb4c,0x23000b48)
 w(m,0x7170,0x23006200);w(m,0x7174,0x23006400);w(m,0x717c,0x23006200)
 # Current requester priority1, existing owner priority5. Both initially ready.
 for t,priority in [(0x6200,1),(0x6000,5),(0x6400,127)]:
  m[t+0xe]=priority
  for k in range(8):w(m,t+0x30+k*4,0x51000000+t+k)
  w(m,t+0x50,0x2300a000+t);w(m,t+0x74,0x23009000+t);w(m,t+0x84,0x23003000+t//256)
 for t,nxt,prev in [(0x6200,0x6000,0x7180),(0x6000,0x7180,0x6200)]:
  m[t+0xd]=128;w(m,t,0x23000000+nxt);w(m,t+4,0x23000000+prev)
 w(m,0x7180,0x23006200);w(m,0x7184,0x23006000)
 w(m,0x7000,0x23007000);w(m,0x7004,0x23007000);w(m,0x7008,0x23006000);w(m,0x700c,1);w(m,0x7010,5)
 c=CPU(0,0,0,0);state=State();result=I(0x12345678)
 assert f.rr_receiver_mutex_lock(mb,rb,0x23007000,delay,C.byref(c),C.byref(state),C.byref(result))==1
 assert c.entry==0xe0611cc and state.phase==1 and result.value==0x12345678
 assert r(m,0x717c)==0x23006000 and r(m,0x6208)==0x23007000 and m[0x600e]==1
 assert r(m,0xb48)==0x23006218 and r(m,0x6220)==0xe06daf5 and r(m,0x7000)==0x23006200
 deadline=r(rtc,0x520+ch*16)|(r(rtc,0x524+ch*16)<<32);assert deadline==base+delay+1
 cpu=(W*24)();cpu[0]=c.arg0;cpu[13]=0x2302f000;cpu[14]=0x2302df01;cpu[15]=c.entry;cpu[16]=0x2300f000;cpu[18]=c.priority
 assert f.rr_receiver_switch_request_inert(mb,nb,sb,cpu)==0
 cpu[14]=0xfffffffd;cpu[15]=0xe06124c
 assert f.rr_receiver_pendsv_body(mb,nb,sb,cpu)==1 and r(m,0x7170)==0x23006000
 # Explicit compare-event/time/interrupt-enable inputs; hardware does not run.
 q(rtc,0x770,deadline);w(rtc,0x100+4*ch,1);w(rtc,0x350,1<<ch)
 c.priority=cpu[18];c.exception=125;pending=Pending()
 assert f.rr_receiver_rtc_dispatch(C.byref(hw),C.byref(c),C.byref(pending))==0
 assert not pending.entry and r(rtc,0x100+4*ch)==0 and r(m,0xb48)==0x23000b48
 assert r(m,0x2840)==deadline and r(m,0x2c78)==base+delay+1
 assert r(m,0x6208)==0 and m[0x620d]==128 and r(m,0x6218)==0 and r(m,0x621c)==0
 assert r(m,0x7000)==0x23007000 and r(m,0x7004)==0x23007000
 assert r(m,0x6000)==0x23006200 and r(m,0x6200)==0x23007180
 assert r(m,0x7008)==0x23006000 and r(m,0x700c)==1 and r(m,0x628c)==0xfffffff5
 assert result.value==0x12345678 and state.phase==1
 results.append({'cycle':cycle,'channel':ch,'deadline':deadline,'timed_out_thread':hex(0x23006200),'mutex_owner_retained':hex(0x23006000)})
paths=sorted(P.glob('*.c'))+list(P.glob('*.h'))+[Path(__file__),A/'libreceiver_rtc_handlers.dylib']
d={'status':'PASS','cycles':128,'real_mutex_waits':128,'explicit_PendSV_segments':128,'explicit_RTC_compare_events':128,'original_thread_timeout_callbacks_in_C':128,'results':results,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'not_added_to_original_input_count':True,'limits':['Component sequence, not new original instruction cases','Real recovered mutex/timeout/CPU/RTC/thread-expiry bodies share RAM; no replacement ready/wait list effects','Clock, compare event, enable readback and handler entry explicitly supplied','Stops before architectural exception return; requester made ready, not proven resumed or lock-acquired','No autonomous interrupts, actual concurrency or RF verification']}
(A/'receiver-rtc-handlers-continuous-regression.json').write_text(json.dumps(d,indent=2)+'\n');print(json.dumps({k:v for k,v in d.items() if k not in ['sources','results']},indent=2))
