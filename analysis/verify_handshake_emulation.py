"""Compare reconstructed 0x11 producer to retained ORIGINAL instruction runs."""
from pathlib import Path
import hashlib
import json
from handshake_codec import dongle_offer, next_sequence

root = Path(__file__).parent
source = root / 'handshake-original-emulation.jsonl'
records = [json.loads(line) for line in source.read_text().splitlines()]
assert len(records) == 128
assert len({r['case'] for r in records}) == 128
for r in records:
    packet = dongle_offer(bytes([0xa5]*12), sequence=r['sequence'],slot=r['slot'],
                         base1=r['base1'], capabilities=r['capabilities'],
                         flag7=bool(r['flag7']), flag6=bool(r['flag6']),
                         event_counter=r['event_counter'])
    assert packet.hex() == r['packet_hex'], (r['case'],packet.hex(),r['packet_hex'])
    assert next_sequence(r['sequence']) == r['next_sequence']
result = {'status':'PASS','cases':len(records),'function':'dongle 0x23022360',
          'engine':'Ghidra 12.1.3 AdaptedEmulator (modern p-code)',
          'sha256':hashlib.sha256(source.read_bytes()).hexdigest(),
          'checked':['all 12 produced bytes','sequence advancement'],
          'limits':['software emulation, not silicon execution','one packet producer only',
                    'not PHY/radio/timing/peer interoperability validation',
                    'other five message types have static byte-write tests, not this emulation']}
(root / 'handshake-emulation-comparison.json').write_text(json.dumps(result,indent=2))
print('PASS: 128 original-instruction cases match reconstructed 0x11 bytes and next sequence')
