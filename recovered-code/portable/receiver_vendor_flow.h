#ifndef RR_RECEIVER_VENDOR_FLOW_H
#define RR_RECEIVER_VENDOR_FLOW_H
#include "receiver_radio_test_engine.h"
/* Official receiver1.20, serialized privileged execution. Bus contains128KiB
 * RAM, official image, RADIO/TIMER021/EGU/DPPI/RTC/NVIC/TIMER020 windows,
 * device ID8B at0FFFE010 and boot16B atF000. Worker additionally needs
 * auxiliary4KiB at5F9A2000. No hardware effects are automatically generated.
 * entry2604C/26090/205F8, statistics24DB4 or wrappers2048C/20510/20530. The test wrappers
 * execute real control, work-submit and caller return tails. Other unresolved
 * vendor commands retain original entry/arguments.0=returned,1=boundary,
 * negative=unsupported/invalid state. Explicit event consumed per reachedpoll.
 */
int rr_receiver_vendor_flow(rr_rt_bus*,uint32_t,uint32_t,uint32_t,rr_rt_event*,rr_rt_pending*);
/* Runs actual worker through vendor callback205F9 and knownUSB software.
 *0=next loop header, not thread exit;1=CPU/driver/unknowncallback/event boundary.
 * No callback result or USB outcome substitution. */
int rr_receiver_vendor_work_step(rr_rt_bus*,uint32_t,uint32_t,rr_rt_event*,rr_rt_pending*);
#endif
