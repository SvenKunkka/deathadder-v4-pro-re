#ifndef RR_RECEIVER_RADIO_IRQ_H
#define RR_RECEIVER_RADIO_IRQ_H
#include <stdint.h>
#include "receiver_business_flow.h"
/* Mode4 register-snapshot model. Arrays map RADIO5302C000/4KiB,
 * TIMER02053028000/2KiB, aux5300E000/2KiB. Values are environment inputs;
 * TASK writes do NOT simulate PHY/DPPI/time or auto-complete operations.
 * nvic_last retains raw last store; nvic_requests ORs all W1S requests from
 * model calls (independent of actual NVIC servicing/priority).
 * Requires valid RAM, queue pointers, DMA<=31B, slot0..5, normal protocol4.
 * -1 explicitly unsupported mode; timer -2 is a real event branch outside
 * this CC1-only recovery, not original return/error behavior.
 */
typedef struct {uint32_t radio[1024],timer[512],aux[512],nvic_last,nvic_requests;} rr_receiver_radio_hw;
int rr_receiver_radio_irq(uint8_t *ram,const uint8_t *flash,rr_receiver_radio_hw *hw);
int rr_receiver_timer_cc1(uint8_t *ram,rr_receiver_radio_hw *hw);
/* Actual mode4 SWI4 wrapper, including post-business failure-stat update.
 * Call separately after IRQ servicing, not synchronously inside RADIO IRQ.
 * 1=USB driver pending,0=done,-1=unsupported. */
int rr_receiver_radio_swi4(uint8_t *ram,const uint8_t *flash,rr_receiver_radio_hw *hw,rr_receiver_business_pending *pending);
int rr_receiver_radio_swi4_resume(uint8_t *ram,int32_t result,rr_receiver_business_pending *pending);
#endif
