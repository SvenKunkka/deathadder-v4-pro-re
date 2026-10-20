#ifndef RR_RECEIVER_RADIO_TEST_LIFECYCLE_H
#define RR_RECEIVER_RADIO_TEST_LIFECYCLE_H
#include "receiver_radio_test_bus.h"
/* Same RAM/ROM and explicit windows as test engine, plus TIMER020 at53028000.
 * CPU exception number is explicit. Global timer/ready lists must be valid.
 * 0 returned;1 genuine CPU or dynamic log callback boundary; negatives domain.
 * Meaningful result only for D1AC / D634; void entries use marker zero.
 * Includes F04 radio tail stop,F88 full stop,1D9C pause,1DB0 flag clear,
 * D1AC test init,D634 known test logs,612F0 IRQ priority.
 */
int rr_receiver_radio_test_lifecycle(rr_rt_bus*,uint32_t entry,const uint32_t args[5],
    uint32_t exception_number,uint32_t *result,rr_rt_pending*);
/* Matches engine dependency hook; context points to uint32 exception_number
 * (or NULL for thread mode). Executes only supported original bodies. */
int rr_receiver_radio_test_dependencies(void*,rr_rt_bus*,uint32_t,
    const uint32_t args[5],rr_rt_pending*);
#endif
