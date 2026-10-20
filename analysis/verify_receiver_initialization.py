from pathlib import Path
import ctypes as C,json,subprocess,hashlib,gzip,base64,collections
R=Path(__file__).resolve().parent.parent;P=R/'recovered-code/portable';A=R/'analysis';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
files=[P/(n+'.c') for n in ['receiver_initialization','business_keys','business_cipher']]
lib=A/'libreceiver_initialization.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True)
f=C.CDLL(str(lib));names=['ram','radio','timer','nvic','dppi','rtc','clock0','clock1','clock2','deviceid']
class HW(C.Structure):_fields_=[(n,Ptr) for n in names]
f.rr_receiver_initialize.argtypes=[C.POINTER(HW),W,W,U]
f.rr_receiver_radio_initialize.argtypes=[C.POINTER(HW),W,U]
f.rr_receiver_config_event.argtypes=[C.POINTER(HW),W,W,U,Ptr]
image=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();table=(U*256).from_buffer_copy(image[0x1ba74:0x1bb74])
def un(z):return gzip.decompress(base64.b64decode(z))
rows=[json.loads(s) for s in (A/'receiver-initialization-original.jsonl').read_text().splitlines()];assert len(rows)==3072
fails=[];counts=collections.Counter();phy=collections.Counter();channels=set();returns=collections.Counter()
for t in rows:
 mem={n:(U*len(un(t[n+'_before']))).from_buffer_copy(un(t[n+'_before'])) for n in names};hw=HW(*[mem[n] for n in names])
 if t['op']==0:rc=f.rr_receiver_initialize(C.byref(hw),t['identity'],t['capability'],t['phy'])
 elif t['op']==1:rc=f.rr_receiver_radio_initialize(C.byref(hw),t['capability'],t['phy'])
 else:rc=f.rr_receiver_config_event(C.byref(hw),t['event'],t['identity'],t['phy'],table)
 errors=[]
 for n in names:
  got=bytes(mem[n]);expect=un(t[n+'_after'])
  if got!=expect:
   ds=[i for i in range(len(expect)) if got[i]!=expect[i]];errors.append({'window':n,'diffs':len(ds),'first':[(hex(i),got[i],expect[i]) for i in ds[:12]]})
 if rc:errors.append({'return':rc})
 if t['initial_priority']!=t['final_priority']:errors.append({'priority':t['final_priority']})
 if errors:fails.append({'case':t['case'],'op':t['op'],'event':t['event'],'errors':errors})
 counts[str(t['op'])]+=1;returns['next_loop_head' if t['op']==2 else 'full_return']+=1
 if t['op']==0:phy[str(t['phy'])]+=1;channels.add(tuple(bytes(mem['ram'])[0x31ac:0x31ae]))
paths=files+[P/'receiver_initialization.h',Path(__file__),R/'ghidra-scripts/EmulateReceiverInitialization.java',A/'receiver-initialization-original.jsonl']
report={'status':'PASS' if not fails else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'counts':dict(counts),'endings':dict(returns),'initialization_stack_phy_values':len(phy),'initialization_channel_pairs':len(channels),'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['Ten inert memory windows; real RTC/readback/IRQ/radio not autonomous','Original PRNG and all called initialization instructions executed; constant RTC snapshot per case','Old stack byte explicitly supplied for full init; stack writes not compared','Config dispatch starts after dequeue and ends at next loop header; only events1/8/9 and ignored defaults covered','Other dispatch arms, queue wait, whole startup, crosscore identities and RF remain incomplete']}
(A/'receiver-initialization-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']},indent=2));print(json.dumps(fails[:8],indent=2));assert not fails
