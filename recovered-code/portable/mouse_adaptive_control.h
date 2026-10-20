#ifndef RR_MOUSE_ADAPTIVE_CONTROL_H
#define RR_MOUSE_ADAPTIVE_CONTROL_H
#include <stdint.h>
/* Original23022f90: publish phase/channel/reason then software IRQ word.
 * Byte parameters match original STRB truncation. No actual interrupt delivery. */
void rr_mouse_adaptive_request(uint8_t ram[65536],uint32_t phase,uint32_t channel,uint32_t reason,uint32_t *nvic_pending);
/* Original shared body23021ea8. Full software body, including real class0
 * enqueue via business_tx, with serialized RAM/queue state. peer0/1,
 * channel0..255; caller supplies valid ring layout if phase0 can report.
 * Returns0 on modeled execution; -1 invalid analysis-domain inputs before
 * mutation, not an original firmware status. phase outside0..2 is a no-op.
 * Does not establish physical signal or timing semantics. */
int rr_mouse_adaptive_run(uint8_t ram[65536],unsigned peer,uint32_t phase,uint32_t channel);
/* No-argument original23022f70: peer0, phase76f7/channel76f6. */
int rr_mouse_adaptive_irq(uint8_t ram[65536]);
#endif
