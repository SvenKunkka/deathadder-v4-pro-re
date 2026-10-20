#ifndef RR_RECEIVER_RTOS_LIFECYCLE_H
#define RR_RECEIVER_RTOS_LIFECYCLE_H
#include <stdint.h>
#include "receiver_radio_timer.h"
/* 128KiB projected RAM, valid intrusive lists and queue memory required.
 * 0=completed,1=stopped BEFORE real pending call,-1=memory domain error.
 * Earlier real side effects are retained on pending/error; no rollback.
 * Priority/exception are explicit serialized CPU inputs, not a scheduler.
 */
typedef struct {uint32_t priority,exception_number,entry,arg0;} rr_receiver_rtos;
/* Optional exact timeout implementation; NULL retains original boundaries.
 * Callbacks must retain real writes on error and return0 only on completion.
 * CPU context switch remains a real boundary even when both are supplied. */
typedef struct {
 void *context;
 int (*abort)(void *context,uint32_t timeout);
 int (*start)(void *context,uint32_t timeout,uint32_t callback,uint64_t delay);
} rr_receiver_rtos_ops;
int rr_receiver_semaphore_give_with_ops(uint8_t*,uint32_t,rr_receiver_rtos*,const rr_receiver_rtos_ops*);
int rr_receiver_message_put_with_ops(uint8_t*,uint32_t,const uint8_t[36],rr_receiver_rtos*,int32_t*,const rr_receiver_rtos_ops*);
int rr_receiver_message_purge_with_ops(uint8_t*,uint32_t,rr_receiver_rtos*,const rr_receiver_rtos_ops*);
int rr_receiver_disconnect_notice_with_ops(uint8_t*,const uint8_t[8],const uint8_t[24],rr_receiver_rtos*,const rr_receiver_rtos_ops*);
int rr_receiver_semaphore_give(uint8_t *ram,uint32_t address,rr_receiver_rtos *cpu);
int rr_receiver_message_put(uint8_t *ram,uint32_t queue,const uint8_t message[36],rr_receiver_rtos *cpu,int32_t *original_result);
int rr_receiver_message_purge(uint8_t *ram,uint32_t queue,rr_receiver_rtos *cpu);
int rr_receiver_disconnect_notice(uint8_t *ram,const uint8_t pair[8],const uint8_t opaque_stack_tail[24],rr_receiver_rtos *cpu);
/* Completes existing mode4 prefix through sem and type2 notification.
 * opaque_stack_tail is the original24B at notification-entry stack[-32:-8].
 * Supplying it is explicit provenance, not a claim to emulate CPU stack. */
int rr_receiver_timer_mode4_lifecycle(uint8_t *ram,const uint8_t *flash,rr_receiver_radio_hw *hw,rr_receiver_rtos *cpu,const uint8_t opaque_stack_tail[24]);
#endif
