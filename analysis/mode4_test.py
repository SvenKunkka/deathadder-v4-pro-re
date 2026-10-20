"""Offline consistency/boundary tests; not RF or target-execution validation."""
import json
from pathlib import Path
from mode4_codec import *

count=0

def eq(a,b):
    global count
    assert a==b,(a,b)
    count+=1

def rejects(f):
    global count
    try: f()
    except ValueError: count+=1; return
    raise AssertionError("expected rejection")

vectors=[("00","0100"),("0100","020000"),("01ff","02ff01"),
         ("05b203171234","06b203171234ee"),("08010801ff0001ffff","09010801ff0001fffff8")]
for src,wire in vectors:
    eq(encode_mouse_uplink(bytes.fromhex(src)).hex(),wire)
    eq(decode_mouse_uplink(bytes.fromhex(wire),hardware_crc_ok=True).hex(),src)
    rejects(lambda:decode_mouse_uplink(bytes.fromhex(wire),hardware_crc_ok=False))
    rejects(lambda:decode_mouse_uplink(bytes.fromhex(wire)[:-1],hardware_crc_ok=True))
# Independent arithmetic identity and every possible one-byte payload.
for v in range(256):
    wire=encode_mouse_uplink(bytes([1,v]))
    eq(wire,bytes([2,v,(-v)%256]))
    eq(sum(wire[1:])%256,0)
# Every nonzero single-byte corruption of data/checksum must be rejected.
wire=bytes.fromhex("06b203171234ee")
for i in range(1,len(wire)):
    for delta in range(1,256):
        b=bytearray(wire);b[i]=(b[i]+delta)&255
        rejects(lambda b=b:decode_mouse_uplink(bytes(b),hardware_crc_ok=True))
# Additive checksum's limitation: balanced corruption can pass. Preserve evidence.
b=bytearray(wire);b[1]+=1;b[2]-=1
eq(decode_mouse_uplink(bytes(b),hardware_crc_ok=True).hex(),"05b302171234")
rejects(lambda:decode_mouse_uplink(bytes.fromhex("025500"),hardware_crc_ok=True))
eq(make_mouse_status(3,3,0x1234,2).hex(),"06b203171234ee")
eq(make_dongle_sync(0xc0,3,0x1234).hex(),"05c0031f1234")
eq(mouse_header(1,7,100),0xff)
eq(dongle_header(1,1,0),0xc0)
for tick,expected in [(0,9),(165,9),(166,0x1234),(249,0x1234),(250,9),
                       (415,9),(416,0x1235),(499,0x1235),(500,9),(0xffffffff,9)]:
    eq(sync_counter(9,0x1234,tick),expected)
eq(sync_counter(9,65535,416),0)
for slot,cut,low,high in [(0,99,False,True),(1,100,True,False),
                         (3,250,True,False),(4,350,True,False)]:
    eq(tx_guard(slot,cut),low);eq(tx_guard(slot,cut+1),high)
a,f=MotionAccumulator().add(bytes.fromhex("08010801ff0001ffff"))
a,f=a.add(bytes.fromhex("08010802020002ffff"))
eq(f.hex(),"08010803010003fffe")
eq(a.on_crc_ok_downlink(),MotionAccumulator())
eq(next_sequence(7),1);eq(next_sequence(0),1)
r=dongle_sequence_transition(2,2,1,7)
eq((r['pop_selected_queue'],r['tx_sequence'],r['reset_link_miss_counter']),(False,7,False))
r=dongle_sequence_transition(2,3,1,7)
eq((r['pop_selected_queue'],r['tx_sequence'],r['reset_link_miss_counter']),(True,1,True))
r=dongle_sequence_transition(2,3,255,7)
eq((r['pop_selected_queue'],r['tx_sequence']),(False,7))
result={"status":"passed","assertions":count,"single_byte_corruptions_rejected":1530,
        "one_byte_payloads_exhaustive":256,"fixed_vectors":vectors,
        "scope":"Static reconstruction consistency only; no RF capture, emulation or target execution."}
Path(__file__).with_name('mode4_test_results.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(result,indent=2))
