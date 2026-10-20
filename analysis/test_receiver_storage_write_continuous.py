from pathlib import Path
import ctypes as C,json,hashlib,struct
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
names=['ram','radio','timer','nvic','dppi','rtc','clock0','clock1','clock2','deviceid']
class HW(C.Structure):_fields_=[(n,Ptr) for n in names]
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
f=C.CDLL(str(A/'libreceiver_storage_write.dylib'))
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
Write=C.CFUNCTYPE(C.c_int32,C.c_void_p,W,W,Ptr,W);Lock=C.CFUNCTYPE(C.c_int32,C.c_void_p,W,C.c_uint64);Unlock=C.CFUNCTYPE(C.c_int32,C.c_void_p,W)
class IO(C.Structure):_fields_=[('read',Read),('write',Write),('lock',Lock),('unlock',Unlock),('user',C.c_void_p),('block_size',W),('erase_value',U)]
f.rr_receiver_settings_write_continue.argtypes=[Ptr,Ptr,Ptr,Ptr,C.POINTER(State),C.POINTER(IO)];f.rr_receiver_settings_mark.argtypes=[Ptr,W]
f.rr_receiver_storage_write.argtypes=[Ptr,W,W,Ptr,W,C.POINTER(IO)];f.rr_receiver_storage_read.argtypes=[Ptr,W,Ptr,W,Ptr,Read,C.c_void_p];f.rr_receiver_storage_mapped_write.argtypes=[Ptr,W,Ptr,W]
output=C.cast(C.byref(m,0x9000),Ptr);counts={'cycles':0,'config_records_written':0,'config_records_read':0,'aux_records_written':0,'aux_latest_checks':0,'identity_messages_consumed':0,'mapped_reads':0,'mapped_writes':0,'lock_calls':0,'unlock_calls':0,'page_close_writes':0,'page_header_writes':0}
def crc8(b):
 c=255
 for x in b:
  c^=x
  for _ in range(8):c=((c<<1)^(7 if c&128 else 0))&255
 return c
def put32(buf,at,x):buf[at:at+4]=(x&0xffffffff).to_bytes(4,'little')
mapped=bytearray([255])*0x200000;mapped[0x54000:0x54000+len(image)]=image
# Initial mounted contexts and first-page headers are explicit fixture inputs.
for idx,(base,pages) in enumerate([(0x1db000,2),(0x1df000,3)]):
 ctx=0x1f30+72*idx;m[ctx:ctx+72]=bytes(72);pw(ctx,base);pw(ctx+8,4048);pw(ctx+24,4096);pw(ctx+28,pages);m[ctx+32]=1;m[ctx+33]=1;pw(ctx+56,0xe06f6cc);pw(ctx+60,0xe070394);pw(ctx+64,16)
 head=bytearray(16);head[1]=1;head[2:4]=b'\xff\xff';put32(head,4,0xffffffff);put32(head,12,0x4201);head[0]=crc8(head[1:]);mapped[base+4080:base+4096]=head
flashmem=(U*len(mapped)).from_buffer_copy(mapped)
@Read
def read(user,device,address,dest,n):counts['mapped_reads']+=1;return f.rr_receiver_storage_mapped_read(flashmem,device,address,dest,n)
@Write
def write(user,device,address,data,n):
 counts['mapped_writes']+=1
 if n==16:
  b=C.string_at(data,n)
  if address%4096==4064 and int.from_bytes(b[4:8],'little')==0xffffffff:counts['page_close_writes']+=1
  if address%4096==4080 and b[2:4]==b'\xff\xff':counts['page_header_writes']+=1
 return f.rr_receiver_storage_mapped_write(flashmem,address,data,n)
