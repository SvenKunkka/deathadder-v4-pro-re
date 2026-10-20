#ifndef RR_MOUSE_WORK_QUEUE_H
#define RR_MOUSE_WORK_QUEUE_H
#include <stdint.h>
#include "mouse_mode4_lifecycle.h"
/*128KiB is NOT needed here: mouse projected RAM is64KiB, RTC4KiB.
 * Serialized privileged CPU state, not an executing scheduler.
 *0=original call returned,1=before actual CPU switch,-1=invalid domain,
 *other negative values propagate exact helper boundaries. Prior writes stay.
 */
typedef struct{uint32_t priority,exception_number,entry,arg0;} rr_mouse_rtos;
/* Original0E09518C helper; queue_ref corresponds to the caller's mutable word.
 * On failure/queued no-op original clears queue_ref; submit wrapper uses2498. */
int rr_mouse_work_submit_to_queue(uint8_t*,uint8_t*,uint32_t,uint32_t*,rr_mouse_rtos*,int32_t*);
int rr_mouse_work_submit(uint8_t*,uint8_t*,uint32_t,rr_mouse_rtos*,int32_t*);
/* Extends exact mode4 timeout prefix through work submit and timer-start.
 * Pending identifies actual switch on return1; not resumable by reentry.
 * Clock words5302E040, SPIM16B retain the earlier lifecycle API layout. */
int rr_mouse_mode4_timer_rtos(uint8_t*,uint8_t*,uint8_t*,uint8_t*,const uint8_t*,uint8_t*,uint32_t*,uint32_t*,rr_mouse_rtos*,rr_mouse_mode4_pending*);
#endif
