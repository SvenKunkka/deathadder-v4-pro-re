#ifndef RR_RECEIVER_LEGACY_RADIO_H
#define RR_RECEIVER_LEGACY_RADIO_H
#include "receiver_radio_irq.h"
#include "receiver_legacy_business.h"
#include "receiver_rtos_lifecycle.h"
/* Direct entry23023498(mode1)/23022A50(mode2), 128KiB projected RAM.
 * Valid domain: peer0..2, channel0..1, selected queue0..5 or255 (actual timer sentinel; new ACK performs original out-of-array byte pop projection), valid RTOS lists.
 * 0 completed;1 real RTOS boundary(cpu.entry/arg0);-1 unsupported model input.
 * Caller supplies original stack provenance for notification-only paths:
 * notice_tail24: type1 message+12..35 / type5 message+16..35(first20);
 * pair_padding2: original uninitialized connection pair bytes2..3.
 * These are opaque bytes, not protocol fields. No synthetic queue success.
 * CPU boundary retains prefix mutations. Re-entering IRQ is NOT a resume.
 */
int rr_receiver_legacy_radio(uint8_t *ram,rr_receiver_radio_hw *hw,unsigned mode,
 rr_receiver_rtos *cpu,const uint8_t notice_tail24[24],const uint8_t pair_padding2[2]);
/* Explicit same-state IRQ->SWI wiring. Only call after actual10000000 request;
 * USB pending/resume uses receiver_legacy_business's existing contract. */
int rr_receiver_legacy_radio_swi(uint8_t *ram,const uint8_t *flash,unsigned mode,
 rr_receiver_legacy_pending *pending);
#endif
