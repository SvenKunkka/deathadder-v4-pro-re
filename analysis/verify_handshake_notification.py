"""Original-instruction/C differential checks for notification ring path."""
from pathlib import Path
import ctypes as C,json,subprocess,hashlib
from collections import Counter
r=Path(__file__).resolve().parent.parent;src=r/'recovered-code/portable';build=src/'build';build.mkdir(exist_ok=True)
lib=build/'librr_notification.dylib'
command=['rtk','proxy','clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-fPIC','-shared',str(src/'handshake.c'),str(src/'handshake_notification.c'),'-o',str(lib)]
subprocess.run(command,check=True,capture_output=True,text=True)
U8=C.c_uint8;U16=C.c_uint16;U32=C.c_uint32
class Globals(C.Structure):
 _fields_=[('status0',U32),('status1',U32),('primary_cap',U16),('fallback_cap',U16),('selector',U16),('selected_mode',U16),('index0',U8),('index1',U8),('frequencies',U8*8),('mask',U8*5),('extra',U8)]
class Context(C.Structure):
 _fields_=[('queue',U8*40),('ring',U8*180),('opaque_tail',U8*20),('other_pending',U32),('base1',U32),('rxaddresses',U32)]
f=C.CDLL(str(lib.resolve()));f.rr_dongle_handshake_step.argtypes=[C.POINTER(U8),C.POINTER(U8),U8,C.POINTER(Globals),C.POINTER(Context)];f.rr_dongle_handshake_step.restype=C.c_int
p=r/'analysis/handshake-notification-original.jsonl';rows=[json.loads(x) for x in p.read_text().splitlines()];assert len(rows)==96
coverage=Counter();fail=[];cpu=Counter()
for row in rows:
 m=(U8*224).from_buffer_copy(bytes.fromhex(row['before']));rx=(U8*12)(11,0,0,0x16);g=Globals();c=Context()
 c.queue[:]=bytes.fromhex(row['queue_before']);c.ring[:]=bytes.fromhex(row['buffer_before']);c.opaque_tail[:]=bytes.fromhex(row['opaque_tail'])
 c.other_pending=row['other_pending'];c.base1=row['base'];c.rxaddresses=row['rx_mask_before']
 result=f.rr_dongle_handshake_step(m,rx,row['slot'],C.byref(g),C.byref(c))
 checks={'state':bytes(m).hex()==row['after'],'queue':bytes(c.queue).hex()==row['queue_after'],'ring':bytes(c.ring).hex()==row['buffer_after'],'mask':c.rxaddresses==row['rx_mask_after'],'return':result==row['return']}
 if not all(checks.values()):fail.append({'case':row['case'],'checks':checks})
 count=int.from_bytes(bytes.fromhex(row['queue_before'])[32:36],'little')
 coverage['pending_nonzero' if row['pending'] else 'pending_zero']+=1
 if row['pending']:coverage[f'initial_queue_count_{count}']+=1
 if c.rxaddresses!=row['rx_mask_before']:coverage['mask_changed']+=1
 assert row['basepri_final']==row['basepri_initial']
 for name,value in zip(['get_BASEPRI','get_IPSR'],row['cpu_support_calls']):cpu[name]+=value
result={'status':'PASS' if not fail else 'FAIL','cases':len(rows),'coverage':dict(coverage),'failures':fail,
 'cpu_support_calls':dict(cpu),'checked':['224 slot bytes','40 queue bytes','180 ring bytes including explicit 20-byte prior-stack tail','RXADDRESSES','function return','BASEPRI restored'],
 'assumptions':['no waiters; serialized queue operations','BASEPRI getter reads built-in ArmCpuState used by real setter; initial 0/0x20/0x80, IPSR=60 fixture','ISB has no scheduling/cache model; built-in Ghidra TODO warning retained','no peripheral event evolution or physical device action'],
 'sources':{str(x.relative_to(r)):hashlib.sha256(x.read_bytes()).hexdigest() for x in [p,src/'handshake_notification.c',src/'handshake_notification.h',r/'ghidra-scripts/EmulateHandshakeNotification.java']}}
(r/'analysis/handshake-notification-comparison.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result,indent=2));assert not fail
