from pathlib import Path
import json,hashlib,ctypes as C,subprocess,base64,gzip,collections
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;I=C.c_int32;Q=C.c_uint64;Ptr=C.POINTER(U)
files=sorted(P.glob('*.c'));lib=A/'libreceiver_work_rtc.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True);f=C.CDLL(str(lib))
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
f.rr_receiver_work_submit_to_queue.argtypes=[Ptr,Ptr,W,C.POINTER(W),C.POINTER(CPU),C.POINTER(I)]
f.rr_receiver_work_submit.argtypes=[Ptr,Ptr,W,W,C.POINTER(CPU),C.POINTER(I)]
f.rr_receiver_delayed_work_schedule.argtypes=[Ptr,Ptr,W,W,Q,C.c_int,C.POINTER(CPU),C.POINTER(I)]
f.rr_receiver_delayed_work_expiry.argtypes=[Ptr,Ptr,W,C.POINTER(CPU)]
f.rr_receiver_work_cancel.argtypes=[Ptr,W,C.POINTER(CPU),C.POINTER(W)]
f.rr_receiver_work_initialize.argtypes=[Ptr,W,W,C.c_int]
class HW(C.Structure):_fields_=[(n,Ptr) for n in ['ram','radio','timer','nvic','dppi','rtc','clock0','clock1','clock2','deviceid']]
class Pending(C.Structure):_fields_=[('entry',W),('args',W*5)]
f.rr_receiver_rtc_work_dispatch.argtypes=[C.POINTER(HW),Ptr,Ptr,Ptr,C.POINTER(CPU),C.POINTER(Pending)]
raw=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();fw=(U*len(raw)).from_buffer_copy(raw)
def un(z):return gzip.decompress(base64.b64decode(z))
rows=[json.loads(l) for l in (A/'receiver-work-rtc-original.jsonl').open()];assert len(rows)==512 and [t['case'] for t in rows]==list(range(512));fails=[];ends=collections.Counter()
for t in rows:
 bm=un(t['before_gzip']);br=un(t['rtc_before']);assert len(bm)==131072 and len(br)==4096;m=(U*len(bm)).from_buffer_copy(bm);r=(U*len(br)).from_buffer_copy(br);cpu=CPU(t['initial_priority'],t['exception'],0,0);result=I(0x12345678);q=W(t['queue']);out=W();op=t['op'];a=t['address']
 others=[(U*4096)() for _ in range(7)];device=(U*8)();service=(U*4096)();tail=(U*32)();hw=HW(m,others[0],others[1],others[2],others[3],r,others[4],others[5],others[6],device);p=Pending()
 rc=f.rr_receiver_rtc_work_dispatch(C.byref(hw),service,fw,tail,C.byref(cpu),C.byref(p))
 assert all(bytes(x)==bytes(len(x)) for x in others+[device,service])

 errors=[]
 for n,b,z in [('ram',bytes(m),'after_gzip'),('rtc',bytes(r),'rtc_after')]:
  expected=un(t[z]);assert len(b)==len(expected)
  if b!=expected:
   diffs=[i for i in range(len(b)) if b[i]!=expected[i]];errors.append({'window':n,'count':len(diffs),'first':[(hex(i),b[i],expected[i]) for i in diffs[:10]]})
 if rc!=bool(t['boundary']):errors.append({'rc':rc,'expected_boundary':t['boundary']})

 if op==0 and q.value!=t['queue_after']:errors.append({'queue':q.value,'expected':t['queue_after']})
 if cpu.priority!=t['final_priority'] or cpu.entry!=t['boundary'] or cpu.arg0!=t['arg0']:errors.append({'cpu':[cpu.priority,cpu.entry,cpu.arg0],'expected':[t['final_priority'],t['boundary'],t['arg0']]})
 if errors:fails.append({'case':t['case'],'op':op,'errors':errors})
 ends[hex(t['boundary'])]+=1
paths=files+list(P.glob('*.h'))+[Path(__file__),R/'ghidra-scripts/EmulateReceiverWorkRtc.java',A/'receiver-work-rtc-original.jsonl']
d={'status':'PASS' if not fails else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'endings':dict(ends),'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['Privileged serialized CPU with stable RTC, bounded coherent lists and full128KiB RAM/4KiB RTC snapshots','512 complete RTC dispatcher/clock/timeout/delayed-work expiry/submit inputs','Stops at actual CPU request; no resumed thread/callback or physicalUSB/RF behavior asserted']}
(A/'receiver-work-rtc-comparison.json').write_text(json.dumps(d,indent=2)+'\n');print(json.dumps({k:v for k,v in d.items() if k not in ['sources','failures']},indent=2));print(json.dumps(fails[:6],indent=2));assert not fails
