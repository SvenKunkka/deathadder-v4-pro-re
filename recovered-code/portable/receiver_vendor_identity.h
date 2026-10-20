#ifndef RR_RECEIVER_VENDOR_IDENTITY_H
#define RR_RECEIVER_VENDOR_IDENTITY_H
#include "receiver_vendor_flow.h"
/* Receiver 1.20 identity producers 230252A4 / 23025300 and their vendor
 * callers 2302604C / 23026090 / 230205F8. stack_before contains the exact
 * 512 bytes [initial SP-512, initial SP), before the selected root executes.
 * The original producers copy 28 uninitialized stack bytes into their queue
 * message. This input preserves those bytes; it is not a zero-fill policy.
 * Uses the same bus/windows and boundary conventions as vendor_flow.
 * A successful producer return means enqueued/delivered, not applied by the
 * configuration thread. No CPU-switch continuation is synthesized. */
int rr_receiver_vendor_identity_flow(rr_rt_bus*,uint32_t,uint32_t,uint32_t,
                                    const uint8_t stack_before[512],rr_rt_event*,rr_rt_pending*);
/* First nonempty worker iteration directly invoking205F9, without a prior
 * callback/wait/scheduler modifying this stack. stack_before is relative to
 * the worker's entry SP, not the vendor callback's SP. */
int rr_receiver_vendor_identity_work_step(rr_rt_bus*,uint32_t,uint32_t,
                                         const uint8_t stack_before[512],rr_rt_event*,rr_rt_pending*);
#endif
