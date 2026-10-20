#!/usr/bin/env python3
"""Summarize observed outcomes of original instruction records, not exhaustive branch coverage."""
import json,gzip,base64,collections
from pathlib import Path
B=Path(__file__).resolve().parent;c=collections.Counter()
for name in ['mouse-mode4-tx-original.jsonl','mouse-mode4-tx-special-original.jsonl']:
 for ln in (B/name).open():
  d=json.loads(ln);r=gzip.decompress(base64.b64decode(d['before_gzip']));s=gzip.decompress(base64.b64decode(d['after_gzip']));c['cases']+=1
  prepared=int.from_bytes(bytes.fromhex(d['radio_after'])[0xed0:0xed4],'little')==0x23002650
  if prepared:
   c['prepared_dma']+=1
   special=s[0x2650:0x2653]==bytes([2,85,0]);c['special_02_55_00' if special else 'normal_checksum']+=1
   c['tx_state' if int.from_bytes(s[0x2a04:0x2a08],'little')==25 else 'deadline_cancel']+=1
   if not special:
    c['selected_q_'+str(int.from_bytes(s[0x2a1a:0x2a1c],'little'))]+=1
    if s[0x2650] in [0,17,32]:c['normal_wire_length_0_17_32']+=1
  else:c['no_packet_prepared']+=1
  if s[0x2add]!=r[0x2add]:c['motion_popped']+=1
result={'status':'observed_original_outcomes','counts':dict(c),'limits':['Outcome counts are not all-branch coverage','Length0 here may be original byte255+1 wrap; no validity claim']}
assert c['cases']==4352 and c['special_02_55_00']==128
(B/'mouse-mode4-tx-coverage.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result,indent=2))
