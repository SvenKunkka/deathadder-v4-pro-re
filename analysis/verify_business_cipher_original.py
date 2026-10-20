from pathlib import Path
import ctypes as C,struct,subprocess,json,hashlib
from business_software_cipher import transform
r=Path(__file__).resolve().parent.parent;src=r/'recovered-code/portable';lib=src/'build/librr_cipher.dylib'
subprocess.run(['rtk','proxy','clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-fPIC','-shared',str(src/'business_cipher.c'),'-o',str(lib)],check=True,capture_output=True,text=True)
f=C.CDLL(str(lib.resolve()));U32=C.c_uint32
for name in ('rr_cipher_encrypt_words','rr_cipher_decrypt_words'):
 fn=getattr(f,name);fn.argtypes=[C.POINTER(U32),C.c_uint,C.POINTER(U32)];fn.restype=C.c_int
fail=[];sources={};counts={}
for side in ('mouse','dongle'):
 p=r/'analysis'/f'{side}-cipher-original.jsonl';rows=[json.loads(x) for x in p.read_text().splitlines()];assert len(rows)==64
 sources[str(p.relative_to(r))]=hashlib.sha256(p.read_bytes()).hexdigest();counts[side]=len(rows)
 for row in rows:
  data=bytes.fromhex(row['input']);key=bytes.fromhex(row['key']);expected=bytes.fromhex(row['output_with_guard'])
  py=transform(data,key,decrypt=side=='dongle')+bytes([0xa5])*(32-len(data))
  words=(U32*8)(*struct.unpack('<8I',data+bytes([0xa5])*(32-len(data))));kw=(U32*4)(*struct.unpack('<4I',key))
  fn=f.rr_cipher_encrypt_words if side=='mouse' else f.rr_cipher_decrypt_words
  assert fn(words,len(data)//4,kw)==0
  actual=struct.pack('<8I',*words)
  if py!=expected or actual!=expected or row['key_after']!=row['key']:fail.append({'side':side,'case':row['case']})
for p in [src/'business_cipher.c',src/'business_cipher.h',r/'ghidra-scripts/EmulateBusinessCipher.java',r/'analysis/business_software_cipher.py']:
 sources[str(p.relative_to(r))]=hashlib.sha256(p.read_bytes()).hexdigest()
result={'status':'PASS' if not fail else 'FAIL','original_instruction_cases':sum(counts.values()),'per_side':counts,'failures':fail,
 'coverage':'all16 key selectors, lengths8/16, two inputs each combination per side',
 'checked':['C and Python independently match original transform output','16/24 trailing guard bytes unchanged','key memory unchanged'],
 'sources':sources,'limits':['pure transform entrypoints only; not key-install wrapper or framing','software emulation, no RF or authentication verification','no CPU-userop overrides in these cipher runs']}
(r/'analysis/business-cipher-original-comparison.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result,indent=2));assert not fail
