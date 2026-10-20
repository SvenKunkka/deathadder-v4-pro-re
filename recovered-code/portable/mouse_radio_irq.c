/* Source-derived mode1/2 RADIO IRQ, original firmware1.20. */
#include "mouse_radio_irq.h"
#include "business_tx.h"
#include <string.h>
static unsigned r16(const uint8_t*p){return p[0]|(unsigned)p[1]<<8;}
static uint32_t r32(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void w16(uint8_t*p,unsigned x){p[0]=(uint8_t)x;p[1]=(uint8_t)(x>>8);}
static void w32(uint8_t*p,uint32_t x){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(x>>(8*i));}
static void advance(uint8_t*m,unsigned bank){uint8_t next=(uint8_t)(m[0x29d5+bank]+1);if(next==m[0x29df])next=0;m[0x29d5+bank]=next;}
/* Exact230238f0: called here witharg0=1 and require_due0/1. */
static void failure(uint8_t*m,int require_due){
 if(require_due&&!m[0x2a25])return;
 unsigned state=r16(m+0x2794),rate=r16(m+0x29ac),counter=r16(m+0x2a0a);int allowed=0;
 if(state==3){
  if(rate==1||rate==2||rate==4||rate==8)allowed=1;
  else if(rate==16)allowed=(counter&1)==0;
  else if(rate==32)allowed=(counter&3)==0;
  else if(rate==64)allowed=(counter&7)==0;
 }else if(state==4)allowed=1;
 if(allowed){unsigned bank=r16(m+0x2836),at=0x2a14+bank*2,count=(uint16_t)(r16(m+at)+1);w16(m+at,count);if(count>3){advance(m,bank);w16(m+at,0);}}
 m[0x2a25]=0;
}
int rr_mouse_radio_irq_with_ack(uint8_t*m,uint8_t*r,uint8_t*t,uint32_t*nvic,unsigned mode,rr_mouse_ack_handler handler,void *context){
 if(!m||!r||!t||!nvic||(mode!=1&&mode!=2))return -1;
 uint32_t state=r32(m+0x2a04);unsigned bank=r16(m+0x2836),qid=r16(m+0x2a1a);
 int rx=r32(r+0x220)==1&&state==0x1a,ok=r32(r+0x22c)==1;
 if(rx&&bank>1)return -3;
 if(rx&&ok&&qid==3&&r32(m+0x6b68)!=0&&!handler)return -2;
 const unsigned events[4]={0x204,0x208,0x20c,0x218};
 for(unsigned i=0;i<4;i++)if(r32(r+events[i])==1)w32(r+events[i],0);
 if(r32(r+0x220)!=1)return 0;
 w32(r+0x220,0);
 if(mode==2&&state==0x19)w32(r+0x100,0);
 if(state==0x1a){
  w32(r+0x104,0);
  if(mode==2){w32(r+0x110,0);w32(t+0xdc,0);}
  else w32(r+0x400,r32(r+0x400)&~0x80000u);
  if(ok){
   if(mode==1)w32(r+0x22c,0);
   if((r32(m+0x29c4)|r32(m+0x29cc))==0){
    if(mode==2||r16(m+0x29ac)==1||r16(m+0x283c)==1)w32(m+0x29c4,r32(t+0x55c));
    else if(r16(m+0x283c)==3)w32(m+0x29c4,r32(t+0x55c)-250u);
   }
   memcpy(m+0x2a96,m+0x2630,16);m[0x2630]=0;
   unsigned at=0x2a14+bank*2;
   if(mode==1&&r16(m+at)>2){w16(m+at,0);advance(m,bank);}
   m[0x2a1e]=(uint8_t)(m[0x2a1e]+1);if(m[0x2a1e]==8)m[0x2a1e]=1;
   w16(m+0x2a0c,0);w16(m+at,0);m[0x2a22]=1;
   if(mode==1){m[0x2a26]=0;memset(m+0x2670,0,24);}
   if(qid<6){rr_bt_pop(m,1,0,qid);if(qid==3&&r32(m+0x6b68)!=0){int rc=handler(context,(uint16_t)qid);if(rc)return rc;}}
   *nvic=0x10000000u;
  }else{
   m[0x2a26]=0;
   if(mode==1){
    if(r16(m+0x29ac)==1)failure(m,0);
    else if(r16(m+0x283c)==1)m[0x2a25]=1;
    else if(r16(m+0x283c)==3)failure(m,1);
   }
   m[0x29d0]=2;
  }
  w32(m+0x2a04,0x18);
 }
 /* Actual tail230218d8 only runs after DISABLED==1, including other states. */
 w32(r+0x22c,0);w32(r+0x230,0);return 0;
}

int rr_mouse_radio_irq(uint8_t*m,uint8_t*r,uint8_t*t,uint32_t*nvic,unsigned mode){return rr_mouse_radio_irq_with_ack(m,r,t,nvic,mode,0,0);}
