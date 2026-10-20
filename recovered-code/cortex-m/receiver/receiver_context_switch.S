/* Reconstructed from receiver v1.20 Thumb instructions. Address-bound fragment,
 * not a complete firmware image. Relocate only with all RAM/SCB bindings reviewed.
 * The literal layout deliberately matches 0x0e0611cc through 0x0e06128b.
 * Hardware exception entry/return is supplied by Cortex-M, not this source. */
.syntax unified
.cpu cortex-m33
.thumb
.section .text.rr_receiver_context,"ax",%progbits
.balign 4
.global rr_receiver_switch_request_native
.type rr_receiver_switch_request_native,%function
.thumb_func
rr_receiver_switch_request_native:
 push {r4}
 mvn.w r4,#10
 ldr.n r2,.Lstate1
 ldr r1,.Lscb1
 ldr r3,[r2,#8]
 mov.w r12,#0
 strd r0,r4,[r3,#0x88]
 ldr r3,[r1,#4]
 orr.w r3,r3,#0x10000000
 str r3,[r1,#4]
 msr basepri,r12
 isb
 ldr r3,[r2,#8]
 pop {r4}
 ldr.w r0,[r3,#0x8c]
 bx lr
.size rr_receiver_switch_request_native,.-rr_receiver_switch_request_native
 nop
.org 0x30
.Lstate1: .word 0x23007168
.Lscb1: .word 0xe000ed00
.global rr_receiver_select_context_native
.type rr_receiver_select_context_native,%function
.thumb_func
rr_receiver_select_context_native:
 push {r4,r5}
 mrs r3,basepri
 movs r3,#0x40
 msr basepri_max,r3
 isb
 mov.w r5,#0x08000000
 movs r1,#0
 ldr r2,.Lstate2
 ldr r4,.Lscb2
 ldr r3,[r2,#0x14]
 str r3,[r2,#8]
 str r5,[r4,#4]
 ldr r2,.Lthread_local
 ldr.w r4,[r3,#0x84]
 str r4,[r2]
 ldr.w r2,[r3,#0x88]
 str.w r1,[r3,#0x88]
 msr basepri,r2
 isb
 pop {r4,r5}
 bx lr
.size rr_receiver_select_context_native,.-rr_receiver_select_context_native
.org 0x74
.Lstate2: .word 0x23007168
.Lscb2: .word 0xe000ed00
.Lthread_local: .word 0x23006930
.global rr_receiver_pendsv_native
.type rr_receiver_pendsv_native,%function
.thumb_func
rr_receiver_pendsv_native:
 ldr r1,.Lstate3
 ldr r2,[r1,#8]
 mov.w r0,#0x30
 add r0,r2
 mrs r12,psp
 stm r0,{r4-r12}
 mov r4,lr
 mov r0,lr
 bl rr_receiver_select_context_native
 mov lr,r4
 ldr r1,.Lstate3
 ldr r2,[r1,#8]
 add.w r0,r2,#0x30
 ldm.w r0,{r4-r12}
 msr psp,r12
 add.w r0,r2,#0
 push {r2,lr}
 bl rr_receiver_psplim_native
 pop.w {r2,lr}
 bx lr
.size rr_receiver_pendsv_native,.-rr_receiver_pendsv_native
.org 0xbc
.Lstate3: .word 0x23007168
/* Original intervening routines are outside this recovered fragment. */
.org 0x1d8
.global rr_receiver_psplim_native
.type rr_receiver_psplim_native,%function
.thumb_func
rr_receiver_psplim_native:
 ldr r3,[r0,#0x74]
 msr psplim,r3
 bx lr
.size rr_receiver_psplim_native,.-rr_receiver_psplim_native
