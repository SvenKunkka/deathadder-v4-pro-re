"""Offline consistency tests only; no claim of hardware or air-protocol validation."""
import json, pathlib, random, struct
import dongle_radio_algorithms as alg

ROOT=pathlib.Path(__file__).resolve().parents[1]
IMAGE=ROOT/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin'
b=IMAGE.read_bytes()
lut=b[0x0E06FB74-0x0E054000:0x0E06FB74-0x0E054000+16]
freq=b[0x0E06FB84-0x0E054000:0x0E06FB84-0x0E054000+40]
assert tuple(freq)==alg.FREQUENCY_OFFSETS_MHZ
assert list(lut)==[0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15]

def literal_permutation(x):
    return lut[(x>>4)&15] | lut[x&15]<<4 | lut[(x>>8)&15]<<12 | lut[x>>12]<<8

for x in range(65536):assert alg.reverse_bits_within_each_byte(x)==literal_permutation(x)

def instruction_formula(counter,base,mask):
    # Direct rendering of the observed three function calls in0x23021534,
    # separately preserving the nibble table and target's scalar operations.
    ident=(base&65535)^(base>>16)
    x=literal_permutation((counter^ident)&65535)
    x=literal_permutation((ident+((x*17)&65535))&65535)
    x=literal_permutation((ident+((x*17)&65535))&65535)
    prn=ident^((ident+((x*17)&65535))&65535)
    remap=[i for i in range(37)if mask&(1<<i)]
    channel=prn%37
    if not mask&(1<<channel):channel=remap[(prn*len(remap))>>16]
    return prn,channel

randomizer=random.Random(120)
for _ in range(5000):
    counter=randomizer.randrange(65536);base=randomizer.randrange(1<<32);mask=randomizer.randrange(1,1<<37)
    got=alg.select_channel(counter,base,mask);expected=instruction_formula(counter,base,mask)
    assert (got['prn'],got['channel'])==expected
assert alg.crc16_ccitt(b'123456789')==0x29B1
assert alg.crc16_ccitt(b'')==0xFFFF
assert alg.additive_checksum(bytes([0x11,0x22,0x33]))==0x9A
vectors=[]
for base,mask in [(0x12345678,(1<<37)-1),(0x12345678,0x100001),(0xEB8A542C,(1<<37)-1),(0x89ABCDEF,1<<22)]:
    for counter in (0,1,2,15,255,65535):
        vectors.append({'event_counter':counter,'base1':hex(base),'enabled_mask':hex(mask),'expected':alg.select_channel(counter,base,mask)})
out={'scope':'Static formula consistency; no target execution or RF validation',
     'permutation_cases':65536,'channel_formula_cases':5000,
     'crc_reference':'123456789 ->0x29B1',
     'vectors':vectors}
(ROOT/'analysis/dongle-radio-algorithm-test-vectors.json').write_text(json.dumps(out,indent=2)+'\n')
print('PASS:65536 permutation cases,5000 channel formula cases,CRC/checksum known values;24 fixed channel vectors saved')
