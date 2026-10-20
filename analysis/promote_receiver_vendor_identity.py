from pathlib import Path
import json,hashlib,subprocess,datetime
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def read(p):return json.loads(p.read_text())
def write(p,d):p.write_text(json.dumps(d,indent=2,ensure_ascii=False)+'\n')
v=read(A/'receiver-vendor-identity-comparison.json')
assert v['status']=='PASS' and not v['failures']
for field in ['sources','libraries']:
 for rel,h in v[field].items():assert sha(R/rel)==h,rel
files=sorted(P.glob('*.c'));assert len(files)==67
subprocess.run(['make','-C',str(P)],check=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
lib=P/'build/librr_recovered67.dylib'
subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True)
fwpath=R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin';fw=fwpath.read_bytes()
entries=[0x230252a4,0x23025300,0x2302604c,0x23026090,0x230205f8,0xe06d19c,0x23024e46,0x23020fcc,0x23021094,0x23020108]
spans=[]
for address in entries:
 offset=address-0x23020000+0x79c if address>=0x23020000 else address-0xe054000
 spans.append({'address':hex(address),'image_offset':hex(offset),'entry16_hex':fw[offset:offset+16].hex()})
dataset='receiver-vendor-identity-original.jsonl';rows=[json.loads(l) for l in (A/dataset).open()];n=len(rows)
assert n==3584 and [r['case'] for r in rows]==list(range(n))
sourcepaths=[fwpath,P/'receiver_vendor_identity.c',P/'receiver_vendor_identity.h',A/'receiver-vendor-identity-stack.json',A/'receiver-vendor-identity-stack.md',A/'run_receiver_vendor_identity_oracle.py']
x={'status':'PASS','phase':64,'firmware_sha256':sha(fwpath),'sources':{str(p.relative_to(R)):sha(p) for p in sourcepaths},'entry_spans':spans,'comparison':v,'dataset_coverage':[{'file':dataset,'cases':n,'sha256':sha(A/dataset)}],'original_inputs':n,'original_steps':v['original_steps'],'endings':v['endings'],'limits':['Host reconstruction, not complete bootable MCU firmware','The exact 28 residual stack bytes are input from initial512Bsnapshot; only first direct worker iteration proven','Identity producer return is distinct from config application; consumer invocation is an explicitly staged software handoff, not a CPU context switch','Full128KiBRAM,eight4KiBMMIO,deviceID8B,boot16B; privileged sequential CPU; scratch stack excluded except escaped bytes','No automatic peripheral effects, actual RF, concurrency, board or physical receiver validation','No receiver or hardware writes'],'api':['rr_receiver_vendor_identity_flow','rr_receiver_vendor_identity_work_step']}
write(A/'receiver-vendor-identity-exact.json',x)
s=read(A/'recovered-code-validation-summary.json');archive=A/'recovered-code-validation-phase63-frozen.json'
if not archive.exists():write(archive,s)
s['datasets'][dataset]={'cases':n,'sha256':sha(A/dataset)}
s['verification_results']['receiver-vendor-identity-comparison.json']=sha(A/'receiver-vendor-identity-comparison.json')
s['sources']={str(p.relative_to(R)):sha(p) for p in files+sorted(P.glob('*.h'))+[P/'Makefile']}
s['libraries']={str(p.relative_to(R)):sha(p) for p in [P/'build/librr_recovered.a',lib]};s['library_sha256']=sha(P/'build/librr_recovered.a')
s['unique_original_input_count']=sum(d['cases'] for d in s['datasets'].values());assert s['unique_original_input_count']==208128+n
s['integrated_host_link']='67 C11 units strictly compiled and linked as host static/shared libraries; current shared librr_recovered67.dylib; prior snapshots retained. Not a complete MCU image.'
s['receiver_vendor_identity_integration']={'file':'receiver-vendor-identity-exact.json','sha256':sha(A/'receiver-vendor-identity-exact.json')}
s['execution_boundaries']['receiver_vendor_identity']={'total':n,'endings':v['endings'],'not_modeled':'CPU context switch continuation, LED/update handlers, physical peripheral or RF behavior'}
s['updated_at']=datetime.datetime.now(datetime.timezone.utc).isoformat();write(A/'recovered-code-validation-summary.json',s)
print(json.dumps({'status':'PASS','new_cases':n,'steps':v['original_steps'],'total_cases':s['unique_original_input_count'],'units':67,'datasets':len(s['datasets'])},indent=2))
