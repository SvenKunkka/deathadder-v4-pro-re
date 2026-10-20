from pathlib import Path
import ctypes as C,json,subprocess,hashlib,gzip,base64,collections
R=Path(__file__).resolve().parent.parent;P=R/'recovered-code/portable';A=R/'analysis';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
files=[P/(n+'.c') for n in ['receiver_timeout','receiver_rtos_lifecycle','receiver_radio_timer','receiver_radio_irq','receiver_business_flow','business_dispatch','business_rx','business_cipher','business_control','business_tx','dongle_business_consumer']]
lib=A/'libreceiver_rtos_timed.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True)
f=C.CDLL(str(lib))
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
f.rr_receiver_semaphore_give_timed.argtypes=[Ptr,Ptr,W,C.POINTER(CPU)];f.rr_receiver_message_put_timed.argtypes=[Ptr,Ptr,W,Ptr,C.POINTER(CPU),C.POINTER(C.c_int32)];f.rr_receiver_message_purge_timed.argtypes=[Ptr,Ptr,W,C.POINTER(CPU)];f.rr_receiver_disconnect_notice_timed.argtypes=[Ptr,Ptr,Ptr,Ptr,C.POINTER(CPU)]
rows=[json.loads(s) for s in (A/'receiver-rtos-timed-original.jsonl').read_text().splitlines()];assert len(rows)==1536
fails=[];counts=collections.Counter();boundaries=collections.Counter()
def un(z):return gzip.decompress(base64.b64decode(z))
def buf(b):return (U*len(b)).from_buffer_copy(b)
for t in rows:
 m=buf(un(t['before_gzip']));rtc=buf(un(t['rtc_before']));cpu=CPU(t['initial_priority'],t['exception'],0,0);value=C.c_int32(0)
 if t['op']==0:rc=f.rr_receiver_semaphore_give_timed(m,rtc,t['address'],C.byref(cpu))
 elif t['op']==1:rc=f.rr_receiver_message_put_timed(m,rtc,t['address'],buf(bytes.fromhex(t['message'])),C.byref(cpu),C.byref(value))
 elif t['op']==2:rc=f.rr_receiver_message_purge_timed(m,rtc,t['address'],C.byref(cpu))
 else:rc=f.rr_receiver_disconnect_notice_timed(m,rtc,buf(bytes.fromhex(t['pair'])),buf(bytes.fromhex(t['opaque_tail'])),C.byref(cpu))
 errors=[];expected=un(t['after_gzip']);actual=bytes(m)
 if actual!=expected:
  ds=[i for i in range(len(expected)) if expected[i]!=actual[i]];errors.append({'RAM_diffs':len(ds),'first':[(hex(i),actual[i],expected[i]) for i in ds[:12]]})
 if bytes(rtc)!=un(t['rtc_after']):
  ds=[i for i in range(4096) if rtc[i]!=un(t['rtc_after'])[i]];errors.append({'RTC_diffs':len(ds),'first':[(hex(i),rtc[i],un(t['rtc_after'])[i]) for i in ds[:12]]})
 if rc!=(1 if t['boundary'] else 0):errors.append({'return':rc,'boundary':t['boundary']})
 if cpu.entry!=t['boundary'] or cpu.arg0!=t['arg0']:errors.append({'pending':(hex(cpu.entry),hex(cpu.arg0)),'expected':(hex(t['boundary']),hex(t['arg0']))})
 if cpu.priority!=t['final_priority']:errors.append({'priority':cpu.priority,'expected':t['final_priority']})
 if not t['boundary'] and t['op']==1 and value.value&0xffffffff!=t['return']:errors.append({'put_return':value.value,'expected':t['return']})
 if errors:fails.append({'case':t['case'],'op':t['op'],'errors':errors})
 counts[str(t['op'])]+=1;boundaries[hex(t['boundary'])]+=1
paths=files+[P/'receiver_rtos_lifecycle.h',P/'receiver_timeout.h',Path(__file__),R/'ghidra-scripts/EmulateReceiverRtosTimed.java',A/'receiver-rtos-timed-original.jsonl']
report={'status':'PASS' if not fails else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'counts':dict(counts),'boundaries':dict(boundaries),'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['128KiB RAM and4KiB RTC snapshots plus serialized CPU priority/exception model','active timeout abort and timeslice start execute real original code; actual thread context switch remains a real boundary with prior side effects retained','message type2 copies24 bytes of explicit previous stack data, not initialized payload','no RF/device writes or actual scheduler execution']}
(A/'receiver-rtos-timed-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']},indent=2));print(json.dumps(fails[:8],indent=2));assert not fails
