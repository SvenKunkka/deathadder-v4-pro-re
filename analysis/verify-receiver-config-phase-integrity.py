from pathlib import Path
import json,hashlib,re
R=Path(__file__).resolve().parent.parent;A=R/'analysis';errors=[]
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1048576),b''):h.update(b)
 return h.hexdigest()
def check(p,w):
 if not p.is_file():errors.append('missing '+str(p))
 elif sha(p)!=w:errors.append('hash '+str(p))
s=json.loads((A/'recovered-code-validation-summary.json').read_text())
for k in ['sources','libraries']:
 for rel,h in s[k].items():check(R/rel,h)
for name,d in s['datasets'].items():check(A/name,d['sha256'])
for name,h in s['verification_results'].items():
 check(A/name,h);v=json.loads((A/name).read_text())
 if v.get('status') not in ['PASS','pass',None]:errors.append('result '+name)
 for key in ['sources','code_sha256','source_hashes','sha256']:
  for rel,value in v.get(key,{}).items():
   if (R/rel).is_file():check(R/rel,value)
for field in ['business_exchange_integration','adaptive_integration','receiver_irq_integration','receiver_timer_integration','mouse_mode4_integration','mouse_mode4_tx_integration','mouse_mode4_runtime_integration','mouse_mode4_runtime_host_boundaries']:
 if field in s:check(A/s[field]['file'],s[field]['sha256'])
for rel in ['逆向进度与代码入口.md','recovered-code/portable/README.md','analysis/mouse-timer-lifecycle-exact.md','analysis/receiver-radio-timer-exact.md','analysis/mouse-mode4-exact.md','analysis/receiver-other-modes-map.md','analysis/mouse-mode4-tx-exact.md','analysis/receiver-legacy-business-exact.md','analysis/receiver-rtos-lifecycle-exact.md','analysis/receiver-timeout-exact.md','analysis/mouse-mode4-runtime-exact.md','analysis/receiver-legacy-radio-exact.md']:
 p=R/rel
 if not p.is_file():errors.append('missing report '+rel);continue
 for url in re.findall(r'\]\(([^)]+)\)',p.read_text()):
  if '://' not in url and not url.startswith('#') and not (p.parent/url.split('#')[0]).exists():errors.append('broken link '+rel+' '+url)
