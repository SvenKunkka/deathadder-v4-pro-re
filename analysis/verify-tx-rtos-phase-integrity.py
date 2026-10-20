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
 for key in ['sources','code_sha256','source_hashes']:
  for rel,value in v.get(key,{}).items():
   if (R/rel).is_file():check(R/rel,value)
for field in ['business_exchange_integration','adaptive_integration','receiver_irq_integration','receiver_timer_integration','mouse_mode4_integration','mouse_mode4_tx_integration']:
 if field in s:check(A/s[field]['file'],s[field]['sha256'])
for rel in ['逆向进度与代码入口.md','recovered-code/portable/README.md','analysis/mouse-timer-lifecycle-exact.md','analysis/receiver-radio-timer-exact.md','analysis/mouse-mode4-exact.md','analysis/receiver-other-modes-map.md','analysis/mouse-mode4-tx-exact.md','analysis/receiver-legacy-business-exact.md','analysis/receiver-rtos-lifecycle-exact.md']:
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
count=sum(d['cases'] for d in s['datasets'].values());units=len(list((R/'recovered-code/portable').glob('*.c')))
assert count==36096 and units==23 and len(s['datasets'])==34
out={'status':'PASS' if not errors else 'FAIL','datasets':34,'original_inputs':count,'C_units':units,'validated_sources_and_build_records':len(s['sources'])+len(s['libraries']),'errors':errors,'scope':'Current artifact/source/build/data integrity and declared test status; complete firmware/RF objective remains incomplete'}
(A/'phase-tx-rtos-integrity.json').write_text(json.dumps(out,indent=2)+'\n');print(json.dumps(out,indent=2));assert not errors
