#ifndef RR_MOUSE_RTC_DISPATCH_H
#define RR_MOUSE_RTC_DISPATCH_H
#include "mouse_scanning.h"
/* Original pending callee ABI. args0..3=r0..r3; args4=first stacked argument
 * for an unknown RTC callback. Other pending callers define only args0.
 *0=return;1=actual unknown callback/CPU/RTOS entry; -1=memory domain;
 *-4=busy inert RTC; -5=host iteration bound. Prior writes always remain.
 * No actual exception entry/return or autonomous peripheral events. */
typedef struct {uint32_t entry,args[5];} rr_mouse_rtc_pending;
int rr_mouse_timeout_announce(rr_mouse_scan_hw*,uint32_t,rr_mouse_rtos*,rr_mouse_rtc_pending*);
int rr_mouse_clock_announce(rr_mouse_scan_hw*,uint64_t,rr_mouse_rtos*,rr_mouse_rtc_pending*);
int rr_mouse_rtc_dispatch(rr_mouse_scan_hw*,rr_mouse_rtos*,rr_mouse_rtc_pending*);
#endif
