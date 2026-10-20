#ifndef RR_RECEIVER_CONFIG_PRODUCER_H
#define RR_RECEIVER_CONFIG_PRODUCER_H
#include "receiver_config_control.h"
/* Producer stack tails are explicit inputs: value messages8+28bytes,
 * event-only messages4+32bytes. No invented zero fill or queue success. */
int rr_receiver_config_value_publish(uint8_t*,uint8_t*,uint32_t,uint32_t,const uint8_t[28],rr_receiver_rtos*);
int rr_receiver_config_signal_publish(uint8_t*,uint8_t*,uint32_t,const uint8_t[32],rr_receiver_rtos*);
int rr_receiver_identity_publish(uint8_t*,uint8_t*,const uint8_t[28],rr_receiver_rtos*);
int rr_receiver_stats_reset(uint8_t*,uint32_t);
/* Events41/40/44/43 wrappers set USB mode and wake/suspend thread1EA0.
 * Event43 ends at real LED entry23025954 with arg0=0, not a fake return. */
int rr_receiver_config_mode_publish(rr_receiver_init_hw*,const uint8_t*,uint32_t,const uint8_t[32],rr_receiver_rtos*);
#endif
