from pathlib import Path
import ctypes as C,json,hashlib,struct
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
names=['ram','radio','timer','nvic','dppi','rtc','clock0','clock1','clock2','deviceid']
class HW(C.Structure):_fields_=[(n,Ptr) for n in names]
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
f=C.CDLL(str(A/'libreceiver_storage_read.dylib'))
f.rr_receiver_config_value_publish.argtypes=[Ptr,Ptr,W,W,Ptr,C.POINTER(CPU)]
f.rr_receiver_config_signal_publish.argtypes=[Ptr,Ptr,W,Ptr,C.POINTER(CPU)]
f.rr_receiver_identity_publish.argtypes=[Ptr,Ptr,Ptr,C.POINTER(CPU)]
f.rr_receiver_config_mode_publish.argtypes=[C.POINTER(HW),Ptr,W,Ptr,C.POINTER(CPU)]
f.rr_receiver_config_iteration.argtypes=[C.POINTER(HW),W,Ptr,U,Ptr,C.POINTER(CPU)]
mem={n:(U*(131072 if n=='ram' else 8 if n=='deviceid' else 4096))() for n in names};m=mem['ram'];rtc=mem['rtc'];hw=HW(*[mem[n] for n in names]);cpu=CPU(0x80,0,0,0)
image=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();m[:0x1e08]=image[0x1c854:0x1e08+0x1c854];flash=(U*len(image)).from_buffer_copy(image);keys=(U*256).from_buffer_copy(image[0x1ba74:0x1bb74])
def w(a):return int.from_bytes(bytes(m[a:a+4]),'little')
def pw(a,v):m[a:a+4]=(v&0xffffffff).to_bytes(4,'little')
def ph(a,v):m[a:a+2]=(v&65535).to_bytes(2,'little')
# Exact initialized queue object: ten36-byte slots155F8..15760.
q=0x1bb4;assert w(q+8)==36 and w(q+12)==10 and w(q+16)==0x230155f8 and w(q+20)==0x23015760
# Threads live outside radio-init clear ranges. Scheduler transitions remain software only.
pw(0x7170,0x230020e0);pw(0x7174,0x230029f8);pw(0x717c,0x230020e0);pw(0x7180,0x230020e0);pw(0x7184,0x230020e0);pw(0x20e0,0x23007180);pw(0x20e4,0x23007180);m[0x20ed]=128;m[0x20ee]=14;m[0x1ead]=16;m[0x1eae]=14;m[0x1fcd]=16;m[0x1fce]=14
pw(0xb48,0x23000b48);pw(0xb4c,0x23000b48);m[0x960]=7;pw(0xab4,0);pw(0x7194,0);pw(0x7198,0);m[0x7178]=0
import binascii
class State(C.Structure):_fields_=[('stage',W),('entry',W),('args',W*4)]
f.rr_receiver_settings_load.argtypes=[Ptr,C.POINTER(State)];f.rr_receiver_settings_flush.argtypes=[Ptr,C.POINTER(State)]
f.rr_receiver_settings_resume.argtypes=[Ptr,Ptr,Ptr,Ptr,C.POINTER(State),W]
Read=C.CFUNCTYPE(C.c_int32,C.c_void_p,W,W,Ptr,W)
f.rr_receiver_storage_mapped_read.argtypes=[C.c_void_p,W,W,Ptr,W];f.rr_receiver_storage_mapped_read.restype=C.c_int32
f.rr_receiver_settings_read_continue.argtypes=[Ptr,Ptr,Ptr,Ptr,C.POINTER(State),Ptr,Read,C.c_void_p]
output=C.cast(C.byref(m,0x9000),Ptr);counts={'cycles':0,'mapped_driver_reads':0,'settings_records_read':0,'external_write_acknowledgements':0,'identity_messages_consumed':0}
def crc8(b):
 c=255
 for x in b:
  c^=x
  for _ in range(8):c=((c<<1)^(7 if c&128 else 0))&255
 return c
def put32(buf,at,x):buf[at:at+4]=(x&0xffffffff).to_bytes(4,'little')
def record(epoch,n,key,data):
 b=bytearray(16);b[1]=epoch;b[2:4]=n.to_bytes(2,'little');put32(b,4,key);b[8:8+len(data)]=data;b[0]=crc8(b[1:]);return b
