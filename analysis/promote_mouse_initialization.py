from pathlib import Path
import json,hashlib,subprocess,datetime
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def read(p):return json.loads(p.read_text())
def write(p,d):p.write_text(json.dumps(d,indent=2,ensure_ascii=False)+'\n')
v=read(A/'mouse-initialization-comparison.json')
assert v['status']=='PASS' and not v['failures']
for field in ['sources','libraries']:
 for rel,h in v[field].items():assert sha(R/rel)==h,rel
files=sorted(P.glob('*.c'));assert len(files)==68
subprocess.run(['make','-C',str(P)],check=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
lib=P/'build/librr_recovered68.dylib'
subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True)
fwpath=R/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin';fw=fwpath.read_bytes()
entries=[0x23022e28,0x230259a4,0x230218ec,0x230225cc,0x23021800,0x23021528,0x23021c6c,0x23020e24]
spans=[]
for address in entries:
 offset=address-0x23020000+0x79c if address>=0x23020000 else address-0xe06c000
 spans.append({'address':hex(address),'image_offset':hex(offset),'entry16_hex':fw[offset:offset+16].hex()})
dataset='mouse-initialization-original.jsonl';rows=[json.loads(l) for l in (A/dataset).open()];n=len(rows)
assert n==3840 and [r['case'] for r in rows]==list(range(n))
integration=read(A/'mouse-initialization-exchange-comparison.json');assert integration['status']=='PASS'
for section in ['sources','libraries']:
 for rel,h in integration[section].items():assert sha(R/rel)==h,rel
sourcepaths=[fwpath,P/'mouse_initialization.c',P/'mouse_initialization.h',A/'mouse-initialization-map.json',A/'mouse-initialization-map.md',A/'run_mouse_initialization_oracle.py']
x={'status':'PASS','phase':65,'firmware_sha256':sha(fwpath),'sources':{str(p.relative_to(R)):sha(p) for p in sourcepaths},'entry_spans':spans,'comparison':v,'exchange_integration':integration,'dataset_coverage':[{'file':dataset,'cases':n,'sha256':sha(A/dataset)}],'original_inputs':n,'original_steps':v['original_steps'],'full_returns':v['full_returns'],'limits':['Host reconstruction, not complete bootable MCU firmware','Complete mouse initialization and wrapper; post-connection state and transport in component test are explicit inputs','Full128KiBRAM,five4KiBMMIO and finalBASEPRI; finalmemoryeffects, not timedwrite trace','FullinitPHYfixed4 verified from original stack writes; standalonePHYall256 is parametercoverage, not hardwarevalidity','No automatic peripheral effects, actual RF, concurrency, board or physical receiver validation','No receiver or hardware writes'],'api':['rr_mouse_initialize','rr_mouse_application_initialize','rr_mouse_radio_initialize','rr_mouse_radio_reset','rr_mouse_radio_dppi','rr_mouse_radio_queue_initialize']}
write(A/'mouse-initialization-exact.json',x)
s=read(A/'recovered-code-validation-summary.json');archive=A/'recovered-code-validation-phase64-frozen.json'
if not archive.exists():write(archive,s)
s['datasets'][dataset]={'cases':n,'sha256':sha(A/dataset)}
s['verification_results']['mouse-initialization-comparison.json']=sha(A/'mouse-initialization-comparison.json')
s['sources']={str(p.relative_to(R)):sha(p) for p in files+sorted(P.glob('*.h'))+[P/'Makefile']}
s['libraries']={str(p.relative_to(R)):sha(p) for p in [P/'build/librr_recovered.a',lib]};s['library_sha256']=sha(P/'build/librr_recovered.a')
s['unique_original_input_count']=sum(d['cases'] for d in s['datasets'].values());assert s['unique_original_input_count']==211712+n
s['integrated_host_link']='68 C11 units strictly compiled and linked as host static/shared libraries; current shared librr_recovered68.dylib; prior snapshots retained. Not a complete MCU image.'
s['mouse_initialization_integration']={'file':'mouse-initialization-exact.json','sha256':sha(A/'mouse-initialization-exact.json')}
s['execution_boundaries']['mouse_initialization']={'total':n,'full_returns':v['full_returns'],'not_modeled':'Upstream settings/thread creation/mode switch; CPU scheduling, physical peripheral and RF behavior'}
s['verification_results']['mouse-initialization-exchange-comparison.json']=sha(A/'mouse-initialization-exchange-comparison.json')
s['updated_at']=datetime.datetime.now(datetime.timezone.utc).isoformat();write(A/'recovered-code-validation-summary.json',s)
print(json.dumps({'status':'PASS','new_cases':n,'steps':v['original_steps'],'total_cases':s['unique_original_input_count'],'units':68,'datasets':len(s['datasets'])},indent=2))
