from pathlib import Path
import subprocess,os
R=Path(__file__).resolve().parents[2];A=R/'analysis/frame-sync'
env=dict(os.environ,JAVA_HOME='/opt/homebrew/opt/openjdk@25/libexec/openjdk.jdk/Contents/Home')
for name,project,suit,n in [('mouse','mouse120',2,304),('receiver','dongle120',1,160)]:
 out=A/(name+'-timing-original.jsonl');log=A/(name+'-timing.log')
 if out.exists() and log.exists() and f'FRAME_SYNC_COMPLETE={name}:{n}' in log.read_text():continue
 cmd=['/opt/homebrew/opt/ghidra/libexec/support/analyzeHeadless','./local-ghidra-projects',project,'-process',f'Suit{suit}FWData__radio_radio.bin','-readOnly','-noanalysis','-scriptPath',str(R/'ghidra-scripts'),'-postScript','EmulateFrameSync.java',str(out),str(R/f'firmware-extracted-1.20/Suit{suit}FWData__radio_radio.bin'),name]
 p=subprocess.run(cmd,env=env,text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT);log.write_text(p.stdout)
 if p.returncode or f'FRAME_SYNC_COMPLETE={name}:{n}' not in p.stdout:raise RuntimeError(p.stdout[-5000:])
 print(f'FRAME_SYNC_COMPLETE={name}:{n}',flush=True)
