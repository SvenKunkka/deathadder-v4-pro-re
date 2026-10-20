from pathlib import Path
import subprocess,os,json
R=Path(__file__).resolve().parent.parent;A=R/'analysis';G=R/'ghidra-scripts'
env=dict(os.environ,JAVA_HOME='/opt/homebrew/opt/openjdk@25/libexec/openjdk.jdk/Contents/Home')
output=A/'receiver-vendor-flow-original.jsonl'
rows=[json.loads(l) for l in output.read_text().splitlines()] if output.exists() else []
assert [r['case'] for r in rows]==list(range(len(rows)))
for start in range(len(rows),6144,256):
 cmd=['/opt/homebrew/opt/ghidra/libexec/support/analyzeHeadless','./local-ghidra-projects','dongle120','-process','Suit1FWData__radio_radio.bin','-readOnly','-noanalysis','-scriptPath',str(G),'-postScript','EmulateReceiverVendorFlow.java',str(A/'receiver-vendor-flow-original.jsonl'),str(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin'),str(start),str(min(start+256,6144))]
 p=subprocess.run(cmd,env=env,text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
 (A/f'receiver-vendor-flow-oracle-{start}.log').write_text(p.stdout)
 marker=f'RECEIVER_VENDOR_FLOW_RANGE={start}:{min(start+256,6144)}'
 if p.returncode or marker not in p.stdout:raise RuntimeError(p.stdout[-6000:])
 print(marker,flush=True)
