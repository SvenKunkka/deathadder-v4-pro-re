"""Original Thumb vs independently recovered C; inert RAM/RTC, no device IO."""
from pathlib import Path
import ctypes as C,json,subprocess,hashlib,zlib,base64,collections
R=Path(__file__).resolve().parent.parent;P=R/'recovered-code/portable';A=R/'analysis';U=C.c_uint8;W=C.c_uint32;Q=C.c_uint64;Ptr=C.POINTER(U)
srcs=[P/(n+'.c') for n in ['mouse_timer_start','mouse_timer_lifecycle','mouse_radio_irq','business_tx','business_cipher']]
lib=P/'build/libmouse_timer_start.dylib'
subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-dynamiclib',*map(str,srcs),'-o',str(lib)],check=True)
f=C.CDLL(str(lib));f.rr_mouse_timeout_start.argtypes=[Ptr,Ptr,W,W,Q];f.rr_mouse_timer_start.argtypes=[Ptr,Ptr,W,Q,Q]
rows=[json.loads(s) for s in (A/'mouse-timer-start-original.jsonl').read_text().splitlines() if s.strip()];assert len(rows)==4096
counts=collections.Counter();fails=[]
def unpack(z):return zlib.decompress(base64.b64decode(z))
for t in rows:
 mem={name:(U*len(v)).from_buffer_copy(v) for name in ['ram','rtc'] for v in [unpack(t[name+'_before_z'])]}
 if t['op']==0:rc=f.rr_mouse_timeout_start(mem['ram'],mem['rtc'],t['target'],t['callback'],int(t['duration']))
 else:rc=f.rr_mouse_timer_start(mem['ram'],mem['rtc'],t['target'],int(t['duration']),int(t['period']))
 errors=[]
 if rc:errors.append({'model_return':rc})
 if t['basepri_initial']!=t['basepri_final']:errors.append({'basepri':'changed'})
 for name,buf in mem.items():
  ex=unpack(t[name+'_after_z']);ac=bytes(buf)
  if ex!=ac:
   diff=[i for i in range(len(ex)) if ex[i]!=ac[i]];errors.append({'window':name,'count':len(diff),'diff':[(hex(i),ac[i],ex[i]) for i in diff[:12]]})
 if errors:fails.append({'case':t['case'],'op':t['op'],'shape':t['shape'],'errors':errors})
 counts[f"op{t['op']}:shape{t['shape']}"]+=1
paths=srcs+[P/'mouse_timer_start.h',Path(__file__),R/'ghidra-scripts/EmulateMouseTimerStart.java',A/'mouse-timer-start-original.jsonl',R/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin']
report={'status':'PASS' if not fails else 'FAIL','original_instruction_cases':len(rows),'counts':dict(counts),'failures':fails,'checks':['all65536 RAM bytes','all4096 RTC bytes','original BASEPRI restored through same ArmCpuState','full original functions execute to LR sentinel without target patches'],'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['inert stable RTC; no actual time advance or hardware IRQ','raw timeout start expects unlinked object','start registers expiry thunk, does not execute expiry callback','C calls serially under caller interrupt exclusion; CPU BASEPRI compared only in original emulator']}
(A/'mouse-timer-start-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures','counts']},indent=2));print(json.dumps(fails[:8],indent=2));assert not fails
