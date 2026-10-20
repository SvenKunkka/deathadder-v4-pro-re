from pathlib import Path
import ctypes as C,json,hashlib,gzip,base64,struct
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
names=['ram','radio','timer','nvic','dppi','rtc','clock0','clock1','clock2','deviceid']
class HW(C.Structure):_fields_=[(n,Ptr) for n in names]
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
f=C.CDLL(str(A/'libreceiver_timer_expiry.dylib'))
f.rr_receiver_connection_publish.argtypes=[Ptr,Ptr,Ptr,Ptr,C.POINTER(CPU)]
f.rr_receiver_disconnect_notice_timed.argtypes=[Ptr,Ptr,Ptr,Ptr,C.POINTER(CPU)]
f.rr_receiver_notification_iteration.argtypes=[C.POINTER(HW),Ptr,W,Ptr,C.POINTER(CPU)]
f.rr_bt_pop.argtypes=[Ptr,C.c_int,C.c_uint,C.c_uint]
row=next(json.loads(s) for s in (A/'receiver-notification-runtime-original.jsonl').open() if json.loads(s)['case']==3074)
mem={n:(U*len(gzip.decompress(base64.b64decode(row[n+'_before'])))).from_buffer_copy(gzip.decompress(base64.b64decode(row[n+'_before']))) for n in names};m=mem['ram'];rtc=mem['rtc'];hw=HW(*[mem[n] for n in names]);cpu=CPU(0x80,0,0,0)
def w(a):return int.from_bytes(bytes(m[a:a+4]),'little')
def pw(a,v):m[a:a+4]=v.to_bytes(4,'little')
def ph(a,v):m[a:a+2]=v.to_bytes(2,'little')
q=0x1b8c;pw(q,0x23001b8c);pw(q+4,0x23001b8c);pw(q+24,0x23015760);pw(q+28,0x23015760);pw(q+32,0)
pw(0x1a48,0x23001a48);pw(0x1a4c,0x23001a48);pw(0x1a54,0);pw(0x65e2,0)
ph(0x2c80,0);ph(0x2c82,1);m[0x490]=2;m[0x6836]=0;m[0x683a]=0
output=C.cast(C.byref(m,0x9000),Ptr);image=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();flash=(U*len(image)).from_buffer_copy(image)

class RtcHW(C.Structure):_fields_=[('ram',Ptr),('rtc',Ptr)]
class Pending(C.Structure):_fields_=[('entry',W),('args',W*5)]
f.rr_receiver_rtc_dispatch_timers.argtypes=[C.POINTER(RtcHW),Ptr,C.POINTER(CPU),C.POINTER(Pending)]
rh=RtcHW(m,rtc)
# Seed inactive timer and empty timeout state, then use real producers only.
for off in [0x1a30,0x1a34,0x2c60,0x2c64,0x7188,0x718c,0x7194,0x7198]:pw(off,0)
pw(0xb48,0x23000b48);pw(0xb4c,0x23000b48);pw(0x958,0xe0683a1);pw(0x95c,0);m[0x960]=7;pw(0xab4,0);pw(0xab8,0)
pw(0x2840,0);pw(0x2844,0);pw(0x2c78,0);pw(0x2c7c,0);pw(0x1a50,0x230255b9);m[0x71e4]=1
counts={'cycles':0,'notification_messages':0,'actual_timer_expiries':0,'disconnect_reports_queued':0,'explicit_RTC_events':0}
for cycle in range(128):
 now=cycle*2100000;rtc[0x770:0x778]=now.to_bytes(8,'little');m[0x6836]=m[0x683a]
 pair=(U*8).from_buffer_copy(struct.pack('<II',0,0x12340000+cycle));tail=(U*24).from_buffer_copy(bytes((cycle+j)&255 for j in range(24)))
 cpu.exception_number=0
 assert f.rr_receiver_connection_publish(m,rtc,pair,tail,C.byref(cpu))==0
 assert f.rr_receiver_notification_iteration(C.byref(hw),flash,0x23009000,output,C.byref(cpu))==0
 assert w(0x65e2)==0 and w(0x1a30)==0 and int.from_bytes(bytes(m[0x2c80:0x2c82]),'little')&2
 assert f.rr_receiver_disconnect_notice_timed(m,rtc,pair,tail,C.byref(cpu))==0
 assert f.rr_receiver_notification_iteration(C.byref(hw),flash,0x23009000,output,C.byref(cpu))==0
 assert w(0x1a30)!=0 and w(0xb48)==0x23001a30 and w(0x65e2)==4
 deadline=int.from_bytes(bytes(rtc[0x590:0x598]),'little');assert deadline==now+2000000
 # Explicit peripheral compare flag, counter and enable readback.
 rtc[0x770:0x778]=deadline.to_bytes(8,'little');rtc[0x11c:0x120]=(1).to_bytes(4,'little');rtc[0x350:0x354]=(128).to_bytes(4,'little')
 before=m[0x683a];m[0x6836]=before;cpu.exception_number=125;p=Pending()
 assert f.rr_receiver_rtc_dispatch_timers(C.byref(rh),flash,C.byref(cpu),C.byref(p))==0
 assert p.entry==0 and w(0x1a30)==0 and w(0xb48)==0x23000b48 and w(0x1a60)==1
 assert bytes(m[0x6590:0x6592])==b'\0\0' and w(0x65e2)==0x50000
 assert not(int.from_bytes(bytes(m[0x2c80:0x2c82]),'little')&2)
 assert m[0x683a]==(before+1)%4 and bytes(m[0x68bc+before*16:0x68cc+before*16])==bytes([5,9,2,1])+bytes(12)
 assert bytes(m[0x353c:0x3548])==bytes(12) and cpu.priority==0x80
 assert w(q+32)==0
 for key,inc in [('cycles',1),('notification_messages',2),('actual_timer_expiries',1),('disconnect_reports_queued',1),('explicit_RTC_events',1)]:counts[key]+=inc
paths=sorted(P.glob('*.c'))+list(P.glob('*.h'))+[Path(__file__),A/'libreceiver_timer_expiry.dylib',A/'receiver-notification-runtime-original.jsonl']
d={'status':'PASS',**counts,'not_added_to_original_input_count':True,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'checks':['Real connect/disconnect producers and notification consumer register original2-million-tick timer','Explicit RTC event enters dispatcher,clock announce,generic timer and registered disconnect callback without callback success substitution','Original connection state/reset and USB disconnect packet bytes checked after each expiry'],'limits':['Initial coherent RAM from retained fixture and official callback identity; no full boot','Time,event and interrupt-enable readback supplied; USB sink drained explicitly','No actual USB transmission,RF or concurrent CPU scheduling']}
(A/'receiver-timer-expiry-continuous-comparison.json').write_text(json.dumps(d,indent=2)+'\n');print(json.dumps({k:v for k,v in d.items() if k!='sources'},indent=2))
