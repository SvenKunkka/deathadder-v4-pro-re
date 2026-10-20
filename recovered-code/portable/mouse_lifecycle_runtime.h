#ifndef RR_MOUSE_LIFECYCLE_RUNTIME_H
#define RR_MOUSE_LIFECYCLE_RUNTIME_H
#include "mouse_timer_stop_runtime.h"
/* Direct disconnect23022D88, ACK callback23025C2C and class3 callback23025EB4.
 * Full software path uses timer-stop unpend/ready/schedule. 1=actual stop
 * callback or CPU request, recorded in cpu. Prior mutations retained;
 * do NOT re-enter the whole API to resume. Caller continuation still needed.
 * -2 in ACK callback is an unsupported nonzero ACK function, not stop callback.
 * Same RAM/RADIO/TIMER/RTC/clock windows as mouse_timer_lifecycle. No hardware.
 */
int rr_mouse_disconnect_runtime(uint8_t*,uint8_t*,uint8_t*,uint8_t*,uint32_t*,uint32_t,rr_mouse_rtos*);
int rr_mouse_disconnect_ack_runtime(uint8_t*,uint8_t*,uint8_t*,uint8_t*,uint32_t*,rr_mouse_rtos*);
int rr_mouse_ack_callback_runtime(uint8_t*,uint8_t*,uint8_t*,uint8_t*,uint32_t*,uint16_t,rr_mouse_rtos*);
#endif
