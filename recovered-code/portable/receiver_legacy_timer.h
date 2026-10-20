#ifndef RR_RECEIVER_LEGACY_TIMER_H
#define RR_RECEIVER_LEGACY_TIMER_H
#include "receiver_legacy_radio.h"
#include "receiver_timeout.h"
/* Direct original23023C60(mode1)/23022ED4(mode2). 128KiB RAM,4KiB RTC.
 * Mode1/2 argument selects direct entry; root3230 gate is caller's responsibility.
 * 0 complete;1 pending CPU context switch; -4 RTC busy; -1 invalid model domain.
 * Original prefix writes persist. Recalling timer/IRQ is not a continuation.
 * tails[peer][24] is old stack tail at each actual type2 message_put call.
 * Valid slot/channel/queue/list/map memory is required; no implicit HW events. */
int rr_receiver_legacy_timer(uint8_t *ram,const uint8_t *flash,rr_receiver_radio_hw *hw,
 unsigned mode,uint8_t *rtc,rr_receiver_rtos *cpu,const uint8_t tails[2][24]);
#endif
