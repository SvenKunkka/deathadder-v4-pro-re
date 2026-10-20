from pathlib import Path
import ctypes as C,json,subprocess,hashlib,gzip,base64,collections
R=Path(__file__).resolve().parent.parent;P=R/'recovered-code/portable';A=R/'analysis';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
files=[P/(n+'.c') for n in ['receiver_timeout','receiver_rtos_lifecycle','receiver_radio_timer','receiver_radio_irq','receiver_business_flow','business_dispatch','business_rx','business_cipher','business_control','business_tx','dongle_business_consumer']]
lib=A/'libreceiver_timeout.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True)
f=C.CDLL(str(lib))
f.rr_receiver_timeout_abort.argtypes=[Ptr,Ptr,W,C.POINTER(C.c_int32)];f.rr_receiver_timeout_start.argtypes=[Ptr,Ptr,W,W,C.c_uint64]
def un(z):return gzip.decompress(base64.b64decode(z))
def buf(b):return (U*len(b)).from_buffer_copy(b)
def diff(name,got,expect):
 if got==expect:return []
 ds=[i for i in range(len(expect)) if got[i]!=expect[i]]
 return [{name+'_diffs':len(ds),'first':[(hex(i),got[i],expect[i]) for i in ds[:12]]}]
rows=[json.loads(s) for s in (A/'receiver-timeout-original.jsonl').read_text().splitlines()];assert len(rows)==2048
fails=[];counts=collections.Counter();changed=collections.Counter()
for t in rows:
 m=buf(un(t['before_gzip']));rtc=buf(un(t['rtc_before']));value=C.c_int32(0)
 if t['op']==0:rc=f.rr_receiver_timeout_abort(m,rtc,t['address'],C.byref(value))
 else:rc=f.rr_receiver_timeout_start(m,rtc,t['address'],t['callback'],int(t['delay']))
 errors=diff('RAM',bytes(m),un(t['after_gzip']))+diff('RTC',bytes(rtc),un(t['rtc_after']))
 if rc:errors.append({'model_rc':rc})
 if t['initial_priority']!=t['final_priority']:errors.append({'original_priority_not_restored':t['final_priority']})
 if t['op']==0 and value.value&0xffffffff!=t['return']:errors.append({'abort_return':value.value,'expected':t['return']})
 if errors:fails.append({'case':t['case'],'op':t['op'],'delay':t['delay'],'errors':errors})
 counts[str(t['op'])]+=1
 if t['rtc_before']!=t['rtc_after']:changed[str(t['op'])]+=1
paths=files+[P/'receiver_timeout.h',P/'receiver_rtos_lifecycle.h',Path(__file__),R/'ghidra-scripts/EmulateReceiverTimeout.java',A/'receiver-timeout-original.jsonl']
report={'status':'PASS' if not fails else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'counts':dict(counts),'RTC_changed':dict(changed),'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['128KiB RAM and4KiB RTC register snapshots; explicit stable clock input','original CPU base-priority getter bridges same built-in state as setter; instruction barrier inert; no function-call stubs','original timeout callback registration recovered; future expiry and thread context switch not executed','invalid list domain and high-word busy clock are host boundaries, not fabricated successful firmware behavior']}
(A/'receiver-timeout-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']},indent=2));print(json.dumps(fails[:8],indent=2));assert not fails
