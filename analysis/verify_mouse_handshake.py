from pathlib import Path
from collections import Counter
import json,hashlib
from mouse_handshake_transition import transition
r=Path(__file__).resolve().parent;p=r/'mouse-handshake-original.jsonl'
rows=[json.loads(x) for x in p.read_text().splitlines()];assert len(rows)==256
fail=[];coverage=Counter()
for row in rows:
 before=bytes.fromhex(row['before']);expected=bytes.fromhex(row['after'])
 actual,regs=transition(before,event=row['event'],crc_ok=row['crc_ok'],channel=row['channel'])
 diff=[hex(0x23002688+i) for i,(a,b) in enumerate(zip(actual,expected)) if a!=b]
 regdiff=[hex(a) for a,v in regs.items() if v!=int.from_bytes(bytes.fromhex(row['registers_after'][f'{a:x}']),'little')]
 if diff or regdiff:fail.append({'case':row['case'],'ram':diff,'registers':regdiff})
 state=int.from_bytes(expected[0x37c:0x380],'little');coverage[f'output_state_{state:#x}']+=1
 if state in (0x16,0x17):coverage[f'reply_{expected[0x3d1]:#x}']+=1
result={'status':'PASS' if not fail else 'FAIL','cases':len(rows),'coverage':dict(coverage),'failures':fail,
 'source_sha256':hashlib.sha256(p.read_bytes()).hexdigest(),
 'checked':['all 992 RAM-window bytes','15 selected register words'],
 'limits':['inert MMIO memory, no hardware peripheral state evolution',
           'pairing flag zero; no terminal state0x17 execution',
           'software execution, no RF/interrupt timing validation']}
(r/'mouse-handshake-comparison.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(result,indent=2));assert not fail
