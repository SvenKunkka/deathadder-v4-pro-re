#ifndef RR_MOUSE_TIMER_START_H
#define RR_MOUSE_TIMER_START_H
#include <stdint.h>
/* Original 0e096474: unlinked 24-byte timeout object; UINT64_MAX is no-op.
 * 0 complete, -1 invalid address/list, -4 RTC snapshot busy. Earlier writes
 * are preserved on boundaries. RAM/RTC arrays model inert memory, not hardware.
 * Call serially under the original caller's interrupt exclusion contract. */
int rr_mouse_timeout_start(uint8_t ram[65536], uint8_t rtc[4096],
 uint32_t address, uint32_t callback, uint64_t delay);
/* Original 0e096a50: 0x38-byte timer, abort/restart, expiry thunk registration,
 * duration normalization, period storage and status reset. */
int rr_mouse_timer_start(uint8_t ram[65536], uint8_t rtc[4096],
 uint32_t address, uint64_t duration, uint64_t period);
#endif
