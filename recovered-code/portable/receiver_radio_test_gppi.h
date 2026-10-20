#ifndef RR_RECEIVER_RADIO_TEST_GPPI_H
#define RR_RECEIVER_RADIO_TEST_GPPI_H
#include "receiver_radio_test_bus.h"
/* Original serialized GPPI software for same-descriptor RF endpoints.
 * 0: returned; 1: real pending boundary; -2: unsupported input/domain.
 * Result is meaningful for original nonvoid entries A658/AACC/AB70/AB78/
 * AB80/A0D4/8A5C/8A9C/A484/A264 only. Void-entry r0 residue is not an API.
 * SET/CLR writes remain inert MMIO writes; CHEN is never synthesized.
 */
int rr_receiver_radio_test_gppi(rr_rt_bus *bus,uint32_t entry,
    const uint32_t args[4],uint32_t *result,rr_rt_pending *pending);
#endif
