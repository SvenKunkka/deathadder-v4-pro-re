from pathlib import Path
import ctypes as C,json,hashlib
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
class HW(C.Structure):_fields_=[(n,Ptr) for n in ['ram','radio','timer','nvic','dppi','rtc','clock0','clock1','clock2','deviceid']]
class Pending(C.Structure):_fields_=[('entry',W),('args',W*5)]
f=C.CDLL(str(A/'libreceiver_worker_runtime.dylib'));f.rr_receiver_periodic_init.argtypes=[Ptr,Ptr,C.POINTER(W)];f.rr_receiver_periodic_refresh.argtypes=[Ptr,Ptr,Ptr,C.POINTER(W)];f.rr_receiver_periodic_dispatch.argtypes=[Ptr,Ptr,Ptr,Ptr,C.POINTER(CPU),C.POINTER(Pending)];f.rr_receiver_clock_allocate.argtypes=[Ptr];f.rr_receiver_clock_allocate.restype=W
image=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();fw=(U*len(image)).from_buffer_copy(image);m=(U*131072)();r=(U*4096)();s=(U*4096)();m[:0x1e08]=image[0x1c854:0x1c854+0x1e08]
def w(a):return int.from_bytes(bytes(m[a:a+4]),'little')
def put(b,a,v,n=4):b[a:a+n]=v.to_bytes(n,'little')
put(m,0xab4,0xe080);put(m,0xab8,0);put(m,0x6db0,0);m[0x71eb]=0;result=W();assert f.rr_receiver_periodic_init(m,s,C.byref(result))==0
assert result.value==15 and w(0x2df8)==15 and m[0x71eb]==1 and w(0xab4)==0x6080
assert bytes(s[0x504:0x510])==(65536).to_bytes(4,'little')+(1).to_bytes(4,'little')+bytes(4) and bytes(s[:4])==b'\1\0\0\0'
assert f.rr_receiver_clock_allocate(m)==14 and f.rr_receiver_clock_allocate(m)==13 and f.rr_receiver_clock_allocate(m)==0xfffffff4 and w(0xab4)==0x80
put(r,0x770,123,8);put(m,0x2840,123,8);put(m,0x2c78,123,8);put(m,0x7198,0)
assert f.rr_receiver_periodic_refresh(m,r,s,C.byref(result))==0 and result.value==0
assert w(0xabc+36)==0xe05bde1 and w(0xac0+36)==0 and m[0xac4+36]==15
cpu=CPU(0x80,125,0,0);events=0
# Explicit system-clock ownership and coherent thread/timeout fixture.
f.rr_receiver_timer_start_control.argtypes=[Ptr,Ptr,W,C.c_uint64,C.c_uint64,C.POINTER(CPU)]
f.rr_receiver_rtc_work_dispatch.argtypes=[C.POINTER(HW),Ptr,Ptr,Ptr,C.POINTER(CPU),C.POINTER(Pending)]
other=[(U*4096)() for _ in range(7)];device=(U*8)();hw=HW(m,other[0],other[1],other[2],other[3],r,other[4],other[5],other[6],device);tail=(U*32)()
put(m,0xab4,0);put(m,0x958,0xe0683a1);put(m,0x95c,0);m[0x960]=7
for a,v in [(0xb48,0x23000b48),(0xb4c,0x23000b48),(0x7170,0x23006000),(0x717c,0x23006000),(0x7174,0x23006000),(0x7180,0x23007180),(0x7184,0x23007180)]:put(m,a,v)
m[0x1ad8:0x1b10]=bytes(0x38);put(m,0x1af0,0x23001af0);put(m,0x1af4,0x23001af0);put(m,0x1af8,0x23025641)
assert f.rr_receiver_timer_start_control(m,r,0x23001ad8,100000,100000,C.byref(cpu))==0

f.rr_receiver_work_initialize.argtypes=[Ptr,W,W,C.c_int]
f.rr_receiver_delayed_work_schedule.argtypes=[Ptr,Ptr,W,W,C.c_uint64,C.c_int,C.POINTER(CPU),C.POINTER(C.c_int32)]
f.rr_receiver_work_cancel.argtypes=[Ptr,W,C.POINTER(CPU),C.POINTER(W)]
queue=0x2b18;work=0x7000;m[queue:queue+0xb0]=bytes(0xb0)
for off,val in [(0x98,0x23002bb0),(0x9c,0x23002bb0),(0xa0,0x23002bb8),(0xa4,0x23002bb8),(0xa8,0x101)]:put(m,queue+off,val)
assert f.rr_receiver_work_initialize(m,0x23007000,0x23026d29,1)==0
class Call(C.Structure):_fields_=[('entry',W),('device',W),('length',W),('buffer',W)]
Hook=C.CFUNCTYPE(C.c_int32,C.c_void_p,Ptr,C.POINTER(Call));f.rr_receiver_work_thread_step.argtypes=[Ptr,Ptr,Ptr,W,C.POINTER(CPU),Hook,C.c_void_p,C.POINTER(Call)];f.rr_dbc_usb_enqueue.argtypes=[Ptr,C.c_uint,Ptr,W];f.rr_dbc_usb_enqueue.restype=U
aux=(U*4096)();usb=Call();expected={};fail_mode=False;errors=[];attempts=0
@Hook
def driver(_,mem,ptr):
 global attempts
 c=ptr.contents;ch={0xe06f6a4:0,0xe06f690:1,0xe06f67c:2}[c.device];payload=bytes(mem[c.buffer-0x23000000+j] for j in range(c.length));attempts+=1
 if payload!=expected[ch]:errors.append((ch,payload.hex(),expected[ch].hex()))
 if fail_mode:return -13
 if ch==0:mem[0x6904]=0
 else:mem[0x6900+ch]=0;mem[0x6908+ch]=0
 return 0
