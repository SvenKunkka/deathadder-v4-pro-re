from pathlib import Path
import ctypes as C,subprocess,json,hashlib
root=Path(__file__).resolve().parent.parent;src=root/'recovered-code/portable';U8=C.c_uint8;U32=C.c_uint32
lib=src/'build/librr_keys.dylib'
subprocess.run(['rtk','proxy','clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-fPIC','-shared',str(src/'business_keys.c'),str(src/'business_cipher.c'),'-o',str(lib)],check=True,capture_output=True,text=True)
f=C.CDLL(str(lib));f.rr_business_install_key.argtypes=[C.POINTER(U8),C.c_int,U32,C.POINTER(U8)]
f.rr_business_cipher_wrapper.argtypes=[C.POINTER(U8),U8,C.POINTER(U8),C.c_int];f.rr_business_cipher_wrapper.restype=C.c_int
fail=[];sources={};counts={}
for side,suit,offset,keybase in [('mouse','Suit2',0x2c904,0x2600),('dongle','Suit1',0x1ba74,0x3020)]:
 image=(root/'firmware-extracted-1.20'/f'{suit}FWData__radio_radio.bin').read_bytes();table=image[offset:offset+256]
 assert hashlib.sha256(table).hexdigest()=='d33f232d47337cb1d80b47ef7c78787df4e8fc49f532155fbd35e06df70841f7'
 p=root/'analysis'/f'{side}-keys-original.jsonl';rows=[json.loads(x) for x in p.read_text().splitlines()];assert len(rows)==528
 counts[side]=len(rows);sources[str(p.relative_to(root))]=hashlib.sha256(p.read_bytes()).hexdigest()
 for row in rows:
  ram=(U8*65536)();ram[keybase-16:keybase+48]=bytes.fromhex(row['key_region_before'])
  f.rr_business_install_key(ram,side=='mouse',row['identity'],(U8*256).from_buffer_copy(table))
  installed=bytes(ram[keybase-16:keybase+48]).hex()
  data=(U8*64).from_buffer_copy(bytes.fromhex(row['input']))
  ret=f.rr_business_cipher_wrapper(data,row['length'],ram,side=='mouse')
  if (installed!=row['key_region_installed'] or bytes(ram[keybase-16:keybase+48]).hex()!=row['key_region_after'] or
      bytes(data).hex()!=row['output'] or ret!=row['return'] or row['length_before']!=row['length_after']):
   fail.append({'side':side,'case':row['case'],'length':row['length'],'C_output':bytes(data).hex(),'expected':row['output']})
for p in [src/'business_keys.c',src/'business_keys.h',src/'business_cipher.c',src/'business_cipher.h',root/'ghidra-scripts/EmulateBusinessKeys.java']:
 sources[str(p.relative_to(root))]=hashlib.sha256(p.read_bytes()).hexdigest()
report={'status':'FAIL' if fail else 'PASS','original_instruction_cases':sum(counts.values()),'per_side':counts,'failures':fail,'sources':sources,
 'coverage':['each16 key selectors x every length0..32 on both sides','random upper28 bits in key identity argument','actual installer then wrapper/transform/memcpy in same emulator memory','64-byte key area guards and64-byte data guards plus length object unchanged'],
 'limits':['host simulation; wrapper domain0..32 only','connection initialization caller and scheduler timing not executed','not identity authentication or RF proof']}
(root/'analysis/business-keys-original-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k!='sources'},indent=2));assert not fail
