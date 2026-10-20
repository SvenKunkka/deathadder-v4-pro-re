#include "receiver_legacy_radio.h"
#include "business_tx.h"
#include "handshake.h"
#include <string.h>
#define R(o) h->radio[(o)/4]
#define T(o) h->timer[(o)/4]
static uint16_t u16(const uint8_t*p){return (uint16_t)(p[0]|p[1]<<8);}
static uint32_t u32(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void s16(uint8_t*p,uint16_t x){p[0]=(uint8_t)x;p[1]=(uint8_t)(x>>8);}
static void s32(uint8_t*p,uint32_t x){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(x>>(8*i));}
static void disable(uint8_t*r,rr_receiver_radio_hw*h,unsigned b,unsigned state){s32(r+b+0x80,state);R(0x200)=R(0x218)=R(0x220)=0;R(0x10)=1;}
static void next_channel(uint8_t*r,unsigned ch){if(!r[0x5384]){uint8_t v=(uint8_t)(r[0x5349+ch]+1);r[0x5349+ch]=v==r[0x5353]?0:v;}}
/*23023708(1): deliberately operates peer0, even when IRQ selected another peer.*/
static void failure(uint8_t*r){
 if(!r[0x348a])return;unsigned conn=u32(r+0x33e8),interval=u16(r+0x341c);int tick=0;
 if(conn==3){if(interval<9)tick=!((0xfffffee9u>>interval)&1);else if(interval==16)tick=!(u16(r+0x346e)&1);else if(interval==32)tick=!(u16(r+0x346e)&3);else if(interval==64)tick=!(u16(r+0x346e)&7);}
 else if(conn==4)tick=!(u16(r+0x5376)&0x1d);
 if(tick){unsigned ch=u16(r+0x32ca),a=0x3478+2*ch;uint16_t v=(uint16_t)(u16(r+a)+1);s16(r+a,v);if(v>3){next_channel(r,ch);s16(r+a,0);}}
 r[0x348a]=0;
}
static void receive(uint8_t*r,rr_receiver_radio_hw*h,unsigned mode,unsigned peer){
 unsigned b=0x33e8+peer*0xf84;uint8_t packet[16];memcpy(packet,r+0x3050,16);r[0x3050]=0;memcpy(r+b+0x114,packet,16);r[b+0x9f]=1;
 unsigned header=r[b+0x115],reply=header>>7,seq=(header&127)>>4,ch=u16(r+0x32ca);s16(r+b+0x9c,(uint16_t)(reply|(reply<<8)));
 if(seq!=r[b+0x9b]){s16(r+b+0x88,0);s16(r+b+0x90+2*ch,0);unsigned q=u16(r+b+0x96);if(q){r[b+0x9a]++;if(r[b+0x9a]==8)r[b+0x9a]=1;if(q==255){unsigned i=b+255;uint8_t n=(uint8_t)(r[i+0x15a]+1);if(n==r[i+0x160])n=0;r[i+0x15a]=n;}else rr_bt_pop(r,0,peer,q);s16(r+b+0x98,(uint16_t)q);}}
 r[b+0x9b]=(uint8_t)seq;s16(r+b+0x96,0);s16(r+0x71a4,(uint16_t)peer);h->nvic_last=0x10000000;h->nvic_requests|=0x10000000;
 if(mode==1){unsigned low=header&15;s16(r+b+0x90+2*ch,(uint16_t)low);s16(r+0x33e8+2*(ch+0xfcc),(uint16_t)low);}
}
static void configure(uint8_t*r,rr_receiver_radio_hw*h,unsigned peer){
 unsigned mode=u16(r+0x3236);s16(r+0x3234,(uint16_t)mode);if(mode!=1&&mode!=2&&mode!=4)return;
 if(mode!=2){R(0xe34)=u32(r+0x324c);R(0xe20)=(uint32_t)r[0x3042]<<16|(uint32_t)r[0x3041]<<8|r[0x3040]|(uint32_t)r[0x3043]<<20|(uint32_t)r[0x3044]<<22|(uint32_t)r[0x3045]<<24|(uint32_t)r[0x3046]<<26|(uint32_t)r[0x3047]<<29;R(0xe28)=(uint32_t)r[0x304a]<<16|(uint32_t)r[0x3049]<<8|r[0x3048]|(uint32_t)r[0x304b]<<24|(uint32_t)r[0x304c]<<25;}
 unsigned b=0x33e8+peer*0xf84;s32(r+b,3);s32(r+0x5370,13);s32(r+b+0x8c,0);s32(r+b+0x80,11);s32(r+b+0x86,0);s32(r+b+0x90,0);r[b+0x85]=1;r[b+0x9b]=255;
 if(mode==2)R(0x400)|=0x10;else R(0x400)=0x11;R(0x490)=0xffffffff;R(0x488)=mode==2?0x100:mode==1?0x148:0x144;R(0x500)=mode==4?9:4;
 if(R(0x8a0)==0x80000000||R(0x8a0)==0x58120e)R(0x8a0)=0x58090e;R(0x8a4)=0xf8aa5f;R(0x8a8)=0xc00030;R(0x8ac)=0xa80030;R(0x7ac)=0x8672827a;R(0x7b0)=0x7e768672;R(0x7b4)=0x0406007e;R(0x7e4)=0x0412c384;
 if(mode!=2){T(0x544)=0;T(0x548)=mode==4?13280:12640;if(mode==1)T(0x54c)=0;s16(r+0x32d0,(uint16_t)(mode==4?5:u16(r+b+0x34)==1?4:3));T(0x144)=T(0x148)=T(0x14c)=0;}
}
static int enqueue(uint8_t*r,const uint8_t msg[36],rr_receiver_rtos*c){
 if(u32(r+0x1b94)!=36||u32(r+0x1b98)!=5)return -1;int32_t result;int rc=rr_receiver_message_put(r,0x23001b8c,msg,c,&result);if(rc||!result)return rc;
 rc=rr_receiver_message_purge(r,0x23001b8c,c);if(rc)return rc;return rr_receiver_message_put(r,0x23001b8c,msg,c,&result);
}
static int handshake(uint8_t*r,rr_receiver_radio_hw*h,unsigned peer,rr_receiver_rtos*c,const uint8_t tail[24],int*result){
 unsigned b=0x33e8+peer*0xf84;rr_handshake_globals g={0};g.status0=u32(r+0x33e8);g.status1=u32(r+0x436c);g.primary_cap=u16(r+0x3238);g.fallback_cap=u16(r+0x3234);g.selector=u16(r+0x323e);g.selected_mode=u16(r+0x3236);g.index0=r[0x5349];g.index1=r[0x534a];memcpy(g.frequencies,r+0x534b,8);memcpy(g.mask,r+0x30d9,5);g.extra=r[0x3158];uint8_t rx[12];memcpy(rx,r+b+0xd4,12);
 *result=rr_dongle_handshake(r+b,rx,(uint8_t)peer,&g);s16(r+0x3236,g.selected_mode);
 if(*result!=RR_UNRECOVERED_NOTIFICATION)return 0;
 if(!tail||!c)return -1;uint8_t msg[36];s32(msg,5);s16(msg+4,(uint16_t)peer);s16(msg+6,1);s32(msg+8,u32(r+0x3244));msg[12]=r[b+7];msg[13]=r[b+6];msg[14]=r[b+9];msg[15]=r[b+8];memcpy(msg+16,tail,20);
 int rc=enqueue(r,msg,c);if(rc)return rc;s32(r+b+0x14,0);s16(r+b+0x1a,0);if(!u32(r+0x33fc)&&!u32(r+0x4380))R(0xe40)&=~1u;s16(r+b+0xc8,6);s32(r+b+0xcc,0);*result=2;return 0;
}
int rr_receiver_legacy_radio(uint8_t*r,rr_receiver_radio_hw*h,unsigned mode,rr_receiver_rtos*c,const uint8_t tail[24],const uint8_t padding[2]){
 if(!r||!h||(mode!=1&&mode!=2))return -1;
 unsigned peer=u16(r+(mode==1?0x6274:0x32d0));if(peer>2||u16(r+0x32ca)>1)return -1;unsigned b=0x33e8+peer*0xf84;if(u16(r+b+0x96)>5&&u16(r+b+0x96)!=255)return -1;
 if(c){c->entry=0;c->arg0=0;}
 if(R(0x204)==1)R(0x204)=0;if(R(0x208)==1)R(0x208)=0;
 if(mode==1){
  if(R(0x20c)==1)R(0x20c)=0;
  if(R(0x218)==1){R(0x218)=0;if(u16(r+0x3230)>1){unsigned state=u32(r+b+0x80);if(state==12){if(R(0x22c)==1&&r[0x3050]){R(0x22c)=0;receive(r,h,1,peer);}else{r[0x3050]=0;if(u16(r+0x341c)==1||u16(r+0x32d0)<2)r[b+0xa2]=1;else failure(r);}s32(r+b+0x80,11);}else if(state==13)disable(r,h,b,13);}}
  if(R(0x220)==1){R(0x220)=0;if(u16(r+0x3230)>1&&u32(r+b+0x80)==13){unsigned ch=u16(r+0x32ca),a=b+0x90+2*ch;if(u16(r+a)>2){next_channel(r,ch);s16(r+a,0);}s32(r+b+0x80,13);}R(0x22c)=R(0x230)=0;}return 0;
 }
 if(R(0x218))R(0x218)=0;if(R(0x220)!=1)return 0;R(0x220)=0;
 if(u16(r+0x3230)>1){unsigned state=u32(r+b+0x80);
  if(state==8)s32(r+b+0x80,7);
  else if(state==9){int result=0;if(R(0x22c)==1){int rc=handshake(r,h,peer,c,tail,&result);if(rc)return rc;}if(result<=1)s32(r+b+0x80,7);else if(result==2)disable(r,h,b,10);}
  else if(state==10){R(0x100)=R(0x104)=R(0x110)=0;disable(r,h,b,0);configure(r,h,peer);if(!tail||!padding||!c)return -1;uint8_t msg[36];s32(msg,1);s16(msg+4,(uint16_t)peer);memcpy(msg+6,padding,2);msg[8]=r[b+7];msg[9]=r[b+6];msg[10]=r[b+9];msg[11]=r[b+8];memcpy(msg+12,tail,24);int rc=enqueue(r,msg,c);if(rc)return rc;}
  else if(state==11||state==12){if(state==12&&R(0x22c)==1)receive(r,h,2,peer);s32(r+b+0x80,11);}
  else if(state==13)s32(r+b+0x80,13);
 }
 R(0x22c)=R(0x230)=0;return 0;
}
int rr_receiver_legacy_radio_swi(uint8_t*r,const uint8_t*f,unsigned mode,rr_receiver_legacy_pending*p){return rr_receiver_legacy_business(r,f,mode,u16(r+0x71a4),p);}