@Lock
def lock(user,address,timeout):assert address in (0x23001f54,0x23001f9c) and timeout==0xffffffffffffffff;counts['lock_calls']+=1;return 0
@Unlock
def unlock(user,address):assert address in (0x23001f54,0x23001f9c);counts['unlock_calls']+=1;return 0
io=IO(read,write,lock,unlock,None,16,255);prior=(U*32)();latest={};aux_ctx=C.cast(C.byref(m,0x1f30),Ptr)
for cycle in range(192):
 identity=0x12345678+cycle;payloadA=bytearray((cycle+j*7)&255 for j in range(70));payloadB=bytearray((cycle+j*11)&255 for j in range(47));put32(payloadA,31,identity);put32(payloadB,11,identity);m[0x2db0:0x2df6]=payloadA;m[0x2d80:0x2daf]=payloadB
 assert f.rr_receiver_settings_mark(m,2)==0 and f.rr_receiver_settings_mark(m,4)==0
 state=State();assert f.rr_receiver_settings_flush(m,C.byref(state))==1
 assert f.rr_receiver_settings_write_continue(m,flash,mem['deviceid'],rtc,C.byref(state),C.byref(io))==0 and m[0x71ba]==0
 expectedA=bytes(m[0x2db0:0x2df6]);expectedB=bytes(m[0x2d80:0x2daf]);counts['config_records_written']+=2
 key=0xa010+cycle%3;n=[0,1,8,9,31,70][cycle%6];data=bytes((cycle+j)&255 for j in range(n));source=(U*max(n,1))();source[:n]=data
 assert f.rr_receiver_storage_write(aux_ctx,0x23001f30,key,source,n,C.byref(io))==n;latest[key]=data;counts['aux_records_written']+=1
 m[0x2d80:0x2daf]=bytes(47);m[0x2db0:0x2df6]=bytes(70);assert f.rr_receiver_settings_load(m,C.byref(state))==1
 assert f.rr_receiver_settings_read_continue(m,flash,mem['deviceid'],rtc,C.byref(state),prior,read,None)==0
 assert bytes(m[0x2db0:0x2df6])==expectedA and bytes(m[0x2d80:0x2daf])==expectedB and w(0x2dcf)==identity;counts['config_records_read']+=2
 for k,value in latest.items():
  dest=(U*128)();result=f.rr_receiver_storage_read(aux_ctx,k,dest,128,prior,read,None)
  assert result==(len(value) if value else -2),(cycle,hex(k),result,len(value))
  if value:assert bytes(dest[:len(value)])==value
  counts['aux_latest_checks']+=1
 tail=(U*28)(*[(cycle+j)&255 for j in range(28)]);assert f.rr_receiver_identity_publish(m,rtc,tail,C.byref(cpu))==0
 assert f.rr_receiver_config_iteration(C.byref(hw),0x23009000,output,0,keys,C.byref(cpu))==0
 radioid=int.from_bytes(identity.to_bytes(4,'little'),'big');assert w(0x3244)==radioid and w(0x324c)==(~radioid&0xffffffff);counts['identity_messages_consumed']+=1;counts['cycles']+=1
assert counts['page_close_writes']>=4 and counts['page_header_writes']>=4
assert counts['lock_calls']==counts['unlock_calls']==576
paths=[Path(__file__),P/'receiver_storage_write.c',P/'receiver_storage_write.h',P/'receiver_storage_read.c',P/'receiver_settings.c',P/'receiver_config_producer.c',P/'receiver_queue_runtime.c',P/'receiver_initialization.c',R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin']
report={'status':'PASS',**counts,'final_snapshot_sha256':hashlib.sha256(bytes(flashmem)).hexdigest(),'not_added_to_original_count':True,'checks':['Record write manager updates mapped snapshot without externally supplying write success','Both configuration records re-read after every write and auxiliary update','Long/inline records and tombstones preserve latest values across repeated page rotations/collection','Loaded identity reaches original configuration queue, radio init and key install'],'limits':['Mounted contexts and initial first-page headers explicit; no mount recovery','Mutex callbacks explicitly return0 with no scheduler/concurrency effects','Mapped2MiB is host memory; no physical flash persistence or actual receiver/RF'],'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths}}
(A/'receiver-storage-write-continuous-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k!='sources'},indent=2))
