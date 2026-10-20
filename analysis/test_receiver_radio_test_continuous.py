from pathlib import Path
import ctypes as C,hashlib,json,random
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
lib=A/'libreceiver_radio_test_control.dylib';f=C.CDLL(str(lib))
class Pending(C.Structure):_fields_=[('entry',W),('arg0',W),('arg0_valid',W)]
f.rr_receiver_radio_test_control.argtypes=[Ptr,Ptr,W,W,W,C.POINTER(Pending)]
image=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();fw=(U*len(image)).from_buffer_copy(image);rng=random.Random(12060)
counts={'A_set_to_work_descriptor':0,'B_set_read_roundtrips':0,'counter_callback_readbacks':0,'B_work_descriptors':0,'unsupported_pointer_no_mutation':0};kinds=set()
def call(m,entry,a=0,b=0):
 p=Pending();rc=f.rr_receiver_radio_test_control(m,fw,entry,a,b,C.byref(p));return rc,p
for cycle in range(64):
 pattern=rng.randbytes(256);m=(U*131072).from_buffer_copy(pattern*512)
 for selection,sweep,packet,duty,kind in [(1,0,0,0,0),(1,0,1,0,1),(1,0,1,50,5),(1,1,0,0,3),(2,0,0,0,2),(2,1,0,0,4)]:
  m[0x71c7]=1;m[0x71dd]=0;m[0x71de]=0;m[0x71d1]=0;m[0x71d0]=0
  payload=bytes([selection,packet,cycle%3,sweep,cycle,cycle+10,cycle+20,cycle%20,cycle+1,duty]);m[0x2d24:0x2d2e]=payload
  rc,p=call(m,0xe05c504,0x23002d24);assert rc==0 and m[0x71dc]==1 and m[0x71dd]==1
  rc,p=call(m,0xe05c774);assert rc==1 and (p.entry,p.arg0,p.arg0_valid)==(0xe05cd78,0x230065e8,1) and m[0x71dc]==0
  assert m[0x65e8]==kind and m[0x65e9]==[3,4,9][cycle%3];counts['A_set_to_work_descriptor']+=1;kinds.add(kind)
 # Reset fixture state explicitly; no assertion that a stopped original call returned.
 m[0x71d1]=0;m[0x71dd]=0;m[0x71de]=0;m[0x71c7]=1
 payload=bytearray(rng.randbytes(14));payload[0]=cycle%4;payload[1]=cycle%20;payload[5]=[0,1,2,98,99,255][cycle%6];m[0x2d24:0x2d32]=payload
 rc,p=call(m,0xe05c5ec,0x23002d24);assert rc==0
 m[0x2d24:0x2d32]=bytes(14);rc,p=call(m,0xe05c6d4,0x23002d24);assert rc==0 and bytes(m[0x2d24:0x2d32])==payload;counts['B_set_read_roundtrips']+=1
 x=rng.getrandbits(32);y=rng.getrandbits(32);rc,p=call(m,0xe05c0d4,x,y);assert rc==0
 rc,p=call(m,0xe05c6d4,0x23002d24);assert rc==0 and bytes(m[0x2d2e:0x2d32])==(x&65535).to_bytes(2,'big')+(y&65535).to_bytes(2,'big');counts['counter_callback_readbacks']+=1
 rc,p=call(m,0xe05c774);assert rc==1 and p.entry==0xe05cd78 and m[0x71d0]==0 and bytes(m[0x71a6:0x71ac])==bytes(6)
 assert m[0x65e8]==2 and bytes(m[0x65f8:0x65fc])==bytes.fromhex('d5c0050e')
 raw=payload[5];expected=50 if raw<2 else 100//(raw+1) if raw<99 else 1
 assert int.from_bytes(bytes(m[0x660c:0x6610]),'little')==expected;counts['B_work_descriptors']+=1
 before=bytes(m);rc,p=call(m,0xe05c6d4,0x230071a6);assert rc==-2 and bytes(m)==before;counts['unsupported_pointer_no_mutation']+=1
assert kinds==set(range(6))
paths=[Path(__file__),P/'receiver_radio_test_control.c',P/'receiver_radio_test_control.h']
d={'status':'PASS','cycles':64,'counts':counts,'descriptor_kinds':sorted(kinds),'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'libraries':{str(lib.relative_to(R)):hashlib.sha256(lib.read_bytes()).hexdigest()},'limits':['Host component sequence only; not additional original instruction cases','Descriptor calls stop before actual test engine; following fixtures explicitly reset state, not simulated returns','No physical receiver, RF traffic, test-engine MMIO or initialization proof']}
(A/'receiver-radio-test-continuous-comparison.json').write_text(json.dumps(d,indent=2)+'\n');print(json.dumps({k:v for k,v in d.items() if k not in ['sources','libraries']},indent=2))
