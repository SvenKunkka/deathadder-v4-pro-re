#ifndef RR_MOUSE_TIMER_LIFECYCLE_H
#define RR_MOUSE_TIMER_LIFECYCLE_H
#include <stdint.h>
/* Byte windows: RAM23000000/64KiB, RTC5F99C000/4KiB, RADIO5302C000/4KiB,
 * TIMER02053028000/1536B, clock words5302E040/8B. No time advancement.
 * Handles active linked timers, including head removal and RTC re-arm.
 * 0=software path completed. Negative API boundaries may follow original
 * earlier mutations: -1 invalid memory domain, -2 actual stop callback,
 * -3 waiting thread/scheduler path, -4 RTC snapshot remains busy.
 * Callers must honor this partial-state contract; not firmware return codes.
 */
int rr_mouse_timer_abort(uint8_t ram[65536],uint8_t rtc[4096],uint32_t timer_address,int32_t *original_result);
int rr_mouse_timer_stop(uint8_t ram[65536],uint8_t rtc[4096],uint32_t timer_address);
/* Direct original23022d88. Empty notification23025ed0 really returns. */
int rr_mouse_disconnect(uint8_t ram[65536],uint8_t radio[4096],uint8_t timer[1536],uint8_t rtc[4096],uint32_t clock[2],uint32_t reason);
/* Original23025c2c: stop15B0, read byte6B7B, then disconnect. */
int rr_mouse_disconnect_ack(uint8_t ram[65536],uint8_t radio[4096],uint8_t timer[1536],uint8_t rtc[4096],uint32_t clock[2]);
/* Original23025eb4 with class supplied from caller descriptor+2.
 * Known callback23025C2D executed; another nonzero callback returns-2.
 * Callback pointer cleared only after completed callback. */
int rr_mouse_ack_callback(uint8_t ram[65536],uint8_t radio[4096],uint8_t timer[1536],uint8_t rtc[4096],uint32_t clock[2],uint16_t message_class);
/* Full mode1/2 IRQ with known class3 ACK lifecycle at original call site.
 * Underlying IRQ preflight -1/-3 retains its contract; lifecycle boundaries
 * can occur after queue pop and retain prior effects. */
int rr_mouse_radio_irq_lifecycle(uint8_t ram[65536],uint8_t radio[4096],uint8_t timer[1536],uint8_t rtc[4096],uint32_t clock[2],uint32_t *nvic_pending,unsigned mode);
#endif
