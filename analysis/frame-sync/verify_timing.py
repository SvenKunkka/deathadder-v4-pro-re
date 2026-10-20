"""Compare bounded original Thumb executions with independent timing semantics.

MMIO is inert memory here: validates writes, not running timer/USB/RF behavior.
No external-function success is injected. Original return is required.
"""
import base64
import gzip
import hashlib
import json
import struct
from pathlib import Path

HERE = Path(__file__).resolve().parent


def get(b, o):
    return struct.unpack_from('<I', b, o)[0]


def put(b, o, v):
    struct.pack_into('<I', b, o, v & 0xffffffff)


def signed(v):
    return v if v < 0x80000000 else v - 0x100000000


def model(row, ram, timer, nvic):
    if row['family'] == 0:
        for i in range(6):
            put(timer, 0x540 + 4*i, 0)
        put(timer, 0x200, get(timer, 0x200) & 0xff00ff00)
        put(timer, 0x308, 0xff0000)
        rate = ram[0x4a5f]
        schedule = [(0,90),(1,215),(2,340),(3,465)] if rate == 1 else [(0,10),(3,260)] if rate == 2 else [(3,10)]
        for channel, value in schedule:
            bits = (1 << channel) | (0x10000 << channel)
            put(timer, 0x200, (get(timer, 0x200) & ~bits) | 0x80008)
            put(timer, 0x140 + 4*channel, 0)
            put(timer, 0x304, 0x10000 << channel)
            put(timer, 0x540 + 4*channel, (value * 16) >> get(timer, 0x510))
    elif row['family'] == 1:
        if ram[0x774b]:
            put(timer, 12, 1)
            put(timer, 0, 1)
    else:
        if int.from_bytes(ram[0x3230:0x3232], 'little') == 5:
            return
        assert ram[0x3250] == 0 and ram[0x3256] == 0, 'fixture outside returning calibration slice'
        if not ram[0x3258]:
            return
        if ram[0x325a]:
            for offset in (0x184, 0x284, 0x104):
                put(nvic, offset, 0x100)
            put(timer, 12, 1)
            put(timer, 0, 1)
            ram[0x325a:0x325d] = bytes([0, 1, 0])
            put(ram, 0x3264, 0)
        elif ram[0x325b]:
            value = (get(ram, 0x3264) + 1) & 0xffffffff
            put(ram, 0x3264, value)
            if signed(value) > 32:
                put(ram, 0x325a, 0x10000)
        elif ram[0x325c]:
            phase = get(timer, 0x55c)
            if 1761 <= phase <= 3359:
                put(ram, 0x3278, get(ram, 0x3278) + 1)
                put(ram, 0x3270, get(ram, 0x3270) + phase)
            if signed(get(ram, 0x3278)) > 31:
                average = (signed(get(ram, 0x3270)) >> 5) & 0xffffffff
                if average > 2560 and average - 2560 > 31:
                    put(timer, 0x540, get(timer, 0x540) + 32)
                elif average < 2560 and 2560 - average > 31:
                    put(timer, 0x540, get(timer, 0x540) - 32)
                put(ram, 0x3270, 0)
                put(ram, 0x3278, 0)


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    results = []
    for name, expected in [('mouse', 304), ('receiver', 160)]:
        path = HERE / f'{name}-timing-original.jsonl'
        rows = [json.loads(line) for line in path.read_text().splitlines()]
        assert len(rows) == expected
        steps = 0
        for row in rows:
            blocks = {key: bytearray(gzip.decompress(base64.b64decode(row[key+'_before']))) for key in ('ram','timer','nvic')}
            model(row, **blocks)
            for key, block in blocks.items():
                actual = gzip.decompress(base64.b64decode(row[key+'_after']))
                if block != actual:
                    differences = [hex(i) for i,(a,b) in enumerate(zip(block,actual)) if a!=b]
                    raise AssertionError((name,row['case'],key,differences[:40]))
            assert row['boundary'] == 0 and row['end_pc'] == 0x2302df00
            assert row['initial_priority'] == row['final_priority']
            steps += row['steps']
        results.append({'target':name,'cases':len(rows),'original_steps':steps,'original_returns':len(rows),'dataset_sha256':digest(path)})
    out = {'status':'PASS','cases':sum(r['cases'] for r in results),'original_steps':sum(r['original_steps'] for r in results),'results':results,'comparison':'entire 128 KiB RAM, 4 KiB TIMER, 4 KiB NVIC and unchanged BASEPRI','limits':['Static MMIO, explicit CC7 input, no timer progression or USB/RF edges','Bounded function executions; no end-to-end scheduler or physical sensor model','Does not verify sensor frame formation, latency or hardware synchronization precision'],'verifier_sha256':digest(Path(__file__)), 'harness_sha256':digest(HERE.parents[1]/'ghidra-scripts/EmulateFrameSync.java')}
    (HERE/'timing-comparison.json').write_text(json.dumps(out,indent=2)+'\n')
    print(json.dumps(out,indent=2))


if __name__ == '__main__':
    main()
