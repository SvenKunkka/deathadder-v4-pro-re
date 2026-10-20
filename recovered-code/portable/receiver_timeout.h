#ifndef RR_RECEIVER_TIMEOUT_H
#define RR_RECEIVER_TIMEOUT_H
#include <stdint.h>
#include "receiver_rtos_lifecycle.h"
/* Receiver 1.20 timeout delta-list (0E06E648/0E06E768).
 * RAM is 128KiB at23000000; RTC is 4KiB at5F99C000.
 * 0=completed,-1=invalid projected list/memory,-4=RTC high-word busy.
 * Earlier writes are retained on a boundary. Clock words are explicit static
 * hardware inputs; this model does not advance time or deliver interrupts.
 * start delay uses the original 64-bit bit pattern; UINT64_MAX is no-op.
 */
int rr_receiver_timeout_abort(uint8_t *ram,uint8_t *rtc,uint32_t address,int32_t *original_result);
int rr_receiver_timeout_start(uint8_t *ram,uint8_t *rtc,uint32_t address,uint32_t callback,uint64_t delay);
int rr_receiver_semaphore_give_timed(uint8_t*,uint8_t*,uint32_t,rr_receiver_rtos*);
int rr_receiver_message_put_timed(uint8_t*,uint8_t*,uint32_t,const uint8_t[36],rr_receiver_rtos*,int32_t*);
int rr_receiver_message_purge_timed(uint8_t*,uint8_t*,uint32_t,rr_receiver_rtos*);
int rr_receiver_disconnect_notice_timed(uint8_t*,uint8_t*,const uint8_t[8],const uint8_t[24],rr_receiver_rtos*);
int rr_receiver_timer_mode4_lifecycle_timed(uint8_t*,const uint8_t*,rr_receiver_radio_hw*,uint8_t*,rr_receiver_rtos*,const uint8_t[24]);
#endif
