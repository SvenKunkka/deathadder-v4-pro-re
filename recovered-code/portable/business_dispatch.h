#ifndef RR_BUSINESS_DISPATCH_H
#define RR_BUSINESS_DISPATCH_H
#include <stdint.h>
typedef struct { uint8_t context[0x200], motion[6], counters[4]; } rr_business_dispatch_state;
typedef struct { uint8_t forward, business_class, size, metadata, payload[128]; } rr_business_dispatch_event;
/* Receiver mode4 SWI data classes1..5, before 230254a0. context is one peer's
 * 230033e8+peer*f84 projection; motion/counters are shared globals. Caller owns
 * downstream execution and calls finish ONLY after its return. peer forwarded
 * by this original branch is always0, despite a selected input peer.
 * Returns -1 without mutation for unsupported class0/6/7 when packetlen>0.
 * This is a reconstruction boundary, not an original firmware rejection. */
int rr_business_dispatch(rr_business_dispatch_state *s, rr_business_dispatch_event *event);
void rr_business_dispatch_finish(rr_business_dispatch_state *s);
#endif
