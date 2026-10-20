from pathlib import Path
import ctypes as C,json,subprocess,hashlib,gzip,base64,collections
R=Path(__file__).resolve().parent.parent;P=R/'recovered-code/portable';A=R/'analysis';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
files=sorted(P.glob('*.c'))
lib=A/'libreceiver_rtc_handlers.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True)
f=C.CDLL(str(lib))
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
class HW(C.Structure):_fields_=[('ram',Ptr),('rtc',Ptr)]
class Pending(C.Structure):_fields_=[('entry',W),('args',W*5)]
f.rr_receiver_timeout_announce.argtypes=[C.POINTER(HW),W,C.POINTER(CPU),C.POINTER(Pending)]
f.rr_receiver_clock_announce.argtypes=[C.POINTER(HW),C.c_uint64,C.POINTER(CPU),C.POINTER(Pending)]
f.rr_receiver_rtc_dispatch.argtypes=[C.POINTER(HW),C.POINTER(CPU),C.POINTER(Pending)]

def un(z):return gzip.decompress(base64.b64decode(z))
def buf(b):return (U*len(b)).from_buffer_copy(b)
def diff(name,got,expect):
 if got==expect:return []
 ds=[i for i in range(len(expect)) if got[i]!=expect[i]];return [{name+'_diffs':len(ds),'first':[(hex(i),got[i],expect[i]) for i in ds[:12]]}]
rows=[json.loads(s) for s in (A/'receiver-rtc-dispatch-original.jsonl').read_text().splitlines()];assert len(rows)==6144
fails=[];counts=collections.Counter();boundaries=collections.Counter();returns=collections.Counter()
for t in rows:
 m=buf(un(t['before_gzip']));rtc=buf(un(t['rtc_before']));cpu=CPU(t['initial_priority'],t['exception'],0,0)
 hw=HW(m,rtc)
 pending=Pending()
 if t['op']==0:rc=f.rr_receiver_timeout_announce(C.byref(hw),t['ticks'],C.byref(cpu),C.byref(pending))
 elif t['op']==1:rc=f.rr_receiver_clock_announce(C.byref(hw),t['deadline'],C.byref(cpu),C.byref(pending))
 else:rc=f.rr_receiver_rtc_dispatch(C.byref(hw),C.byref(cpu),C.byref(pending))
 errors=[]
 for label,got,key in [('RAM',m,'after_gzip'),('RTC',rtc,'rtc_after')]:errors+=diff(label,bytes(got),un(t[key]))
 if rc!=(1 if t['boundary'] else 0):errors.append({'return':rc,'boundary':t['boundary']})
 if cpu.entry!=t['boundary'] or cpu.arg0!=t['arg0']:errors.append({'pending':(hex(cpu.entry),hex(cpu.arg0)),'expected':(hex(t['boundary']),hex(t['arg0']))})
 if cpu.priority!=t['final_priority']:errors.append({'priority':cpu.priority,'expected':t['final_priority']})
 if pending.entry!=t['boundary'] or list(pending.args)!=t['pending_args']:errors.append({'pending_ABI':list(pending.args),'expected':t['pending_args']})
 if errors:fails.append({'case':t['case'],'op':t['op'],'errors':errors})
 counts[str(t['op'])]+=1;boundaries[hex(t['boundary'])]+=1
 if not t['boundary']:returns['original_full_return']+=1
paths=files+list(P.glob('*.h'))+[Path(__file__),R/'ghidra-scripts/EmulateReceiverRtcDispatch.java',A/'receiver-rtc-dispatch-original.jsonl']
report={'status':'PASS' if not fails else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'counts':dict(counts),'boundaries':dict(boundaries),'original_returns':dict(returns),'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['Full inert RAM/MMIO and serialized privileged CPU comparisons; hardware readback/event generation not autonomous','Application timer expiry0E06EB00 and RTC callback0E05BDE0 stop at their real entries; fixture-injected unknown timeout0E06C000 also stops before execution, not observed registered callback','Supported thread/timeslice callbacks and end-of-tick scheduler updates execute original instructions; application timer expiry remains boundary','Top generic ISR, exception return, real clock/RF/CPU concurrency remain unverified']}
(A/'receiver-rtc-handlers-regression.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']},indent=2));print(json.dumps(fails[:8],indent=2));assert not fails
