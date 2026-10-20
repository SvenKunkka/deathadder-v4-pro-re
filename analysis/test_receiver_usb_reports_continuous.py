from pathlib import Path
import ctypes as C,json,hashlib,collections
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U);lib=A/'libreceiver_usb_reports.dylib';f=C.CDLL(str(lib))
class Call(C.Structure):_fields_=[('entry',W),('device',W),('length',W),('buffer',W)]
Hook=C.CFUNCTYPE(C.c_int32,C.c_void_p,Ptr,C.POINTER(Call));f.rr_receiver_usb_reports.argtypes=[Ptr,Ptr,W,Hook,C.c_void_p,C.POINTER(Call)];f.rr_dbc_usb_enqueue.argtypes=[Ptr,C.c_uint,Ptr,W];f.rr_dbc_usb_enqueue.restype=U
fw=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();m=(U*131072)();aux=(U*4096)();m[:0x1e08]=fw[0x1c854:0x1c854+0x1e08];m[0x71e4]=1
mapping={cls:m[0x48c+cls] for cls in [1,2,4]};assert set(mapping.values())=={0,1,2};counts=collections.Counter();pending=Call();expected={ch:[] for ch in range(3)};failed_payloads={};fail_mode=False;errors=[]
@Hook
def driver(_,mem,ptr):
 c=ptr.contents;ch={0xe06f6a4:0,0xe06f690:1,0xe06f67c:2}[c.device];payload=bytes(mem[c.buffer-0x23000000+i] for i in range(c.length));counts['driver_attempts']+=1
 if not expected[ch] or payload!=expected[ch][0]:errors.append({'ch':ch,'payload':payload.hex(),'expected':expected[ch][0].hex() if expected[ch] else None})
 if fail_mode:
  failed_payloads[ch]=payload;counts['external_failure']+=1;return -13
 if ch in failed_payloads:
  if failed_payloads.pop(ch)!=payload:errors.append('failed payload not retried')
  counts['retry_same_payload']+=1
 expected[ch].pop(0);counts['external_success']+=1
 # Explicit environment completion inputs: no real USB callback modeled.
 if ch==0:mem[0x6904]=0
 else:mem[0x6900+ch]=0;mem[0x6908+ch]=0
 return 0
for cycle in range(64):
 for cls,ch in mapping.items():
  n=16 if ch==1 else 8
  for slot in range(3):
   payload=bytes((cycle*13+slot*37+ch*71+i)&255 for i in range(n));buf=(U*n).from_buffer_copy(payload);assert f.rr_dbc_usb_enqueue(m,cls,buf,n)==1;expected[ch].append(payload);counts['enqueued']+=1
  before=bytes(m);assert f.rr_dbc_usb_enqueue(m,cls,buf,n)==0 and bytes(m)==before;counts['full_rejects']+=1
 clone=(U*len(m)).from_buffer_copy(m);assert f.rr_receiver_usb_reports(clone,aux,0x23026d28,Hook(),None,C.byref(pending))==1 and pending.entry==0xe064288;counts['real_driver_boundaries']+=1
 old=bytes(m[0x6834:0x6837]);fail_mode=True;assert f.rr_receiver_usb_reports(m,aux,0x23026d28,driver,None,C.byref(pending))==0;assert bytes(m[0x6834:0x6837])==old
 fail_mode=False
 for _ in range(3):assert f.rr_receiver_usb_reports(m,aux,0x23026d28,driver,None,C.byref(pending))==0
 assert not any(expected.values()) and not failed_payloads;assert bytes(m[0x6834:0x6837])==bytes(m[0x6838:0x683b])
assert not errors,errors[:5]
paths=[P/'receiver_usb_reports.c',P/'receiver_usb_reports.h',P/'dongle_business_consumer.c',P/'dongle_business_consumer.h',Path(__file__),lib]
d={'status':'PASS','cycles':64,'counts':dict(counts),'class_to_ring':mapping,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['Component producer/callback sequencing is explicit, not recovered work-thread execution','AllUSB results and completion state are explicit external inputs; no physicalUSB/RF','Not additional original-instruction input cases']};(A/'receiver-usb-reports-continuous-comparison.json').write_text(json.dumps(d,indent=2)+'\n');print(json.dumps({k:v for k,v in d.items() if k!='sources'},indent=2))
