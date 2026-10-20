from pathlib import Path
import ctypes as C,json,subprocess,hashlib,gzip,base64,collections
R=Path(__file__).resolve().parent.parent;P=R/'recovered-code/portable';A=R/'analysis';U=C.c_uint8;W=C.c_uint32;Q=C.c_uint64;Ptr=C.POINTER(U)
files=sorted(P.glob('*.c'));lib=A/'libreceiver_storage_scan.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True);f=C.CDLL(str(lib))
Read=C.CFUNCTYPE(C.c_int32,C.c_void_p,W,W,Ptr,W)
f.rr_receiver_storage_scan.argtypes=[Ptr,Ptr,Ptr,W,Read,C.c_void_p];f.rr_receiver_storage_mapped_read.argtypes=[C.c_void_p,W,W,Ptr,W]
un=lambda s:gzip.decompress(base64.b64decode(s));arr=lambda b:(U*len(b)).from_buffer_copy(b)
rows=[json.loads(s) for s in (A/'receiver-storage-scan-original.jsonl').read_text().splitlines()];assert len(rows)==1024 and [t['case'] for t in rows]==list(range(1024))
image=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();failures=[];counts=collections.Counter();returns=collections.Counter()
for t in rows:
 m=arr(un(t['ram_before']));mapped=bytearray([255])*0x200000;mapped[0x54000:0x54000+len(image)]=image;storage=un(t['storage_before']);mapped[t['base']:t['base']+len(storage)]=storage;flash=arr(mapped);err=[];calls=[]
 @Read
 def read(user,device,address,dest,n):
  at=len(calls);calls.append(address);counts[t['mode']+'_read_calls']+=1
  if at>=len(t['trace']):err.append({'extra_read':[device,address,n]});return -5
  tr=t['trace'][at];actual=[device,address,n];wanted=[tr['args'][0],tr['args'][1],tr['args'][3]]
  if actual!=wanted:err.append({'read_args':actual,'want':wanted})
  if t['mode']=='mapped':
   result=f.rr_receiver_storage_mapped_read(flash,device,address,dest,n)
   if result&0xffffffff!=tr['return']:err.append({'read_return':result,'want':tr['return']})
   return result
  result=C.c_int32(tr['return']).value
  if result==0:C.memmove(dest,C.byref(flash,address),n)
  return result
 ptr=lambda off:C.cast(C.byref(m,off),Ptr)
 result=f.rr_receiver_storage_scan(ptr(t['ctx']),ptr(0x9300),ptr(0x9308),t['block'],read,None)
 if result&0xffffffff!=t['return']:err.append({'return':result&0xffffffff,'want':t['return']})
 if len(calls)!=len(t['trace']):err.append({'reads':len(calls),'want':len(t['trace'])})
 expected=un(t['ram_after'])
 if bytes(m)!=expected:
  ds=[j for j in range(len(expected)) if m[j]!=expected[j]];err.append({'ram_diffs':len(ds),'first':[(hex(j),m[j],expected[j]) for j in ds[:12]]})
 if hashlib.sha256(bytes(flash)).hexdigest()!=t['mapped_after_sha256']:err.append({'full2MiB_different':True})
 if err:failures.append({'case':t['case'],'errors':err})
 returns[hex(t['return'])]+=1
paths=files+[P/'receiver_storage_scan.h',Path(__file__),R/'ghidra-scripts/EmulateReceiverStorageScan.java',A/'receiver-storage-scan-original.jsonl']
report={'status':'PASS' if not failures else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'C_callback_counts':dict(counts),'return_histogram':dict(returns),'failures':failures,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths}, 'limits':['512 cases execute mapped read driver body; 512 expose exact read callback result including negative and positive faults','Full 128KiB RAM and 2MiB mapped snapshot checked; temporary stack excluded','Distinct position buffers; callback does not mutate context or parameter table; finite traversals only','This is E018 selected-page cursor scan, not full E6D4 mount, mutex, physical flash or RF']}

(A/'receiver-storage-scan-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']},indent=2));print(json.dumps(failures[:8],indent=2));assert not failures
