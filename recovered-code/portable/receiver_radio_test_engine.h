#ifndef RR_RECEIVER_RADIO_TEST_ENGINE_H
#define RR_RECEIVER_RADIO_TEST_ENGINE_H
#include "receiver_radio_test_bus.h"
typedef struct { uint32_t disabled_value, consumed; } rr_rt_event;
typedef int (*rr_rt_dependency)(void*,rr_rt_bus*,uint32_t,const uint32_t args[5],rr_rt_pending*);
/* The extended entry calls supplied real dependency bodies synchronously.
 * Legacy APIs below pass NULL and retain their original call boundaries. */
int rr_receiver_radio_test_engine_with_dependencies(rr_rt_bus*,uint32_t,const uint32_t args[5],rr_rt_event*,rr_rt_pending*,rr_rt_dependency,void*);
int rr_receiver_radio_test_flow_with_dependencies(rr_rt_bus*,uint32_t,const uint32_t args[5],rr_rt_event*,rr_rt_pending*,rr_rt_dependency,void*);
/* Explicit event supplied at first EVENTS_DISABLED poll; NULL/zero stops at
 * poll, without inventing completion. Each invocation has at most one poll.
 * No implicit SET/CLR, TIMER, EGU, RADIO or GPPI effects exist in snapshots.
 * Return0: function returned;1: pending call/event; -2: unsupported input.
 * Pending is an observation, not a continuation token. No automatic resume.
 * Entry: C7F4,C8A0,C8FC,C9EC,CAC4,CB44,CBB8,CC4C,CD04,CD78,D028.
 * RAM/ROM and explicit window sizes must be valid; privileged serialized CPU.
 * RTC entropy path supports a stable RTC high<=3fffffff, otherwise -4.
 */
int rr_receiver_radio_test_engine(rr_rt_bus*,uint32_t entry,const uint32_t args[5],
    rr_rt_event*,rr_rt_pending*);
/* Connects the previously recovered parameter/work functions to this real
 * engine. An explicitly supplied event value is used at EACH disabled poll.
 * Resumes only verified source continuations after engine calls return.
 * Normal radio-stop/init and logging remain genuine call boundaries. */
int rr_receiver_radio_test_control_flow(rr_rt_bus*,uint32_t entry,
    const uint32_t args[5],rr_rt_event*,rr_rt_pending*);
#endif
