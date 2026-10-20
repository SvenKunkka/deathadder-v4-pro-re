#include "handshake.h"
#include <string.h>
static uint16_t get16(const uint8_t *p) {
    return (uint16_t)((uint16_t)p[0] | ((uint16_t)p[1] << 8));
}
static uint32_t get32(const uint8_t *p) {
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static void put16(uint8_t *p, uint16_t v) {p[0]=(uint8_t)v;p[1]=(uint8_t)(v>>8);}
static void put32(uint8_t *p, uint32_t v) {
    p[0]=(uint8_t)v;p[1]=(uint8_t)(v>>8);p[2]=(uint8_t)(v>>16);p[3]=(uint8_t)(v>>24);
}
static uint8_t advance(uint8_t v) {v=(uint8_t)(v+1u);return v==8u?1u:v;}
static void header(uint8_t *p,uint8_t sequence,uint8_t slot,uint8_t command) {
    p[0]=11;p[1]=(uint8_t)((slot&1u)<<6);p[2]=sequence;p[3]=command;
}
uint8_t rr_dongle_offer(uint8_t p[RR_HANDSHAKE_BYTES],uint8_t seq,uint8_t slot,
    uint32_t base1,uint8_t caps,uint8_t flag7,uint8_t flag6,uint16_t counter) {
    header(p,seq,slot,0x11);
    p[4]=(uint8_t)(base1>>24);p[5]=(uint8_t)(base1>>16);
    p[6]=(uint8_t)(base1>>8);p[7]=(uint8_t)base1;
    p[8]=(uint8_t)((caps&15u)|((flag7&1u)<<7)|((flag6&1u)<<6));
    p[9]=0;p[10]=(uint8_t)(counter>>8);p[11]=(uint8_t)counter;
    return advance(seq);
}
int rr_dongle_handshake(uint8_t m[RR_SLOT_BYTES],const uint8_t rx[RR_HANDSHAKE_BYTES],
    uint8_t slot,rr_handshake_globals *g) {
    uint16_t state=get16(m+0xc8);
    if((rx[1]&0x80u)!=0u || rx[0]!=11u)return 0;
    if(state==0u) {
        if(rx[3]!=0x12u)return 0;
        if(get32(m+0x14)!=0u && get16(m+6)!=0xffffu &&
           (rx[6]!=m[6] || rx[7]!=m[7]))return 0;
        m[0x84]=(uint8_t)(rx[4]>>7);
        uint16_t caps=(g->status0<=2u && g->status1<=2u)?g->primary_cap:g->fallback_cap;
        uint8_t common=(uint8_t)(rx[4]&caps&15u);
        if(common==0u)return 0;
        memcpy(m+6,rx+6,4);
        m[10]=rx[7];m[11]=rx[6];m[12]=rx[9];m[13]=rx[8];
        g->selected_mode=(common&8u)?8u:(common&4u)?4u:(common&1u)?1u:2u;
        header(m+0xd4,m[0xa7],slot,0x13);
        m[0xd8]=(uint8_t)(g->selected_mode|((g->selector&3u)<<4));
        m[0xd9]=0;m[0xda]=(uint8_t)((g->index0&15u)|(g->index1<<4));
        put16(m+0xc8,2);
    } else if(state==2u) {
        if(rx[3]!=0x14u)return 0;
        put16(m+0x34,rx[4]);header(m+0xd4,m[0xa7],slot,0x15);
        if(g->selector<=1u)memcpy(m+0xd8,g->frequencies,8);
        else if(g->selector==2u || g->selector==3u) {
            memcpy(m+0xd8,g->mask,5);
            if(g->selector==2u)m[0xdd]=g->extra;
        }
        put16(m+0xc8,3);
    } else if(state==3u) {
        if(rx[3]!=0x16u)return 0;
        if(get32(m+0x14)!=0u)return RR_UNRECOVERED_NOTIFICATION;
        put16(m+0xc8,6);put32(m+0xcc,0);return 2;
    } else return 0;
    m[0xa7]=advance(m[0xa7]);put32(m+0xcc,0x40000);return 1;
}
