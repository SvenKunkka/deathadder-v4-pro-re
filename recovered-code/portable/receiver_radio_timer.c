#include "receiver_radio_timer.h"
#include <string.h>
#define R(o) h->radio[(o)/4]
#define T(o) h->timer[(o)/4]
static uint16_t r16(const uint8_t*p){return (uint16_t)(p[0]|p[1]<<8);}
static uint32_t r32(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void w16(uint8_t*p,uint16_t x){p[0]=(uint8_t)x;p[1]=(uint8_t)(x>>8);}
static void w32(uint8_t*p,uint32_t x){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(x>>(i*8));}
static void channel_map(uint8_t*r,rr_receiver_radio_hw*h){
 memcpy(r+0x30d9,r+0x30de,5);
 unsigned mode=r16(r+0x323e);if(mode!=2&&mode!=3)return;
 unsigned count=0;for(unsigned ch=0;ch<37;ch++){
  uint8_t value=255;if(r[0x30d9+ch/8]&(1u<<(ch%8))){r[0x30e8+count]=(uint8_t)count;r[0x310d+count]=(uint8_t)ch;count++;value=(uint8_t)ch;}r[0x3132+ch]=value;
 }r[0x3157]=(uint8_t)count;w16(r+0x30e6,(uint16_t)(R(0xe30)^(R(0xe30)>>16)));
}
static uint16_t permute(uint16_t v,const uint8_t*f){const uint8_t*t=f+0x1bb74;return (uint16_t)(t[(v&255)>>4]|t[v&15]<<4|t[(v&4095)>>8]<<12|t[v>>12]<<8);}
static uint16_t next_frequency(uint8_t*r,const uint8_t*f,unsigned counter,unsigned channel){
 unsigned mode=r16(r+0x323e);if(mode<=1)return r[0x534b+4*channel+r[0x5349+channel]];
 if(mode!=2&&mode!=3)return 0x962;
 w16(r+0x30e4,(uint16_t)counter);uint16_t id=r16(r+0x30e6),v=(uint16_t)(counter^id);
 for(unsigned i=0;i<3;i++)v=(uint16_t)(17u*permute(v,f)+id);
 v^=id;uint8_t ch=r[0x3132+v%37];if(ch==255)ch=r[0x310d+r[0x30e8+((uint32_t)v*r[0x3157]>>16)]];
 r[0x30e3]=ch;w16(r+0x3228,ch);return f[0x1bb84+ch];
}
static void period_stats(uint8_t*r,rr_receiver_radio_hw*h){
 unsigned counter=r16(r+0x5376);
 if(r[0x325d]&&r16(r+0x33d6)==counter){r[0x325d]=0;channel_map(r,h);counter=r16(r+0x5376);}
 if(counter&2047)return;
 uint32_t totals=r32(r+0x33dc);w32(r+0x33d8,totals);w32(r+0x33dc,0);w16(r+0x33e0,0);
 unsigned interval=r16(r+0x341c),threshold=8090;
 switch(interval){case 2:threshold=3994;break;case 4:threshold=1997;break;case 8:threshold=999;break;case 16:threshold=500;break;case 32:threshold=250;break;case 64:threshold=125;break;default:break;}
 if((totals>>16)>=threshold)w16(r+0x33e0,1);
}
static void disconnect_prefix(uint8_t*r,rr_receiver_radio_hw*h,rr_receiver_timer_pending*p){
 R(0x104)=0;R(0x10c)=0;R(0x100)=0;w32(r+0x3468,0);R(0x200)=0;R(0x218)=0;R(0x220)=0;R(0x10)=1;
 /* 23021DFC -> 23020E84(2) -> 23020D5C -> queue0 reset. */
 w16(r+0x3234,2);R(0x400)=0x80001;R(0x490)=0xffffffffu;R(0x488)=0x100;R(0x500)=4;
 if(R(0x8a0)==0x80000000u||R(0x8a0)==0x58120e)R(0x8a0)=0x58090e;
 R(0x8a4)=0xf8aa5f;R(0x8a8)=0xc00030;R(0x8ac)=0xa80030;R(0x7ac)=0x8672827a;R(0x7b0)=0x7e768672;R(0x7b4)=0x406007e;R(0x7e4)=0x412c384;
 R(0xe34)=0xc3c2c1e7;
 R(0xe20)=(uint32_t)r[0x3032]<<16|(uint32_t)r[0x3031]<<8|r[0x3030]|(uint32_t)r[0x3033]<<20|(uint32_t)r[0x3034]<<22|(uint32_t)r[0x3035]<<24|(uint32_t)r[0x3036]<<26|(uint32_t)r[0x3037]<<29;
 R(0xe28)=(uint32_t)r[0x303a]<<16|(uint32_t)r[0x3039]<<8|r[0x3038]|(uint32_t)r[0x303b]<<24|(uint32_t)r[0x303c]<<25;
 if(r32(r+0x3468)<11&&r32(r+0x43ec)<11){w16(r+0x5349,0);w32(r+0x5380,0);w32(r+0x5370,11);}
 r[0x353c]=0;r[0x3542]=0;r[0x33ec]=1;
 p->active=1;p->entry=0x0e06d0d0;p->arg0=0x23001c54;
}
int rr_receiver_timer_mode4(uint8_t*r,const uint8_t*f,rr_receiver_radio_hw*h,rr_receiver_timer_pending*p){
 memset(p,0,sizeof(*p));if(r16(r+0x3230)<2)return 0;if(r16(r+0x3234)!=4)return -1;
 if(T(0x140)==1){T(0x140)=0;w16(r+0x32d0,0);T(0x540)=16000;R(0x104)=0;T(0x544)=2720;T(0x550)=0;T(0x548)=3200;period_stats(r,h);return 0;}
 if(T(0x144)==1)return rr_receiver_timer_cc1(r,h);
 if(T(0x148)==1){
  T(0x148)=0;unsigned slot=r16(r+0x32d0),state=r32(r+0x3468);
  if(slot==1||slot==4){T(0x544)=slot==1?4640:12640;T(0x550)=T(0x544);T(0x548)=slot==1?5280:13280;if(state==11||state==12)R(0x104)=0;}
  else if(slot==2){R(0x100)=0;T(0x544)=7040;T(0x550)=0;T(0x548)=8000;}
  else if(slot==3){R(0x104)=0;T(0x544)=10720;T(0x550)=0;T(0x548)=11200;}
  else if(slot==5){
   R(0x100)=0;T(0x544)=15040;T(0x550)=0;T(0x548)=0;
   for(unsigned peer=0;peer<=2;peer+=2){unsigned b=0x33e8+peer*0xf84;if(r32(r+b)>2){w16(r+b+0x86,(uint16_t)(r16(r+b+0x86)+1));w16(r+b+0x88,(uint16_t)(r16(r+b+0x88)+1));w32(r+b+0x8c,r32(r+b+0x8c)+1);}}
   unsigned counter=r16(r+0x5376);w16(r+0x3226,next_frequency(r,f,counter,r16(r+0x32ca)));w16(r+0x32ca,(uint16_t)((counter>>1)&1));
   if(r32(r+0x33e8)>2){if(r16(r+0x3470)>=100){disconnect_prefix(r,h,p);return 1;}w32(r+0x33e8,r32(r+0x3474)<200?3:4);}
  }return 0;
 }
 for(unsigned i=3;i<8;i++)if(T(0x140+4*i)==1){T(0x140+4*i)=0;break;}return 0;
}
