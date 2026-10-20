#include "mouse_deferred_work.h"
#include "mouse_timer_start.h"
#include "mouse_timer_lifecycle.h"
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



int rr_mouse_delayed_work_schedule(uint8_t*m,uint8_t*r,uint32_t queue,uint32_t work,uint64_t delay,int reschedule,rr_mouse_rtos*c,int32_t*result){
 if(!m||!r||!c||!result||!valid(work,44))return -1;c->entry=0;c->arg0=0;uint32_t old=lock(c);uint8_t*t=at(m,work);uint32_t flags=w(t+12);int rc;
 if(reschedule){pw(t+12,flags&~8u);if(flags&8u){int32_t ignored;rc=rr_mouse_timer_abort(m,r,work+16,&ignored);if(rc)return rc;}}
 else if(flags&0x1eu){*result=0;c->priority=old;return 0;}
 if(!delay){rc=rr_mouse_work_submit_to_queue(m,r,work,&queue,c,result);if(rc)return rc;}
 else{pw(t+12,w(t+12)|8u);pw(t+40,queue);rc=rr_mouse_timeout_start(m,r,work+16,0x0e095255u,delay);if(rc)return rc;*result=1;}
 c->priority=old;return 0;
}
int rr_mouse_timer_expiry_deferred(rr_mouse_scan_hw*x,uint32_t address,rr_mouse_rtos*c){
 if(!x||!c)return -1;int rc=rr_mouse_timer_expiry_scanning(x,address,c);if(rc!=1||c->entry!=0x23025f78u)return rc;
 c->entry=0;c->arg0=0;uint8_t*m=x->ram,*t=at(m,address);uint32_t old=lock(c);rc=rr_mouse_disconnect(m,x->radio,x->timer,x->rtc,x->clock,m[0x6b7b]);if(rc==-4)return rc;c->priority=old;if(rc)return rc;
 old=lock(c);uint32_t waiter=w(t+0x18);if(waiter&&waiter!=address+0x18){if(!valid(waiter,0x90))return -1;uint8_t*v=at(m,waiter);if(w(v+8)){uint32_t next=w(v),prev=w(v+4);if(!valid(next,8)||!valid(prev,4))return -1;pw(at(m,prev),next);pw(at(m,next)+4,prev);pw(v,0);pw(v+4,0);v[0xd]&=0xfdu;pw(v+8,0);}pw(v+0x8c,0);c->priority=old;uint32_t oldready=lock(c);rc=ready(m,x->rtc,waiter);if(rc)return rc;c->priority=oldready;return 0;}c->priority=old;return 0;
}
static int extra_timeout(rr_mouse_scan_hw*x,uint32_t address,uint32_t callback,rr_mouse_rtos*c){
 if(callback==0x0e095255u)return rr_mouse_delayed_work_expiry(x->ram,x->rtc,address,c);c->entry=callback&~1u;c->arg0=address;return 1;
}
static const rr_mouse_rtc_hooks deferred_hooks={rr_mouse_timer_expiry_deferred,extra_timeout};
int rr_mouse_timeout_announce_deferred(rr_mouse_scan_hw*x,uint32_t ticks,rr_mouse_rtos*c,rr_mouse_rtc_pending*p){return rr_mouse_timeout_announce_with_hooks(x,ticks,c,p,&deferred_hooks);}
int rr_mouse_clock_announce_deferred(rr_mouse_scan_hw*x,uint64_t deadline,rr_mouse_rtos*c,rr_mouse_rtc_pending*p){return rr_mouse_clock_announce_with_hooks(x,deadline,c,p,&deferred_hooks);}
int rr_mouse_rtc_dispatch_deferred(rr_mouse_scan_hw*x,rr_mouse_rtos*c,rr_mouse_rtc_pending*p){return rr_mouse_rtc_dispatch_with_hooks(x,c,p,&deferred_hooks);}
