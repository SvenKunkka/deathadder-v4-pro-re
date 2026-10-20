#ifndef RR_MOUSE_MODE4_RADIO_H
#define RR_MOUSE_MODE4_RADIO_H
#include <stdint.h>
/* Inert windows: RAM23000000(65536), RADIO5302c000(4096),
 * TIMER53028000(1536), SPIM5f9c2000(16), final NVIC storeE000E208.
 * IRQ success performs TWO writes10000000 then08000000: actual NVIC W1S
 * pends both; the memory projection exposes only the final store.
 * No automatic software-IRQ/consumer scheduling or physical hardware I/O.
 * Negative host statuses leave all inputs untouched: -1 null; -2 nonnull
 * class3 ACKcallback; -3 IRQ bank>2/channel>36; -4 idle TX selection/action3;
 * -5 slot5 disconnect; -6 pending rate change; -7 channel plan2/3 recompute;
 * -8 RX packet pointer outside RAM. These are not firmware validation rules. */
int rr_mouse_mode4_radio(uint8_t*m,uint8_t*r,uint8_t*t,uint32_t*nvic);
int rr_mouse_mode4_action(uint8_t*m,uint8_t*r,uint32_t action);
int rr_mouse_mode4_timer(uint8_t*m,uint8_t*r,uint8_t*t,uint8_t*spim,uint32_t*nvic);
/* Expanded action/timer with actual idle TX selection and encoding.
 * Old APIs preserve the historical -4 boundary. Other boundaries remain.
 * Valid initialized queue layout is a precondition of timer_full's TX path;
 * malformed TX layout returns-9 (timer event/slot may already be consumed). */
int rr_mouse_mode4_action_full(uint8_t *ram,uint8_t *radio,uint8_t *timer,uint32_t action);
int rr_mouse_mode4_timer_full(uint8_t *ram,uint8_t *radio,uint8_t *timer,uint8_t *spim,uint32_t *nvic);
/* Extended software branches. The image is the exact mouse1.20 radio binary
 * (base0E06C000), providing S-box/frequency constants. callbacks execute real
 * restored tails or stop at named pending boundaries; nonzero propagates with
 * earlier mutations retained. Old APIs retain their original boundaries. */
typedef int (*rr_mouse_mode4_ack_fn)(void *context,uint16_t message_class);
typedef int (*rr_mouse_mode4_timeout_fn)(void *context);
int rr_mouse_mode4_radio_with_ack(uint8_t *ram,uint8_t *radio,uint8_t *timer,uint32_t *nvic,rr_mouse_mode4_ack_fn ack,void *context);
int rr_mouse_mode4_timer_with_runtime(uint8_t *ram,uint8_t *radio,uint8_t *timer,uint8_t *spim,uint32_t *nvic,const uint8_t *image,uint32_t clock[2],rr_mouse_mode4_timeout_fn timeout,void *context);
#endif
