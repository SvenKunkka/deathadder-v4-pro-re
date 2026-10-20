#include "mouse_mode4_tx.h"
#include "business_tx.h"
#include <string.h>
static unsigned h(const uint8_t*p){return p[0]|(unsigned)p[1]<<8;}
static uint32_t w(const uint8_t*p){return p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void ph(uint8_t*p,unsigned v){p[0]=(uint8_t)v;p[1]=(uint8_t)(v>>8);}
static void pw(uint8_t*p,uint32_t v){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(v>>(i*8));}
static unsigned fail(const uint8_t*m,unsigned bank){unsigned sel=h(m+0x27a2),v=0;if(sel<2)v=h(m+0x2a14+bank*2);else if(sel<4)v=h(m+0x289e + h(m+0x2792)*2);return v>14?15:v;}
static int empty(const uint8_t*m,unsigned q){return m[0x2ad6+q]==m[0x2adc+q];}
static unsigned peek(uint8_t*m,unsigned q){uint32_t p=rr_bt_peek(m,1,0,q);return p?p-0x23000000u:0;}
static void tune(uint8_t*m,uint8_t*r){pw(m+0x278c,w(m+0x2790));pw(r+0x708,h(m+0x2790));pw(r+0x710,m[0x2a00]);}
int rr_mouse_mode4_tx(uint8_t*m,uint8_t*r,uint8_t*t){
 if(!m||!r||!t)return -1;if(w(m+0x2a04)!=0x18)return 0;
 unsigned bank=h(m+0x2836),slot=h(m+0x283c),rate=h(m+0x29ac),q=255,src=0;
 if(bank>2||((h(m+0x27a2)==2||h(m+0x27a2)==3)&&h(m+0x2792)>36))return -9;
 for(unsigned c=0;c<6;c++){unsigned cap=m[0x2ae2+c],stride=m[0x2ae8+c];uint32_t p=w(m+0x2af0+4*c);if(!cap||stride<16||m[0x2ad6+c]>=cap||m[0x2adc+c]>=cap||p<0x23000000u||(uint64_t)p+(uint64_t)cap*stride>0x23010000ull)return -9;}
 if(slot==0||slot==3){
  if(rate==2){m[0x27c7]=m[0x27c8];if(m[0x2670])m[0x27c7]=1;}
  if(!m[0x2671]){int all=1;for(unsigned c=0;c<6;c++)if(!empty(m,c))all=0;if(all&&!m[0x29d0])goto inactivity;}
  goto prepare;
 }
 if(slot==1||slot==4){
  if(rate==1){if(!m[0x2671]){if(m[0x2a26])return 0;if(empty(m,1))goto special;}}
  else if(rate!=2||!m[0x27c7]||!m[0x2671])return 0;
  goto prepare;
 }
 if(m[0x29d0])goto prepare;
 inactivity:
 if(m[0x29d1+bank]<(h(m+0x2794)==3?4u:16u))goto special;
 prepare:
 if(slot==0||slot==3){
  pw(r+0x100,0x80000000u|m[slot==0?0x76f5:0x76f3]);pw(r+0x400,w(r+0x400)|1);
  if(rate!=1&&(rate!=2||!m[0x27c7]))pw(r+0x400,w(r+0x400)|0x80000u);tune(m,r);
  if(m[0x2670])goto fallback;
  if(slot==3&&m[0x2671]){q=1;src=peek(m,q);if(src){m[0x2a20]=1;if(rate<3)goto motion;goto selected;}goto fallback;}
  if(h(m+0x2a0a)&1u)for(q=2;q<6;q++){src=peek(m,q);if(src)goto selected_low;}
  for(q=0;q<6;q++){src=peek(m,q);if(src){m[0x2a20]=1;if(rate<3){if(q==1)goto motion;goto selected_low;}goto selected;}}
  goto fallback;
 }
 pw(r+0x108,0x80000000u|m[0x76f3]);pw(r+0x400,w(r+0x400)|1);tune(m,r);
 if(m[0x2670]||(slot!=1&&slot!=4))goto fallback;
 if((slot==1||slot==4)&&rate==1){
  m[0x2a20]=1;if(m[0x2a26])goto cached_or_status;
  q=1;src=peek(m,1);if(src){if(rate<3)goto motion;goto selected;}goto cached_or_status;
 }
 m[0x2a20]=1;if(rate>2)goto status;
 if(!m[0x2671])goto status;
 if(rate==2&&slot!=3)m[0x2a20]=0;else if(rate==2)m[0x2670]=1;
 goto cached;
 selected_low:
 m[0x2a20]=1;if(rate>2)goto selected;m[0x2a26]=1;if(m[0x2671])goto cache_flags;goto selected;
 fallback:
 m[0x2a20]=1;if(rate>2)goto status;
 cached_or_status:
 if(!m[0x2671])goto status;
 cache_flags:
 if((rate==1&&slot==4)||(rate==2&&slot==3))m[0x2670]=1;
 else if((rate==1||rate==2)&&!m[0x2670])m[0x2a20]=0;
 cached:
 m[0x2675]|=m[0x2a19];memcpy(m+0x2a76,m+0x2672,9);src=0x2a76;q=255;goto selected;
 motion:
 m[src+3]|=m[0x2a19];m[0x2671]=1;m[0x2687]|=m[src+3];m[0x2686]=(uint8_t)(m[0x2686]+m[src+4]);
 ph(m+0x2682,h(m+0x2682)+((unsigned)m[src+5]<<8|m[src+6]));ph(m+0x2684,h(m+0x2684)+((unsigned)m[src+7]<<8|m[src+8]));
 m[src+3]=m[0x2687];m[src+4]=m[0x2686];m[src+5]=m[0x2683];m[src+6]=m[0x2682];m[src+7]=m[0x2685];m[src+8]=m[0x2684];
 memcpy(m+0x2672,m+src,9);rr_bt_pop(m,1,0,1);
 if((rate==1&&slot==4)||(rate==2&&slot==3))m[0x2670]=1;else if((rate==1||rate==2)&&!m[0x2670])m[0x2a20]=0;
 q=255;
 selected:
 ph(m+0x2a1a,q);m[0x29d1+bank]=0;pw(m+0x2a10,0);m[src+1]=(uint8_t)((m[0x2a20]<<7)|(m[0x2a1e]<<4)|fail(m,bank));goto encode;
 status:
 m[0x29d1+bank]=0;ph(m+0x2a1a,255);m[0x2a20]=1;src=0x2a76;m[src]=5;m[src+2]=m[0x2a2a];m[0x2a2a]++;if(m[0x2a2a]==8)m[0x2a2a]=1;m[src+3]=0x17;m[src+4]=m[0x2a11];m[src+5]=m[0x2a10];m[src+1]=(uint8_t)(0x80|(m[0x2a1e]<<4)|fail(m,bank));
 encode:
 memcpy(m+0x2650,m+src,16);pw(r+0xed0,0x23002650);{
 unsigned len=m[0x2650];uint8_t sum=0;for(unsigned i=1;i<=len;i++)sum=(uint8_t)(sum+m[0x2650+i]);m[0x2651+len]=(uint8_t)-sum;m[0x2650]=(uint8_t)(len+1);}
 pw(t+0x5c,1);{
 uint32_t cc=w(t+0x55c);int timely=slot==0?cc>99:slot==1?cc<=100:slot==3?cc<=250:slot==4?cc<=350:1;
 if(!timely){pw(r+0x100,0);pw(r+0x108,0);pw(m+0x2a04,0x18);return 0;}}
 pw(m+0x2a04,0x19);pw(r+0x104,m[0x2a20]==1?(0x80000000u|m[0x76f1]):0);return 0;
 special:
 if(rate!=1||(slot!=0&&slot!=3))return 0;
 pw(r+0x100,0x80000000u|m[slot==0?0x76f5:0x76f3]);pw(r+0x400,w(r+0x400)|1);ph(m+0x2650,0x5502);m[0x2652]=0;pw(r+0xed0,0x23002650);tune(m,r);pw(t+0x5c,1);
 if(slot==0?w(t+0x55c)<=99:w(t+0x55c)>250){pw(r+0x100,0);pw(m+0x2a04,0x18);}else pw(m+0x2a04,0x19);return 0;
}
