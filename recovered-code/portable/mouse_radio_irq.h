#ifndef RR_MOUSE_RADIO_IRQ_H
#define RR_MOUSE_RADIO_IRQ_H
#include <stdint.h>
/* Direct original mode1=230236ac / mode2=23022fbc entry, NOT full23021704.
 * Inert memory windows: RAM23000000(65536), RADIO5302c000(4096),
 * TIMER02053028000(1536), NVIC wordE000E208. No automatic SWI scheduling.
 * 0 complete in serialized supported domain; -1 bad pointer/mode;
 * -2 actual class3 ACK callback nonzero; -3 RX bank outside0/1.
 * Negative host boundary statuses leave all inputs untouched.
 * Physical register task/event timing, interrupts and callback lifecycle
 * are not simulated; original ring pop is reused with serialized PRIMASK. */
int rr_mouse_radio_irq(uint8_t ram[65536],uint8_t radio[4096],
 uint8_t timer[1536],uint32_t *nvic_pending,unsigned mode);
/* Extended reconstruction: invoke a recovered ACK callback at the original
 * call site after queue pop and before NVIC/state18/tail event clears.
 * NULL retains old -2 preflight. A nonzero callback result stops at that
 * actual call boundary with earlier mutations retained. No target code stub. */
typedef int (*rr_mouse_ack_handler)(void *context,uint16_t message_class);
int rr_mouse_radio_irq_with_ack(uint8_t ram[65536],uint8_t radio[4096],
 uint8_t timer[1536],uint32_t *nvic_pending,unsigned mode,
 rr_mouse_ack_handler handler,void *context);
#endif
