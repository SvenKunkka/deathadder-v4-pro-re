"""Compare standalone C lifecycle against original unmodified Thumb execution."""
from pathlib import Path
from collections import Counter
import ctypes as C, subprocess, json, hashlib, sys
root=Path(__file__).resolve().parent.parent;a=root/'analysis';src=root/'recovered-code'/'portable'
lib=a/('libmouse_lifecycle.dylib' if sys.platform=='darwin' else 'libmouse_lifecycle.so')
subprocess.run(['rtk','proxy','clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-fPIC','-shared',str(src/'mouse_lifecycle.c'),'-o',str(lib)],check=True,capture_output=True,text=True)
f=C.CDLL(str(lib));fn=f.rr_mouse_lifecycle;U8=C.c_uint8;fn.argtypes=[C.POINTER(U8),C.POINTER(U8),C.POINTER(U8),C.c_uint32];fn.restype=C.c_int
fail=[];coverage=Counter();count=0
path=a/'mouse-lifecycle-original.jsonl'
with path.open() as inp:
 for line in inp:
  row=json.loads(line);count+=1
  ram=(U8*0x8000).from_buffer_copy(bytes.fromhex(row['before']));radio=(U8*0x1000).from_buffer_copy(bytes.fromhex(row['radio_before']));timer=(U8*0x600).from_buffer_copy(bytes.fromhex(row['timer_before']))
  result=fn(ram,radio,timer,row['event']);differences={}
  for name,actual,expected,base in [('ram',bytes(ram),row['after'],0x23000000),('radio',bytes(radio),row['radio_after'],0x5302c000),('timer',bytes(timer),row['timer_after'],0x53028000)]:
   want=bytes.fromhex(expected);diff=[{'address':hex(base+i),'actual':v,'expected':w} for i,(v,w) in enumerate(zip(actual,want)) if v!=w]
   if diff:differences[name]=diff[:20]
  if result!=0 or differences:fail.append({'case':row['case'],'return':result,'differences':differences})
  coverage[f'mode_{row["mode"]}_event_{row["event"]}']+=1
  coverage[f'selector_{row["selector"]}']+=1
  coverage[f'pairing_{row["pairing"]}_pending_{row["pending"]}']+=1
assert count==400,count
# Declared unsupported contexts must fail before changing any caller buffer.
for timer_pointer,work_flags,want in [(1,2,-2),(0,0,-3)]:
 ram=(U8*0x8000)();radio=(U8*0x1000)(*([0xa5]*0x1000));timer=(U8*0x600)(*([0x5a]*0x600));ram[0x2a04]=0x17;ram[0x1540]=timer_pointer;ram[0x67cc]=work_flags
 before=(bytes(ram),bytes(radio),bytes(timer));assert fn(ram,radio,timer,5)==want and before==(bytes(ram),bytes(radio),bytes(timer))
work_fn=f.rr_mouse_lifecycle_connected_work;work_fn.argtypes=[C.POINTER(U8)];work_fn.restype=C.c_int
work_path=a/'mouse-lifecycle-work-original.jsonl';work_count=0
with work_path.open() as inp:
 for line in inp:
  row=json.loads(line);work_count+=1;ram=(U8*0x8000).from_buffer_copy(bytes.fromhex(row['before']))
  status=work_fn(ram);expected=bytes.fromhex(row['after']);diff=[hex(0x23000000+i) for i,(x,y) in enumerate(zip(bytes(ram),expected)) if x!=y]
  if status or diff or row['radio_before']!=row['radio_after'] or row['timer_before']!=row['timer_after']:
   fail.append({'work_case':row['case'],'return':status,'RAM_diff':diff[:20]})
  assert row['basepri_initial']==row['basepri_final']
assert work_count==128
for pending,active,want in [(0,0,-4),(1,1,-2)]:
 ram=(U8*0x8000)();ram[0x6b7e]=pending;ram[0x7747]=1;ram[0x7748]=1;ram[0x1b48]=active;before=bytes(ram)
 assert work_fn(ram)==want and bytes(ram)==before
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
result={'status':'PASS' if not fail else 'FAIL','cases':count+work_count,'terminal_cases':count,'connected_work_cases':work_count,'coverage':dict(coverage),'failures':fail,'unsupported_context_preflight_tests':4,
 'checked':['32768 RAM bytes','4096 RADIO bytes','1536 TIMER020 bytes','random nonzero MMIO before-state','unmodified Thumb code including natural inactive-timer/work-fast-return paths'],
 'source_sha256':sha(path),'work_source_sha256':sha(work_path),'code_sha256':{str(p.relative_to(root)):sha(p) for p in [src/'mouse_lifecycle.c',src/'mouse_lifecycle.h',root/'ghidra-scripts'/'EmulateMouseLifecycle.java',root/'ghidra-scripts'/'EmulateMouseLifecycleWork.java']},
 'limits':['active timer callbacks/unlinking/scheduling unresolved','unsubmitted work entering scheduler unresolved','inert MMIO, no hardware autonomous evolution, no timing validation','connected work callback only; disconnect callback excluded','ISB is TODO/no-op in Ghidra; no barrier timing verification','host C build, not deployable radio firmware']}
(a/'mouse-lifecycle-comparison.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result,indent=2));assert not fail
