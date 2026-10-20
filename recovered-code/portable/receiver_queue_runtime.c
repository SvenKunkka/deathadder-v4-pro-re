#include "receiver_queue_runtime.h"
#include <string.h>
static uint16_t h(const uint8_t*p){return (uint16_t)(p[0]|p[1]<<8);}
static uint32_t w(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void pw(uint8_t*p,uint32_t x){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(x>>(8*i));}
static int valid(uint32_t a,unsigned len){return a>=0x23000000u&&a-0x23000000u<=0x20000u-len;}
static uint8_t*at(uint8_t*m,uint32_t a){return m+a-0x23000000u;}
static uint32_t lock(rr_receiver_rtos*c){uint32_t old=c->priority;if(!old||old>0x40)c->priority=0x40;return old;}
static int pending(rr_receiver_rtos*c,uint32_t entry,uint32_t arg){c->entry=entry;c->arg0=arg;return 1;}
static int unlock(uint8_t*m,rr_receiver_rtos*c,uint32_t old){
 if(!old&&!(c->exception_number&0x1ffu)&&w(m+0x717c)!=w(m+0x7170))return pending(c,0x0e0611cc,0);
 c->priority=old;return 0;
}
static int schedule(uint8_t*m,uint8_t*rtc,int force){
 uint32_t next=w(m+0x7180),cur=w(m+0x7170);if(!next||next==0x23007180u)next=w(m+0x7174);
 if(!valid(cur,0x90)||!valid(next,0x90))return -1;uint8_t*t=at(m,next),*current=at(m,cur);
 if(!force&&!(current[0xd]&31u)&&!w(t+0x18)&&h(current+0xe)>=128u)next=cur;
 if(next!=cur){
  t=at(m,next);unsigned cpu=m[0x7178];uint32_t timeout=0x23002c60u+cpu*24u;if(!valid(timeout,24))return -1;
  if(w(at(m,timeout))){int32_t ignored;int rc=rr_receiver_timeout_abort(m,rtc,timeout,&ignored);if(rc)return rc;}
  m[0x718c+cpu]=0;
  if(h(t+0xe)<128u&&w(m+0x7194)&&(int32_t)w(m+0x7190)<=(int8_t)t[0xe]&&!(t[0xd]&31u)&&next!=0x230029f8u){uint32_t d=w(m+0x7194)-1;uint64_t delay=(d&0x80000000u)?UINT64_C(0xffffffff00000000)|d:d;int rc=rr_receiver_timeout_start(m,rtc,timeout,0x0e06e4c9,delay);if(rc)return rc;}
 }
 pw(m+0x717c,next);return 0;
}
static int ready(uint8_t*m,uint8_t*rtc,uint32_t address){
 uint8_t*t=at(m,address);if((t[0xd]&0x9fu)||w(t+0x18))return 0;t[0xd]|=0x80u;
 uint32_t first=w(m+0x7180),last=w(m+0x7184);if(first==0x23007180u)first=0;
 unsigned bound=0;for(uint32_t i=first;i;){
  if(!valid(i,0x90)||++bound>128)return -1;uint8_t*v=at(m,i);
  if((int8_t)t[0xe]<(int8_t)v[0xe]){uint32_t prev=w(v+4);if(!valid(prev,4))return -1;pw(t,i);pw(t+4,prev);pw(at(m,prev),address);pw(v+4,address);return schedule(m,rtc,0);}
  if(i==last)break;i=w(v);
 }
 if(!valid(last,4))return -1;pw(t,0x23007180);pw(t+4,last);pw(at(m,last),address);pw(m+0x7184,address);return schedule(m,rtc,0);
}

static int unlink_thread(uint8_t*m,uint32_t a){if(!valid(a,0x90))return -1;uint8_t*t=at(m,a);uint32_t next=w(t),prev=w(t+4);if(!valid(next,8)||!valid(prev,4))return -1;pw(at(m,prev),next);pw(at(m,next)+4,prev);pw(t,0);pw(t+4,0);return 0;}

/* The queue API is specialized to the two observed 36-byte control queues.
 * output_address preserves the machine pointer used by a blocked reader.
 * If it refers into RAM, output must alias that exact RAM window. */
static int enqueue_waiter(uint8_t*m,uint32_t q,uint32_t address){
 uint8_t*t=at(m,address);pw(t+8,q);uint32_t first=w(at(m,q)),last=w(at(m,q)+4);if(first==q)first=0;
 for(unsigned bound=0;first;){if(!valid(first,0x90)||++bound>128)return -1;uint8_t*v=at(m,first);if((int8_t)t[0xe]<(int8_t)v[0xe]){uint32_t prev=w(v+4);if(!valid(prev,4))return -1;pw(t,first);pw(t+4,prev);pw(at(m,prev),address);pw(v+4,address);return 0;}if(first==last)break;first=w(v);}
 if(!valid(last,4))return -1;pw(t,q);pw(t+4,last);pw(at(m,last),address);pw(at(m,q)+4,address);return 0;
}
int rr_receiver_message_get(uint8_t*m,uint8_t*r,uint32_t address,uint32_t output_address,uint8_t output[36],uint64_t timeout,rr_receiver_rtos*c,int32_t*result){
 if(!m||!r||!c||!output||!result||!valid(address,40))return -1;c->entry=0;c->arg0=0;uint8_t*q=at(m,address);if(w(q+8)!=36)return -1;uint32_t old=lock(c);
 if(!w(q+0x20)){
  if(!timeout){*result=-35;c->priority=old;return 0;}
  uint32_t cur=w(m+0x7170);if(!valid(cur,0x90))return -1;uint8_t*t=at(m,cur);pw(t+0x14,output_address);pw(m+0x7188,cur);(void)lock(c);
  if(t[0xd]&128u){t[0xd]&=127u;int rc=unlink_thread(m,cur);if(rc)return rc;}
  int rc=schedule(m,r,1);if(rc)return rc;t[0xd]|=2u;rc=enqueue_waiter(m,address,cur);if(rc)return rc;
  if(timeout!=UINT64_MAX){rc=rr_receiver_timeout_start(m,r,cur+0x18,0x0e06daf5u,timeout);if(rc)return rc;}
  return pending(c,0x0e0611cc,old);
 }
 uint32_t src=w(q+0x18);if(!valid(src,36))return -1;memcpy(output,at(m,src),36);src+=36;if(src==w(q+0x14))src=w(q+0x10);pw(q+0x18,src);pw(q+0x20,w(q+0x20)-1);
 uint32_t first=w(q);if(!first||first==address){*result=0;c->priority=old;return 0;}
 if(!valid(first,0x90))return -1;int rc=unlink_thread(m,first);if(rc)return rc;uint8_t*t=at(m,first);t[0xd]&=0xfdu;pw(t+8,0);int32_t ignored;rc=rr_receiver_timeout_abort(m,r,first+0x18,&ignored);if(rc)return rc;
 uint32_t dest=w(q+0x1c);src=w(t+0x14);if(!valid(dest,36)||!valid(src,36))return -1;memcpy(at(m,dest),at(m,src),36);dest+=36;if(dest==w(q+0x14))dest=w(q+0x10);pw(q+0x1c,dest);pw(q+0x20,w(q+0x20)+1);pw(t+0x8c,0);rc=ready(m,r,first);if(rc)return rc;rc=unlock(m,c,old);if(rc)return rc;*result=0;return 0;
}
int rr_receiver_config_iteration(rr_receiver_init_hw*x,uint32_t message_address,uint8_t message[36],uint8_t phy,const uint8_t*keytable,rr_receiver_rtos*c){
 if(!x)return -1;int32_t result;int rc=rr_receiver_message_get(x->ram,x->rtc,0x23001bb4u,message_address,message,UINT64_MAX,c,&result);if(rc)return rc;if(result)return -2;
 return rr_receiver_config_control(x,w(message),w(message+4),phy,keytable,c);
}
