#ifndef RR_MOUSE_WORKER_RUNTIME_H
#define RR_MOUSE_WORKER_RUNTIME_H
#include "mouse_scanning.h"
/* 0=return (runtime worker: next loop header); 1=actual CPU/unknown
 * callee entry in cpu. Negative codes are analysis-domain boundaries;
 * existing mutations remain. Pend/yield stop BEFORE CPU switch request.
 * Pend models the pre-switch path of original 0e09628c, including its
 * 64-bit stack timeout. Post-switch output pointer is not executed. */
int rr_mouse_wait_wake(uint8_t*,uint8_t*,uint32_t,uint32_t,uint32_t,rr_mouse_rtos*,int32_t*);
int rr_mouse_worker_yield(uint8_t*,uint8_t*,rr_mouse_rtos*);
int rr_mouse_worker_pend(uint8_t*,uint8_t*,uint32_t,uint32_t,uint64_t,rr_mouse_rtos*);
int rr_mouse_delayed_work_expiry(uint8_t*,uint8_t*,uint32_t,rr_mouse_rtos*);
int rr_mouse_work_thread_runtime(uint8_t*,uint8_t*,uint8_t*,uint32_t,rr_mouse_rtos*);
int rr_mouse_work_thread_scanning_runtime(rr_mouse_scan_hw*,uint32_t,rr_mouse_rtos*);
#endif
