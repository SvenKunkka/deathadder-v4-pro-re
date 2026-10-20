#ifndef RR_RECEIVER_MUTEX_H
#define RR_RECEIVER_MUTEX_H
#include "receiver_timeout.h"
/* Privileged serialized CPU model, RAM128KiB and stable RTC4KiB. Valid finite
 * intrusive lists required. Return0=original returned,result valid;1=BEFORE
 * CPU request at0E0611CC,result untouched;negative=projected-domain failure.
 * State phase1 resumes after pend,phase2 after post-timeout reschedule,phase3
 * after unlock reschedule. Resume requires actual external post-CPU RAM and
 * priority/result inputs; it does not schedule or invent a lock handoff. */
typedef struct {uint32_t mutex,changed,phase;} rr_receiver_mutex_state;
int rr_receiver_mutex_lock(uint8_t*,uint8_t*,uint32_t,uint64_t,rr_receiver_rtos*,rr_receiver_mutex_state*,int32_t*);
int rr_receiver_mutex_unlock(uint8_t*,uint8_t*,uint32_t,rr_receiver_rtos*,rr_receiver_mutex_state*,int32_t*);
int rr_receiver_mutex_resume(uint8_t*,uint8_t*,rr_receiver_rtos*,rr_receiver_mutex_state*,int32_t,int32_t*);
int rr_receiver_thread_priority_set(uint8_t*,uint8_t*,uint32_t,int8_t,rr_receiver_rtos*,int32_t*);
#endif
