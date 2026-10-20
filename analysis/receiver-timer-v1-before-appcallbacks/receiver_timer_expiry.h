#ifndef RR_RECEIVER_TIMER_EXPIRY_H
#define RR_RECEIVER_TIMER_EXPIRY_H
#include "receiver_rtc_dispatch.h"
/* Original E06EB00. RAM128KiB, inert RTC4KiB, official radio image.
 * Executes registered230255B8 disconnect callback and one waiter wakeup.
 * Other user callbacks stop at their entry with prior effects retained.
 *0=original return,1=real callback entry,negative=analysis domain error.
 * No asynchronous hardware, nested continuation or frame return invented. */
int rr_receiver_timer_expiry(uint8_t*,uint8_t*,const uint8_t*,uint32_t,rr_receiver_rtos*);
int rr_receiver_rtc_dispatch_timers(rr_receiver_rtc_hw*,const uint8_t*,rr_receiver_rtos*,rr_receiver_rtc_pending*);
int rr_receiver_clock_announce_timers(rr_receiver_rtc_hw*,const uint8_t*,uint64_t,rr_receiver_rtos*,rr_receiver_rtc_pending*);
int rr_receiver_timeout_announce_timers(rr_receiver_rtc_hw*,const uint8_t*,uint32_t,rr_receiver_rtos*,rr_receiver_rtc_pending*);
#endif
