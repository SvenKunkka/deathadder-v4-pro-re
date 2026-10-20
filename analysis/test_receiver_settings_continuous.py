from pathlib import Path
import ctypes as C,json,hashlib,struct
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
names=['ram','radio','timer','nvic','dppi','rtc','clock0','clock1','clock2','deviceid']
class HW(C.Structure):_fields_=[(n,Ptr) for n in names]
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
f=C.CDLL(str(A/'libreceiver_settings.dylib'))
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
output=C.cast(C.byref(m,0x9000),Ptr);counts={'cycles':0,'loads':0,'external_reads':0,'external_writes':0,'failed_writes':0,'published_and_consumed':0}
for cycle in range(64):
 # This dictionary is an explicit external fixture, not recovered flash storage.
 store={};chip=0x10203040+cycle*0x10203;mem['deviceid'][:4]=chip.to_bytes(4,'little');mem['deviceid'][4:8]=bytes(4)
 expected=int.from_bytes(chip.to_bytes(4,'little'),'big');preserved=bytes((cycle+j*17)&255 for j in range(22))
 m[0x2d80:0x2daf]=bytes(47);m[0x2d94:0x2daa]=preserved;m[0x2db0:0x2df6]=bytes(70);m[0x71ba]=0;ph(0x719e,17)
 def service(s,rc,fail_a=False):
  while rc==1:
   entry=s.entry;context,key,address,n=list(s.args);off=address-0x23000000
   assert context==0x23001f30+(72 if key==0xa002 else 0)
   if entry==0xe05ed64:
    counts['external_reads']+=1
    if key in store:m[off:off+n]=store[key];result=n
    else:result=0xfffffffe
   else:
    assert entry==0xe05eb1c;counts['external_writes']+=1;data=bytes(m[off:off+n]);assert int.from_bytes(data[:2],'little')==n
    assert binascii.crc_hqx(data[:-2],65535)==int.from_bytes(data[-2:],'little')
    if fail_a and key==0xa001:result=0xfffffff3;counts['failed_writes']+=1
    else:store[key]=data;result=n
   rc=f.rr_receiver_settings_resume(m,flash,mem['deviceid'],rtc,C.byref(s),result)
  assert rc==0 and s.stage==0
 s=State();service(s,f.rr_receiver_settings_load(m,C.byref(s)),True);counts['loads']+=1
 assert w(0x2dcf)==expected and w(0x2d8b)==expected and bytes(m[0x2d94:0x2daa])==preserved
 assert m[0x71ba]==2 and 0xa001 not in store and 0xa002 in store
 service(s,f.rr_receiver_settings_flush(m,C.byref(s)));assert m[0x71ba]==0 and len(store)==2
 # Re-load acknowledged records into cleared RAM, without requesting any write.
 writes=counts['external_writes'];m[0x2d80:0x2daf]=bytes(47);m[0x2db0:0x2df6]=bytes(70)
 service(s,f.rr_receiver_settings_load(m,C.byref(s)));counts['loads']+=1
 assert counts['external_writes']==writes and w(0x2dcf)==expected and bytes(m[0x2d94:0x2daa])==preserved
 tail=bytes((cycle+j)&255 for j in range(28));t=(U*28).from_buffer_copy(tail)
 assert f.rr_receiver_identity_publish(m,rtc,t,C.byref(cpu))==0
 assert f.rr_receiver_config_iteration(C.byref(hw),0x23009000,output,0,keys,C.byref(cpu))==0
 assert bytes(output[:36])==struct.pack('<II',1,chip)+tail and w(0x3244)==chip and w(0x324c)==(~chip&0xffffffff)
 counts['published_and_consumed']+=1;counts['cycles']+=1
paths=[Path(__file__),P/'receiver_settings.c',P/'receiver_settings.h',P/'receiver_config_producer.c',P/'receiver_queue_runtime.c',P/'receiver_initialization.c',R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin']
report={'status':'PASS',**counts,'not_added_to_original_count':True,'checks':['Independent Python binascii CRC verification of every write request','Invalid records retain22middle bytes; chip identity fallback precedes dirty marking','Failed A write retains dirty bit; B success clears its own bit; later flush retries A','Explicit acknowledged-record reload requests no further write','Loaded identity feeds original ten-slot queue, radio initialization and key install'],'limits':['External dictionary and injected success/failure are test inputs; no flash persistence implementation','Serialized components, fixed RTC and explicit old-stack bytes; no physical receiver or CPU stack switching'],'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths}}
(A/'receiver-settings-continuous-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k!='sources'},indent=2))
