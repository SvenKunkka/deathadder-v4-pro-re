"""Independent original-Thumb/Python/host-C differential; no physical MMIO."""
from pathlib import Path
from collections import Counter
import ctypes as C, hashlib, json, subprocess, sys
from mouse_handshake_transition import transition, REGISTERS, STEP_REGISTERS
root=Path(__file__).resolve().parent.parent
a=root/'analysis';src=root/'recovered-code'/'portable'
lib=a/('libmouse_handshake_extended.dylib' if sys.platform=='darwin' else 'libmouse_handshake_extended.so')
cmd=['rtk','proxy','clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-fPIC','-shared',str(src/'mouse_handshake.c'),'-o',str(lib)]
subprocess.run(cmd,check=True,capture_output=True,text=True)
f=C.CDLL(str(lib));u8=C.c_uint8;u32=C.c_uint32
for name in ['rr_mouse_handshake_rx','rr_mouse_handshake_step']:
 fn=getattr(f,name);fn.argtypes=[C.POINTER(u8),u32,u32,u8,C.POINTER(u32)];fn.restype=C.c_int
fail=[];coverage=Counter();sources={}
for filename,count,extended in [('mouse-handshake-original.jsonl',256,False),('mouse-handshake-extended-original.jsonl',384,True)]:
 path=a/filename;data=path.read_bytes();sources[filename]=hashlib.sha256(data).hexdigest();rows=[json.loads(s) for s in data.splitlines()];assert len(rows)==count
 for row in rows:
  before=bytes.fromhex(row['before']);expected=bytes.fromhex(row['after']);addresses=STEP_REGISTERS if extended else REGISTERS
  initial={addr:int.from_bytes(bytes.fromhex(row.get('registers_before',{}).get(f'{addr:x}','00000000')),'little') for addr in addresses}
  actual,regs=transition(before,event=row['event'],crc_ok=row['crc_ok'],channel=row['channel'],extended_registers=extended,initial_registers=initial)
  expected_regs=[int.from_bytes(bytes.fromhex(row['registers_after'][f'{addr:x}']),'little') for addr in addresses]
  cm=(u8*992).from_buffer_copy(before);cr=(u32*len(addresses))(*[initial[addr] for addr in addresses])
  fn=f.rr_mouse_handshake_step if extended else f.rr_mouse_handshake_rx
  ret=fn(cm,row['event'],row['crc_ok'],row['channel'],cr)
  if actual!=expected or [regs[addr] for addr in addresses]!=expected_regs or bytes(cm)!=expected or list(cr)!=expected_regs or ret!=0:
   fail.append({'source':filename,'case':row['case'],'python_ram':[hex(0x23002688+i) for i,(v,w) in enumerate(zip(actual,expected)) if v!=w],
    'python_regs':[hex(addr) for addr,v in zip(addresses,expected_regs) if regs[addr]!=v],
    'C_ram':[hex(0x23002688+i) for i,(v,w) in enumerate(zip(bytes(cm),expected)) if v!=w],
    'C_regs':[hex(addr) for addr,v,w in zip(addresses,list(cr),expected_regs) if v!=w],'return':ret})
  rd=lambda b,addr,n:int.from_bytes(b[addr-0x23002688:addr-0x23002688+n],'little')
  if extended:
   state=rd(before,0x23002a04,4);outstate=rd(expected,0x23002a04,4)
   coverage[f'state_{state:#x}_event_{row["event"]}_to_{outstate:#x}']+=1
   if state==0x14 and rd(before,0x2300298c,4):
    if rd(expected,0x230027b0,4)!=rd(before,0x230027b0,4):coverage['pairing_identity_updated']+=1
    if rd(expected,0x23002990,4)==0x10000 and outstate==0x13:coverage['identity_filter_0x10000_rejected']+=1
result={'status':'PASS' if not fail else 'FAIL','cases':640,'old_cases_preserved':256,'new_original_cases':384,'coverage':dict(coverage),'failures':fail,
 'checked':['992 RAM bytes','15 legacy / 19 extended MMIO words','nonzero randomized initial registers','C and Python independently compared to original Thumb'],
 'sources':sources,'code_hashes':{str(p.relative_to(root)):hashlib.sha256(p.read_bytes()).hexdigest() for p in [src/'mouse_handshake.c',src/'mouse_handshake.h',a/'mouse_handshake_transition.py',root/'ghidra-scripts'/'EmulateMouseHandshakeExtended.java']},
 'limits':['state0x17 terminal lifecycle remains unimplemented','inert MMIO only, no radio or interrupt timing validation','host C build, not Cortex-M firmware build']}
(a/'mouse-handshake-extended-comparison.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(result,indent=2));assert not fail
