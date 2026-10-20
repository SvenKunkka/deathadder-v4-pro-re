from pathlib import Path
import ctypes as C,json,hashlib,gzip,base64,collections,subprocess
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
lib=A/'libreceiver_vendor_identity.dylib';files=sorted(P.glob('*.c'));subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True);f=C.CDLL(str(lib))
class Window(C.Structure):_fields_=[('base',W),('data',Ptr),('size',C.c_size_t)]
class Bus(C.Structure):_fields_=[('ram',Ptr),('firmware',Ptr),('firmware_size',C.c_size_t),('windows',C.POINTER(Window)),('window_count',C.c_size_t),('priority',W),('error',C.c_int)]
class Pending(C.Structure):_fields_=[('kind',W),('entry',W),('args',W*4),('arg_mask',W)]
class Event(C.Structure):_fields_=[('disabled_value',W),('consumed',W)]
f.rr_receiver_vendor_identity_flow.argtypes=[C.POINTER(Bus),W,W,W,Ptr,C.POINTER(Event),C.POINTER(Pending)]
f.rr_receiver_vendor_identity_work_step.argtypes=[C.POINTER(Bus),W,W,Ptr,C.POINTER(Event),C.POINTER(Pending)]
class HW(C.Structure):_fields_=[(n,Ptr) for n in ['ram','radio','timer','nvic','dppi','rtc','clock0','clock1','clock2','deviceid']]
class CPU(C.Structure):_fields_=[('priority',W),('exception_number',W),('entry',W),('arg0',W)]
f.rr_receiver_config_iteration.argtypes=[C.POINTER(HW),W,Ptr,U,Ptr,C.POINTER(CPU)]
image=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();fw=(U*len(image)).from_buffer_copy(image)
table=(U*256).from_buffer_copy(image[0x1ba74:0x1bb74])
rows=[json.loads(l) for l in (A/'receiver-vendor-identity-original.jsonl').read_text().splitlines()];assert len(rows) in [3072,3584] and [t['case'] for t in rows]==list(range(len(rows)))
def un(s):return gzip.decompress(base64.b64decode(s))
fails=[];ends=collections.Counter();groups=collections.defaultdict(collections.Counter)
addresses={'radio':0x5302c000,'timer':0x53029000,'egu':0x53025000,'dppi':0x53022000,'rtc':0x5f99c000,'nvic':0xe000e000,'normal_timer':0x53028000,'aux':0x5f9a2000,'deviceid':0xfffe010,'boot':0xf000}
for t in rows:
 sizes={'ram':131072,'deviceid':8,'boot':16}
 mem={n:(U*sizes.get(n,4096)).from_buffer_copy(un(t[n+'_before'])) for n in ['ram',*addresses]}
 wins=(Window*10)(*[Window(addr,mem[n],sizes.get(n,4096)) for n,addr in addresses.items()]);bus=Bus(mem['ram'],fw,len(image),wins,10,t['initial_priority'],0);args=(W*5)(*t['args']);p=Pending();ev=Event(t['event_value'],0);result=W(0);errors=[]
 exception=W(t['exception']);stack=(U*512).from_buffer_copy(bytes.fromhex(t['stack_before']))
 if t['producer_count']:
  offset={0:52,1:76,2:84,3:148,4:36,5:36,6:76}[t['family']]
  if bytes(stack)[512-offset:540-offset].hex()!=t['tail']:errors.append({'stack_provenance':t['tail'],'expected':bytes(stack)[512-offset:540-offset].hex()})
  if t['producer_sp']!=t['initial_sp']-offset+36:errors.append({'producer_sp':t['producer_sp'],'expected':t['initial_sp']-offset+36})
 if t['family']==3:rc=f.rr_receiver_vendor_identity_work_step(C.byref(bus),t['args'][0],exception,stack,C.byref(ev),C.byref(p))
 else:rc=f.rr_receiver_vendor_identity_flow(C.byref(bus),t['entry'],t['args'][0],exception,stack,C.byref(ev),C.byref(p))
 if t.get('consumer_started'):
  if rc or p.kind or bus.priority!=t['producer_final_priority']:errors.append({'producer_return':[rc,p.kind,bus.priority],'expected':[0,0,t['producer_final_priority']]})
  for n,b in mem.items():
   if bytes(b)!=un(t[n+'_producer_after']):errors.append({'producer_window':n})
  clocks=[(U*4096)() for _ in range(3)]
  hw=HW(mem['ram'],mem['radio'],mem['normal_timer'],mem['nvic'],mem['dppi'],mem['rtc'],*clocks,mem['deviceid'])
  cpu=CPU(bus.priority,t['exception'],0,0)
  output=(U*36).from_buffer_copy(bytes.fromhex(t['consumer_output_before']))
  rc=f.rr_receiver_config_iteration(C.byref(hw),t['consumer_output_address'],output,0,table,C.byref(cpu))
  bus.priority=cpu.priority
  if rc==1:p.kind=1;p.entry=cpu.entry;p.args[0]=cpu.arg0;p.arg_mask=1
  if bytes(output).hex()!=t['consumer_output']:errors.append({'consumer_message':bytes(output).hex(),'expected':t['consumer_output']})
  event_id=int.from_bytes(bytes(output)[:4],'little');value=int.from_bytes(bytes(output)[4:8],'little')
  expected_id=8 if t['producer_entry']==0x230252a4 else 9
  if event_id!=expected_id or value!=t['producer_arg0']:errors.append({'identity_message':[event_id,value],'expected':[expected_id,t['producer_arg0']]})
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
 end=('next_config_header' if t.get('consumer_started') else 'next_worker_header' if t['family']==3 else 'returned') if not t['boundary'] else ('wait:' if t['kind']==2 else 'call:')+hex(t['boundary']);ends[end]+=1;groups[str(t['family'])][end]+=1
paths=files+list(P.glob('*.h'))+[Path(__file__),R/'ghidra-scripts/EmulateReceiverVendorIdentity.java',A/'receiver-vendor-identity-original.jsonl']
d={'status':'PASS' if not fails else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'endings':dict(ends),'groups':dict(groups),'injected_disabled_events':sum(t['consumed'] for t in rows),'producer_reached':sum(bool(t['producer_count']) for t in rows),'explicit_consumer_handoffs':sum(bool(t.get('consumer_started')) for t in rows),'consumer_events':dict(collections.Counter(str(int.from_bytes(bytes.fromhex(t['consumer_output'])[:4],'little')) for t in rows if t.get('consumer_started'))),'stack_provenance_matches':sum(bool(t['producer_count']) and t['tail_matches_initial'] for t in rows),'failure_count':len(fails),'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'libraries':{str(lib.relative_to(R)):hashlib.sha256(lib.read_bytes()).hexdigest()},'limits':['Full128KiBRAM,eight4KiBMMIO,deviceID8B,boot16B,BASEPRI and actual boundaries compared','The 28 residual producer stack bytes are compared against the exact initial512B snapshot and original producer entry observation','First nonempty worker iteration, direct callback and serialized privileged execution only; no asynchronous stack writes','Consumer invocation is explicitly staged after a normal producer return, not original CPU context switching','Scratch stack is excluded except bytes escaping to the message; no RF, physical peripheral effects, concurrency or firmware startup proof']}
(A/'receiver-vendor-identity-comparison.json').write_text(json.dumps(d,indent=2)+'\n');print(json.dumps({k:v for k,v in d.items() if k not in ['sources','libraries','failures']},indent=2));print(json.dumps(fails[:12],indent=2));assert not fails
