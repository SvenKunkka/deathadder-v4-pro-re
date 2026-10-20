from pathlib import Path
import ctypes as C,json,hashlib,gzip,base64,collections,subprocess
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
files=sorted(P.glob('*.c'));lib=A/'libmouse_initialization_partial.dylib'
subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True)
f=C.CDLL(str(lib));names=['ram','radio','timer','nvic','dppi','clock']
class HW(C.Structure):_fields_=[(n,Ptr) for n in names]
f.rr_mouse_initialize.argtypes=[C.POINTER(HW),W,W,W,W,W]
f.rr_mouse_application_initialize.argtypes=[C.POINTER(HW),W,W,W,W,Ptr]
f.rr_mouse_radio_initialize.argtypes=[C.POINTER(HW),W,U]
f.rr_mouse_radio_reset.argtypes=[Ptr]
f.rr_mouse_radio_dppi.argtypes=[C.POINTER(HW)]
f.rr_mouse_radio_queue_initialize.argtypes=[Ptr,W]
image=(R/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin').read_bytes();table=(U*256).from_buffer_copy(image[0x2c904:0x2ca04])
def un(s):return gzip.decompress(base64.b64decode(s))
rows=[json.loads(line) for line in (A/'mouse-initialization-original.jsonl').read_text().splitlines()[:-1]]
assert rows and [t['case'] for t in rows]==list(range(len(rows)))
fails=[];groups=collections.Counter();rates=collections.Counter();keys=set();phys=set()
for t in rows:
 mem={n:(U*len(un(t[n+'_before']))).from_buffer_copy(un(t[n+'_before'])) for n in names};hw=HW(*[mem[n] for n in names]);errors=[];params=t['params'];family=t['family']
 if family==0:rc=f.rr_mouse_initialize(C.byref(hw),*params)
 elif family==1:rc=f.rr_mouse_application_initialize(C.byref(hw),params[0],*params[2:],table);keys.add(params[0]&15)
 elif family==2:rc=f.rr_mouse_radio_initialize(C.byref(hw),params[0],t['phy']);phys.add(t['phy'])
 elif family==3:rc=f.rr_mouse_radio_reset(mem['ram'])
 elif family==4:rc=f.rr_mouse_radio_dppi(C.byref(hw))
 else:rc=f.rr_mouse_radio_queue_initialize(mem['ram'],t['peer'])
 for n,b in mem.items():
  got=bytes(b);expected=un(t[n+'_after'])
  if got!=expected:
   ds=[i for i in range(len(got)) if got[i]!=expected[i]];errors.append({'window':n,'count':len(ds),'first':[(hex(i),got[i],expected[i]) for i in ds[:12]]})
 if rc or t['kind'] or t['boundary'] or t['end_pc']!=0x2302df00:errors.append({'return':rc,'kind':t['kind'],'boundary':t['boundary'],'pc':t['end_pc']})
 if t['initial_priority']!=t['final_priority']:errors.append({'priority':[t['initial_priority'],t['final_priority']]})
 if family<=1:
  rate=params[4]&65535;rates[str(rate)]+=1
  if bytes(mem['radio'][0x500:0x504])!=bytes([4,0,0,0]):errors.append({'full_PHY':'not4'})
 if errors:fails.append({'case':t['case'],'family':family,'errors':errors})
 groups[str(family)]+=1
assert keys.issubset(set(range(16))) and phys.issubset(set(range(256)))
paths=files+sorted(P.glob('*.h'))+[Path(__file__),R/'ghidra-scripts/EmulateMouseInitialization.java',A/'run_mouse_initialization_oracle.py',A/'mouse-initialization-original.jsonl']
d={'status':'PASS' if not fails else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'groups':dict(groups),'full_returns':len(rows)-sum(bool(t['boundary']) for t in rows),'installed_key_selectors':sorted(keys),'standalone_PHY_values':sorted(phys),'rate_inputs':dict(rates),'failure_count':len(fails),'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'libraries':{str(lib.relative_to(R)):hashlib.sha256(lib.read_bytes()).hexdigest()},'limits':['Full128KiBRAM and five4KiBMMIO windows, finalBASEPRI and complete originalsoftware returns','Initial scratchstack supplied tooriginal CPU; fullinitPHYiswritten4 and wrapper truncates16bitfields; no escaped unknownstack input','IRQ configuration finalmemory compared; write sequence and timing not asserted','Standalone queue initializer index0..31 is address-bounded synthetic input, not proof of supported peer count','No automatic peripheralSET/CLR effects, RF, physical clocks, concurrency, complete boot or firmware link proof']}
(A/'mouse-initialization-partial-comparison.json').write_text(json.dumps(d,indent=2)+'\n');print(json.dumps({k:v for k,v in d.items() if k not in ['sources','libraries','failures','standalone_PHY_values']},indent=2));print(json.dumps(fails[:12],indent=2));assert not fails
