"""Compare authored C to actual Thumb execution, including downstream arguments."""
from pathlib import Path
import ctypes as C,json,hashlib,subprocess,struct,collections
root=Path(__file__).resolve().parent.parent
src=root/'recovered-code/portable';U8=C.c_uint8;U32=C.c_uint32
class State(C.Structure):
    _fields_=[('data',(U8*128)*6),('expected',U8*8),('length',U8*8),
              ('completed',U8*128),('completed_class',U8),('completed_length',U8),
              ('motion',U8*8),('activity',U8)]
class Event(C.Structure):
    _fields_=[('kind',U8),('business_class',U8),('length',U8),('payload',U8*128)]
lib=src/'build/librr_rx.dylib'
subprocess.run(['rtk','proxy','clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-fPIC','-shared',str(src/'business_rx.c'),str(src/'business_cipher.c'),'-o',str(lib)],check=True,capture_output=True,text=True)
fn=C.CDLL(str(lib)).rr_business_rx
fn.argtypes=[C.c_int,C.POINTER(State),C.c_uint,C.POINTER(U8),C.c_uint,C.POINTER(U32),C.POINTER(Event)];fn.restype=C.c_int
fail=[];counts={};coverage={};sources={}
for side in ('mouse','dongle'):
    p=root/'analysis'/f'{side}-rx-original.jsonl';rows=[json.loads(x) for x in p.read_text().splitlines()]
    assert len(rows)==(576 if side=='mouse' else 704),(side,len(rows));counts[side]=len(rows)
    sources[str(p.relative_to(root))]=hashlib.sha256(p.read_bytes()).hexdigest()
    cov=collections.Counter()
    for row in rows:
        s=State.from_buffer_copy(bytes.fromhex(row['before']+row['completed_before']+row['meta_before']+row['motion_before'])+bytes([row['activity_before']]))
        e=Event();data=bytes.fromhex(row['fragment']);key=(U32*4)(*struct.unpack('<4I',bytes.fromhex(row['key'])))
        result=fn(side=='mouse',C.byref(s),row['class'],(U8*len(data)).from_buffer_copy(data),len(data),key,C.byref(e))
        actual={'after':bytes(s)[:784].hex(),'completed_after':bytes(s.completed).hex(),
                'meta_after':bytes([s.completed_class,s.completed_length]).hex(),
                'motion_after':bytes(s.motion).hex(),'activity_after':s.activity,'kind':e.kind,
                'length':e.length,'payload':bytes(e.payload)[:e.length].hex()}
        bad={k:{'expected':row[k],'actual':v} for k,v in actual.items() if v!=row[k]}
        if result or bad:fail.append({'side':side,'case':row['case'],'return':result,'differences':bad})
        cov[f'class{row["class"]}:kind{row["kind"]}']+=1
    coverage[side]=dict(cov)
for f in [src/'business_rx.c',src/'business_rx.h',src/'business_cipher.c',root/'ghidra-scripts/EmulateBusinessRx.java']:
    sources[str(f.relative_to(root))]=hashlib.sha256(f.read_bytes()).hexdigest()
report={'status':'FAIL' if fail else 'PASS','original_instruction_cases':sum(counts.values()),'per_side':counts,'coverage':coverage,
        'failures':fail,'sources':sources,'boundaries':['original execution pauses before mouse work-submit or dongle management/consumer call',
        'class2/4 final lengths8/16; other lengths explicitly unsupported, not original rejection','RAM/software execution, no physical RF or scheduler proof']}
(root/'analysis/business-rx-original-comparison.json').write_text(json.dumps(report,indent=2)+'\n')
print(json.dumps({k:v for k,v in report.items() if k!='sources'},indent=2));assert not fail
