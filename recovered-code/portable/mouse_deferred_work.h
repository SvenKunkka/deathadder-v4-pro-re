#ifndef RR_MOUSE_DEFERRED_WORK_H
#define RR_MOUSE_DEFERRED_WORK_H
#include "mouse_rtc_dispatch.h"
#include "mouse_worker_runtime.h"
/* Original four schedule/reschedule entries share this body. Pass queue
 * 23002498 for default variants; reschedule=0 for095478/0954e0, nonzero for
 *09554c/0955c4. delay is original uint64 register bits (including sentinels).
 * Return status0 means original returned; actual result is *result.
 * Negative codes are model boundaries; previous writes remain. */
int rr_mouse_delayed_work_schedule(uint8_t*,uint8_t*,uint32_t,uint32_t,uint64_t,int,rr_mouse_rtos*,int32_t*);
/* Adds actual timer user callback23025f78 and raw timeout095254 to the
 * existing known scan/thread/timeslice policy. No fake returns or reentry. */
int rr_mouse_timer_expiry_deferred(rr_mouse_scan_hw*,uint32_t,rr_mouse_rtos*);
int rr_mouse_timeout_announce_deferred(rr_mouse_scan_hw*,uint32_t,rr_mouse_rtos*,rr_mouse_rtc_pending*);
int rr_mouse_clock_announce_deferred(rr_mouse_scan_hw*,uint64_t,rr_mouse_rtos*,rr_mouse_rtc_pending*);
int rr_mouse_rtc_dispatch_deferred(rr_mouse_scan_hw*,rr_mouse_rtos*,rr_mouse_rtc_pending*);
#endif
