from pathlib import Path
import json,hashlib,ctypes as C,subprocess,base64,gzip,collections
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
files=sorted(P.glob('*.c'));lib=A/'libreceiver_vendor_commands.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True);f=C.CDLL(str(lib))
class Pending(C.Structure):_fields_=[('entry',W),('arg0',W),('arg0_valid',W)]
f.rr_receiver_vendor_commands.argtypes=[Ptr,Ptr,Ptr,Ptr,Ptr,W,W,C.POINTER(Pending)]
image=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();flash=(U*len(image)).from_buffer_copy(image)
def un(z):return gzip.decompress(base64.b64decode(z))
rows=[json.loads(l) for l in (A/'receiver-vendor-commands-original.jsonl').open()];assert len(rows)==8704 and [t['case'] for t in rows]==list(range(8704));fails=[];ends=collections.Counter();groups=collections.defaultdict(collections.Counter);coverage=collections.defaultdict(set)
for t in rows:
 windows={}
 for n,size in [('ram',131072),('radio',4096),('deviceid',8),('boot',16)]:
  b=un(t[n+'_before']);assert len(b)==size;windows[n]=(U*size).from_buffer_copy(b)
 pending=Pending();rc=f.rr_receiver_vendor_commands(windows['ram'],flash,windows['radio'],windows['deviceid'],windows['boot'],t['entry'],t['incoming_r0'],C.byref(pending));errors=[]
 for n,b in windows.items():
  actual=bytes(b);expected=un(t[n+'_after']);assert len(actual)==len(expected)
  if actual!=expected:
   diffs=[i for i in range(len(actual)) if actual[i]!=expected[i]];errors.append({'window':n,'count':len(diffs),'first':[(hex(i),actual[i],expected[i]) for i in diffs[:10]]})
 if rc!=bool(t['boundary']):errors.append({'rc':rc,'expected_boundary':t['boundary']})
 if [pending.entry,pending.arg0,pending.arg0_valid]!=[t['boundary'],t['arg0'],t['arg0_valid']]:errors.append({'pending':[pending.entry,pending.arg0,pending.arg0_valid],'expected':[t['boundary'],t['arg0'],t['arg0_valid']]})
 if errors:fails.append({'case':t['case'],'class':hex(t['class']),'command':hex(t['command']),'errors':errors})
 kind=hex(t['boundary']) if t['boundary'] else 'returned';ends[kind]+=1;groups[str(t['op'])][kind]+=1;coverage[str(t['op'])+':'+hex(t['class'])].add(t['command'])
paths=files+list(P.glob('*.h'))+[Path(__file__),R/'ghidra-scripts/EmulateReceiverVendorCommands.java',A/'receiver-vendor-commands-original.jsonl']
d={'status':'PASS' if not fails else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'endings':dict(ends),'groups':dict(groups),'command_coverage':{k:sorted(v) for k,v in coverage.items()},'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'libraries':{str(lib.relative_to(R)):hashlib.sha256(lib.read_bytes()).hexdigest()},'limits':['Full128KiB RAM and staticRADIO4KiB/ID8B/boot16B compared; no opaque callback substituted','Classes0/7/FE each256command bytes, four fixtures per direct/router command;512 additionalworkwrapper inputs','True unresolved helper entry stops with meaningfularg0; no-argumentC774 records arg0_valid0','No physicalRF/USB/Flash orCPU stack/PRIMASK/concurrency proof; not full mouse-side vendor dictionary']}
(A/'receiver-vendor-commands-comparison.json').write_text(json.dumps(d,indent=2)+'\n');print(json.dumps({k:v for k,v in d.items() if k not in ['sources','libraries','failures','command_coverage']},indent=2));print(json.dumps(fails[:10],indent=2));assert not fails
