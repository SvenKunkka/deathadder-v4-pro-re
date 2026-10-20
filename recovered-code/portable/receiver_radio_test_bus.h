#ifndef RR_RECEIVER_RADIO_TEST_BUS_H
#define RR_RECEIVER_RADIO_TEST_BUS_H
#include <stdint.h>
#include <stddef.h>
typedef struct { uint32_t base; uint8_t *data; size_t size; } rr_rt_window;
typedef struct {
    uint8_t *ram; const uint8_t *firmware; size_t firmware_size;
    rr_rt_window *windows; size_t window_count;
    uint32_t priority; int error;
} rr_rt_bus;
typedef struct { uint32_t kind, entry, args[4], arg_mask; } rr_rt_pending;
/* kind1: genuine unresolved call; kind2: external event required at poll PC.
 * Read/write windows are inert snapshots; no implicit hardware side effects. */
static inline uint8_t *rr_rt_mut(rr_rt_bus *b,uint32_t a,size_t n) {
    if (a>=0x23000000u && a-0x23000000u<=0x20000u && n<=0x20000u-(a-0x23000000u)) return b->ram+a-0x23000000u;
    for(size_t i=0;i<b->window_count;i++) {
        rr_rt_window *w=b->windows+i;
        if(a>=w->base && a-w->base<=w->size && n<=w->size-(a-w->base)) return w->data+a-w->base;
    }
    b->error=1; return NULL;
}
static inline const uint8_t *rr_rt_const(rr_rt_bus *b,uint32_t a,size_t n) {
    if(a>=0x0e054000u && a-0x0e054000u<=b->firmware_size && n<=b->firmware_size-(a-0x0e054000u)) return b->firmware+a-0x0e054000u;
    return rr_rt_mut(b,a,n);
}
static inline uint32_t rr_rt_r(rr_rt_bus *b,uint32_t a,unsigned n) {
    const uint8_t *p=rr_rt_const(b,a,n); uint32_t v=0;
    if(p) for(unsigned i=0;i<n;i++) v|=(uint32_t)p[i]<<(8*i);
    return v;
}
static inline void rr_rt_w(rr_rt_bus *b,uint32_t a,uint32_t v,unsigned n) {
    uint8_t *p=rr_rt_mut(b,a,n); if(p) for(unsigned i=0;i<n;i++) p[i]=(uint8_t)(v>>(8*i));
}
static inline int rr_rt_stop(rr_rt_pending *p,uint32_t entry,uint32_t a0,uint32_t a1,uint32_t a2,uint32_t mask) {
    p->kind=1;p->entry=entry;p->args[0]=a0;p->args[1]=a1;p->args[2]=a2;p->args[3]=0;p->arg_mask=mask;return 1;
}
#endif
