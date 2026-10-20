"""Both full initialization chains feeding bidirectional business components.
This is C integration with explicitly copied DMA data; no physical transport.
"""
from pathlib import Path
import ctypes as C,struct,json,subprocess,random,hashlib
root=Path(__file__).resolve().parent.parent;src=root/'recovered-code/portable';U8=C.c_uint8;U32=C.c_uint32;B=C.POINTER(U8)
class Pending(C.Structure):_fields_=[('active',U8),('peer',U8),('metadata',U8),('reserved',U8),('device',U32)]
class MouseEvent(C.Structure):_fields_=[('business_class',U8),('sequence',U8),('accepted',U8),('reassembly_kind',U8),('work_requested',U8),('work_return',C.c_int)]
files=sorted(src.glob('*.c'));lib=root/'analysis/libmouse_initialization_exchange.dylib'
subprocess.run(['rtk','proxy','clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-fPIC','-shared',*[str(p) for p in files],'-o',str(lib)],check=True,capture_output=True,text=True)
f=C.CDLL(str(lib));f.rr_bt_init.argtypes=[B,C.c_int,C.c_uint]
for name in ('rr_bt_mouse_tx','rr_bt_dongle_tx'):
 fn=getattr(f,name);fn.argtypes=[B,C.c_uint,C.c_uint,B,U32,C.c_void_p,C.c_void_p];fn.restype=U32
