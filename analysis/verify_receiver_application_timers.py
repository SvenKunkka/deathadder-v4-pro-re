from pathlib import Path
import ctypes as C,json,subprocess,hashlib,gzip,base64,collections
R=Path(__file__).resolve().parent.parent;P=R/'recovered-code/portable';A=R/'analysis';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
files=sorted(P.glob('*.c'))
lib=A/'libreceiver_application_timers.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True)
f=C.CDLL(str(lib));names=['ram','radio','timer','nvic','dppi','rtc','clock0','clock1','clock2','deviceid']
class HW(C.Structure):_fields_=[(n,Ptr) for n in names]
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
f.rr_receiver_application_timer.argtypes=[C.POINTER(HW),Ptr,W,Ptr,C.POINTER(CPU)]
image=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();table=(U*256).from_buffer_copy(image[0x1ba74:0x1bb74])
flash=(U*len(image)).from_buffer_copy(image)
def un(z):return gzip.decompress(base64.b64decode(z))
rows=[json.loads(s) for s in (A/'receiver-application-timers-original.jsonl').read_text().splitlines()];assert len(rows)==4096
fails=[];counts=collections.Counter();phy=collections.Counter();channels=set();returns=collections.Counter()
for t in rows:
 mem={n:(U*len(un(t[n+'_before']))).from_buffer_copy(un(t[n+'_before'])) for n in names};hw=HW(*[mem[n] for n in names])
 cpu=CPU(t['initial_priority'],t['exception'],0,0);raw=bytes.fromhex(t['opaque_tail']);tail=(U*len(raw)).from_buffer_copy(raw)
 rc=f.rr_receiver_application_timer(C.byref(hw),flash,[0x230255d0,0x230255f8,0x23025640,0x230256e8][t['op']],tail,C.byref(cpu))
 errors=[]
 for n in names:
  got=bytes(mem[n]);expect=un(t[n+'_after'])
  if got!=expect:
   ds=[i for i in range(len(expect)) if got[i]!=expect[i]];errors.append({'window':n,'diffs':len(ds),'first':[(hex(i),got[i],expect[i]) for i in ds[:12]]})
 if rc!=bool(t['boundary']):errors.append({'return':rc,'want':bool(t['boundary'])})
 if cpu.entry!=t['boundary'] or cpu.arg0!=t['arg0']:errors.append({'boundary':[hex(cpu.entry),hex(cpu.arg0)],'want':[hex(t['boundary']),hex(t['arg0'])]})
 if cpu.priority!=t['final_priority']:errors.append({'priority':cpu.priority,'want':t['final_priority']})
 if errors:fails.append({'case':t['case'],'op':t['op'],'event':t['event'],'errors':errors})
 counts[str(t['op'])]+=1;returns[hex(t['boundary'])]+=1
paths=files+[P/'receiver_application_timers.h',Path(__file__),R/'ghidra-scripts/EmulateReceiverApplicationTimers.java',A/'receiver-application-timers-original.jsonl']
report={'status':'PASS' if not fails else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'counts':dict(counts),'endings':dict(returns),'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['Ten inert windows, privileged serialized CPU, valid bounded lists','Event4 producer preserves32explicit prior-stack bytes, no invented padding','Stops before actual CPU0E0611CC, injected stop callback23024FD8, or reboot0E05D698','No actual hardware reboot, RF or USB transmission; no fabricated nested continuation']}
(A/'receiver-application-timers-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']},indent=2));print(json.dumps(fails[:8],indent=2));assert not fails
