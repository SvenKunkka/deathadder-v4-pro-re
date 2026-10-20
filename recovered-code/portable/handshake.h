/* Reconstructed from Razer DeathAdder V4 Pro 1.20 radio binaries.
 * This is authored reconstruction, not recovered original source.
 * DMA/state transformations only. No hardware I/O or complete radio stack.
 */
#ifndef RR_HANDSHAKE_H
#define RR_HANDSHAKE_H
#include <stdint.h>
#define RR_SLOT_BYTES 224u
#define RR_HANDSHAKE_BYTES 12u
#define RR_UNRECOVERED_NOTIFICATION (-1)

typedef struct {
    uint32_t status0, status1;
    uint16_t primary_cap, fallback_cap, selector, selected_mode;
    uint8_t index0, index1, frequencies[8], mask[5], extra;
} rr_handshake_globals;

/* Caller supplies actual-size arrays; no I/O, allocation or hidden globals.
 * Byte sequence advances modulo 256, with 8 replaced by 1, as in firmware.
 */
uint8_t rr_dongle_offer(uint8_t packet[RR_HANDSHAKE_BYTES], uint8_t sequence,
    uint8_t slot, uint32_t base1, uint8_t capabilities, uint8_t flag7,
    uint8_t flag6, uint16_t event_counter);

/* Models 0x230223f0 with state bytes based at 0x230033e8+slot*0xf84.
 * Returns firmware result 0/1/2. For the still-unrecovered terminal
 * notification branch returns -1 without altering memory or globals.
 * The -1 result is an explicit reconstruction boundary, not device behavior.
 */
int rr_dongle_handshake(uint8_t memory[RR_SLOT_BYTES],
    const uint8_t incoming[RR_HANDSHAKE_BYTES], uint8_t slot,
    rr_handshake_globals *globals);
#endif
