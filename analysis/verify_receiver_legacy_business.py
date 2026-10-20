#!/usr/bin/env python3
import base64,ctypes as C,gzip,hashlib,json,subprocess,tempfile
from pathlib import Path
B=Path(__file__).resolve().parents[1];U=C.c_uint8;P=C.POINTER(U)
class Pending(C.Structure):_fields_=[('active',U),('selected_peer',U),('forward_peer',U),('metadata',U),('device',C.c_uint32)]
def uz(s):return gzip.decompress(base64.b64decode(s))
def main():
 modules=['receiver_legacy_business','business_rx','business_cipher','business_control','business_tx','dongle_business_consumer']
 with tempfile.TemporaryDirectory(prefix='rbf-') as t:
  libpath=Path(t)/'lib.dylib';subprocess.run(['/usr/bin/cc','-std=c11','-Wall','-Wextra','-Werror','-O2','-shared','-fPIC',*[str(B/f'recovered-code/portable/{m}.c') for m in modules],'-o',str(libpath)],check=True)
  lib=C.CDLL(str(libpath));lib.rr_receiver_legacy_business.argtypes=[P,P,C.c_uint,C.c_uint,C.POINTER(Pending)];lib.rr_receiver_legacy_business.restype=C.c_int
  lib.rr_receiver_legacy_resume.argtypes=[P,C.c_int32,C.POINTER(Pending)];lib.rr_receiver_legacy_resume.restype=C.c_int
  raw=(B/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();flash=(U*len(raw)).from_buffer_copy(raw)
  fail=[];count=0;tails=0;byclass={};bymode={};bypeer={};steps=0;tailsteps=0;short_b1=0
  for line in (B/'analysis/receiver-legacy-business-original.jsonl').read_text().splitlines():
   d=json.loads(line);before=uz(d['before_gzip']);ram=(U*65536).from_buffer_copy(before);nvic=C.c_uint32(0x12345678);pending=Pending()
   ret=lib.rr_receiver_legacy_business(ram,flash,d['mode'],d['peer'],C.byref(pending));err=[]
   def compare(actual,expected,stage):
    if actual!=expected:
     diff=[i for i,(a,b) in enumerate(zip(actual,expected)) if a!=b];err.append({'stage':stage,'count':len(diff),'bytes':[(hex(0x23000000+i),actual[i],expected[i]) for i in diff[:20]]})
   compare(bytes(ram),uz(d['after_gzip']),'entry')
   if ret!=int(d['pending']):err.append({'return':ret,'expected_pending':d['pending']})
   if nvic.value!=d['nvic_after']:err.append({'nvic':nvic.value,'expected':d['nvic_after']})
   if d['pending']:
    if pending.device!=d['device']:err.append({'device':pending.device,'expected':d['device']})
    rc=lib.rr_receiver_legacy_resume(ram,d['driver_result'],C.byref(pending));assert rc==0 and pending.active==0
    compare(bytes(ram),uz(d['continuation_gzip']),'external_result_continuation');tails+=1
   if d['class']==3:
    b=0x33e8+d['peer']*0xf84
    if before[b+0x118]==0xb1 and before[b+0x114]<11:short_b1+=1
   if err:fail.append({'case':d['case'],'mode':d['mode'],'class':d['class'],'peer':d['peer'],'variant':d['variant'],'errors':err})
   bymode[str(d['mode'])]=bymode.get(str(d['mode']),0)+1;bypeer[str(d['peer'])]=bypeer.get(str(d['peer']),0)+1;steps+=d['steps'];tailsteps+=d['tail_steps'];count+=1;byclass[str(d['class'])]=byclass.get(str(d['class']),0)+1
  sources={}
  for fn in [*[f'recovered-code/portable/{m}.c' for m in modules],'analysis/receiver-legacy-business-original.jsonl','ghidra-scripts/EmulateReceiverLegacyBusiness.java']:
   sources[fn]=hashlib.sha256((B/fn).read_bytes()).hexdigest()
  report={'status':'PASS' if not fail else 'FAIL','original_entrypoint_cases':count,'by_class':byclass,'by_mode':bymode,'by_context':bypeer,'original_steps_to_boundary_or_return':steps,'continuation_steps':tailsteps,'full_returns':count-tails,'real_driver_boundary_cases':tails,'explicit_environment_result_continuations':tails,'short_B1_input_fixtures':short_b1,'checks':['all65536 RAM bytes','NVIC pending word','driver boundary device pointer','delayed peer-aware statistics and selected-peer interval clear after explicit resume'],'failures':fail,'sources':sources,'limits':['USB driver0E0622BC not executed; return supplied explicitly for separate continuation checks','RX cipher completion length8/16 domain retained','no RF/hardware/IRQ timing validation']}
  (B/'analysis/receiver-legacy-business-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']}));print(json.dumps(fail[:8],indent=2));assert not fail
if __name__=='__main__':main()
