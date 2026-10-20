#ifndef RR_RECEIVER_RADIO_TEST_CONTROL_H
#define RR_RECEIVER_RADIO_TEST_CONTROL_H
#include <stdint.h>

typedef struct {
    uint32_t entry, arg0, arg0_valid;
} rr_receiver_radio_test_pending;

/* Original receiver 1.20 entries: E05C504/C5EC/C6D4 (set/get parameters),
 * C774 (work), C214/C0E8 (build descriptors), C200 (reset), C0D4 (counters).
 * ram is an inert 128 KiB snapshot; firmware is the exact 124596-byte image.
 * The three parameter APIs support the actual vendor payload at 23002D24.
 * Other payload addresses return -2 before modifying RAM.
 * 0: original function returned; 1: stopped BEFORE the genuine downstream
 * entry in pending; -1: invalid input/entry. A boundary is NOT a continuation
 * token: never restart this function to simulate a downstream return.
 * Radio-stop 23021F88, test-stop E05D028, test-engine E05CD78 remain boundaries.
 * No hardware effects, unmodeled call results, or CPU stack are simulated.
 */
int rr_receiver_radio_test_control(uint8_t *ram, const uint8_t *firmware,
    uint32_t entry, uint32_t arg0, uint32_t arg1,
    rr_receiver_radio_test_pending *pending);
#endif
