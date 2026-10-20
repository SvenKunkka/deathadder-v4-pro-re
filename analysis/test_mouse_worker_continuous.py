from pathlib import Path
import ctypes as C,struct,json,hashlib
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
f=C.CDLL(str(A/'libmouse_worker_runtime.dylib'))
f.rr_mouse_work_thread_runtime.argtypes=[Ptr,Ptr,Ptr,W,C.POINTER(CPU)]
f.rr_mouse_delayed_work_expiry.argtypes=[Ptr,Ptr,W,C.POINTER(CPU)]
def w(b,o,v):struct.pack_into('<I',b,o,v&0xffffffff)
def r(b,o):return struct.unpack_from('<I',b,o)[0]
results=[]
for priority in [0,16,128]:
 m=bytearray(65536);rtc=bytearray(4096);aux=bytearray(16);cpu=CPU(priority,0,0,0)
 for off,ptr in [(0x14f4,0x230014f4),(0x14f8,0x230014f4),(0x2530,0x23002530),(0x2534,0x23002530),(0x2538,0x23002538),(0x253c,0x23002538),(0x7668,0x23002498),(0x766c,0x23002498),(0x2498,0x23007668),(0x249c,0x23007668),(0x7654,0x23002498),(0x7658,0x23002378),(0x7664,0x23002498),(0x67c4,0x23025df1),(0x67c8,0x23002498),(0x67e8,0x23002498),(0x1b60,0x23001b60),(0x1b64,0x23001b60)]:w(m,off,ptr)
 m[0x24a5]=128;w(m,0x2540,0x101);m[0x1304]=7
 mb=(U*len(m)).from_buffer(m);rb=(U*len(rtc)).from_buffer(rtc);ab=(U*len(aux)).from_buffer(aux)
 for cycle in range(64):
  cpu.priority=priority;cpu.exception_number=0
  rc=f.rr_mouse_work_thread_runtime(mb,rb,ab,0x23002498,C.byref(cpu))
  assert rc==1 and cpu.entry==0xe089d4c and cpu.arg0==priority
  assert m[0x24a5]==2 and r(m,0x24a0)==0x23002530
  assert r(m,0x2530)==r(m,0x2534)==0x23002498 and r(m,0x7664)==0x23002378
  assert r(m,0x7668)==r(m,0x766c)==0x23007668
  # Explicit external context handoff at the actual CPU boundary. This is
  # test input, not recovered or validated exception/context-switch code.
  w(m,0x7654,0x23002378);cpu.priority=0;cpu.exception_number=60
  w(m,0x67cc,8)
  assert f.rr_mouse_delayed_work_expiry(mb,rb,0x230067d0,C.byref(cpu))==0
  assert r(m,0x67cc)==4 and r(m,0x2528)==r(m,0x252c)==0x230067c0
  assert r(m,0x2530)==r(m,0x2534)==0x23002530 and m[0x24a5]==128
  assert r(m,0x24a0)==0 and r(m,0x7664)==0x23002498
  assert r(m,0x7668)==r(m,0x766c)==0x23002498
  w(m,0x7654,0x23002498);cpu.priority=priority;cpu.exception_number=0
  assert f.rr_mouse_work_thread_runtime(mb,rb,ab,0x23002498,C.byref(cpu))==0
  assert r(m,0x67cc)==0 and r(m,0x2528)==r(m,0x252c)==0
  assert r(m,0x14f4)==r(m,0x14f8)==0x230014f4
 results.append({'initial_priority':priority,'wait_delayed_enqueue_callback_cycles':64})
paths=[Path(__file__),P/'mouse_worker_runtime.c',P/'mouse_worker_runtime.h',A/'libmouse_worker_runtime.dylib']
d={'status':'PASS','scenarios':3,'cycles':192,'worker_pend_to_CPU_boundaries':192,'explicit_context_handoffs':384,'delayed_callbacks':192,'worker_next_loop_segments':192,'results':results,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'not_added_to_original_input_count':True,'limits':['C integration with explicitly supplied context handoffs and delayed-callback arrival','CPU request and exception execution not modeled; no automatic RTC/IRQ/time or RF','Worker next-loop segment is not a thread return']}
(A/'mouse-worker-continuous-comparison.json').write_text(json.dumps(d,indent=2)+'\n');print(json.dumps({k:v for k,v in d.items() if k not in ['sources','results']},indent=2))
