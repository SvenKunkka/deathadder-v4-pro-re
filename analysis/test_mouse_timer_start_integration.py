"""Independent continuous delta-list invariant and explicit boundary checks."""
from pathlib import Path
import ctypes as C,json,random,hashlib
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Q=C.c_uint64;Ptr=C.POINTER(U)
f=C.CDLL(str(P/'build/libmouse_timer_start.dylib'));f.rr_mouse_timer_start.argtypes=[Ptr,Ptr,W,Q,Q];f.rr_mouse_timeout_start.argtypes=[Ptr,Ptr,W,W,Q];f.rr_mouse_timer_abort.argtypes=[Ptr,Ptr,W,C.POINTER(C.c_int32)]
B=0x23000000;S=B+0x14f4
m=(U*65536)();r=(U*4096)()
def w(buf,a,v,n=4):buf[a:a+n]=v.to_bytes(n,'little')
def g(buf,a,n=4):return int.from_bytes(bytes(buf[a:a+n]),'little')
def init():
 C.memset(m,0,65536);C.memset(r,0,4096);w(m,0x14f4,S);w(m,0x14f8,S);m[0x1304]=7
init();rng=random.Random(0x96474);expected={};serial=0;counts={'relative':0,'absolute':0,'stop':0,'forever_noop':0}
for case in range(1024):
 t=0x6000+0x40*rng.randrange(12);addr=B+t;kind=rng.randrange(4)
 if kind==0:
  before=(bytes(m),bytes(r));assert f.rr_mouse_timer_start(m,r,addr,2**64-1,123)==0;assert before==(bytes(m),bytes(r));counts['forever_noop']+=1
 elif kind==1:
  result=C.c_int32();assert f.rr_mouse_timer_abort(m,r,addr,C.byref(result))==0;assert result.value==(0 if t in expected else -22);expected.pop(t,None);counts['stop']+=1
 else:
  due=rng.randrange(1,500);period=rng.getrandbits(64);delay=due if kind==2 else (2**64-2-due)
  assert f.rr_mouse_timer_start(m,r,addr,delay,period)==0;serial+=1;expected[t]=(due,serial);assert g(m,t+40,8)==period and g(m,t+48)==0 and g(m,t+8)==0x0e096951
  counts['relative' if kind==2 else 'absolute']+=1
  # RTC epoch/global tick baseline are zero in this continuous sequence.
 node=g(m,0x14f4);prev=S;absolute=0;seen=[]
 while node!=S:
  tnode=node-B;assert node not in seen and len(seen)<12;assert g(m,tnode+4)==prev;absolute+=g(m,tnode+16,8);seen.append(node);assert expected[tnode][0]==absolute;prev=node;node=g(m,tnode)
 assert g(m,0x14f8)==prev
 assert [x-B for x in seen]==[x for x,_ in sorted(expected.items(),key=lambda item:item[1])]
boundaries=[]
init();w(r,0x774,0xc0000000);before=bytes(m);assert f.rr_mouse_timeout_start(m,r,B+0x6000,0x12345679,5)==-4;assert g(m,0x6008)==0x12345679 and bytes(m[:0x6008])==before[:0x6008];boundaries.append('relative busy: callback written before elapsed read')
init();w(r,0x774,0xc0000000);assert f.rr_mouse_timeout_start(m,r,B+0x6000,0x12345679,2**64-12)==-4;assert g(m,0x14f4)==B+0x6000 and g(m,0x6010,8)==10;boundaries.append('absolute busy: node inserted before rearm read')
init();w(r,0x774,0xc0000000);w(m,0x7680,1);assert f.rr_mouse_timeout_start(m,r,B+0x6000,1,5)==0;assert g(m,0x6010,8)==6;boundaries.append('paused list does not sample busy RTC')
init();assert f.rr_mouse_timer_start(m,r,B+65520,4,0)==-1;boundaries.append('invalid timer extent')
init();w(m,0x14f4,0x12345678);assert f.rr_mouse_timeout_start(m,r,B+0x6000,1,5)==-1;boundaries.append('invalid list pointer')
init();assert f.rr_mouse_timeout_start(m,r,B+65512,1,3)==0;assert g(m,65512+16,8)==4;boundaries.append('raw timeout accepts exact24-byte extent')
report={'status':'PASS','continuous_operations':1024,'counts':counts,'boundary_checks':boundaries,'not_original_instruction_cases':True,'checks':['independent cumulative deadlines and stable tie ordering','all prev/next/sentinel links','period/status/expiry thunk registration','no-op preserves all state','busy retains mutations at exact read boundary'],'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in [Path(__file__),P/'mouse_timer_start.c',P/'mouse_timer_start.h']}}
(A/'mouse-timer-start-integration.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
