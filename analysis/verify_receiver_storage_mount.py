from pathlib import Path
import ctypes as C,json,subprocess,hashlib,gzip,base64,collections
R=Path(__file__).resolve().parent.parent;P=R/'recovered-code/portable';A=R/'analysis';U=C.c_uint8;W=C.c_uint32;Q=C.c_uint64;Ptr=C.POINTER(U)
files=sorted(P.glob('*.c'));lib=A/'libreceiver_storage_mount.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True);f=C.CDLL(str(lib))
Read=C.CFUNCTYPE(C.c_int32,C.c_void_p,W,W,Ptr,W);Write=C.CFUNCTYPE(C.c_int32,C.c_void_p,W,W,Ptr,W);Lock=C.CFUNCTYPE(C.c_int32,C.c_void_p,W,Q);Unlock=C.CFUNCTYPE(C.c_int32,C.c_void_p,W)
class IO(C.Structure):_fields_=[('read',Read),('write',Write),('lock',Lock),('unlock',Unlock),('user',C.c_void_p),('block_size',W),('erase_value',U)]
f.rr_receiver_storage_mount.argtypes=[Ptr,W,W,C.POINTER(IO)];f.rr_receiver_storage_mapped_read.argtypes=[C.c_void_p,W,W,Ptr,W];f.rr_receiver_storage_mapped_write.argtypes=[Ptr,W,Ptr,W]
un=lambda s:gzip.decompress(base64.b64decode(s));arr=lambda b:(U*len(b)).from_buffer_copy(b)
rows=[json.loads(s) for s in (A/'receiver-storage-mount-original.jsonl').read_text().splitlines()];assert len(rows)==1088 and [t['case'] for t in rows]==list(range(1088))
image=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();failures=[];counts=collections.Counter();returns=collections.Counter()
for t in rows:
 m=arr(un(t['ram_before']));mapped=bytearray([255])*0x200000;mapped[0x54000:0x54000+len(image)]=image;storage=un(t['storage_before']);mapped[t['base']:t['base']+len(storage)]=storage;flash=arr(mapped);err=[];calls=[]
 def call(entry,args,payload=None):
  at=len(calls);calls.append(entry);counts[hex(entry)]+=1
  if at>=len(t['trace']):err.append({'extra_call':entry});return -5
  tr=t['trace'][at];expected=tr['args']
  if entry==0xe06cdac:project=[expected[0],expected[2]|expected[3]<<32]
  elif entry==0xe06cea8:project=[expected[0]]
  else:project=[expected[0],expected[1],expected[3]]
  if tr['entry']!=entry or args!=project:err.append({'call':[entry,args],'want':[tr['entry'],project]})
  if payload is not None and payload.hex()!=tr['payload']:err.append({'write_payload':payload.hex(),'want':tr['payload']})
  return C.c_int32(tr['return']).value
 @Read
 def read(user,device,address,dest,n):
  result=call(0xe067488,[device,address,n])
  if t['mode']=='mapped':
   got=f.rr_receiver_storage_mapped_read(flash,device,address,dest,n)
   if got!=result:err.append({'read_result':got,'want':result})
   return got
  if result==0:C.memmove(dest,C.byref(flash,address),n)
  return result
 @Write
 def write(user,device,address,data,n):
  result=call(0xe0674b4,[device,address,n],C.string_at(data,n))
  if t['mode']=='mapped':
   got=f.rr_receiver_storage_mapped_write(flash,address,data,n)
   if got!=result:err.append({'write_result':got,'want':result})
   return got
  if address<len(flash) and n<=len(flash)-address:C.memmove(C.byref(flash,address),data,n)
  return result
 @Lock
 def lock(user,address,timeout):return call(0xe06cdac,[address,timeout])
 @Unlock
 def unlock(user,address):return call(0xe06cea8,[address])
 io=IO(read,write,lock,unlock,None,t['block'],255);ctx=C.cast(C.byref(m,t['ctx']),Ptr)
 result=f.rr_receiver_storage_mount(ctx,0x23000000+t['ctx'],t['params'],C.byref(io))
 if result&0xffffffff!=t['return']:err.append({'return':result&0xffffffff,'want':t['return']})
 if len(calls)!=len(t['trace']):err.append({'calls':len(calls),'want':len(t['trace'])})
 expected=un(t['ram_after'])
 if bytes(m)!=expected:
  ds=[j for j in range(len(expected)) if m[j]!=expected[j]];err.append({'ram_diffs':len(ds),'first':[(hex(j),m[j],expected[j]) for j in ds[:12]]})
 if bytes(flash)[t['base']:t['base']+len(storage)]!=un(t['storage_after']):err.append({'storage_different':True})
 if hashlib.sha256(bytes(flash)).hexdigest()!=t['mapped_after_sha256']:err.append({'full2MiB_different':True})
 if err:failures.append({'case':t['case'],'errors':err})
 returns[hex(t['return'])]+=1
paths=files+[P/'receiver_storage_mount.h',Path(__file__),R/'ghidra-scripts/EmulateReceiverStorageMount.java',A/'receiver-storage-mount-original.jsonl']
report={'status':'PASS' if not failures else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'C_callback_counts':dict(counts),'return_histogram':dict(returns),'failures':failures,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths}, 'limits':['512 cases execute original parameter getter and mapped I/O; remaining576 supply explicit getter and read/write results','Real mutex initialization body executes; lock/unlock return values external and ignored by mount','Callbacks do not mutate context; negative read errors only, full buffer on read0; supported successful block sizes1/2/4/8/16/32','Full128KiB RAM and2MiB mapped snapshot compared; temporary stack excluded','No physical persistence, actual scheduling or RF']}
report['branch_hits']=dict(sum((collections.Counter(t['hits']) for t in rows),collections.Counter()))

(A/'receiver-storage-mount-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']},indent=2));print(json.dumps(failures[:8],indent=2));assert not failures
