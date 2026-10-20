from pathlib import Path
import json,hashlib,re
R=Path(__file__).resolve().parent.parent;A=R/'analysis';errors=[];historical_resolutions=set()
archive=json.loads((A/'receiver-rtc-v1-before-timers/manifest.json').read_text())['files']
archive.update(json.loads((A/'receiver-timer-v1-before-appcallbacks/manifest.json').read_text())['files'])
historical_keys={'recovered-code/portable/receiver_rtc_dispatch.c','recovered-code/portable/receiver_rtc_dispatch.h','recovered-code/portable/receiver_timer_expiry.c','recovered-code/portable/receiver_timer_expiry.h'}
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1048576),b''):h.update(b)
 return h.hexdigest()
def check(p,w):
 if not p.is_file():errors.append('missing '+str(p))
 elif sha(p)!=w:
  rel=str(p.relative_to(R));entry=archive.get(rel)
  if rel in historical_keys and entry and entry['sha256']==w and (R/entry['frozen_path']).is_file() and sha(R/entry['frozen_path'])==w:historical_resolutions.add(rel)
  else:errors.append('hash '+str(p))
s=json.loads((A/'recovered-code-validation-summary.json').read_text())
for k in ['sources','libraries']:
 for rel,h in s[k].items():
  if not (R/rel).is_file() or sha(R/rel)!=h:errors.append('current artifact '+rel)
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
x=json.loads((A/'receiver-queue-runtime-exact.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
for rel,h in x['component_integration']['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('receiver queue firmware')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('queue span '+e['address'])
p=A/'receiver-queue-runtime-exact.md'
for url in re.findall(r'\]\(([^)]+)\)',p.read_text()):
 if '://' not in url and not url.startswith('#') and not (p.parent/url.split('#')[0]).exists():errors.append('broken queue link '+url)
x=json.loads((A/'receiver-notification-runtime-exact.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
for rel,h in x['component_integration']['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('receiver notification firmware')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('notification span '+e['address'])
e=x['timer_initializer'];o=int(e['file_offset'],16);b=bytes.fromhex(e['bytes'])
if fw[o:o+len(b)]!=b:errors.append('notification timer initializer')
p=A/'receiver-notification-runtime-exact.md'
for url in re.findall(r'\]\(([^)]+)\)',p.read_text()):
 if '://' not in url and not url.startswith('#') and not (p.parent/url.split('#')[0]).exists():errors.append('broken notification link '+url)
x=json.loads((A/'receiver-config-producer-exact.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
for rel,h in x['component_integration']['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('receiver producer firmware')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('producer span '+e['address'])
for e in x['queue_initializers']:
 o=int(e['file_offset'],16);b=bytes.fromhex(e['bytes'])
 if fw[o:o+len(b)]!=b:errors.append('queue initializer '+e['address'])
p=A/'receiver-config-producer-exact.md'
for url in re.findall(r'\]\(([^)]+)\)',p.read_text()):
 if '://' not in url and not url.startswith('#') and not (p.parent/url.split('#')[0]).exists():errors.append('broken producer link '+url)
x=json.loads((A/'receiver-settings-exact.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
for rel,h in x['component_integration']['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('settings firmware')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('settings entry '+e['address'])
for e in x['constant_evidence']:
 o=int(e['file_offset'],16);b=bytes.fromhex(e['bytes'])
 if fw[o:o+len(b)]!=b:errors.append('settings constants '+e['address'])
p=A/'receiver-settings-exact.md'
for url in re.findall(r'\]\(([^)]+)\)',p.read_text()):
 if '://' not in url and not url.startswith('#') and not (p.parent/url.split('#')[0]).exists():errors.append('broken settings link '+url)
x=json.loads((A/'receiver-storage-read-exact.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
for rel,h in x['component_integration']['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('storage firmware')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('storage entry '+e['address'])
for e in x['constant_evidence']:
 o=int(e['file_offset'],16);b=bytes.fromhex(e['bytes'])
 if fw[o:o+len(b)]!=b:errors.append('storage constants '+e['address'])
for d in x['dataset_coverage']:
 check(A/d['file'],d['sha256']);ids=[json.loads(line)['case'] for line in (A/d['file']).open()]
 if ids!=list(range(d['cases'])):errors.append('storage dataset IDs '+d['file'])
p=A/'receiver-storage-read-exact.md'
for url in re.findall(r'\]\(([^)]+)\)',p.read_text()):
 if '://' not in url and not url.startswith('#') and not (p.parent/url.split('#')[0]).exists():errors.append('broken storage link '+url)
x=json.loads((A/'receiver-storage-write-exact.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
for rel,h in x['component_integration']['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('storage write firmware')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('storage write entry '+e['address'])
for e in x['constant_evidence']:
 o=int(e['file_offset'],16);b=bytes.fromhex(e['bytes'])
 if fw[o:o+len(b)]!=b:errors.append('storage write constants '+e['address'])
for d in x['dataset_coverage']:
 check(A/d['file'],d['sha256']);ids=[json.loads(line)['case'] for line in (A/d['file']).open()]
 if ids!=list(range(d['cases'])):errors.append('storage write dataset IDs '+d['file'])
p=A/'receiver-storage-write-exact.md'
for url in re.findall(r'\]\(([^)]+)\)',p.read_text()):
 if '://' not in url and not url.startswith('#') and not (p.parent/url.split('#')[0]).exists():errors.append('broken storage write link '+url)
x=json.loads((A/'receiver-storage-scan-exact.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
for rel,h in x['component_integration']['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('scan firmware')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('scan entry '+e['address'])
for d in x['dataset_coverage']:
 check(A/d['file'],d['sha256']);ids=[json.loads(line)['case'] for line in (A/d['file']).open()]
 if ids!=list(range(d['cases'])):errors.append('scan dataset IDs')
p=A/'receiver-storage-scan-exact.md'
for url in re.findall(r'\]\(([^)]+)\)',p.read_text()):
 if '://' not in url and not url.startswith('#') and not (p.parent/url.split('#')[0]).exists():errors.append('broken scan link '+url)
x=json.loads((A/'receiver-storage-mount-exact.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
for rel,h in x['component_integration']['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('mount firmware')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('mount entry '+e['address'])
for d in x['dataset_coverage']:
 check(A/d['file'],d['sha256']);ids=[json.loads(line)['case'] for line in (A/d['file']).open()]
 if ids!=list(range(d['cases'])):errors.append('mount dataset IDs')
p=A/'receiver-storage-mount-exact.md'
for url in re.findall(r'\]\(([^)]+)\)',p.read_text()):
 if '://' not in url and not url.startswith('#') and not (p.parent/url.split('#')[0]).exists():errors.append('broken mount link '+url)
x=json.loads((A/'receiver-storage-startup-exact.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
for rel,h in x['component_integration']['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('startup firmware')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('startup entry '+e['address'])
for e in x['constant_evidence']:
 o=int(e['file_offset'],16);b=bytes.fromhex(e['bytes'])
 if fw[o:o+len(b)]!=b:errors.append('startup constant '+e['name'])
for d in x['dataset_coverage']:
 check(A/d['file'],d['sha256']);ids=[json.loads(line)['case'] for line in (A/d['file']).open()]
 if ids!=list(range(d['cases'])):errors.append('startup dataset IDs')
x=json.loads((A/'receiver-boot-chain-map.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
o=int(x['entry_image_offset'],16);b=bytes.fromhex(x['bytes'])
if fw[o:o+len(b)]!=b:errors.append('boot chain span')
for e in x['calls']:
 o=int(e['site_image_offset'],16)
 if fw[o:o+4].hex()!=e['call_bytes4']:errors.append('boot call '+e['site'])
 o=int(e['target_image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('boot target '+e['resolved_target'])
 if e['branch_target']!=e['resolved_target']:
  o=0x79c+int(e['branch_target'],16)-0x23020000+4
  if int.from_bytes(fw[o:o+4],'little')!=(int(e['resolved_target'],16)|1):errors.append('boot thunk '+e['branch_target'])
for name in ['receiver-storage-startup-exact.md','receiver-boot-chain-map.md']:
 p=A/name
 for url in re.findall(r'\]\(([^)]+)\)',p.read_text()):
  if '://' not in url and not url.startswith('#') and not (p.parent/url.split('#')[0]).exists():errors.append('broken startup link '+url)
x=json.loads((A/'receiver-mutex-exact.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
for rel,h in x['component_integration']['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('mutex firmware')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('mutex entry '+e['address'])
for d in x['dataset_coverage']:
 check(A/d['file'],d['sha256']);rows=[json.loads(line) for line in (A/d['file']).open()]
 if [row['case'] for row in rows]!=list(range(d['cases'])):errors.append('mutex dataset IDs')
 if d['file']=='receiver-mutex-original.jsonl' and any(row['mutex']!=0x23007000 for row in rows):errors.append('mutex metadata address')
p=A/'receiver-mutex-exact.md'
for url in re.findall(r'\]\(([^)]+)\)',p.read_text()):
 if '://' not in url and not url.startswith('#') and not (p.parent/url.split('#')[0]).exists():errors.append('broken mutex link '+url)
x=json.loads((A/'receiver-context-switch-exact.json').read_text())
for section in ['sources']:
 for rel,h in x[section].items():check(R/rel,h)
for section in ['native_assembly','component_integration','mutex_component_integration']:
 for rel,h in x[section]['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('receiver context firmware')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('receiver context entry '+e['address'])
native=(R/'recovered-code/cortex-m/receiver/build/receiver_context_switch.bin').read_bytes()
for e in x['native_assembly']['spans']:
 o=int(e['image_offset'],16);a=int(e['assembled_offset'],16);n=e['length']
 if fw[o:o+n]!=native[a:a+n] or hashlib.sha256(native[a:a+n]).hexdigest()!=e['sha256']:errors.append('receiver native context span')
rows=[json.loads(line) for line in (A/'receiver-context-switch-original.jsonl').open()]
if [v['case'] for v in rows]!=list(range(2048)):errors.append('receiver context dataset IDs')
p=A/'receiver-context-switch-exact.md'
for url in re.findall(r'\]\(([^)]+)\)',p.read_text()):
 if '://' not in url and not url.startswith('#') and not (p.parent/url.split('#')[0]).exists():errors.append('broken receiver context link '+url)
x=json.loads((A/'receiver-rtc-dispatch-exact.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
for rel,h in x['component_integration']['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('receiver RTC firmware')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('receiver RTC entry '+e['address'])
for e in x['literal_evidence']:
 o=int(e['image_offset'],16)
 if fw[o:o+4].hex()!=e['bytes4'] or int.from_bytes(fw[o:o+4],'little')!=int(e['value'],16):errors.append('receiver RTC literal '+e['address'])
for d in x['dataset_coverage']:
 check(A/d['file'],d['sha256']);rows=[json.loads(line) for line in (A/d['file']).open()]
 if [v['case'] for v in rows]!=list(range(d['cases'])):errors.append('receiver RTC dataset IDs')
p=A/'receiver-rtc-dispatch-exact.md'
for url in re.findall(r'\]\(([^)]+)\)',p.read_text()):
 if '://' not in url and not url.startswith('#') and not (p.parent/url.split('#')[0]).exists():errors.append('broken receiver RTC link '+url)
for rel,v in archive.items():check(R/v['frozen_path'],v['sha256'])
x=json.loads((A/'receiver-timer-expiry-exact.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
for section in ['component_integration','legacy_regression','legacy_continuous_regression']:
 for rel,h in x[section]['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('timer expiry firmware')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('timer expiry entry '+e['address'])
for d in x['dataset_coverage']:
 check(A/d['file'],d['sha256']);rows=[json.loads(line) for line in (A/d['file']).open()]
 if [v['case'] for v in rows]!=list(range(d['cases'])):errors.append('timer expiry dataset IDs')
x=json.loads((A/'receiver-application-timer-map.json').read_text())
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('timer map firmware')
for e in x['timers']:
 o=int(e['file_offset'],16);raw=bytes.fromhex(e['bytes'])
 if fw[o:o+len(raw)]!=raw:errors.append('timer initializer '+e['timer'])
 o=int(e['callback_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('timer callback entry '+e['timer'])
p=A/'receiver-timer-expiry-exact.md'
for url in re.findall(r'\]\(([^)]+)\)',p.read_text()):
 if '://' not in url and not url.startswith('#') and not (p.parent/url.split('#')[0]).exists():errors.append('broken expiry link '+url)
x=json.loads((A/'receiver-application-timers-exact.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
for section in ['direct_comparison','RTC_chain_comparison','component_integration','legacy_regression','legacy_continuous_regression']:
 for rel,h in x[section]['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('app timer firmware')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('app timer entry '+e['address'])
import gzip,base64
all_initial=set()
for d in x['dataset_coverage']:
 check(A/d['file'],d['sha256']);ids=[];keys=set()
 for line in (A/d['file']).open():
  t=json.loads(line);ids.append(t['case']);keys.add(hashlib.sha256(gzip.decompress(base64.b64decode(t['ram_before']))).hexdigest())
  for name in ['ram','radio','timer','nvic','dppi','rtc','clock0','clock1','clock2','deviceid']:
   for side in ['before','after']:
    if len(gzip.decompress(base64.b64decode(t[name+'_'+side])))!=(131072 if name=='ram' else 8 if name=='deviceid' else 4096):errors.append('app window dimension '+d['file'])
 if ids!=list(range(d['cases'])) or len(keys)!=d['cases'] or keys&all_initial:errors.append('app dataset IDs or duplicate initial RAM')
 all_initial|=keys
for rel in ['analysis/receiver-application-timers-exact.md']:
 p=R/rel
 for url in re.findall(r'\]\(([^)]+)\)',p.read_text()):
  if '://' not in url and not url.startswith('#') and not (p.parent/url.split('#')[0]).exists():errors.append('broken app timer link '+url)
if x['original_inputs']!=6144 or x['full_function_returns']!=5719 or x['entry_boundaries']!=425:errors.append('app result totals')

x=json.loads((A/'receiver-periodic-service-exact.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
for section in ['comparison','application_regression','component_integration']:
 for rel,h in x[section]['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('periodic firmware')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('periodic entry '+e['address'])
for d in x['dataset_coverage']:
 check(A/d['file'],d['sha256']);ids=[];keys=set()
 for line in (A/d['file']).open():
  t=json.loads(line);ids.append(t['case']);keys.add(hashlib.sha256(gzip.decompress(base64.b64decode(t['ram_before']))).hexdigest())
  for name in ['ram','rtc','service']:
   for side in ['before','after']:
    if len(gzip.decompress(base64.b64decode(t[name+'_'+side])))!=(131072 if name=='ram' else 4096):errors.append('periodic window size')
 if ids!=list(range(d['cases'])) or len(keys)!=d['cases']:errors.append('periodic dataset IDs or duplicate initial RAM')
p=A/'receiver-periodic-service-exact.md'
for url in re.findall(r'\]\(([^)]+)\)',p.read_text()):
 if '://' not in url and not url.startswith('#') and not (p.parent/url.split('#')[0]).exists():errors.append('periodic link '+url)

x=json.loads((A/'receiver-work-queue-exact.json').read_text())
for rel,h in x['sources'].items():check(R/rel,h)
for section in ['queue_comparison','RTC_comparison','application_regression','component_integration']:
 for rel,h in x[section]['sources'].items():check(R/rel,h)
fw=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes()
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('work queue firmware')
for e in x['entry_spans']:
 o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('work queue entry '+e['address'])
all_work_keys=set()
for d in x['dataset_coverage']:
 check(A/d['file'],d['sha256']);ids=[];keys=set()
 for line in (A/d['file']).open():
  t=json.loads(line);ids.append(t['case']);keys.add(hashlib.sha256(gzip.decompress(base64.b64decode(t['before_gzip']))).hexdigest())
  for name,n in [('before_gzip',131072),('after_gzip',131072),('rtc_before',4096),('rtc_after',4096)]:
   if len(gzip.decompress(base64.b64decode(t[name])))!=n:errors.append('work queue window size')
 if ids!=list(range(d['cases'])) or len(keys)!=d['cases'] or keys&all_work_keys:errors.append('work dataset IDs or duplicate input')
 all_work_keys|=keys
p=A/'receiver-work-queue-exact.md'
for url in re.findall(r'\]\(([^)]+)\)',p.read_text()):
 if '://' not in url and not url.startswith('#') and not (p.parent/url.split('#')[0]).exists():errors.append('work queue link '+url)
x=json.loads((A/'receiver-work-registration-map.json').read_text())
if hashlib.sha256(fw).hexdigest()!=x['firmware_sha256']:errors.append('work registration firmware')
for e in x['registrations']:
 check(R/e['decompilation'],e['sha256']);o=int(e['image_offset'],16)
 if fw[o:o+16].hex()!=e['entry16_hex']:errors.append('work registration entry')

if historical_resolutions!=historical_keys:errors.append('unexpected historical source resolution set')
count=sum(d['cases'] for d in s['datasets'].values());units=len(list((R/'recovered-code/portable').glob('*.c')))
assert count==172288 and units==56 and len(s['datasets'])==78
out={'status':'PASS' if not errors else 'FAIL','datasets':78,'original_inputs':count,'C_units':units,'validated_sources_and_build_records':len(s['sources'])+len(s['libraries']),'errors':errors,'historical_source_bindings_checked':sorted(historical_resolutions),'scope':'Current artifact/source/build/data integrity and declared test status; complete firmware/RF objective remains incomplete'}
(A/'phase-receiver-work-integrity.json').write_text(json.dumps(out,indent=2)+'\n');print(json.dumps(out,indent=2));assert not errors
