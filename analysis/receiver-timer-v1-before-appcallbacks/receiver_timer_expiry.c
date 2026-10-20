#include "receiver_timer_expiry.h"
#include "receiver_notification_runtime.h"
/* Same original ready/schedule helpers0E06DA0C/0E06D9CC as work submit.
 * Kept local so existing public APIs and their frozen contracts do not change. */
#define BASE 0x23000000u
static uint32_t w(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static uint16_t h(const uint8_t*p){return (uint16_t)(p[0]|(uint16_t)p[1]<<8);}
static void pw(uint8_t*p,uint32_t v){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(v>>(8*i));}
static int valid(uint32_t a,unsigned n){return a>=BASE&&a-BASE<=131072u-n;}
static uint8_t*at(uint8_t*m,uint32_t a){return m+a-BASE;}
static uint32_t lock(rr_receiver_rtos*c){uint32_t old=c->priority;if(!old||old>0x40)c->priority=0x40;return old;}
static int schedule(uint8_t*m,uint8_t*r){
 uint32_t next=w(m+0x7180),cur=w(m+0x7170);if(!next||next==0x23007180u)next=w(m+0x7174);
 if(!valid(next,0x90)||!valid(cur,0x90))return -1;uint8_t*t=at(m,next),*current=at(m,cur);
 if(!(current[0xd]&31u)&&!w(t+0x18)&&h(current+0xe)>=128u)next=cur;
 if(next!=cur){
  t=at(m,next);unsigned cpu=m[0x7178];uint32_t timeout=0x23002c60u+cpu*24u;if(!valid(timeout,0x38))return -1;
  int32_t result;int rc=rr_receiver_timeout_abort(m,r,timeout,&result);if(rc)return rc;m[0x718c+cpu]=0;
  if(h(t+0xe)<128u&&w(m+0x7194)&&(int32_t)w(m+0x7190)<=(int8_t)t[0xe]&&!(t[0xd]&31u)&&next!=0x230029f8u){
   uint32_t d=w(m+0x7194)-1;uint64_t delay=(d&0x80000000u)?UINT64_C(0xffffffff00000000)|d:d;rc=rr_receiver_timeout_start(m,r,timeout,0x0e06e4c9,delay);if(rc)return rc;
  }
 }
 pw(m+0x717c,next);return 0;
}
static int ready(uint8_t*m,uint8_t*r,uint32_t address){
 if(!valid(address,0x90))return -1;uint8_t*t=at(m,address);if((t[0xd]&0x9fu)||w(t+0x18))return 0;t[0xd]|=0x80u;
 uint32_t first=w(m+0x7180),last=w(m+0x7184);if(first==0x23007180u)first=0;
 unsigned count=0;for(uint32_t i=first;i;){if(!valid(i,0x90)||++count>128)return -1;uint8_t*v=at(m,i);
  if((int8_t)t[0xe]<(int8_t)v[0xe]){uint32_t prev=w(v+4);if(!valid(prev,4))return -1;pw(t,i);pw(t+4,prev);pw(at(m,prev),address);pw(v+4,address);return schedule(m,r);}
  if(i==last)break;i=w(v);
 }
 if(!valid(last,4))return -1;pw(t,0x23007180);pw(t+4,last);pw(at(m,last),address);pw(m+0x7184,address);return schedule(m,r);
}

static uint64_t q64(const uint8_t*p){return w(p)|(uint64_t)w(p+4)<<32;}
static uint64_t sx32(uint32_t x){return x&0x80000000u?UINT64_C(0xffffffff00000000)|x:x;}
static int ticks(uint8_t*m,uint8_t*r,uint64_t*out){
 uint64_t elapsed=0;if(!w(m+0x7198)){uint32_t hi=w(r+0x774);if(hi>0x3fffffffu)return -4;uint64_t now=w(r+0x770)|(uint64_t)(hi&0xfffffu)<<32;elapsed=sx32((uint32_t)(now-q64(m+0x2840)));}
 *out=q64(m+0x2c78)+elapsed;return 0;
}
int rr_receiver_timer_expiry(uint8_t*m,uint8_t*r,const uint8_t*f,uint32_t address,rr_receiver_rtos*c){
 if(!m||!r||!f||!c||!valid(address,0x38))return -1;c->entry=0;c->arg0=0;uint32_t old=lock(c);uint8_t*t=at(m,address);
 if(w(t)){c->priority=old;return 0;}
 uint64_t period=q64(t+0x28);
 if(period+1>=2){
  if(!period||(period>>63))period=1;uint64_t current;int rc=ticks(m,r,&current);if(rc)return rc;uint64_t absolute=current+period;
  uint64_t encoded=UINT64_MAX-1;if(absolute&&!(absolute>>63)){/* Original reads ticks again atEBBC. */rc=ticks(m,r,&current);if(rc)return rc;encoded-=current+period;}
  rc=rr_receiver_timeout_start(m,r,address,0x0e06eb01u,encoded);if(rc)return rc;
 }
 pw(t+0x30,w(t+0x30)+1u);uint32_t callback=w(t+0x20);
 if(callback){
  c->priority=old;if(callback!=0x230255b9u){c->entry=callback&~1u;c->arg0=address;return 1;}
  int rc=rr_receiver_disconnect_expiry(m,f);if(rc)return rc;old=lock(c);
 }
 uint32_t waiter=w(t+0x18);if(waiter&&waiter!=address+0x18){
  if(!valid(waiter,0x90))return -1;uint8_t*v=at(m,waiter);
  if(w(v+8)){uint32_t next=w(v),prev=w(v+4);if(!valid(next,8)||!valid(prev,4))return -1;pw(at(m,prev),next);pw(at(m,next)+4,prev);pw(v,0);pw(v+4,0);v[0xd]&=0xfdu;pw(v+8,0);}
  pw(v+0x8c,0);c->priority=old;uint32_t nextold=lock(c);int rc=ready(m,r,waiter);if(rc)return rc;c->priority=nextold;return 0;
 }
 c->priority=old;return 0;
}

static int timer_handler(rr_receiver_rtc_hw*x,uint32_t address,uint32_t cb,rr_receiver_rtos*c,void*context){
 if(cb==0x0e06eb01u)return rr_receiver_timer_expiry(x->ram,x->rtc,(const uint8_t*)context,address,c);
 c->entry=cb&~1u;c->arg0=address;return 1;
}
int rr_receiver_rtc_dispatch_timers(rr_receiver_rtc_hw*x,const uint8_t*f,rr_receiver_rtos*c,rr_receiver_rtc_pending*p){if(!f)return -1;return rr_receiver_rtc_dispatch_with_handler(x,c,p,timer_handler,(void*)f);}
int rr_receiver_clock_announce_timers(rr_receiver_rtc_hw*x,const uint8_t*f,uint64_t d,rr_receiver_rtos*c,rr_receiver_rtc_pending*p){if(!f)return -1;return rr_receiver_clock_announce_with_handler(x,d,c,p,timer_handler,(void*)f);}
int rr_receiver_timeout_announce_timers(rr_receiver_rtc_hw*x,const uint8_t*f,uint32_t ticks,rr_receiver_rtos*c,rr_receiver_rtc_pending*p){if(!f)return -1;return rr_receiver_timeout_announce_with_handler(x,ticks,c,p,timer_handler,(void*)f);}
