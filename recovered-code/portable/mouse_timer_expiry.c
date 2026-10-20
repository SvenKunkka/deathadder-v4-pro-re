#include "mouse_timer_expiry.h"
#include "mouse_timer_start.h"
#include "mouse_timer_lifecycle.h"
/* Same original ready/schedule helpers0E0958BC/0E09587C as work submit.
 * Kept local so existing public APIs and their frozen contracts do not change. */
#define BASE 0x23000000u
static uint32_t w(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static uint16_t h(const uint8_t*p){return (uint16_t)(p[0]|(uint16_t)p[1]<<8);}
static void pw(uint8_t*p,uint32_t v){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(v>>(8*i));}
static int valid(uint32_t a,unsigned n){return a>=BASE&&a-BASE<=65536u-n;}
static uint8_t*at(uint8_t*m,uint32_t a){return m+a-BASE;}
static uint32_t lock(rr_mouse_rtos*c){uint32_t old=c->priority;if(!old||old>0x20)c->priority=0x20;return old;}
static int schedule(uint8_t*m,uint8_t*r){
 uint32_t next=w(m+0x7668),cur=w(m+0x7654);if(!next||next==0x23007668u)next=w(m+0x7658);
 if(!valid(next,0x90)||!valid(cur,0x90))return -1;uint8_t*t=at(m,next),*current=at(m,cur);
 if(!(current[0xd]&31u)&&!w(t+0x18)&&h(current+0xe)>=128u)next=cur;
 if(next!=cur){
  t=at(m,next);unsigned cpu=m[0x765c];uint32_t timeout=0x230025e0u+cpu*24u;if(!valid(timeout,0x38))return -1;
  int32_t result;int rc=rr_mouse_timer_abort(m,r,timeout,&result);if(rc)return rc;m[0x7674+cpu]=0;
  if(h(t+0xe)<128u&&w(m+0x767c)&&(int32_t)w(m+0x7678)<=(int8_t)t[0xe]&&!(t[0xd]&31u)&&next!=0x23002378u){
   uint32_t d=w(m+0x767c)-1;uint64_t delay=(d&0x80000000u)?UINT64_C(0xffffffff00000000)|d:d;rc=rr_mouse_timeout_start(m,r,timeout,0x0e0962f5,delay);if(rc)return rc;
  }
 }
 pw(m+0x7664,next);return 0;
}
static int ready(uint8_t*m,uint8_t*r,uint32_t address){
 if(!valid(address,0x90))return -1;uint8_t*t=at(m,address);if((t[0xd]&0x9fu)||w(t+0x18))return 0;t[0xd]|=0x80u;
 uint32_t first=w(m+0x7668),last=w(m+0x766c);if(first==0x23007668u)first=0;
 unsigned count=0;for(uint32_t i=first;i;){if(!valid(i,0x90)||++count>128)return -1;uint8_t*v=at(m,i);
  if((int8_t)t[0xe]<(int8_t)v[0xe]){uint32_t prev=w(v+4);if(!valid(prev,4))return -1;pw(t,i);pw(t+4,prev);pw(at(m,prev),address);pw(v+4,address);return schedule(m,r);}
  if(i==last)break;i=w(v);
 }
 if(!valid(last,4))return -1;pw(t,0x23007668);pw(t+4,last);pw(at(m,last),address);pw(m+0x766c,address);return schedule(m,r);
}

static uint64_t q64(const uint8_t*p){return w(p)|(uint64_t)w(p+4)<<32;}
static uint64_t sx32(uint32_t x){return x&0x80000000u?UINT64_C(0xffffffff00000000)|x:x;}
static int ticks(uint8_t*m,uint8_t*r,uint64_t*out){
 uint64_t elapsed=0;if(!w(m+0x7680)){uint32_t hi=w(r+0x774);if(hi>0x3fffffffu)return -4;uint64_t now=w(r+0x770)|(uint64_t)(hi&0xfffffu)<<32;elapsed=sx32((uint32_t)((now-q64(m+0x21c0))>>5));}
 *out=q64(m+0x25f8)+elapsed;return 0;
}
int rr_mouse_disconnect_timer_callback(uint8_t*m,uint8_t*r,rr_mouse_rtos*c){
 if(!m||!r||!c)return -1;m[0x6b7e]=0;m[0x6b7f]=0;int32_t result;return rr_mouse_work_submit(m,r,0x230067c0u,c,&result);
}
int rr_mouse_timer_expiry(uint8_t*m,uint8_t*r,uint32_t address,rr_mouse_rtos*c){
 if(!m||!r||!c||!valid(address,0x38))return -1;c->entry=0;c->arg0=0;uint32_t old=lock(c);uint8_t*t=at(m,address);
 if(w(t)){c->priority=old;return 0;}
 uint64_t period=q64(t+0x28);
 if(period+1>=2){
  if(!period||(period>>63))period=1;uint64_t current;int rc=ticks(m,r,&current);if(rc)return rc;uint64_t absolute=current+period;
  uint64_t encoded=UINT64_MAX-1;if(absolute&&!(absolute>>63))encoded-=absolute;
  rc=rr_mouse_timeout_start(m,r,address,0x0e096951u,encoded);if(rc)return rc;
 }
 pw(t+0x30,w(t+0x30)+1u);uint32_t callback=w(t+0x20);
 if(callback){
  c->priority=old;if(callback!=0x23025f65u){c->entry=callback&~1u;c->arg0=address;return 1;}
  int rc=rr_mouse_disconnect_timer_callback(m,r,c);if(rc)return rc;old=lock(c);
 }
 uint32_t waiter=w(t+0x18);if(waiter&&waiter!=address+0x18){
  if(!valid(waiter,0x90))return -1;uint8_t*v=at(m,waiter);
  if(w(v+8)){uint32_t next=w(v),prev=w(v+4);if(!valid(next,8)||!valid(prev,4))return -1;pw(at(m,prev),next);pw(at(m,next)+4,prev);pw(v,0);pw(v+4,0);v[0xd]&=0xfdu;pw(v+8,0);}
  pw(v+0x8c,0);c->priority=old;uint32_t nextold=lock(c);int rc=ready(m,r,waiter);if(rc)return rc;c->priority=nextold;return 0;
 }
 c->priority=old;return 0;
}
int rr_mouse_link_work_callback(uint8_t*m,uint8_t*r,uint8_t*a,rr_mouse_rtos*c){
 if(!m||!r||!a||!c)return -1;c->entry=0;c->arg0=0;unsigned connected=h(m+0x6b7e)==1;m[0x76e0]=(uint8_t)connected;m[0x76e1]=0;
 if(connected){
  m[0x771f]=1;if(m[0x7748]&&m[0x7747]){uint32_t old=lock(c);int rc=rr_mouse_timer_stop(m,r,0x23001b48u);if(rc==-4)return rc;c->priority=old;if(rc)return rc;m[0x7747]=0;}
  m[0x7788]=2;m[0x777f]=1;
  if(!m[0x775d]&&!m[0x775c]){m[0x775d]=1;m[0x7743]=0xff;m[0x775c]=1;m[0x7742]=0xff;m[0x7741]=0xff;m[0x769c]=0;m[0x769d]=0;m[0x775e]=0;}
  m[0x772c]=1;if(m[0x7736]){m[0x772d]=1;m[0x7690]=0;m[0x7691]=0;m[0x772c]=0;}
 }else{
  m[0x777f]=0;pw(a+4,1);pw(a+12,1);m[0x771f]=0;
  if(m[0x7748]&&!m[0x7747]){uint32_t old=lock(c);int rc=rr_mouse_timer_start(m,r,0x23001b48u,625,32);if(rc)return rc;c->priority=old;m[0x7747]=1;}
  if(m[0x7723]==1&&!m[0x775e]){for(unsigned i=0;i<8;i++){const unsigned offs[]={0x7742,0x7743,0x775d,0x7741,0x775c,0x775a,0x7759,0x775b};m[offs[i]]=0;}m[0x76c4]=0;m[0x76c5]=0;m[0x769e]=0;m[0x769f]=0;m[0x775e]=1;}
 }
 return 0;
}

int rr_mouse_work_semaphore_give(uint8_t*m,uint8_t*r,uint32_t address,rr_mouse_rtos*c){
 if(!m||!r||!c||!valid(address,16))return -1;uint32_t old=lock(c);uint8_t*q=at(m,address);uint32_t waiter=w(q);
 if(!waiter||waiter==address){uint32_t count=w(q+8);if(count!=w(q+12))count++;pw(q+8,count);c->priority=old;return 0;}
 if(!valid(waiter,0x90))return -1;uint8_t*t=at(m,waiter);uint32_t next=w(t),prev=w(t+4);if(!valid(next,8)||!valid(prev,4))return -1;
 pw(at(m,prev),next);pw(at(m,next)+4,prev);pw(t,0);pw(t+4,0);t[0xd]&=0xfdu;pw(t+8,0);int32_t result;int rc=rr_mouse_timer_abort(m,r,waiter+0x18,&result);if(rc)return rc;pw(t+0x8c,0);rc=ready(m,r,waiter);if(rc)return rc;
 if(!old&&!(c->exception_number&0x1ffu)&&w(m+0x7664)!=w(m+0x7654)){c->entry=0x0e089d4cu;c->arg0=0;return 1;}c->priority=old;return 0;
}
