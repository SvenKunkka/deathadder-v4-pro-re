#ifndef RR_MOUSE_TIMER_STOP_RUNTIME_H
#define RR_MOUSE_TIMER_STOP_RUNTIME_H
#include "mouse_work_queue.h"
/* Original0E096AC4: active timer abort, optional stop callback, then one
 * waiter unpend/ready and actual reschedule decision. Same RAM/RTC windows
 * as mouse_timer_lifecycle. 0=returned,1=actual callback/CPU entry pending;
 * negative values are retained host domain/busy boundaries. No device I/O.
 * Does not write waiter result or abort its timeout. */
int rr_mouse_timer_stop_runtime(uint8_t ram[65536],uint8_t rtc[4096],uint32_t timer_address,rr_mouse_rtos *cpu);
/* Resume only after a pending stop callback has actually returned. Does not
 * call, skip or fabricate the callback. Caller must retain its effects and
 * supply the original timer address. Original continuation0E096AD6. */
int rr_mouse_timer_stop_after_callback(uint8_t ram[65536],uint8_t rtc[4096],uint32_t timer_address,rr_mouse_rtos *cpu);
#endif
