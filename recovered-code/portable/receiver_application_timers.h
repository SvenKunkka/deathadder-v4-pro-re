#ifndef RR_RECEIVER_APPLICATION_TIMERS_H
#define RR_RECEIVER_APPLICATION_TIMERS_H
#include "receiver_config_control.h"
#include "receiver_timer_expiry.h"
/* Four statically registered callbacks255D0/255F8/25640/256E8.
 * Callback is even code address. tail32 is exact old callback stack bytes
 * used by event4 queue message after initialized event word; never zeroed.
 * Return0=full return,1=actualCPU/stop/reboot entry,negative=domain bound.
 * Privileged serialized CPU, stable MMIO; no physical reboot or execution. */
int rr_receiver_application_timer(rr_receiver_init_hw*,const uint8_t*,uint32_t,const uint8_t[32],rr_receiver_rtos*);
int rr_receiver_rtc_application_timers(rr_receiver_init_hw*,const uint8_t*,const uint8_t[32],rr_receiver_rtos*,rr_receiver_rtc_pending*);
#endif
