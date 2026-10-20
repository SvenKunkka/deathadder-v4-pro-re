from pathlib import Path
import json,hashlib,gzip,base64,datetime
R=Path(__file__).resolve().parent.parent;A=R/'analysis';P=R/'recovered-code/portable'
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1048576),b''):h.update(b)
 return h.hexdigest()
def read(n):return json.loads((A/n).read_text())
def write(p,v):p.write_text(json.dumps(v,ensure_ascii=False,indent=2)+'\n')
comparisons=['receiver-application-timers-comparison.json','receiver-rtc-application-timers-comparison.json','receiver-timer-user-handlers-regression.json','receiver-timer-user-handlers-continuous-regression.json','receiver-application-timers-continuous-comparison.json']
reports={n:read(n) for n in comparisons}
assert all(v['status']=='PASS' for v in reports.values())
data=[];all_initial=set()
for n,num in [('receiver-application-timers-original.jsonl',4096),('receiver-rtc-application-timers-original.jsonl',2048)]:
 ids=[];keys=set()
 for line in (A/n).open():
  t=json.loads(line);ids.append(t['case']);raw=gzip.decompress(base64.b64decode(t['ram_before']));keys.add(hashlib.sha256(raw).hexdigest())
  for name in ['ram','radio','timer','nvic','dppi','rtc','clock0','clock1','clock2','deviceid']:
   for side in ['before','after']:assert len(gzip.decompress(base64.b64decode(t[name+'_'+side])))==(131072 if name=='ram' else 8 if name=='deviceid' else 4096)
 assert ids==list(range(num)) and len(keys)==num and not(keys&all_initial);all_initial|=keys
 data.append({'file':n,'cases':num,'sha256':sha(A/n)})
