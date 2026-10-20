#include "mouse_timer_lifecycle.h"
#include "mouse_radio_irq.h"
#include <string.h>
static uint32_t g32(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static uint64_t g64(const uint8_t*p){return g32(p)|(uint64_t)g32(p+4)<<32;}
static void s16(uint8_t*p,uint16_t v){p[0]=(uint8_t)v;p[1]=(uint8_t)(v>>8);}
static void s32(uint8_t*p,uint32_t v){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(v>>(i*8));}
static void s64(uint8_t*p,uint64_t v){s32(p,(uint32_t)v);s32(p+4,(uint32_t)(v>>32));}
static int valid(uint32_t a,unsigned size){return a>=0x23000000u&&a-0x23000000u<=65536u-size;}
static int now(const uint8_t*rtc,uint64_t*out){uint32_t hi=g32(rtc+0x774);if(hi>0x3fffffffu)return -4;*out=g32(rtc+0x770)|(uint64_t)(hi&0xfffffu)<<32;return 0;}
static void compare_write(uint8_t*m,uint8_t*rtc,uint64_t deadline){
 unsigned ch=m[0x1304];uint32_t mask=ch<32?1u<<ch:0;
 if(!(mask&0xe080u)||!(~g32(m+0x1458)&0xe080u&mask))return;
 unsigned slot=ch==7?0:ch-12;
 s32(rtc+0x52c+ch*16,0);memcpy(m+0x1460+slot*12,m+0x12fc,8);m[0x1468+slot*12]=(uint8_t)ch;s32(m+0x145c,g32(m+0x145c)|mask);
 s32(rtc+0x100+ch*4,0);s32(rtc+0x520+ch*16,(uint32_t)deadline);s32(rtc+0x524+ch*16,(uint32_t)(deadline>>32)&0xfffffu);s32(rtc+0x354,mask);
}
int rr_mouse_timer_abort(uint8_t*m,uint8_t*rtc,uint32_t address,int32_t*result){
 if(!m||!rtc||!result||!valid(address,0x38))return -1;
 unsigned t=address-0x23000000u;uint32_t next=g32(m+t),prev=g32(m+t+4),oldhead=g32(m+0x14f4);
 if(!next){*result=-22;return 0;}
 if(!valid(next,24)||!valid(prev,8))return -1;
 unsigned n=next-0x23000000u,b=prev-0x23000000u;
 if(g32(m+0x14f8)!=address)s64(m+n+16,g64(m+n+16)+g64(m+t+16));
 s32(m+b,next);s32(m+n+4,prev);s32(m+t,0);s32(m+t+4,0);
 if(oldhead!=0x230014f4u&&oldhead==address){
  uint32_t first=g32(m+0x14f4),elapsed=0,wait=0x7fffffffu;uint64_t ticks;
  if(!g32(m+0x7680)){int rc=now(rtc,&ticks);if(rc)return rc;elapsed=(uint32_t)((ticks-g64(m+0x21c0))>>5);}
  if(first!=0x230014f4u&&first){
   if(!valid(first,24))return -1;
   uint64_t delta=g64(m+(first-0x23000000u)+16)-(uint64_t)(int64_t)(int32_t)elapsed;
   if(delta>>63)wait=0;else if(delta<0x80000000u)wait=(uint32_t)delta;
  }
  int rc=now(rtc,&ticks);if(rc)return rc;
  uint64_t base=g64(m+0x21c0),due=(ticks-base)+((uint64_t)wait<<5);
  due=due<64?32:(due&~(uint64_t)31);compare_write(m,rtc,base+due);
 }
 *result=0;return 0;
}
int rr_mouse_timer_stop(uint8_t*m,uint8_t*rtc,uint32_t address){
 int32_t result;int rc=rr_mouse_timer_abort(m,rtc,address,&result);if(rc||result)return rc;
 unsigned t=address-0x23000000u;
 if(g32(m+t+0x24))return -2;
 uint32_t waiter=g32(m+t+0x18);if(waiter&&waiter!=address+0x18)return -3;
 return 0;
}
int rr_mouse_disconnect(uint8_t*m,uint8_t*r,uint8_t*t,uint8_t*rtc,uint32_t*c,uint32_t reason){
 if(!m||!r||!t||!rtc||!c)return -1;
 s16(m+0x27ba,0);s16(m+0x2796,(uint16_t)reason);
 if(m[0x76ee]){c[1]=1;m[0x76ee]=0;}s32(t+0x8c,0);
 int rc=rr_mouse_timer_stop(m,rtc,0x23001540u);if(rc)return rc;
 rc=rr_mouse_timer_stop(m,rtc,0x23001540u);if(rc)return rc;
 for(unsigned mode=0;mode<3;mode++){
  s32(m+0x2a04,0);s32(r+0x200,0);s32(r+0x218,0);s32(r+0x220,0);s32(r+0x10,1);
  if(mode==2){s32(r+0x100,0);s32(r+0x108,0);s32(t+0x558,0);}
  s32(r+0x104,0);s32(r+0x110,0);s32(t+0xdc,0);s32(t+4,1);s32(m+0x2978,0);s16(m+0x2794,0);
 }
 s32(t+0x558,0);s32(t+4,1);s32(t+0xc,1);
 return rr_mouse_timer_stop(m,rtc,0x23001540u);
}
int rr_mouse_disconnect_ack(uint8_t*m,uint8_t*r,uint8_t*t,uint8_t*rtc,uint32_t*c){
 int rc=rr_mouse_timer_stop(m,rtc,0x230015b0u);if(rc)return rc;return rr_mouse_disconnect(m,r,t,rtc,c,m[0x6b7b]);
}
int rr_mouse_ack_callback(uint8_t*m,uint8_t*r,uint8_t*t,uint8_t*rtc,uint32_t*c,uint16_t cls){
 if(!m)return -1;if(cls!=3||!g32(m+0x6b68))return 0;
 if(g32(m+0x6b68)!=0x23025c2du)return -2;
 int rc=rr_mouse_disconnect_ack(m,r,t,rtc,c);if(!rc)s32(m+0x6b68,0);return rc;
}

struct lifecycle_context {uint8_t *m,*r,*t,*rtc;uint32_t *clock;};
static int lifecycle_ack(void*context,uint16_t cls){struct lifecycle_context*c=context;return rr_mouse_ack_callback(c->m,c->r,c->t,c->rtc,c->clock,cls);}
int rr_mouse_radio_irq_lifecycle(uint8_t*m,uint8_t*r,uint8_t*t,uint8_t*rtc,uint32_t*c,uint32_t*nvic,unsigned mode){
 if(!rtc||!c)return -1;struct lifecycle_context context={m,r,t,rtc,c};return rr_mouse_radio_irq_with_ack(m,r,t,nvic,mode,lifecycle_ack,&context);
}
