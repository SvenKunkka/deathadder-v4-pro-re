#include "mouse_business_consumer.h"
#include "business_tx.h"
#include <string.h>
static uint16_t g16(const uint8_t*p){return (uint16_t)(p[0]|((uint16_t)p[1]<<8));}
static uint32_t g32(const uint8_t*p){return p[0]|((uint32_t)p[1]<<8)|((uint32_t)p[2]<<16)|((uint32_t)p[3]<<24);}
static void s16(uint8_t*p,uint16_t v){p[0]=(uint8_t)v;p[1]=(uint8_t)(v>>8);}
static void s32(uint8_t*p,uint32_t v){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(v>>(8*i));}
static void finish(uint8_t*m){if(m[0x1508]!=m[0x7796]){m[0x1508]=m[0x7796];if(m[0x7796])m[0x7795]=0;else{s32(m+0x679c,15000);m[0x7795]=1;}}}
static void rate_update(uint8_t*m,uint8_t*dppi,uint8_t rate){
 if((uint32_t)rate-1u>=64u)return;
 if(g16(m+0x2794)<3u || g16(m+0x29ac)==0u){
  s16(m+0x29ac,rate);
  if(rate==1u){if(m[0x76ee]==0u){m[0x76ee]=1;s32(dppi+0x40,1);}}
  else if(m[0x76ee]!=0u){s32(dppi+0x44,1);m[0x76ee]=0;}
 }else{
  uint16_t when=(uint16_t)(g16(m+0x2a0a)+100u);uint8_t body[4]={0x2f,rate,(uint8_t)(when>>8),(uint8_t)when};
  (void)rr_bt_enqueue(m,1,0,0,body,4,0xff);s16(m+0x29ae,rate);s16(m+0x29b0,when);
 }
}
static void timing_config(uint8_t*m){
 if(m[0x7723]==4u){
  if(m[0x779e]){m[0x7783]=m[0x4a5d];m[0x7782]=0x50;m[0x7784]=4;m[0x7780]=8;}
  else{m[0x7783]=m[0x4a5c];m[0x7784]=1;m[0x7782]=10;m[0x7780]=1;}
 }else if(m[0x7723]==1u){
  uint8_t rate=m[0x4a5f];m[0x7783]=1;m[0x7784]=1;
  if(rate==1u){m[0x7780]=8;m[0x7782]=0x50;m[0x7784]=4;}
  else if(rate==2u){m[0x7784]=2;m[0x7782]=0x28;m[0x7780]=4;}
  else{m[0x7780]=2;m[0x7782]=0x14;if(rate!=4u)m[0x7783]=(uint8_t)(rate>>2);}
 }
}
int rr_mouse_business_consumer(uint8_t*m,uint8_t*spim,uint8_t*dppi){
 uint8_t cls=m[0x779b],n=m[0x779c],*p=m+0x67d0;
 if(cls==3u && p[0]==0xacu){
  m[0x29e0]=p[2];
  if(g16(p+1)!=0u){uint32_t counts=g32(m+0x6b88);uint8_t response[2]={0xac,0};
   if((counts>>16)!=0u)response[1]=(uint8_t)((counts&0xffffu)/(counts>>16));
   s32(m+0x6b88,0);(void)rr_bt_mouse_tx(m,0,3,response,2,0,0);s32(m+0x6b68,0);}
  return 0;
 }
 uint8_t sum=0;for(unsigned i=0;i<n;i++)sum=(uint8_t)(sum+p[i]);if(sum)return 0;
 if(cls==5u && p[0]==0x5au){
  if(n<3u)return -5;
  memset(m+0x3efc,0,90);memcpy(m+0x3efc,p+2,(unsigned)n-3u);m[0x3f54]=p[1];m[0x7715]=1;m[0x7797]=1;finish(m);return 0;
 }
 if(cls!=3u){finish(m);return 0;}
 if(p[0]==0xa3u){
  if(m[0x7748]!=0u && m[0x7747]==0u)return -2;
  unsigned clear[]={0x775e,0x7758,0x7755,0x772f,0x775d,0x775c,0x7761,0x7763};
  for(unsigned i=0;i<sizeof(clear)/sizeof(clear[0]);i++)m[clear[i]]=0;
  s16(m+0x76e0,0);m[0x777f]=0;s32(spim+4,1);s32(spim+12,1);m[0x7796]=0;m[0x771f]=0;
  if(m[0x7723]==1u){
   unsigned c[]={0x7742,0x7743,0x775d,0x7741,0x775c,0x775a,0x7759,0x775b};
   for(unsigned i=0;i<sizeof(c)/sizeof(c[0]);i++)m[c[i]]=0;
   s16(m+0x76c4,0);s16(m+0x769e,0);m[0x775e]=1;
  }
  finish(m);return 0;
 }
 if(p[0]!=0xb1u){finish(m);return 0;}
 if(g16(m+0x76e0)==0u)return -4;
 /* Preflight only if the pending rate change would enter active hardware. */
 uint8_t rate=m[0x4a5f],target=m[0x7781],change=m[0x7776];
 if(p[1]==1u){if(rate<8u){target=8;change=1;}}
 else if(m[0x7775]!=0u){target=m[0x7774];change=1;}
 if(p[4]==0u){if(rate<8u){target=8;change=1;}}
 else if(m[0x7773]!=0u){target=m[0x7772];change=1;}
 if(change!=0u && m[0x771f]!=0u && rate!=target && (m[0x774b]!=0u || m[0x774c]!=0u))return -3;
 m[0x7724]=p[1];
 if(p[1]==1u){if(rate<8u){m[0x7774]=rate;m[0x7775]=1;m[0x7781]=8;m[0x7776]=1;}}
 else if(m[0x7775]!=0u){m[0x7781]=m[0x7774];m[0x7775]=0;m[0x7776]=1;}
 m[0x7771]=p[4];
 if(p[4]==0u){if(rate<8u){m[0x7772]=rate;m[0x7781]=8;m[0x7773]=1;m[0x7776]=1;}}
 else if(m[0x7773]!=0u){m[0x7781]=m[0x7772];m[0x7776]=1;m[0x7773]=0;}
 m[0x7796]=p[5];
 uint8_t reply[8]={0xb1,0,0xbf,0,m[0x4955],rate,m[0x4a62],m[0x7733]};
 (void)rr_bt_mouse_tx(m,0,3,reply,8,0,0);rate_update(m,dppi,rate);
 if(m[0x7776]!=0u && m[0x771f]!=0u){
  if(m[0x4a5f]!=m[0x7781]){
   s32(spim+4,1);s32(spim+12,1);m[0x4a5f]=m[0x7781];timing_config(m);
   m[0x7786]=0;s16(m+0x76de,0);m[0x7787]=0;m[0x7785]=0;m[0x7792]=0;s16(m+0x76dc,0);
  }
  m[0x7776]=0;
 }
 if(m[0x7796]!=0u){if(m[0x773f]==1u)m[0x773f]=0;finish(m);return 0;}
 if(m[0x773f]==1u){s16(m+0x76d6,1);s16(m+0x76d2,(uint16_t)(g16(m+0x76d2)|1u));}
 finish(m);return 0;
}
