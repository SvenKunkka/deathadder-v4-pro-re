from pathlib import Path
import subprocess,os,json
R=Path(__file__).resolve().parent.parent;A=R/'analysis';G=R/'ghidra-scripts'
env=dict(os.environ,JAVA_HOME='/opt/homebrew/opt/openjdk@25/libexec/openjdk.jdk/Contents/Home')
output=A/'mouse-initialization-original.jsonl'
rows=[json.loads(l) for l in output.read_text().splitlines()] if output.exists() else []
assert [r['case'] for r in rows]==list(range(len(rows)))
for start in range(len(rows),3840,256):
 end=min(start+256,3840)
 cmd=['/opt/homebrew/opt/ghidra/libexec/support/analyzeHeadless','./local-ghidra-projects','mouse120','-process','Suit2FWData__radio_radio.bin','-readOnly','-noanalysis','-scriptPath',str(G),'-postScript','EmulateMouseInitialization.java',str(output),str(R/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin'),str(start),str(end)]
 p=subprocess.run(cmd,env=env,text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
 (A/f'mouse-initialization-oracle-{start}.log').write_text(p.stdout)
 marker=f'MOUSE_INITIALIZATION_RANGE={start}:{end}'
 if p.returncode or marker not in p.stdout:raise RuntimeError(p.stdout[-6000:])
 print(marker,flush=True)
