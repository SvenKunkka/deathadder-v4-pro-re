#ifndef RR_RECEIVER_CONTEXT_SWITCH_H
#define RR_RECEIVER_CONTEXT_SWITCH_H
#include <stdint.h>
/* Integer-register projection of original privileged Thumb bodies.
 * RAM=23000000/128KiB; SCB window=E000E000/4KiB.
 * scratch[32] is the incoming MSP interval [sp-32,sp), preserved except
 * actual original push writes. CPU flags are CY,ZR,NG,OV,Q in that order.
 * No exception entry, automatic PendSV servicing, frame unstacking, FPU,
 * security-state transition or architectural fault simulation.
 * Return0=normal return;1=at original BX LR exception-return boundary;
 * -1=analysis memory domain, with previous writes retained.
 */
typedef struct {uint32_t r[13],sp,lr,pc,psp,psplim,priority,flags[5];} rr_receiver_context_cpu;
/* Original0e0611cc with no asynchronous interrupt during its instructions.
 * r0 supplies saved priority; resulting r0 is current_thread.result.
 * ICSR is an inert write snapshot, not a hardware readback model. */
int rr_receiver_switch_request_inert(uint8_t*,uint8_t*,uint8_t[32],rr_receiver_context_cpu*);
int rr_receiver_select_context(uint8_t*,uint8_t*,uint8_t[32],rr_receiver_context_cpu*);
/* Original0e06124c through0e061284; stop before BX LR at0e061286.
 * Handler-mode MSP and already-stacked exception frame are caller inputs. */
int rr_receiver_pendsv_body(uint8_t*,uint8_t*,uint8_t[32],rr_receiver_context_cpu*);
/* Original0e0613a4. r0 supplies the thread pointer. */
int rr_receiver_set_psplim(uint8_t*,rr_receiver_context_cpu*);
#endif
