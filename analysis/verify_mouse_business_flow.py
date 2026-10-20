"""Differential check of full original23022508 with all natural helpers."""
from pathlib import Path
import ctypes as C,json,hashlib,subprocess,sys,gzip,base64
from collections import Counter
root=Path(__file__).resolve().parent.parent;a=root/'analysis';src=root/'recovered-code'/'portable'
lib=a/('libmouse_business_flow.dylib' if sys.platform=='darwin' else 'libmouse_business_flow.so')
files=[src/(name+'.c') for name in ['mouse_business_flow','business_rx','business_control','business_tx','business_cipher']]
subprocess.run(['rtk','proxy','clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-fPIC','-shared',*[str(p) for p in files],'-o',str(lib)],check=True,capture_output=True,text=True)
class Event(C.Structure):
 _fields_=[('cls',C.c_uint8),('seq',C.c_uint8),('accepted',C.c_uint8),('kind',C.c_uint8),('work',C.c_uint8),('work_return',C.c_int)]
U8=C.c_uint8;fn=C.CDLL(str(lib)).rr_mouse_business_flow;fn.argtypes=[C.POINTER(U8),C.POINTER(Event)];fn.restype=C.c_int
p=a/'mouse-business-flow-original.jsonl';fails=[];count=0;cover=Counter();events=Counter()
with p.open() as rows:
 for line in rows:
  row=json.loads(line);count+=1;b=gzip.decompress(base64.b64decode(row['before_gzip']));expected=gzip.decompress(base64.b64decode(row['after_gzip']))
  m=(U8*65536).from_buffer_copy(b);ev=Event();ret=fn(m,C.byref(ev))
  if bytes(m)!=expected or ret:
   diff=[{'a':hex(0x23000000+i),'actual':v,'expected':w} for i,(v,w) in enumerate(zip(m,expected)) if v!=w]
   fails.append({'case':row['case'],'kind':row['kind'],'ret':ret,'diff':diff[:20]})
  assert row['basepri_initial']==row['basepri_final']
  cover[f'kind_{row["kind"]}']+=1
  events[f'{ev.accepted}:{ev.kind}:{ev.work}:{ev.work_return}']+=1
assert count==1600
boundaries=0
for length,cls,index,offset,flags,code in [(1,3,0,0,4,-2),(2,3,0,0,4,-2),(127,3,1,128,4,-2),(8,6,0,0,4,-2),(8,7,0,0,4,-2),(8,3,0,0,0,-3),(8,3,0,0,1,-3)]:
 m=(U8*65536)();m[0x2798]=1;m[0x2a96]=length;m[0x2a98]=cls*8+1;m[0x2a99]=index;m[0x6b50+cls]=index;m[0x6b58+cls]=offset;m[0x67ac]=flags
 ev=Event(1,2,3,4,5,6);before=bytes(m),bytes(ev)
 assert fn(m,C.byref(ev))==code and before==(bytes(m),bytes(ev));boundaries+=1
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
result={'status':'PASS' if not fails else 'FAIL','original_cases':count,'coverage':dict(cover),'events':dict(events),'failures':fails,'boundary_tests':boundaries,'comparison':['all65536 RAM bytes','BASEPRI restored','whole original23022508 including real RX/memcpy/work-submit fast-return'],
'source_sha256':sha(p),'code_sha256':{str(p.relative_to(root)):sha(p) for p in files+[src/'mouse_business_flow.h',root/'ghidra-scripts'/'EmulateMouseBusinessFlow.java']},
'limits':['Real RTOS queue path not modeled; supports flags&6 natural fast-return','Accepted class6/7 not projected by six-class RX module','Copies beyond128B or malformed zero-size copies explicit preflight boundary','No asynchronous consumer call, RF timing or physical hardware validation','Missing Ghidra BASEPRI getter bridged to same ArmCpuState; ISB inert']}
(a/'mouse-business-flow-comparison.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result,indent=2));assert not fails
