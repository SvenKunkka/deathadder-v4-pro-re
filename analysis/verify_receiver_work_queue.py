from pathlib import Path
import json,hashlib,ctypes as C,subprocess,base64,gzip,collections
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;I=C.c_int32;Q=C.c_uint64;Ptr=C.POINTER(U)
files=sorted(P.glob('*.c'));lib=A/'libreceiver_work_queue.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True);f=C.CDLL(str(lib))
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
f.rr_receiver_work_submit_to_queue.argtypes=[Ptr,Ptr,W,C.POINTER(W),C.POINTER(CPU),C.POINTER(I)]
f.rr_receiver_work_submit.argtypes=[Ptr,Ptr,W,W,C.POINTER(CPU),C.POINTER(I)]
f.rr_receiver_delayed_work_schedule.argtypes=[Ptr,Ptr,W,W,Q,C.c_int,C.POINTER(CPU),C.POINTER(I)]
f.rr_receiver_delayed_work_expiry.argtypes=[Ptr,Ptr,W,C.POINTER(CPU)]
f.rr_receiver_work_cancel.argtypes=[Ptr,W,C.POINTER(CPU),C.POINTER(W)]
f.rr_receiver_work_initialize.argtypes=[Ptr,W,W,C.c_int]
def un(z):return gzip.decompress(base64.b64decode(z))
rows=[json.loads(l) for l in (A/'receiver-work-queue-original.jsonl').open()];assert len(rows)==2816 and [t['case'] for t in rows]==list(range(2816));fails=[];ends=collections.Counter()
for t in rows:
 bm=un(t['before_gzip']);br=un(t['rtc_before']);assert len(bm)==131072 and len(br)==4096;m=(U*len(bm)).from_buffer_copy(bm);r=(U*len(br)).from_buffer_copy(br);cpu=CPU(t['initial_priority'],t['exception'],0,0);result=I(0x12345678);q=W(t['queue']);out=W();op=t['op'];a=t['address']
 if op==0:rc=f.rr_receiver_work_submit_to_queue(m,r,a,C.byref(q),C.byref(cpu),C.byref(result))
 elif op in [1,2]:rc=f.rr_receiver_work_submit(m,r,a,0x23002b18 if op==1 else q.value,C.byref(cpu),C.byref(result))
 elif op in [3,4,5,6]:rc=f.rr_receiver_delayed_work_schedule(m,r,0x23002b18 if op in [4,6] else q.value,a,int(t['timeout']),int(op>=5),C.byref(cpu),C.byref(result))
 elif op==7:rc=f.rr_receiver_delayed_work_expiry(m,r,a+16,C.byref(cpu))
 elif op==8:rc=f.rr_receiver_work_cancel(m,a,C.byref(cpu),C.byref(out));result.value=out.value
 else:rc=f.rr_receiver_work_initialize(m,a,t['callback'],int(op==10))
 errors=[]
 for n,b,z in [('ram',bytes(m),'after_gzip'),('rtc',bytes(r),'rtc_after')]:
  expected=un(t[z]);assert len(b)==len(expected)
  if b!=expected:
   diffs=[i for i in range(len(b)) if b[i]!=expected[i]];errors.append({'window':n,'count':len(diffs),'first':[(hex(i),b[i],expected[i]) for i in diffs[:10]]})
 if rc!=bool(t['boundary']):errors.append({'rc':rc,'expected_boundary':t['boundary']})
 if op in [0,1,2,3,4,5,6,8] and not t['boundary'] and result.value&0xffffffff!=t['return']&0xffffffff:errors.append({'result':result.value,'expected':t['return']})
 if op==0 and q.value!=t['queue_after']:errors.append({'queue':q.value,'expected':t['queue_after']})
 if cpu.priority!=t['final_priority'] or cpu.entry!=t['boundary'] or cpu.arg0!=t['arg0']:errors.append({'cpu':[cpu.priority,cpu.entry,cpu.arg0],'expected':[t['final_priority'],t['boundary'],t['arg0']]})
 if errors:fails.append({'case':t['case'],'op':op,'errors':errors})
 ends[hex(t['boundary'])]+=1
paths=files+list(P.glob('*.h'))+[Path(__file__),R/'ghidra-scripts/EmulateReceiverWorkQueue.java',A/'receiver-work-queue-original.jsonl']
d={'status':'PASS' if not fails else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'endings':dict(ends),'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['Privileged serialized CPU with stable RTC, bounded coherent lists and full128KiB RAM/4KiB RTC snapshots','Eleven groups256 inputs:helper submit,default/explicit wrappers,four schedule/reschedule entries,expiry,cancel,twoinitializers','Stops at actual CPU request; no resumed thread/callback or physicalUSB/RF behavior asserted']}
(A/'receiver-work-queue-comparison.json').write_text(json.dumps(d,indent=2)+'\n');print(json.dumps({k:v for k,v in d.items() if k not in ['sources','failures']},indent=2));print(json.dumps(fails[:6],indent=2));assert not fails
