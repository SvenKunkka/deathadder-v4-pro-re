/* Authored from mouse230259ec and dongle23025004 with GNU Thumb cross-check.
 * All copies before the declared downstream boundary are modeled, including
 * stale buffer tails, index restart and exact motion accumulator clears. */
#include "business_rx.h"
#include "business_cipher.h"
#include <string.h>
static uint16_t le16(const uint8_t *p) { return (uint16_t)(p[0]|(uint16_t)p[1]<<8); }
static uint16_t be16(const uint8_t *p) { return (uint16_t)((uint16_t)p[0]<<8|p[1]); }
static void put16(uint8_t *p, uint16_t x) { p[0]=(uint8_t)x;p[1]=(uint8_t)(x>>8); }
static uint32_t le32(const uint8_t *p) { return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24; }
static void put32(uint8_t *p,uint32_t x) { for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(x>>(8*i)); }
int rr_business_rx(int mouse, rr_business_rx_state *s, unsigned cls,
                   const uint8_t *fragment, unsigned size,
                   const uint32_t key[4], rr_business_rx_event *event) {
    if(!s||!fragment||!event||cls>=6||size<1||size>129)return -1;
    unsigned index=fragment[0]&31u, offset=index?s->length[cls]:0;
    int mismatch=index && s->expected[cls]!=index;
    unsigned total=offset+size-1;
    int final=(fragment[0]&128u)==0;
    if(!mismatch && (total>128 || (!mouse && final && (cls==2||cls==4)
        && ((total!=8&&total!=16)||!key))))return -1;
    memset(event,0,sizeof(*event));event->business_class=(uint8_t)cls;
    if(mismatch) {
        s->expected[cls]=0;s->length[cls]=0;event->kind=RR_RX_MISMATCH;return 0;
    }
    if(index==0)s->expected[cls]=0;
    memcpy(s->data[cls]+offset,fragment+1,size-1);
    s->length[cls]=(uint8_t)total;
    s->expected[cls]=(uint8_t)(s->expected[cls]+1);
    if(!final)return 0;
    s->expected[cls]=0;s->length[cls]=0;
    if(mouse) {
        s->completed_class=(uint8_t)cls;s->completed_length=(uint8_t)total;
        memcpy(s->completed,s->data[cls],total);
        event->kind=RR_RX_MOUSE_WORK;event->length=(uint8_t)total;
        memcpy(event->payload,s->completed,total);return 0;
    }
    event->kind=cls==3?RR_RX_MANAGEMENT:RR_RX_DELIVER;
    event->length=(uint8_t)total;memcpy(event->payload,s->data[cls],128);
    /* Downstream class3/5 receive a pointer into the full persistent bank.
     * Preserve stale tail bytes even when logical length is shorter. */
    if(cls==1) {
        const uint8_t *p=s->data[1];
        event->length=8;event->payload[0]=(p[0]|s->motion[0])&127u;
        event->payload[1]=0;event->payload[2]=0;
        event->payload[3]=(uint8_t)(p[1]+s->motion[1]);
        put16(event->payload+4,(uint16_t)(be16(p+2)+le16(s->motion+4)));
        put16(event->payload+6,(uint16_t)(be16(p+4)+le16(s->motion+6)));
        s->motion[0]=0;s->motion[1]=0;s->motion[2]=0;
        memset(s->motion+4,0,4); /* offset3 deliberately preserved */
    } else if(cls==2||cls==4) {
        uint32_t words[4]={0,0,0,0};
        for(unsigned i=0;i<total/4;i++)words[i]=le32(s->data[cls]+i*4);
        (void)rr_cipher_decrypt_words(words,total/4,key);
        memset(event->payload,0,sizeof(event->payload));
        for(unsigned i=0;i<total/4;i++)put32(event->payload+i*4,words[i]);
        event->length=cls==2?8:16;
        if(cls==2 || event->payload[0]==1) {
            s->activity=0;
            for(unsigned i=cls==2?0:2;i<event->length;i++)
                if(event->payload[i])s->activity=1;
        }
    }
    return 0;
}