for cycle in range(64):
 mode=cycle%4;chip=0x10203040+cycle;identity=0x98765432+cycle;expected=int.from_bytes(chip.to_bytes(4,'little'),'big') if mode in (1,3) else identity
 mem['deviceid'][:4]=chip.to_bytes(4,'little');mem['deviceid'][4:8]=bytes(4);m[0x71ba]=0;ph(0x719e,0)
 mapped=bytearray([255])*0x200000;mapped[0x54000:0x54000+len(image)]=image
 for idx,(base,n,pages,key) in enumerate([(0x1db000,70,8,0xa001),(0x1df000,47,12,0xa002)]):
  context=0x1f30+72*idx;m[context:context+72]=bytes(72);pw(context,base);pw(context+8,976);pw(context+12,0);pw(context+24,1024);pw(context+28,pages);m[context+33]=1;pw(context+56,0xe06f6cc);pw(context+64,16)
  for page in range(pages):
   at=base+page*1024;mapped[at+1008:at+1024]=record(page+1,65535,0xffffffff,bytes(8));mapped[at+992:at+1008]=record(page+1,0,0xffffffff,(976).to_bytes(4,'little')+bytes(4))
  payload=bytearray((cycle+j*13)&255 for j in range(n));payload[:2]=n.to_bytes(2,'little');put32(payload,31 if idx==0 else 11,0 if mode==3 else identity)
  payload[-2:]=binascii.crc_hqx(payload[:-2],65535).to_bytes(2,'little')
  if (mode==1 and idx==0) or (mode==2 and idx==1):payload[-1]^=1
  mapped[base+32:base+32+n]=payload;mapped[base+976:base+992]=record(1,n,key,(32).to_bytes(4,'little')+bytes(4))
 flashmem=(U*len(mapped)).from_buffer_copy(mapped)
 @Read
 def read(user,device,address,dest,n):
  counts['mapped_driver_reads']+=1;return f.rr_receiver_storage_mapped_read(flashmem,device,address,dest,n)
 prior=(U*32)(*[(cycle+j)&255 for j in range(32)]);s=State();assert f.rr_receiver_settings_load(m,C.byref(s))==1
 rc=f.rr_receiver_settings_read_continue(m,flash,mem['deviceid'],rtc,C.byref(s),prior,read,None);counts['settings_records_read']+=2
 expected_stages={0:[],1:[3],2:[4],3:[3,4]}[mode];stages=[]
 while rc==1:
  stages.append(s.stage);assert s.stage in (3,4);off=s.args[2]-0x23000000;n=s.args[3];payload=bytes(m[off:off+n]);assert binascii.crc_hqx(payload[:-2],65535)==int.from_bytes(payload[-2:],'little')
  counts['external_write_acknowledgements']+=1;rc=f.rr_receiver_settings_resume(m,flash,mem['deviceid'],rtc,C.byref(s),n)
 assert rc==0 and stages==expected_stages and w(0x2dcf)==expected
 tail=(U*28)(*[(cycle+j)&255 for j in range(28)]);assert f.rr_receiver_identity_publish(m,rtc,tail,C.byref(cpu))==0
 assert f.rr_receiver_config_iteration(C.byref(hw),0x23009000,output,0,keys,C.byref(cpu))==0
 radioid=int.from_bytes(expected.to_bytes(4,'little'),'big');assert w(0x3244)==radioid and w(0x324c)==(~radioid&0xffffffff)
 counts['identity_messages_consumed']+=1;counts['cycles']+=1
paths=[Path(__file__),P/'receiver_storage_read.c',P/'receiver_storage_read.h',P/'receiver_settings.c',P/'receiver_config_producer.c',P/'receiver_queue_runtime.c',P/'receiver_initialization.c',R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin']
report={'status':'PASS',**counts,'not_added_to_original_count':True,'checks':['Mapped snapshot to record search and data copy, then real settings CRC and fallback','All valid/invalidA/invalidB/zero-identity combinations','Expected write-boundary sequence and independent innerCRC verification','Loaded identity through real queue and initialization/key-install event'],'limits':['Synthetic mounted contexts and flash snapshot; no mount discovery or actual hardware','Write acknowledgements explicit only; no record write/flash persistence asserted','Serialized components and explicit prior stack bytes/PHY; no autonomous CPU or RF'],'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths}}
(A/'receiver-storage-continuous-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k!='sources'},indent=2))
