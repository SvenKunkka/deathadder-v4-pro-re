from pathlib import Path
import ctypes as C,json,subprocess,hashlib,gzip,base64,collections
R=Path(__file__).resolve().parent.parent;P=R/'recovered-code/portable';A=R/'analysis';N=R/'recovered-code/cortex-m';U=C.c_uint8;W=C.c_uint32;Ptr=C.POINTER(U)
lib=A/'libmouse_context_switch.dylib';subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',str(P/'mouse_context_switch.c'),'-o',str(lib)],check=True)
f=C.CDLL(str(lib));names=['rr_mouse_switch_request_inert','rr_mouse_select_context','rr_mouse_pendsv_body','rr_mouse_set_psplim']
for name in names[:3]:getattr(f,name).argtypes=[Ptr,Ptr,Ptr,C.POINTER(W)]
f.rr_mouse_set_psplim.argtypes=[Ptr,C.POINTER(W)]
def un(z):return gzip.decompress(base64.b64decode(z))
def buf(b):return (U*len(b)).from_buffer_copy(b)
def diff(name,got,expect):
 if got==expect:return []
 ds=[i for i in range(len(expect)) if got[i]!=expect[i]];return [{name+'_diffs':len(ds),'first':[(hex(i),got[i],expect[i]) for i in ds[:16]]}]
rows=[json.loads(s) for s in (A/'mouse-context-switch-original.jsonl').read_text().splitlines()];assert len(rows)==2048
fails=[];counts=collections.Counter()
for t in rows:
 m=buf(un(t['before_gzip']));nvic=buf(un(t['nvic_before']));scratch=buf(bytes.fromhex(t['scratch_before']));cpu=(W*24)(*t['cpu_before'])
 rc=getattr(f,names[t['op']])(m,cpu) if t['op']==3 else getattr(f,names[t['op']])(m,nvic,scratch,cpu)
 errors=diff('RAM',bytes(m),un(t['after_gzip']))+diff('NVIC',bytes(nvic),un(t['nvic_after']))+diff('MSP_scratch',bytes(scratch),bytes.fromhex(t['scratch_after']))+diff('CPU',list(cpu),t['cpu_after'])
 if rc!=(1 if t['op']==2 else 0):errors.append({'status':rc,'op':t['op']})
 if errors:fails.append({'case':t['case'],'op':t['op'],'errors':errors})
 counts[str(t['op'])]+=1
paths=[P/'mouse_context_switch.c',P/'mouse_context_switch.h',Path(__file__),R/'ghidra-scripts/EmulateMouseContextSwitch.java',A/'mouse-context-switch-original.jsonl']
report={'status':'PASS' if not fails else 'FAIL','original_cases':len(rows),'original_steps':sum(t['steps'] for t in rows),'counts':dict(counts),'normal_returns':1536,'before_exception_return_BX_LR':512,'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['Privileged body execution; no asynchronous interrupt in request','PendSV original stops before BX LR at0e089e06; no architectural frame unstacking, exception entry or real concurrency','PSP uses emulator shared native CPU state; absent PSPLIM operation records literal assignment only, not memory fault enforcement','All13 registers, SP/LR/PC, PSP/PSPLIM/BASEPRI, five flag bits,32B MSP scratch,64KiB RAM and4KiB SCB snapshot compared','Inert ICSR snapshots record original writes, not hardware readback or interrupt delivery']}
(A/'mouse-context-switch-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']},indent=2));print(json.dumps(fails[:6],indent=2));assert not fails
subprocess.run(['make','-C',str(N)],check=True)
fw=(R/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin').read_bytes();binary=(N/'build/mouse_context_switch.bin').read_bytes();spans=[]
for start,end in [(0,0xc0),(0x1f0,0x1f8)]:
 got=binary[start:end];expected=fw[0x1dd4c+start:0x1dd4c+end];assert got==expected;spans.append({'start':hex(0xe089d4c+start),'end_exclusive':hex(0xe089d4c+end),'image_offset':hex(0x1dd4c+start),'assembled_offset':hex(start),'length':end-start,'sha256':hashlib.sha256(got).hexdigest()})
paths=[N/'mouse_context_switch.S',N/'mouse_context_switch.ld',N/'Makefile',N/'build/mouse_context_switch.o',N/'build/mouse_context_switch.elf',N/'build/mouse_context_switch.bin']
n={'status':'PASS','architecture':'Cortex-M33 Thumb ARMv8-M','compared_bytes':200,'spans':spans,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'firmware_sha256':hashlib.sha256(fw).hexdigest(),'limits':['Exact source-assembled bytes for selected200 bytes, not full MCU image','Intervening304 bytes in fragment are placeholder padding and excluded, not original code','Fixed mouse1.20 addresses; no boot/vector/startup/full firmware linking or device execution','BX LR bytes match; architectural exception return is not executed in original-instruction fixture']}
(A/'mouse-context-native-comparison.json').write_text(json.dumps(n,indent=2)+'\n');print('native200 bytes PASS')