notes={'status':'PASS','root_cause':'New combined emulator accidentally allocated2048B rather than4096B MMIO windows during a text substitution. Initial host comparison overran these buffers; no recovered C defect inferred.','resolution':'Corrected emulator allocations to4096, regenerated all2048 original records and added strict size assertions before C invocation. Full host comparison passed after correction.','invalid_run_directory':'analysis/receiver-app-harness-diagnostic','invalid_original_records_counted':False,'sanitizer_attempt':'Standalone sanitizer diagnostic was terminated before yielding output; no sanitizer pass claimed.','valid_dataset_dimensions':{'ram':131072,'MMIO_each':4096,'deviceid':8},'valid_new_inputs':6144,'within_and_between_dataset_RAM_duplicates':0,'sources':{str((R/'ghidra-scripts/EmulateReceiverRtcApplicationTimers.java').relative_to(R)):sha(R/'ghidra-scripts/EmulateReceiverRtcApplicationTimers.java'),'analysis/verify_receiver_rtc_application_timers.py':sha(A/'verify_receiver_rtc_application_timers.py')}}
write(A/'receiver-application-timers-execution-notes.json',notes)
fw=(R/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes();entries=[]
for addr,role in [(0x230255d0,'start radio and schedule stop'),(0x230255f8,'stop radio and schedule start'),(0x23025640,'periodic ratios and class3/USB reports'),(0x230256e8,'status countdowns, classification, config event4 and reboot boundary')]:
 off=0x79c+addr-0x23020000;entries.append({'address':hex(addr),'role':role,'image_offset':hex(off),'entry16_hex':fw[off:off+16].hex()})
sources={str(p.relative_to(R)):sha(p) for p in sorted(P.glob('*.c'))+sorted(P.glob('*.h'))}
for n in comparisons+['receiver-application-timers-execution-notes.json','receiver-application-timer-map.json','receiver-timer-v1-before-appcallbacks/manifest.json']:sources['analysis/'+n]=sha(A/n)
for addr in ['230255d0','230255f8','23025640','230256e8']:
 p=A/'dongle-radio-1.20-final'/f'{addr}.c';sources[str(p.relative_to(R))]=sha(p)
new=[reports[n] for n in comparisons[:2]];returns=sum(v['endings'].get('0x0',0) for v in new);steps=sum(v['original_steps'] for v in new)
x={'status':'PASS','firmware_sha256':hashlib.sha256(fw).hexdigest(),'original_inputs':6144,'original_steps':steps,'full_function_returns':returns,'entry_boundaries':6144-returns,'sources':sources,'entry_spans':entries,'dataset_coverage':data,'direct_comparison':new[0],'RTC_chain_comparison':new[1],'component_integration':reports[comparisons[4]],'legacy_regression':reports[comparisons[2]],'legacy_continuous_regression':reports[comparisons[3]],'limits':['Official firmware static callbacks recovered, not proof that all possible dynamic registrations have been exhausted','Unknown callbacks, CPU switch and reboot retain entry boundaries','Opaque32B event tail is supplied explicitly; combined comparison observes original callback SP-56, does not reconstruct full CPU stack','Hardware events/readback are explicit stable snapshots; no physical receiver, USB/RF transfer, full boot or concurrency validation']}
write(A/'receiver-application-timers-exact.json',x)
md=f'''# 接收器四个应用定时器回调恢复（官方 1.20）

四个静态注册回调已恢复为 C，并接入 RTC → clock → timeout → 通用 timer → 用户回调链。新增 **6,144 组原指令输入对照通过**，共 {steps:,} 步原指令；完整返回 {returns:,} 组，其余在真实 CPU/复位入口或注入的未知 stop 回调前停止。未执行设备写入或复位。

[实现](../recovered-code/portable/receiver_application_timers.c) · [接口](../recovered-code/portable/receiver_application_timers.h) · [原字节与来源](receiver-application-timers-exact.json)

|回调|恢复行为|
|---|---|
|230255D0|登记 100,000 tick 的停止定时器，初始化无线并恢复相关线程、发出信号量|
|230255F8|登记 400,000 tick 的启动定时器，停止无线；连接存在时清状态并生成断连通知|
|23025640|两个计数比值取低 8 位；按周期登记 class3 的 AC 报文，并生成 `05 FE 72` 统计 USB 报告|
|230256E8|按阈值更新状态码，处理断连倒计时和 timer-stop，投递配置事件4；连接看门计数归零时停在复位入口|

具体周期单位保留为固件 tick，未由这些测试换算实际射频时间。各统计字段的产品业务名称尚不能仅凭地址确定。

直接回调对照 4,096 组，完整 RTC 调用链 2,048 组，均比较 128 KiB RAM、八个 4 KiB 外设窗口、8 字节设备 ID、优先级和入口边界；组合入口额外检查 pending 参数。旧通用 timer 的 8,192 组原指令输入及 128 轮断连连续路径回归通过，回归未重复计入总数。

[直接结果](receiver-application-timers-comparison.json) · [RTC组合结果](receiver-rtc-application-timers-comparison.json) · [旧行为回归](receiver-timer-user-handlers-regression.json) · [旧连续路径](receiver-timer-user-handlers-continuous-regression.json)

连续组件共输入 193 次 RTC 事件，完成 32 次启动和 32 次停止、64 次统计回调（16 条统计 USB 报告）、64 次状态回调及配置事件收取，最后核对一次复位入口边界。事件4的 32 字节旧栈尾部显式提供，保留原内容；没有把这些字节伪造成零，也没有恢复完整 CPU 栈生成过程。[连续结果](receiver-application-timers-continuous-comparison.json)

新组合验证脚本曾误分配 2 KiB 外设窗口，造成主机越界。已保存错误批次，修正为 4 KiB 后重新执行全部组合输入；错误批次不计数。独立 sanitizer 尝试未产生结果，不宣称通过。[执行说明](receiver-application-timers-execution-notes.json)

原通用 timer 的 C/h 已保存于[基线归档](receiver-timer-v1-before-appcallbacks/manifest.json)。其旧接口边界不变，新增可选用户回调处理器；更早 RTC 基线另行保留。累计 **54 个 C 单元、75 份数据集、167,168 组原指令输入**。当前主机共享库为 `recovered-code/portable/build/librr_recovered54.dylib`，不代表可烧录 MCU 工程。

[原静态 timer 表](receiver-application-timer-map.json)中的五个已知用户回调现均有恢复实现；该旧表“仅1A30已接入”的进度描述已由本报告更新。未知动态回调、延迟工作、RTC其余回调、完整启动、跨核来源、硬件异常返回与真实空口验证仍未完成。用户暂时无接收器，因此此阶段不包含两端实机验证。
'''
(A/'receiver-application-timers-exact.md').write_text(md)
s=read('recovered-code-validation-summary.json');archive=read('receiver-timer-v1-before-appcallbacks/manifest.json')['files']
for rel,e in archive.items():assert s['sources'][rel]==e['sha256'] and sha(R/e['frozen_path'])==e['sha256']
for p in sorted(P.glob('*.c'))+sorted(P.glob('*.h')):s['sources'][str(p.relative_to(R))]=sha(p)
s['historical_source_snapshots'].update(archive)
for d in data:s['datasets'][d['file']]={'cases':d['cases'],'sha256':d['sha256']}
for n in comparisons:s['verification_results'][n]=sha(A/n)
for field,n in [('receiver_application_timers_integration',comparisons[4]),('receiver_timer_user_handlers_regression',comparisons[2]),('receiver_timer_user_handlers_continuous_regression',comparisons[3]),('receiver_timer_v1_archive','receiver-timer-v1-before-appcallbacks/manifest.json'),('receiver_application_timers_execution_notes','receiver-application-timers-execution-notes.json')]:s[field]={'file':n,'sha256':sha(A/n)}
s['libraries']={str(p.relative_to(R)):sha(p) for p in [P/'build/librr_recovered.a',P/'build/librr_recovered54.dylib']};s['library_sha256']=sha(P/'build/librr_recovered.a');s['unique_original_input_count']=sum(d['cases'] for d in s['datasets'].values());assert s['unique_original_input_count']==167168 and len(s['datasets'])==75
s['integrated_host_link']='all54 C translation units compiled C11 Wall Wextra Werror pedantic and linked into host static/shared libraries; current shared librr_recovered54.dylib; older shared snapshots retained. No full MCU image.';s['updated_at']=datetime.datetime.now(datetime.timezone.utc).isoformat();write(A/'recovered-code-validation-summary.json',s)
p=R/'逆向进度与代码入口.md';text=p.read_text();assert '当前累计53个C单元、73份数据集、161,024组原指令输入' in text;text=text.replace('当前累计53个C单元、73份数据集、161,024组原指令输入','当前累计54个C单元、75份数据集、167,168组原指令输入',1);text+='\n## 接收器四个应用定时器回调及 RTC 接线\n\n恢复无线交替启停、统计/状态报告、断连和配置事件倒计时，并保留真实复位入口边界。新增6,144组原指令对照通过；旧timer8,192组及128轮断连连续验证回归通过。193次显式RTC事件的连续组件检查通过。\n\n[本阶段代码、范围与验证](analysis/receiver-application-timers-exact.md)。累计54个C单元与167,168组原指令输入；仍未完成整机启动、未知回调及真实RF互通。此前阶段章节保留历史口径。\n';p.write_text(text)
p=P/'README.md';text=p.read_text().replace('**53 个 C11 单元**','**54 个 C11 单元**',1).replace('**161,024 组原指令输入差分通过**','**167,168 组原指令输入差分通过**',1);text=text.replace('|receiver_timer_expiry.c/.h|','|receiver_application_timers.c/.h|四个应用timer的无线启停、统计/状态、倒计时、配置事件及RTC组合|未知回调/复位/CPU边界；旧栈尾部及外设事件显式输入|\n|receiver_timer_expiry.c/.h|',1);text+='\n## 应用 timer 回调接线（54 单元版本）\n\n新增四个静态注册用户回调与可选handler，保留原timer API边界。6,144组新原指令对照、8,192组旧回归、128轮旧断连及193次新RTC连续事件检查通过。共享构建为 `build/librr_recovered54.dylib`。\n\n[详细证据与限制](../../analysis/receiver-application-timers-exact.md)。五个已知静态timer用户回调均已接入；全系统启动/动态回调/实际射频仍不完整。\n';p.write_text(text)
p=R/'investigation-status.json';state=json.loads(p.read_text());state['updated_at']=s['updated_at'];state['completed'].append('接收器四个应用timer255D0/255F8/25640/256E8及完整RTC接线恢复；6144新增原输入通过；8192旧timer和128轮断连回归；193RTC连续事件检查通过；累计54单元167168输入')
state['next_resume']['primary_inputs']=['analysis/receiver-application-timers-exact.md','analysis/phase-receiver-application-timers-integrity.json','analysis/receiver-application-timers-execution-notes.json']+state['next_resume']['primary_inputs']
state['next_resume']['next_high_value']='54 C units /167168 inputs /75 datasets. Four app callbacks255D0/255F8/25640/256E8 now implement and integrate via rr_receiver_rtc_application_timers. Direct4096 and RTC2048 original comparisons passed, old8192 timer+128cycles regression. New193RTC events:32on32off,64stats/16USB,64state/config,1reboot boundary. timer c/h baseline archived receiver-timer-v1-before-appcallbacks; integrity historical keys now4(2RTC+2timer). Initial combined fixture MMIO accidentally2048B fixed4096; invalid run preserved separately, not counted. Next remaining receiver deferred work, RTC BDE0/BE20/BE4C boot, full crosscore/CPU continuation. No receiver, no writes. Current shared librr_recovered54.dylib.'
state['last_phase']={'classification':'progress','goal_complete':False,'new_original_instruction_cases':6144,'total_original_instruction_cases':167168,'compiled_c_units':54,'compiled_c_verified':True,'hardware_operations':False,'new_original_steps':steps,'normal_returns':returns,'entry_boundaries':6144-returns,'legacy_timer_regression_cases':8192,'legacy_disconnect_cycles':128,'continuous_RTC_events':193,'integrity_report':'analysis/phase-receiver-application-timers-integrity.json','integrity_status':'PENDING','limits':x['limits']}
state['pending']=[v.replace('应用timer/work到期回调','其他动态timer/work到期回调') for v in state['pending']];write(p,state)
print('Prepared54-unit manifest and reports; integrity audit still pending',returns,steps)
