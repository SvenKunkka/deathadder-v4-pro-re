from pathlib import Path
import ctypes as C,json,subprocess,hashlib,gzip,base64,collections
R=Path(__file__).resolve().parent.parent;P=R/'recovered-code/portable';A=R/'analysis';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
files=sorted(P.glob('*.c'))
lib=A/'libreceiver_config_producer.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True)
f=C.CDLL(str(lib));names=['ram','radio','timer','nvic','dppi','rtc','clock0','clock1','clock2','deviceid']
class HW(C.Structure):_fields_=[(n,Ptr) for n in names]
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
f.rr_receiver_config_value_publish.argtypes=[Ptr,Ptr,W,W,Ptr,C.POINTER(CPU)]
f.rr_receiver_config_signal_publish.argtypes=[Ptr,Ptr,W,Ptr,C.POINTER(CPU)]
f.rr_receiver_identity_publish.argtypes=[Ptr,Ptr,Ptr,C.POINTER(CPU)]
f.rr_receiver_stats_reset.argtypes=[Ptr,W]
f.rr_receiver_config_mode_publish.argtypes=[C.POINTER(HW),Ptr,W,Ptr,C.POINTER(CPU)]
image=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();table=(U*256).from_buffer_copy(image[0x1ba74:0x1bb74])
flash=(U*len(image)).from_buffer_copy(image)
def un(z):return gzip.decompress(base64.b64decode(z))
rows=[json.loads(s) for s in (A/'receiver-config-producer-original.jsonl').read_text().splitlines()];assert len(rows)==10240
fails=[];counts=collections.Counter();phy=collections.Counter();channels=set();returns=collections.Counter()
for t in rows:
 mem={n:(U*len(un(t[n+'_before']))).from_buffer_copy(un(t[n+'_before'])) for n in names};hw=HW(*[mem[n] for n in names])
 cpu=CPU(t['initial_priority'],t['exception'],0,0);raw=bytes.fromhex(t['opaque_tail']);tail=(U*len(raw)).from_buffer_copy(raw)
 if t['op']<3:rc=f.rr_receiver_config_value_publish(mem['ram'],mem['rtc'],t['event'],t['value'],tail,C.byref(cpu))
 elif t['op']==3:rc=f.rr_receiver_config_signal_publish(mem['ram'],mem['rtc'],t['event'],tail,C.byref(cpu))
 elif t['op']==4:rc=f.rr_receiver_identity_publish(mem['ram'],mem['rtc'],tail,C.byref(cpu))
 elif t['op']==5:rc=f.rr_receiver_stats_reset(mem['ram'],t['value'])
 else:rc=f.rr_receiver_config_mode_publish(C.byref(hw),flash,t['event'],tail,C.byref(cpu))
 errors=[]
 for n in names:
  got=bytes(mem[n]);expect=un(t[n+'_after'])
  if got!=expect:
   ds=[i for i in range(len(expect)) if got[i]!=expect[i]];errors.append({'window':n,'diffs':len(ds),'first':[(hex(i),got[i],expect[i]) for i in ds[:12]]})
 if rc!=bool(t['boundary']):errors.append({'return':rc,'want':bool(t['boundary'])})
 if cpu.entry!=t['boundary'] or cpu.arg0!=t['arg0']:errors.append({'boundary':[hex(cpu.entry),hex(cpu.arg0)],'want':[hex(t['boundary']),hex(t['arg0'])]})
 if cpu.priority!=t['final_priority']:errors.append({'priority':cpu.priority,'want':t['final_priority']})
 if errors:fails.append({'case':t['case'],'op':t['op'],'event':t['event'],'errors':errors})
 counts[str(t['op'])]+=1;returns['cpu_request' if t['boundary']==0xe0611cc else 'LED_driver_entry' if t['boundary'] else 'full_return']+=1
paths=files+[P/'receiver_config_producer.h',Path(__file__),R/'ghidra-scripts/EmulateReceiverConfigProducer.java',A/'receiver-config-producer-original.jsonl']
report={'status':'PASS' if not fails else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'counts':dict(counts),'endings':dict(returns),'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['Ten inert memory windows; no autonomous IRQ/RTC/radio','Configuration producers retain28or32 explicit prior-stack bytes','Event43 stops at actual LED function23025954 with arg0=0; hardware body not fabricated','CPU boundary preserves all effects and arguments; no nested stack continuation','Input identity is read from existing RAM2DCF; persistence/load ancestry remains incomplete']}
(A/'receiver-config-producer-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']},indent=2));print(json.dumps(fails[:8],indent=2));assert not fails
