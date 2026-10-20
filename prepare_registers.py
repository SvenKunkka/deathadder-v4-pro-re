from pathlib import Path
import xml.etree.ElementTree as ET

root = Path(__file__).parent
xml = ET.parse(root / 'downloads/nordic/nrf54h20_radiocore.svd').getroot()
peripherals = {p.findtext('name'): p for p in xml.findall('./peripherals/peripheral')}
lines = []
for name, peripheral in peripherals.items():
    if not name.startswith(('RADIO_', 'TIMER02', 'DPPIC02', 'CCM03', 'EGU02', 'BELLBOARD')):
        continue
    definition = peripheral
    while definition.get('derivedFrom'):
        definition = peripherals[definition.get('derivedFrom')]
    base = int(peripheral.findtext('baseAddress'), 0)
    size = int(definition.findtext('addressBlock/size'), 0)
    lines.append(f'B\t{name}\t{base:x}\t{size:x}')
    for reg in definition.findall('./registers/register'):
        offset = int(reg.findtext('addressOffset'), 0)
        count = int(reg.findtext('dim', '1'), 0)
        inc = int(reg.findtext('dimIncrement', '0'), 0)
        for index in range(count):
            label = reg.findtext('name').replace('[%s]', f'_{index}').replace('%s', str(index))
            lines.append(f'R\t{name}_{label}\t{base+offset+index*inc:x}\t4')
(root / 'analysis/registers.tsv').write_text('\n'.join(lines)+'\n')
print(f'Prepared {len(lines)} block/register entries')
