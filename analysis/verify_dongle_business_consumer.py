#!/usr/bin/env python3
import base64,ctypes as C,gzip,hashlib,json,subprocess,tempfile
from pathlib import Path
B=Path(__file__).resolve().parents[1];U=C.c_uint8;P=C.POINTER(U)
def unzip(s):return gzip.decompress(base64.b64decode(s))
def main():
 with tempfile.TemporaryDirectory(prefix='dbc-') as tmp:
  library=Path(tmp)/'lib.dylib';subprocess.run(['/usr/bin/cc','-std=c11','-Wall','-Wextra','-Werror','-O2','-shared','-fPIC',str(B/'recovered-code/portable/dongle_business_consumer.c'),'-o',str(library)],check=True)
  lib=C.CDLL(str(library));lib.rr_dbc_usb_enqueue.argtypes=[P,C.c_uint,P,C.c_uint32];lib.rr_dbc_usb_enqueue.restype=U
  lib.rr_dbc_consume.argtypes=[P,P,C.c_uint,P,C.c_uint32];lib.rr_dbc_consume.restype=C.c_int
  lib.rr_dbc_management.argtypes=[P,P,C.c_uint,P];lib.rr_dbc_management.restype=C.c_uint32
  lib.rr_dbc_status.argtypes=[P,P,C.c_uint,C.c_uint32];lib.rr_dbc_resume_result.argtypes=[P,C.c_int32]
  fp=B/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin';raw=fp.read_bytes();flash=(U*len(raw)).from_buffer_copy(raw)
  source=B/'analysis/dongle-business-consumer-original.jsonl';counts={};failures=[];boundary=0
  for line in source.read_text().splitlines():
   d=json.loads(line);before=unzip(d['before_gzip']);ram=(U*65536).from_buffer_copy(before);data=(U*128).from_buffer_copy(bytes.fromhex(d['input']));op=d['op']
   if op==0:ret=lib.rr_dbc_usb_enqueue(ram,d['class'],data,d['length'])
   elif op==1:ret=lib.rr_dbc_consume(ram,flash,d['class'],data,d['length'])
   elif op==2:ret=lib.rr_dbc_management(ram,flash,d['peer'],data)
   elif op==3:lib.rr_dbc_status(ram,flash,d['opcode'],d['value'])
   else:lib.rr_dbc_resume_result(ram,d['resume_result'])
   err=[];expected=unzip(d['after_gzip']);actual=bytes(ram)
   if expected!=actual:
    diff=[hex(0x23000000+i) for i,(a,b) in enumerate(zip(actual,expected)) if a!=b];err.append({'ram_diff':diff[:20],'count':len(diff),'actual':[(a,actual[int(a,16)-0x23000000],expected[int(a,16)-0x23000000]) for a in diff[:12]]})
   if bytes(data).hex()!=d['input_after']:err.append({'input_diff':True})
   if op in [0,2] and ret!=d['r0']:err.append({'ret':ret,'expected':d['r0']})
   if op==1 and bool(ret)!=d['boundary']:err.append({'boundary':ret,'expected':d['boundary']})
   if d['boundary']:
    boundary+=1;assert d['r0']==int.from_bytes(before[0x690c:0x6910],'little')
   if err:failures.append({'case':d['case'],'op':op,'class':d['class'],'errors':err})
   counts[str(op)]=counts.get(str(op),0)+1
  sources={}
  for path in ['recovered-code/portable/dongle_business_consumer.c','recovered-code/portable/dongle_business_consumer.h','analysis/dongle-business-consumer-original.jsonl','ghidra-scripts/EmulateDongleBusinessConsumer.java','firmware-extracted-1.20/Suit1FWData__radio_radio.bin']:
   sources[path]=hashlib.sha256((B/path).read_bytes()).hexdigest()
  report={'status':'PASS' if not failures else 'FAIL','original_instruction_cases':sum(counts.values()),'counts':counts,'boundary_stops':boundary,'continuation_cases':counts.get('4',0),'checked':['64KiB RAM including preserved bytes','128-byte input and guard','queue/management rawr0','actual USB driver boundary condition and r0 device argument'],'failures':failures,'sources':sources,'limits':['op4 starts at actual post-driver continuation with synthetic ABI frame and supplied environment result; does not execute USB driver','boundary cases stop before0E0622BC; no success stub','no CPU userop overrides or opcode replacements','no RF/hardware/concurrency validation']}
  (B/'analysis/dongle-business-consumer-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['failures','sources']}));print(json.dumps(failures[:5],indent=2));assert not failures
if __name__=='__main__':main()
