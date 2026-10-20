"""C-only adaptive report to receiver class0 integration. No hardware events."""
from pathlib import Path
import ctypes as C,json,hashlib,subprocess
R=Path(__file__).resolve().parent.parent;P=R/'recovered-code/portable';A=R/'analysis';U=C.c_uint8;W=C.c_uint32;B=U*65536;Ptr=C.POINTER(U)
files=[P/n for n in ['mouse_adaptive_control.c','business_control.c','business_tx.c','business_cipher.c']]
lib=P/'build/libadaptive_exchange.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-dynamiclib',*[str(f) for f in files],'-o',str(lib)],check=True)
l=C.CDLL(str(lib));l.rr_bt_init.argtypes=[Ptr,C.c_int,C.c_uint];l.rr_bt_peek.argtypes=[Ptr,C.c_int,C.c_uint,C.c_uint];l.rr_bt_peek.restype=W
l.rr_mouse_adaptive_request.argtypes=[Ptr,W,W,W,C.POINTER(W)];l.rr_mouse_adaptive_irq.argtypes=[Ptr];l.rr_mouse_adaptive_run.argtypes=[Ptr,C.c_uint,W,W]
l.rr_control_consume.argtypes=[Ptr,C.c_int,C.c_uint,C.POINTER(W)]
def w16(r,o,v):r[o]=v&255;r[o+1]=(v>>8)&255
def r16(r,o):return r[o]|r[o+1]<<8
cases=delivered=full=0
for peer in (0,1):
 for ch in range(37):
  for kind in (0,1):
   for blocked in (False,True):
    m=B();d=B();l.rr_bt_init(m,1,peer);b=0x2978+peer*0xee0;m[b+0xb2]=1
    if blocked:m[b+0x164]=1
    w16(m,0x2936,1);total=40 if kind==0 else 31;count=6
    w16(m,0x2854+ch*2,total);w16(m,0x289e+ch*2,6 if kind==0 else 0);w16(m,0x28e8+ch*2,0 if kind==0 else 6)
    irq=W(0)
    if peer==0:
     l.rr_mouse_adaptive_request(m,0,ch,255,C.byref(irq));assert irq.value==0x08000000;assert l.rr_mouse_adaptive_irq(m)==0
    else:assert l.rr_mouse_adaptive_run(m,peer,0,ch)==0
    assert m[0x294d+ch]==1 and bytes(m[0x2854:0x2932])==bytes(0xde) and r16(m,0x2936)==0
    if blocked:assert m[b+0x15e]==0;full+=1
    else:
     address=l.rr_bt_peek(m,1,peer,0);assert address;off=address-0x23000000;packet=bytes(m[off:off+m[off]+1]);db=0x33e8+peer*0xf84
     d[db+0x114:db+0x114+len(packet)]=packet;d[db+0x69]=31
     irq=W(0);assert l.rr_control_consume(d,0,peer,C.byref(irq))==0
     assert r16(d,0x33ce)==ch and r16(d,0x33d0)==kind and r16(d,0x33d2)==total and r16(d,0x33d4)==count
     assert irq.value==0x08000000 and r16(d,0x71a0)==2 and r16(d,0x71a2)==0 and r16(d,0x33dc)==1
     delivered+=1
    cases+=1
out={'status':'PASS','component_cases':cases,'reports_delivered':delivered,'full_queue_side_effect_cases':full,'source_sha256':{str(f.relative_to(R)):hashlib.sha256(f.read_bytes()).hexdigest() for f in files+[Path(__file__)]},'limits':['C integration only; not new original Thumb cases','IRQ delivery and DMA packet transfer explicit test actions','no RF event or actual NVIC scheduling']}
(A/'adaptive-exchange-comparison.json').write_text(json.dumps(out,indent=2)+'\n');print(json.dumps({k:v for k,v in out.items() if k!='source_sha256'},indent=2))
