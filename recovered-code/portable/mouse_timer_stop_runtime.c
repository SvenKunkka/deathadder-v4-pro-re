#include "mouse_timer_stop_runtime.h"
#include "mouse_timer_start.h"
#include "mouse_timer_lifecycle.h"
#define BASE 0x23000000u
static uint32_t w(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static uint16_t h(const uint8_t*p){return (uint16_t)(p[0]|(uint16_t)p[1]<<8);}
static void pw(uint8_t*p,uint32_t v){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(v>>(8*i));}
static int valid(uint32_t a,unsigned n){return a>=BASE&&a-BASE<=65536u-n;}
static uint8_t*at(uint8_t*m,uint32_t a){return m+a-BASE;}
static uint32_t lock(rr_mouse_rtos*c){uint32_t old=c->priority;if(!old||old>0x20)c->priority=0x20;return old;}
static int schedule(uint8_t*m,uint8_t*r,int force){
 uint32_t next=w(m+0x7668),cur=w(m+0x7654);if(!next||next==0x23007668u)next=w(m+0x7658);
 if(!valid(next,0x90)||!valid(cur,0x90))return -1;uint8_t*t=at(m,next),*current=at(m,cur);
 if(!force&&!(current[0xd]&31u)&&!w(t+0x18)&&h(current+0xe)>=128u)next=cur;
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
  if((int8_t)t[0xe]<(int8_t)v[0xe]){uint32_t prev=w(v+4);if(!valid(prev,4))return -1;pw(t,i);pw(t+4,prev);pw(at(m,prev),address);pw(v+4,address);return schedule(m,r,0);}
  if(i==last)break;i=w(v);
 }
 if(!valid(last,4))return -1;pw(t,0x23007668);pw(t+4,last);pw(at(m,last),address);pw(m+0x766c,address);return schedule(m,r,0);
}



/* Original0E096AD6 continuation. No timeout-abort or timer status/result write
 * occurs here: stop wakes one timer waiter, unlike semaphore give. */
int rr_mouse_timer_stop_after_callback(uint8_t*m,uint8_t*r,uint32_t address,rr_mouse_rtos*c){
 if(!m||!r||!c||!valid(address,0x38))return -1;
 c->entry=0;c->arg0=0;uint32_t old=lock(c),queue=address+0x18,first=w(at(m,queue));
 if(!first||first==queue){c->priority=old;return 0;}
 if(!valid(first,0x90))return -1;uint8_t*t=at(m,first);uint32_t next=w(t),prev=w(t+4);
 if(!valid(next,8)||!valid(prev,4))return -1;
 pw(at(m,prev),next);pw(at(m,next)+4,prev);pw(t,0);pw(t+4,0);t[0xd]&=0xfdu;pw(t+8,0);
 c->priority=old;uint32_t readyold=lock(c);int rc=ready(m,r,first);if(rc)return rc;c->priority=readyold;
 old=lock(c);if(!old&&!(c->exception_number&0x1ffu)&&w(m+0x7664)!=w(m+0x7654)){c->entry=0x0e089d4cu;c->arg0=0;return 1;}
 c->priority=old;return 0;
}
int rr_mouse_timer_stop_runtime(uint8_t*m,uint8_t*r,uint32_t address,rr_mouse_rtos*c){
 if(!m||!r||!c||!valid(address,0x38))return -1;c->entry=0;c->arg0=0;
 int32_t result;int rc=rr_mouse_timer_abort(m,r,address,&result);if(rc||result)return rc;
 uint32_t callback=w(at(m,address)+0x24);
 if(callback){c->entry=callback&~1u;c->arg0=address;return 1;}
 return rr_mouse_timer_stop_after_callback(m,r,address,c);
}
