"""Component integration, not original-instruction or RF end-to-end proof."""
from pathlib import Path
import ctypes as C,struct,json,subprocess,hashlib,random
root=Path(__file__).resolve().parent.parent;src=root/'recovered-code/portable';U8=C.c_uint8;U32=C.c_uint32
class Rx(C.Structure):
 _fields_=[('data',(U8*128)*6),('expected',U8*8),('length',U8*8),('completed',U8*128),('completed_class',U8),('completed_length',U8),('motion',U8*8),('activity',U8)]
class RxEvent(C.Structure):
 _fields_=[('kind',U8),('business_class',U8),('length',U8),('payload',U8*128)]
class Dispatch(C.Structure):
 _fields_=[('context',U8*512),('motion',U8*6),('counters',U8*4)]
class DispatchEvent(C.Structure):
 _fields_=[('forward',U8),('business_class',U8),('size',U8),('metadata',U8),('payload',U8*128)]
lib=src/'build/librr_business_pipeline.dylib'
files=[src/(s+'.c') for s in ('business_cipher','business_tx','business_rx','business_dispatch')]
subprocess.run(['rtk','proxy','clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-fPIC','-shared',*[str(p) for p in files],'-o',str(lib)],check=True,capture_output=True,text=True)
f=C.CDLL(str(lib));B=C.POINTER(U8)
f.rr_bt_init.argtypes=[B,C.c_int,C.c_uint]
f.rr_bt_mouse_tx.argtypes=[B,C.c_uint,C.c_uint,B,U32,C.c_void_p,C.c_void_p];f.rr_bt_mouse_tx.restype=U32
f.rr_bt_dongle_tx.argtypes=f.rr_bt_mouse_tx.argtypes;f.rr_bt_dongle_tx.restype=U32
f.rr_bt_peek.argtypes=[B,C.c_int,C.c_uint,C.c_uint];f.rr_bt_peek.restype=U32
f.rr_bt_pop.argtypes=f.rr_bt_peek.argtypes
f.rr_business_rx.argtypes=[C.c_int,C.POINTER(Rx),C.c_uint,B,C.c_uint,C.POINTER(U32),C.POINTER(RxEvent)];f.rr_business_rx.restype=C.c_int
f.rr_business_dispatch.argtypes=[C.POINTER(Dispatch),C.POINTER(DispatchEvent)];f.rr_business_dispatch.restype=C.c_int
f.rr_business_dispatch_finish.argtypes=[C.POINTER(Dispatch)]
image=(root/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin').read_bytes();table=image[0x2c904:0x2ca04]
rng=random.Random(12020261019);cases=0;frames=0;duplicates=0;restarts=0

def newram(mouse):
 ram=(U8*65536)();f.rr_bt_init(ram,mouse,0)
 base=0x2a2a if mouse else 0x348f
 for i in range(6):ram[base+i]=1
 return ram

def drain(ram,mouse,cls):
 out=[]
 while True:
  a=f.rr_bt_peek(ram,mouse,0,cls)
  if not a:break
  off=a-0x23000000;length=ram[off]
  out.append(bytes(ram[off:off+length+1]));f.rr_bt_pop(ram,mouse,0,cls)
 return out

def receive(rx,mouse,cls,data,key):
 ev=RxEvent();ret=f.rr_business_rx(mouse,C.byref(rx),cls,(U8*len(data)).from_buffer_copy(data),len(data),key,C.byref(ev));assert ret==0
 return ev

for selector in range(16):
 keybytes=table[selector*16:selector*16+16];key=(U32*4)(*struct.unpack('<4I',keybytes))
 for cls in range(1,6):
  lengths={1:[6]*6,2:[0,1,7,8,16,32],3:[1,6,7,31,64,90],4:[0,1,8,15,16,32],5:[1,6,7,31,64,90]}[cls]
  for length in lengths:
   original=bytes(rng.randrange(256) for _ in range(length));buf=(U8*128)();buf[:length]=original
   ram=newram(1);ram[0x2600:0x2610]=keybytes
   effective=8 if cls==2 else 16 if cls==4 else length
   assert f.rr_bt_mouse_tx(ram,0,cls,buf,length,None,None)==effective
   packets=drain(ram,1,cls);rx=Rx();ds=Dispatch();ds.context[0x9d]=1;events=[]
   for packet in packets:
    ds.context[0x114]=packet[0];ds.context[0x116:0x116+len(packet)-2]=packet[2:]
    ev=DispatchEvent();assert f.rr_business_dispatch(C.byref(ds),C.byref(ev))==0 and ev.forward==1
    result=receive(rx,0,ev.business_class,bytes(ev.payload)[:ev.size],key)
    if result.kind in (3,4):events.append(bytes(result.payload)[:result.length])
    f.rr_business_dispatch_finish(C.byref(ds));frames+=1
    before=bytes(rx);dup=DispatchEvent();assert f.rr_business_dispatch(C.byref(ds),C.byref(dup))==0 and dup.forward==0
    assert bytes(rx)==before;duplicates+=1
   if cls==1:
    expected=bytes([original[0]&127,0,0,original[1],original[3],original[2],original[5],original[4]])
   elif cls in (2,4):expected=(original+bytes(effective))[:effective]
   else:expected=original
   assert events==[expected],(selector,cls,length,events,expected.hex())
   # Last fragment arriving first must reject; a new index0 then restarts cleanly.
   if cls!=1 and len(packets)>1:
    other=Rx();e=receive(other,0,cls,packets[-1][3:],key);assert e.kind==1
    for packet in packets:e=receive(other,0,cls,packet[3:],key)
    assert bytes(e.payload)[:e.length]==expected;restarts+=1
   cases+=1
for cls in (3,5):
 for length in range(91):
  ram=newram(0);original=bytes(rng.randrange(256) for _ in range(length));buf=(U8*128)();buf[:length]=original
  assert f.rr_bt_dongle_tx(ram,0,cls,buf,length,None,None)==1
  rx=Rx();events=[]
  for packet in drain(ram,0,cls):
   e=receive(rx,1,cls,packet[3:],None);frames+=1
   if e.kind==2:events.append(bytes(e.payload)[:e.length])
  expected=original+bytes([-sum(original)&255]);assert events==[expected] and sum(expected)%256==0
  assert bytes(rx.completed)[:rx.completed_length]==expected;cases+=1
report={'status':'PASS','integration_cases':cases,'fragments_processed':frames,'duplicate_dispatch_checks':duplicates,'out_of_order_then_restart_cases':restarts,
 'sources':{str(p.relative_to(root)):hashlib.sha256(p.read_bytes()).hexdigest() for p in files+[Path(__file__)]},
 'coverage':['all16 installed key records; class2/4 zero padding, truncation, encrypt->fragment->decrypt','classes1..5 uplink TX/ring/dispatch/reassembly to consumer boundary','class3/5 downlink0..90 bytes, checksum then4-byte fragmentation/reassembly','per-class sequence wrapping; exact duplicates; last-fragment-first then restart'],
 'limits':['C component integration only; NOT counted as new original-instruction cases','constructed packet headers; no full mode4 aggregation, ACK/PHY scheduler, radio or USB execution','downstream management/vendor work consumers not executed; checksum checked by test, consumer still pending']}
(root/'analysis/business-pipeline-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
