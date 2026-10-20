import ctypes as C,json,hashlib,collections
from pathlib import Path
import verify_mouse_work_queue as common
R=common.R;A=common.A;P=common.P;U=common.U;W=common.W;Ptr=common.Ptr;CPU=common.CPU;f=common.f
class Pending(C.Structure):_fields_=[('active',W),('entry',W),('args',W*4)]
f.rr_mouse_mode4_timer_rtos.argtypes=[Ptr,Ptr,Ptr,Ptr,Ptr,Ptr,C.POINTER(W),C.POINTER(W),C.POINTER(CPU),C.POINTER(Pending)]
flash=common.buf((R/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin').read_bytes());fails=[]
rows=[json.loads(x) for x in (A/'mouse-mode4-rtos-original.jsonl').read_text().splitlines()];assert len(rows)==512
for t in rows:
 before={'ram':common.un(t['before_gzip']),'rtc':common.un(t['rtc_before']),**{x:bytes.fromhex(t[x+'_before']) for x in ['radio','timer','spim','clock','nvic']}}
 want={'ram':common.un(t['after_gzip']),'rtc':common.un(t['rtc_after']),**{x:bytes.fromhex(t[x+'_after']) for x in ['radio','timer','spim','clock','nvic']}}
 m={k:common.buf(v) for k,v in before.items()};pending=Pending();cpu=CPU(t['initial_priority'],60,0,0)
 rc=f.rr_mouse_mode4_timer_rtos(m['ram'],m['radio'],m['timer'],m['spim'],flash,m['rtc'],C.cast(m['clock'],C.POINTER(W)),C.cast(m['nvic'],C.POINTER(W)),C.byref(cpu),C.byref(pending));errors=[]
 for k in m:errors+=common.diff(k,bytes(m[k]),want[k])
 if rc or pending.active or pending.entry or cpu.entry or cpu.priority!=t['final_priority']:errors.append({'return':rc,'pending':(pending.active,pending.entry),'CPU':(cpu.priority,cpu.entry),'expected_priority':t['final_priority']})
 if errors:fails.append({'case':t['case'],'errors':errors})
paths=common.files+[P/'mouse_work_queue.h',P/'mouse_timer_start.h',Path(__file__),R/'ghidra-scripts/EmulateMouseMode4Rtos.java',A/'mouse-mode4-rtos-original.jsonl']
report={'status':'PASS' if not fails else 'FAIL','original_cases':len(rows),'full_instruction_returns':len(rows),'original_steps':sum(t['steps'] for t in rows),'original_work_calls':sum(t['work_calls'] for t in rows),'original_timer_start_calls':sum(t['timer_start_calls'] for t in rows),'failures':fails,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'limits':['Whole mode4 TIMER timeout -> work submission -> timer-start returns, allRAM/RADIO/TIMER/SPIM/clock/NVIC/RTC snapshots compared','Explicit interrupt mode prevents actual thread switch; direct work cases separately retain true switch boundary','Work queued and callback registered; future worker/expiry callback execution not implied','No autonomous hardware or actual RF/device behavior']}
(A/'mouse-mode4-rtos-comparison.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k not in ['sources','failures']},indent=2));print(json.dumps(fails[:8],indent=2));assert not fails
