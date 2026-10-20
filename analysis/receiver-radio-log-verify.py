from pathlib import Path
import ctypes as C,json,hashlib,gzip,base64,collections,subprocess
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
lib=A/'libreceiver_radio_log_phase62.dylib'
if not lib.exists():subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',str(P/'receiver_radio_test_log.c'),'-o',str(lib)],check=True)
f=C.CDLL(str(lib))
class Window(C.Structure):_fields_=[('base',W),('data',Ptr),('size',C.c_size_t)]
class Bus(C.Structure):_fields_=[('ram',Ptr),('firmware',Ptr),('firmware_size',C.c_size_t),('windows',C.POINTER(Window)),('window_count',C.c_size_t),('priority',W),('error',C.c_int)]
class Pending(C.Structure):_fields_=[('kind',W),('entry',W),('args',W*4),('arg_mask',W)]
f.rr_receiver_radio_test_log.argtypes=[C.POINTER(Bus),C.POINTER(W),C.POINTER(W),C.POINTER(Pending)]
image=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();assert hashlib.sha256(image).hexdigest()=='f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162';fw=(U*len(image)).from_buffer_copy(image)
addresses={'radio':0x5302c000,'timer':0x53029000,'egu':0x53025000,'dppi':0x53022000,'rtc':0x5f99c000,'nvic':0xe000e000}
def un(s):return gzip.decompress(base64.b64decode(s))
fails=[];ends=collections.Counter();groups=collections.Counter();values32=set();low8=collections.defaultdict(set);steps=0;count=0
for line in (A/'receiver-radio-log-original.jsonl').open():
 t=json.loads(line);assert t['case']==count;count+=1;steps+=t['steps'];mem={n:(U*(131072 if n=='ram' else 4096)).from_buffer_copy(un(t[n+'_before'])) for n in ['ram',*addresses]}
 wins=(Window*6)(*[Window(addr,mem[n],4096) for n,addr in addresses.items()]);bus=Bus(mem['ram'],fw,len(image),wins,6,17,0);args=(W*5)(*t['args']);result=W(0);p=Pending();errors=[]
 rc=f.rr_receiver_radio_test_log(C.byref(bus),args,C.byref(result),C.byref(p))
 for n,b in mem.items():
  actual=bytes(b);expected=un(t[n+'_after'])
  if actual!=expected:
   diffs=[i for i,(x,y) in enumerate(zip(actual,expected)) if x!=y];errors.append({'window':n,'count':len(diffs),'first':[(hex(i),actual[i],expected[i]) for i in diffs[:10]]})
 expected=[1,t['boundary'],t['arg0'],0,0,0,1] if t['boundary'] else [0]*7
 actual=[p.kind,p.entry,*p.args,p.arg_mask]
 if actual!=expected:errors.append({'pending':actual,'expected':expected})
 if rc!=bool(t['boundary']) or bus.error or bus.priority!=17:errors.append({'rc':rc,'error':bus.error,'priority':bus.priority})
 if not t['boundary'] and result.value!=t['result']:errors.append({'result':result.value,'expected':t['result']})
 if errors:fails.append({'case':t['case'],'errors':errors})
 end='boundary' if t['boundary'] else 'returned';ends[end]+=1;groups[f"{t['format_index']}:{end}"]+=1
 if not t['boundary']:
  if t['format_index'] in (1,2):low8[t['format_index']].add(t['args'][1]&255)
  elif t['format_index'] in (3,4,6):values32.add(t['args'][1])
assert count==3328;assert all(len(s)==256 for s in low8.values());assert len(values32)>=1024
paths=[P/'receiver_radio_test_log.c',P/'receiver_radio_test_log.h',P/'receiver_radio_test_bus.h',R/'ghidra-scripts/EmulateReceiverRadioLog.java',A/'receiver-radio-log-run.py',Path(__file__),A/'receiver-radio-log-original.jsonl']
d={'status':'PASS' if not fails else 'FAIL','original_cases':count,'original_steps':steps,'endings':dict(ends),'format_groups':dict(groups),'distinct_signed32_inputs':len(values32),'signed8_lowbyte_coverage':{str(k):len(v) for k,v in low8.items()},'failure_count':len(fails),'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'libraries':{str(lib.relative_to(R)):hashlib.sha256(lib.read_bytes()).hexdigest()},'limits':['Actual original printf formatter and default sink executed; no callback result was stubbed','Full128KiBRAM and six4KiB inert MMIO snapshots compared; stack-local scratch excluded','3,072 meaningful original return counts and256 actual changed-sink boundaries compared','Exactly seven validated RF format ROM strings; no claim of generic printf recovery','No physical device output or peripheral timing behavior tested']}
(A/'receiver-radio-log-comparison.json').write_text(json.dumps(d,indent=2)+'\n');print(json.dumps({k:v for k,v in d.items() if k not in ('sources','libraries','failures')},indent=2));print(json.dumps(fails[:10],indent=2));assert not fails
