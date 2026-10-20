/* Independently recovered mouse 1.20 state0x17 lifecycle, inert memory only. */
#ifndef RR_MOUSE_LIFECYCLE_H
#define RR_MOUSE_LIFECYCLE_H
#include <stdint.h>
#define RR_LIFECYCLE_RAM_BYTES 0x8000u
#define RR_LIFECYCLE_RADIO_BYTES 0x1000u
#define RR_LIFECYCLE_TIMER_BYTES 0x600u
/* In/out bytes: RAM base23000000, RADIO base5302c000, TIMER020 base53028000.
 * 0: modeled execution/no-op; -2: active RTOS timer; -3: work submission may
 * enter unmodeled scheduler. Unsupported contexts return before any mutation.
 * Supported context: timers23001540/23001578 inactive (*timer==0), and either
 * pending23006b7e!=0 or work230067c0 flags(+12)&6!=0 (natural fast-return path).
 * These explicit RTOS limits are not claims about the actual live device.
 */
int rr_mouse_lifecycle(uint8_t ram[RR_LIFECYCLE_RAM_BYTES],
 uint8_t radio[RR_LIFECYCLE_RADIO_BYTES],uint8_t timer[RR_LIFECYCLE_TIMER_BYTES],
 uint32_t event);
/* Deferred connection-up callback23025df0, invoked separately by scheduler.
 * Supports pending==1; returns -4 for disconnect path, -2 for active optional
 * timer23001b48. No caller buffer changes on either unsupported condition.
 */
int rr_mouse_lifecycle_connected_work(uint8_t ram[RR_LIFECYCLE_RAM_BYTES]);
#endif
