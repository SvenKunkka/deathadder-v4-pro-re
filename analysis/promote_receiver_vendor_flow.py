from pathlib import Path
import json,hashlib,subprocess,datetime
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def read(p):return json.loads(p.read_text())
def write(p,d):p.write_text(json.dumps(d,indent=2,ensure_ascii=False)+'\n')
comparisons={'comparison':'receiver-vendor-flow-comparison.json','worker_regression':'receiver-worker-vendor-regression.json'}
v={k:read(A/n) for k,n in comparisons.items()}
for k,d in v.items():
 assert d['status']=='PASS' and not d['failures'],k
 for rel,h in d['sources'].items():assert sha(R/rel)==h,(k,rel,'source drift')
 for rel,h in d['libraries'].items():assert sha(R/rel)==h,(k,rel,'library drift')
files=sorted(P.glob('*.c'));assert len(files)==66
subprocess.run(['make','-C',str(P)],check=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
lib=P/'build/librr_recovered66.dylib'
subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True)
fwpath=R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin';fw=fwpath.read_bytes()
entries=[0x2302604c,0x23026090,0x230205f8,0x2302048c,0x23020510,0x23020530,0x23024db4,0xe06d43c,0xe06d19c]
spans=[]
for address in entries:
 offset=address-0x23020000+0x79c if address>=0x23020000 else address-0xe054000
 spans.append({'address':hex(address),'image_offset':hex(offset),'entry16_hex':fw[offset:offset+16].hex()})
dataset='receiver-vendor-flow-original.jsonl';rows=[json.loads(l) for l in (A/dataset).read_text().splitlines()]
assert [r['case'] for r in rows]==list(range(6144))
sourcepaths=[fwpath,P/'receiver_vendor_flow.c',P/'receiver_vendor_flow.h',P/'receiver_worker_runtime.c',P/'receiver_worker_runtime.h',A/'receiver-vendor-dependency-map.json',A/'receiver-worker-v1-before-vendor/manifest.json']
x={'status':'PASS','phase':63,'firmware_sha256':sha(fwpath),'sources':{str(p.relative_to(R)):sha(p) for p in sourcepaths},'entry_spans':spans,**v,'dataset_coverage':[{'file':dataset,'cases':6144,'sha256':sha(A/dataset)}],'original_inputs':6144,'original_steps':4729891,'full_function_returns':3538,'next_worker_header':658,'event_injections':725,'limits':['Host reconstruction, not complete bootable MCU firmware','Actual vendor test/statistics implementation and worker return tail; unresolved identity/LED/update handlers retain actual entry','Worker next-loop-header is not thread termination or physical asynchronous scheduling','No USB callback result substitution in new dataset; legacy regression retains its previously declared external USB result fixtures','Full128KiBRAM,eight4KiBMMIO,deviceID8B,boot16B; privileged sequential CPU, stack scratch excluded','No automatic peripheral completion, SET/CLR effects, actual RF or concurrency proof','No receiver or hardware writes'],'api':['rr_receiver_vendor_flow','rr_receiver_vendor_work_step','rr_receiver_work_thread_step_with_handler']}
write(A/'receiver-vendor-flow-exact.json',x)
s=read(A/'recovered-code-validation-summary.json');archivepath=A/'recovered-code-validation-phase62-frozen.json'
if not archivepath.exists():write(archivepath,s)
s['datasets'][dataset]={'cases':6144,'sha256':sha(A/dataset)}
for n in comparisons.values():s['verification_results'][n]=sha(A/n)
s['sources']={str(p.relative_to(R)):sha(p) for p in files+sorted(P.glob('*.h'))+[P/'Makefile']}
s['libraries']={str(p.relative_to(R)):sha(p) for p in [P/'build/librr_recovered.a',lib]};s['library_sha256']=sha(P/'build/librr_recovered.a')
s['unique_original_input_count']=sum(d['cases'] for d in s['datasets'].values());assert s['unique_original_input_count']==208128
s['integrated_host_link']='66 C11 units strictly compiled and linked as host static/shared libraries; current shared librr_recovered66.dylib; prior snapshots retained. Not a complete MCU image.'
s['receiver_vendor_flow_integration']={'file':'receiver-vendor-flow-exact.json','sha256':sha(A/'receiver-vendor-flow-exact.json')}
s['receiver_worker_v1_archive']={'file':'receiver-worker-v1-before-vendor/manifest.json','sha256':sha(A/'receiver-worker-v1-before-vendor/manifest.json')}
s['historical_source_snapshots'].update(read(A/'receiver-worker-v1-before-vendor/manifest.json')['files'])
s['execution_boundaries']['receiver_vendor_flow']={'total':6144,'full_returns':3538,'next_worker_header':658,'explicit_disabled_events':725,'not_modeled':'Identity/LED/update handler bodies, CPU switch and USB driver continuation, hardware/RF scheduling'}
s['updated_at']=datetime.datetime.now(datetime.timezone.utc).isoformat();write(A/'recovered-code-validation-summary.json',s)
print(json.dumps({'status':'PASS','new_cases':6144,'steps':4729891,'returns':3538,'worker_headers':658,'injections':725,'total_cases':208128,'units':66,'datasets':87},indent=2))
