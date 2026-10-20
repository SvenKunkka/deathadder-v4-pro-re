#include "mouse_worker_runtime.h"
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



static int boundary(rr_mouse_rtos*c,uint32_t entry,uint32_t arg){c->entry=entry;c->arg0=arg;return 1;}
static int unlink_thread(uint8_t*m,uint32_t address){
 if(!valid(address,0x90))return -1;uint8_t*t=at(m,address);uint32_t next=w(t),prev=w(t+4);if(!valid(next,8)||!valid(prev,4))return -1;
 pw(at(m,prev),next);pw(at(m,next)+4,prev);pw(t,0);pw(t+4,0);return 0;
}
static int insert_thread(uint8_t*m,uint32_t queue,uint32_t address){
 if(!valid(queue,8)||!valid(address,0x90))return -1;uint8_t*q=at(m,queue),*t=at(m,address);uint32_t first=w(q),last=w(q+4);if(first==queue)first=0;unsigned count=0;
 for(uint32_t n=first;n;){if(!valid(n,0x90)||++count>128)return -1;uint8_t*v=at(m,n);if((int8_t)t[0xe]<(int8_t)v[0xe]){uint32_t prev=w(v+4);if(!valid(prev,4))return -1;pw(t,n);pw(t+4,prev);pw(at(m,prev),address);pw(v+4,address);return 0;}if(n==last)break;n=w(v);}
 if(!valid(last,4))return -1;pw(t,queue);pw(t+4,last);pw(at(m,last),address);pw(q+4,address);return 0;
}
int rr_mouse_wait_wake(uint8_t*m,uint8_t*r,uint32_t queue,uint32_t result,uint32_t data,rr_mouse_rtos*c,int32_t*out){
 if(!m||!r||!c||!out||!valid(queue,8))return -1;c->entry=0;c->arg0=0;uint32_t old=lock(c),first=w(at(m,queue));if(!first||first==queue){c->priority=old;*out=0;return 0;}
 if(!valid(first,0x90))return -1;uint8_t*t=at(m,first);pw(t+0x14,data);pw(t+0x8c,result);int rc=unlink_thread(m,first);if(rc)return rc;pw(t+8,0);t[0xd]&=0xfdu;
 int32_t ignored;rc=rr_mouse_timer_abort(m,r,first+0x18,&ignored);if(rc)return rc;rc=ready(m,r,first);if(rc)return rc;c->priority=old;*out=1;return 0;
}
int rr_mouse_worker_yield(uint8_t*m,uint8_t*r,rr_mouse_rtos*c){
 if(!m||!r||!c)return -1;c->entry=0;c->arg0=0;uint32_t old=lock(c),cur=w(m+0x7654);if(!valid(cur,0x90))return -1;uint8_t*t=at(m,cur);t[0xd]&=127u;int rc=unlink_thread(m,cur);if(rc)return rc;t[0xd]|=128u;
 rc=insert_thread(m,0x23007668u,cur);if(rc)return rc;rc=schedule(m,r,1);if(rc)return rc;return boundary(c,0x0e089d4cu,old);
}
int rr_mouse_worker_pend(uint8_t*m,uint8_t*r,uint32_t queue,uint32_t saved_priority,uint64_t timeout,rr_mouse_rtos*c){
 if(!m||!r||!c)return -1;c->entry=0;c->arg0=0;uint32_t cur=w(m+0x7654);if(!valid(cur,0x90))return -1;pw(m+0x7670,cur);lock(c);uint8_t*t=at(m,cur);int rc;
 if(t[0xd]&128u){t[0xd]&=127u;rc=unlink_thread(m,cur);if(rc)return rc;}rc=schedule(m,r,1);if(rc)return rc;t[0xd]|=2u;
 if(queue){if(!valid(queue,8))return -1;pw(t+8,queue);rc=insert_thread(m,queue,cur);if(rc)return rc;}
 if(timeout!=UINT64_MAX){rc=rr_mouse_timeout_start(m,r,cur+0x18,0x0e0959a5u,timeout);if(rc)return rc;}
 return boundary(c,0x0e089d4cu,saved_priority);
}
int rr_mouse_delayed_work_expiry(uint8_t*m,uint8_t*r,uint32_t timeout,rr_mouse_rtos*c){
 if(!m||!r||!c||timeout<BASE+16u||!valid(timeout-16u,44))return -1;c->entry=0;c->arg0=0;uint8_t*work=at(m,timeout-16u);uint32_t old=lock(c),flags=w(work+12);pw(work+12,flags&~8u);
 if(flags&8u){uint32_t queue=w(work+40);int32_t ignored;int rc=rr_mouse_work_submit_to_queue(m,r,timeout-16u,&queue,c,&ignored);if(rc)return rc;}c->priority=old;return 0;
}
static int worker_tail(uint8_t*m,uint8_t*r,uint32_t queue,rr_mouse_rtos*c,uint32_t old,int rc){
 if(rc!=1)return rc;
 if(c->entry==0x0e09600cu)return rr_mouse_worker_yield(m,r,c);
 if(c->entry==0x0e096220u){int32_t found;unsigned count=0;do{if(++count>128)return -5;rc=rr_mouse_wait_wake(m,r,queue+0xa0,1,0,c,&found);if(rc)return rc;}while(found);}
 else if(c->entry!=0x0e09628cu)return 1;
 return rr_mouse_worker_pend(m,r,queue+0x98,old,UINT64_MAX,c);
}

int rr_mouse_work_thread_runtime(uint8_t*m,uint8_t*r,uint8_t*a,uint32_t queue,rr_mouse_rtos*c){
 if(!m||!r||!a||!c||!valid(queue,0xac))return -1;uint32_t old=c->priority;int rc=rr_mouse_work_thread_step(m,r,a,queue,c);return worker_tail(m,r,queue,c,old,rc);
}
int rr_mouse_work_thread_scanning_runtime(rr_mouse_scan_hw*x,uint32_t queue,rr_mouse_rtos*c){
 if(!x||!c||!valid(queue,0xac))return -1;uint32_t old=c->priority;int rc=rr_mouse_work_thread_scanning(x,queue,c);return worker_tail(x->ram,x->rtc,queue,c,old,rc);
}
