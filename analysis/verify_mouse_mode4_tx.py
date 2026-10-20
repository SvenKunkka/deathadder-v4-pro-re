"""Compare direct mode4 RADIO/timer/action against unmodified Thumb instructions."""
from pathlib import Path
import ctypes as C,json,hashlib,subprocess,sys,gzip,base64
from collections import Counter
from itertools import chain
root=Path(__file__).resolve().parent.parent;a=root/'analysis';src=root/'recovered-code'/'portable'
lib=a/('libmouse_mode4_tx.dylib' if sys.platform=='darwin' else 'libmouse_mode4_tx.so')
files=[src/(name+'.c') for name in ['mouse_mode4_radio','mouse_mode4_tx','mouse_adaptive_control','business_tx','business_cipher','mouse_business_flow','business_rx','business_control']]
subprocess.run(['rtk','proxy','clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-fPIC','-shared',*[str(p) for p in files],'-o',str(lib)],check=True,capture_output=True,text=True)
U8=C.c_uint8;libc=C.CDLL(str(lib))
irq=libc.rr_mouse_mode4_radio;irq.argtypes=[C.POINTER(U8)]*3+[C.POINTER(C.c_uint32)];irq.restype=C.c_int
tim=libc.rr_mouse_mode4_timer_full;tim.argtypes=[C.POINTER(U8)]*4+[C.POINTER(C.c_uint32)];tim.restype=C.c_int
act=libc.rr_mouse_mode4_action_full;act.argtypes=[C.POINTER(U8)]*3+[C.c_uint32];act.restype=C.c_int
adaptive=libc.rr_mouse_adaptive_irq;adaptive.argtypes=[C.POINTER(U8)];adaptive.restype=C.c_int
class Event(C.Structure):
 _fields_=[('cls',C.c_uint8),('seq',C.c_uint8),('accepted',C.c_uint8),('kind',C.c_uint8),('work',C.c_uint8),('work_return',C.c_int)]
flow=C.CDLL(str(lib)).rr_mouse_business_flow;flow.argtypes=[C.POINTER(U8),C.POINTER(Event)];flow.restype=C.c_int
p=a/'mouse-mode4-tx-original.jsonl';fails=[];count=0;cover=Counter()
p2=a/'mouse-mode4-tx-special-original.jsonl'
with p.open() as rows,p2.open() as extra:
 for line in chain(rows,extra):
  row=json.loads(line);count+=1;b=gzip.decompress(base64.b64decode(row['before_gzip']));expected=gzip.decompress(base64.b64decode(row['after_gzip']))
  m=(U8*65536).from_buffer_copy(b);r=(U8*4096).from_buffer_copy(bytes.fromhex(row['radio_before']));t=(U8*1536).from_buffer_copy(bytes.fromhex(row['timer_before']));nv=C.c_uint32(int.from_bytes(bytes.fromhex(row['nvic_before']),'little'))
  sp=(U8*16).from_buffer_copy(bytes.fromhex(row['spim_before']))
  ret=tim(m,r,t,sp,C.byref(nv)) if row['kind']==1 else act(m,r,t,3);diff={}
  for name,actual,want,addr in [('ram',bytes(m),expected,0x23000000),('radio',bytes(r),bytes.fromhex(row['radio_after']),0x5302c000),('timer',bytes(t),bytes.fromhex(row['timer_after']),0x53028000),('spim',bytes(sp),bytes.fromhex(row['spim_after']),0x5f9c2000),('nvic',nv.value.to_bytes(4,'little'),bytes.fromhex(row['nvic_after']),0xe000e208)]:
   ds=[{'a':hex(addr+i),'actual':v,'expected':w} for i,(v,w) in enumerate(zip(actual,want)) if v!=w]
   if ds:diff[name]=ds[:20]
  if diff or ret:fails.append({'case':row['case'],'kind':row['kind'],'ret':ret,'diff':diff})
  cover[f'kind{row["kind"]}']+=1
assert count==4352
boundaries=0
init=libc.rr_bt_init;init.argtypes=[C.POINTER(U8),C.c_int,C.c_uint]
for case in range(6):
 m=(U8*65536)();r=(U8*4096)();t=(U8*1536)();init(m,1,0);m[0x2a04]=0x18
 if case==0:m[0x2836]=3
 elif case==1:m[0x27a2]=2;m[0x2792]=37
 elif case==2:m[0x2ae2]=0
 elif case==3:m[0x2ae8]=15
 elif case==4:m[0x2af0:0x2af4]=bytes(4)
 else:m[0x2ad6]=32
 before=bytes(m),bytes(r),bytes(t)
 assert act(m,r,t,3)==-9 and before==(bytes(m),bytes(r),bytes(t));boundaries+=1
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
result={'status':'PASS' if not fails else 'FAIL','original_cases':count,'coverage':dict(cover),'failures':fails,'boundary_tests':boundaries,'comparison':['all65536 RAM bytes','all4096 RADIO inert bytes','all1536 TIMER020 inert bytes','NVIC E000E208 word','3328 actual idle/action3 (including256 focused special/no-op) +1024 TIMER IRQ TX selection; no target stubs or CPU userop bridge','all16 SPIM inert bytes'],
'source_sha256':{p.name:sha(p),p2.name:sha(p2)},'code_sha256':{str(p.relative_to(root)):sha(p) for p in files+[src/'mouse_mode4_radio.h',src/'mouse_mode4_tx.h',root/'ghidra-scripts'/'EmulateMouseMode4Tx.java',root/'ghidra-scripts'/'EmulateMouseMode4TxSpecial.java']},
 'limits':['Inert MMIO, no PHY/DPPI/concurrent queue behavior','TX snapshot implementation; real RTOS/lifecycle boundaries from previous stage remain']}

(a/'mouse-mode4-tx-comparison.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result,indent=2));assert not fails
