from pathlib import Path
import json,hashlib,ctypes as C,subprocess,base64,gzip,collections
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;I=C.c_int32;Q=C.c_uint64;Ptr=C.POINTER(U)
files=sorted(P.glob('*.c'));lib=A/'libreceiver_worker_vendor_phase63.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True);f=C.CDLL(str(lib))
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
class Call(C.Structure):_fields_=[('entry',W),('device',W),('length',W),('buffer',W)]
Hook=C.CFUNCTYPE(I,C.c_void_p,Ptr,C.POINTER(Call))
f.rr_receiver_wait_wake.argtypes=[Ptr,Ptr,W,W,W,C.POINTER(CPU),C.POINTER(I)]
f.rr_receiver_worker_yield.argtypes=[Ptr,Ptr,C.POINTER(CPU)]
f.rr_receiver_worker_pend.argtypes=[Ptr,Ptr,W,W,Q,C.POINTER(CPU)]
f.rr_receiver_work_thread_step.argtypes=[Ptr,Ptr,Ptr,W,C.POINTER(CPU),Hook,C.c_void_p,C.POINTER(Call)]
def un(z):return gzip.decompress(base64.b64decode(z))
rows=[json.loads(l) for l in (A/'receiver-worker-runtime-original.jsonl').open()];assert len(rows)==3072 and [t['case'] for t in rows]==list(range(3072));fails=[];ends=collections.Counter();groups=collections.defaultdict(collections.Counter);external=0;coverage=collections.Counter()
for t in rows:
 bm=un(t['ram_before']);br=un(t['rtc_before']);ba=un(t['aux_before']);assert len(bm)==131072 and len(br)==len(ba)==4096;m=(U*len(bm)).from_buffer_copy(bm);r=(U*len(br)).from_buffer_copy(br);a=(U*len(ba)).from_buffer_copy(ba);cpu=CPU(t['initial_priority'],t['exception'],0,0);result=I(0x12345678);pending=Call();calls=[];op=t['op']
 def record(c):return {k:getattr(c,k) for k in ['entry','device','length','buffer']}|{'payload':bytes(m[c.buffer-0x23000000:c.buffer-0x23000000+c.length]).hex()}
 @Hook
 def driver(_,mem,ptr):
  c=ptr.contents;ch={0xe06f6a4:0,0xe06f690:1,0xe06f67c:2}[c.device];v=t['v'];value=0 if (v+ch)%2==0 else -13;calls.append(record(c)|{'external_result':value});return value
 if op==0:rc=f.rr_receiver_wait_wake(m,r,t['queue']+0xa0,t['wake_result'],t['wake_data'],C.byref(cpu),C.byref(result))
 elif op==1:rc=f.rr_receiver_worker_yield(m,r,C.byref(cpu))
 elif op==2:rc=f.rr_receiver_worker_pend(m,r,t['wait_queue'],t['saved_priority'],int(t['timeout']),C.byref(cpu))
 else:rc=f.rr_receiver_work_thread_step(m,r,a,t['queue'],C.byref(cpu),driver if op==5 else Hook(),None,C.byref(pending))
 if t['boundary']==0xe064288:calls.append(record(pending)|{'external_result':None})
 errors=[]
 for n,b,z in [('ram',bytes(m),'ram_after'),('rtc',bytes(r),'rtc_after'),('aux',bytes(a),'aux_after')]:
  expected=un(t[z]);assert len(b)==len(expected)
  if b!=expected:
   diffs=[i for i in range(len(b)) if b[i]!=expected[i]];errors.append({'window':n,'count':len(diffs),'first':[(hex(i),b[i],expected[i]) for i in diffs[:12]]})
 if rc!=bool(t['boundary']):errors.append({'rc':rc,'boundary':t['boundary']})
 if op==0 and not t['boundary'] and result.value&0xffffffff!=t['return']&0xffffffff:errors.append({'result':result.value,'expected':t['return']})
 if [cpu.priority,cpu.entry,cpu.arg0]!=[t['final_priority'],t['boundary'],t['arg0']]:errors.append({'cpu':[cpu.priority,cpu.entry,cpu.arg0],'expected':[t['final_priority'],t['boundary'],t['arg0']]})
 if calls!=t['calls']:errors.append({'calls':calls,'expected':t['calls']})
 if errors:fails.append({'case':t['case'],'op':op,'errors':errors})
 if op>=3:
  def word(b,o):return int.from_bytes(b[o:o+4],'little')
  before=bm;after=un(t['ram_after']);q=t['queue']-0x23000000
  if not word(before,q+0x90):
   coverage['empty_queue_to_CPU']+=int(t['boundary']==0xe0611cc)
   if word(before,q+0xa8)&4:coverage['drain_mark_cleared']+=int(not word(after,q+0xa8)&4)
  elif t['boundary'] not in [0x230205f8,0xe064288]:
   coverage['known_callback_completed']+=1
   flags=word(before,0x780c)
   if flags&16:coverage['flush_flag_cleared']+=int(not word(after,0x780c)&16)
   if flags&2:
    coverage['cancel_flag_cleared']+=int(not word(after,0x780c)&2)
    node=word(before,0x2bc8)
    while node:
     off=node-0x23000000
     if word(before,off+4)==0x23007800:
      coverage['cancel_waiter_node_unlinked']+=int(word(after,off)==0 and word(after,0x2bc8)!=node);break
     node=word(before,off)
 kind=hex(t['boundary']) if t['boundary'] else 'next_worker_header' if op>=3 else 'helper_return';ends[kind]+=1;groups[str(op)][kind]+=1;external+=bool(t['calls'] and op==5)
paths=files+list(P.glob('*.h'))+[Path(__file__),R/'ghidra-scripts/EmulateReceiverWorkerRuntime.java',A/'receiver-worker-runtime-original.jsonl']
d={'status':'PASS' if not fails else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'endings':dict(ends),'groups':dict(groups),'worker_inputs_with_external_USB':external,'worker_coverage':dict(coverage),'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'libraries':{str(lib.relative_to(R)):hashlib.sha256(lib.read_bytes()).hexdigest()},'limits':['Serialized privilegedCPU and coherent bounded lists, full128KiBRAM and4KiBRTC/aux compared','Worker stops at next loop header or actualCPU/unknowncallback/USBentry; no thread termination or resumedCPU claimed','Group5 explicitly supplies USB result and resumes software; physicalUSB/RF, dynamichardware and concurrency not validated']}
(A/'receiver-worker-vendor-regression.json').write_text(json.dumps(d,indent=2)+'\n');print(json.dumps({k:v for k,v in d.items() if k not in ['sources','libraries','failures']},indent=2));print(json.dumps(fails[:8],indent=2));assert not fails
