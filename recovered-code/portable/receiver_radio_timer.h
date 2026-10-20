#ifndef RR_RECEIVER_RADIO_TIMER_H
#define RR_RECEIVER_RADIO_TIMER_H
#include "receiver_radio_irq.h"
/* Full normal mode4 timer event selection, including CC0/CC2 and CC3..7.
 * 0=returned,1=stopped BEFORE real RTOS semaphore-give entry, -1=other mode.
 * A disconnect has already changed radio configuration and state at boundary.
 * pending names the real unresolved call; no success return is supplied.
 * Valid initialized channel maps/queue pointers are caller preconditions.
 * Snapshot MMIO semantics are inherited from receiver_radio_irq.h. */
typedef struct {uint32_t active,entry,arg0;} rr_receiver_timer_pending;
int rr_receiver_timer_mode4(uint8_t *ram,const uint8_t *flash,rr_receiver_radio_hw *hw,rr_receiver_timer_pending *pending);
#endif
