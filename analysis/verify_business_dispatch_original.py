from pathlib import Path
import ctypes as C,json,subprocess,hashlib,collections
root=Path(__file__).resolve().parent.parent;src=root/'recovered-code/portable';U8=C.c_uint8
class State(C.Structure):
 _fields_=[('context',U8*512),('motion',U8*6),('counters',U8*4)]
class Event(C.Structure):
 _fields_=[('forward',U8),('business_class',U8),('size',U8),('metadata',U8),('payload',U8*128)]
lib=src/'build/librr_dispatch.dylib'
subprocess.run(['rtk','proxy','clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-fPIC','-shared',str(src/'business_dispatch.c'),'-o',str(lib)],check=True,capture_output=True,text=True)
f=C.CDLL(str(lib));fn=f.rr_business_dispatch;fn.argtypes=[C.POINTER(State),C.POINTER(Event)];fn.restype=C.c_int
p=root/'analysis/business-dispatch-original.jsonl';rows=[json.loads(x) for x in p.read_text().splitlines()];assert len(rows)==640
fail=[];coverage=collections.Counter()
for row in rows:
 s=State.from_buffer_copy(bytes.fromhex(row['before']+row['motion_before']+row['counters_before']));e=Event()
 result=fn(C.byref(s),C.byref(e))
 actual={'after':bytes(s.context).hex(),'motion_after':bytes(s.motion).hex(),'counters_after':bytes(s.counters).hex(),
 'forward':e.forward,'class':e.business_class,'length':e.size,'metadata':e.metadata,'payload':bytes(e.payload)[:e.size].hex(),
 'forward_peer':0 if e.forward else -1}
 bad={k:{'expected':row[k],'actual':v} for k,v in actual.items() if row[k]!=v}
 if result or bad:fail.append({'case':row['case'],'return':result,'differences':bad})
 before=bytes.fromhex(row['before']);coverage[f"peer{row['peer']}:class{(before[0x116]&63)>>3}:forward{e.forward}"]+=1
files=[p,src/'business_dispatch.c',src/'business_dispatch.h',root/'ghidra-scripts/EmulateBusinessDispatch.java']
report={'status':'FAIL' if fail else 'PASS','original_instruction_cases':len(rows),'failures':fail,'coverage':dict(coverage),
 'sources':{str(p.relative_to(root)):hashlib.sha256(p.read_bytes()).hexdigest() for p in files},
 'boundaries':['class1..5 only; class0 control path outstanding','forwarded cases stop before230254a0; downstream and after-call suffix not executed in these cases','finish helper sourced from assembly; only no-forward invocation covered here','static RAM original execution, not real IRQ or RF']}
(root/'analysis/business-dispatch-original-comparison.json').write_text(json.dumps(report,indent=2)+'\n')
print(json.dumps({k:v for k,v in report.items() if k!='sources'},indent=2));assert not fail
