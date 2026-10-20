from pathlib import Path
import ctypes as C,struct,json,hashlib
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
f=C.CDLL(str(A/'libmouse_context_switch.dylib'))
for n in ['rr_mouse_switch_request_inert','rr_mouse_pendsv_body']:getattr(f,n).argtypes=[Ptr,Ptr,Ptr,C.POINTER(W)]
def w(b,o,v):struct.pack_into('<I',b,o,v&0xffffffff)
def r(b,o):return struct.unpack_from('<I',b,o)[0]
results=[]
for seed in range(4):
 m=bytearray(65536);nv=bytearray(4096);scratch=bytearray(32);cpu=(W*24)();cpu[13]=0x2302f000;cpu[19]=seed%2;cpu[22]=(seed//2)%2;cpu[23]=seed%2
 state={}
 for j,t in enumerate([0x5200,0x5400]):
  state[t]={'regs':[0x12000000+seed*65536+j*256+k for k in range(8)],'psp':0x23009000+j*4096,'limit':0x23008000+j*4096,'tls':0x23003000+j*32,'priority':16 if j==0 else 128}
  q=state[t]
  for k,v in enumerate(q['regs']):w(m,t+0x30+4*k,v)
  w(m,t+0x50,q['psp']);w(m,t+0x74,q['limit']);w(m,t+0x84,q['tls']);w(m,t+0x88,q['priority'])
 current=0x5200;w(m,0x7654,0x23000000+current)
 for k,v in enumerate(state[current]['regs']):cpu[4+k]=v
 cpu[16]=state[current]['psp'];cpu[17]=state[current]['limit'];cpu[18]=state[current]['priority']
 mb=(U*len(m)).from_buffer(m);nb=(U*len(nv)).from_buffer(nv);sb=(U*32).from_buffer(scratch)
 for cycle in range(64):
  # Explicit intervening thread work: supply live callee-saved values and
  # already-stacked PSP input; no claim of instruction/frame generation.
  outgoing={'regs':[0x31000000+seed*65536+cycle*16+k for k in range(8)],'psp':0x2300b000+cycle*8,'priority':[0,16,128][cycle%3]}
  for k,v in enumerate(outgoing['regs']):cpu[4+k]=v
  cpu[16]=outgoing['psp'];cpu[18]=outgoing['priority'];cpu[0]=cpu[18];cpu[14]=0x2302df01;cpu[15]=0xe089d4c
  assert f.rr_mouse_switch_request_inert(mb,nb,sb,cpu)==0
  assert cpu[0]==0xfffffff5 and cpu[18]==0 and r(m,current+0x88)==outgoing['priority']
  assert r(nv,0xd04)&0x10000000
  target=0x5400 if current==0x5200 else 0x5200;expected=state[target].copy();w(m,0x7664,0x23000000+target)
  # Explicit handler entry, ending BEFORE hardware exception return.
  cpu[14]=0xfffffffd;cpu[15]=0xe089dcc
  assert f.rr_mouse_pendsv_body(mb,nb,sb,cpu)==1
  assert list(cpu)[4:12]==expected['regs'] and cpu[16]==expected['psp']
  assert cpu[17]==expected['limit'] and cpu[18]==expected['priority']
  assert cpu[15]==0xe089e06 and cpu[14]==0xfffffffd and cpu[13]==0x2302f000
  assert r(m,0x7654)==0x23000000+target and r(m,0x6d30)==expected['tls'] and r(m,target+0x88)==0
  assert r(nv,0xd04)==0x08000000
  assert [r(m,current+0x30+4*k) for k in range(8)]==outgoing['regs'] and r(m,current+0x50)==outgoing['psp']
  state[current].update(outgoing);state[target]['priority']=0;current=target
 results.append({'seed':seed,'switch_body_segments':64})
paths=[Path(__file__),P/'mouse_context_switch.c',P/'mouse_context_switch.h',A/'libmouse_context_switch.dylib']
d={'status':'PASS','scenarios':4,'switch_request_segments':256,'PendSV_body_segments':256,'results':results,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'not_added_to_original_input_count':True,'limits':['C component sequence with explicitly provided thread execution and handler entry inputs','Stops before each hardware exception return; no frame unstacking or real autonomous task execution','NVIC ICSR is last-written snapshot only']}
(A/'mouse-context-continuous-comparison.json').write_text(json.dumps(d,indent=2)+'\n');print(json.dumps({k:v for k,v in d.items() if k not in ['sources','results']},indent=2))
