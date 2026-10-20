from pathlib import Path
import json,hashlib,subprocess,datetime
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def read(p):return json.loads(p.read_text())
def write(p,d):p.write_text(json.dumps(d,indent=2,ensure_ascii=False)+'\n')
comparisons={
 'comparison':'receiver-radio-lifecycle-comparison.json',
 'log_comparison':'receiver-radio-log-comparison.json',
 'legacy_engine_regression':'receiver-radio-engine-phase62-regression-comparison.json',
 'legacy_flow_regression':'receiver-radio-flow-phase62-regression-comparison.json'}
v={k:read(A/n) for k,n in comparisons.items()}
for k,d in v.items():
 assert d['status']=='PASS' and d['failure_count']==0,k
 for rel,h in d['sources'].items():assert sha(R/rel)==h,(k,rel,'source drift')
 for rel,h in d['libraries'].items():assert sha(R/rel)==h,(k,rel,'library drift')
files=sorted(P.glob('*.c'));assert len(files)==65
subprocess.run(['make','-C',str(P)],check=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
lib=P/'build/librr_recovered65.dylib'
subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True)
fwpath=R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin';fw=fwpath.read_bytes()
entries=[0x23021f04,0x23021f88,0x23021d9c,0x23021db0,0xe05d1ac,0xe0612f0,0xe05d624,0xe05d628,0xe05d634,0xe06eea8]
spans=[]
for address in entries:
 offset=address-0x23020000+0x79c if address>=0x23020000 else address-0xe054000
 spans.append({'address':hex(address),'image_offset':hex(offset),'entry16_hex':fw[offset:offset+16].hex()})
datasets=[]
for name in ['receiver-radio-lifecycle-original.jsonl','receiver-radio-log-original.jsonl']:
 rows=[json.loads(l) for l in (A/name).read_text().splitlines()]
 assert [r['case'] for r in rows]==list(range(len(rows)))
 datasets.append({'file':name,'cases':len(rows),'sha256':sha(A/name)})
newcases=sum(d['cases'] for d in datasets);assert newcases==7552
steps=v['comparison']['original_steps']+v['log_comparison']['original_steps']
returns=v['comparison']['endings']['returned']+v['log_comparison']['endings']['returned']
injections=v['comparison']['injected_disabled_events']
sourcepaths=[fwpath]+[p for p in P.glob('receiver_radio_test_*') if p.suffix in ['.c','.h']]+[A/'receiver-test-log-notes.json',A/'receiver-test-engine-v1-before-lifecycle/manifest.json']
x={'status':'PASS','phase':62,'firmware_sha256':sha(fwpath),'sources':{str(p.relative_to(R)):sha(p) for p in sourcepaths},'entry_spans':spans,**v,'dataset_coverage':datasets,'original_inputs':newcases,'original_steps':steps,'full_function_returns':returns,'event_injections':injections,'limits':['Host C reconstruction, not original source or bootable complete MCU firmware','Seven exact known log format strings and actual initialized no-output callback only; unknown callback stops at real entry','Full128KiB RAM, seven inert MMIO windows and priority compared for lifecycle; six MMIO windows for direct logging; CPU stack scratch excluded','Sequential memory barriers have no modeled side effect; no concurrency or bus ordering proof','Radio EVENTS_DISABLED input is explicit per reached poll, no simulated automatic hardware completion','CPU switch remains real E0611CC entry boundary; no continuation across actual task context change','No receiver or physical RF validation; no hardware writes'], 'api':['rr_receiver_radio_test_lifecycle','rr_receiver_radio_test_dependencies','rr_receiver_radio_test_engine_with_dependencies','rr_receiver_radio_test_flow_with_dependencies','rr_receiver_radio_test_log']}
write(A/'receiver-radio-lifecycle-exact.json',x)
s=read(A/'recovered-code-validation-summary.json')
archivepath=A/'recovered-code-validation-phase61-frozen.json'
if not archivepath.exists():write(archivepath,s)
for d in datasets:s['datasets'][d['file']]={k:d[k] for k in ['cases','sha256']}
for n in comparisons.values():s['verification_results'][n]=sha(A/n)
s['sources']={str(p.relative_to(R)):sha(p) for p in files+sorted(P.glob('*.h'))+[P/'Makefile']}
s['libraries']={str(p.relative_to(R)):sha(p) for p in [P/'build/librr_recovered.a',lib]};s['library_sha256']=sha(P/'build/librr_recovered.a')
s['unique_original_input_count']=sum(d['cases'] for d in s['datasets'].values());assert s['unique_original_input_count']==201984
s['integrated_host_link']='65 C11 units strictly compiled and linked as host static/shared libraries; current shared librr_recovered65.dylib; prior snapshots retained. Not a complete MCU image.'
s['receiver_radio_lifecycle_integration']={'file':'receiver-radio-lifecycle-exact.json','sha256':sha(A/'receiver-radio-lifecycle-exact.json')}
s['receiver_radio_engine_v1_archive']={'file':'receiver-test-engine-v1-before-lifecycle/manifest.json','sha256':sha(A/'receiver-test-engine-v1-before-lifecycle/manifest.json')}
s['historical_source_snapshots'].update(read(A/'receiver-test-engine-v1-before-lifecycle/manifest.json')['files'])
s['execution_boundaries']['receiver_radio_lifecycle']={'total':newcases,'full_returns':returns,'explicit_disabled_events':injections,'not_modeled':'Actual CPU switch continuation, physical RF/event timing, arbitrary dynamically installed logger'}
s['updated_at']=datetime.datetime.now(datetime.timezone.utc).isoformat();write(A/'recovered-code-validation-summary.json',s)
print(json.dumps({'new_cases':newcases,'steps':steps,'returns':returns,'injections':injections,'total_cases':s['unique_original_input_count'],'units':65,'datasets':len(s['datasets'])},indent=2))
