#include "mouse_wireless_startup.h"
#include "mouse_worker_runtime.h"
#include "mouse_timer_start.h"
#include "mouse_timer_lifecycle.h"
#include <string.h>
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
static void work_init(uint8_t*m,uint32_t offset,uint32_t callback){
 pw(m+offset+4,callback);pw(m+offset+8,0);pw(m+offset+12,0);pw(m+offset,0);
}
int rr_mouse_scan_work_initialize(uint8_t*m){
 if(!m)return -1;work_init(m,0x3858,0x23022621);m[0x76f8]=1;return 0;
}
int rr_mouse_thread_start(uint8_t*m,uint8_t*r,uint32_t address,rr_mouse_rtos*c){
 if(!m||!r||!c||!valid(address,0x90))return -1;c->entry=0;c->arg0=0;
 uint32_t old=lock(c);uint8_t*t=at(m,address);
 if(t[0xd]&4u){t[0xd]&=0xfbu;int rc=ready(m,r,address);if(rc)return rc;
  if(!old&&!(c->exception_number&0x1ffu)&&w(m+0x7664)!=w(m+0x7654))return boundary(c,0x0e089d4c,old);
 }
 c->priority=old;return 0;
}
int rr_mouse_thread_create(uint8_t*m,uint8_t*r,const rr_mouse_thread_config*q,rr_mouse_rtos*c,uint32_t*out){
 if(!m||!r||!q||!c||!out||!valid(q->thread,0x90)||q->size>0x1fff8u)return -1;
 uint32_t size=(q->size+7u)&~7u;
 if(size<48u||q->stack<BASE||q->stack-BASE>131072u-size)return -1;
 c->entry=0;c->arg0=0;uint8_t*t=at(m,q->thread);uint32_t top=q->stack+size,frame=top-48u;
 t[0xc]=(uint8_t)q->options;t[0xe]=(uint8_t)q->priority;
 pw(t+0x58,q->thread+0x58);pw(t+0x5c,q->thread+0x58);t[0xd]=4;
 pw(t+0x18,0);pw(t+0x1c,0);pw(t+8,0);t[0xf]=0;
 memset(at(m,top-8),0,8);pw(t+0x84,top-16);
 pw(t+0x78,size);pw(t+0x74,q->stack);pw(t+0x7c,16);
 pw(at(m,frame),q->entry);pw(at(m,frame)+4,q->arg1);pw(at(m,frame)+8,q->arg2);pw(at(m,frame)+12,q->arg3);
 pw(at(m,frame)+24,0x0e085ea4);pw(at(m,frame)+28,0x01000000);
 pw(t+0x88,0);pw(t+0x50,frame);pw(t+0x54,0);pw(t+0x70,0);t[0x6c]=0;
 uint32_t current=w(m+0x7654);if(current&&!valid(current,0x90))return -1;pw(t+0x80,current?w(at(m,current)+0x80):0);
 int rc=0;
 if(q->delay!=UINT64_MAX){
  if(!q->delay)rc=rr_mouse_thread_start(m,r,q->thread,c);
  else rc=rr_mouse_timeout_start(m,r,q->thread+0x18,0x0e0959a5,q->delay);
 }
 if(rc)return rc;*out=q->thread;return 0;
}
static int ticks(uint8_t*m,uint8_t*r,uint32_t*out){
 uint32_t elapsed=0;if(!w(m+0x7680)){
  uint32_t high=w(r+0x774);if(high>0x3fffffffu)return -4;
  uint64_t now=(uint64_t)(high&0xfffffu)<<32|w(r+0x770);
  uint64_t previous=(uint64_t)w(m+0x21c4)<<32|w(m+0x21c0);
  elapsed=(uint32_t)((now-previous)>>5);
 }
 *out=w(m+0x25f8)+elapsed;return 0;
}
int rr_mouse_ticks_sleep(uint8_t*m,uint8_t*r,uint64_t duration,rr_mouse_rtos*c,uint32_t*deadline){
 if(!m||!r||!c||!deadline)return -1;c->entry=0;c->arg0=0;
 if(!duration)return rr_mouse_worker_yield(m,r,c);
 uint32_t end;int rc;
 if(!(duration>>63)||duration>=UINT64_MAX-1u){rc=ticks(m,r,&end);if(rc)return rc;end+=(uint32_t)duration;}
 else end=0u-(uint32_t)duration-2u;
 *deadline=end;uint32_t old=lock(c),cur=w(m+0x7654);if(!valid(cur,0x90))return -1;pw(m+0x7670,cur);uint8_t*t=at(m,cur);
 if(t[0xd]&128u){t[0xd]&=127u;rc=unlink_thread(m,cur);if(rc)return rc;}
 rc=schedule(m,r,1);if(rc)return rc;
 rc=rr_mouse_timeout_start(m,r,cur+0x18,0x0e0959a5,duration);if(rc)return rc;
 t[0xd]|=16u;return boundary(c,0x0e089d4c,old);
}
int rr_mouse_public_sleep(uint8_t*m,uint8_t*r,uint64_t duration,rr_mouse_rtos*c,uint32_t*out){
 if(!m||!r||!c||!out)return -1;c->entry=0;c->arg0=0;
 if(duration!=UINT64_MAX){uint32_t deadline;return rr_mouse_ticks_sleep(m,r,duration,c,&deadline);}
 uint32_t cur=w(m+0x7654);if(!valid(cur,0x90))return -1;uint8_t*t=at(m,cur);int32_t ignored;
 int rc=rr_mouse_timer_abort(m,r,cur+0x18,&ignored);if(rc)return rc;uint32_t old=lock(c);
 if(!(t[0xd]&16u)){
  if(t[0xd]&128u){t[0xd]=(t[0xd]&127u)|16u;rc=unlink_thread(m,cur);if(rc)return rc;}else t[0xd]|=16u;
  rc=schedule(m,r,1);if(rc)return rc;t[0xd]&=0x9fu;
  if(!(c->exception_number&0x1ffu))return boundary(c,0x0e089d4c,old);
 }
 c->priority=old;*out=UINT32_MAX;return 0;
}
int rr_mouse_wireless_setup(rr_mouse_startup_hw*x,rr_mouse_rtos*c){
 if(!x||!x->init.ram||!x->rtc||!c)return -1;
 uint8_t*m=x->init.ram;int rc=rr_mouse_scan_work_initialize(m);if(rc)return rc;
 rr_mouse_thread_config q={0x23001bb8,0x230109e0,0x400,0x23025d91,0,0,0,10,0,0};uint32_t result;
 rc=rr_mouse_thread_create(m,x->rtc,&q,c,&result);if(rc)return rc;
 work_init(m,0x67c0,0x23025df1);work_init(m,0x67b0,0x23025eb1);work_init(m,0x67a0,0x23025e39);
 m[0x76fb]=0;m[0x76fa]=0;return 0;
}
int rr_mouse_wireless_startup(rr_mouse_startup_hw*x,uint32_t identity,uint32_t rate,rr_mouse_rtos*c){
 if(!x||!x->init.ram||!x->rtc||!x->key_table||!c)return -1;c->entry=0;c->arg0=0;uint8_t*m=x->init.ram;int rc;
 if(!m[0x779a]){rc=rr_mouse_wireless_setup(x,c);if(rc)return rc;m[0x779a]=1;uint32_t result;rc=rr_mouse_public_sleep(m,x->rtc,625,c,&result);if(rc)return rc;}
 rc=rr_mouse_application_initialize(&x->init,identity,0xbf,0,rate,x->key_table);if(rc)return rc;m[0x7799]=1;return 0;
}
