from pathlib import Path
import ctypes as C,json,subprocess,hashlib,gzip,base64,collections
R=Path(__file__).resolve().parent.parent;P=R/'recovered-code/portable';A=R/'analysis';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
files=sorted(P.glob('*.c'));lib=A/'libreceiver_storage_mapped.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True);f=C.CDLL(str(lib))
Read=C.CFUNCTYPE(C.c_int32,C.c_void_p,W,W,Ptr,W)
f.rr_receiver_storage_read_history.argtypes=[Ptr,W,Ptr,W,W,Ptr,Read,C.c_void_p];f.rr_receiver_storage_read_history.restype=C.c_int32
f.rr_receiver_storage_read.argtypes=[Ptr,W,Ptr,W,Ptr,Read,C.c_void_p];f.rr_receiver_storage_read.restype=C.c_int32
f.rr_receiver_storage_mapped_read.argtypes=[C.c_void_p,W,W,Ptr,W];f.rr_receiver_storage_mapped_read.restype=C.c_int32
f.rr_receiver_storage_mapped_write.argtypes=[Ptr,W,Ptr,W];f.rr_receiver_storage_mapped_write.restype=C.c_int32
f.rr_receiver_storage_mapped_erase.argtypes=[Ptr,W,W];f.rr_receiver_storage_mapped_erase.restype=C.c_int32
un=lambda s:gzip.decompress(base64.b64decode(s));arr=lambda b:(U*len(b)).from_buffer_copy(b)
rows=[json.loads(s) for s in (A/'receiver-storage-mapped-original.jsonl').read_text().splitlines()];assert len(rows)==1792
image=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();failures=[];counts=collections.Counter();returns=collections.Counter();totalreads=0
for t in rows:
 raw=un(t['ram_before']);m=arr(raw);prior=arr(bytes.fromhex(t['prior']));err=[];mapped=bytearray(raw[:256]*8192);mapped[0x54000:0x54000+len(image)]=image;storage=un(t['storage']);mapped[0x1db000:0x1db000+len(storage)]=storage;flash=arr(mapped);calls=[]
 @Read
 def read(user,device,address,dest,n):
  calls.append([device,address,n]);return f.rr_receiver_storage_mapped_read(flash,device,address,dest,n)
 ctx=C.cast(C.byref(m,0x1f30),Ptr);dest=C.cast(C.byref(m,t['destination']-0x23000000),Ptr) if t['destination'] else None;data=C.cast(C.byref(m,0x9000),Ptr)
 if t['op']==0:result=f.rr_receiver_storage_read_history(ctx,t['key'],dest,t['capacity'],t['history'],prior,read,None)
 elif t['op']==1:result=f.rr_receiver_storage_read(ctx,t['key'],dest,t['capacity'],prior,read,None)
 elif t['op']==2:calls.append(None);result=f.rr_receiver_storage_mapped_read(flash,0xe06f6cc,t['offset'],data,t['transfer'])
 elif t['op']==3:result=f.rr_receiver_storage_mapped_write(flash,t['offset'],data,t['transfer'])
 else:result=f.rr_receiver_storage_mapped_erase(flash,t['offset'],t['transfer'])
 if result&0xffffffff!=t['return']:err.append({'return':result&0xffffffff,'expected':t['return']})
 if len(calls)!=t['driver_reads']:err.append({'calls':len(calls),'expected':t['driver_reads']})
 expected=un(t['ram_after'])
 if bytes(m)!=expected:
  ds=[i for i in range(len(expected)) if m[i]!=expected[i]];err.append({'diffs':len(ds),'first':[(hex(i),m[i],expected[i]) for i in ds[:12]]})
 got=hashlib.sha256(bytes(flash)).hexdigest()
 if got!=t['mapped_after_sha256']:err.append({'mapped_sha256':got,'expected':t['mapped_after_sha256']})
 if err:failures.append({'case':t['case'],'op':t['op'],'errors':err})
 counts[str(t['op'])]+=1;returns[str(t['op'])+':'+hex(t['return'])]+=1;totalreads+=len(calls)
paths=files+[P/'receiver_storage_read.h',Path(__file__),R/'ghidra-scripts/EmulateReceiverStorageMapped.java',A/'receiver-storage-mapped-original.jsonl']
report={'status':'PASS' if not failures else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'operations':dict(counts),'native_read_driver_calls':totalreads,'return_histogram':dict(returns),'failures':failures,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['No substituted calls/returns: original read backend and mapped read/write/erase bodies execute to return','RAM byte equality and complete2MiB mapped-region SHA256 compared','Mapped region is an inert constructed software window, not an actual receiver flash dump; physical write/erase behavior and persistence not proved','Contexts are explicitly initialized test fixtures; mount and record-writing state machine remain separate','DMB modeled as inert; no concurrent hardware']}
(A/'receiver-storage-mapped-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures','return_histogram']},indent=2));print(json.dumps(failures[:8],indent=2));assert not failures
