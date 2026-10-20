#!/usr/bin/env python3
"""Compile authored host code, compare complete RAM/input against original ARM cases."""
import base64,ctypes as C,gzip,hashlib,json,subprocess,tempfile
from pathlib import Path
BASE=Path(__file__).resolve().parents[1]
U8=C.c_uint8; P=C.POINTER(U8);HOOK=C.CFUNCTYPE(None,C.c_void_p,P,C.c_uint)
def unpack(s):return gzip.decompress(base64.b64decode(s))
def run():
 with tempfile.TemporaryDirectory(prefix='business-tx-') as td:
  libpath=Path(td)/'libtx.dylib'
  subprocess.run(['/usr/bin/cc','-std=c11','-Wall','-Wextra','-Werror','-O2','-shared','-fPIC',str(BASE/'recovered-code/portable/business_tx.c'),str(BASE/'recovered-code/portable/business_cipher.c'),'-o',str(libpath)],check=True)
  lib=C.CDLL(str(libpath))
  for name in ['init','free','peek','pop']:
   f=getattr(lib,'rr_bt_'+name);f.argtypes=[P,C.c_int,C.c_uint]+([] if name=='init' else [C.c_uint]);f.restype=C.c_uint32
  lib.rr_bt_enqueue.argtypes=[P,C.c_int,C.c_uint,C.c_uint,P,C.c_uint32,C.c_uint16];lib.rr_bt_enqueue.restype=C.c_int
  for side in ['mouse','dongle']:
   f=getattr(lib,'rr_bt_'+side+'_tx');f.argtypes=[P,C.c_uint,C.c_uint,P,C.c_uint32,HOOK,C.c_void_p];f.restype=C.c_uint32
  failures=[];cases=0;injections=0;counts={};sources={}
  for side in ['mouse','dongle']:
   path=BASE/f'analysis/{side}-business-tx-original.jsonl';sources[str(path.relative_to(BASE))]=hashlib.sha256(path.read_bytes()).hexdigest()
   for line in path.read_text().splitlines():
    d=json.loads(line);m=d['mouse'];peer=d['peer'];cls=d['class'];op=d['op'];before=unpack(d['before_gzip']);ram=(U8*65536).from_buffer_copy(before);data=(U8*128).from_buffer_copy(bytes.fromhex(d['input']))
    def hook(_,mem,index):
     if index==d['fail_at']:
      ctx=(0x2978 if m else 0x33e8)+peer*(0xee0 if m else 0xf84);wo=0x15e if m else 0x154;ro=0x164 if m else 0x15a;co=0x16a if m else 0x160
      mem[ctx+ro+cls]=(mem[ctx+wo+cls]+1)%mem[ctx+co+cls]
    cb=HOOK(hook)
    if op==0:ret=lib.rr_bt_init(ram,m,peer)
    elif op==1:ret=lib.rr_bt_free(ram,m,peer,cls)
    elif op==2:ret=lib.rr_bt_peek(ram,m,peer,cls)
    elif op==3:ret=lib.rr_bt_pop(ram,m,peer,cls)
    elif op==4:ret=lib.rr_bt_enqueue(ram,m,peer,cls,data,d['length'],0x12ef)
    else:ret=getattr(lib,'rr_bt_'+side+'_tx')(ram,peer,cls,data,d['length'],cb,None)
    errs=[];expected=unpack(d['after_gzip']);actual=bytes(ram)
    if actual!=expected:
     changed=[hex(0x23000000+i) for i,(a,b) in enumerate(zip(actual,expected)) if a!=b];errs.append({'RAM_differences':changed[:20],'count':len(changed)})
    if bytes(data)!=bytes.fromhex(d['input_after']):errs.append({'input_expected':d['input_after'],'actual':bytes(data).hex()})
    if op not in (0,3) and ret!=d['r0']:errs.append({'return_expected':d['r0'],'actual':ret})
    if errs:failures.append({'side':side,'case':d['case'],'op':op,'class':cls,'variant':d['variant'],'errors':errs})
    cases+=1;injections+=d['injected'];counts[f'{side}_op{op}']=counts.get(f'{side}_op{op}',0)+1
  for path in ['recovered-code/portable/business_tx.c','recovered-code/portable/business_tx.h','ghidra-scripts/EmulateBusinessTx.java']:
   sources[path]=hashlib.sha256((BASE/path).read_bytes()).hexdigest()
  report={'status':'PASS' if not failures else 'FAIL','original_instruction_cases':cases,'injected_interleaving_cases':injections,'by_operation':counts,'checked':['all65536 RAM bytes','128 input/guard bytes','r0 except init/pop void semantics'],'failures':failures,'sources':sources,'limits':['software emulation; no RF or device validation','CPU interrupt masking/timing not asserted','explicit hook injections are external state interleavings, not recovered firmware code','bounded valid class/length domain; no claim for buffer overflow inputs']}
  (BASE/'analysis/business-tx-original-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']}));print('failures',json.dumps(failures[:5],indent=2));assert not failures
if __name__=='__main__':run()
