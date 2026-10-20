from pathlib import Path
import ctypes as C,json,hashlib,base64,gzip
import verify_receiver_rtos_lifecycle as common
R=common.R;A=common.A;P=common.P;U=common.U;W=common.W;CPU=common.CPU
class HW(C.Structure):_fields_=[('radio',W*1024),('timer',W*512),('aux',W*512),('nvic_last',W),('nvic_requests',W)]
f=common.f;f.rr_receiver_timer_mode4_lifecycle.argtypes=[common.Ptr,common.Ptr,C.POINTER(HW),C.POINTER(CPU),common.Ptr]
flash=common.buf((R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes());rows=[json.loads(s) for s in (A/'receiver-disconnect-lifecycle-original.jsonl').read_text().splitlines()];assert len(rows)==256
fails=[]
for t in rows:
 m=common.buf(common.un(t['before_gzip']));h=HW();C.memmove(h.radio,common.un(t['radio_before_gzip']),4096);C.memmove(h.timer,common.un(t['timer_before_gzip']),2048);h.nvic_last=0x12345678;cpu=CPU(t['initial_priority'],60,0,0)
 rc=f.rr_receiver_timer_mode4_lifecycle(m,flash,C.byref(h),C.byref(cpu),common.buf(bytes.fromhex(t['opaque_tail'])));errors=[]
 for name,actual in [('after',bytes(m)),('radio_after',bytes(h.radio)),('timer_after',bytes(h.timer)),('aux_after',bytes(h.aux))]:
  expected=common.un(t[name+'_gzip'])
  if expected!=actual:
   ds=[i for i in range(len(expected)) if expected[i]!=actual[i]];errors.append({'window':name,'count':len(ds),'first':[(hex(i),actual[i],expected[i]) for i in ds[:8]]})
 if rc or cpu.entry or cpu.priority!=t['final_priority']:errors.append({'return':rc,'entry':cpu.entry,'priority':cpu.priority})
 if errors:fails.append({'case':t['case'],'errors':errors})
paths=common.files+[P/'receiver_rtos_lifecycle.h',Path(__file__),R/'ghidra-scripts/EmulateReceiverDisconnectLifecycle.java',A/'receiver-disconnect-lifecycle-original.jsonl']
report={'status':'PASS' if not fails else 'FAIL','original_cases':256,'full_instruction_returns':256,'original_steps':sum(t['steps'] for t in rows),'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['24 uninitialized notification tail bytes observed at original callsite supplied explicitly to C; CPU stack residue generation itself NOT reconstructed','timer -> actual semaphore/waiter-ready operations -> actual notification queue executed, no successful stubs','active timeout, timeslice start, true thread-mode context switch excluded from these256 inputs; separately boundary-tested','MMIO snapshots, no IRQ preemption/time/PHY']}
(A/'receiver-disconnect-lifecycle-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']},indent=2));print(json.dumps(fails[:5],indent=2));assert not fails
