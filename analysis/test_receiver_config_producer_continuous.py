from pathlib import Path
import ctypes as C,json,hashlib,struct
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
names=['ram','radio','timer','nvic','dppi','rtc','clock0','clock1','clock2','deviceid']
class HW(C.Structure):_fields_=[(n,Ptr) for n in names]
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
f=C.CDLL(str(A/'libreceiver_config_producer.dylib'))
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
output=C.cast(C.byref(m,0x9000),Ptr);counts={'cycles':0,'identity_initializations':0,'full_queue_purges':0,'config_messages_consumed':0,'mode_wrappers_and_consumers':0}
def consume(expected):
 assert f.rr_receiver_config_iteration(C.byref(hw),0x23009000,output,0,keys,C.byref(cpu))==0,(cpu.entry,cpu.arg0)
 assert bytes(output[:36])==expected
 counts['config_messages_consumed']+=1
for cycle in range(64):
 tail28=bytes((cycle+j)&255 for j in range(28));tail32=bytes((cycle+j+17)&255 for j in range(32));t28=(U*28).from_buffer_copy(tail28);t32=(U*32).from_buffer_copy(tail32)
 identity=(0x12345678+cycle*0x10203)&0xffffffff;pw(0x2dcf,identity);expected=int.from_bytes(identity.to_bytes(4,'little'),'big')
 assert f.rr_receiver_identity_publish(m,rtc,t28,C.byref(cpu))==0
 assert w(0x65b4)==0x20002 and bytes(m[0x65b8:0x65e0])==bytes(40)
 consume(struct.pack('<II',1,expected)+tail28)
 assert w(0x3244)==expected and w(0x324c)==(~expected&0xffffffff)
 counts['identity_initializations']+=1
 # Original producer behavior: an eleventh message purges the full ten-slot queue.
 for j in range(10):assert f.rr_receiver_config_value_publish(m,rtc,9,cycle*10+j,t28,C.byref(cpu))==0
 assert w(q+32)==10
 value=0xabc00000+cycle
 assert f.rr_receiver_config_value_publish(m,rtc,8,value,t28,C.byref(cpu))==0
 assert w(q+32)==1;consume(struct.pack('<II',8,value)+tail28);assert w(0x3244)==value
 counts['full_queue_purges']+=1
 for j in range(10):assert f.rr_receiver_config_value_publish(m,rtc,9,cycle*10+j,t28,C.byref(cpu))==0
 for j in range(10):consume(struct.pack('<II',9,cycle*10+j)+tail28);assert w(0x3240)==cycle*10+j
 for event in [40,44,41]:
  assert f.rr_receiver_config_mode_publish(C.byref(hw),flash,event,t32,C.byref(cpu))==0,(cpu.entry,cpu.arg0)
  assert int.from_bytes(bytes(m[0x2c82:0x2c84]),'little')==int(event!=40)
  consume(struct.pack('<I',event)+tail32);counts['mode_wrappers_and_consumers']+=1
 assert w(q+32)==0 and cpu.priority==0x80;counts['cycles']+=1
paths=[Path(__file__),P/'receiver_config_producer.c',P/'receiver_config_producer.h',P/'receiver_queue_runtime.c',P/'receiver_config_control.c',P/'receiver_initialization.c',P/'receiver_timeout.c',P/'receiver_rtos_lifecycle.c',R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin']
report={'status':'PASS',**counts,'not_added_to_original_count':True,'checks':['Official ten-slot configuration queue object and ring bounds','Stored identity byte-swap to actual initialization and key-install event','Statistics reset before subsequent queue consumption','Full queue purges all ten older messages and retains newest','Ten-message FIFO and wrapping with complete28-byte tail','Mode40/44/41 producers through actual queue and radio/timer consumer'],'limits':['Serialized software event chain; no CPU stack switching or hardware','Old-stack PHY explicitly0 and message tails explicit inputs','Event43 LED hardware boundary independently tested, excluded from continuing loop','Identity source RAM is supplied; persistent storage read not simulated'],'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths}}
(A/'receiver-config-producer-continuous-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k!='sources'},indent=2))
