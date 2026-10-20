#!/usr/bin/env python3
"""Serialized C component sequences; explicit packets/events, not RF or new Thumb cases."""
import ctypes as C, json, subprocess, tempfile, gzip, base64, hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent
U=C.c_uint8;P=C.POINTER(U)
class HW(C.Structure):
 _fields_=[('radio',C.c_uint32*1024),('timer',C.c_uint32*512),('aux',C.c_uint32*512),('nvic_last',C.c_uint32),('nvic_requests',C.c_uint32)]
class Pending(C.Structure):
 _fields_=[('active',U),('peer',U),('metadata',U),('reserved',U),('device',C.c_uint32)]
class TP(C.Structure):
 _fields_=[('active',C.c_uint32),('entry',C.c_uint32),('arg0',C.c_uint32)]
class Event(C.Structure):
 _fields_=[('cls',U),('seq',U),('accepted',U),('kind',U),('work',U),('result',C.c_int)]
def p16(r,a,v):r[a]=v&255;r[a+1]=(v>>8)&255
def p32(r,a,v):
 for i in range(4):r[a+i]=(v>>(8*i))&255
def u16(r,a):return r[a]|r[a+1]<<8
modules=['mouse_mode4_radio','mouse_mode4_tx','mouse_adaptive_control','mouse_business_flow','receiver_radio_timer','receiver_radio_irq','receiver_business_flow','business_dispatch','business_rx','business_cipher','business_control','business_tx','dongle_business_consumer']
counts=dict(scenarios=0,periods=0,receiver_timer_events=0,receiver_uplink_inputs=0,receiver_generated_downlinks=0,mouse_timer_events=0,mouse_success_irqs=0,mouse_crc_fail_irqs=0,new_business_completions=0,duplicate_business_rejections=0,adaptive_services=0,receiver_scan_irq_events=0)
with tempfile.TemporaryDirectory(prefix='mouse-mode4-components-') as td:
 libpath=Path(td)/'lib.dylib';subprocess.run(['rtk','proxy','clang','-std=c11','-Wall','-Wextra','-Werror','-O2','-shared','-fPIC',*[str(B/f'recovered-code/portable/{x}.c') for x in modules],'-o',str(libpath)],check=True)
 l=C.CDLL(str(libpath))
 specs={'rr_bt_init':([P,C.c_int,C.c_uint],None),'rr_bt_dongle_tx':([P,C.c_uint,C.c_uint,P,C.c_uint32,C.c_void_p,C.c_void_p],C.c_uint32),'rr_receiver_timer_mode4':([P,P,C.POINTER(HW),C.POINTER(TP)],C.c_int),'rr_receiver_radio_irq':([P,P,C.POINTER(HW)],C.c_int),'rr_receiver_radio_swi4':([P,P,C.POINTER(HW),C.POINTER(Pending)],C.c_int),'rr_mouse_mode4_radio':([P,P,P,C.POINTER(C.c_uint32)],C.c_int),'rr_mouse_mode4_timer':([P,P,P,P,C.POINTER(C.c_uint32)],C.c_int),'rr_mouse_mode4_action':([P,P,C.c_uint32],C.c_int),'rr_mouse_business_flow':([P,C.POINTER(Event)],C.c_int),'rr_mouse_adaptive_irq':([P],C.c_int)}
 for name,(args,ret) in specs.items():getattr(l,name).argtypes=args;getattr(l,name).restype=ret
 flash=(B/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();f=(U*len(flash)).from_buffer_copy(flash)
 baseline=next(json.loads(x) for x in (B/'analysis/receiver-radio-timer-original.jsonl').read_text().splitlines() if json.loads(x)['event']==0 and json.loads(x)['variant']==1)
 details=[]
 for mode in range(4):
  for bank in [0,2]:
   d=(U*65536).from_buffer_copy(gzip.decompress(base64.b64decode(baseline['before_gzip'])));h=HW();m=(U*65536)();radio=(U*4096)();timer=(U*1536)();spim=(U*16)();nv=C.c_uint32()
   for a,v in [(0x3230,3),(0x3234,4),(0x323e,mode),(0x3470,0),(0x5376,0),(0x32ca,0),(0x347e,255)]:p16(d,a,v)
   for a,v in [(0x33e8,3),(0x52f0,3),(0x3468,11),(0x5370,13),(0x3474,0)]:p32(d,a,v)
   d[0x325d]=0;l.rr_bt_init(d,0,0);l.rr_bt_init(m,1,0)
   d[0x348f:0x3495]=bytes([1]*6);d[0x3482]=1;d[0x3483]=0
   for a,v in [(0x2798,4),(0x2794,3),(0x2836,bank),(0x278e,mode),(0x2a1a,255),(0x27a2,0)]:p16(m,a,v)
   p32(m,0x67ac,4);p32(m,0x29e0,1);m[0x27a0]=1
   def dtick(ev):
    for k in range(8):h.timer[(0x140+4*k)//4]=0
    h.timer[(0x140+4*ev)//4]=1;h.timer[0x55c//4]=0
    pending=TP();assert l.rr_receiver_timer_mode4(d,f,C.byref(h),C.byref(pending))==0;counts['receiver_timer_events']+=1
   def mtick(ev):
    for k in range(8):p32(timer,0x140+4*k,0)
    p32(timer,0x140+4*ev,1);assert l.rr_mouse_mode4_timer(m,radio,timer,spim,C.byref(nv))==0;counts['mouse_timer_events']+=1
   def deliver(packet,crc,duplicate=False):
    # Explicit environment availability, DMA bytes, CRC and DISABLED event.
    p32(m,0x2a04,0x18);m[0x2a20]=1;assert l.rr_mouse_mode4_action(m,radio,6)==0
    m[0x2630:0x2640]=packet;p32(radio,0x220,1);p32(radio,0x22c,crc);p32(radio,0x718,40+mode);p32(timer,0x55c,180)
    assert l.rr_mouse_mode4_radio(m,radio,timer,C.byref(nv))==0
    assert nv.value==0x08000000
    if crc:
     ev=Event();assert l.rr_mouse_business_flow(m,C.byref(ev))==0
     if duplicate:assert ev.accepted==0;counts['duplicate_business_rejections']+=1
     else:assert ev.accepted==1 and ev.work==1 and ev.result==0;counts['new_business_completions']+=1
     counts['mouse_success_irqs']+=1
    else:counts['mouse_crc_fail_irqs']+=1
    assert l.rr_mouse_adaptive_irq(m)==0;counts['adaptive_services']+=1
   for period in range(1,33):
    body=(U*4)(0xa3,period,mode,0);assert l.rr_bt_dongle_tx(d,0,3,body,3,None,None)==1
    dtick(0);dtick(1);assert u16(d,0x32d0)==1
    # External uplink ACK/input, not claimed to originate from unimplemented mouse TX.
    p32(d,0x3468,12);d[0x3050]=8;d[0x3051]=0x80|(((period-1)%7+1)<<4);d[0x3052]=1;d[0x3053]=0x2c;d[0x3054]=1;d[0x3055]=0;d[0x3056]=2;d[0x3057]=0;d[0x3058]=(-sum(d[0x3051:0x3058]))&255
    h.radio[0x218//4]=1;h.radio[0x22c//4]=1;h.radio[0x220//4]=1
    assert l.rr_receiver_radio_irq(d,f,C.byref(h))==0
    pp=Pending();assert l.rr_receiver_radio_swi4(d,f,C.byref(h),C.byref(pp))==0;counts['receiver_uplink_inputs']+=1
    dtick(2);dtick(1);assert u16(d,0x32d0)==2 and h.radio[0xed0//4]==0x23003070,(period,mode,bank,u16(d,0x32d0),hex(h.radio[0xed0//4]),list(d[0x5370:0x5374]))
    packet=bytes(d[0x3070:0x3080]);assert packet[0]==7 and ((packet[2]&63)>>3)==3,(period,mode,bank,packet.hex(),u16(d,0x347e),list(d[0x353c:0x3548]));counts['receiver_generated_downlinks']+=1
    # Only modeled timer paths used: CC0 maintenance, later slot5 accounting.
    p32(m,0x2a04,0x18);mtick(0)
    if period%4==0:deliver(packet,0)
    deliver(packet,1);assert bytes(m[0x67d0:0x67d4])==bytes(body)
    if period%3==0:deliver(packet,1,True)
    p16(m,0x283c,5);mtick(2)
    for ev in [2,1,2,1,2,1]:dtick(ev)
    # Complete pending RSSI scan with explicit external hardware events.
    for scanstep in range(3):
     state=int.from_bytes(bytes(d[0x5370:0x5374]),'little')
     if state==13:break
     assert state in (14,15,16)
     h.radio[0x208//4]=1 if state==15 else 0;h.radio[0x220//4]=0 if state==15 else 1
     assert l.rr_receiver_radio_irq(d,f,C.byref(h))==0;counts['receiver_scan_irq_events']+=1
    assert int.from_bytes(bytes(d[0x5370:0x5374]),'little')==13
    dtick(2);dtick(1)
    counts['periods']+=1
   counts['scenarios']+=1;details.append({'channel_mode':mode,'initial_mouse_bank':bank,'periods':32,'completed_class3_messages':32})
 result={'status':'PASS','component_integration':counts,'scenarios':details,'original_instruction_cases_added':0,'limits':['serialized C event chains, not new original-instruction cases','uplinks and CRC/event delivery explicitly injected; no recovered mouse TX selection or RF/DPPI/time','receiver downlink comes from real restored class3 enqueue and timer selection','consumer remains deferred; real work.flags=4 natural fast return only','mouse timer exercised CC0 and slot5 CC2, not all transmit-selection slots','no nonzero ACK callback, concurrent IRQ/work scheduling or physical behavior'], 'source_sha256':{str((B/f'recovered-code/portable/{x}.c').relative_to(B)):hashlib.sha256((B/f'recovered-code/portable/{x}.c').read_bytes()).hexdigest() for x in modules}}
 (B/'analysis/mouse-mode4-integration.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(counts))
