#ifndef RR_MOUSE_BUSINESS_FLOW_H
#define RR_MOUSE_BUSINESS_FLOW_H
#include <stdint.h>
typedef struct {
 uint8_t business_class, sequence, accepted, reassembly_kind;
 uint8_t work_requested;
 int work_return;
} rr_mouse_business_flow_event;
/* Original entry23022508, modes1/2/4, RAM projection23000000..2300ffff.
 * Consumer23025e38 is asynchronous and MUST be invoked separately.
 * Supports actual work-submit fast-return flags&6; never fakes an enqueue.
 * -1 null argument; -2 unsupported reassembly bounds/class; -3 real RTOS
 * enqueue path outside model. Negative statuses leave RAM and event unchanged.
 * These statuses are host preflight boundaries, NOT firmware return values. */
int rr_mouse_business_flow(uint8_t ram[65536],rr_mouse_business_flow_event *event);
#endif
