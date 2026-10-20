"""Freeze the original-image evidence for the RF -> sampling scheduler bridge."""
import hashlib
import json
import xml.etree.ElementTree as ET
from pathlib import Path

F = Path(__file__).resolve().parent
R = F.parents[1]
M = R/'analysis/mouse-radio-1.20-final'
image_path = R/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin'
blob = image_path.read_bytes()
sha = lambda b: hashlib.sha256(b).hexdigest()
assert sha(blob) == 'c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48'
asm = [(int(line[:8],16),n,line) for n,line in enumerate((M/'disassembly.txt').read_text().splitlines(),1)]
ranges = [
    (0x23021800,0x230218a0,'RADIO ADDRESS publishes DPPI channel 6; CAPTURE7 subscribes'),
    (0x23022e28,0x23022f70,'Radio timer initialization and prescaler 5'),
    (0x2302516c,0x23025778,'Mode4 timer: phase correction and CC0 tailcall to 25F48'),
    (0x23025f48,0x23025f64,'Timer134 CLEAR and START plus literals'),
    (0x23026bd0,0x23026ca4,'Wireless sampling decimation configuration'),
    (0x23026ca4,0x23026ce0,'Report callback dispatch: wireless tailcall 288D0'),
    (0x23026d90,0x23026da0,'Report work registration and literals'),
    (0x23026da0,0x23026e98,'Sensor read callback and movement accumulation'),
    (0x23028760,0x23028820,'Sampling tick: motion input, deferred work, Timer132 start'),
    (0x230288d0,0x23028ad4,'Wireless publisher: class1 six-byte enqueue at 28970 and accumulator reset'),
    (0x23029ca4,0x23029d04,'Timer channel configuration helper'),
    (0x23029e1c,0x23029e88,'Timer nominal microseconds conversion helper'),
    (0x23029e88,0x23029f6c,'Timer frequency and prescaler helper'),
    (0x2302a718,0x2302a71c,'Sensor-work thunk to 26DA0'),
    (0x2302a74c,0x2302a75c,'Sensor work registration and literals'),
    (0x2302b3d0,0x2302b4a8,'Timer134 IRQ and sampling dispatch'),
    (0x2302b890,0x2302b934,'Timer134 initialization at 16 MHz'),
    (0x2302ba74,0x2302bb64,'Timer134 compare schedule'),
    (0x0e099248,0x0e099250,'Timer134 descriptor base')]
records = []
for start,end,purpose in ranges:
    offset = start-0x23020000+0x79c if start>=0x23020000 else start-0x0e06c000
    data = blob[offset:offset+end-start]
    assert len(data)==end-start
    records.append({'start':hex(start),'end_exclusive':hex(end),'file_offset':hex(offset),'purpose':purpose,'bytes':data.hex(),'sha256':sha(data),'assembly':[{'line':n,'text':s} for a,n,s in asm if start<=a<end]})
source_names = ['23021800','230218a0','23022e28','2302516c','23026bd0','23026ca4','23026d90','23026da0','23028760','23029ca4','23029e1c','23029e88','2302a74c','2302b3d0','2302b890','2302ba74']
sources = [M/(n+'.c') for n in source_names if (M/(n+'.c')).exists()]
sources += [M/'disassembly.txt',image_path,R/'recovered-code/portable/mouse_mode4_radio.c',R/'recovered-code/portable/receiver_radio_irq.c',R/'analysis/dongle-radio-1.20-final/2302206c.c',R/'downloads/nordic/nrf54h20_application.svd',R/'downloads/nordic/nrf54h20_radiocore.svd']
root = ET.parse(R/'downloads/nordic/nrf54h20_application.svd')
peripherals = {p.findtext('name'):p for p in root.findall('.//peripheral')}
p = peripherals['GLOBAL_TIMER134_S']
assert int(p.findtext('baseAddress'),16)==0x5f9c2000
shorts = next(x for x in peripherals[p.attrib['derivedFrom']].findall('.//register') if x.findtext('name')=='SHORTS')
fields = {f.findtext('name'):int(f.findtext('lsb')) for f in shorts.findall('.//field')}
assert fields['COMPARE3_CLEAR']==3 and fields['COMPARE3_STOP']==19
out = {'target':'DeathAdder V4 Pro official 1.20, wireless mode4 bounded path','firmware_sha256':sha(blob),'raw_evidence':records,'sources':[{'path':str(p.relative_to(R)),'sha256':sha(p.read_bytes())} for p in sources],'register_correction':{'address':'0x5F9C2000','actual':'GLOBAL_TIMER134_S','historical_variable':'spim / s in mouse_mode4_radio.c','shorts_0x80008':['COMPARE3_CLEAR','COMPARE3_STOP']},'nominal_clocks':{'mouse_radio':'32 MHz / 2^5 = 1 MHz','receiver_radio':'32 MHz / 2^0 = 32 MHz','mouse_timer134':'16 MHz, prescaler 0','limitation':'code/SVD-derived nominal units, not measured clocks or ISR latency'},'timing_oracle':'timing-comparison.json','limits':['Original bytes and exports support static control/data-flow; not an end-to-end execution','Timer134 is started by software in the radio timer ISR; relative offset includes ISR delay','Work submission, sensor read, report enqueue and radio transmission are distinct events','Sensor exposure/frame formation remains unknown']}
(F/'radio-sampling-map.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n')
for rec in records:
    off=int(rec['file_offset'],16)
    assert sha(blob[off:off+len(bytes.fromhex(rec['bytes']))])==rec['sha256']
print(json.dumps({'raw_spans':len(records),'source_hashes':len(sources),'status':'PASS'}))
