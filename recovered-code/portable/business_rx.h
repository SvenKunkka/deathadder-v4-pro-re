#ifndef RR_BUSINESS_RX_H
#define RR_BUSINESS_RX_H
#include <stdint.h>
/* RAM projection of both six-class reassembly banks. Padding after the six
 * index/length bytes is retained because the original arrays are 8 bytes apart. */
typedef struct {
    uint8_t data[6][128], expected[8], length[8];
    uint8_t completed[128], completed_class, completed_length;
    uint8_t motion[8], activity;
} rr_business_rx_state;
enum { RR_RX_NONE=0, RR_RX_MISMATCH=1, RR_RX_MOUSE_WORK=2,
       RR_RX_MANAGEMENT=3, RR_RX_DELIVER=4 };
typedef struct {
    uint8_t kind, business_class, length, payload[128];
} rr_business_rx_event;
/* Stops at the real downstream call boundary: mouse work-submit, dongle
 * management handler (class3) or business consumer. Does not emulate those
 * callees. Returns -1 without changing state for our unsupported bounds,
 * including class2/4 completed lengths other than 8/16. This is NOT a firmware
 * validation rule. Otherwise returns 0; event.kind conveys the boundary.
 * key is four numeric little-endian words already installed by the caller. */
int rr_business_rx(int mouse, rr_business_rx_state *s, unsigned cls,
                   const uint8_t *fragment, unsigned size,
                   const uint32_t key[4], rr_business_rx_event *event);
#endif
