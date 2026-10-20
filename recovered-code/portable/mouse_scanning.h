#ifndef RR_MOUSE_SCANNING_H
#define RR_MOUSE_SCANNING_H
#include "mouse_work_thread.h"
/* Inert byte windows RAM64KiB, RADIO4KiB, TIMER0201536B, RTC4KiB,
 * auxiliary16B, NVIC/SCB4KiB atE000E000, clock2words5302E040,
 * exact201044B mouse1.20 firmware. No live hardware operations. */
typedef struct {uint8_t *ram,*radio,*timer,*rtc,*aux,*nvic;uint32_t *clock;const uint8_t *image;} rr_mouse_scan_hw;
/*0=original return. Negative helper analysis boundaries retain prior effects.
 *1=actual pending CPU/RTOS entry. Firmware callback r0 is not the API status. */
int rr_mouse_scan_work(rr_mouse_scan_hw*,rr_mouse_rtos*);
int rr_mouse_scan_tick(rr_mouse_scan_hw*,rr_mouse_rtos*);
int rr_mouse_scan_advance(rr_mouse_scan_hw*);
int rr_mouse_scan_start(rr_mouse_scan_hw*,rr_mouse_rtos*);
/* Extends old exact API at actual unknown-handler boundary, then executes
 * its continuation once. Never reenters an already-mutated prefix. */
int rr_mouse_timer_expiry_scanning(rr_mouse_scan_hw*,uint32_t,rr_mouse_rtos*);
/*0=next worker loop header, NOT thread exit. Retains pend/yield/drain and
 * other unknown callback boundaries. Handles both known work callbacks. */
int rr_mouse_work_thread_scanning(rr_mouse_scan_hw*,uint32_t,rr_mouse_rtos*);
#endif
