#include "mouse_work_queue.h"
#include "mouse_timer_lifecycle.h"
#include "mouse_timer_start.h"
#include <string.h>
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
static int wake(uint8_t*m,uint8_t*r,uint32_t queue){
 if(!valid(queue,8))return -1;uint32_t first=w(at(m,queue));if(!first||first==queue)return 0;
 if(!valid(first,0x90))return -1;uint8_t*t=at(m,first);uint32_t next=w(t),prev=w(t+4);if(!valid(next,8)||!valid(prev,4))return -1;
 pw(t+0x14,0);pw(t+0x8c,0);pw(at(m,prev),next);pw(at(m,next)+4,prev);pw(t+8,0);t[0xd]&=0xfdu;pw(t,0);pw(t+4,0);
 int32_t result;int rc=rr_mouse_timer_abort(m,r,first+0x18,&result);if(rc)return rc;return ready(m,r,first);
}
int rr_mouse_work_submit_to_queue(uint8_t*m,uint8_t*r,uint32_t address,uint32_t*q,rr_mouse_rtos*c,int32_t*result){
 if(!m||!r||!q||!c||!result||!valid(address,16))return -1;uint8_t*work=at(m,address);uint32_t flags=w(work+12);int32_t value=0;
 if(flags&2u)value=-16;else if(flags&4u)value=0;else{
  uint32_t queue=*q;if(!queue){queue=w(work+8);*q=queue;}
  unsigned outcome=1;if(flags&1u){queue=w(work+8);*q=queue;outcome=2;}
  if(!queue)value=-22;else{
   if(!valid(queue,0xac))return -1;uint8_t*t=at(m,queue);uint32_t state=w(t+0xa8);
   if(!(state&1u))value=-19;else{
    int self_thread=queue==w(m+0x7654)&&!(c->exception_number&0x1ffu);int allowed=self_thread?(!(state&8u)||(state&4u)):!(state&12u);
    if(!allowed)value=-16;else{
     pw(work,0);uint32_t tail=w(t+0x94);if(tail){if(!valid(tail,4))return -1;pw(at(m,tail),address);}else pw(t+0x90,address);pw(t+0x94,address);
     uint32_t old=lock(c);int rc=wake(m,r,queue+0x98);if(rc)return rc;c->priority=old;
     pw(work+12,w(work+12)|4u);pw(work+8,*q);*result=(int32_t)outcome;return 0;
    }
   }
  }
 }
 *q=0;*result=value;return 0;
}
int rr_mouse_work_submit(uint8_t*m,uint8_t*r,uint32_t address,rr_mouse_rtos*c,int32_t*result){
 if(!m||!r||!c||!result)return -1;c->entry=0;c->arg0=0;uint32_t old=lock(c),queue=0x23002498u;int rc=rr_mouse_work_submit_to_queue(m,r,address,&queue,c,result);if(rc)return rc;c->priority=old;
 if(*result>0){old=lock(c);if(!old&&!(c->exception_number&0x1ffu)&&w(m+0x7664)!=w(m+0x7654)){c->entry=0x0e089d4c;c->arg0=0;return 1;}c->priority=old;}return 0;
}
int rr_mouse_mode4_timer_rtos(uint8_t*m,uint8_t*r,uint8_t*t,uint8_t*spim,const uint8_t*f,uint8_t*rtc,uint32_t*clock,uint32_t*nv,rr_mouse_rtos*c,rr_mouse_mode4_pending*p){
 if(!rtc||!c||!p)return -1;c->entry=0;c->arg0=0;int rc=rr_mouse_mode4_timer_lifecycle(m,r,t,spim,f,clock,nv,p);if(rc!=1)return rc;
 if(p->entry==0x0e0952ecu){int32_t result;rc=rr_mouse_work_submit(m,rtc,p->args[0],c,&result);if(rc){if(rc==1){p->entry=c->entry;p->args[0]=c->arg0;}return rc;}m[0x6b82]=0;m[0x6b83]=0;p->entry=0x0e096a50;p->args[0]=0x23001578;p->args[1]=0;p->args[2]=(h(m+0x6b80)*31250u+999u)/1000u;p->args[3]=0;}
 if(p->entry!=0x0e096a50u)return 1;
 uint32_t old=lock(c);rc=rr_mouse_timer_start(m,rtc,p->args[0],(uint64_t)p->args[2]|(uint64_t)p->args[3]<<32,0);if(rc)return rc;c->priority=old;memset(p,0,sizeof(*p));return 0;
}
