"""Offline branch-boundary and original-byte checks; not an RF test."""
from pathlib import Path
from dataclasses import replace
import json
from mode4_special_behavior import SpecialInput,select_special,receiver_special_result
n=0

def ck(v):
    global n
    assert v
    n+=1

s=SpecialInput()
ck(select_special(s)['armed'])
for slot,tick,armed in [(0,99,False),(0,100,True),(0,470,True),(3,250,True),(3,251,False)]:
    r=select_special(replace(s,slot=slot,capture7=tick))
    ck(r['built'] and r['armed']==armed)
for field,values in {'radio_state':[0x19,0x1a,0], 'handler_event':[1,6,8],
                     'protocol_mode':[1,2], 'slot':[1,2,4,5], 'interval':[2,4,8],
                     'cached_motion':[1], 'retry_holdoff':[1,2]}.items():
    for value in values:ck(not select_special(replace(s,**{field:value}))['built'])
for state in range(8):
    for count in range(256):
        ck(select_special(replace(s,link_state=state,idle_channel_count=count))['built']
           == (count<(4 if state==3 else 16)))
for q in range(6):
    indices=[0]*6;indices[q]=1
    ck(not select_special(replace(s,read_indices=tuple(indices)))['built'])
for crc in [False,True]:
    r=receiver_special_result(hardware_crc_ok=crc)
    ck(not r['accepted'] and not r['notification_called'] and not r['miss_counter_reset'])
ck((-0x55)&255 == 0xab)
base=Path(__file__).parent
raw=(base/'runtime-images/mouse-ram-1.20.bin').read_bytes()
checks={0x23024a28:'45f20256',0x23024a34:'0022',0x23024a3a:'9a70',0x23024a42:'1e80',
        0x23024a44:'c2f8d03e',0x23024e84:'032b'}
for addr,h in checks.items():
    data=bytes.fromhex(h);ck(raw[addr-0x23020000:addr-0x23020000+len(data)]==data)
result={'status':'passed','assertions':n,'original_instruction_spans_checked':len(checks),
        'scope':'static branch model and existing RAM bytes; no target execution or RF validation'}
(base/'mode4_special_test_results.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(result))
