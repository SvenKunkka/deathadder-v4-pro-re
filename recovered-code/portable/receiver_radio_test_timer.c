#include "receiver_radio_test_timer.h"
#include <string.h>
#define SUCCESS 0x0bad0000u
#define INVALID 0x0bad0004u
static uint32_t lsl(uint32_t v,uint32_t n) {
    n&=255u; return n>=32u ? 0u : v<<n;
}
static uint32_t lsr(uint32_t v,uint32_t n) {
    n&=255u; return n>=32u ? 0u : v>>n;
}
static uint32_t source_hz(uint32_t base) {
    if(base==0x5f8e2000u || base==0x5f8e3000u) return 320000000u;
    if(base==0x53028000u || base==0x53029000u || base==0x5302a000u) return 32000000u;
    return 16000000u;
}
static uint32_t state_address(rr_rt_bus *b,uint32_t instance) {
    return 0x23006e40u+12u*rr_rt_r(b,instance+4u,1);
}
static uint32_t configure(rr_rt_bus *b,uint32_t instance,uint32_t config) {
    uint32_t base=rr_rt_r(b,instance,4),frequency=rr_rt_r(b,config,4);
    uint32_t hz=source_hz(base),q=frequency ? hz/frequency : 0u;
    /* ARM UDIV without DIV_0_TRP returns zero. A zero input fails the
     * remainder check, so no division by zero is performed by host C. */
    if(hz-frequency*q || frequency>hz || ((q-1u)&q) || q>512u) return INVALID;
    uint32_t shift=0u,t=q;
    while(t && !(t&1u)) { ++shift;t>>=1; }
    if(!t) shift=32u;
    uint32_t bitmode=rr_rt_r(b,config+5u,1),mode=rr_rt_r(b,config+4u,1);
    uint32_t old=rr_rt_r(b,base+0x504u,4);
    rr_rt_w(b,base+0x504u,(old&~3u)|(mode&3u),4);
    old=rr_rt_r(b,base+0x508u,4);
    rr_rt_w(b,base+0x508u,(old&~3u)|(bitmode&3u),4);
    rr_rt_w(b,base+0x510u,shift,4);
    base=rr_rt_r(b,instance,4);
    for(uint32_t off=0x140u;off<0x160u;off+=4u) {
        rr_rt_w(b,base+off,0,4); (void)rr_rt_r(b,base+off,4);
    }
    uint32_t irq=(base>>12)&511u;
    rr_rt_w(b,0xe000e100u+4u*(irq>>5),1u<<(irq&31u),4);
    return SUCCESS;
}
static uint32_t ticks(rr_rt_bus *b,uint32_t instance,uint32_t duration,int milliseconds) {
    uint32_t base=rr_rt_r(b,instance,4),shift=rr_rt_r(b,base+0x510u,4);
    uint32_t factor=source_hz(base)/(milliseconds ? 1000u : 1000000u);
    uint64_t product=(uint64_t)duration*factor;
    uint32_t low=(uint32_t)product,high=(uint32_t)(product>>32);
    return lsr(low,shift)|lsl(high,32u-shift)|lsr(high,shift-32u);
}
static int irq_handler(rr_rt_bus *b,uint32_t base,uint32_t state,rr_rt_pending *pending) {
    uint32_t recorded=0;
    for(uint32_t ch=0;ch<8u;ch++) {
        uint32_t a=base+0x140u+4u*ch;
        if(rr_rt_r(b,a,4)) {
            rr_rt_w(b,a,0,4);(void)rr_rt_r(b,a,4);recorded|=1u<<(16u+ch);
        }
    }
    uint32_t enabled=rr_rt_r(b,base+0x304u,4)&0x00ff0000u;
    if(b->error) return -2;
    for(uint32_t ch=0;ch<8u;ch++) {
        if((recorded&enabled)&(1u<<(16u+ch))) {
            uint32_t callback=rr_rt_r(b,state,4);
            if(callback) {
                uint32_t context=rr_rt_r(b,state+4u,4);
                if(b->error) return -2;
                return rr_rt_stop(pending,callback&~1u,0x140u+4u*ch,context,0,3);
            }
        }
    }
    return b->error ? -2 : 0;
}
int rr_receiver_radio_test_timer(rr_rt_bus *b,uint32_t entry,
    const uint32_t args[5],uint32_t *result,rr_rt_pending *pending) {
    if(!b || !args || !result || !pending || !b->ram || !b->firmware) return -2;
    memset(pending,0,sizeof(*pending));*result=0;
    uint32_t instance=args[0],base,state,mask,old;
    switch(entry&~1u) {
    case 0x0e069e04u:
        *result=configure(b,instance,args[1]);break;
    case 0x0e069ee8u:
        state=state_address(b,instance);
        if(rr_rt_r(b,state+8u,1)) {*result=0x0bad000cu;break;}
        rr_rt_w(b,state,args[2],4);
        if(args[1]) {
            rr_rt_w(b,state+4u,rr_rt_r(b,args[1]+8u,4),4);
            *result=configure(b,instance,args[1]);
        } else *result=SUCCESS;
        rr_rt_w(b,state+8u,*result==SUCCESS,1);break;
    case 0x0e069f3cu:
        base=rr_rt_r(b,instance,4);rr_rt_w(b,base,1,4);
        state=state_address(b,instance);rr_rt_w(b,state+8u,2,1);break;
    case 0x0e069f5cu:
        base=rr_rt_r(b,instance,4);rr_rt_w(b,base+4u,1,4);
        base=rr_rt_r(b,instance,4);rr_rt_w(b,base+12u,1,4);
        state=state_address(b,instance);rr_rt_w(b,state+8u,1,1);break;
    case 0x0e069f7cu:
        base=rr_rt_r(b,instance,4);rr_rt_w(b,base+12u,1,4);break;
    case 0x0e069f84u:
        *result=ticks(b,instance,args[1],0);break;
    case 0x0e069ff0u:
        *result=ticks(b,instance,args[1],1);break;
    case 0x0e06a064u:
        mask=lsl(0x10000u,args[1]);base=rr_rt_r(b,instance,4);
        old=rr_rt_r(b,base+0x200u,4);
        rr_rt_w(b,base+0x200u,old&~(mask|lsl(1,args[1])),4);
        base=rr_rt_r(b,instance,4);old=rr_rt_r(b,base+0x200u,4);
        rr_rt_w(b,base+0x200u,old|args[3],4);
        if((uint8_t)args[4]) {
            base=rr_rt_r(b,instance,4);
            rr_rt_w(b,base+0x140u+4u*args[1],0,4);
            (void)rr_rt_r(b,base+0x140u+4u*args[1],4);
            base=rr_rt_r(b,instance,4);rr_rt_w(b,base+0x304u,mask,4);
        } else {
            base=rr_rt_r(b,instance,4);rr_rt_w(b,base+0x308u,mask,4);
        }
        base=rr_rt_r(b,instance,4);rr_rt_w(b,base+(args[1]+0x150u)*4u,args[2],4);break;
    case 0x0e069d98u:return irq_handler(b,args[0],args[1],pending);
    case 0x0e06a0c4u:return irq_handler(b,0x53029000u,0x23006e4cu,pending);
    default:return -2;
    }
    return b->error ? -2 : 0;
}
