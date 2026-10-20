#ifndef RR_RECEIVER_NOTIFICATION_RUNTIME_H
#define RR_RECEIVER_NOTIFICATION_RUNTIME_H
#include "receiver_queue_runtime.h"
/* Official receiver radio image at0E054000 supplies existing status tables.
 * RAM128KiB. Helpers preserve original full-queue/no-wait behavior. */
int rr_receiver_connection_notice(uint8_t*,const uint8_t*,uint32_t,uint32_t);
int rr_receiver_mode_notice(uint8_t*,const uint8_t*,uint8_t);
/* After-dequeue segment230253EC to next loop230253DC, or real pending call.
 * Message is36bytes; only event word and peer halfword are read here. */
int rr_receiver_notification_dispatch(rr_receiver_init_hw*,const uint8_t*,const uint8_t[36],rr_receiver_rtos*);
/* Loop from230253DC including actual message_get. Same explicit stack/buffer
 * and pending-call rules as receiver_queue_runtime; never fake a nested return. */
int rr_receiver_notification_iteration(rr_receiver_init_hw*,const uint8_t*,uint32_t,uint8_t[36],rr_receiver_rtos*);
/* Event1 producer2302546C: pair8B plus explicit prior stack tail24B. */
int rr_receiver_connection_publish(uint8_t*,uint8_t*,const uint8_t[8],const uint8_t[24],rr_receiver_rtos*);
/* Timer1A30 registered user callback230255B8, no autonomous expiry modeled. */
int rr_receiver_disconnect_expiry(uint8_t*,const uint8_t*);
#endif
