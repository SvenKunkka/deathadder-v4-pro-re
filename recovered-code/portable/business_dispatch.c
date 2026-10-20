#include "business_dispatch.h"
#include <string.h>
static uint16_t le16(const uint8_t *p) {return (uint16_t)(p[0]|(uint16_t)p[1]<<8);}
static uint16_t be16(const uint8_t *p) {return (uint16_t)((uint16_t)p[0]<<8|p[1]);}
static void put16(uint8_t *p,uint16_t x) {p[0]=(uint8_t)x;p[1]=(uint8_t)(x>>8);}
static void count_all(rr_business_dispatch_state *s) {put16(s->counters,(uint16_t)(le16(s->counters)+1));}
void rr_business_dispatch_finish(rr_business_dispatch_state *s) {
    memset(s->context+0x8c,0,4);
    put16(s->counters+2,(uint16_t)(le16(s->counters+2)+1));count_all(s);
}
int rr_business_dispatch(rr_business_dispatch_state *s, rr_business_dispatch_event *event) {
    if(!s||!event)return -1;
    uint8_t *c=s->context,header=c[0x116];unsigned cls=(header&63u)>>3;
    unsigned len=c[0x114],seq=header&7u,accumulated=header>>7,epoch=(header>>6)&1;
    if(len>0 && len<128 && (cls==0||cls>5))return -1;
    memset(event,0,sizeof(*event));
    if(len==0||len>=128)return 0; /* original signed-byte greater-than-zero */
    if(c[0xb7+cls]==seq) {
        if(cls==1) {
            if(c[0x9d]==1 && accumulated==0)memset(s->motion,0,6);
            memset(c+0x8c,0,4);
        }
        count_all(s);return 0;
    }
    c[0xb7+cls]=(uint8_t)seq;
    if(cls!=1 && len<=2) {rr_business_dispatch_finish(s);return 0;}
    event->forward=1;event->business_class=(uint8_t)cls;event->metadata=c[0x69];
    if(cls!=1) {
        event->size=(uint8_t)(len-2);memcpy(event->payload,c+0x117,len-2);return 0;
    }
    if(accumulated==1 && c[0xa6]!=epoch) {
        c[0xa6]=(uint8_t)epoch;
        memset(s->motion,0,5); /* original clears X/Y + wheel; button later overwritten */
    }
    const uint8_t *p=c+0x117;
    uint16_t x=be16(p+2),y=be16(p+4);
    uint16_t dx=(uint16_t)(x-le16(s->motion)),dy=(uint16_t)(y-le16(s->motion+2));
    uint8_t wheel=(uint8_t)(p[1]-s->motion[4]);
    event->size=7;event->payload[0]=0;event->payload[1]=p[0];event->payload[2]=wheel;
    event->payload[3]=(uint8_t)(dx>>8);event->payload[4]=(uint8_t)dx;
    event->payload[5]=(uint8_t)(dy>>8);event->payload[6]=(uint8_t)dy;
    if(c[0x9d]!=0 && accumulated!=1)memset(s->motion,0,6);
    else {put16(s->motion,x);put16(s->motion+2,y);s->motion[4]=p[1];s->motion[5]=p[0];}
    return 0;
}
