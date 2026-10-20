from pathlib import Path
import ctypes as C,json,hashlib,collections
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U);lib=A/'libreceiver_vendor_commands.dylib';f=C.CDLL(str(lib))
class Pending(C.Structure):_fields_=[('entry',W),('arg0',W),('arg0_valid',W)]
class MouseEvent(C.Structure):_fields_=[('business_class',U),('sequence',U),('accepted',U),('reassembly_kind',U),('work_requested',U),('work_return',C.c_int)]
f.rr_receiver_vendor_commands.argtypes=[Ptr,Ptr,Ptr,Ptr,Ptr,W,W,C.POINTER(Pending)];f.rr_bt_init.argtypes=[Ptr,C.c_int,C.c_uint];f.rr_bt_peek.argtypes=[Ptr,C.c_int,C.c_uint,C.c_uint];f.rr_bt_peek.restype=W;f.rr_bt_pop.argtypes=f.rr_bt_peek.argtypes;f.rr_mouse_business_flow.argtypes=[Ptr,C.POINTER(MouseEvent)];f.rr_mouse_business_consumer.argtypes=[Ptr,Ptr,Ptr]
image=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();flash=(U*len(image)).from_buffer_copy(image);radio=(U*4096)();device=(U*8)();boot=(U*16)();counts=collections.Counter()
def call(m):
 pending=Pending();assert f.rr_receiver_vendor_commands(m,flash,radio,device,boot,0x23026090,0,C.byref(pending))==0 and pending.entry==0;assert m[0x71bb]==0

def request(m,peer,n,cmd=2,cls=0):
 packet=bytearray(90);packet[0]=1;packet[1]=0 if peer==0 else 0x80;packet[5]=n;packet[6]=cls;packet[7]=cmd
 for i in range(n):packet[8+i]=(i*37+peer*17+n)&255
 checksum=0
 for v in packet[2:88]:checksum^=v
 packet[88]=checksum;m[0x2d1c:0x2d76]=packet;m[0x71bb]=1;return bytes(packet)
for peer in range(2):
 d=(U*131072)();f.rr_bt_init(d,0,peer)
 mouse=(U*65536)();f.rr_bt_init(mouse,1,0)
 for c in range(6):d[0x348f+peer*0xf84+c]=1;mouse[0x2a2a+c]=1
 mouse[0x2798]=4;mouse[0x67ac]=2;mouse[0x7733]=128;d[0x2c80]=1<<(peer+1)
 for cycle in range(32):
  n=[0,1,3,7,31,79,80][cycle%7];packet=request(d,peer,n);call(d);assert d[0x2d1c]==1
  work=0
  while True:
   addr=f.rr_bt_peek(d,0,peer,5)
   if not addr:break
   off=addr-0x23000000;frame=bytes(d[off:off+d[off]+1]);f.rr_bt_pop(d,0,peer,5);mouse[0x2a96:0x2a96+len(frame)]=frame;event=MouseEvent();assert f.rr_mouse_business_flow(mouse,C.byref(event))==0;work+=event.work_requested;counts['fragments']+=1
  assert work==1;assert f.rr_mouse_business_consumer(mouse,(U*16)(),(U*72)())==0
  expected=bytearray(90);expected[:n+8]=packet[:n+8];expected[88]=packet[88]
  assert bytes(mouse[0x3efc:0x3f56])==expected and mouse[0x7715]==mouse[0x7797]==1;counts['forwarded_to_mouse_mailbox']+=1
  # Explicit absent-peer input produces status4, without queued frames.
  d[0x2c80]=0;request(d,peer,n);call(d);assert d[0x2d1c]==4 and f.rr_bt_peek(d,0,peer,5)==0;counts['absent_peer']+=1;d[0x2c80]=1<<(peer+1)
  request(d,peer,n);old=d[0x2d74]^1;d[0x2d74]=old;call(d);assert d[0x2d1c]==3 and d[0x2d74]==old and f.rr_bt_peek(d,0,peer,5)==0;counts['bad_checksum']+=1
 # Explicit coherent full ring: read is one beyond write.
 base=0x33e8+peer*0xf84;d[base+0x159]=0;d[base+0x15f]=1;request(d,peer,80);call(d);assert d[0x2d1c]==1 and d[base+0x159]==0 and d[base+0x15f]==1;counts['full_ring_no_enqueue_but_request_cleared']+=1
# Repeated local write/read, dirty flags and exact widths. NoFlash API called.
m=(U*131072)()
for i in range(64):
 packet=request(m,0,4,0xd);value=(i*0x1020304).to_bytes(4,'little');m[0x2d24:0x2d28]=value;m[0x719e:0x71a0]=b'\x12\x34';m[0x71ba]=0;check=0
 for b in m[0x2d1e:0x2d74]:check^=b
 m[0x2d74]=check;call(m);assert bytes(m[0x2db5:0x2db9])==value and m[0x2d1c]==2 and m[0x71ba]==2 and bytes(m[0x719e:0x71a0])==bytes(2)
 request(m,0,0,0x8d);call(m);assert bytes(m[0x2d24:0x2d28])==value and m[0x2d1c]==2;counts['local_write_read_pairs']+=1
paths=sorted(P.glob('*.c'))+list(P.glob('*.h'))+[Path(__file__),lib]
d={'status':'PASS','counts':dict(counts),'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['C components with explicitly copied DMA frames and explicit mouse consumer execution; noRF/ACK/CPU scheduling','Forwarding ends at mouse90B command mailbox and flags, not execution of mouse vendor commands','Localdirty flags do not prove Flash persistence; queuefull is not success','Not additional original-instruction input cases']};(A/'receiver-vendor-commands-continuous-comparison.json').write_text(json.dumps(d,indent=2)+'\n');print(json.dumps({k:v for k,v in d.items() if k!='sources'},indent=2))
