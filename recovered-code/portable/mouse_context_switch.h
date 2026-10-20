#ifndef RR_MOUSE_CONTEXT_SWITCH_H
#define RR_MOUSE_CONTEXT_SWITCH_H
#include <stdint.h>
/* Integer-register projection of original privileged Thumb bodies.
 * RAM=23000000/64KiB; SCB window=E000E000/4KiB.
 * scratch[32] is the incoming MSP interval [sp-32,sp), preserved except
 * actual original push writes. CPU flags are CY,ZR,NG,OV,Q in that order.
 * No exception entry, automatic PendSV servicing, frame unstacking, FPU,
 * security-state transition or architectural fault simulation.
 * Return0=normal return;1=at original BX LR exception-return boundary;
 * -1=analysis memory domain, with previous writes retained.
 */
typedef struct {uint32_t r[13],sp,lr,pc,psp,psplim,priority,flags[5];} rr_mouse_context_cpu;
/* Original0e089d4c with no asynchronous interrupt during its instructions.
 * r0 supplies saved priority; resulting r0 is current_thread.result.
 * ICSR is an inert write snapshot, not a hardware readback model. */
int rr_mouse_switch_request_inert(uint8_t*,uint8_t*,uint8_t[32],rr_mouse_context_cpu*);
int rr_mouse_select_context(uint8_t*,uint8_t*,uint8_t[32],rr_mouse_context_cpu*);
/* Original0e089dcc through0e089e04; stop before BX LR at0e089e06.
 * Handler-mode MSP and already-stacked exception frame are caller inputs. */
int rr_mouse_pendsv_body(uint8_t*,uint8_t*,uint8_t[32],rr_mouse_context_cpu*);
/* Original0e089f3c. r0 supplies the thread pointer. */
int rr_mouse_set_psplim(uint8_t*,rr_mouse_context_cpu*);
#endif
