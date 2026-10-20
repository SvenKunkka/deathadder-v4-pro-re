from pathlib import Path
import subprocess,os
R=Path(__file__).resolve().parent.parent;A=R/'analysis';G=R/'ghidra-scripts'
env=dict(os.environ,JAVA_HOME='/opt/homebrew/opt/openjdk@25/libexec/openjdk.jdk/Contents/Home')
for start in range(0,2048,256):
 cmd=['/opt/homebrew/opt/ghidra/libexec/support/analyzeHeadless','./local-ghidra-projects','dongle120','-process','Suit1FWData__radio_radio.bin','-readOnly','-noanalysis','-scriptPath',str(G),'-postScript','EmulateReceiverRadioTestFlow.java',str(A/'receiver-radio-flow-original.jsonl'),str(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin'),str(start),str(min(start+256,2048))]
 p=subprocess.run(cmd,env=env,text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
 (A/f'receiver-radio-flow-oracle-{start}.log').write_text(p.stdout)
 marker=f'RECEIVER_RADIO_FLOW_RANGE={start}:{min(start+256,2048)}'
 if p.returncode or marker not in p.stdout:raise RuntimeError(p.stdout[-6000:])
 print(marker,flush=True)
