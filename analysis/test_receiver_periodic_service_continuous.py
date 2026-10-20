from pathlib import Path
import ctypes as C,json,hashlib
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
class HW(C.Structure):_fields_=[(n,Ptr) for n in ['ram','radio','timer','nvic','dppi','rtc','clock0','clock1','clock2','deviceid']]
class Pending(C.Structure):_fields_=[('entry',W),('args',W*5)]
f=C.CDLL(str(A/'libreceiver_periodic_service.dylib'));f.rr_receiver_periodic_init.argtypes=[Ptr,Ptr,C.POINTER(W)];f.rr_receiver_periodic_refresh.argtypes=[Ptr,Ptr,Ptr,C.POINTER(W)];f.rr_receiver_periodic_dispatch.argtypes=[Ptr,Ptr,Ptr,Ptr,C.POINTER(CPU),C.POINTER(Pending)];f.rr_receiver_clock_allocate.argtypes=[Ptr];f.rr_receiver_clock_allocate.restype=W
image=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();fw=(U*len(image)).from_buffer_copy(image);m=(U*131072)();r=(U*4096)();s=(U*4096)();m[:0x1e08]=image[0x1c854:0x1c854+0x1e08]
def w(a):return int.from_bytes(bytes(m[a:a+4]),'little')
def put(b,a,v,n=4):b[a:a+n]=v.to_bytes(n,'little')
put(m,0xab4,0xe080);put(m,0xab8,0);put(m,0x6db0,0);m[0x71eb]=0;result=W();assert f.rr_receiver_periodic_init(m,s,C.byref(result))==0
assert result.value==15 and w(0x2df8)==15 and m[0x71eb]==1 and w(0xab4)==0x6080
assert bytes(s[0x504:0x510])==(65536).to_bytes(4,'little')+(1).to_bytes(4,'little')+bytes(4) and bytes(s[:4])==b'\1\0\0\0'
assert f.rr_receiver_clock_allocate(m)==14 and f.rr_receiver_clock_allocate(m)==13 and f.rr_receiver_clock_allocate(m)==0xfffffff4 and w(0xab4)==0x80
put(r,0x770,123,8);put(m,0x2840,123,8);put(m,0x2c78,123,8);put(m,0x7198,0)
assert f.rr_receiver_periodic_refresh(m,r,s,C.byref(result))==0 and result.value==0
assert w(0xabc+36)==0xe05bde1 and w(0xac0+36)==0 and m[0xac4+36]==15
cpu=CPU(0x80,125,0,0);events=0
# Explicit system-clock ownership and coherent thread/timeout fixture.
f.rr_receiver_timer_start_control.argtypes=[Ptr,Ptr,W,C.c_uint64,C.c_uint64,C.POINTER(CPU)]
f.rr_receiver_rtc_known_callbacks.argtypes=[C.POINTER(HW),Ptr,Ptr,Ptr,C.POINTER(CPU),C.POINTER(Pending)]
other=[(U*4096)() for _ in range(7)];device=(U*8)();hw=HW(m,other[0],other[1],other[2],other[3],r,other[4],other[5],other[6],device);tail=(U*32)()
put(m,0xab4,0);put(m,0x958,0xe0683a1);put(m,0x95c,0);m[0x960]=7
for a,v in [(0xb48,0x23000b48),(0xb4c,0x23000b48),(0x7170,0x23006000),(0x717c,0x23006000),(0x7174,0x23006000),(0x7180,0x23007180),(0x7184,0x23007180)]:put(m,a,v)
m[0x1ad8:0x1b10]=bytes(0x38);put(m,0x1af0,0x23001af0);put(m,0x1af4,0x23001af0);put(m,0x1af8,0x23025641)
assert f.rr_receiver_timer_start_control(m,r,0x23001ad8,100000,100000,C.byref(cpu))==0

for i in range(128):
 deadline=int.from_bytes(bytes(r[0x610:0x618]),'little');assert deadline==123+(i+1)*100000
 put(r,0x770,deadline,8);put(r,0x13c,1);put(r,0x11c,1);put(r,0x350,0x8080);put(s,0x600,0);p=Pending()
 assert f.rr_receiver_rtc_known_callbacks(C.byref(hw),s,fw,tail,C.byref(cpu),C.byref(p))==0
 assert p.entry==0 and cpu.priority==0x80 and bytes(s[0x600:0x604])==(0x6e524635).to_bytes(4,'little') and bytes(r[0x13c:0x140])==bytes(4)
 assert int.from_bytes(bytes(r[0x610:0x618]),'little')==deadline+100000
 assert w(0xabc+36)==0xe05bde1 and m[0xac4+36]==15 and w(0xab8)==0x8080 and w(0x1b08)==i+1;events+=1
paths=sorted(P.glob('*.c'))+list(P.glob('*.h'))+[Path(__file__),A/'libreceiver_periodic_service.dylib']
d={'status':'PASS','explicit_RTC_events':events,'application_timer_callbacks':128,'initial_arms':2,'successful_channel_allocations':3,'capacity_rejections':1,'not_added_to_original_input_count':True,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'checks':['Actual init then refresh and128RTC events executing both periodic and registered application timer callback, rearming by100000ticks','Original allocation descending15,14,13 then cap rejection; channel7 remains reserved','Register write, callback identity, event clear, priority and next compare verified each cycle'],'limits':['System clock ownership and empty scheduler initialized explicitly; stable RTC,event and enable readbacks; not full boot or autonomous time','No physical receiver or register access, no watchdog/reset or RF behavior established']}
(A/'receiver-periodic-service-continuous-comparison.json').write_text(json.dumps(d,indent=2)+'\n');print(json.dumps({k:v for k,v in d.items() if k!='sources'},indent=2))
