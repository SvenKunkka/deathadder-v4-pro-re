from pathlib import Path
import ctypes as C,json,subprocess,hashlib,gzip,base64,collections
R=Path(__file__).resolve().parent.parent;P=R/'recovered-code/portable';A=R/'analysis';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
files=sorted(P.glob('*.c'));lib=A/'libreceiver_storage_read.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True);f=C.CDLL(str(lib))
Read=C.CFUNCTYPE(C.c_int32,C.c_void_p,W,W,Ptr,W)
f.rr_receiver_storage_read_history.argtypes=[Ptr,W,Ptr,W,W,Ptr,Read,C.c_void_p];f.rr_receiver_storage_read_history.restype=C.c_int32
f.rr_receiver_storage_read.argtypes=[Ptr,W,Ptr,W,Ptr,Read,C.c_void_p];f.rr_receiver_storage_read.restype=C.c_int32
f.rr_receiver_storage_crc8.argtypes=[Ptr,C.c_size_t,U];f.rr_receiver_storage_crc8.restype=U
un=lambda s:gzip.decompress(base64.b64decode(s));arr=lambda b:(U*len(b)).from_buffer_copy(b)
rows=[json.loads(s) for s in (A/'receiver-storage-read-original.jsonl').read_text().splitlines()];assert len(rows)==4096
failures=[];counts=collections.Counter();returns=collections.Counter();calls=0;maximum=0
for t in rows:
 m=arr(un(t['ram_before']));prior=arr(bytes.fromhex(t['prior']));err=[];seen=[]
 @Read
 def read(user,device,address,dest,n):
  i=len(seen);seen.append((device,address,n))
  if i>=len(t['trace']):err.append({'extra_call':[i,device,address,n]});return -5
  e=t['trace'][i]
  if [device,address,n]!=[e['device'],e['address'],e['length']]:err.append({'driver_args':[device,address,n],'expected':[e['device'],e['address'],e['length']]})
  data=bytes.fromhex(e['data'])
  # Never overwrite beyond the requested C buffer if an incorrect trace diverges.
  if len(data)>n:err.append({'oversize':len(data),'n':n});return -5
  if data:C.memmove(dest,data,len(data))
  return C.c_int32(e['return']).value
 ctx=C.cast(C.byref(m,0x1f30),Ptr);dest=C.cast(C.byref(m,t['destination']-0x23000000),Ptr) if t['destination'] else None
 if t['op']==0:result=f.rr_receiver_storage_read_history(ctx,t['key'],dest,t['capacity'],t['history'],prior,read,None)
 elif t['op']==1:result=f.rr_receiver_storage_read(ctx,t['key'],dest,t['capacity'],prior,read,None)
 else:result=f.rr_receiver_storage_crc8(C.cast(C.byref(m,0x9000),Ptr),t['length'],t['seed'])
 if result&0xffffffff!=t['return']:err.append({'return':result&0xffffffff,'expected':t['return']})
 if len(seen)!=len(t['trace']):err.append({'calls':len(seen),'expected':len(t['trace'])})
 expected=un(t['ram_after'])
 if bytes(m)!=expected:
  ds=[i for i in range(len(expected)) if m[i]!=expected[i]];err.append({'diffs':len(ds),'first':[(hex(i),m[i],expected[i]) for i in ds[:12]]})
 if err:failures.append({'case':t['case'],'op':t['op'],'errors':err})
 counts[str(t['op'])]+=1;returns[hex(t['return'])]+=1;calls+=len(seen);maximum=max(maximum,len(seen))
paths=files+[P/'receiver_storage_read.h',Path(__file__),R/'ghidra-scripts/EmulateReceiverStorageRead.java',A/'receiver-storage-read-original.jsonl']
report={'status':'PASS' if not failures else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'operations':dict(counts),'original_read_driver_calls':calls,'max_calls_one_case':maximum,'return_histogram':dict(returns),'failures':failures,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['Original code runs through record search, page iteration, CRC8 and data-copy; real flash driver0E067488 remains external','Driver request device/address/length, return and exact data effects compared; transient ABI stack destination pointers are not reconstructed','Full128KiB RAM compared; temporary emulated CPU stack excluded','Prior16-byte caller record is explicit for unexpected positive driver returns; no invented zero-fill','Constructed mounted contexts and storage pages, not receiver flash dumps; mount/write/erase not recovered here']}
(A/'receiver-storage-read-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']},indent=2));print(json.dumps(failures[:8],indent=2));assert not failures
