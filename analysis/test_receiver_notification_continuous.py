from pathlib import Path
import ctypes as C,json,hashlib,gzip,base64,struct
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
names=['ram','radio','timer','nvic','dppi','rtc','clock0','clock1','clock2','deviceid']
class HW(C.Structure):_fields_=[(n,Ptr) for n in names]
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
f=C.CDLL(str(A/'libreceiver_notification_runtime.dylib'))
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
counts={'cycles':0,'real_notification_messages':0,'timer_starts':0,'timer_stops':0,'usb_reports_queued':0,'usb_reports_dropped':0,'B1_messages_queued':0,'B1_messages_rejected':0,'explicit_usb_drains':0,'explicit_rf_queue_pops':0}
# Independent three-slot usable USB ring model; no USB transmission is simulated.
usb=bytearray(m[0x68bc:0x68fc]);rd=wr=0;pending=0
rf_w=0x33e8+0x154+3;rf_r=0x33e8+0x15a+3;rf_s=0x33e8+0xa7+3
for cycle in range(128):
 if cycle%4==0:rd=wr;pending=0;m[0x6836]=rd;counts['explicit_usb_drains']+=1
 if cycle%16==0:
  while m[rf_r]!=m[rf_w]:f.rr_bt_pop(m,0,0,3);counts['explicit_rf_queue_pops']+=1
 enabled=cycle%5!=0;m[0x71e4]=int(enabled)
 pair=(U*8).from_buffer_copy(struct.pack('<II',0,0x12340000+cycle));tail=(U*24).from_buffer_copy(bytes((cycle+j)&255 for j in range(24)))
 assert f.rr_receiver_disconnect_notice_timed(m,rtc,pair,tail,C.byref(cpu))==0
 assert f.rr_receiver_notification_iteration(C.byref(hw),flash,0x23009000,output,C.byref(cpu))==0
 assert bytes(output[:36])==struct.pack('<I',2)+bytes(pair)+bytes(tail)
 assert w(0x1a30)!=0 and int.from_bytes(bytes(m[0x65e2:0x65e4]),'little')==4 and bytes(m[0x65de:0x65e0])==b'\0\0'
 counts['timer_starts']+=1
 before_write,before_read,before_seq=m[rf_w],m[rf_r],m[rf_s];rf_before=bytes(m[0x396c:0x3b6c]);free=(before_read-before_write-1)%32
 assert f.rr_receiver_connection_publish(m,rtc,pair,tail,C.byref(cpu))==0
 assert f.rr_receiver_notification_iteration(C.byref(hw),flash,0x23009000,output,C.byref(cpu))==0
 assert bytes(output[:36])==struct.pack('<I',1)+bytes(pair)+bytes(tail)
 assert w(0x1a30)==0 and w(0x65e2)==0 and bytes(m[0x65e6:0x65e8])==b'\x05\0'
 assert int.from_bytes(bytes(m[0x6590:0x6592]),'little')&1 and int.from_bytes(bytes(m[0x2c80:0x2c82]),'little')&2
 counts['timer_stops']+=1
 for report in [bytes([5,9,3,1])+bytes(12),bytes([5,0x56,4])+bytes(13)]:
  if enabled and pending<3:usb[wr*16:(wr+1)*16]=report;wr=(wr+1)%4;pending+=1;counts['usb_reports_queued']+=1
  else:counts['usb_reports_dropped']+=1
 assert bytes(m[0x68bc:0x68fc])==usb and m[0x683a]==wr and m[0x6836]==rd
 if free>=2:
  payload=bytes([0xb1,m[0x71bd],m[0x71bc],1,m[0x71e5],1]);payload+=bytes([-sum(payload)&255])
  expected=[bytes([0x80])+payload[:4],bytes([1])+payload[4:]]
  for j,body in enumerate(expected):
   entry=0x396c+((before_write+j)%32)*16;seq=(before_seq-1+j)%7+1
   assert m[entry]==len(body) and m[entry+1]==255 and m[entry+2]==0 and m[entry+4]==len(body)+2 and m[entry+6]==seq|24
   assert bytes(m[entry+7:entry+7+len(body)])==body
  assert m[rf_w]==(before_write+2)%32 and m[rf_s]==(before_seq-1+2)%7+1
  counts['B1_messages_queued']+=1
 else:
  assert m[rf_w]==before_write and m[rf_s]==before_seq and bytes(m[0x396c:0x3b6c])==rf_before
  counts['B1_messages_rejected']+=1
 counts['cycles']+=1;counts['real_notification_messages']+=2
 assert w(q+32)==0 and cpu.priority==0x80
paths=[Path(__file__),P/'receiver_notification_runtime.c',P/'receiver_notification_runtime.h',P/'receiver_queue_runtime.c',P/'receiver_config_control.c',P/'receiver_timeout.c',P/'receiver_rtos_lifecycle.c',P/'dongle_business_consumer.c',P/'business_tx.c',A/'receiver-notification-runtime-original.jsonl']
report={'status':'PASS',**counts,'not_added_to_original_count':True,'checks':['Actual event2/event1 producers through36-byte queue and notification consumer','Each disconnect starts timer1A30; each connection stops it and clears full65E2 word','Independent USB ring capacity/FIFO/report bytes with explicit sink drains','B1 two-fragment payload, checksum, sequence and queue-full preservation','All24 prior-stack tail bytes preserved in queue messages'],'limits':['Explicit queue sink consumption; no USB transmission or RF events','No real CPU switching; priority80 suppresses wakeup switches','Synthetic opaque tail supplied explicitly; no full ABI stack generation'],'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths}}
(A/'receiver-notification-continuous-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k!='sources'},indent=2))
