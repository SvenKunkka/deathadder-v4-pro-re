#ifndef RR_MOUSE_BUSINESS_CONSUMER_H
#define RR_MOUSE_BUSINESS_CONSUMER_H
#include <stdint.h>
/* Original23025e38. RAM maps23000000..2300ffff; class=byte779b,
 * length=byte779c, buffer=67d0. Caller supplies valid TX ring layout (business_tx.h).
 * spim maps5f9c2000..200f; dppi maps5302e000..e047, inert bytes only.
 * 0 modeled; -2 A3 requires RTOS timer start; -3 B1 enabled sensor reinit;
 * -4 B1 would enter nonreturning reboot; -5 class5/5A length<3 copy underflow.
 * Negative returns are recovery preflight statuses, NOT firmware return codes;
 * all outputs remain unchanged on these unsupported contexts.
 */
int rr_mouse_business_consumer(uint8_t ram[0x10000],uint8_t spim[16],uint8_t dppi[72]);
#endif
