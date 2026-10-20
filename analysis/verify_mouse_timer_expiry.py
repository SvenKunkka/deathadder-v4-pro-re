from pathlib import Path
import ctypes as C,json,subprocess,hashlib,gzip,base64,collections
R=Path(__file__).resolve().parent.parent;P=R/'recovered-code/portable';A=R/'analysis';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
files=[P/(n+'.c') for n in ['mouse_timer_expiry','mouse_work_queue','mouse_timer_start','mouse_timer_lifecycle','mouse_mode4_lifecycle','mouse_mode4_radio','mouse_mode4_tx','mouse_radio_irq','mouse_adaptive_control','business_tx','business_cipher']]
lib=A/'libmouse_timer_expiry.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True)
f=C.CDLL(str(lib))
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
f.rr_mouse_timer_expiry.argtypes=[Ptr,Ptr,W,C.POINTER(CPU)]
f.rr_mouse_disconnect_timer_callback.argtypes=[Ptr,Ptr,C.POINTER(CPU)]
f.rr_mouse_link_work_callback.argtypes=[Ptr,Ptr,Ptr,C.POINTER(CPU)]
def un(z):return gzip.decompress(base64.b64decode(z))
def buf(b):return (U*len(b)).from_buffer_copy(b)
def diff(name,got,expect):
 if got==expect:return []
 ds=[i for i in range(len(expect)) if got[i]!=expect[i]];return [{name+'_diffs':len(ds),'first':[(hex(i),got[i],expect[i]) for i in ds[:12]]}]
rows=[json.loads(s) for s in (A/'mouse-timer-expiry-original.jsonl').read_text().splitlines()];assert len(rows)==4096
fails=[];counts=collections.Counter();boundaries=collections.Counter();returns=collections.Counter()
for t in rows:
 m=buf(un(t['before_gzip']));rtc=buf(un(t['rtc_before']));cpu=CPU(t['initial_priority'],t['exception'],0,0);value=C.c_int32(0);queue=W(t['queue'])
 aux=buf(un(t['aux_before']))
 if t['op']<2:rc=f.rr_mouse_timer_expiry(m,rtc,t['address'],C.byref(cpu))
 elif t['op']==2:rc=f.rr_mouse_disconnect_timer_callback(m,rtc,C.byref(cpu))
 else:rc=f.rr_mouse_link_work_callback(m,rtc,aux,C.byref(cpu))
 errors=diff('RAM',bytes(m),un(t['after_gzip']))+diff('RTC',bytes(rtc),un(t['rtc_after']))+diff('AUX',bytes(aux),un(t['aux_after']))
 if rc!=(1 if t['boundary'] else 0):errors.append({'return':rc,'boundary':t['boundary']})
 if cpu.entry!=t['boundary'] or cpu.arg0!=t['arg0']:errors.append({'pending':(hex(cpu.entry),hex(cpu.arg0)),'expected':(hex(t['boundary']),hex(t['arg0']))})
 if cpu.priority!=t['final_priority']:errors.append({'priority':cpu.priority,'expected':t['final_priority']})
 if errors:fails.append({'case':t['case'],'op':t['op'],'errors':errors})
 counts[str(t['op'])]+=1;boundaries[hex(t['boundary'])]+=1
 if not t['boundary']:returns['original_full_return']+=1
paths=files+[P/'mouse_timer_expiry.h',P/'mouse_work_queue.h',P/'mouse_timer_start.h',Path(__file__),R/'ghidra-scripts/EmulateMouseTimerExpiry.java',A/'mouse-timer-expiry-original.jsonl']
report={'status':'PASS' if not fails else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'counts':dict(counts),'boundaries':dict(boundaries),'original_returns':dict(returns),'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['64KiB RAM and4KiB RTC snapshots plus serialized privileged CPU priority/exception model','timer expiry, periodic reinsert, usercallback1578, timer waiter ready and link-state work callback execute original paths','unknown callback23022310 and true CPU context switch remain real entry boundaries','direct callback invocation does not prove autonomous RTC dispatch or actual work thread dispatch','inert clock/IRQ/peripherals, no physical device access']}
(A/'mouse-timer-expiry-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']},indent=2));print(json.dumps(fails[:8],indent=2));assert not fails
