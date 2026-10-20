from pathlib import Path
import ctypes as C,json,hashlib,gzip,base64
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
names=['ram','radio','timer','nvic','dppi','rtc','clock0','clock1','clock2','deviceid']
class HW(C.Structure):_fields_=[(n,Ptr) for n in names]
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
class Pending(C.Structure):_fields_=[('entry',W),('args',W*5)]
f=C.CDLL(str(A/'libreceiver_application_timers.dylib'))
f.rr_receiver_rtc_application_timers.argtypes=[C.POINTER(HW),Ptr,Ptr,C.POINTER(CPU),C.POINTER(Pending)]
f.rr_receiver_timer_start_control.argtypes=[Ptr,Ptr,W,C.c_uint64,C.c_uint64,C.POINTER(CPU)]
f.rr_receiver_message_get.argtypes=[Ptr,Ptr,W,W,Ptr,C.c_uint64,C.POINTER(CPU),C.POINTER(C.c_int32)]
f.rr_bt_init.argtypes=[Ptr,C.c_int,C.c_uint];f.rr_bt_pop.argtypes=[Ptr,C.c_int,C.c_uint,C.c_uint]
row=json.loads(next((A/'receiver-application-timers-original.jsonl').open()))
image=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();fw=(U*len(image)).from_buffer_copy(image)
counts={'RTC_events':0,'radio_on':0,'radio_off':0,'statistics_expiries':0,'statistics_USB_reports':0,'state_expiries':0,'configuration_events':0,'reboot_boundary':0}
for scenario in range(3):
 mem={n:(U*len(gzip.decompress(base64.b64decode(row[n+'_before'])))).from_buffer_copy(gzip.decompress(base64.b64decode(row[n+'_before']))) for n in names};m=mem['ram'];rtc=mem['rtc'];hw=HW(*[mem[n] for n in names]);cpu=CPU(0x80,125,0,0)
 def w(a):return int.from_bytes(bytes(m[a:a+4]),'little')
 def h(a):return int.from_bytes(bytes(m[a:a+2]),'little')
 def pw(a,v):m[a:a+4]=v.to_bytes(4,'little')
 def ph(a,v):m[a:a+2]=v.to_bytes(2,'little')
 def rw(a,v,n=4):rtc[a:a+n]=v.to_bytes(n,'little')
 def empty(a):pw(a,0x23000000+a);pw(a+4,0x23000000+a)
 for t,cb in [(0x1a30,0x230255b9),(0x1a68,0x230255d1),(0x1aa0,0x230255f9),(0x1ad8,0x23025641),(0x1b10,0x230256e9)]:
  m[t:t+0x38]=bytes(0x38);empty(t+0x18);pw(t+0x20,cb)
 for t in [0x1fc0,0x6000,0x29f8]:m[t:t+0x90]=bytes(0x90)
 m[0x1fcd]=16;m[0x1fce]=4;m[0x600d]=128;m[0x600e]=248
 empty(0x7180);pw(0x7180,0x23006000);pw(0x7184,0x23006000);pw(0x6000,0x23007180);pw(0x6004,0x23007180)
 for a,v in [(0x7170,0x23006000),(0x717c,0x23006000),(0x7174,0x230029f8),(0x7188,0),(0x718c,0),(0x7190,0),(0x7194,0),(0x7198,0),(0x2c60,0),(0x2c64,0),(0x2840,0),(0x2844,0),(0x2c78,0),(0x2c7c,0),(0x958,0xe0683a1),(0x95c,0),(0xab4,0),(0xab8,0)]:pw(a,v)
 m[0x7178]=0;m[0x960]=7;empty(0xb48);empty(0x1c54);pw(0x1c5c,0);pw(0x1c60,1)
 ph(0x6590,0);ph(0x2c80,0);ph(0x2c82,1);m[0x71e4]=1;m[0x490]=2;m[0x6836]=0;m[0x683a]=0
 q=0x1bb4;empty(q);pw(q+8,36);pw(q+12,10);pw(q+16,0x230155f8);pw(q+20,0x23015760);pw(q+24,0x230155f8);pw(q+28,0x230155f8);pw(q+32,0)
 f.rr_bt_init(m,0,0);f.rr_bt_init(m,0,1);rw(0x770,0,8)
 target=[0x1a68,0x1ad8,0x1b10][scenario];period=0 if scenario==0 else 10
 assert f.rr_receiver_timer_start_control(m,rtc,0x23000000+target,10,period,C.byref(cpu))==0
 ph(0x659a,4);ph(0x659c,1);ph(0x659e,0);m[0x65b2]=0x31;m[0x65b3]=0x42
 ph(0x65b4,1);ph(0x65b6,1);ph(0x65e2,0);ph(0x65e4,0);ph(0x65e6,100);m[0x6595]=0;m[0x65e0]=0;m[0x2daa]=5;m[0x2dab]=25;m[0x2dac]=50
 for cycle in range(64):
  deadline=int.from_bytes(bytes(rtc[0x590:0x598]),'little');rw(0x770,deadline,8);rw(0x11c,1);rw(0x350,128)
  oldwrite=m[0x683a];m[0x6836]=oldwrite;tail=(U*32).from_buffer_copy(bytes((cycle+j)&255 for j in range(32)))
  if scenario==1:
   for a,v in [(0x65a0,100),(0x65a4,100),(0x65a8,4),(0x65ac,5)]:pw(a,v)
  if scenario==2:
   for a,v in [(0x65b8,25),(0x65bc,51),(0x65c0,1),(0x65c4,1)]:pw(a,v)
   ph(0x65e4,1)
  p=Pending();rc=f.rr_receiver_rtc_application_timers(C.byref(hw),fw,tail,C.byref(cpu),C.byref(p));assert rc==0,(scenario,cycle,rc,hex(cpu.entry))
  assert p.entry==0 and cpu.priority==0x80;counts['RTC_events']+=1
  if scenario==0:
   on=cycle%2==0;assert h(0x3232)==int(on);assert w(0xb48)==(0x23001aa0 if on else 0x23001a68)
   following=int.from_bytes(bytes(rtc[0x590:0x598]),'little');assert following-deadline==(100000 if on else 400000)
   counts['radio_on' if on else 'radio_off']+=1
  elif scenario==1:
   counts['statistics_expiries']+=1
   assert w(0x1b08)==cycle+1
   if cycle%4==0:
    assert m[0x65b0]==25 and m[0x65b1]==20 and w(0x65a0)==w(0x65a4)==w(0x65a8)==w(0x65ac)==0
    f.rr_bt_pop(m,0,0,3) # explicit simulated transmit sink
   if cycle%4==1:
    assert m[0x683a]==(oldwrite+1)%4
    assert bytes(m[0x68bc+oldwrite*16:0x68c3+oldwrite*16])==bytes([5,254,114,25,0x31,20,0x42]);counts['statistics_USB_reports']+=1
  else:
   assert h(0x65dc)==0x0103 and h(0x65de)==0x0103 and bytes(m[0x65d8:0x65da])==bytes([25,51])
   assert bytes(m[0x65b8:0x65d8])==bytes(32) and w(q+32)==1
   out=(U*36)();result=C.c_int32(999)
   assert f.rr_receiver_message_get(m,rtc,0x23001bb4,0x2302f000,out,0,C.byref(cpu),C.byref(result))==0
   assert result.value==0 and bytes(out)==(4).to_bytes(4,'little')+bytes(tail) and w(q+32)==0
   counts['state_expiries']+=1;counts['configuration_events']+=1
 if scenario==2:
  ph(0x6590,1);ph(0x65e6,1);ph(0x65e4,0);deadline=int.from_bytes(bytes(rtc[0x590:0x598]),'little');rw(0x770,deadline,8);rw(0x11c,1);rw(0x350,128);p=Pending()
  assert f.rr_receiver_rtc_application_timers(C.byref(hw),fw,tail,C.byref(cpu),C.byref(p))==1
  assert cpu.entry==p.entry==0xe05d698 and cpu.arg0==0 and h(0x65e6)==0;counts['reboot_boundary']+=1;counts['RTC_events']+=1
paths=sorted(P.glob('*.c'))+list(P.glob('*.h'))+[Path(__file__),A/'libreceiver_application_timers.dylib',A/'receiver-application-timers-original.jsonl']
d={'status':'PASS',**counts,'not_added_to_original_input_count':True,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['Coherent RAM fixture, explicit RTC time/event/enable inputs and opaque32B message tails; not full boot or CPU stack reconstruction','USB and TX queue sinks drained explicitly; configuration events read with real queue consumer but not hardware execution','Stops at reboot entry; no physical reboot, writes, USB or RF communication']}
(A/'receiver-application-timers-continuous-comparison.json').write_text(json.dumps(d,indent=2)+'\n');print(json.dumps({k:v for k,v in d.items() if k!='sources'},indent=2))
