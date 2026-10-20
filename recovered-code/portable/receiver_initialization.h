#ifndef RR_RECEIVER_INITIALIZATION_H
#define RR_RECEIVER_INITIALIZATION_H
#include <stdint.h>
typedef struct {uint8_t *ram,*radio,*timer,*nvic,*dppi,*rtc,*clock0,*clock1,*clock2,*deviceid;} rr_receiver_init_hw;
/* RAM64KiB; each MMIO window4KiB, except deviceid8B at0FFFE010.
 * All hardware is inert input/output snapshots. Clock windows5300/1/2E000.
 * Full2302206C uses four real PRNG steps with fixed supplied RTC low32.
 * stack_phy is the original uninitialized byte at entrySP-36; supply it
 * explicitly. Return0 full software return; -4 busy RTC after prefix effects.
 * Tables003B8..003DA must contain actual initialized channel values<37.
 */
int rr_receiver_initialize(rr_receiver_init_hw*,uint32_t identity,uint32_t capability,uint8_t stack_phy);
int rr_receiver_radio_initialize(rr_receiver_init_hw*,uint32_t identity,uint8_t phy);
/* One already-dequeued config event:1 full init then key,8 identity then key,
 * 9 identity metadata only. Default ignored events return0 at next loop head.
 * -2 for the remaining known dispatcher arms; no side effects in that case.
 * Does not receive a queue message or implement an infinite management thread.
 */
int rr_receiver_config_event(rr_receiver_init_hw*,uint32_t event,uint32_t value,uint8_t stack_phy,const uint8_t key_table[256]);
#endif
