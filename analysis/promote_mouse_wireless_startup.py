from pathlib import Path
import json,hashlib,subprocess,datetime
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def read(p):return json.loads(p.read_text())
def write(p,d):p.write_text(json.dumps(d,indent=2,ensure_ascii=False)+'\n')
v=read(A/'mouse-wireless-startup-comparison.json')
assert v['status']=='PASS' and not v['failures']
for field in ['sources','libraries']:
 for rel,h in v[field].items():assert sha(R/rel)==h,rel
files=sorted(P.glob('*.c'));assert len(files)==69
subprocess.run(['make','-C',str(P)],check=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
lib=P/'build/librr_recovered69.dylib'
subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True)
fwpath=R/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin';fw=fwpath.read_bytes()
entries=[0x23021150,0x23025d1c,0x23022d68,0x0e0957a8,0x0e095bf4,0x0e0960a8,0x0e096164]
spans=[]
for address in entries:
 offset=address-0x23020000+0x79c if address>=0x23020000 else address-0xe06c000
 spans.append({'address':hex(address),'image_offset':hex(offset),'entry16_hex':fw[offset:offset+16].hex()})
dataset='mouse-wireless-startup-original.jsonl';rows=[json.loads(l) for l in (A/dataset).open()];n=len(rows)
assert n==3712 and [r['case'] for r in rows]==list(range(n))
sourcepaths=[fwpath,P/'mouse_wireless_startup.c',P/'mouse_wireless_startup.h',A/'mouse-wireless-startup-map.json',A/'mouse-wireless-startup-map.md',A/'run_mouse_wireless_startup_oracle.py']
x={'status':'PASS','phase':66,'firmware_sha256':sha(fwpath),'sources':{str(p.relative_to(R)):sha(p) for p in sourcepaths},'entry_spans':spans,'comparison':v,'dataset_coverage':[{'file':dataset,'cases':n,'sha256':sha(A/dataset)}],'original_inputs':n,'original_steps':v['original_steps'],'full_returns':v['full_returns'],'limits':v['limits'],'api':['rr_mouse_wireless_startup','rr_mouse_wireless_setup','rr_mouse_scan_work_initialize','rr_mouse_thread_create','rr_mouse_thread_start','rr_mouse_ticks_sleep','rr_mouse_public_sleep']}
write(A/'mouse-wireless-startup-exact.json',x)
s=read(A/'recovered-code-validation-summary.json');archive=A/'recovered-code-validation-phase65-frozen.json'
if not archive.exists():write(archive,s)
s['datasets'][dataset]={'cases':n,'sha256':sha(A/dataset)}
s['verification_results']['mouse-wireless-startup-comparison.json']=sha(A/'mouse-wireless-startup-comparison.json')
s['sources']={str(p.relative_to(R)):sha(p) for p in files+sorted(P.glob('*.h'))+[P/'Makefile']}
s['libraries']={str(p.relative_to(R)):sha(p) for p in [P/'build/librr_recovered.a',lib]};s['library_sha256']=sha(P/'build/librr_recovered.a')
s['unique_original_input_count']=sum(d['cases'] for d in s['datasets'].values());assert s['unique_original_input_count']==215552+n
s['integrated_host_link']='69 C11 units strictly compiled and linked as host static/shared libraries; current shared librr_recovered69.dylib; prior snapshots retained. Not a complete MCU image.'
s['mouse_wireless_startup_integration']={'file':'mouse-wireless-startup-exact.json','sha256':sha(A/'mouse-wireless-startup-exact.json')}
s['execution_boundaries']['mouse_wireless_startup']={'total':n,'full_returns':v['full_returns'],'CPU_requests':v['CPU_requests'],'not_modeled':'CPUrequest continuation, settings/mode sources, physical peripheral and RF behavior'}
s['updated_at']=datetime.datetime.now(datetime.timezone.utc).isoformat();write(A/'recovered-code-validation-summary.json',s)
print(json.dumps({'status':'PASS','new_cases':n,'steps':v['original_steps'],'total_cases':s['unique_original_input_count'],'units':69,'datasets':len(s['datasets'])},indent=2))
