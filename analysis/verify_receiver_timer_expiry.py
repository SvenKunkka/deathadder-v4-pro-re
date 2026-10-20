from pathlib import Path
import ctypes as C,json,subprocess,hashlib,gzip,base64,collections
R=Path(__file__).resolve().parent.parent;P=R/'recovered-code/portable';A=R/'analysis';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
files=sorted(P.glob('*.c'))
lib=A/'libreceiver_timer_expiry.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True)
f=C.CDLL(str(lib))
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
class HW(C.Structure):_fields_=[('ram',Ptr),('rtc',Ptr)]
class Pending(C.Structure):_fields_=[('entry',W),('args',W*5)]
f.rr_receiver_timeout_announce_timers.argtypes=[C.POINTER(HW),Ptr,W,C.POINTER(CPU),C.POINTER(Pending)]
f.rr_receiver_clock_announce_timers.argtypes=[C.POINTER(HW),Ptr,C.c_uint64,C.POINTER(CPU),C.POINTER(Pending)]
f.rr_receiver_rtc_dispatch_timers.argtypes=[C.POINTER(HW),Ptr,C.POINTER(CPU),C.POINTER(Pending)]

f.rr_receiver_timer_expiry.argtypes=[Ptr,Ptr,Ptr,W,C.POINTER(CPU)]
image=(U*124596).from_buffer_copy((R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes())

def un(z):return gzip.decompress(base64.b64decode(z))
def buf(b):return (U*len(b)).from_buffer_copy(b)
def diff(name,got,expect):
 if got==expect:return []
 ds=[i for i in range(len(expect)) if got[i]!=expect[i]];return [{name+'_diffs':len(ds),'first':[(hex(i),got[i],expect[i]) for i in ds[:12]]}]
rows=[json.loads(s) for s in (A/'receiver-timer-expiry-original.jsonl').read_text().splitlines()];assert len(rows)==8192
fails=[];counts=collections.Counter();boundaries=collections.Counter();returns=collections.Counter()
for t in rows:
 m=buf(un(t['before_gzip']));rtc=buf(un(t['rtc_before']));cpu=CPU(t['initial_priority'],t['exception'],0,0)
 hw=HW(m,rtc)
 pending=Pending()
 if t['op']==0:
  rc=f.rr_receiver_timer_expiry(m,rtc,image,0x23001a30,C.byref(cpu))
  if rc==1:pending.entry=cpu.entry;pending.args[0]=cpu.arg0
 elif t['op']==1:rc=f.rr_receiver_timeout_announce_timers(C.byref(hw),image,t['ticks'],C.byref(cpu),C.byref(pending))
 elif t['op']==2:rc=f.rr_receiver_clock_announce_timers(C.byref(hw),image,t['deadline'],C.byref(cpu),C.byref(pending))
 else:rc=f.rr_receiver_rtc_dispatch_timers(C.byref(hw),image,C.byref(cpu),C.byref(pending))
 errors=[]
 for label,got,key in [('RAM',m,'after_gzip'),('RTC',rtc,'rtc_after')]:errors+=diff(label,bytes(got),un(t[key]))
 if rc!=(1 if t['boundary'] else 0):errors.append({'return':rc,'boundary':t['boundary']})
 if cpu.entry!=t['boundary'] or cpu.arg0!=t['arg0']:errors.append({'pending':(hex(cpu.entry),hex(cpu.arg0)),'expected':(hex(t['boundary']),hex(t['arg0']))})
 if cpu.priority!=t['final_priority']:errors.append({'priority':cpu.priority,'expected':t['final_priority']})
 if pending.entry!=t['boundary'] or list(pending.args)!=t['pending_args']:errors.append({'pending_ABI':list(pending.args),'expected':t['pending_args']})
 if errors:fails.append({'case':t['case'],'op':t['op'],'errors':errors})
 counts[str(t['op'])]+=1;boundaries[hex(t['boundary'])]+=1
 if not t['boundary']:returns['original_full_return']+=1
paths=files+list(P.glob('*.h'))+[Path(__file__),R/'ghidra-scripts/EmulateReceiverTimerExpiry.java',A/'receiver-timer-expiry-original.jsonl']
report={'status':'PASS' if not fails else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'counts':dict(counts),'boundaries':dict(boundaries),'original_returns':dict(returns),'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['Full inert RAM/MMIO and serialized privileged CPU comparisons; hardware readback/event generation not autonomous','Original generic timer expiry and registered230255B8 disconnect callback execute; injected unknown user23024FD8/timeout0E06C000 and RTC callback0E05BDE0 stop before entry','Supported thread/timeslice callbacks and end-of-tick scheduler updates execute original instructions; unknown application callbacks remain boundaries','Top generic ISR, exception return, real clock/RF/CPU concurrency remain unverified']}
(A/'receiver-timer-expiry-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']},indent=2));print(json.dumps(fails[:8],indent=2));assert not fails
