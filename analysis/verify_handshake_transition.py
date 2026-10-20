"""Compare reconstruction with actual original-instruction software execution."""
from pathlib import Path
from collections import Counter
import json,hashlib
from dongle_handshake_transition import transition
root=Path(__file__).resolve().parent
source=root/'handshake-transition-original.jsonl'
rows=[json.loads(x) for x in source.read_text().splitlines()]
assert len(rows)==640, len(rows)
coverage=Counter(); failures=[]
for row in rows:
    before=bytes.fromhex(row['before']);incoming=bytes.fromhex(row['incoming'])
    args={k:row[k] for k in ['slot','status0','status1','primary_cap','fallback_cap',
                            'selector','index0','index1','extra']}
    args.update(frequencies=bytes.fromhex(row['frequencies']),mask=bytes.fromhex(row['mask']),
                selected_mode=row['selected_before'])
    actual=transition(before,incoming,**args)
    expected=bytes.fromhex(row['after'])
    differing=[hex(i) for i,(a,b) in enumerate(zip(actual.memory,expected)) if a!=b]
    if differing or actual.selected_mode!=row['selected_after'] or actual.result!=row['return']:
        failures.append({'case':row['case'],'memory_offsets':differing,
                         'selected':[actual.selected_mode,row['selected_after']],
                         'return':[actual.result,row['return']]})
    state=int.from_bytes(before[0xc8:0xca],'little')
    coverage[f'state_{state}_return_{row["return"]}']+=1
result={'status':'PASS' if not failures else 'FAIL','cases':len(rows),
        'function':'dongle 0x230223f0','engine':'Ghidra 12.1.3 AdaptedEmulator',
        'source_sha256':hashlib.sha256(source.read_bytes()).hexdigest(),
        'checked':['all 224 bytes of selected slot state','global selected mode','return value'],
        'coverage':dict(coverage),'failures':failures,
        'limits':['state3 with nonzero notification flag excluded',
                  'software execution only; no real radio/interrupt scheduling',
                  'no claim exhaustive full-state-space coverage']}
(root/'handshake-transition-comparison.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(result,indent=2));assert not failures
