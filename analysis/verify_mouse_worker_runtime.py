from pathlib import Path
import ctypes as C,json,subprocess,hashlib,gzip,base64,collections
R=Path(__file__).resolve().parent.parent;P=R/'recovered-code/portable';A=R/'analysis';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
files=[P/(n+'.c') for n in ['mouse_worker_runtime','mouse_scanning','mouse_work_thread','mouse_timer_expiry','mouse_work_queue','mouse_timer_start','mouse_timer_lifecycle','mouse_mode4_lifecycle','mouse_mode4_radio','mouse_mode4_tx','mouse_radio_irq','mouse_adaptive_control','business_tx','business_cipher']]
lib=A/'libmouse_worker_runtime.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True)
f=C.CDLL(str(lib))
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
class HW(C.Structure):_fields_=[('ram',Ptr),('radio',Ptr),('timer',Ptr),('rtc',Ptr),('aux',Ptr),('nvic',Ptr),('clock',C.POINTER(W)),('image',Ptr)]
image=(U*201044).from_buffer_copy((R/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin').read_bytes())
f.rr_mouse_work_thread_scanning_runtime.argtypes=[C.POINTER(HW),W,C.POINTER(CPU)]
f.rr_mouse_wait_wake.argtypes=[Ptr,Ptr,W,W,W,C.POINTER(CPU),C.POINTER(C.c_int32)]
f.rr_mouse_worker_yield.argtypes=[Ptr,Ptr,C.POINTER(CPU)]
f.rr_mouse_worker_pend.argtypes=[Ptr,Ptr,W,W,C.c_uint64,C.POINTER(CPU)]
f.rr_mouse_delayed_work_expiry.argtypes=[Ptr,Ptr,W,C.POINTER(CPU)]
f.rr_mouse_work_thread_runtime.argtypes=[Ptr,Ptr,Ptr,W,C.POINTER(CPU)]
def un(z):return gzip.decompress(base64.b64decode(z))
def buf(b):return (U*len(b)).from_buffer_copy(b)
def diff(name,got,expect):
 if got==expect:return []
 ds=[i for i in range(len(expect)) if got[i]!=expect[i]];return [{name+'_diffs':len(ds),'first':[(hex(i),got[i],expect[i]) for i in ds[:12]]}]
rows=[json.loads(s) for s in (A/'mouse-worker-runtime-original.jsonl').read_text().splitlines()];assert len(rows)==6144
fails=[];counts=collections.Counter();boundaries=collections.Counter();returns=collections.Counter()
for t in rows:
 m=buf(un(t['before_gzip']));rtc=buf(un(t['rtc_before']));cpu=CPU(t['initial_priority'],t['exception'],0,0);value=C.c_int32(0);queue=W(t['queue'])
 aux=buf(un(t['aux_before']));radio=buf(un(t['radio_before']));timer=buf(un(t['timer_before']));nvic=buf(un(t['nvic_before']));clock=buf(un(t['clock_before']));hw=HW(m,radio,timer,rtc,aux,nvic,C.cast(clock,C.POINTER(W)),image)
 if t['op']==0:rc=f.rr_mouse_wait_wake(m,rtc,0x23002538,t['wake_result'],t['wake_data'],C.byref(cpu),C.byref(value))
 elif t['op']==1:rc=f.rr_mouse_worker_yield(m,rtc,C.byref(cpu))
 elif t['op']==2:rc=f.rr_mouse_worker_pend(m,rtc,t['wait_queue'],t['saved_priority'],int(t['timeout']),C.byref(cpu))
 elif t['op']==3:rc=f.rr_mouse_delayed_work_expiry(m,rtc,0x230067d0,C.byref(cpu))
 elif t['op']==4:rc=f.rr_mouse_work_thread_runtime(m,rtc,aux,0x23002498,C.byref(cpu))
 else:rc=f.rr_mouse_work_thread_scanning_runtime(C.byref(hw),0x23002498,C.byref(cpu))
 errors=diff('RAM',bytes(m),un(t['after_gzip']))+diff('RTC',bytes(rtc),un(t['rtc_after']))+diff('AUX',bytes(aux),un(t['aux_after']))
 for label,got,key in [('RADIO',radio,'radio_after'),('TIMER',timer,'timer_after'),('NVIC',nvic,'nvic_after'),('CLOCK',clock,'clock_after')]:errors+=diff(label,bytes(got),un(t[key]))
 if rc!=(1 if t['boundary'] else 0):errors.append({'return':rc,'boundary':t['boundary']})
 if cpu.entry!=t['boundary'] or cpu.arg0!=t['arg0']:errors.append({'pending':(hex(cpu.entry),hex(cpu.arg0)),'expected':(hex(t['boundary']),hex(t['arg0']))})
 if cpu.priority!=t['final_priority']:errors.append({'priority':cpu.priority,'expected':t['final_priority']})
 if t['op']==0 and value.value!=t['return']:errors.append({'original_result':t['return'],'C_result':value.value})
 if errors:fails.append({'case':t['case'],'op':t['op'],'errors':errors})
 counts[str(t['op'])]+=1;boundaries[hex(t['boundary'])]+=1
 if not t['boundary']:returns['next_loop_header' if t['op']>=4 else 'full_return']+=1
paths=files+[P/'mouse_worker_runtime.h',P/'mouse_scanning.h',P/'mouse_work_thread.h',P/'mouse_timer_expiry.h',P/'mouse_work_queue.h',P/'mouse_timer_start.h',Path(__file__),R/'ghidra-scripts/EmulateMouseWorkerRuntime.java',A/'mouse-worker-runtime-original.jsonl']
report={'status':'PASS' if not fails else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'counts':dict(counts),'boundaries':dict(boundaries),'original_returns':dict(returns),'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['Original wake/yield/pend/delayed-work functions and actual worker through scheduling requests','CPU context-switch request is a real entry boundary, not executed or replaced with successful return','Worker next-loop header is not thread exit; unknown handler retains actual pointer','Pend stops before CPU call; post-switch return/output and live CPU scheduling not reconstructed','Inert RAM/MMIO only; no real RF or concurrent IRQ execution']}
(A/'mouse-worker-runtime-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']},indent=2));print(json.dumps(fails[:8],indent=2));assert not fails
