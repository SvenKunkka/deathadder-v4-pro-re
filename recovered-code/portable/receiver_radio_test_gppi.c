#include "receiver_radio_test_gppi.h"

#define OK 0x0bad0000u
#define NO_RESOURCE 0x0bad0002u
#define INVALID 0x0bad0004u
#define SLOTS 0x23006e58u
#define SHARED 0x0e070744u
static uint32_t bit(uint32_t n) { n&=255u;return n<32u?1u<<n:0u; }
static uint32_t shifted(uint32_t x,uint32_t n) { n&=255u;return n<32u?x>>n:0u; }
static uint32_t highest(uint32_t x) { uint32_t n=0;while(x>>1){x>>=1;n++;}return n; }
static uint32_t domain(rr_rt_bus *b,uint32_t d) { return rr_rt_r(b,d+3u,1)&15u; }
static uint32_t lookup(rr_rt_bus *b,uint32_t endpoint) {
    uint32_t isf=(endpoint>>24&15u)==15u;
    uint32_t d=isf?SHARED:0x0e0707a4u;
    for(uint32_t i=0;i<(isf?4u:1u);i++,d+=24u) {
        uint32_t mask=0u-rr_rt_r(b,d+20u,4);
        if(((rr_rt_r(b,d,4)&mask)>>16&255u)==((endpoint&mask)>>16&255u)) return d;
    }
    return 0;
}
static uint32_t reg(uint32_t endpoint) {
    return endpoint+((uint32_t)(endpoint-0x5302c000u)<=0x1064u?0x100u:0x80u);
}
static void reset(rr_rt_bus *b,uint32_t s) {
    rr_rt_w(b,s,0,4);rr_rt_w(b,s+4u,0,4);rr_rt_w(b,s+8u,0,4);
    rr_rt_w(b,s+8u,0xffffu,2);rr_rt_w(b,s+10u,0xffu,1);
}
static uint32_t take(rr_rt_bus *b,uint32_t bitmap,uint32_t mask,uint32_t out) {
    uint32_t v=rr_rt_r(b,bitmap,4),usable=v&mask;
    if(!usable) return NO_RESOURCE;
    uint32_t n=highest(usable);
    rr_rt_w(b,bitmap,v&~bit(n),4);rr_rt_w(b,out,n,1);return OK;
}
static uint32_t release(rr_rt_bus *b,uint32_t bitmap,uint32_t n) {
    uint32_t v=rr_rt_r(b,bitmap,4);
    if(shifted(v,n)&1u) return INVALID;
    rr_rt_w(b,bitmap,v|bit(n),4);return OK;
}
static uint32_t release_channel(rr_rt_bus *b,uint32_t d,uint32_t ch) {
    return ch==255u?INVALID:release(b,rr_rt_r(b,d+4u,4),ch);
}
static uint32_t shared_needed(rr_rt_bus *b,uint32_t a,uint32_t c) {
    return (domain(b,a)==15u||domain(b,c)==15u)&&a!=SHARED&&c!=SHARED&&a!=c;
}
static int toggle(rr_rt_bus *b,uint32_t h,uint32_t enable) {
    if(h>=32u) return -2;
    uint32_t s=SLOTS+12u*h,a=rr_rt_r(b,s,4),c=rr_rt_r(b,s+4u,4);
    if(!a||a!=c) return -2;
    uint32_t offset=domain(b,a)==15u?8u:9u;
    uint32_t ch=rr_rt_r(b,s+offset,1),mask=bit(ch),r=rr_rt_r(b,a,4)+(enable?0x504u:0x508u);
    rr_rt_w(b,r,mask,4);rr_rt_w(b,r,mask,4);return b->error?-2:0;
}
int rr_receiver_radio_test_gppi(rr_rt_bus *b,uint32_t entry,const uint32_t args[4],uint32_t *result,rr_rt_pending *pending) {
    (void)pending;
    if(!b||!b->ram||!b->firmware||!args||!result) return -2;
    uint32_t h=args[0],a=args[1],c=args[2],s,d,e,ch,v;
    *result=0;entry&=~1u;
    switch(entry) {
    case 0x0e068a5cu:
        *result=take(b,h,0xffffffffu,a);break;
    case 0x0e068a9cu:
        *result=release(b,h,a);break;
    case 0x0e06ab70u: case 0x0e06abecu:
        *result=domain(b,h);break;
    case 0x0e06ab78u:
        *result=SHARED;break;
    case 0x0e06ab80u:
        *result=lookup(b,h);break;
    case 0x0e06a0d4u:
        *result=shared_needed(b,h,a);break;
    case 0x0e06a658u:
        *result=take(b,0x23000af8u,0xffffffffu,h);
        if(*result==OK) reset(b,SLOTS+12u*rr_rt_r(b,h,1));
        break;
    case 0x0e06a484u:
        if(!h||h!=a) return -2;
        *result=take(b,rr_rt_r(b,h+4u,4),rr_rt_r(b,h+8u,4)|rr_rt_r(b,h+12u,4),c);break;
    case 0x0e06a264u:
        if(!h||h!=a) return -2;
        *result=release_channel(b,h,c);break;
    case 0x0e06a760u:
        if(h>=32u) return -2;
        d=lookup(b,a);e=lookup(b,c);if(!d||d!=e) return -2;
        s=SLOTS+12u*h;ch=s+(domain(b,d)==15u?8u:9u);
        v=take(b,rr_rt_r(b,d+4u,4),rr_rt_r(b,d+8u,4)|rr_rt_r(b,d+12u,4),ch);
        if(v!=OK) { (void)release_channel(b,d,rr_rt_r(b,ch,1));reset(b,s);break; }
        rr_rt_w(b,s,d,4);rr_rt_w(b,s+4u,e,4);
        rr_rt_w(b,reg(a),rr_rt_r(b,ch,1)|0x80000000u,4);
        rr_rt_w(b,reg(c),rr_rt_r(b,ch,1)|0x80000000u,4);break;
    case 0x0e06a8e0u:
        if(h>=32u) return -2;
        d=lookup(b,a);e=lookup(b,c);if(!d||d!=e) return -2;
        s=SLOTS+12u*h;ch=rr_rt_r(b,s+(domain(b,d)==15u?8u:9u),1);
        if(release_channel(b,d,ch)==OK) {reset(b,s);rr_rt_w(b,reg(a),0,4);rr_rt_w(b,reg(c),0,4);}break;
    case 0x0e06a6a0u: case 0x0e06a708u:
        if(h>=32u) return -2;
        d=lookup(b,a);if(!d) return -2;
        s=SLOTS+12u*h;
        /* A0D4/AB78 conditional calls have no memory effects. */
        v=entry==0x0e06a708u?0u:rr_rt_r(b,s+(domain(b,d)==15u?8u:9u),1)|0x80000000u;
        rr_rt_w(b,reg(a),v,4);break;
    case 0x0e06aaccu:
        if(h>=32u) return -2;
        s=SLOTS+12u*h;ch=rr_rt_r(b,s+8u,1);if(ch==255u) break;
        d=rr_rt_r(b,s,4);if(!d) return -2;
        if(!(shifted(rr_rt_r(b,rr_rt_r(b,d,4)+0x500u,4),ch)&1u)) break;
        e=rr_rt_r(b,s+4u,4);if(!e) return -2;
        v=shifted(rr_rt_r(b,rr_rt_r(b,e,4)+0x500u,4),ch)&1u;
        if(v&&shared_needed(b,d,e)) v=shifted(rr_rt_r(b,rr_rt_r(b,SHARED,4)+0x500u,4),ch)&1u;
        *result=v;break;
    case 0x0e06a108u:
        return toggle(b,h,a);
    case 0x0e06ab28u: case 0x0e06ab4cu:
        while(h) {
            uint32_t n=0;while(!(h&bit(n))) n++;
            int rc=toggle(b,n,entry==0x0e06ab28u);if(rc) return rc;
            h&=~bit(n);
        }break;
    default:return -2;
    }
    return b->error?-2:0;
}
