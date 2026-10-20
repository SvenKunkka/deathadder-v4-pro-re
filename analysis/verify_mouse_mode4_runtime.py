#!/usr/bin/env python3
"""Original mode4 rate/plan/timeout boundary + real ACK lifecycle differential."""
from pathlib import Path
import ctypes as C,json,subprocess,hashlib,zlib,gzip,base64,collections
B=Path(__file__).resolve().parent.parent;A=B/'analysis';P=B/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
mods=['mouse_mode4_radio','mouse_mode4_tx','mouse_mode4_lifecycle','mouse_timer_lifecycle','mouse_radio_irq','mouse_adaptive_control','business_tx','business_cipher']
lib=A/'libmouse_mode4_runtime.dylib';subprocess.run(['rtk','proxy','clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-shared','-fPIC',*[str(P/(x+'.c')) for x in mods],'-o',str(lib)],check=True)
f=C.CDLL(str(lib))
class Pending(C.Structure):_fields_=[('active',W),('entry',W),('args',W*4)]
f.rr_mouse_mode4_timer_lifecycle.argtypes=[Ptr,Ptr,Ptr,Ptr,Ptr,C.POINTER(W),C.POINTER(W),C.POINTER(Pending)]
f.rr_mouse_mode4_radio_lifecycle.argtypes=[Ptr,Ptr,Ptr,Ptr,C.POINTER(W),C.POINTER(W)]
image=(B/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin').read_bytes();flash=(U*len(image)).from_buffer_copy(image)
fails=[];counts=collections.Counter()
def un(z):return zlib.decompress(base64.b64decode(z))
def gz(z):return gzip.decompress(base64.b64decode(z))
def compare(case,mem,want,extra):
 errors=list(extra)
 for name,buf in mem.items():
  ac=bytes(buf);ex=want[name]
  if ac!=ex:
   ds=[i for i in range(len(ex)) if ex[i]!=ac[i]];errors.append({'window':name,'count':len(ds),'diff':[(hex(i),ac[i],ex[i]) for i in ds[:12]]})
 if errors:fails.append({'case':case,'errors':errors})
for row in map(json.loads,(A/'mouse-mode4-runtime-original.jsonl').read_text().splitlines()):
 before={'ram':gz(row['before_gzip']),**{x:bytes.fromhex(row[x+'_before']) for x in ['radio','timer','spim','clock','nvic']}}
 want={'ram':gz(row['after_gzip']),**{x:bytes.fromhex(row[x+'_after']) for x in ['radio','timer','spim','clock','nvic']}}
 mem={k:(U*len(v)).from_buffer_copy(v) for k,v in before.items()};pending=Pending()
 rc=f.rr_mouse_mode4_timer_lifecycle(mem['ram'],mem['radio'],mem['timer'],mem['spim'],flash,C.cast(mem['clock'],C.POINTER(W)),C.cast(mem['nvic'],C.POINTER(W)),C.byref(pending));errors=[]
 entry=row['pending'];expected=1 if entry else 0
 if rc!=expected:errors.append({'return':rc,'expected':expected})
 if pending.active!=bool(entry) or pending.entry!=entry:errors.append({'pending':list((pending.active,pending.entry)),'expected':entry})
 if entry:
  n=1 if entry==0xe0952ec else 4
  if list(pending.args)[:n]!=row['args'][:n]:errors.append({'args':list(pending.args),'expected':row['args']})
 counts['timer_returned' if not entry else 'work_submit_boundary' if entry==0xe0952ec else 'timer_start_boundary']+=1
 compare('timer:'+str(row['case']),mem,want,errors)
for row in map(json.loads,(A/'mouse-mode4-ack-original.jsonl').read_text().splitlines()):
 mem={k:(U*len(un(row[k+'_before_z']))).from_buffer_copy(un(row[k+'_before_z'])) for k in ['ram','radio','timer','rtc','clock']};want={k:un(row[k+'_after_z']) for k in mem};nv=W(0x12345678)
 rc=f.rr_mouse_mode4_radio_lifecycle(mem['ram'],mem['radio'],mem['timer'],mem['rtc'],C.cast(mem['clock'],C.POINTER(W)),C.byref(nv));errors=[]
 if rc:errors.append({'return':rc})
 if nv.value!=row['nvic_after']:errors.append({'nvic':nv.value,'expected':row['nvic_after']})
 compare('ack:'+str(row['case']),mem,want,errors);counts['ack_returned']+=1
assert sum(counts.values())==2560
files=[P/(x+'.c') for x in mods]+[P/'mouse_mode4_lifecycle.h',P/'mouse_mode4_radio.h',Path(__file__),B/'ghidra-scripts/EmulateMouseMode4Runtime.java',B/'ghidra-scripts/EmulateMouseMode4Ack.java',A/'mouse-mode4-runtime-original.jsonl',A/'mouse-mode4-ack-original.jsonl']
result={'status':'FAIL' if fails else 'PASS','original_cases':2560,'counts':dict(counts),'failures':fails,'checks':['all65536 RAM bytes','RADIO4096/TIMER1536/SPIM16/NVIC4/clock8 (runtime)','RADIO4096/TIMER1536/RTC4096/clock8/NVIC4 (ACK)','pending actual entry + meaningful original registers','BASEPRI getter reads same ArmCpuState; returned paths restore it'], 'limits':['512 timeout paths stop at real RTOS entry, not successful completion','work flags2/4 natural fast-return before timer-start; flags0 boundary before work submit','inert MMIO no physical timing/concurrency; arbitrary ACK callbacks and timer stop callbacks/waiters remain boundaries'],'sha256':{str(p.relative_to(B)):hashlib.sha256(p.read_bytes()).hexdigest() for p in files}}
(A/'mouse-mode4-runtime-comparison.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({k:v for k,v in result.items() if k not in ['sha256','failures']},indent=2));print(json.dumps(fails[:8],indent=2));assert not fails
