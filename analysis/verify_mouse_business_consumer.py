"""Compare complete consumer entrypoint against original instructions; inert RAM/MMIO."""
from pathlib import Path
import ctypes as C,json,hashlib,subprocess,sys,gzip,base64
from collections import Counter
root=Path(__file__).resolve().parent.parent;a=root/'analysis';src=root/'recovered-code'/'portable'
lib=a/('libmouse_business_consumer.dylib' if sys.platform=='darwin' else 'libmouse_business_consumer.so')
files=[src/'mouse_business_consumer.c',src/'business_tx.c',src/'business_cipher.c']
subprocess.run(['rtk','proxy','clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-fPIC','-shared',*[str(p) for p in files],'-o',str(lib)],check=True,capture_output=True,text=True)
f=C.CDLL(str(lib));fn=f.rr_mouse_business_consumer;U8=C.c_uint8;fn.argtypes=[C.POINTER(U8)]*3;fn.restype=C.c_int
p=a/'mouse-business-consumer-original.jsonl';fails=[];count=0;cover=Counter()
for line in p.read_text().splitlines():
 row=json.loads(line);count+=1;b=gzip.decompress(base64.b64decode(row['before_gzip']));expected=gzip.decompress(base64.b64decode(row['after_gzip']))
 m=(U8*65536).from_buffer_copy(b);sp=(U8*16).from_buffer_copy(bytes.fromhex(row['spim_before']));dp=(U8*72).from_buffer_copy(bytes.fromhex(row['dppi_before']))
 ret=fn(m,sp,dp);diff={}
 for name,actual,want,addr in [('ram',bytes(m),expected,0x23000000),('spim',bytes(sp),bytes.fromhex(row['spim_after']),0x5f9c2000),('dppi',bytes(dp),bytes.fromhex(row['dppi_after']),0x5302e000)]:
  ds=[{'a':hex(addr+i),'actual':v,'expected':w} for i,(v,w) in enumerate(zip(actual,want)) if v!=w]
  if ds:diff[name]=ds[:20]
 if diff or ret:fails.append({'case':row['case'],'kind':row['kind'],'ret':ret,'diff':diff})
 cover[f'kind_{row["kind"]}']+=1
assert count==512
# Invalid-memory/nonreturning/RTOS boundaries are interface statuses, not firmware returns.
for cmd,n,code in [(0x5a,0,-5),(0x5a,2,-5),(0xb1,0,-4),(0xa3,0,-2),(0xb1,0,-3)]:
 m=(U8*65536)();sp=(U8*16)();dp=(U8*72)();m[0x779b]=5 if cmd==0x5a else 3;m[0x779c]=n;m[0x67d0]=cmd
 if n==2:m[0x67d1]=0xa6
 if code==-2:m[0x7748]=1
 if code==-3:m[0x76e0]=1;m[0x774b]=1;m[0x771f]=1
 before=(bytes(m),bytes(sp),bytes(dp));assert fn(m,sp,dp)==code and before==(bytes(m),bytes(sp),bytes(dp))
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
result={'status':'PASS' if not fails else 'FAIL','original_cases':count,'coverage':dict(cover),'failures':fails,'boundary_tests':5,
 'comparison':['all65536 RAM bytes','SPIM inert16B','DPPI inert72B','actual TX fragmentation/ring helpers and memory copy executed'],
 'source_sha256':sha(p),'code_sha256':{str(p.relative_to(root)):sha(p) for p in files+[src/'mouse_business_consumer.h',root/'ghidra-scripts'/'EmulateMouseBusinessConsumer.java']},
 'limits':['A3 timer-start branch not implemented','B1 reboot path not returned/modelled','B1 active sensor reinit gated off','class5 n0/n2 huge copy rejected by host preflight','PRIMASK/real peripheral timing not modeled']}
(a/'mouse-business-consumer-comparison.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result,indent=2));assert not fails
