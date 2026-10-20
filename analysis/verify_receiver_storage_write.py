from pathlib import Path
import ctypes as C,json,subprocess,hashlib,gzip,base64,collections
R=Path(__file__).resolve().parent.parent;P=R/'recovered-code/portable';A=R/'analysis';U=C.c_uint8;W=C.c_uint32;Q=C.c_uint64;Ptr=C.POINTER(U)
files=sorted(P.glob('*.c'));lib=A/'libreceiver_storage_write.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True);f=C.CDLL(str(lib))
Read=C.CFUNCTYPE(C.c_int32,C.c_void_p,W,W,Ptr,W);Write=C.CFUNCTYPE(C.c_int32,C.c_void_p,W,W,Ptr,W);Lock=C.CFUNCTYPE(C.c_int32,C.c_void_p,W,Q);Unlock=C.CFUNCTYPE(C.c_int32,C.c_void_p,W)
class IO(C.Structure):_fields_=[('read',Read),('write',Write),('lock',Lock),('unlock',Unlock),('user',C.c_void_p),('block_size',W),('erase_value',U)]
f.rr_receiver_storage_write_bytes.argtypes=[Ptr,Q,Ptr,W,C.POINTER(IO)];f.rr_receiver_storage_append_data.argtypes=[Ptr,Ptr,W,C.POINTER(IO)];f.rr_receiver_storage_append_record.argtypes=[Ptr,Ptr,C.POINTER(IO)];f.rr_receiver_storage_initialize_page.argtypes=[Ptr,W,C.POINTER(IO)];f.rr_receiver_storage_rotate.argtypes=[Ptr,C.POINTER(IO)];f.rr_receiver_storage_collect.argtypes=[Ptr,C.POINTER(IO)];f.rr_receiver_storage_write.argtypes=[Ptr,W,W,Ptr,W,C.POINTER(IO)]
un=lambda s:gzip.decompress(base64.b64decode(s));arr=lambda b:(U*len(b)).from_buffer_copy(b)
rows=[json.loads(s) for s in (A/'receiver-storage-write-original.jsonl').read_text().splitlines()];assert len(rows)==4096 and [t['case'] for t in rows]==list(range(4096))
failures=[];counts=collections.Counter();events=collections.Counter();results=collections.Counter()
for t in rows:
 m=arr(un(t['ram_before']));storage=bytearray(un(t['storage_before']));err=[];seen=[]
 def event(entry,args):
  at=len(seen);seen.append(entry);events[hex(entry)]+=1
  if at>=len(t['trace']):err.append({'extra_event':hex(entry)});return None
  e=t['trace'][at];expected=e['args'];project=[expected[0],expected[1],expected[3]] if entry in (0xe067488,0xe0674b4) else [expected[0],expected[2]|expected[3]<<32] if entry==0xe06cdac else [expected[0]]
  if e['entry']!=entry or args!=project:err.append({'event':at,'got':[hex(entry),args],'want':[hex(e['entry']),project]})
  return e
 @Read
 def read(user,device,address,dest,n):
  e=event(0xe067488,[device,address,n])
  if e is None:return -5
  data=bytes.fromhex(e['data']);off=address-t['base']
  if data:
   if data!=storage[off:off+n]:err.append({'read_storage':off,'length':n})
   if len(data)>n:err.append({'oversize_read':len(data),'n':n});return -5
   C.memmove(dest,data,len(data))
  return C.c_int32(e['return']).value
 @Write
 def write(user,device,address,data,n):
  e=event(0xe0674b4,[device,address,n])
  if e is None:return -5
  expected=bytes.fromhex(e['data']);off=address-t['base']
  if expected:
   got=C.string_at(data,n)
   if got!=expected:err.append({'write_payload':off,'got':got.hex(),'want':expected.hex()})
   if e['commit']:storage[off:off+n]=got
  return C.c_int32(e['return']).value
 @Lock
 def lock(user,address,timeout):
  e=event(0xe06cdac,[address,timeout]);return -5 if e is None else C.c_int32(e['return']).value
 @Unlock
 def unlock(user,address):
  e=event(0xe06cea8,[address]);return -5 if e is None else C.c_int32(e['return']).value
 io=IO(read,write,lock,unlock,None,t['block'],t['erase']);ctx=C.cast(C.byref(m,t['ctx']),Ptr);src=C.cast(C.byref(m,t['src']-0x23000000),Ptr) if t['src'] else None
 op=t['op']
 if op==0:result=f.rr_receiver_storage_write_bytes(ctx,t['position'],src,t['len'],C.byref(io))
 elif op==1:result=f.rr_receiver_storage_append_data(ctx,src,t['len'],C.byref(io))
 elif op==2:result=f.rr_receiver_storage_append_record(ctx,src,C.byref(io))
 elif op==3:result=f.rr_receiver_storage_initialize_page(ctx,t['page'],C.byref(io))
 elif op==4:result=f.rr_receiver_storage_rotate(ctx,C.byref(io))
 elif op==5:result=f.rr_receiver_storage_collect(ctx,C.byref(io))
 elif op==7 and t['index']>1:result=0
 else:
  result=f.rr_receiver_storage_write(ctx,0x23000000+t['ctx'],t['key'],src,t['len'],C.byref(io))
  if op==7:result=int(result==0 or result==t['len'])
 if result&0xffffffff!=t['return']:err.append({'return':result&0xffffffff,'want':t['return']})
 if len(seen)!=len(t['trace']):err.append({'events':len(seen),'want':len(t['trace'])})
 expected=un(t['ram_after'])
 if bytes(m)!=expected:
  ds=[j for j in range(len(expected)) if m[j]!=expected[j]];err.append({'ram_diffs':len(ds),'first':[(hex(j),m[j],expected[j]) for j in ds[:12]]})
 if bytes(storage)!=un(t['storage_after']):err.append({'storage_different':True})
 if err:failures.append({'case':t['case'],'op':op,'errors':err})
 counts[str(op)]+=1;results[str(op)+':'+hex(t['return'])]+=1
paths=files+[P/'receiver_storage_write.h',Path(__file__),R/'ghidra-scripts/EmulateReceiverStorageWrite.java',A/'receiver-storage-write-original.jsonl']
report={'status':'PASS' if not failures else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'operations':dict(counts),'external_calls':dict(events),'return_histogram':dict(results),'failures':failures,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['Read/write drivers and mutex calls are explicit external events with provided effects/results; no invented mutex implementation','Mounted finite page graph and block sizes1/2/4/8/16/32; actual selected device params16/FF separately bound to firmware bytes','RAM, storage region, callback sequence and write payload compared; temporary CPU stack not reconstructed','No mount discovery, real flash persistence, hardware concurrency or RF verification']}
(A/'receiver-storage-write-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures','return_histogram']},indent=2));print(json.dumps(failures[:8],indent=2));assert not failures
