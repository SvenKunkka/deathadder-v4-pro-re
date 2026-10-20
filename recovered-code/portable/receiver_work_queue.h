#ifndef RR_RECEIVER_WORK_QUEUE_H
#define RR_RECEIVER_WORK_QUEUE_H
#include "receiver_application_timers.h"
/* RAM128KiB + RTC4KiB snapshots, bounded coherent queues, serialized
 * privileged CPU.0=original returned; result separate.1=CPU boundary,
 * negatives=domain limitations. No fabricated thread/USB execution. */
int rr_receiver_work_submit_to_queue(uint8_t*,uint8_t*,uint32_t,uint32_t*,rr_receiver_rtos*,int32_t*);
/* explicit queue for D3FC; pass23002B18 for D43C default wrapper */
int rr_receiver_work_submit(uint8_t*,uint8_t*,uint32_t,uint32_t,rr_receiver_rtos*,int32_t*);
int rr_receiver_delayed_work_schedule(uint8_t*,uint8_t*,uint32_t,uint32_t,uint64_t,int,rr_receiver_rtos*,int32_t*);
int rr_receiver_delayed_work_expiry(uint8_t*,uint8_t*,uint32_t,rr_receiver_rtos*);
int rr_receiver_work_initialize(uint8_t*,uint32_t,uint32_t,int);
int rr_receiver_work_cancel(uint8_t*,uint32_t,rr_receiver_rtos*,uint32_t*);
/* All currently recovered periodic/application callbacks plus D3A4 expiry. */
int rr_receiver_rtc_work_dispatch(rr_receiver_init_hw*,uint8_t*,const uint8_t*,const uint8_t[32],rr_receiver_rtos*,rr_receiver_rtc_pending*);
#endif
