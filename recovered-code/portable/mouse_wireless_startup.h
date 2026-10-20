#ifndef RR_MOUSE_WIRELESS_STARTUP_H
#define RR_MOUSE_WIRELESS_STARTUP_H
#include "mouse_initialization.h"
#include "mouse_work_queue.h"
/* Official mouse1.20 software startup, on inert memory snapshots.
 * init RAM128KiB; six4KiB peripheral windows including RTC5F99C000.
 * 0=returned, 1=pending original CPU request E089D4C in cpu.entry/arg0,
 * negative=invalid/outside modeled input. Pending is NOT completed sleep.
 * CPU request requires external scheduling and original continuation state;
 * calling a startup function again does not resume a suspended invocation.
 * Linked RTOS objects must be in the lower64KiB, as in the original fixture.
 * Stack memory in created threads is preserved except original written bytes.
 */
typedef struct {rr_mouse_init_hw init;uint8_t *rtc;const uint8_t *key_table;} rr_mouse_startup_hw;
typedef struct {
 uint32_t thread,stack,size,entry,arg1,arg2,arg3,priority,options;
 uint64_t delay;
} rr_mouse_thread_config;
int rr_mouse_scan_work_initialize(uint8_t *ram);
int rr_mouse_thread_start(uint8_t *ram,uint8_t *rtc,uint32_t thread,rr_mouse_rtos *cpu);
int rr_mouse_thread_create(uint8_t *ram,uint8_t *rtc,const rr_mouse_thread_config*,rr_mouse_rtos*,uint32_t *result);
/* ticks_sleep records the pre-switch32bit deadline when nonzero duration.
 * It has not run the post-switch tick read or returned a remaining duration. */
int rr_mouse_ticks_sleep(uint8_t *ram,uint8_t *rtc,uint64_t duration,rr_mouse_rtos*,uint32_t *deadline);
int rr_mouse_public_sleep(uint8_t *ram,uint8_t *rtc,uint64_t duration,rr_mouse_rtos*,uint32_t *result);
int rr_mouse_wireless_setup(rr_mouse_startup_hw*,rr_mouse_rtos*);
int rr_mouse_wireless_startup(rr_mouse_startup_hw*,uint32_t identity,uint32_t rate,rr_mouse_rtos*);
#endif
