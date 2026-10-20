#ifndef RR_RECEIVER_QUEUE_RUNTIME_H
#define RR_RECEIVER_QUEUE_RUNTIME_H
#include "receiver_config_control.h"
/* RAM128KiB, output buffer36B. Output aliases RAM at output_address when in
 * range; stack addresses use a separate explicit buffer. 0=returned/next loop,
 * 1=actual CPU/callback boundary; negatives preserve prior effects.
 * No return value is invented when pending; result stays untouched then. */
int rr_receiver_message_get(uint8_t*,uint8_t*,uint32_t,uint32_t,uint8_t[36],uint64_t,rr_receiver_rtos*,int32_t*);
/* One config loop starting at23024e46 through actual message_get. phy is the
 * old stack byte at initialization call; no stack continuation after pending. */
int rr_receiver_config_iteration(rr_receiver_init_hw*,uint32_t,uint8_t[36],uint8_t,const uint8_t*,rr_receiver_rtos*);
#endif
