#include "mouse_lifecycle.h"
static uint16_t g16(const uint8_t *p){return (uint16_t)(p[0]|((uint16_t)p[1]<<8));}
static uint32_t g32(const uint8_t *p){return (uint32_t)p[0]|((uint32_t)p[1]<<8)|((uint32_t)p[2]<<16)|((uint32_t)p[3]<<24);}
static void s16(uint8_t *p,uint16_t v){p[0]=(uint8_t)v;p[1]=(uint8_t)(v>>8);}
static void s32(uint8_t *p,uint32_t v){p[0]=(uint8_t)v;p[1]=(uint8_t)(v>>8);p[2]=(uint8_t)(v>>16);p[3]=(uint8_t)(v>>24);}
static void packet_config(uint8_t *m,uint8_t *r){
 const uint8_t *c=m+0x2620;
 s32(r+0xe34,g32(m+0x27b4));
 s32(r+0xe20,(uint32_t)c[0]|((uint32_t)c[1]<<8)|((uint32_t)c[2]<<16)|((uint32_t)c[3]<<20)|((uint32_t)c[4]<<22)|((uint32_t)c[5]<<24)|((uint32_t)c[6]<<26)|((uint32_t)c[7]<<29));
 s32(r+0xe28,(uint32_t)c[8]|((uint32_t)c[9]<<8)|((uint32_t)c[10]<<16)|((uint32_t)c[11]<<24)|((uint32_t)c[12]<<25));
}
static void radio_mode(uint8_t *r,unsigned mode){
 s32(r+0x500,mode==4u?9u:4u);
 uint32_t x=g32(r+0x8a0);
 if(x==0x80000000u || x==0x58120eu)s32(r+0x8a0,0x58090e);
 s32(r+0x8a4,0xf8aa5f);s32(r+0x8a8,0xc00030);s32(r+0x8ac,0xa80030);
 s32(r+0x7ac,0x8672827a);s32(r+0x7b0,0x7e768672);s32(r+0x7b4,0x0406007e);s32(r+0x7e4,0x0412c384);
}
static void channel_mask(uint8_t *m,uint8_t *r){
 unsigned n=0;
 for(unsigned i=0;i<37;i++){
  uint8_t v=0xff;
  if((m[0x26b9+i/8]&(1u<<(i%8)))!=0u){m[0x26c8+n]=(uint8_t)n;m[0x26ed+n]=(uint8_t)i;n++;v=(uint8_t)i;}
  m[0x2712+i]=v;
 }
 m[0x2737]=(uint8_t)n;
 uint32_t base=g32(r+0xe30);s16(m+0x26c6,(uint16_t)(base^(base>>16)));
}
int rr_mouse_lifecycle(uint8_t m[RR_LIFECYCLE_RAM_BYTES],uint8_t r[RR_LIFECYCLE_RADIO_BYTES],uint8_t t[RR_LIFECYCLE_TIMER_BYTES],uint32_t event){
 if(g32(m+0x2a04)!=0x17u || event!=5u)return 0;
 if(g32(m+0x1540)!=0u || g32(m+0x1578)!=0u)return -2;
 if(g16(m+0x6b7e)==0u && (g32(m+0x67cc)&6u)==0u)return -3;
 s32(r+0x100,0);s32(t+0x8c,0);
 if(g32(m+0x298c)!=0u){
  s32(m+0x298c,0); /* 23025f44 is a literal BX LR, no notification effect. */
  uint32_t identity=g32(m+0x27b0);s32(m+0x27ac,identity);s32(r+0xe30,identity);s32(m+0x27b4,~identity);
 }
 s32(r+0xe3c,1);s32(r+0xe40,10);s32(t+0x8c,0);
 /* Both original timer-stop calls on23001540 return -22 internally when inactive. */
 uint16_t mode=g16(m+0x2798);
 if(mode==1u || mode==2u || mode==4u){
  if(mode!=2u)packet_config(m,r);
  s32(m+0x2978,3);s16(m+0x2794,3);m[0x2a1f]=0xff;
  s16(m+0x2a0a,(uint16_t)(g16(m+0x2a0a)+5u));
  s32(m+0x2a10,0);s32(m+0x2a14,0);s16(m+0x2a0c,0);s16(m+0x29a8,0);
  if(mode==4u){
   s32(m+0x2a00,0x18);s16(m+0x29fa,5);
   uint16_t rate=g16(m+0x29ac);m[0x29f9]=(uint8_t)(rate==4u || rate>7u);
  }
  s32(t+0xdc,(uint32_t)m[0x76ef]|0x80000000u);
  s32(r+0x400,mode==2u?0x80001u:1u);s32(r+0x490,0xffffffffu);
  s32(r+0x488,mode==2u?0x100u:mode==1u?0x14eu:0x140u);
  radio_mode(r,mode==4u?4u:2u);
  uint16_t selector=g16(m+0x27a2);if(selector==2u || selector==3u)channel_mask(m,r);
  s32(m+0x2a04,0x18);
  if(mode==2u){s32(r+0x200,0);s32(r+0x218,0);s32(r+0x220,0);s32(r+0x10,1);}
  for(unsigned a=0x29b4;a<=0x29cc;a+=4)s32(m+a,0);
  uint16_t timing=mode==2u?2u:mode==4u?5u:g16(m+0x29ac)==1u?4u:3u;
  s16(m+0x283c,timing);
  s32(t+0x548,mode==2u?300u:mode==4u?415u:g16(m+0x29ac)==1u?395u:390u);
 }
 /*23025dc0 first stops inactive timer23001578, then optional work submit. */
 if(g16(m+0x6b7e)==0u){s16(m+0x6b7e,1);s16(m+0x6b82,mode);}
 return 0;
}

int rr_mouse_lifecycle_connected_work(uint8_t m[RR_LIFECYCLE_RAM_BYTES]){
 if(g16(m+0x6b7e)!=1u)return -4;
 if(m[0x7748]!=0u && m[0x7747]!=0u && g32(m+0x1b48)!=0u)return -2;
 s16(m+0x76e0,1);m[0x771f]=1;
 if(m[0x7748]!=0u && m[0x7747]!=0u)m[0x7747]=0;
 m[0x7788]=2;m[0x777f]=1;
 if(m[0x775d]==0u && m[0x775c]==0u){
  m[0x775d]=1;m[0x7743]=0xff;m[0x775c]=1;m[0x7742]=0xff;m[0x7741]=0xff;
  s16(m+0x769c,0);m[0x775e]=0;
 }
 m[0x772c]=1;
 if(m[0x7736]!=0u){m[0x772d]=1;s16(m+0x7690,0);m[0x772c]=0;}
 return 0;
}
