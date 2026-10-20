"""Differential checks for active timers and disconnect lifecycle, no device IO."""
from pathlib import Path
import ctypes as C,json,subprocess,hashlib,zlib,base64,collections
R=Path(__file__).resolve().parent.parent;P=R/'recovered-code/portable';A=R/'analysis';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
lib=P/'build/libmouse_timer_lifecycle.dylib';src=P/'mouse_timer_lifecycle.c'
subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-dynamiclib',str(src),str(P/'mouse_radio_irq.c'),str(P/'business_tx.c'),str(P/'business_cipher.c'),'-o',str(lib)],check=True)
f=C.CDLL(str(lib));f.rr_mouse_timer_abort.argtypes=[Ptr,Ptr,W,C.POINTER(C.c_int32)];f.rr_mouse_timer_stop.argtypes=[Ptr,Ptr,W]
f.rr_mouse_disconnect.argtypes=[Ptr,Ptr,Ptr,Ptr,C.POINTER(W),W];f.rr_mouse_disconnect_ack.argtypes=[Ptr,Ptr,Ptr,Ptr,C.POINTER(W)];f.rr_mouse_ack_callback.argtypes=[Ptr,Ptr,Ptr,Ptr,C.POINTER(W),C.c_uint16]
f.rr_mouse_radio_irq_lifecycle.argtypes=[Ptr,Ptr,Ptr,Ptr,C.POINTER(W),C.POINTER(W),C.c_uint]
datasets=['mouse-timer-lifecycle-original.jsonl','mouse-ack-lifecycle-original.jsonl']
rows=[json.loads(s) for name in datasets for s in (A/name).read_text().splitlines() if s.strip()];assert len(rows)==2304
counts=collections.Counter();fails=[]
def unpack(z):return zlib.decompress(base64.b64decode(z))
for t in rows:
 b={name:unpack(t[name+'_before_z']) for name in ['ram','radio','timer','rtc','clock']};mem={name:(U*len(v)).from_buffer_copy(v) for name,v in b.items()};clk=C.cast(mem['clock'],C.POINTER(W));m=mem['ram'];result=C.c_int32()
 if t['op']==0:rc=f.rr_mouse_timer_abort(m,mem['rtc'],t['target'],C.byref(result))
 elif t['op']==1:rc=f.rr_mouse_timer_stop(m,mem['rtc'],t['target'])
 elif t['op']==2:rc=f.rr_mouse_disconnect(m,mem['radio'],mem['timer'],mem['rtc'],clk,t['reason'])
 elif t['op']==3:rc=f.rr_mouse_disconnect_ack(m,mem['radio'],mem['timer'],mem['rtc'],clk)
 elif t['op']==4:rc=f.rr_mouse_ack_callback(m,mem['radio'],mem['timer'],mem['rtc'],clk,t['message_class'])
 else:
  nvic=W(0x12345678);rc=f.rr_mouse_radio_irq_lifecycle(m,mem['radio'],mem['timer'],mem['rtc'],clk,C.byref(nvic),t['mode'])
 errors=[]
 if t['op']==5 and nvic.value!=t['nvic_after']:errors.append({'nvic':nvic.value,'expected':t['nvic_after']})
 if rc:errors.append({'model_return':rc})
 if t['op']==0 and (result.value&0xffffffff)!=t['original_r0']:errors.append({'abort_return':result.value,'expected':t['original_r0']})
 for name,buf in mem.items():
  ex=unpack(t[name+'_after_z']);ac=bytes(buf)
  if ex!=ac:
   diff=[i for i in range(len(ex)) if ex[i]!=ac[i]];errors.append({'window':name,'count':len(diff),'diff':[(hex(i),ac[i],ex[i]) for i in diff[:8]]})
 if errors:fails.append({'case':t['case'],'op':t['op'],'shape':t['shape'],'errors':errors})
 counts[f"op{t['op']}:shape{t['shape']}"]+=1
report={'status':'PASS' if not fails else 'FAIL','original_instruction_cases':len(rows),'counts':dict(counts),'failures':fails,'checks':['all65536 RAM bytes','RADIO4096 TIMER1536 RTC4096 clock8 byte windows','abort original return value','original BASEPRI restored'],'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in [src,P/'mouse_timer_lifecycle.h',Path(__file__),R/'ghidra-scripts/EmulateMouseTimerLifecycle.java',A/'mouse-timer-lifecycle-original.jsonl',A/'mouse-ack-lifecycle-original.jsonl',R/'ghidra-scripts/EmulateMouseAckLifecycle.java',P/'mouse_radio_irq.c',P/'mouse_radio_irq.h',P/'business_tx.c',P/'business_tx.h',P/'business_cipher.c',P/'business_cipher.h']},'limits':['active timer callbacks and waiting threads remain explicit boundaries','RTC snapshot, no time advancement; BASEPRI getter uses same emulator ArmCpuState','disconnect notification23025ed0 is original empty return','arbitrary pointers/corrupt linked lists outside declared memory domain']}
(A/'mouse-timer-lifecycle-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures','counts']},indent=2));print(json.dumps(fails[:12],indent=2));assert not fails
