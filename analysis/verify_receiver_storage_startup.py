from pathlib import Path
import ctypes as C,json,subprocess,hashlib,gzip,base64,collections
R=Path(__file__).resolve().parent.parent;P=R/'recovered-code/portable';A=R/'analysis';U=C.c_uint8;W=C.c_uint32;Q=C.c_uint64;Ptr=C.POINTER(U)
files=sorted(P.glob('*.c'));lib=A/'libreceiver_storage_startup.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True);f=C.CDLL(str(lib))
Read=C.CFUNCTYPE(C.c_int32,C.c_void_p,W,W,Ptr,W);Write=C.CFUNCTYPE(C.c_int32,C.c_void_p,W,W,Ptr,W);Lock=C.CFUNCTYPE(C.c_int32,C.c_void_p,W,Q);Unlock=C.CFUNCTYPE(C.c_int32,C.c_void_p,W)
class IO(C.Structure):_fields_=[('read',Read),('write',Write),('lock',Lock),('unlock',Unlock),('user',C.c_void_p),('block_size',W),('erase_value',U)]
f.rr_receiver_storage_initialize.argtypes=[Ptr,Ptr,C.POINTER(IO)];f.rr_receiver_storage_mount_partitions.argtypes=[Ptr,Ptr,C.POINTER(IO)];f.rr_receiver_storage_page_info.argtypes=[Ptr,W,W,W,Ptr];f.rr_receiver_storage_device_ready.argtypes=[W,Ptr];f.rr_receiver_storage_mapped_read.argtypes=[C.c_void_p,W,W,Ptr,W];f.rr_receiver_storage_mapped_write.argtypes=[Ptr,W,Ptr,W]
un=lambda s:gzip.decompress(base64.b64decode(s));arr=lambda b:(U*len(b)).from_buffer_copy(b)
rows=[json.loads(s) for s in (A/'receiver-storage-startup-original.jsonl').read_text().splitlines()];assert len(rows)==1536 and [t['case'] for t in rows]==list(range(1536))
image=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();imagebuf=arr(image);failures=[];counts=collections.Counter();returns=collections.Counter()
for t in rows:
 m=arr(un(t['ram_before']));mapped=bytearray([255])*0x200000;mapped[0x54000:0x54000+len(image)]=image;storage=un(t['storage_before']);mapped[t['base']:t['base']+len(storage)]=storage;flash=arr(mapped);err=[];locks=[]
 def sync(entry,args):
  at=len(locks);locks.append(entry);counts['mutex_calls']+=1
  if at>=len(t['trace']):err.append({'extra_mutex':entry});return -5
  e=t['trace'][at];expected=e['args'];project=[expected[0],expected[2]|expected[3]<<32] if entry==0xe06cdac else [expected[0]]
  if e['entry']!=entry or args!=project:err.append({'mutex':[entry,args],'want':[e['entry'],project]})
  if e['state_flip']:m[0x1a1a]=1;counts['external_device_state_changes']+=1
  return C.c_int32(e['return']).value
 @Read
 def read(user,device,address,dest,n):counts['mapped_reads']+=1;return f.rr_receiver_storage_mapped_read(flash,device,address,dest,n)
 @Write
 def write(user,device,address,data,n):counts['mapped_writes']+=1;return f.rr_receiver_storage_mapped_write(flash,address,data,n)
 @Lock
 def lock(user,address,timeout):return sync(0xe06cdac,[address,timeout])
 @Unlock
 def unlock(user,address):return sync(0xe06cea8,[address])
 io=IO(read,write,lock,unlock,None,16,255);ptr=lambda off:C.cast(C.byref(m,off),Ptr)
 if t['op']==0:
  fn=f.rr_receiver_storage_initialize if t['entry']==0x23025848 else f.rr_receiver_storage_mount_partitions
  result=fn(m,imagebuf,C.byref(io))
 elif t['op']==1:result=f.rr_receiver_storage_page_info(ptr(0x9400),t['entries'],t['offset'],t['index'],ptr(0x9300))
 else:result=f.rr_receiver_storage_device_ready(t['device'],ptr(0x1a1a))
 if result&0xffffffff!=t['return']:err.append({'return':result&0xffffffff,'want':t['return']})
 if len(locks)!=len(t['trace']):err.append({'mutex_calls':len(locks),'want':len(t['trace'])})
 expected=un(t['ram_after'])
 if bytes(m)!=expected:
  ds=[j for j in range(len(expected)) if m[j]!=expected[j]];err.append({'ram_diffs':len(ds),'first':[(hex(j),m[j],expected[j]) for j in ds[:12]]})
 if bytes(flash)[t['base']:t['base']+len(storage)]!=un(t['storage_after']):err.append({'storage_different':True})
 if hashlib.sha256(bytes(flash)).hexdigest()!=t['mapped_after_sha256']:err.append({'full2MiB_different':True})
 if err:failures.append({'case':t['case'],'errors':err})
 returns[hex(t['return'])]+=1
paths=files+[P/'receiver_storage_startup.h',Path(__file__),R/'ghidra-scripts/EmulateReceiverStorageStartup.java',A/'receiver-storage-startup-original.jsonl']
report={'status':'PASS' if not failures else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'C_callback_counts':dict(counts),'return_histogram':dict(returns),'failures':failures,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths}, 'limits':['512 startup entries execute real readiness, layout query, mount and mapped drivers; only mutex results and declared device-state changes are external','512 standalone page queries use explicit layout-getter tables;512 readiness cases use exact descriptor pointer or NULL','Startup is bound to official1.20 device0E06F6CC/stateRAM1A1A/layout0E07039C and16/FF parameters','RAM128KiB and mapped2MiB hashes verified; temporary stack excluded','Device driver initialization before startup, CPU/IRQ scheduling, physical flash and RF remain incomplete']}
report['branch_hits']=dict(sum((collections.Counter(t['hits']) for t in rows),collections.Counter()))

(A/'receiver-storage-startup-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']},indent=2));print(json.dumps(failures[:8],indent=2));assert not failures
