/* Authored recovery of RX and state0x16 TX-completion branches of mouse 1.20 0x230227b8. */
#ifndef RR_MOUSE_HANDSHAKE_H
#define RR_MOUSE_HANDSHAKE_H
#include <stdint.h>
#define RR_MOUSE_RAM_BYTES 992u
/* Register-array order: RADIO TXEN-subscribe; TIMER CLEAR-subscribe, STOP,
 * CLEAR, SHORTS, INTENSET, INTENCLR, then CC0..CC7. Values describe register
 * stores into inert simulated memory. No hardware is accessed.
 */
#define RR_MOUSE_REGISTER_WORDS 15u
/* Returns 0 for modeled execution; -1 for unimplemented terminal lifecycle
 * branches. Input covers RAM [23002688,23002a68). For this verified interface,
 * selected register words start at zero, CRCOK is supplied separately.
 * State0x17 terminal initialization remains outside the recovered module.
 */
int rr_mouse_handshake_rx(uint8_t ram[RR_MOUSE_RAM_BYTES], uint32_t event,
    uint32_t crc_ok, uint8_t channel, uint32_t regs[RR_MOUSE_REGISTER_WORDS]);
/* Full in/out inert register state. First 15 match the retained ABI; appended:
 * RADIO EVENTS_READY (5302c200), END (5302c218), DISABLED (5302c220),
 * TASKS_RXEN (5302c004). Untouched words retain caller-supplied values.
 * Terminal state 0x17 + event5 returns -1 without implementing its lifecycle.
 */
#define RR_MOUSE_STEP_REGISTER_WORDS 19u
int rr_mouse_handshake_step(uint8_t ram[RR_MOUSE_RAM_BYTES], uint32_t event,
    uint32_t crc_ok, uint8_t channel, uint32_t regs[RR_MOUSE_STEP_REGISTER_WORDS]);
#endif
