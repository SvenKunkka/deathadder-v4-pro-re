"""Compare direct mode1/2 RADIO handlers against unmodified Thumb instructions."""
from pathlib import Path
import ctypes as C,json,hashlib,subprocess,sys,gzip,base64
from collections import Counter
root=Path(__file__).resolve().parent.parent;a=root/'analysis';src=root/'recovered-code'/'portable'
lib=a/('libmouse_radio_irq.dylib' if sys.platform=='darwin' else 'libmouse_radio_irq.so')
files=[src/(name+'.c') for name in ['mouse_radio_irq','business_tx','business_cipher','mouse_business_flow','business_rx','business_control']]
subprocess.run(['rtk','proxy','clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-fPIC','-shared',*[str(p) for p in files],'-o',str(lib)],check=True,capture_output=True,text=True)
U8=C.c_uint8;fn=C.CDLL(str(lib)).rr_mouse_radio_irq;fn.argtypes=[C.POINTER(U8)]*3+[C.POINTER(C.c_uint32),C.c_uint];fn.restype=C.c_int
class Event(C.Structure):
 _fields_=[('cls',C.c_uint8),('seq',C.c_uint8),('accepted',C.c_uint8),('kind',C.c_uint8),('work',C.c_uint8),('work_return',C.c_int)]
flow=C.CDLL(str(lib)).rr_mouse_business_flow;flow.argtypes=[C.POINTER(U8),C.POINTER(Event)];flow.restype=C.c_int
p=a/'mouse-radio-irq-original.jsonl';fails=[];count=0;cover=Counter()
with p.open() as rows:
 for line in rows:
  row=json.loads(line);count+=1;b=gzip.decompress(base64.b64decode(row['before_gzip']));expected=gzip.decompress(base64.b64decode(row['after_gzip']))
  m=(U8*65536).from_buffer_copy(b);r=(U8*4096).from_buffer_copy(bytes.fromhex(row['radio_before']));t=(U8*1536).from_buffer_copy(bytes.fromhex(row['timer_before']));nv=C.c_uint32(int.from_bytes(bytes.fromhex(row['nvic_before']),'little'))
  ret=fn(m,r,t,C.byref(nv),row['mode']);diff={}
  if row['kind']==9:
   ev=Event();assert flow(m,C.byref(ev))==0 and ev.work==1 and ev.accepted==1
  for name,actual,want,addr in [('ram',bytes(m),expected,0x23000000),('radio',bytes(r),bytes.fromhex(row['radio_after']),0x5302c000),('timer',bytes(t),bytes.fromhex(row['timer_after']),0x53028000),('nvic',nv.value.to_bytes(4,'little'),bytes.fromhex(row['nvic_after']),0xe000e208)]:
   ds=[{'a':hex(addr+i),'actual':v,'expected':w} for i,(v,w) in enumerate(zip(actual,want)) if v!=w]
   if ds:diff[name]=ds[:20]
  if diff or ret:fails.append({'case':row['case'],'kind':row['kind'],'mode':row['mode'],'ret':ret,'diff':diff})
  cover[f'mode{row["mode"]}_kind{row["kind"]}']+=1
assert count==2944
boundaries=0
for mode in [1,2]:
 for boundary in [-2,-3]:
  m=(U8*65536)();r=(U8*4096)();t=(U8*1536)();nv=C.c_uint32(0x12345678)
  m[0x2a04]=0x1a;r[0x220]=1;r[0x22c]=1;m[0x2a1a]=3
  if boundary==-2:m[0x6b68]=1
  else:m[0x2836]=2
  before=bytes(m),bytes(r),bytes(t),nv.value
  assert fn(m,r,t,C.byref(nv),mode)==boundary and before==(bytes(m),bytes(r),bytes(t),nv.value);boundaries+=1
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
result={'status':'PASS' if not fails else 'FAIL','original_cases':count,'coverage':dict(cover),'failures':fails,'boundary_tests':boundaries,'comparison':['all65536 RAM bytes','all4096 RADIO inert bytes','all1536 TIMER020 inert bytes','NVIC E000E208 word','2688 whole mode1/2 handler cases plus256 explicit IRQ-return then SWI handoffs; no target stubs','CPU BASEPRI getter bridge only for256 handoff cases, actual work fast-return instructions'],
'source_sha256':sha(p),'code_sha256':{str(p.relative_to(root)):sha(p) for p in files+[src/'mouse_radio_irq.h',root/'ghidra-scripts'/'EmulateMouseRadioIrq.java']},
'limits':['Nonzero class3 ACK callback is explicit boundary','RX bank outside0/1 is explicit projection boundary','Direct handlers only; full23021704 dispatch is not modeled','256 handoffs explicitly invoke SWI after IRQ return; real scheduling, consumers, hardware event timing and concurrency not modeled','Queue pop IRQ instructions executed but C models serialized RAM, not PRIMASK']}
(a/'mouse-radio-irq-comparison.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result,indent=2));assert not fails
