#include "mouse_adaptive_control.h"
#include "business_tx.h"
#include <string.h>
static uint16_t r16(const uint8_t*p){return (uint16_t)(p[0]|(uint16_t)p[1]<<8);}
static void w16(uint8_t*p,uint16_t v){p[0]=(uint8_t)v;p[1]=(uint8_t)(v>>8);}
static void w32(uint8_t*p,uint32_t v){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(v>>(i*8));}
void rr_mouse_adaptive_request(uint8_t*m,uint32_t phase,uint32_t channel,uint32_t reason,uint32_t*nvic){
 m[0x76f6]=(uint8_t)channel;m[0x76f7]=(uint8_t)phase;m[0x1504]=(uint8_t)reason;*nvic=0x08000000;
}
static void report(uint8_t*m,unsigned peer,unsigned channel,unsigned flag,uint16_t total,uint16_t count){
 uint8_t data[6]={0x2b,(uint8_t)((channel&63)|flag),(uint8_t)(total>>8),(uint8_t)total,(uint8_t)(count>>8),(uint8_t)count};
 (void)rr_bt_enqueue(m,1,peer,0,data,6,255);
 m[0x294d+channel]=1;w32(m+0x2932,0);
 memset(m+0x2854,0,0x4a);memset(m+0x289e,0,0x4a);memset(m+0x28e8,0,0x4a);
}
int rr_mouse_adaptive_run(uint8_t*m,unsigned peer,uint32_t phase,uint32_t channel){
 if(!m||peer>1||channel>255)return -1;
 unsigned b=0x2978+peer*0xee0;
 if(phase==0){
  if(!m[b+0x84]&&!m[b+0x85]&&m[b+0x81]&&r16(m+b+0x82)<5){w16(m+b+0x82,5);w32(m+b+0x88,24);}
  uint16_t delay=r16(m+0x2934);
  if(delay){delay=(uint16_t)(delay-1);w16(m+0x2934,delay);if(delay)return 0;}
  if(m[0x294d+channel]==1||r16(m+0x2936)==0)return 0;
  uint16_t total=r16(m+0x2854+channel*2);w16(m+0x2936,0);
  if(total>31){uint16_t count=r16(m+0x289e + channel*2);if(count>(total>>3))report(m,peer,channel,0,total,count);}
  uint16_t bad=r16(m+0x28e8+channel*2);
  if(bad>4)report(m,peer,channel,64,r16(m+0x2854+channel*2),bad);
 }else if(phase==1){
  unsigned value=m[b+0x6d];
  if(value!=255){
   if(!m[b+0x6a]){
    m[b+0x6a]=(uint8_t)value;
    if(!m[b+0x6b]){m[b+0x6b]=(uint8_t)value;if(value<m[b+0x6a])m[b+0x6a]=(uint8_t)value;}
    else if(m[b+0x6b]<value)m[b+0x6b]=(uint8_t)value;
   }else if(!m[b+0x6b]){m[b+0x6b]=(uint8_t)value;if(value<m[b+0x6a])m[b+0x6a]=(uint8_t)value;}
   else if(value<m[b+0x6a])m[b+0x6a]=(uint8_t)value;
   else if(m[b+0x6b]<value)m[b+0x6b]=(uint8_t)value;
   w16(m+b+0x72,(uint16_t)(r16(m+b+0x72)+1));w16(m+b+0x70,(uint16_t)(r16(m+b+0x70)+value));
  }
  if(m[b+0x84]||m[b+0x85])return 0;
  if(m[b+0x81]){
   uint16_t countdown=r16(m+b+0x82);if(!countdown)return 0;
   countdown=(uint16_t)(countdown-1);w16(m+b+0x82,countdown);
   unsigned average=m[b+0x69];
   if(average>=1&&average<=70){if(countdown<=1){w32(m+b+0x88,11);return 0;}if(countdown<=3){w32(m+b+0x88,14);return 0;}}
   else if(average==0&&countdown==0){w32(m+b+0x88,11);return 0;}
  }
  w32(m+b+0x88,24);
 }else if(phase==2){
  uint16_t count=r16(m+b+0x72);
  if(count<=15){m[b+0x69]=0;return 0;}
  uint16_t sum=(uint16_t)(r16(m+b+0x70)-(m[b+0x6a]+m[b+0x6b]));count=(uint16_t)(count-2);
  w16(m+b+0x70,sum);w16(m+b+0x72,count);m[b+0x69]=(uint8_t)(sum/count);
 }
 return 0;
}
int rr_mouse_adaptive_irq(uint8_t*m){if(!m)return -1;return rr_mouse_adaptive_run(m,0,m[0x76f7],m[0x76f6]);}
