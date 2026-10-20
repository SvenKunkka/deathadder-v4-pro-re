#ifndef RR_RECEIVER_CONFIG_CONTROL_H
#define RR_RECEIVER_CONFIG_CONTROL_H
#include "receiver_initialization.h"
#include "receiver_timeout.h"
/* Expanded receiver config dispatcher, after message dequeue. RAM128KiB,
 * other windows as receiver_initialization. 0=next loop head,1=real callback
 * or CPU request stored in cpu; negatives preserve prior mutations.
 * No queue wait or continuation after a pending nested call is fabricated.
 */
int rr_receiver_config_control(rr_receiver_init_hw*,uint32_t,uint32_t,uint8_t,const uint8_t*,rr_receiver_rtos*);
int rr_receiver_timer_start_control(uint8_t*,uint8_t*,uint32_t,uint64_t,uint64_t,rr_receiver_rtos*);
int rr_receiver_timer_stop_control(uint8_t*,uint8_t*,uint32_t,rr_receiver_rtos*);
int rr_receiver_thread_suspend_control(uint8_t*,uint8_t*,uint32_t,rr_receiver_rtos*);
int rr_receiver_thread_resume_control(uint8_t*,uint8_t*,uint32_t,rr_receiver_rtos*);
#endif
