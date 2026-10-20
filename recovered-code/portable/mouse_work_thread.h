#ifndef RR_MOUSE_WORK_THREAD_H
#define RR_MOUSE_WORK_THREAD_H
#include "mouse_timer_expiry.h"
/* One original0E09504C worker loop iteration, including real indirect
 * callback23025DF1. 0=next loop header reached, NOT thread exit.
 * 1=actual unimplemented handler/RTOS helper entry; CPU.entry/arg0 retained.
 * Flush/cancel semaphore give executes; drain wake, pend and yield remain boundaries; no success
 * stubs. Negative helper boundaries preserve preceding writes. RAM64KiB,
 * RTC4KiB, AUX16B. Not resumable by reentry; no actual CPU scheduling. */
int rr_mouse_work_thread_step(uint8_t*,uint8_t*,uint8_t*,uint32_t,rr_mouse_rtos*);
#endif
