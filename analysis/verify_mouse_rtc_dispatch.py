from pathlib import Path
import ctypes as C,json,subprocess,hashlib,gzip,base64,collections
R=Path(__file__).resolve().parent.parent;P=R/'recovered-code/portable';A=R/'analysis';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
files=[P/(n+'.c') for n in ['mouse_rtc_dispatch','mouse_scanning','mouse_work_thread','mouse_timer_expiry','mouse_work_queue','mouse_timer_start','mouse_timer_lifecycle','mouse_mode4_lifecycle','mouse_mode4_radio','mouse_mode4_tx','mouse_radio_irq','mouse_adaptive_control','business_tx','business_cipher']]
lib=A/'libmouse_rtc_dispatch.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True)
f=C.CDLL(str(lib))
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
class HW(C.Structure):_fields_=[('ram',Ptr),('radio',Ptr),('timer',Ptr),('rtc',Ptr),('aux',Ptr),('nvic',Ptr),('clock',C.POINTER(W)),('image',Ptr)]
class Pending(C.Structure):_fields_=[('entry',W),('args',W*5)]
f.rr_mouse_timeout_announce.argtypes=[C.POINTER(HW),W,C.POINTER(CPU),C.POINTER(Pending)]
f.rr_mouse_clock_announce.argtypes=[C.POINTER(HW),C.c_uint64,C.POINTER(CPU),C.POINTER(Pending)]
f.rr_mouse_rtc_dispatch.argtypes=[C.POINTER(HW),C.POINTER(CPU),C.POINTER(Pending)]
image=(U*201044).from_buffer_copy((R/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin').read_bytes())
def un(z):return gzip.decompress(base64.b64decode(z))
def buf(b):return (U*len(b)).from_buffer_copy(b)
def diff(name,got,expect):
 if got==expect:return []
 ds=[i for i in range(len(expect)) if got[i]!=expect[i]];return [{name+'_diffs':len(ds),'first':[(hex(i),got[i],expect[i]) for i in ds[:12]]}]
rows=[json.loads(s) for s in (A/'mouse-rtc-dispatch-original.jsonl').read_text().splitlines()];assert len(rows)==6144
fails=[];counts=collections.Counter();boundaries=collections.Counter();returns=collections.Counter()
for t in rows:
 m=buf(un(t['before_gzip']));rtc=buf(un(t['rtc_before']));cpu=CPU(t['initial_priority'],t['exception'],0,0);value=C.c_int32(0);queue=W(t['queue'])
 aux=buf(un(t['aux_before']))
 radio=buf(un(t['radio_before']));timer=buf(un(t['timer_before']));nvic=buf(un(t['nvic_before']));clock=buf(un(t['clock_before']));hw=HW(m,radio,timer,rtc,aux,nvic,C.cast(clock,C.POINTER(W)),image)
 pending=Pending()
 if t['op']==0:rc=f.rr_mouse_timeout_announce(C.byref(hw),t['ticks'],C.byref(cpu),C.byref(pending))
 elif t['op']==1:rc=f.rr_mouse_clock_announce(C.byref(hw),t['deadline'],C.byref(cpu),C.byref(pending))
 else:rc=f.rr_mouse_rtc_dispatch(C.byref(hw),C.byref(cpu),C.byref(pending))
 errors=[]
 for label,got,key in [('RAM',m,'after_gzip'),('RTC',rtc,'rtc_after'),('AUX',aux,'aux_after'),('RADIO',radio,'radio_after'),('TIMER',timer,'timer_after'),('NVIC',nvic,'nvic_after'),('CLOCK',clock,'clock_after')]:errors+=diff(label,bytes(got),un(t[key]))
 if rc!=(1 if t['boundary'] else 0):errors.append({'return':rc,'boundary':t['boundary']})
 if cpu.entry!=t['boundary'] or cpu.arg0!=t['arg0']:errors.append({'pending':(hex(cpu.entry),hex(cpu.arg0)),'expected':(hex(t['boundary']),hex(t['arg0']))})
 if cpu.priority!=t['final_priority']:errors.append({'priority':cpu.priority,'expected':t['final_priority']})
 if pending.entry!=t['boundary'] or list(pending.args)!=t['pending_args']:errors.append({'pending_ABI':list(pending.args),'expected':t['pending_args']})
 if errors:fails.append({'case':t['case'],'op':t['op'],'errors':errors})
 counts[str(t['op'])]+=1;boundaries[hex(t['boundary'])]+=1
 if not t['boundary']:returns['original_full_return']+=1
paths=files+[P/'mouse_rtc_dispatch.h',P/'mouse_scanning.h',P/'mouse_work_thread.h',P/'mouse_timer_expiry.h',P/'mouse_work_queue.h',P/'mouse_timer_start.h',Path(__file__),R/'ghidra-scripts/EmulateMouseRtcDispatch.java',A/'mouse-rtc-dispatch-original.jsonl']
report={'status':'PASS' if not fails else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'counts':dict(counts),'boundaries':dict(boundaries),'original_returns':dict(returns),'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['Full inert RAM/MMIO and serialized privileged CPU comparisons; hardware readback/event generation not autonomous','Unknown timeout/user/RTC callbacks and actual CPU switch stop at actual entry with pending ABI','Supported timer/thread/timeslice callbacks and end-of-tick scheduler updates execute original instructions','Top generic ISR, exception return, real clock/RF/CPU concurrency remain unverified']}
(A/'mouse-rtc-dispatch-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']},indent=2));print(json.dumps(fails[:8],indent=2));assert not fails