fw=(R/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin').read_bytes();m=json.loads((A/'mouse-timer-lifecycle-exact.json').read_text())
assert hashlib.sha256(fw).hexdigest()==m['firmware_sha256']
for e in m['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('mouse raw span '+e['address'])
x=json.loads((A/'receiver-other-modes-map.json').read_text());fw=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes()
for e in x['entry_evidence']:
 o=int(e['firmware_offset'],16)
 if fw[o:o+16].hex()!=e['first16_hex']:errors.append('receiver route span '+e['address'])
fw=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes()
x=json.loads((A/'receiver-rtos-lifecycle-exact.json').read_text())
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('RTOS raw span '+e['address'])
for name in ['receiver-timeout-exact.json']:
 x=json.loads((A/name).read_text())
 for e in x['entry_spans']:
  o=int(e['image_offset'],16)
  if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('timeout raw span '+e['address'])
x=json.loads((A/'mouse-mode4-runtime-exact.json').read_text())
for rel,h in x['hashes'].items():check(R/rel,h)
# Stage1 freeze is historical. Revision2 binds current q255 code and regression.
x=json.loads((A/'receiver-legacy-radio-revision2.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
for name in ['receiver-timeout-exact.json','receiver-rtos-lifecycle-exact.json']:
 x=json.loads((A/name).read_text())
 for key in ['direct_timeout','rtos_timed','disconnect_timed','rtos_comparison','disconnect_comparison']:
  for rel,h in x.get(key,{}).get('sources',{}).items():check(R/rel,h)

# Current work/timer phase: source-bound static evidence, not new execution cases.
for name in ['mouse-timer-start-exact.json','receiver-legacy-timer-exact.json','mouse-work-expiry-map.json']:
 x=json.loads((A/name).read_text())
 for rel,h in x.get('sources',{}).items():check(R/rel,h)
for name in ['receiver-legacy-timer-freeze.json']:
 x=json.loads((A/name).read_text())
 for rel,v in x['files'].items():check(R/rel,v['sha256'])
for k,v in s.items():
 if isinstance(v,dict) and 'file' in v and 'sha256' in v:check(A/v['file'],v['sha256'])
fw=(R/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin').read_bytes()
x=json.loads((A/'mouse-work-queue-exact.json').read_text())
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('work span '+e['address'])
x=json.loads((A/'mouse-timer-start-exact.json').read_text())
for e in x['slices']:
 b=(R/e['source']).read_bytes();o=int(e['source_offset'],16);n=int(e['end_exclusive'],16)-int(e['start'],16)
 if hashlib.sha256(b[o:o+n]).hexdigest()!=e['sha256']:errors.append('timer-start slice '+e['name'])
x=json.loads((A/'mouse-work-expiry-map.json').read_text())
ram=(R/'analysis/runtime-images/mouse-ram-1.20.bin').read_bytes()
def original_at(addr,n):
 return ram[addr-0x23020000:addr-0x23020000+n] if addr>=0x23020000 else fw[addr-0xe06c000:addr-0xe06c000+n]
for e in x['entries']:
 b=original_at(int(e['address'],16),16)
 if b.hex()!=e['original_entry_bytes_16'] or hashlib.sha256(b).hexdigest()!=e['sha256_entry16']:errors.append('expiry entry '+e['address'])
for e in x['call_sites']:
 if original_at(int(e['site'],16),4).hex()!=e['original_bytes4']:errors.append('expiry call '+e['site'])
for e in x['initialized_data']:
 o=int(e['file_offset'],16);expected=bytes.fromhex(e['bytes'])
 if fw[o:o+len(expected)]!=expected:errors.append('expiry initializer '+e['name'])
v=x['irq'];o=int(v['vector_offset'],16)
if int.from_bytes(fw[o:o+4],'little')!=int(v['vector_value'],16):errors.append('RTC IRQ vector')
fw=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes()
x=json.loads((A/'receiver-legacy-timer-exact.json').read_text())
for e in x['evidence']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['bytes16']:errors.append('legacy timer span '+e['address'])
for rel in ['analysis/mouse-work-expiry-map.md','analysis/mouse-work-queue-exact.md','analysis/mouse-timer-start-exact.md','analysis/receiver-legacy-timer-exact.md']:
 p=R/rel
 for url in re.findall(r'\]\(([^)]+)\)',p.read_text()):
  if '://' not in url and not url.startswith('#') and not (p.parent/url.split('#')[0]).exists():errors.append('broken link '+rel+' '+url)


x=json.loads((A/'mouse-expiry-work-exact.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('expiry firmware identity')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('expiry/work raw span '+e['address'])
p=A/'mouse-expiry-work-exact.md'
for url in re.findall(r'\]\(([^)]+)\)',p.read_text()):
 if '://' not in url and not url.startswith('#') and not (p.parent/url.split('#')[0]).exists():errors.append('broken expiry link '+url)


x=json.loads((A/'mouse-scanning-exact.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
for rel,h in x['component_integration']['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('scanning firmware identity')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('scanning raw span '+e['address'])
e=x['discovery_table']
for k in ['index','frequency']:
 o=int(e[k+'_image_offset'],16);b=bytes.fromhex(e[k+'_bytes'])
 if fw[o:o+len(b)]!=b:errors.append('scanning '+k+' table')
if e['selected_register_values']!=[fw[0x2ca14+i] for i in fw[0x2ca3c:0x2ca40]]:errors.append('selected scan frequencies')
p=A/'mouse-scanning-exact.md'
for url in re.findall(r'\]\(([^)]+)\)',p.read_text()):
 if '://' not in url and not url.startswith('#') and not (p.parent/url.split('#')[0]).exists():errors.append('broken scanning link '+url)

x=json.loads((A/'mouse-rtc-dispatch-exact.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
for rel,h in x['component_integration']['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('RTC firmware identity')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('RTC raw span '+e['address'])
p=A/'mouse-rtc-dispatch-exact.md'
for url in re.findall(r'\]\(([^)]+)\)',p.read_text()):
 if '://' not in url and not url.startswith('#') and not (p.parent/url.split('#')[0]).exists():errors.append('broken RTC link '+url)

x=json.loads((A/'mouse-worker-runtime-exact.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
for rel,h in x['component_integration']['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('worker firmware identity')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('worker raw span '+e['address'])
for e in x['literal_evidence']:
 o=int(e['image_offset'],16)
 if fw[o:o+4].hex()!=e['bytes4'] or int.from_bytes(fw[o:o+4],'little')!=int(e['value'],16):errors.append('worker literal '+e['image_offset'])
p=A/'mouse-worker-runtime-exact.md'
for url in re.findall(r'\]\(([^)]+)\)',p.read_text()):
 if '://' not in url and not url.startswith('#') and not (p.parent/url.split('#')[0]).exists():errors.append('broken worker link '+url)

x=json.loads((A/'mouse-context-switch-exact.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
for rel,h in x['component_integration']['sources'].items():check(R/rel,h)
for rel,h in x['native_assembly']['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('context firmware identity')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('context raw span '+e['address'])
native=(R/'recovered-code/cortex-m/build/mouse_context_switch.bin').read_bytes()
for e in x['native_assembly']['spans']:
 o=int(e['image_offset'],16);a=int(e['assembled_offset'],16);n=e['length']
 if fw[o:o+n]!=native[a:a+n] or hashlib.sha256(native[a:a+n]).hexdigest()!=e['sha256']:errors.append('native context span '+e['start'])
for rel in ['analysis/mouse-context-switch-exact.md','recovered-code/cortex-m/README.md']:
 p=R/rel
 for url in re.findall(r'\]\(([^)]+)\)',p.read_text()):
  if '://' not in url and not url.startswith('#') and not (p.parent/url.split('#')[0]).exists():errors.append('broken context link '+url)

x=json.loads((A/'mouse-deferred-work-exact.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
for rel,h in x['component_integration']['sources'].items():check(R/rel,h)
for rel,h in x['legacy_regression']['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('deferred firmware identity')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('deferred raw span '+e['address'])
freeze=json.loads((A/'rtc-v1-before-deferred/manifest.json').read_text())
for v in freeze['files'].values():check(R/v['frozen_path'],v['sha256'])
p=A/'mouse-deferred-work-exact.md'
for url in re.findall(r'\]\(([^)]+)\)',p.read_text()):
 if '://' not in url and not url.startswith('#') and not (p.parent/url.split('#')[0]).exists():errors.append('broken deferred link '+url)

x=json.loads((A/'mouse-timer-stop-exact.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('stop firmware identity')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('stop span '+e['address'])
x=json.loads((A/'mouse-lifecycle-runtime-exact.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('lifecycle runtime firmware identity')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('lifecycle runtime span '+e['address'])
x=json.loads((A/'mouse-stop-registration-evidence.json').read_text())
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('registration firmware identity')
for e in x['static_initializers']+x['spans']:
 o=int(e['file_offset'],16);b=bytes.fromhex(e['bytes'])
 if fw[o:o+len(b)]!=b:errors.append('registration bytes '+e['file_offset'])
x=json.loads((A/'receiver-initialization-exact.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('receiver initialization firmware identity')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('init span '+e['address'])
x=json.loads((A/'receiver-config-dispatch-map.json').read_text())
o=int(x['table_offset'],16)
if hashlib.sha256(fw[o:o+176]).hexdigest()!=x['table_sha256']:errors.append('dispatch table hash')
for e in x['table']:
 o=int(e['table_file_offset'],16)
 if fw[o:o+4].hex()!=e['word_hex'] or (int.from_bytes(fw[o:o+4],'little')&~1)!=int(e['entry'],16):errors.append('dispatch event '+str(e['event']))
x=json.loads((A/'receiver-config-control-exact.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('receiver config firmware')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('config span '+e['address'])
p=A/'receiver-config-control-exact.md'
for url in re.findall(r'\]\(([^)]+)\)',p.read_text()):
 if '://' not in url and not url.startswith('#') and not (p.parent/url.split('#')[0]).exists():errors.append('broken config link '+url)
count=sum(d['cases'] for d in s['datasets'].values());units=len(list((R/'recovered-code/portable').glob('*.c')))
assert count==105344 and units==40 and len(s['datasets'])==57
out={'status':'PASS' if not errors else 'FAIL','datasets':57,'original_inputs':count,'C_units':units,'validated_sources_and_build_records':len(s['sources'])+len(s['libraries']),'errors':errors,'scope':'Current artifact/source/build/data integrity and declared test status; complete firmware/RF objective remains incomplete'}
(A/'phase-receiver-config-integrity.json').write_text(json.dumps(out,indent=2)+'\n');print(json.dumps(out,indent=2));assert not errors
