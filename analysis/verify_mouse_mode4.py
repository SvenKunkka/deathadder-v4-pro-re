"""Compare direct mode4 RADIO/timer/action against unmodified Thumb instructions."""
from pathlib import Path
import ctypes as C,json,hashlib,subprocess,sys,gzip,base64
from collections import Counter
root=Path(__file__).resolve().parent.parent;a=root/'analysis';src=root/'recovered-code'/'portable'
lib=a/('libmouse_mode4.dylib' if sys.platform=='darwin' else 'libmouse_mode4.so')
files=[src/(name+'.c') for name in ['mouse_mode4_radio','mouse_mode4_tx','mouse_adaptive_control','business_tx','business_cipher','mouse_business_flow','business_rx','business_control']]
subprocess.run(['rtk','proxy','clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-fPIC','-shared',*[str(p) for p in files],'-o',str(lib)],check=True,capture_output=True,text=True)
U8=C.c_uint8;libc=C.CDLL(str(lib))
irq=libc.rr_mouse_mode4_radio;irq.argtypes=[C.POINTER(U8)]*3+[C.POINTER(C.c_uint32)];irq.restype=C.c_int
tim=libc.rr_mouse_mode4_timer;tim.argtypes=[C.POINTER(U8)]*4+[C.POINTER(C.c_uint32)];tim.restype=C.c_int
act=libc.rr_mouse_mode4_action;act.argtypes=[C.POINTER(U8)]*2+[C.c_uint32];act.restype=C.c_int
adaptive=libc.rr_mouse_adaptive_irq;adaptive.argtypes=[C.POINTER(U8)];adaptive.restype=C.c_int
class Event(C.Structure):
 _fields_=[('cls',C.c_uint8),('seq',C.c_uint8),('accepted',C.c_uint8),('kind',C.c_uint8),('work',C.c_uint8),('work_return',C.c_int)]
flow=C.CDLL(str(lib)).rr_mouse_business_flow;flow.argtypes=[C.POINTER(U8),C.POINTER(Event)];flow.restype=C.c_int
p=a/'mouse-mode4-original.jsonl';fails=[];count=0;cover=Counter()
with p.open() as rows:
 for line in rows:
  row=json.loads(line);count+=1;b=gzip.decompress(base64.b64decode(row['before_gzip']));expected=gzip.decompress(base64.b64decode(row['after_gzip']))
  m=(U8*65536).from_buffer_copy(b);r=(U8*4096).from_buffer_copy(bytes.fromhex(row['radio_before']));t=(U8*1536).from_buffer_copy(bytes.fromhex(row['timer_before']));nv=C.c_uint32(int.from_bytes(bytes.fromhex(row['nvic_before']),'little'))
  sp=(U8*16).from_buffer_copy(bytes.fromhex(row['spim_before']))
  ret=tim(m,r,t,sp,C.byref(nv)) if row['kind']==1 else act(m,r,row['action']) if row['kind']==2 else irq(m,r,t,C.byref(nv));diff={}
  if row['kind']==3:
   ev=Event();assert flow(m,C.byref(ev))==0 and ev.work==1 and ev.accepted==1
   assert adaptive(m)==0
  for name,actual,want,addr in [('ram',bytes(m),expected,0x23000000),('radio',bytes(r),bytes.fromhex(row['radio_after']),0x5302c000),('timer',bytes(t),bytes.fromhex(row['timer_after']),0x53028000),('spim',bytes(sp),bytes.fromhex(row['spim_after']),0x5f9c2000),('nvic',nv.value.to_bytes(4,'little'),bytes.fromhex(row['nvic_after']),0xe000e208)]:
   ds=[{'a':hex(addr+i),'actual':v,'expected':w} for i,(v,w) in enumerate(zip(actual,want)) if v!=w]
   if ds:diff[name]=ds[:20]
  if diff or ret:fails.append({'case':row['case'],'kind':row['kind'],'ret':ret,'diff':diff})
  cover[f'kind{row["kind"]}']+=1
assert count==3072
boundaries=0
for case in range(8):
 m=(U8*65536)();r=(U8*4096)();t=(U8*1536)();sp=(U8*16)();nv=C.c_uint32(0x12345678)
 if case<3:
  m[0x2a04]=0x1a;r[0x220]=1;r[0x22c]=1;m[0x2a1a]=3
  if case==0:m[0x6b68]=1;want=-2
  elif case==1:m[0x2836]=3;want=-3
  else:m[0x278e]=37;want=-3
  call=lambda:irq(m,r,t,C.byref(nv))
 elif case==3:
  m[0x2a04]=0x18;want=-4;call=lambda:act(m,r,3)
 elif case==4:
  m[0x2a04]=0x1a;want=-8;call=lambda:act(m,r,8)
 else:
  t[0x148]=1;m[0x283c]=5;m[0x2794]=3
  if case==5:m[0x2a0c]=99;want=-5
  elif case==6:m[0x29ae]=1;want=-6
  else:m[0x27a2]=2;want=-7
  call=lambda:tim(m,r,t,sp,C.byref(nv))
 before=bytes(m),bytes(r),bytes(t),bytes(sp),nv.value
 assert call()==want and before==(bytes(m),bytes(r),bytes(t),bytes(sp),nv.value);boundaries+=1
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
result={'status':'PASS' if not fails else 'FAIL','original_cases':count,'coverage':dict(cover),'failures':fails,'boundary_tests':boundaries,'comparison':['all65536 RAM bytes','all4096 RADIO inert bytes','all1536 TIMER020 inert bytes','NVIC E000E208 word','1536 RADIO IRQ +1024 TIMER IRQ +256 actions +256 IRQ/business/adaptive chains; no target stubs','CPU BASEPRI getter bridge only for256 handoff cases, actual work fast-return instructions'],
'source_sha256':sha(p),'code_sha256':{str(p.relative_to(root)):sha(p) for p in files+[src/'mouse_mode4_radio.h',root/'ghidra-scripts'/'EmulateMouseMode4.java']},
 'limits':['Nonzero class3 ACK callback is explicit boundary','IRQ bank>2/channel>36 outside projection','Timer idle TX selection, slot5 disconnect, pending rate update and channel-plan2/3 recompute explicit boundaries','No actual NVIC scheduling/physical MMIO/concurrency; final NVIC store is not W1S pending-bitset','256 explicit IRQ->businessSWI->adaptiveSWI chains; consumer stays deferred']}

(a/'mouse-mode4-comparison.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result,indent=2));assert not fails
