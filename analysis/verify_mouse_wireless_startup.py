from pathlib import Path
import ctypes as C,json,hashlib,gzip,base64,collections,subprocess
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable';U=C.c_uint8;W=C.c_uint32;Q=C.c_uint64;Ptr=C.POINTER(U)
files=sorted(P.glob('*.c'));lib=A/'libmouse_wireless_startup.dylib'
subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True)
f=C.CDLL(str(lib));names=['ram','radio','timer','nvic','dppi','clock','rtc']
class Init(C.Structure):_fields_=[(n,Ptr) for n in names[:-1]]
class HW(C.Structure):_fields_=[('init',Init),('rtc',Ptr),('table',Ptr)]
class CPU(C.Structure):_fields_=[(n,W) for n in ['priority','exception','entry','arg0']]
class Thread(C.Structure):_fields_=[(n,W) for n in ['thread','stack','size','entry','arg1','arg2','arg3','priority','options']]+[('delay',Q)]
f.rr_mouse_wireless_startup.argtypes=[C.POINTER(HW),W,W,C.POINTER(CPU)]
f.rr_mouse_wireless_setup.argtypes=[C.POINTER(HW),C.POINTER(CPU)]
f.rr_mouse_scan_work_initialize.argtypes=[Ptr]
f.rr_mouse_thread_create.argtypes=[Ptr,Ptr,C.POINTER(Thread),C.POINTER(CPU),C.POINTER(W)]
f.rr_mouse_thread_start.argtypes=[Ptr,Ptr,W,C.POINTER(CPU)]
for n in ['rr_mouse_ticks_sleep','rr_mouse_public_sleep']:getattr(f,n).argtypes=[Ptr,Ptr,Q,C.POINTER(CPU),C.POINTER(W)]
image=(R/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin').read_bytes();table=(U*256).from_buffer_copy(image[0x2c904:0x2ca04])
def un(s):return gzip.decompress(base64.b64decode(s))
def word(b,o):return int.from_bytes(b[o:o+4],'little')
rows=[json.loads(line) for line in (A/'mouse-wireless-startup-original.jsonl').open()]
assert len(rows)==3712 and [t['case'] for t in rows]==list(range(3712))
fails=[];groups=collections.Counter();ends=collections.Counter();milestones=collections.Counter();deadlines=0;abi=0
for t in rows:
 mem={n:(U*len(un(t[n+'_before']))).from_buffer_copy(un(t[n+'_before'])) for n in names};hw=HW(Init(*[mem[n] for n in names[:-1]]),mem['rtc'],table)
 cpu=CPU(t['initial_priority'],t['exception'],0,0);out=W(0xbad);errors=[];a=t['args'];family=t['family'];delay=int(t['delay'])
 if family==0:rc=f.rr_mouse_wireless_startup(C.byref(hw),a[0],a[1],C.byref(cpu))
 elif family==1:rc=f.rr_mouse_wireless_setup(C.byref(hw),C.byref(cpu));out.value=0
 elif family==2:rc=f.rr_mouse_scan_work_initialize(mem['ram'])
 elif family==3:
  q=Thread(*a[:9],a[10]|a[11]<<32);rc=f.rr_mouse_thread_create(mem['ram'],mem['rtc'],C.byref(q),C.byref(cpu),C.byref(out))
 elif family==4:rc=f.rr_mouse_thread_start(mem['ram'],mem['rtc'],a[0],C.byref(cpu))
 elif family==5:rc=f.rr_mouse_ticks_sleep(mem['ram'],mem['rtc'],delay,C.byref(cpu),C.byref(out))
 else:rc=f.rr_mouse_public_sleep(mem['ram'],mem['rtc'],delay,C.byref(cpu),C.byref(out))
 for n,b in mem.items():
  got=bytes(b);expected=un(t[n+'_after'])
  if got!=expected:
   ds=[i for i in range(len(got)) if got[i]!=expected[i]];errors.append({'window':n,'count':len(ds),'first':[(hex(i),got[i],expected[i]) for i in ds[:12]]})
 if rc!=t['kind'] or cpu.entry!=t['boundary'] or cpu.priority!=t['final_priority']:errors.append({'control':[rc,cpu.entry,cpu.priority],'expected':[t['kind'],t['boundary'],t['final_priority']]})
 if t['arg_mask']&1 and cpu.arg0!=t['boundary_args'][0]:errors.append({'boundary_arg0':[cpu.arg0,t['boundary_args'][0]]})
 if not t['boundary'] and t['result_valid'] and out.value!=t['result']:errors.append({'result':[out.value,t['result']]})
 if family==5 and delay:
  deadlines+=1
  if out.value!=t['registers_after']['r4']:errors.append({'deadline':[out.value,t['registers_after']['r4']]})
 for obs in t['create_observations']:
  stack=bytes.fromhex(obs['stack_args']);regs=obs['registers'];abi+=1
  expected=([0x23001bb8,0x230109e0,0x400,0x23025d91,0,0,0,10,0,0,0] if family in [0,1] else a[:9]+a[10:12])
  actual=[regs['r'+str(i)] for i in range(4)]+[word(stack,i) for i in [0,4,8,12,16,24,28]]
  if actual!=expected:errors.append({'AAPCS_create':actual,'expected':expected})
 for n in ['scan_work_init_seen','application_init_seen','setup_returned']:milestones[n]+=bool(t[n])
 if errors:fails.append({'case':t['case'],'family':family,'errors':errors})
 groups[str(family)]+=1;ends[f'{family}:'+('cpu_request' if t['boundary'] else 'returned')]+=1
paths=files+sorted(P.glob('*.h'))+[Path(__file__),R/'ghidra-scripts/EmulateMouseWirelessStartup.java',A/'run_mouse_wireless_startup_oracle.py',A/'mouse-wireless-startup-original.jsonl']
d={'status':'PASS' if not fails else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'groups':dict(groups),'endings':dict(ends),'full_returns':sum(not t['boundary'] for t in rows),'CPU_requests':sum(bool(t['boundary']) for t in rows),'deadline_register_checks':deadlines,'thread_create_ABI_checks':abi,'milestones':dict(milestones),'failure_count':len(fails),'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'libraries':{str(lib.relative_to(R)):hashlib.sha256(lib.read_bytes()).hexdigest()},'limits':['Full128KiBRAM and six4KiBMMIO windows, finalBASEPRI, actual return or CPUrequest/arg0 compared','Original CPU request stops BEFORE E089D4C; no automatic switch, wait completion, wakeup or resumed call','Escaped original register/stack recorded as diagnostic evidence; portable C is semantic and does not reproduce native caller stack/register layout','Original stack_before initializes576B. Escaped diagnostic bytes beyond its upper address are uninitialized and excluded from claims/comparisons','Only deadline r4 and observed AAPCS thread-create arguments are compared; no full CPU state equivalence claim','Inert finalmemoryeffects; barriers serialized, no automatic peripheral effects, IRQ injection, RF or board validation']}
(A/'mouse-wireless-startup-comparison.json').write_text(json.dumps(d,indent=2)+'\n');print(json.dumps({k:v for k,v in d.items() if k not in ['sources','libraries','failures']},indent=2));print(json.dumps(fails[:12],indent=2));assert not fails
