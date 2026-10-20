#include "handshake_notification.h"
#include <string.h>
static uint16_t u16(const uint8_t *p){return (uint16_t)(p[0]|((uint16_t)p[1]<<8));}
static uint32_t u32(const uint8_t *p){return (uint32_t)p[0]|((uint32_t)p[1]<<8)|((uint32_t)p[2]<<16)|((uint32_t)p[3]<<24);}
static void w16(uint8_t *p,uint16_t v){p[0]=(uint8_t)v;p[1]=(uint8_t)(v>>8);}
static void w32(uint8_t *p,uint32_t v){p[0]=(uint8_t)v;p[1]=(uint8_t)(v>>8);p[2]=(uint8_t)(v>>16);p[3]=(uint8_t)(v>>24);}
int rr_dongle_handshake_step(uint8_t m[RR_SLOT_BYTES],const uint8_t rx[RR_HANDSHAKE_BYTES],
 uint8_t slot,rr_handshake_globals *g,rr_notification_context *c){
 if(u16(m+0xc8)!=3u || u32(m+0x14)==0u || rx[0]!=11u || rx[3]!=0x16u || (rx[1]&0x80u)!=0u)
  return rr_dongle_handshake(m,rx,slot,g);
 if(c==NULL)return RR_UNRECOVERED_NOTIFICATION;
 uint8_t *q=c->queue;uint32_t write=u32(q+28),read=u32(q+24),count=u32(q+32);
 /* Analysis-interface bounds, not newly attributed firmware validation. */
 if(u32(q)!=0x23001b8cu || u32(q+4)!=0x23001b8cu || u32(q+8)!=36u || u32(q+12)!=5u ||
    u32(q+16)!=0x23015760u || u32(q+20)!=0x23015814u ||
    write<0x23015760u || write>=0x23015814u || (write-0x23015760u)%36u!=0u ||
    read<0x23015760u || read>=0x23015814u || (read-0x23015760u)%36u!=0u || count>5u)
  return RR_UNMODELED_QUEUE;
 uint8_t message[36];w32(message,5);w16(message+4,slot);w16(message+6,1);
 w32(message+8,c->base1);message[12]=m[7];message[13]=m[6];message[14]=m[9];message[15]=m[8];
 memcpy(message+16,c->opaque_tail,20);
 if(count==5u){count=0;w32(q+32,0);w32(q+24,write);} /* purge, then retry */
 memcpy(c->ring+(write-0x23015760u),message,36);write+=36u;
 if(write==0x23015814u)write=0x23015760u;
 w32(q+28,write);w32(q+32,count+1u);
 w32(m+0x14,0);w16(m+0x1a,0);
 if(c->other_pending==0u)c->rxaddresses&=0xfffffffeu;
 w32(m+0xcc,0);w16(m+0xc8,6);return 2;
}
