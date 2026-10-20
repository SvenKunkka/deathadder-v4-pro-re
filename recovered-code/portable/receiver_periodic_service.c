#include "receiver_periodic_service.h"
#include <string.h>
static uint32_t w(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void pw(uint8_t*p,uint32_t v){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(v>>(8*i));}
static uint64_t q(const uint8_t*p){return w(p)|(uint64_t)w(p+4)<<32;}
static uint32_t mask(uint32_t ch){ch&=255u;return ch<32?1u<<ch:0;}
static uint64_t sx(uint32_t v){return v&0x80000000u?UINT64_C(0xffffffff00000000)|v:v;}
uint32_t rr_receiver_clock_allocate(uint8_t*m){
 if(!m)return UINT32_MAX-11u;if(m[0x71eb]>=3)return UINT32_MAX-11u;uint32_t available=w(m+0xab4);if(!available)return UINT32_MAX-11u;
 unsigned ch=31;while(!(available&(1u<<ch)))ch--;pw(m+0xab4,available&~(1u<<ch));m[0x71eb]++;return ch;
}
int rr_receiver_clock_deadline(uint8_t*m,uint8_t*r,uint64_t duration,uint64_t*out){
 if(!m||!r||!out)return -1;uint32_t high=w(r+0x774);if(high>0x3fffffffu)return -4;uint64_t now=w(r+0x770)|(uint64_t)(high&0xfffffu)<<32;
 uint64_t uptime=q(m+0x2c78);if(!w(m+0x7198))uptime+=sx((uint32_t)(now-q(m+0x2840)));
 uint64_t inverted=UINT64_MAX-1u-duration;
 if(!(inverted>>63)){uint64_t delta=inverted-uptime;uint32_t dh=(uint32_t)(delta>>32);if(!(dh&0x80000000u)&&dh>=0x100000u){*out=UINT64_MAX-21u;return 0;}*out=now+delta;}
 else{uint32_t dh=(uint32_t)(duration>>32);if(!(dh&0x80000000u)&&dh>=0x100000u){*out=UINT64_MAX-21u;return 0;}*out=now+duration;}return 0;
}
uint32_t rr_receiver_clock_alarm(uint8_t*m,uint8_t*r,uint32_t channel,uint64_t deadline,uint32_t cb,uint32_t data){
 uint32_t bit=mask(channel),old=w(m+0x6db0);pw(m+0x6db0,old&~bit);unsigned ch=channel&255u;
 uint32_t available=(~w(m+0xab4))&0xe080u;
 if((available&bit)&&(w(m+0xab8)&bit))pw(r+0x358,bit);
 uint32_t result=UINT32_MAX;
 if((bit&0xe080u)&&(available&bit)){
  unsigned slot=ch==7?0:ch-12;pw(r+0x52c+ch*16,0);pw(m+0xabc+slot*12,cb);pw(m+0xac0+slot*12,data);m[0xac4+slot*12]=(uint8_t)ch;pw(m+0xab8,w(m+0xab8)|bit);
  pw(r+0x100+ch*4,0);pw(r+0x520+ch*16,(uint32_t)deadline);pw(r+0x524+ch*16,(uint32_t)(deadline>>32)&0xfffffu);pw(r+0x354,bit);result=0;
 }
 if(old&bit){pw(m+0x6db0,w(m+0x6db0)|bit);if(available&bit){pw(m+0xab8,w(m+0xab8)|bit);pw(r+0x354,bit);}}
 return result;
}
int rr_receiver_periodic_init(uint8_t*m,uint8_t*s,uint32_t*out){if(!m||!s||!out)return -1;uint32_t ch=rr_receiver_clock_allocate(m);pw(m+0x2df8,ch);pw(s+0x504,0x10000);pw(s+0x508,1);pw(s+0x50c,0);pw(s,1);*out=ch;return 0;}
int rr_receiver_periodic_refresh(uint8_t*m,uint8_t*r,uint8_t*s,uint32_t*out){if(!m||!r||!s||!out)return -1;pw(s+0x600,0x6e524635);uint64_t d;int rc=rr_receiver_clock_deadline(m,r,100000,&d);if(rc)return rc;*out=rr_receiver_clock_alarm(m,r,w(m+0x2df8),d,0x0e05bde1u,0);return 0;}
typedef struct {rr_receiver_init_hw*x;const uint8_t*f,*tail;} known_context;
static int known_user(uint32_t address,uint32_t cb,rr_receiver_rtos*c,void*user){
 known_context*k=user;uint32_t e=cb&~1u;
 if(e==0x230255d0u||e==0x230255f8u||e==0x23025640u||e==0x230256e8u)return rr_receiver_application_timer(k->x,k->f,e,k->tail,c);
 c->entry=e;c->arg0=address;return 1;
}
static int known_timeout(rr_receiver_rtc_hw*x,uint32_t address,uint32_t cb,rr_receiver_rtos*c,void*user){
 known_context*k=user;if(cb==0xe06eb01u)return rr_receiver_timer_expiry_with_handler(x->ram,x->rtc,k->f,address,c,known_user,user);
 c->entry=cb&~1u;c->arg0=address;return 1;
}
static int dispatch(uint8_t*m,uint8_t*r,uint8_t*s,const uint8_t*f,rr_receiver_rtos*c,rr_receiver_rtc_pending*p,known_context*k){
 if(!m||!r||!s||!f||!c||!p)return -1;memset(p,0,sizeof(*p));c->entry=0;c->arg0=0;
 uint32_t enabled=~w(m+0xab4)&0xe080u&w(m+0xab8),fired=0;
 for(unsigned ch=0;ch<32;ch++)if((enabled&(1u<<ch))&&w(r+0x100+ch*4)){pw(r+0x100+ch*4,0);fired|=1u<<ch;}fired&=w(r+0x350);
 for(unsigned i=0;i<4;i++){uint8_t*t=m+0xabc+12*i;unsigned ch=t[8];uint32_t bit=ch<32?1u<<ch:0;if(!(fired&bit))continue;uint32_t cb=w(t);if(!cb)continue;uint32_t lo=w(r+0x520+ch*16),hi=w(r+0x524+ch*16);
  int rc;if(cb==0xe05bde1u){uint32_t result;rc=rr_receiver_periodic_refresh(m,r,s,&result);}
  else if(cb==0xe0683a1u){rr_receiver_rtc_hw x={m,r};rc=k?rr_receiver_clock_announce_with_handler(&x,lo|(uint64_t)hi<<32,c,p,known_timeout,k):rr_receiver_clock_announce_timers(&x,f,lo|(uint64_t)hi<<32,c,p);}
  else{c->entry=p->entry=cb&~1u;c->arg0=p->args[0]=ch;p->args[1]=cb;p->args[2]=lo;p->args[3]=hi;p->args[4]=w(t+4);return 1;}
  if(rc)return rc;
 }return 0;
}

int rr_receiver_periodic_dispatch(uint8_t*m,uint8_t*r,uint8_t*s,const uint8_t*f,rr_receiver_rtos*c,rr_receiver_rtc_pending*p){return dispatch(m,r,s,f,c,p,0);}
int rr_receiver_rtc_known_callbacks(rr_receiver_init_hw*x,uint8_t*s,const uint8_t*f,const uint8_t tail[32],rr_receiver_rtos*c,rr_receiver_rtc_pending*p){if(!x||!tail)return -1;known_context k={x,f,tail};return dispatch(x->ram,x->rtc,s,f,c,p,&k);}
