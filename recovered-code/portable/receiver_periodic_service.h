#ifndef RR_RECEIVER_PERIODIC_SERVICE_H
#define RR_RECEIVER_PERIODIC_SERVICE_H
#include "receiver_application_timers.h"
/* Official1.20 BDE0/BE20/BE4C and clock-alarm helpers. RAM128KiB,
 * RTC4KiB at5F99C000 and service4KiB at53014000 are inert snapshots.
 * Serialized privileged CPU, stable RTC reads; -4 means busy clock domain.
 * result preserves original r0; no hardware watchdog/reset claim. */
uint32_t rr_receiver_clock_allocate(uint8_t*);
int rr_receiver_clock_deadline(uint8_t*,uint8_t*,uint64_t,uint64_t*);
uint32_t rr_receiver_clock_alarm(uint8_t*,uint8_t*,uint32_t,uint64_t,uint32_t,uint32_t);
int rr_receiver_periodic_init(uint8_t*,uint8_t*,uint32_t*);
int rr_receiver_periodic_refresh(uint8_t*,uint8_t*,uint8_t*,uint32_t*);
/* Dispatcher executes periodic callback and previous generic/disconnect timer
 * chain; other application/RTC callbacks retain actual entry boundaries. */
int rr_receiver_periodic_dispatch(uint8_t*,uint8_t*,uint8_t*,const uint8_t*,rr_receiver_rtos*,rr_receiver_rtc_pending*);
/* Unified known RTC callbacks: periodic service plus all five recovered
 * application timer callbacks. Unknown entries remain explicit boundaries. */
int rr_receiver_rtc_known_callbacks(rr_receiver_init_hw*,uint8_t*,const uint8_t*,const uint8_t[32],rr_receiver_rtos*,rr_receiver_rtc_pending*);
#endif
