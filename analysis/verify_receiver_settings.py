from pathlib import Path
import ctypes as C,json,subprocess,hashlib,gzip,base64,collections
R=Path(__file__).resolve().parent.parent;P=R/'recovered-code/portable';A=R/'analysis';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
files=sorted(P.glob('*.c'));lib=A/'libreceiver_settings.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True);f=C.CDLL(str(lib))
class State(C.Structure):_fields_=[('stage',W),('entry',W),('args',W*4)]
f.rr_receiver_settings_load.argtypes=[Ptr,C.POINTER(State)];f.rr_receiver_settings_flush.argtypes=[Ptr,C.POINTER(State)]
f.rr_receiver_settings_resume.argtypes=[Ptr,Ptr,Ptr,Ptr,C.POINTER(State),W]
f.rr_receiver_settings_mark.argtypes=[Ptr,W];f.rr_receiver_settings_crc.argtypes=[Ptr,C.c_size_t,C.c_uint16];f.rr_receiver_settings_crc.restype=C.c_uint16
image=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();flash=(U*len(image)).from_buffer_copy(image)
def un(s):return gzip.decompress(base64.b64decode(s))
def array(b):return (U*len(b)).from_buffer_copy(b)
def delta(got,expect):
 ds=[i for i,(x,y) in enumerate(zip(got,expect)) if x!=y];return {'diffs':len(ds),'first':[(hex(i),got[i],expect[i]) for i in ds[:12]]}
rows=[json.loads(s) for s in (A/'receiver-settings-original.jsonl').read_text().splitlines()];assert len(rows)==2304
failures=[];counts=collections.Counter();ext=collections.Counter();segment_count=0;special=0
for t in rows:
 m=array(un(t['ram_before']));rtc=array(un(t['rtc_before']));device=array(bytes.fromhex(t['deviceid']));s=State();err=[]
 if t['op']==0:rc=f.rr_receiver_settings_load(m,C.byref(s))
 elif t['op']==1:rc=f.rr_receiver_settings_flush(m,C.byref(s))
 elif t['op']==2:
  result=f.rr_receiver_settings_crc(C.cast(C.byref(m,0x9000),Ptr),t['length'],t['seed']);rc=0
  if result!=t['return']:err.append({'crc':result,'want':t['return']})
 else:rc=f.rr_receiver_settings_mark(m,t['event'])
 for n,e in enumerate(t['events']):
  segment_count+=1;expected=un(e['ram'])
  if rc!=1 or s.entry!=e['entry'] or list(s.args)!=e['args']:err.append({'segment':n,'boundary':[rc,s.entry,list(s.args)],'want':[1,e['entry'],e['args']]})
  if bytes(m)!=expected:err.append({'segment':n,**delta(bytes(m),expected)})
  effect=bytes.fromhex(e['read_effect']);off=e['args'][2]-0x23000000
  for j,b in enumerate(effect):m[off+j]=b
  ext['read' if e['entry']==0xe05ed64 else 'write']+=1
  ext['raw_result_'+hex(e['raw_result'])]+=1
  rc=f.rr_receiver_settings_resume(m,flash,device,rtc,C.byref(s),e['raw_result'])
 if rc!=0 or s.stage!=0:err.append({'end':[rc,s.stage,s.entry]})
 expected=un(t['ram_after'])
 if bytes(m)!=expected:err.append({'end_ram':delta(bytes(m),expected)})
 if bytes(rtc)!=un(t['rtc_after']):err.append({'rtc':'changed'})
 if t['initial_priority']!=t['final_priority']:err.append({'priority':'not preserved'})
 if un(t['ram_before'])[0x230:0x238]!=expected[0x230:0x238]:special+=1
 if err:failures.append({'case':t['case'],'op':t['op'],'errors':err})
 counts[str(t['op'])]+=1
paths=files+[P/'receiver_settings.h',Path(__file__),R/'ghidra-scripts/EmulateReceiverSettings.java',A/'receiver-settings-original.jsonl']
report={'status':'PASS' if not failures else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'operations':dict(counts),'external_storage_boundaries':dict(ext),'boundary_snapshots':segment_count,'special_device_PRNG_cases':special,'failures':failures,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['Original instructions execute between real storage API boundaries; storage reads/writes are external fixture inputs, not emulated flash transactions','Read return values are ignored by the original loader; explicit effects may be full/partial/empty regardless of return code','Static RTC and device ID windows; no changing hardware registers or asynchronous mutation','128KiB RAM and RTC compared; original temporary CPU stack outside that RAM excluded','No receiver hardware or air traffic validated']}
(A/'receiver-settings-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']},indent=2));print(json.dumps(failures[:6],indent=2));assert not failures
