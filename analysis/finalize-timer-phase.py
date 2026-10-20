"""Refresh current phase indexes after independently verified builds/tests."""
from pathlib import Path
import json, hashlib, datetime
R=Path(__file__).resolve().parent.parent; A=R/'analysis'; P=R/'recovered-code/portable'
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1048576),b''):h.update(b)
 return h.hexdigest()
def read(p):return json.loads(p.read_text())
def save(p,d):p.write_text(json.dumps(d,ensure_ascii=False,indent=2)+'\n')
d=read(A/'recovered-code-validation-summary.json')
for name,n in [('mouse-timer-lifecycle-original.jsonl',1920),('mouse-ack-lifecycle-original.jsonl',384),('receiver-radio-timer-original.jsonl',2304),('mouse-mode4-original.jsonl',3072)]:
 p=A/name
 with p.open() as f:count=sum(bool(s.strip()) for s in f)
 assert count==n,(name,count)
 d['datasets'][name]={'cases':n,'sha256':sha(p)}
for name in ['mouse-timer-lifecycle-comparison.json','receiver-radio-timer-comparison.json','mouse-mode4-comparison.json','mouse-radio-irq-comparison.json']:
 result=read(A/name);assert result['status']=='PASS',name
 d['verification_results'][name]=sha(A/name)
for name in list(d['verification_results']):d['verification_results'][name]=sha(A/name)
sources=sorted(P.glob('*.c'))+sorted(P.glob('*.h'))+[P/'Makefile'];units=len(list(P.glob('*.c')));assert units==20
count=sum(x['cases'] for x in d['datasets'].values());assert count==26496
now=datetime.datetime.now(datetime.timezone.utc).isoformat()
d.update(unique_original_input_count=count,integrated_host_link=f'all{units} C translation units compiled C11 Wall Wextra Werror pedantic and linked into host static/shared libraries; no MCU startup/linker/HAL',sources={str(p.relative_to(R)):sha(p) for p in sources},updated_at=now)
d['libraries']={str(p.relative_to(R)):sha(p) for p in [P/'build/librr_recovered.a',P/'build/librr_recovered.dylib']};d['library_sha256']=sha(P/'build/librr_recovered.dylib')
d['limits']=['bounded modules, not full firmware','host build only; no MCU startup/linker/HAL','original-input total includes declared entry-to-boundary and post-driver segment cases; not complete device transactions','42 TX cases inject explicit external queue state changes','USB driver, RTOS timer callbacks/waiters/scheduling, remaining mode4 branches and sensor restart incomplete','no physical RF or concurrency proof']
d['execution_boundaries']['mouse_radio_irq']['not_modeled']='Old API rejects nonzero ACK; new lifecycle API validates known callback in additional384 cases. Top ISR and next timer transmission remain incomplete.'
d['execution_boundaries']['receiver_radio_irq']['not_modeled']='Old1536 scope unchanged; CC0/CC2 added in receiver_radio_timer. Other modes, RTOS tail, PHY/DPPI remain incomplete.'
d['execution_boundaries']['mouse_timer_lifecycle']={'total':2304,'full_returns':2304,'direct_lifecycle':1920,'mode1_mode2_IRQ_through_ACK':384,'not_modeled':'timer stop callback, waiting threads, unknown ACK callback, autonomous RTC'}
d['execution_boundaries']['receiver_radio_timer']={'total':2304,'full_returns':2286,'real_semaphore_entry_stops':18,'not_modeled':'actual semaphore give and wakeup, management queue tail, other modes'}
d['execution_boundaries']['mouse_mode4']={'total':3072,'radio':1536,'timer':1024,'actions':256,'explicit_IRQ_then_business_and_adaptive':256,'not_modeled':'idle TX selection; pending rate, selector2/3 recompute, disconnect, nonempty ACK callback'}
for field in ['business_exchange_integration','adaptive_integration','receiver_irq_integration']:
 d[field]['sha256']=sha(A/d[field]['file'])
d['receiver_timer_integration']={'file':'receiver-radio-timer-integration.json','sha256':sha(A/'receiver-radio-timer-integration.json'),'scenarios':16,'timer_events':16408,'valid_rx_business':960,'disconnect_boundaries':8,'not_added_to_original_count':True}
save(A/'recovered-code-validation-summary.json',d)
p=R/'recovered-code/code-index.json';idx=read(p);c=idx['authored_portable_reconstruction'];c['sources']=[str(p.relative_to(R/'recovered-code')) for p in sources if p.name!='Makefile'];c['scope']='20 bounded C units including active-timer/ACK lifecycle, receiver mode4 normal timer and selected mouse mode4 IRQ/timer paths. Not full radio stack.';save(p,idx)
p=R/'investigation-status.json';s=read(p)
items=['活动timer摘链/RTC重设及ACK断开C恢复；2304原指令全部返回通过，含384组mode1/2完整IRQ至非空ACK回调；旧IRQ2944回归通过','接收器mode4正常CC0/CC1/CC2定时路径恢复；2304组通过，其中2286完整返回、18停在真实RTOS信号量入口；16连续场景通过','鼠标mode4 IRQ/选定TIMER/action恢复；3072原指令通过，含256显式IRQ→业务→adaptive交接；空闲发送选择及其他边界保留','20个C单元严格编译合并；29份数据集累计26496组原指令输入差分通过']
for x in items:
 if x not in s['completed']:s['completed'].append(x)
s['pending']=[x for x in s['pending'] if x not in ['鼠标mode4和接收器其他模式IRQ、完整TIMER各分支/发送选择/时槽、顶层状态机与业务入口接线','鼠标class3非空ACK回调23025c2c→23022d88及实际timer停止/断开生命周期','活动timer停止/回调/调度、work真实入队和断开回调']]
s['pending'][:0]=['鼠标mode4空闲TX选包、pending rate/频道plan2或3重算/slot5断开、已恢复ACK生命周期接入mode4','接收器mode1/2等其他模式IRQ/TIMER与顶层接线','接收器mode4断连后的RTOS semaphore、通知队列/管理线程尾段','活动timer的真实stop回调/等待线程及work真实入队/调度；已恢复摘链/RTC重设不等于完整RTOS']
s['updated_at']=now;s['last_phase']={'classification':'progress','goal_complete':False,'new_original_instruction_cases':7680,'total_original_instruction_cases':26496,'compiled_c_units':20,'compiled_c_verified':True,'hardware_operations':False,'receiver_timer_continuous_scenarios':16,'limits':'Known active-timer/ACK paths, receiver normal mode4 timer and bounded mouse mode4 paths; not full firmware/RF or scheduling.'}
s['next_resume']['primary_inputs']=['analysis/mouse-timer-lifecycle-exact.md','analysis/receiver-radio-timer-exact.md','analysis/mouse-mode4-exact.md','analysis/receiver-other-modes-map.md']+s['next_resume']['primary_inputs']
s['next_resume']['next_high_value']='已有20个C模块/26496组原指令输入；不要重复提取。优先补鼠标mode4 action3空闲发送选择、pending rate/selector2或3/slot5断开，接入已有ACK生命周期；按receiver-other-modes-map推进接收器其他模式。接收器断连停在真实semaphore0E06D0D0，继续其无等待线程/等待线程及通知尾段。保留所有已验证行为与显式边界。'
save(p,s)
print(json.dumps({'units':units,'inputs':count,'datasets':len(d['datasets']),'sources':len(sources)}))
