from pathlib import Path
import json,hashlib,ctypes as C,subprocess,base64,gzip,collections
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
files=sorted(P.glob('*.c'));lib=A/'libreceiver_usb_reports.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True);f=C.CDLL(str(lib))
class Call(C.Structure):_fields_=[('entry',W),('device',W),('length',W),('buffer',W)]
Hook=C.CFUNCTYPE(C.c_int32,C.c_void_p,Ptr,C.POINTER(Call));f.rr_receiver_usb_reports.argtypes=[Ptr,Ptr,W,Hook,C.c_void_p,C.POINTER(Call)]
def un(z):return gzip.decompress(base64.b64decode(z))
rows=[json.loads(l) for l in (A/'receiver-usb-reports-original.jsonl').open()];assert len(rows)==2048 and [t['case'] for t in rows]==list(range(2048));fails=[];ends=collections.Counter();coverage=collections.Counter()
for t in rows:
 bm=un(t['ram_before']);ba=un(t['aux_before']);assert len(bm)==131072 and len(ba)==4096;m=(U*len(bm)).from_buffer_copy(bm);aux=(U*len(ba)).from_buffer_copy(ba);pending=Call();calls=[]
 def record(c):return {k:getattr(c,k) for k in ['entry','device','length','buffer']}|{'payload':bytes(m[c.buffer-0x23000000:c.buffer-0x23000000+c.length]).hex()}
 @Hook
 def driver(_,mem,ptr):
  c=ptr.contents;ch={0xe06f6a4:0,0xe06f690:1,0xe06f67c:2}[c.device];v=t['v'];mode=t['mode'];result=-13 if mode==2 else -12 if mode==3 and (v+ch)%2 else 0
  calls.append(record(c)|{'external_result':result});coverage[f'external_ch{ch}_result{result}']+=1
  if mode==3:
   mem[0x6834+ch]=[3,255,7,0][v%4];mem[0x6904]=[0,1,255][v%3]
   for i,b in enumerate((0xfffffffe).to_bytes(4,'little')):mem[0x6830+i]=b
  return result
 rc=f.rr_receiver_usb_reports(m,aux,t['entry'],driver if t['mode'] else Hook(),None,C.byref(pending))
 if t['boundary']:calls.append(record(pending)|{'external_result':None})
 errors=[]
 for n,b,z in [('ram',bytes(m),'ram_after'),('aux',bytes(aux),'aux_after')]:
  expected=un(t[z]);assert len(b)==len(expected)
  if b!=expected:
   diffs=[i for i in range(len(b)) if b[i]!=expected[i]];errors.append({'window':n,'count':len(diffs),'first':[(hex(i),b[i],expected[i]) for i in diffs[:10]]})
 if rc!=bool(t['boundary']):errors.append({'rc':rc,'boundary':t['boundary']})
 if pending.entry!=t['boundary']:errors.append({'pending':pending.entry,'boundary':t['boundary']})
 if calls!=t['calls']:errors.append({'calls':calls,'expected':t['calls']})
 if errors:fails.append({'case':t['case'],'errors':errors})
 ends['original_driver_entry' if t['boundary'] else 'returned_with_external_driver' if t['calls'] else 'returned_without_driver']+=1
 coverage[f'entry_{t["entry"]:08x}']+=1
paths=files+list(P.glob('*.h'))+[Path(__file__),R/'ghidra-scripts/EmulateReceiverUsbReports.java',A/'receiver-usb-reports-original.jsonl']
d={'status':'PASS' if not fails else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'endings':dict(ends),'coverage':dict(coverage),'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'libraries':{str(lib.relative_to(R)):hashlib.sha256(lib.read_bytes()).hexdigest()},'limits':['Two original entries23026948/23026D28; full128KiB RAM and4KiB auxiliaryMMIO compared','NULL driver stops at original0E064288 before execution; other tests explicitly supply return/sideeffects and resume original callback software','ActualUSB driver, physicalUSB transfer, dynamicMMIO, asynchronous concurrency and worker dispatch are not validated']}
(A/'receiver-usb-reports-comparison.json').write_text(json.dumps(d,indent=2)+'\n');print(json.dumps({k:v for k,v in d.items() if k not in ['sources','libraries','failures']},indent=2));print(json.dumps(fails[:8],indent=2));assert not fails
