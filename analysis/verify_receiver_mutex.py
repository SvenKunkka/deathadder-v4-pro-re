from pathlib import Path
import ctypes as C,json,subprocess,hashlib,gzip,base64,collections
R=Path(__file__).resolve().parent.parent;P=R/'recovered-code/portable';A=R/'analysis';U=C.c_uint8;W=C.c_uint32;Q=C.c_uint64;I=C.c_int32;Ptr=C.POINTER(U)
files=sorted(P.glob('*.c'));lib=A/'libreceiver_mutex.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True);f=C.CDLL(str(lib))
class CPU(C.Structure):_fields_=[('priority',W),('exception',W),('entry',W),('arg0',W)]
class State(C.Structure):_fields_=[('mutex',W),('changed',W),('phase',W)]
f.rr_receiver_mutex_lock.argtypes=[Ptr,Ptr,W,Q,C.POINTER(CPU),C.POINTER(State),C.POINTER(I)]
f.rr_receiver_mutex_unlock.argtypes=[Ptr,Ptr,W,C.POINTER(CPU),C.POINTER(State),C.POINTER(I)]
f.rr_receiver_mutex_resume.argtypes=[Ptr,Ptr,C.POINTER(CPU),C.POINTER(State),I,C.POINTER(I)]
f.rr_receiver_thread_priority_set.argtypes=[Ptr,Ptr,W,C.c_int8,C.POINTER(CPU),C.POINTER(I)]
un=lambda s:gzip.decompress(base64.b64decode(s));arr=lambda b:(U*len(b)).from_buffer_copy(b)
rows=[json.loads(s) for s in (A/'receiver-mutex-original.jsonl').read_text().splitlines()];assert len(rows)==2240 and [t['case'] for t in rows]==list(range(2240))
failures=[];counts=collections.Counter();returns=collections.Counter()
for t in rows:
 m=arr(un(t['ram_before']));r=arr(un(t['rtc_before']));cpu=CPU(t['initial_priority'],t['exception'],0,0);state=State(0x23007000,t['changed'],2 if t['op']==4 else 3 if t['op']==5 else 1);result=I(0x12345678);op=t['op'];err=[]
 if op==0:rc=f.rr_receiver_mutex_lock(m,r,0x23007000,int(t['timeout']),C.byref(cpu),C.byref(state),C.byref(result))
 elif op==1:rc=f.rr_receiver_mutex_unlock(m,r,0x23007000,C.byref(cpu),C.byref(state),C.byref(result))
 elif op==2:rc=f.rr_receiver_thread_priority_set(m,r,0x23006100,t['newpriority'],C.byref(cpu),C.byref(result))
 else:rc=f.rr_receiver_mutex_resume(m,r,C.byref(cpu),C.byref(state),I(t['pendresult']),C.byref(result))
 pending=t['boundary']!=0
 if rc!=(1 if pending else 0):err.append({'status':rc,'want':1 if pending else 0})
 if pending:
  if (cpu.entry,cpu.arg0)!=(t['boundary'],t['arg0']):err.append({'boundary':[cpu.entry,cpu.arg0],'want':[t['boundary'],t['arg0']]})
  if result.value!=0x12345678:err.append({'invented_result':result.value})
  if op==0 and state.changed!=t['saved_changed']:err.append({'changed':state.changed,'want':t['saved_changed']})
  if state.phase!={0:1,1:3,3:2}[op]:err.append({'phase':state.phase})
 else:
  if result.value&0xffffffff!=t['return']:err.append({'return':result.value&0xffffffff,'want':t['return']})
 if cpu.priority!=t['final_priority']:err.append({'priority':cpu.priority,'want':t['final_priority']})
 for name,b in [('ram',m),('rtc',r)]:
  expected=un(t[name+'_after'])
  if bytes(b)!=expected:
   ds=[j for j in range(len(expected)) if b[j]!=expected[j]];err.append({name+'_diffs':len(ds),'first':[(hex(j),b[j],expected[j]) for j in ds[:12]]})
 if err:failures.append({'case':t['case'],'op':op,'errors':err})
 counts[str(op)+('_CPU_boundary' if pending else '_return')]+=1
 if not pending:returns[str(op)+':'+hex(t['return'])]+=1
paths=files+[P/'receiver_mutex.h',Path(__file__),R/'ghidra-scripts/EmulateReceiverMutex.java',A/'receiver-mutex-original.jsonl']
report={'status':'PASS' if not failures else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'counts':dict(counts),'return_histogram':dict(returns),'failures':failures,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['Privileged serialized CPU, valid bounded lists, static RTC input','CPU request entry0E0611CC remains a real stop; no lock result supplied on pending','Resume cases start at original CE22/CE7E/CF04 with explicit post-CPU RAM/result; do not prove CPU continuation or actual scheduling','Full128KiB RAM and4KiB RTC checked; temporary stack excluded']}
(A/'receiver-mutex-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']},indent=2));print(json.dumps(failures[:12],indent=2));assert not failures
