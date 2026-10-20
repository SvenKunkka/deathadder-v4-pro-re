from pathlib import Path
import ctypes as C,json,hashlib,gzip,base64,collections,subprocess
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
lib=A/'libreceiver_vendor_flow_partial.dylib';files=sorted(P.glob('*.c'));subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True);f=C.CDLL(str(lib))
class Window(C.Structure):_fields_=[('base',W),('data',Ptr),('size',C.c_size_t)]
class Bus(C.Structure):_fields_=[('ram',Ptr),('firmware',Ptr),('firmware_size',C.c_size_t),('windows',C.POINTER(Window)),('window_count',C.c_size_t),('priority',W),('error',C.c_int)]
class Pending(C.Structure):_fields_=[('kind',W),('entry',W),('args',W*4),('arg_mask',W)]
class Event(C.Structure):_fields_=[('disabled_value',W),('consumed',W)]
f.rr_receiver_vendor_flow.argtypes=[C.POINTER(Bus),W,W,W,C.POINTER(Event),C.POINTER(Pending)]
f.rr_receiver_vendor_work_step.argtypes=[C.POINTER(Bus),W,W,C.POINTER(Event),C.POINTER(Pending)]
image=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();fw=(U*len(image)).from_buffer_copy(image)
rows=[json.loads(l) for l in (A/'receiver-vendor-flow-original.jsonl').read_text().rsplit('\n',1)[0].splitlines()];assert [t['case'] for t in rows]==list(range(len(rows)))
def un(s):return gzip.decompress(base64.b64decode(s))
fails=[];ends=collections.Counter();groups=collections.defaultdict(collections.Counter)
addresses={'radio':0x5302c000,'timer':0x53029000,'egu':0x53025000,'dppi':0x53022000,'rtc':0x5f99c000,'nvic':0xe000e000,'normal_timer':0x53028000,'aux':0x5f9a2000,'deviceid':0xfffe010,'boot':0xf000}
for t in rows:
 sizes={'ram':131072,'deviceid':8,'boot':16}
 mem={n:(U*sizes.get(n,4096)).from_buffer_copy(un(t[n+'_before'])) for n in ['ram',*addresses]}
 wins=(Window*10)(*[Window(addr,mem[n],sizes.get(n,4096)) for n,addr in addresses.items()]);bus=Bus(mem['ram'],fw,len(image),wins,10,t['initial_priority'],0);args=(W*5)(*t['args']);p=Pending();ev=Event(t['event_value'],0);result=W(0);errors=[]
 exception=W(t['exception'])
 if t['family']==3:rc=f.rr_receiver_vendor_work_step(C.byref(bus),t['args'][0],exception,C.byref(ev),C.byref(p))
 else:rc=f.rr_receiver_vendor_flow(C.byref(bus),t['entry'],t['args'][0],exception,C.byref(ev),C.byref(p))
 for n,b in mem.items():
  actual=bytes(b);expected=un(t[n+'_after'])
  if actual!=expected:
   diff=[i for i in range(len(actual)) if actual[i]!=expected[i]];errors.append({'window':n,'count':len(diff),'first':[(hex(i),actual[i],expected[i]) for i in diff[:10]]})
 expected=[t['kind'],t['boundary'],*t['boundary_args'],t['arg_mask']];actual=[p.kind,p.entry,*p.args,p.arg_mask]
 if actual!=expected:errors.append({'pending':actual,'expected':expected})
 if rc!=bool(t['boundary']) or bus.error:errors.append({'rc':rc,'bus_error':bus.error,'expected':bool(t['boundary'])})
 if bus.priority!=t['final_priority']:errors.append({'priority':bus.priority,'expected':t['final_priority']})
 if ev.consumed!=t['consumed']:errors.append({'events':ev.consumed,'expected':t['consumed']})
 if t['result_valid'] and not t['boundary'] and result.value!=t['result']:errors.append({'result':result.value,'expected':t['result']})
 if errors:fails.append({'case':t['case'],'entry':hex(t['entry']),'errors':errors})
 end=('next_worker_header' if t['family']==3 else 'returned') if not t['boundary'] else ('wait:' if t['kind']==2 else 'call:')+hex(t['boundary']);ends[end]+=1;groups[str(t['family'])][end]+=1
paths=files+list(P.glob('*.h'))+[Path(__file__),R/'ghidra-scripts/EmulateReceiverVendorFlow.java',A/'receiver-vendor-flow-original.jsonl']
d={'status':'PASS' if not fails else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'endings':dict(ends),'groups':dict(groups),'injected_disabled_events':sum(t['consumed'] for t in rows),'failure_count':len(fails),'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'libraries':{str(lib.relative_to(R)):hashlib.sha256(lib.read_bytes()).hexdigest()},'limits':['Full128KiBRAM,eight4KiBMMIO+deviceID8B+boot16B,BASEPRI,meaningfulreturns and realboundaries compared','Explicit nonzeroRADIO_EVENTS_DISABLED injected at EACH reached poll; absent event stops, no physical proof','Default logger runs original formatter and actual no-output sink; changed output callback or CPU switch remains boundary','GPPI same-descriptor RFdomain; cross-domain not reconstructed here','No contention,cycle timing,peripheral SET/CLR effects or firmware link/startup proof']}
(A/'receiver-vendor-flow-partial-comparison.json').write_text(json.dumps(d,indent=2)+'\n');print(json.dumps({k:v for k,v in d.items() if k not in ['sources','libraries','failures']},indent=2));print(json.dumps(fails[:12],indent=2));assert not fails
