#include "receiver_worker_runtime.h"
#define BASE 0x23000000u
static uint32_t w(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static uint16_t h(const uint8_t*p){return (uint16_t)(p[0]|(uint16_t)p[1]<<8);}
static void pw(uint8_t*p,uint32_t v){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(v>>(8*i));}
static int valid(uint32_t a,unsigned n){return a>=BASE&&a-BASE<=131072u-n;}
static uint8_t*at(uint8_t*m,uint32_t a){return m+a-BASE;}
static uint32_t lock(rr_receiver_rtos*c){uint32_t old=c->priority;if(!old||old>0x40)c->priority=0x40;return old;}
static int schedule(uint8_t*m,uint8_t*r,int force){
 uint32_t next=w(m+0x7180),cur=w(m+0x7170);if(!next||next==0x23007180u)next=w(m+0x7174);
 if(!valid(next,0x90)||!valid(cur,0x90))return -1;uint8_t*t=at(m,next),*current=at(m,cur);
 if(!force&&!(current[0xd]&31u)&&!w(t+0x18)&&h(current+0xe)>=128u)next=cur;
 if(next!=cur){
  t=at(m,next);unsigned cpu=m[0x7178];uint32_t timeout=0x23002c60u+cpu*24u;if(!valid(timeout,0x38))return -1;
  int32_t result;int rc=rr_receiver_timeout_abort(m,r,timeout,&result);if(rc)return rc;m[0x718c+cpu]=0;
  if(h(t+0xe)<128u&&w(m+0x7194)&&(int32_t)w(m+0x7190)<=(int8_t)t[0xe]&&!(t[0xd]&31u)&&next!=0x230029f8u){
   uint32_t d=w(m+0x7194)-1;uint64_t delay=(d&0x80000000u)?UINT64_C(0xffffffff00000000)|d:d;rc=rr_receiver_timeout_start(m,r,timeout,0xe06e4c9,delay);if(rc)return rc;
  }
 }
 pw(m+0x717c,next);return 0;
}
static int ready(uint8_t*m,uint8_t*r,uint32_t address){
 if(!valid(address,0x90))return -1;uint8_t*t=at(m,address);if((t[0xd]&0x9fu)||w(t+0x18))return 0;t[0xd]|=0x80u;
 uint32_t first=w(m+0x7180),last=w(m+0x7184);if(first==0x23007180u)first=0;
 unsigned count=0;for(uint32_t i=first;i;){if(!valid(i,0x90)||++count>128)return -1;uint8_t*v=at(m,i);
  if((int8_t)t[0xe]<(int8_t)v[0xe]){uint32_t prev=w(v+4);if(!valid(prev,4))return -1;pw(t,i);pw(t+4,prev);pw(at(m,prev),address);pw(v+4,address);return schedule(m,r,0);}
  if(i==last)break;i=w(v);
 }
 if(!valid(last,4))return -1;pw(t,0x23007180);pw(t+4,last);pw(at(m,last),address);pw(m+0x7184,address);return schedule(m,r,0);
}



static int boundary(rr_receiver_rtos*c,uint32_t entry,uint32_t arg){c->entry=entry;c->arg0=arg;return 1;}
static int unlink_thread(uint8_t*m,uint32_t address){
 if(!valid(address,0x90))return -1;uint8_t*t=at(m,address);uint32_t next=w(t),prev=w(t+4);if(!valid(next,8)||!valid(prev,4))return -1;
 pw(at(m,prev),next);pw(at(m,next)+4,prev);pw(t,0);pw(t+4,0);return 0;
}
static int insert_thread(uint8_t*m,uint32_t queue,uint32_t address){
 if(!valid(queue,8)||!valid(address,0x90))return -1;uint8_t*q=at(m,queue),*t=at(m,address);uint32_t first=w(q),last=w(q+4);if(first==queue)first=0;unsigned count=0;
 for(uint32_t n=first;n;){if(!valid(n,0x90)||++count>128)return -1;uint8_t*v=at(m,n);if((int8_t)t[0xe]<(int8_t)v[0xe]){uint32_t prev=w(v+4);if(!valid(prev,4))return -1;pw(t,n);pw(t+4,prev);pw(at(m,prev),address);pw(v+4,address);return 0;}if(n==last)break;n=w(v);}
 if(!valid(last,4))return -1;pw(t,queue);pw(t+4,last);pw(at(m,last),address);pw(q+4,address);return 0;
}
int rr_receiver_wait_wake(uint8_t*m,uint8_t*r,uint32_t queue,uint32_t result,uint32_t data,rr_receiver_rtos*c,int32_t*out){
 if(!m||!r||!c||!out||!valid(queue,8))return -1;c->entry=0;c->arg0=0;uint32_t old=lock(c),first=w(at(m,queue));if(!first||first==queue){c->priority=old;*out=0;return 0;}
 if(!valid(first,0x90))return -1;uint8_t*t=at(m,first);pw(t+0x14,data);pw(t+0x8c,result);int rc=unlink_thread(m,first);if(rc)return rc;pw(t+8,0);t[0xd]&=0xfdu;
 int32_t ignored;rc=rr_receiver_timeout_abort(m,r,first+0x18,&ignored);if(rc)return rc;rc=ready(m,r,first);if(rc)return rc;c->priority=old;*out=1;return 0;
}
int rr_receiver_worker_yield(uint8_t*m,uint8_t*r,rr_receiver_rtos*c){
 if(!m||!r||!c)return -1;c->entry=0;c->arg0=0;uint32_t old=lock(c),cur=w(m+0x7170);if(!valid(cur,0x90))return -1;uint8_t*t=at(m,cur);t[0xd]&=127u;int rc=unlink_thread(m,cur);if(rc)return rc;t[0xd]|=128u;
 rc=insert_thread(m,0x23007180u,cur);if(rc)return rc;rc=schedule(m,r,1);if(rc)return rc;return boundary(c,0xe0611ccu,old);
}
int rr_receiver_worker_pend(uint8_t*m,uint8_t*r,uint32_t queue,uint32_t saved_priority,uint64_t timeout,rr_receiver_rtos*c){
 if(!m||!r||!c)return -1;c->entry=0;c->arg0=0;uint32_t cur=w(m+0x7170);if(!valid(cur,0x90))return -1;pw(m+0x7188,cur);lock(c);uint8_t*t=at(m,cur);int rc;
 if(t[0xd]&128u){t[0xd]&=127u;rc=unlink_thread(m,cur);if(rc)return rc;}rc=schedule(m,r,1);if(rc)return rc;t[0xd]|=2u;
 if(queue){if(!valid(queue,8))return -1;pw(t+8,queue);rc=insert_thread(m,queue,cur);if(rc)return rc;}
 if(timeout!=UINT64_MAX){rc=rr_receiver_timeout_start(m,r,cur+0x18,0xe06daf5u,timeout);if(rc)return rc;}
 return boundary(c,0xe0611ccu,saved_priority);
}
int rr_receiver_work_thread_step_with_handler(uint8_t*m,uint8_t*r,uint8_t*a,uint32_t address,rr_receiver_rtos*c,rr_receiver_usb_external_driver driver,void*user,rr_receiver_usb_call*usb,rr_receiver_worker_callback callback,void*context){
 if(!m||!r||!a||!c||!usb||!valid(address,0xac))return -1;*usb=(rr_receiver_usb_call){0,0,0,0};c->entry=0;c->arg0=0;uint8_t*q=at(m,address);uint32_t old=lock(c),work=w(q+0x90),state;
 if(!work){state=w(q+0xa8);pw(q+0xa8,state&~4u);if(state&4u){int32_t found;unsigned n=0;do{if(++n>128)return -5;int rc=rr_receiver_wait_wake(m,r,address+0xa0,1,0,c,&found);if(rc)return rc;}while(found);}return rr_receiver_worker_pend(m,r,address+0x98,old,UINT64_MAX,c);}
 if(!valid(work,16))return -1;uint8_t*v=at(m,work);uint32_t next=w(v);pw(q+0x90,next);if(work==w(q+0x94))pw(q+0x94,next);pw(q+0xa8,w(q+0xa8)|2u);uint32_t handler=w(v+4);pw(v+12,(w(v+12)&~4u)|1u);c->priority=old;
 int rc;
 if(handler!=0x23026d29u){
  if(!callback)return boundary(c,handler&~1u,work);
  rc=callback(context,handler,work,c);if(rc)return rc;
 }else{
  rc=rr_receiver_usb_reports(m,a,0x23026d28u,driver,user,usb);if(rc){if(rc==1){c->entry=usb->entry;c->arg0=usb->device;}return rc;}
 }
 old=lock(c);uint32_t flags=w(v+12);
 if(flags&16u){pw(v+12,flags&~17u);rc=rr_receiver_semaphore_give_timed(m,r,work+16u,c);if(rc)return rc;}else pw(v+12,flags&~1u);flags=w(v+12);
 if(flags&2u){
  pw(v+12,w(v+12)&~2u);uint32_t item=w(m+0x2bc8),prev=0;unsigned count=0;
  while(item){if(!valid(item,24)||++count>256)return -1;uint8_t*t=at(m,item);uint32_t n=w(t);
   if(w(t+4)==work){if(prev)pw(at(m,prev),n);else pw(m+0x2bc8,n);if(w(m+0x2bcc)==item)pw(m+0x2bcc,prev?prev:n);pw(t,0);rc=rr_receiver_semaphore_give_timed(m,r,item+8,c);if(rc)return rc;break;}
   prev=item;item=n;
  }
 }
 state=w(q+0xa8)&~2u;pw(q+0xa8,state);c->priority=old;if(!(state&0x100u))return rr_receiver_worker_yield(m,r,c);return 0;
}

int rr_receiver_work_thread_step(uint8_t*m,uint8_t*r,uint8_t*a,uint32_t address,rr_receiver_rtos*c,rr_receiver_usb_external_driver driver,void*user,rr_receiver_usb_call*usb){
 return rr_receiver_work_thread_step_with_handler(m,r,a,address,c,driver,user,usb,0,0);
}
