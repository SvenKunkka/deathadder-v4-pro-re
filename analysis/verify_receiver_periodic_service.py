from pathlib import Path
import json,hashlib,ctypes as C,subprocess,base64,gzip,collections
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Q=C.c_uint64;Ptr=C.POINTER(U)
files=sorted(P.glob('*.c'));lib=A/'libreceiver_periodic_service.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True);f=C.CDLL(str(lib))
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
class Pending(C.Structure):_fields_=[('entry',W),('args',W*5)]
f.rr_receiver_clock_allocate.argtypes=[Ptr];f.rr_receiver_clock_allocate.restype=W
f.rr_receiver_periodic_init.argtypes=[Ptr,Ptr,C.POINTER(W)]
f.rr_receiver_periodic_refresh.argtypes=[Ptr,Ptr,Ptr,C.POINTER(W)]
f.rr_receiver_clock_deadline.argtypes=[Ptr,Ptr,Q,C.POINTER(Q)]
f.rr_receiver_clock_alarm.argtypes=[Ptr,Ptr,W,Q,W,W];f.rr_receiver_clock_alarm.restype=W
f.rr_receiver_periodic_dispatch.argtypes=[Ptr,Ptr,Ptr,Ptr,C.POINTER(CPU),C.POINTER(Pending)]
fwraw=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();fw=(U*len(fwraw)).from_buffer_copy(fwraw)
def un(z):return gzip.decompress(base64.b64decode(z))
rows=[json.loads(l) for l in (A/'receiver-periodic-service-original.jsonl').open()];assert len(rows)==1792 and [t['case'] for t in rows]==list(range(1792));fails=[];ends=collections.Counter()
for t in rows:
 bs={n:un(t[n+'_before']) for n in ['ram','rtc','service']};assert all(len(b)==(131072 if n=='ram' else 4096) for n,b in bs.items());mem={n:(U*len(b)).from_buffer_copy(b) for n,b in bs.items()};m,r,s=[mem[n] for n in ['ram','rtc','service']];cpu=CPU(t['initial_priority'],125,0,0);p=Pending();out=W();wide=Q();op=t['op'];rc=0
 if op==0:out.value=f.rr_receiver_clock_allocate(m)
 elif op==1:rc=f.rr_receiver_periodic_init(m,s,C.byref(out))
 elif op in [2,3]:rc=f.rr_receiver_periodic_refresh(m,r,s,C.byref(out))
 elif op==4:rc=f.rr_receiver_clock_deadline(m,r,int(t['duration']),C.byref(wide))
 elif op==5:out.value=f.rr_receiver_clock_alarm(m,r,t['channel'],int(t['deadline']),t['callback'],t['user'])
 else:rc=f.rr_receiver_periodic_dispatch(m,r,s,fw,C.byref(cpu),C.byref(p))
 errors=[]
 for n in mem:
  got=bytes(mem[n]);expected=un(t[n+'_after']);assert len(got)==len(expected)
  if got!=expected:
   diff=[i for i in range(len(got)) if got[i]!=expected[i]];errors.append({'window':n,'count':len(diff),'first':[(hex(i),got[i],expected[i]) for i in diff[:8]]})
 if rc!=bool(t['boundary']):errors.append({'rc':rc,'boundary':t['boundary']})
 if op==4 and wide.value!=(t['r0']|t['r1']<<32):errors.append({'wide':wide.value,'expected':t['r0']|t['r1']<<32})
 if op<6 and op!=4 and out.value!=t['r0']:errors.append({'r0':out.value,'expected':t['r0']})
 if cpu.priority!=t['final_priority']:errors.append({'priority':cpu.priority,'expected':t['final_priority']})
 if p.entry!=t['boundary'] or list(p.args)!=t['pending_args']:errors.append({'pending':[p.entry,list(p.args)],'expected':[t['boundary'],t['pending_args']]})
 if errors:fails.append({'case':t['case'],'op':op,'errors':errors})
 ends[hex(t['boundary'])]+=1
paths=files+list(P.glob('*.h'))+[Path(__file__),R/'ghidra-scripts/EmulateReceiverPeriodicService.java',A/'receiver-periodic-service-original.jsonl']
d={'status':'PASS' if not fails else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'endings':dict(ends),'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['Privileged serialized CPU and stable RTC4KiB/service4KiB snapshots; no real peripheral or atomic contention','Seven entry groups of256inputs: allocate,init,BDE0,BE4C,deadline,alarm,RTC dispatch','Unknown callbacks preserve entry/5argument ABI; not full boot, interrupt return, or actual periodic hardware']}
(A/'receiver-periodic-service-comparison.json').write_text(json.dumps(d,indent=2)+'\n');print(json.dumps({k:v for k,v in d.items() if k not in ['sources','failures']},indent=2));print(json.dumps(fails[:5],indent=2));assert not fails
