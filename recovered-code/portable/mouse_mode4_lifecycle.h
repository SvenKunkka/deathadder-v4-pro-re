#ifndef RR_MOUSE_MODE4_LIFECYCLE_H
#define RR_MOUSE_MODE4_LIFECYCLE_H
#include <stdint.h>
/* Return0 completed,1 actual pending RTOS entry; negatives are the existing
 * memory/callback/waiter/RTC analysis boundaries. Earlier mutations remain.
 * Timeout ends before real work submission (flags&6==0), or after natural
 * work fast-return before timer-start. No invented RTOS success. */
typedef struct {uint32_t active,entry,args[4];} rr_mouse_mode4_pending;
int rr_mouse_mode4_radio_lifecycle(uint8_t *ram,uint8_t *radio,uint8_t *timer,uint8_t *rtc,uint32_t clock[2],uint32_t *nvic);
int rr_mouse_mode4_timer_lifecycle(uint8_t *ram,uint8_t *radio,uint8_t *timer,uint8_t *spim,const uint8_t *image,uint32_t clock[2],uint32_t *nvic,rr_mouse_mode4_pending *pending);
#endif
