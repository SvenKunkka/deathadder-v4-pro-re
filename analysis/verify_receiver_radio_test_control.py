from pathlib import Path
import json,hashlib,ctypes as C,subprocess,base64,gzip,collections
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
files=sorted(P.glob('*.c'));lib=A/'libreceiver_radio_test_control.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True);f=C.CDLL(str(lib))
class Pending(C.Structure):_fields_=[('entry',W),('arg0',W),('arg0_valid',W)]
f.rr_receiver_radio_test_control.argtypes=[Ptr,Ptr,W,W,W,C.POINTER(Pending)]
image=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();flash=(U*len(image)).from_buffer_copy(image)
def un(z):return gzip.decompress(base64.b64decode(z))
rows=[json.loads(l) for l in (A/'receiver-radio-test-original.jsonl').open()];assert len(rows)==2048 and [t['case'] for t in rows]==list(range(2048));fails=[];ends=collections.Counter();groups=collections.defaultdict(collections.Counter);coverage=collections.defaultdict(set)
for t in rows:
 windows={}
 for n,size in [('ram',131072)]:
  b=un(t[n+'_before']);assert len(b)==size;windows[n]=(U*size).from_buffer_copy(b)
 pending=Pending();rc=f.rr_receiver_radio_test_control(windows['ram'],flash,t['entry'],t['arg0'],t['arg1'],C.byref(pending));errors=[]
 for n,b in windows.items():
  actual=bytes(b);expected=un(t[n+'_after']);assert len(actual)==len(expected)
  if actual!=expected:
   diffs=[i for i in range(len(actual)) if actual[i]!=expected[i]];errors.append({'window':n,'count':len(diffs),'first':[(hex(i),actual[i],expected[i]) for i in diffs[:10]]})
 if rc!=bool(t['boundary']):errors.append({'rc':rc,'expected_boundary':t['boundary']})
 if [pending.entry,pending.arg0,pending.arg0_valid]!=[t['boundary'],t['boundary_arg0'],t['arg0_valid']]:errors.append({'pending':[pending.entry,pending.arg0,pending.arg0_valid],'expected':[t['boundary'],t['boundary_arg0'],t['arg0_valid']]})
 if errors:fails.append({'case':t['case'],'errors':errors})
 kind=hex(t['boundary']) if t['boundary'] else 'returned';ends[kind]+=1;groups[str(t['op'])][kind]+=1
paths=files+list(P.glob('*.h'))+[Path(__file__),R/'ghidra-scripts/EmulateReceiverRadioTestControl.java',A/'receiver-radio-test-original.jsonl']
d={'status':'PASS' if not fails else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'endings':dict(ends),'groups':dict(groups),'command_coverage':{k:sorted(v) for k,v in coverage.items()},'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'libraries':{str(lib.relative_to(R)):hashlib.sha256(lib.read_bytes()).hexdigest()},'limits':['Full128KiB RAM compared at function return or genuine downstream entry','Eight entry functions,256 distinct RAM fixtures each; not exhaustive state combinations','Payload address restricted to actual vendor mailbox23002D24; no alias claim','No injected call results, physicalRF/USB/Flash, CPUstack or concurrency proof','No continuation across radio-stop/test-stop/test-engine boundary']}
(A/'receiver-radio-test-comparison.json').write_text(json.dumps(d,indent=2)+'\n');print(json.dumps({k:v for k,v in d.items() if k not in ['sources','libraries','failures','command_coverage']},indent=2));print(json.dumps(fails[:10],indent=2));assert not fails
