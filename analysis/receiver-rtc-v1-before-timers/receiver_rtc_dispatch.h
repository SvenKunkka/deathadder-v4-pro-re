#ifndef RR_RECEIVER_RTC_DISPATCH_H
#define RR_RECEIVER_RTC_DISPATCH_H
#include "receiver_timeout.h"
/* Full RAM128KiB and RTC4KiB snapshots, serialized privileged CPU, valid
 * bounded lists.0=original return,1=unknown callback entry with real ABI;
 * negative=analysis domain limit, no rollback of prior writes.
 * RTC input/events are explicit; no autonomous hardware/exception return.
 * Application timer/work expiry callbacks remain real entry boundaries. */
typedef struct {uint8_t *ram,*rtc;} rr_receiver_rtc_hw;
typedef struct {uint32_t entry,args[5];} rr_receiver_rtc_pending;
int rr_receiver_timeout_announce(rr_receiver_rtc_hw*,uint32_t,rr_receiver_rtos*,rr_receiver_rtc_pending*);
int rr_receiver_clock_announce(rr_receiver_rtc_hw*,uint64_t,rr_receiver_rtos*,rr_receiver_rtc_pending*);
int rr_receiver_rtc_dispatch(rr_receiver_rtc_hw*,rr_receiver_rtos*,rr_receiver_rtc_pending*);
#endif
