from pathlib import Path
import ctypes as C,subprocess,json,hashlib,struct,zlib,base64
root=Path(__file__).resolve().parent.parent;src=root/'recovered-code/portable';U8=C.c_uint8;U32=C.c_uint32
lib=src/'build/librr_control.dylib';files=[src/(s+'.c') for s in ('business_control','business_tx','business_cipher')]
subprocess.run(['rtk','proxy','clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-fPIC','-shared',*[str(x) for x in files],'-o',str(lib)],check=True,capture_output=True,text=True)
f=C.CDLL(str(lib));B=C.POINTER(U8)
f.rr_control_consume.argtypes=[B,C.c_int,C.c_uint,C.POINTER(U32)];f.rr_control_consume.restype=C.c_int
f.rr_dongle_business_stats.argtypes=[B,C.c_uint,U32];f.rr_mouse_control_interval.argtypes=[B,C.c_uint,U32,C.POINTER(U32)];f.rr_dongle_control_publish.argtypes=[B]
unpack=lambda s:zlib.decompress(base64.b64decode(s))
fail=[];sources={}
for side in ('mouse','dongle'):
 p=root/'analysis'/f'{side}-control-original.jsonl';rows=[json.loads(x) for x in p.read_text().splitlines()];assert len(rows)==448
 sources[str(p.relative_to(root))]=hashlib.sha256(p.read_bytes()).hexdigest()
 for row in rows:
  ram=(U8*65536).from_buffer_copy(unpack(row['ram_before_z']));clock=(U32*2)(*struct.unpack('<2I',bytes.fromhex(row['clock_before'])));nvic=U32(int.from_bytes(bytes.fromhex(row['nvic_before']),'little'))
  if row['op']==0:assert f.rr_control_consume(ram,side=='mouse',row['peer'],C.byref(nvic))==0
  elif row['op']==1:
   if side=='mouse':f.rr_mouse_control_interval(ram,row['peer'],row['arg'],clock)
   else:f.rr_dongle_control_publish(ram)
  else:f.rr_dongle_business_stats(ram,row['peer'],row['arg'])
  expected=unpack(row['ram_after_z']);diff=[{'offset':hex(i),'actual':x,'expected':y} for i,(x,y) in enumerate(zip(bytes(ram),expected)) if x!=y]
  if diff or struct.pack('<2I',*clock).hex()!=row['clock_after'] or nvic.value.to_bytes(4,'little').hex()!=row['nvic_after']:fail.append({'side':side,'case':row['case'],'differences':diff[:30]})
for p in files+[src/'business_control.h',root/'ghidra-scripts/EmulateBusinessControl.java']:sources[str(p.relative_to(root))]=hashlib.sha256(p.read_bytes()).hexdigest()
report={'status':'FAIL' if fail else 'PASS','original_instruction_cases':896,'failures':fail,'sources':sources,'limits':['class0 SWI handlers only; adaptive error reporter remains outstanding','inert NVIC and clock task words, no actual interrupts/clocks','stats uses instruction-proven4-byte stride, correcting decompiler expression']}
(root/'analysis/business-control-original-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k!='sources'},indent=2));assert not fail
