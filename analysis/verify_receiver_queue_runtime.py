from pathlib import Path
import ctypes as C,json,subprocess,hashlib,gzip,base64,collections
R=Path(__file__).resolve().parent.parent;P=R/'recovered-code/portable';A=R/'analysis';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
files=sorted(P.glob('*.c'))
lib=A/'libreceiver_queue_runtime.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True)
f=C.CDLL(str(lib));names=['ram','radio','timer','nvic','dppi','rtc','clock0','clock1','clock2','deviceid']
class HW(C.Structure):_fields_=[(n,Ptr) for n in names]
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
f.rr_receiver_message_get.argtypes=[Ptr,Ptr,W,W,Ptr,C.c_uint64,C.POINTER(CPU),C.POINTER(C.c_int32)]
f.rr_receiver_config_iteration.argtypes=[C.POINTER(HW),W,Ptr,U,Ptr,C.POINTER(CPU)]
image=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();table=(U*256).from_buffer_copy(image[0x1ba74:0x1bb74])
def un(z):return gzip.decompress(base64.b64decode(z))
rows=[json.loads(s) for s in (A/'receiver-queue-runtime-original.jsonl').read_text().splitlines()];assert len(rows)==4096
fails=[];counts=collections.Counter();phy=collections.Counter();channels=set();returns=collections.Counter()
for t in rows:
 mem={n:(U*len(un(t[n+'_before']))).from_buffer_copy(un(t[n+'_before'])) for n in names};hw=HW(*[mem[n] for n in names])
 cpu=CPU(t['initial_priority'],t['exception'],0,0);result=C.c_int32(0x12345678)
 if t['op']==0:
  message=C.cast(C.byref(mem['ram'],t['output']-0x23000000),Ptr)
  rc=f.rr_receiver_message_get(mem['ram'],mem['rtc'],t['queue'],t['output'],message,int(t['timeout']),C.byref(cpu),C.byref(result))
 else:
  message=(U*36).from_buffer_copy(bytes.fromhex(t['message_before']))
  rc=f.rr_receiver_config_iteration(C.byref(hw),t['output'],message,t['phy'],table,C.byref(cpu))
 errors=[]
 if bytes(message[:36]).hex()!=t['message_after']:errors.append({'message':bytes(message[:36]).hex(),'want':t['message_after']})
 if t['op']==0 and not t['boundary'] and (result.value&0xffffffff)!=t['return']:errors.append({'result':result.value,'want':t['return']})
 for n in names:
  got=bytes(mem[n]);expect=un(t[n+'_after'])
  if got!=expect:
   ds=[i for i in range(len(expect)) if got[i]!=expect[i]];errors.append({'window':n,'diffs':len(ds),'first':[(hex(i),got[i],expect[i]) for i in ds[:12]]})
 if rc!=bool(t['boundary']):errors.append({'return':rc,'want':bool(t['boundary'])})
 if cpu.entry!=t['boundary'] or cpu.arg0!=t['arg0']:errors.append({'boundary':[hex(cpu.entry),hex(cpu.arg0)],'want':[hex(t['boundary']),hex(t['arg0'])]})
 if cpu.priority!=t['final_priority']:errors.append({'priority':cpu.priority,'want':t['final_priority']})
 if errors:fails.append({'case':t['case'],'op':t['op'],'event':t['event'],'errors':errors})
 counts[str(t['op'])]+=1;returns['cpu_request' if t['boundary']==0xe0611cc else 'synthetic_stop_callback' if t['boundary'] else 'next_loop_head' if t['op']==1 else 'full_return']+=1
paths=files+[P/'receiver_queue_runtime.h',Path(__file__),R/'ghidra-scripts/EmulateReceiverQueueRuntime.java',A/'receiver-queue-runtime-original.jsonl']
report={'status':'PASS' if not fails else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'counts':dict(counts),'endings':dict(returns),'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['Ten inert memory windows, no autonomous IRQ/RTC/radio hardware','Config iteration begins before message_get; stops at next loop, real CPU request, or synthetic stop callback','Synthetic stop callback 23024fd8 is a test boundary, not a claimed production registration','No nested continuation is fabricated; CPU/callback stack continuation, crosscore startup and real RF remain incomplete']}
(A/'receiver-queue-runtime-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']},indent=2));print(json.dumps(fails[:8],indent=2));assert not fails
