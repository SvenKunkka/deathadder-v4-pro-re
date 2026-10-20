#ifndef RR_RECEIVER_WORKER_RUNTIME_H
#define RR_RECEIVER_WORKER_RUNTIME_H
#include "receiver_timeout.h"
#include "receiver_usb_reports.h"
/* Receiver1.20: serialized privilegedCPU, RAM128KiB, RTC/aux4KiB each.
 * Helper APIs preserve actual writes up to realCPU entry0E0611CC.
 * Work step0=next loop header0E06D1BA, NOT thread termination;
 * 1=actual unknown callback/USB/CPU entry, negative=domain bound.
 * Known callback23026D29 executes USB-report software. NULL driver stops at
 * realUSB0E064288; non-NULL hook is an explicit external outcome/side effect.
 * Does not resume CPU exception return or model asynchronous concurrency.
 */
/* Optional non-USB handler receives the actual odd firmware callback and
 * work address after the worker has dequeued and marked work running.
 * Returning zero means that implementation actually finished the callback;
 * then the original flush/cancel/yield tail runs. Nonzero preserves its
 * genuine boundary/error and does not advance that tail. NULL retains the
 * original unknown-callback boundary. USB callback stays on its existing
 * recovered path, independent of this handler. No async resume is implied. */
typedef int (*rr_receiver_worker_callback)(void *context,uint32_t callback,
    uint32_t work,rr_receiver_rtos *cpu);
int rr_receiver_work_thread_step_with_handler(uint8_t*,uint8_t*,uint8_t*,uint32_t,
    rr_receiver_rtos*,rr_receiver_usb_external_driver,void*,rr_receiver_usb_call*,
    rr_receiver_worker_callback,void*);
int rr_receiver_wait_wake(uint8_t*,uint8_t*,uint32_t,uint32_t,uint32_t,rr_receiver_rtos*,int32_t*);
int rr_receiver_worker_yield(uint8_t*,uint8_t*,rr_receiver_rtos*);
int rr_receiver_worker_pend(uint8_t*,uint8_t*,uint32_t,uint32_t,uint64_t,rr_receiver_rtos*);
int rr_receiver_work_thread_step(uint8_t*,uint8_t*,uint8_t*,uint32_t,rr_receiver_rtos*,rr_receiver_usb_external_driver,void*,rr_receiver_usb_call*);
#endif
