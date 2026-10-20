from pathlib import Path
import subprocess,os
R=Path(__file__).resolve().parent.parent;A=R/'analysis';G=R/'ghidra-scripts'
env=dict(os.environ,JAVA_HOME='/opt/homebrew/opt/openjdk@25/libexec/openjdk.jdk/Contents/Home')
for start in range(0,3328,256):
 end=min(start+256,3328)
 cmd=['/opt/homebrew/opt/ghidra/libexec/support/analyzeHeadless','./local-ghidra-projects','dongle120','-process','Suit1FWData__radio_radio.bin','-readOnly','-noanalysis','-scriptPath',str(G),'-postScript','EmulateReceiverRadioLog.java',str(A/'receiver-radio-log-original.jsonl'),str(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin'),str(start),str(end)]
 p=subprocess.run(cmd,env=env,text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
 (A/f'receiver-radio-log-oracle-{start}.log').write_text(p.stdout)
 marker=f'RECEIVER_RADIO_LOG_RANGE={start}:{end}'
 if p.returncode or marker not in p.stdout:raise RuntimeError(p.stdout[-6000:])
 print(marker,flush=True)