# Explicit current-thread identity; actual exception return is not exercised.
for off,value in [(0x7170,0x23002b18),(0x717c,0x23002b18),(0x7174,0x230029f8),(0x7180,0x23002b18),(0x7184,0x23002b18),(queue,0x23007180),(queue+4,0x23007180)]:put(m,off,value)
m[queue+0xd]=128;m[0x71e4]=1
completed=0;rescheduled=0
for i in range(64):
 now=int.from_bytes(bytes(r[0x770:0x778]),'little');out=C.c_int32();res=W()
 assert f.rr_receiver_delayed_work_schedule(m,r,0x23002b18,0x23007000,100,0,C.byref(cpu),C.byref(out))==0 and out.value==1
 assert f.rr_receiver_delayed_work_schedule(m,r,0x23002b18,0x23007000,50,1,C.byref(cpu),C.byref(out))==0 and out.value==1;rescheduled+=1
 # Original timeout_start adds1 tick to a relative delay, unlike timer_start wrapper.
 early=int.from_bytes(bytes(r[0x590:0x598]),'little');assert early==now+51,(early,now)
 put(r,0x770,early,8);put(r,0x11c,1);put(r,0x13c,0);put(r,0x350,0x8080);p=Pending()
 assert f.rr_receiver_rtc_work_dispatch(C.byref(hw),s,fw,tail,C.byref(cpu),C.byref(p))==0
 assert p.entry==0 and w(queue+0x90)==w(queue+0x94)==0x23007000 and w(work+12)==0x104 and w(work+16)==0
 for cls in [1,2,4]:
  ch=m[0x48c+cls];n=16 if ch==1 else 8;payload=bytes((i*17+ch*43+j)&255 for j in range(n));expected[ch]=payload;data=(U*n).from_buffer_copy(payload);assert f.rr_dbc_usb_enqueue(m,cls,data,n)==1
 clone=(U*131072).from_buffer_copy(m);rclone=(U*4096).from_buffer_copy(r);ac=(U*4096).from_buffer_copy(aux);cc=CPU(cpu.priority,cpu.exception_number,0,0);call=Call()
 assert f.rr_receiver_work_thread_step(clone,rclone,ac,0x23002b18,C.byref(cc),Hook(),None,C.byref(call))==1 and cc.entry==0xe064288
 fail_mode=True;old=bytes(m[0x6834:0x6837]);assert f.rr_receiver_work_thread_step(m,r,aux,0x23002b18,C.byref(cpu),driver,None,C.byref(usb))==0
 assert bytes(m[0x6834:0x6837])==old and w(queue+0x90)==w(queue+0x94)==0 and w(work+12)==0x100
 assert f.rr_receiver_delayed_work_schedule(m,r,0x23002b18,0x23007000,0,0,C.byref(cpu),C.byref(out))==0 and out.value==1
 fail_mode=False;assert f.rr_receiver_work_thread_step(m,r,aux,0x23002b18,C.byref(cpu),driver,None,C.byref(usb))==0
 assert w(queue+0x90)==w(queue+0x94)==0 and w(work+12)==0x100 and w(queue+0xa8)==0x101
 assert bytes(m[0x6834:0x6837])==bytes(m[0x6838:0x683b]) and not errors
 due=int.from_bytes(bytes(r[0x610:0x618]),'little');assert due==123+(i+1)*100000
 assert int.from_bytes(bytes(r[0x590:0x598]),'little')==due
 put(r,0x770,due,8);put(r,0x11c,1);put(r,0x13c,1);put(r,0x350,0x8080);put(s,0x600,0);p=Pending()
 assert f.rr_receiver_rtc_work_dispatch(C.byref(hw),s,fw,tail,C.byref(cpu),C.byref(p))==0
 assert p.entry==0 and w(0x1b08)==i+1 and int.from_bytes(bytes(r[0x610:0x618]),'little')==due+100000
 assert bytes(s[0x600:0x604])==(0x6e524635).to_bytes(4,'little') and cpu.priority==0x80;completed+=1
assert attempts==384 and not errors
paths=sorted(P.glob('*.c'))+list(P.glob('*.h'))+[Path(__file__),A/'libreceiver_worker_runtime.dylib']
d={'status':'PASS','cycles':completed,'explicit_RTC_events':128,'work_expiries':64,'active_reschedules':rescheduled,'worker_loop_steps':128,'USB_entry_boundaries_on_cloned_states':64,'external_USB_failures':192,'external_USB_successes':192,'application_timer_callbacks':64,'periodic_callbacks':64,'not_added_to_original_input_count':True,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'checks':['Actual delayed work initialization/schedule/reschedule thenRTC expiry and work queue insertion','Actual work-thread software removes task, invokes actual USB callback, clears flags and reaches next loop header','Explicit driver failures preserve reports; immediate resubmit then actual worker callback retries identical reports','NextRTC event executes application timer and periodic service, preserving phase'],'limits':['Explicit clock/events and current-thread identity; CPU exception return and concurrency not exercised','USB results and completion byte updates are explicit environment inputs; actualdriver not executed','No physical receiver, RF or USB']}
(A/'receiver-worker-runtime-continuous-comparison.json').write_text(json.dumps(d,indent=2)+'\n');print(json.dumps({k:v for k,v in d.items() if k!='sources'},indent=2))
