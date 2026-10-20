from pathlib import Path
import ctypes as C,json,hashlib,gzip,base64,struct
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
names=['ram','radio','timer','nvic','dppi','rtc','clock0','clock1','clock2','deviceid']
class HW(C.Structure):_fields_=[(n,Ptr) for n in names]
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
f=C.CDLL(str(A/'libreceiver_queue_runtime.dylib'))
f.rr_receiver_message_get.argtypes=[Ptr,Ptr,W,W,Ptr,C.c_uint64,C.POINTER(CPU),C.POINTER(C.c_int32)]
f.rr_receiver_config_iteration.argtypes=[C.POINTER(HW),W,Ptr,U,Ptr,C.POINTER(CPU)]
f.rr_receiver_config_control.argtypes=[C.POINTER(HW),W,W,U,Ptr,C.POINTER(CPU)]
f.rr_receiver_message_put_timed.argtypes=[Ptr,Ptr,W,Ptr,C.POINTER(CPU),C.POINTER(C.c_int32)]
row=next(json.loads(s) for s in (A/'receiver-queue-runtime-original.jsonl').open() if json.loads(s)['case']==2050)
mem={n:(U*len(gzip.decompress(base64.b64decode(row[n+'_before'])))).from_buffer_copy(gzip.decompress(base64.b64decode(row[n+'_before']))) for n in names};m=mem['ram'];rtc=mem['rtc'];hw=HW(*[mem[n] for n in names]);cpu=CPU(0x80,0,0,0)
def w(a):return int.from_bytes(bytes(m[a:a+4]),'little')
def pw(a,v):m[a:a+4]=v.to_bytes(4,'little')
q=0x1bb4;pw(q,0x23001bb4);pw(q+4,0x23001bb4);pw(q+24,0x23015760);pw(q+28,0x23015760);pw(q+32,0)
# Explicit shared-memory destination substitutes the original private stack buffer.
output=C.cast(C.byref(m,0x9000),Ptr)
image=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();table=(U*256).from_buffer_copy(image[0x1ba74:0x1bb74])
def message(i):return struct.pack('<II',9,i)+bytes((i+j)&255 for j in range(28))
def put(b):
 buf=(U*36).from_buffer_copy(b);result=C.c_int32(0x12345678)
 rc=f.rr_receiver_message_put_timed(m,rtc,0x23001bb4,buf,C.byref(cpu),C.byref(result));assert rc==0,(rc,cpu.entry)
 return result.value
counts={'cycles':0,'buffered_messages':0,'direct_waiter_deliveries':0,'full_queue_rejections':0,'finite_waits_canceled':0,'explicit_context_handoffs':0,'post_get_dispatch_segments':0}
for cycle in range(128):
 expected=[message(cycle*6+j) for j in range(5)]
 for b in expected:assert put(b)==0
 before=bytes(m),bytes(rtc);assert put(message(999999))==-35;assert before==(bytes(m),bytes(rtc));counts['full_queue_rejections']+=1
 for b in expected:
  assert f.rr_receiver_config_iteration(C.byref(hw),0x23009000,output,0,table,C.byref(cpu))==0
  assert bytes(output[:36])==b and w(0x3240)==struct.unpack_from('<I',b,4)[0]
  counts['buffered_messages']+=1
 assert w(q+32)==0
 result=C.c_int32(0x12345678);duration=1000 if cycle%2==0 else 0xffffffffffffffff
 assert f.rr_receiver_message_get(m,rtc,0x23001bb4,0x23009000,output,duration,C.byref(cpu),C.byref(result))==1
 assert cpu.entry==0xe0611cc and cpu.arg0==0x80 and result.value==0x12345678
 assert w(q)==0x23006000 and m[0x600d]&2 and w(0x6014)==0x23009000
 if cycle%2==0:assert w(0x6018)!=0
 # The hardware switch is not simulated: hand off explicitly to existing sender.
 pw(0x7170,0x23001fc0);pw(0x717c,0x23001fc0);cpu.priority=0x80;counts['explicit_context_handoffs']+=1
 b=message(cycle*6+5);assert put(b)==0
 assert bytes(output[:36])==b and w(0x608c)==0 and not(m[0x600d]&2) and w(0x6018)==0
 assert w(q+32)==0 and w(q)==0x23001bb4
 counts['direct_waiter_deliveries']+=1;counts['finite_waits_canceled']+=cycle%2==0
 # Explicit delivery of CPU control back to consumer, then the after-get API.
 pw(0x7170,0x23006000);pw(0x717c,0x23006000);cpu.priority=0x80;counts['explicit_context_handoffs']+=1
 assert f.rr_receiver_config_control(C.byref(hw),9,cycle*6+5,0,table,C.byref(cpu))==0
 assert w(0x3240)==cycle*6+5;counts['post_get_dispatch_segments']+=1;counts['cycles']+=1
paths=[Path(__file__),P/'receiver_queue_runtime.c',P/'receiver_queue_runtime.h',P/'receiver_config_control.c',P/'receiver_timeout.c',P/'receiver_rtos_lifecycle.c',A/'receiver-queue-runtime-original.jsonl']
report={'status':'PASS',**counts,'not_added_to_original_count':True,'checks':['Full36-byte FIFO including old tail','Queue capacity rejection preserves RAM/RTC','Read and write pointers wrap across repeated batches','Empty wait records destination, flags, wait queue and CPU request','Real restored producer delivers directly to waiter and cancels finite timeout','Config event9 commits each dequeued value to RAM3240'],'limits':['Explicit context handoff, not CPU exception/stack restoration','After blocked get, separately invoke existing after-get dispatch with actually delivered message','Shared RAM destination replaces thread-private stack; no real RF/IRQ/time'],'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths}}
(A/'receiver-queue-continuous-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k!='sources'},indent=2))
