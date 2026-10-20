from pathlib import Path
import ctypes as C,json,subprocess,hashlib,gzip,base64,collections
R=Path(__file__).resolve().parent.parent;P=R/'recovered-code/portable';A=R/'analysis';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
files=sorted(P.glob('*.c'))
lib=A/'libreceiver_work_rtc_regression.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True)
f=C.CDLL(str(lib));names=['ram','radio','timer','nvic','dppi','rtc','clock0','clock1','clock2','deviceid']
class HW(C.Structure):_fields_=[(n,Ptr) for n in names]
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
class Pending(C.Structure):_fields_=[('entry',W),('args',W*5)]
f.rr_receiver_rtc_work_dispatch.argtypes=[C.POINTER(HW),Ptr,Ptr,Ptr,C.POINTER(CPU),C.POINTER(Pending)]
image=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();table=(U*256).from_buffer_copy(image[0x1ba74:0x1bb74])
flash=(U*len(image)).from_buffer_copy(image)
def un(z):return gzip.decompress(base64.b64decode(z))
rows=[json.loads(s) for s in (A/'receiver-rtc-application-timers-original.jsonl').read_text().splitlines()];assert len(rows)==2048
fails=[];counts=collections.Counter();phy=collections.Counter();channels=set();returns=collections.Counter()
for t in rows:
 decoded={n:un(t[n+'_before']) for n in names}
 assert all(len(decoded[n])==(131072 if n=='ram' else 8 if n=='deviceid' else 4096) for n in names),('invalid MMIO window',t['case'])
 mem={n:(U*len(decoded[n])).from_buffer_copy(decoded[n]) for n in names};hw=HW(*[mem[n] for n in names])
 cpu=CPU(t['initial_priority'],t['exception'],0,0);raw=bytes.fromhex(t['opaque_tail']);tail=(U*len(raw)).from_buffer_copy(raw)
 pending=Pending();service=(U*4096)();rc=f.rr_receiver_rtc_work_dispatch(C.byref(hw),service,flash,tail,C.byref(cpu),C.byref(pending));assert bytes(service)==bytes(4096)
 errors=[]
 if pending.entry!=t['boundary'] or list(pending.args)!=[t['arg0'],0,0,0,0]:errors.append({'pending_ABI':list(pending.args),'entry':pending.entry})
 for n in names:
  got=bytes(mem[n]);expect=un(t[n+'_after'])
  if got!=expect:
   ds=[i for i in range(len(expect)) if got[i]!=expect[i]];errors.append({'window':n,'diffs':len(ds),'first':[(hex(i),got[i],expect[i]) for i in ds[:12]]})
 if rc!=bool(t['boundary']):errors.append({'return':rc,'want':bool(t['boundary'])})
 if cpu.entry!=t['boundary'] or cpu.arg0!=t['arg0']:errors.append({'boundary':[hex(cpu.entry),hex(cpu.arg0)],'want':[hex(t['boundary']),hex(t['arg0'])]})
 if cpu.priority!=t['final_priority']:errors.append({'priority':cpu.priority,'want':t['final_priority']})
 if errors:fails.append({'case':t['case'],'op':t['op'],'event':t['event'],'errors':errors})
 counts[str(t['op'])]+=1;returns[hex(t['boundary'])]+=1
paths=files+list(P.glob('*.h'))+[Path(__file__),R/'ghidra-scripts/EmulateReceiverRtcApplicationTimers.java',A/'receiver-rtc-application-timers-original.jsonl']
report={'status':'PASS' if not fails else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'counts':dict(counts),'endings':dict(returns),'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['Ten inert windows, privileged serialized CPU, valid bounded lists','Event4 tail32 read at actual original callback entry SP-56; C consumes explicit observed bytes, no CPU stack reconstruction','Stops before actual CPU0E0611CC, injected stop callback23024FD8, or reboot0E05D698','No actual hardware reboot, RF or USB transmission; no fabricated nested continuation']}
(A/'receiver-work-app-regression.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']},indent=2));print(json.dumps(fails[:8],indent=2));assert not fails
