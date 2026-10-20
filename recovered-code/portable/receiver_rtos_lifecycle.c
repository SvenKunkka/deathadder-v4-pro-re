#include "receiver_rtos_lifecycle.h"
#include <string.h>
static uint16_t h(const uint8_t*p){return (uint16_t)(p[0]|p[1]<<8);}
static uint32_t w(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void pw(uint8_t*p,uint32_t x){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(x>>(8*i));}
static int valid(uint32_t a,unsigned len){return a>=0x23000000u&&a-0x23000000u<=0x20000u-len;}
static uint8_t*at(uint8_t*m,uint32_t a){return m+a-0x23000000u;}
static uint32_t lock(rr_receiver_rtos*c){uint32_t old=c->priority;if(!old||old>0x40)c->priority=0x40;return old;}
static int pending(rr_receiver_rtos*c,uint32_t entry,uint32_t arg){c->entry=entry;c->arg0=arg;return 1;}
static int unlock(uint8_t*m,rr_receiver_rtos*c,uint32_t old){
 if(!old&&!c->exception_number&&w(m+0x717c)!=w(m+0x7170))return pending(c,0x0e0611cc,0);
 c->priority=old;return 0;
}
/* Actual waiter dequeue prefix0E06DF70; timer cancellation has a real boundary. */
static int pop(uint8_t*m,uint32_t address,rr_receiver_rtos*c,uint32_t*out,const rr_receiver_rtos_ops*ops){
 if(!valid(address,8))return -1;uint8_t*q=at(m,address);uint32_t first=w(q);*out=first;
 if(!first||first==address){*out=0;return 0;}if(!valid(first,0x90))return -1;
 uint8_t*t=at(m,first);uint32_t next=w(t),prev=w(t+4);if(!valid(next,8)||!valid(prev,4))return -1;
 pw(at(m,prev),next);pw(at(m,next)+4,prev);pw(t,0);pw(t+4,0);t[0xd]&=0xfdu;pw(t+8,0);
 if(w(t+0x18)){if(!ops||!ops->abort)return pending(c,0x0e06e768,first+0x18);return ops->abort(ops->context,first+0x18);}return 0;
}
static int schedule(uint8_t*m,rr_receiver_rtos*c,const rr_receiver_rtos_ops*ops){
 uint32_t next=w(m+0x7180),cur=w(m+0x7170);if(!next||next==0x23007180u)next=w(m+0x7174);
 if(!valid(cur,0x90)||!valid(next,0x90))return -1;uint8_t*t=at(m,next),*current=at(m,cur);
 if(!(current[0xd]&31u)&&!w(t+0x18)&&h(current+0xe)>=128u)next=cur;
 if(next!=cur){
  t=at(m,next);unsigned cpu=m[0x7178];uint32_t timeout=0x23002c60u+cpu*24u;if(!valid(timeout,24))return -1;
  if(w(at(m,timeout))){if(!ops||!ops->abort)return pending(c,0x0e06e768,timeout);int rc=ops->abort(ops->context,timeout);if(rc)return rc;}
  m[0x718c+cpu]=0;
  if(h(t+0xe)<128u&&w(m+0x7194)&&(int32_t)w(m+0x7190)<=(int8_t)t[0xe]&&!(t[0xd]&31u)&&next!=0x230029f8u){if(!ops||!ops->start)return pending(c,0x0e06e648,timeout);uint32_t d=w(m+0x7194)-1;uint64_t delay=(d&0x80000000u)?UINT64_C(0xffffffff00000000)|d:d;int rc=ops->start(ops->context,timeout,0x0e06e4c9,delay);if(rc)return rc;}
 }
 pw(m+0x717c,next);return 0;
}
static int ready(uint8_t*m,uint32_t address,rr_receiver_rtos*c,const rr_receiver_rtos_ops*ops){
 uint8_t*t=at(m,address);if((t[0xd]&0x9fu)||w(t+0x18))return 0;t[0xd]|=0x80u;
 uint32_t first=w(m+0x7180),last=w(m+0x7184);if(first==0x23007180u)first=0;
 unsigned bound=0;for(uint32_t i=first;i;){
  if(!valid(i,0x90)||++bound>128)return -1;uint8_t*v=at(m,i);
  if((int8_t)t[0xe]<(int8_t)v[0xe]){uint32_t prev=w(v+4);if(!valid(prev,4))return -1;pw(t,i);pw(t+4,prev);pw(at(m,prev),address);pw(v+4,address);return schedule(m,c,ops);}
  if(i==last)break;i=w(v);
 }
 if(!valid(last,4))return -1;pw(t,0x23007180);pw(t+4,last);pw(at(m,last),address);pw(m+0x7184,address);return schedule(m,c,ops);
}
int rr_receiver_semaphore_give_with_ops(uint8_t*m,uint32_t address,rr_receiver_rtos*c,const rr_receiver_rtos_ops*ops){
 if(!m||!c||!valid(address,16))return -1;c->entry=0;c->arg0=0;uint32_t old=lock(c),thread;int rc=pop(m,address,c,&thread,ops);if(rc)return rc;
 if(!thread){uint8_t*q=at(m,address);uint32_t count=w(q+8);if(count!=w(q+12))count++;pw(q+8,count);c->priority=old;return 0;}
 pw(at(m,thread)+0x8c,0);rc=ready(m,thread,c,ops);if(rc)return rc;return unlock(m,c,old);
}
int rr_receiver_message_put_with_ops(uint8_t*m,uint32_t address,const uint8_t message[36],rr_receiver_rtos*c,int32_t*result,const rr_receiver_rtos_ops*ops){
 if(!m||!c||!message||!result||!valid(address,40))return -1;c->entry=0;c->arg0=0;uint32_t old=lock(c);uint8_t*q=at(m,address);if(w(q+8)!=36)return -1;
 if(w(q+32)>=w(q+12)){*result=-35;c->priority=old;return 0;}
 uint32_t thread;int rc=pop(m,address,c,&thread,ops);if(rc)return rc;
 if(thread){uint8_t*t=at(m,thread);uint32_t dest=w(t+0x14);if(!valid(dest,36))return -1;memcpy(at(m,dest),message,36);pw(t+0x8c,0);rc=ready(m,thread,c,ops);if(rc)return rc;rc=unlock(m,c,old);if(rc)return rc;*result=0;return 0;}
 uint32_t dest=w(q+28);if(!valid(dest,36))return -1;memcpy(at(m,dest),message,36);dest+=36;if(dest==w(q+20))dest=w(q+16);pw(q+28,dest);pw(q+32,w(q+32)+1);*result=0;c->priority=old;return 0;
}
int rr_receiver_message_purge_with_ops(uint8_t*m,uint32_t address,rr_receiver_rtos*c,const rr_receiver_rtos_ops*ops){
 if(!m||!c||!valid(address,40))return -1;c->entry=0;c->arg0=0;uint32_t old=lock(c),thread;int rc;
 for(unsigned i=0;;i++){if(i>128)return -1;rc=pop(m,address,c,&thread,ops);if(rc)return rc;if(!thread)break;pw(at(m,thread)+0x8c,0xffffffddu);rc=ready(m,thread,c,ops);if(rc)return rc;}
 uint8_t*q=at(m,address);pw(q+32,0);pw(q+24,w(q+28));return unlock(m,c,old);
}
int rr_receiver_disconnect_notice_with_ops(uint8_t*m,const uint8_t pair[8],const uint8_t tail[24],rr_receiver_rtos*c,const rr_receiver_rtos_ops*ops){
 if(!m||!pair||!tail||!c||w(m+0x1b94)!=36||w(m+0x1b98)!=5)return -1;
 uint8_t message[36];pw(message,2);memcpy(message+4,pair,8);memcpy(message+12,tail,24);int32_t result;int rc=rr_receiver_message_put_with_ops(m,0x23001b8c,message,c,&result,ops);if(rc||!result)return rc;
 rc=rr_receiver_message_purge_with_ops(m,0x23001b8c,c,ops);if(rc)return rc;return rr_receiver_message_put_with_ops(m,0x23001b8c,message,c,&result,ops);
}
int rr_receiver_timer_mode4_lifecycle(uint8_t*m,const uint8_t*f,rr_receiver_radio_hw*h,rr_receiver_rtos*c,const uint8_t tail[24]){
 if(!m||!f||!h||!c||!tail)return -1;c->entry=0;c->arg0=0;
 rr_receiver_timer_pending p;int rc=rr_receiver_timer_mode4(m,f,h,&p);if(rc!=1)return rc;
 rc=rr_receiver_semaphore_give(m,p.arg0,c);if(rc)return rc;uint8_t pair[8];pw(pair,0);memcpy(pair+4,m+0x33f2,4);return rr_receiver_disconnect_notice(m,pair,tail,c);
}

/* ABI-compatible entry points retain the earlier explicit boundaries. */
int rr_receiver_semaphore_give(uint8_t*m,uint32_t a,rr_receiver_rtos*c){return rr_receiver_semaphore_give_with_ops(m,a,c,0);}
int rr_receiver_message_put(uint8_t*m,uint32_t a,const uint8_t b[36],rr_receiver_rtos*c,int32_t*v){return rr_receiver_message_put_with_ops(m,a,b,c,v,0);}
int rr_receiver_message_purge(uint8_t*m,uint32_t a,rr_receiver_rtos*c){return rr_receiver_message_purge_with_ops(m,a,c,0);}
int rr_receiver_disconnect_notice(uint8_t*m,const uint8_t p[8],const uint8_t t[24],rr_receiver_rtos*c){return rr_receiver_disconnect_notice_with_ops(m,p,t,c,0);}