f.rr_bt_peek.argtypes=[B,C.c_int,C.c_uint,C.c_uint];f.rr_bt_peek.restype=U32;f.rr_bt_pop.argtypes=f.rr_bt_peek.argtypes
f.rr_business_install_key.argtypes=[B,C.c_int,U32,B]
f.rr_receiver_business_flow.argtypes=[B,B,C.c_uint,C.POINTER(U32),C.POINTER(Pending)];f.rr_receiver_business_flow.restype=C.c_int
f.rr_mouse_business_flow.argtypes=[B,C.POINTER(MouseEvent)];f.rr_mouse_business_flow.restype=C.c_int
f.rr_mouse_business_consumer.argtypes=[B,B,B];f.rr_mouse_business_consumer.restype=C.c_int
flashbytes=(root/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();flash=(U8*len(flashbytes)).from_buffer_copy(flashbytes);table=(U8*256).from_buffer_copy(flashbytes[0x1ba74:0x1bb74])
mouse_image=(root/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin').read_bytes()
assert mouse_image[0x2c904:0x2ca04]==flashbytes[0x1ba74:0x1bb74]
class MouseHW(C.Structure):_fields_=[(n,B) for n in ['ram','radio','timer','nvic','dppi','clock']]
class ReceiverHW(C.Structure):_fields_=[(n,B) for n in ['ram','radio','timer','nvic','dppi','rtc','clock0','clock1','clock2','deviceid']]
f.rr_mouse_application_initialize.argtypes=[C.POINTER(MouseHW),U32,U32,U32,U32,B]
f.rr_receiver_config_event.argtypes=[C.POINTER(ReceiverHW),U32,U32,U8,B]
rng=random.Random(2026101902);cases=frames=duplicates=replies=initializations=0

def newram(mouse,identity):
 global initializations
 r=(U8*131072)();radio=(U8*4096)();timer=(U8*4096)();nvic=(U8*4096)();dppi=(U8*4096)()
 if mouse:
  clock=(U8*4096)();hw=MouseHW(r,radio,timer,nvic,dppi,clock)
  assert f.rr_mouse_application_initialize(C.byref(hw),identity,0xbf,0,4,table)==0
  assert bytes(r[0x27ac:0x27b0])==struct.pack('<I',identity)
  assert bytes(r[0x6b72:0x6b76])==bytes([0xbf,0,0,0]) and r[0x6b77]==1
 else:
  r[:0x1e08]=flashbytes[0x1c854:0x1e08+0x1c854]
  rtc=(U8*4096)();clock0=(U8*4096)();clock1=(U8*4096)();clock2=(U8*4096)();deviceid=(U8*8)()
  hw=ReceiverHW(r,radio,timer,nvic,dppi,rtc,clock0,clock1,clock2,deviceid)
  assert f.rr_receiver_config_event(C.byref(hw),1,identity,4,table)==0
  assert bytes(r[0x3244:0x3248])==struct.pack('<I',identity)
 keybase=0x2600 if mouse else 0x3020
 assert bytes(r[keybase:keybase+16])==bytes(table[(identity&15)*16:(identity&15)*16+16])
 assert bytes(radio[0xe30:0xe34])==struct.pack('<I',identity)
 assert bytes(radio[0x500:0x504])==bytes([4,0,0,0])
 initializations+=1
 # Explicit post-connection fixture: connection establishment is not simulated here.
 for i in range(6):r[(0x2a2a if mouse else 0x348f)+i]=1
 if mouse:
  r[0x2798]=4;r[0x67ac]=2;r[0x76e0]=1;r[0x4a5f]=4;r[0x4955]=1;r[0x4a62]=2;r[0x7733]=128
 else:
  r[0x2c82]=1;r[0x71e4]=1;r[0x3485]=1;r[0x48c:0x492]=bytes([0,0,2,0,1,0]);r[0x2cb4:0x2cb7]=bytes([1,3,4])
 return r

def drain(r,mouse,cls):
 out=[]
 while True:
  address=f.rr_bt_peek(r,mouse,0,cls)
  if not address:break
  off=address-0x23000000;out.append(bytes(r[off:off+r[off]+1]));f.rr_bt_pop(r,mouse,0,cls)
 return out

def uplink(mouse,dongle,cls):
 global frames,duplicates
 pending=Pending();nvic=U32()
 for packet in drain(mouse,1,cls):
  dongle[0x34fc:0x34fc+len(packet)]=packet
  assert f.rr_receiver_business_flow(dongle,flash,0,C.byref(nvic),C.byref(pending))==0
  # Only total packet counter may advance for duplicate normal input classes.
  usb=bytes(dongle[0x6834:0x68fc]);vendor=bytes(dongle[0x2d1c:0x2d76]);status=bytes(dongle[0x71b4:0x71ba])
  assert f.rr_receiver_business_flow(dongle,flash,0,C.byref(nvic),C.byref(pending))==0
  assert bytes(dongle[0x6834:0x68fc])==usb and bytes(dongle[0x2d1c:0x2d76])==vendor and bytes(dongle[0x71b4:0x71ba])==status
  frames+=1;duplicates+=1

def downlink(dongle,mouse,cls):
 global frames
 work=0
 for packet in drain(dongle,0,cls):
  mouse[0x2a96:0x2a96+len(packet)]=packet;event=MouseEvent()
  assert f.rr_mouse_business_flow(mouse,C.byref(event))==0
  work+=event.work_requested;frames+=1
 assert work==1
 # Explicit simulated work execution after all fragments, not scheduler proof.
 assert f.rr_mouse_business_consumer(mouse,(U8*16)(),(U8*72)())==0

for selector in range(16):
 identity=(rng.getrandbits(32)&~15)|selector
 for cls in (1,2,3,4,5):
  for variant in range(4):
   m=newram(1,identity);d=newram(0,identity)
   n={1:6,2:[0,1,8,32][variant],3:8,4:[0,8,16,32][variant],5:[2,7,32,90][variant]}[cls]
   data=bytearray(rng.randrange(256) for _ in range(n))
   if cls==3:data[:]=bytes([0xb1,0,0xbf,0,1,4,2,128])
   if cls==5:data[0]=0x5a;data[1]=selector
   buf=(U8*128)();buf[:n]=data;assert f.rr_bt_mouse_tx(m,0,cls,buf,n,None,None)>0
   uplink(m,d,cls)
   if cls in (1,2,4):
    expected=(bytes([data[0]&127,0,0,data[1],data[3],data[2],data[5],data[4]]) if cls==1 else (bytes(data)+bytes(16))[:8 if cls==2 else 16])
    q={1:0,2:2,4:1}[cls];assert d[0x6838+q]==1
    assert bytes(d[0x683c+q*64:0x683c+q*64+len(expected)])==expected
   elif cls==3:assert bytes(d[0x71b4:0x71b7])==bytes([4,2,128]) and d[0x71b8]==1
   else:assert bytes(d[0x2d1c:0x2d1c+n-2])==data[2:] and d[0x2d74]==selector
   cases+=1
 for n in (2,3,7,32,90):
  m=newram(1,identity);d=newram(0,identity);data=bytes([0x5a,selector])+bytes(rng.randrange(256) for _ in range(n-2));buf=(U8*128)();buf[:n]=data
  assert f.rr_bt_dongle_tx(d,0,5,buf,n,None,None)==1;downlink(d,m,5)
  assert bytes(m[0x3efc:0x3efc+n-2])==data[2:] and m[0x3f54]==selector and m[0x7715]==m[0x7797]==1;cases+=1
 # Real B1 downlink consumer generates its8-byte reply, which is sent back to the receiver consumer.
 m=newram(1,identity);d=newram(0,identity);buf=(U8*128)();buf[:6]=bytes([0xb1,1,0,0,1,1])
 assert f.rr_bt_dongle_tx(d,0,3,buf,6,None,None)==1;downlink(d,m,3);uplink(m,d,3)
 assert bytes(d[0x71b4:0x71b7])==bytes([4,2,128]) and m[0x7796]==1 and m[0x1508]==1
 cases+=1;replies+=1
report={'status':'PASS','initialization_calls':initializations,'integration_messages':cases,'business_fragments':frames,'duplicate_checks':duplicates,'bidirectional_B1_reply_cases':replies,
 'sources':{str(p.relative_to(root)):hashlib.sha256(p.read_bytes()).hexdigest() for p in files+sorted(src.glob('*.h'))+[Path(__file__),root/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin',root/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin']},'libraries':{str(lib.relative_to(root)):hashlib.sha256(lib.read_bytes()).hexdigest()},
 'limits':['C integration; copied business DMA buffers, no physical radio/CRC/ACK/PHY scheduling','mouse deferred consumer invoked explicitly after fragments; no RTOS scheduler proof','receiver verified to USB RAM queue, not driver transfer or OS host reception','Actual C full initialization and key install on both sides; connected state and work execution then explicitly supplied, not proven boot/handshake/CPU scheduling','Not counted as new original-instruction inputs']}
(root/'analysis/mouse-initialization-exchange-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k!='sources'},indent=2))
