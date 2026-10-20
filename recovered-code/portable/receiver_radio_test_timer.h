#ifndef RR_RECEIVER_RADIO_TEST_TIMER_H
#define RR_RECEIVER_RADIO_TEST_TIMER_H
#include "receiver_radio_test_bus.h"
/* Direct original receiver 1.20 TIMER functions. args[4] is the fifth
 * stack argument of E06A064. Return 0=returned, 1=actual callback boundary,
 * -2=unsupported entry or inaccessible memory. result is meaningful only
 * for initialize/configure/conversion functions; void entries write zero.
 * IRQ stops at its first actual callback; no callback return is injected. */
int rr_receiver_radio_test_timer(rr_rt_bus *b, uint32_t entry,
    const uint32_t args[5], uint32_t *result, rr_rt_pending *pending);
#endif
