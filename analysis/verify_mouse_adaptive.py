#!/usr/bin/env python3
"""Compare reconstructed adaptive path to retained original Thumb execution."""
from pathlib import Path
import ctypes as C,json,subprocess,hashlib,zlib,base64,collections
R=Path(__file__).resolve().parent.parent
A=R/'analysis';P=R/'recovered-code/portable'
lib=P/'build/libmouse_adaptive.dylib';lib.parent.mkdir(exist_ok=True)
sources=[P/'mouse_adaptive_control.c',P/'business_tx.c',P/'business_cipher.c']
subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-dynamiclib',*[str(f) for f in sources],'-o',str(lib)],check=True)
l=C.CDLL(str(lib));U=C.c_uint8;U32=C.c_uint32;B=U*65536
l.rr_mouse_adaptive_run.argtypes=[C.POINTER(U),C.c_uint,U32,U32];l.rr_mouse_adaptive_run.restype=C.c_int
l.rr_mouse_adaptive_irq.argtypes=[C.POINTER(U)];l.rr_mouse_adaptive_irq.restype=C.c_int
l.rr_mouse_adaptive_request.argtypes=[C.POINTER(U),U32,U32,U32,C.POINTER(U32)]
rows=[json.loads(t) for t in (A/'mouse-adaptive-original.jsonl').read_text().splitlines() if t.strip()]
assert len(rows)==1536
fails=[];counts=collections.Counter();reports=collections.Counter()
def un(z):return zlib.decompress(base64.b64decode(z))
for t in rows:
 before=un(t['ram_before_z']);expected=un(t['ram_after_z']);ram=B.from_buffer_copy(before);nvic=U32(int.from_bytes(bytes.fromhex(t['nvic_before']),'little'))
 if t['op']==2:l.rr_mouse_adaptive_request(ram,t['phase'],t['channel'],t['reason'],C.byref(nvic));rc=0
 elif t['op']==1:rc=l.rr_mouse_adaptive_irq(ram)
 else:rc=l.rr_mouse_adaptive_run(ram,t['peer'],t['phase'],t['channel'])
 result=bytes(ram);counts[f"op{t['op']}:phase{t['phase'] if t['phase']<=2 else 'other'}"]+=1
 if result!=expected or nvic.value.to_bytes(4,'little').hex()!=t['nvic_after'] or rc:
  dif=[f'{i:04x}:{result[i]:02x}!={expected[i]:02x}' for i in range(65536) if result[i]!=expected[i]]
  fails.append({'case':t['case'],'rc':rc,'ram_differences':dif[:24]})
 if t['phase']==0:
  b=0x2978+t['peer']*0xee0
  if expected[b+0x15e]!=before[b+0x15e]:reports['enqueue_success']+=1
  if expected[0x2936:0x2938]!=before[0x2936:0x2938]:reports['ready_consumed']+=1
  if expected[0x2854:0x2932]==bytes(0xde) and before[0x2854:0x2932]!=bytes(0xde):reports['statistics_cleared']+=1
for peer,ch in [(2,0),(0,256)]:
 ram=B(*([0x91]*65536));snap=bytes(ram);assert l.rr_mouse_adaptive_run(ram,peer,0,ch)==-1 and bytes(ram)==snap
assert l.rr_mouse_adaptive_run(None,0,0,0)==-1
out={'status':'PASS' if not fails else 'FAIL','original_instruction_cases':len(rows),'counts':dict(counts),'report_effects':dict(reports),'failures':fails,'boundary_preflight_checks':3,'checks':['all65536 RAM bytes','software pending IRQ word','actual enqueue and memset executed in original image'],'sources':{str(f.relative_to(R)):hashlib.sha256(f.read_bytes()).hexdigest() for f in sources+[P/'mouse_adaptive_control.h',Path(__file__),R/'ghidra-scripts/EmulateMouseAdaptive.java',A/'mouse-adaptive-original.jsonl']},'limits':['serialized software simulation, not actual radio IRQ or concurrent queue','channel0..255 and peer0/1 domain; caller ring layout must be valid','no RF quality/timing or authentication proof']}
(A/'mouse-adaptive-comparison.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n')
print(json.dumps({k:v for k,v in out.items() if k!='sources'},ensure_ascii=False,indent=2));assert not fails
