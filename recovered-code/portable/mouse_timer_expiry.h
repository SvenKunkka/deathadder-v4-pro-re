#ifndef RR_MOUSE_TIMER_EXPIRY_H
#define RR_MOUSE_TIMER_EXPIRY_H
#include "mouse_work_queue.h"
/* Privileged serialized RAM64KiB/RTC4KiB. 0=original return; 1=actual
 * unknown callback/CPU-switch entry, recorded in CPU.entry/arg0.
 * Negative codes retain prior effects; not resumable by entry repetition.
 * Tick source is an inert snapshot. Does not drive RTC/IRQ autonomously. */
int rr_mouse_timer_expiry(uint8_t*,uint8_t*,uint32_t,rr_mouse_rtos*);
/* Original23025F64: clear HALFWORD6B7E, then actual work67C0 submit. */
int rr_mouse_disconnect_timer_callback(uint8_t*,uint8_t*,rr_mouse_rtos*);
/* Original23025DF0, including connected and disconnected branches.
 * auxiliary16B maps5F9C2000; stop callback/waiter boundaries retain the
 * mouse_timer_stop contract (-2/-3), after original preceding mutations. */
int rr_mouse_link_work_callback(uint8_t*,uint8_t*,uint8_t*,rr_mouse_rtos*);
/* Original0E094F80; includes actual waiter timeout abort and ready insertion.
 * Composition helper verified under worker lock; independent caller domains
 * are not separately certified by the current worker dataset. */
int rr_mouse_work_semaphore_give(uint8_t*,uint8_t*,uint32_t,rr_mouse_rtos*);
#endif
