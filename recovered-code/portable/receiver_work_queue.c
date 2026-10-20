#include "receiver_work_queue.h"
#include "receiver_periodic_service.h"
#include <string.h>
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

static int wake(uint8_t*m,uint8_t*r,uint32_t queue){
 if(!valid(queue,8))return -1;uint32_t first=w(at(m,queue));if(!first||first==queue)return 0;
 if(!valid(first,0x90))return -1;uint8_t*t=at(m,first);uint32_t next=w(t),prev=w(t+4);if(!valid(next,8)||!valid(prev,4))return -1;
 pw(t+0x14,0);pw(t+0x8c,0);pw(at(m,prev),next);pw(at(m,next)+4,prev);pw(t+8,0);t[0xd]&=0xfdu;pw(t,0);pw(t+4,0);
 int32_t result;int rc=rr_receiver_timeout_abort(m,r,first+0x18,&result);if(rc)return rc;return ready(m,r,first);
}
int rr_receiver_work_submit_to_queue(uint8_t*m,uint8_t*r,uint32_t address,uint32_t*q,rr_receiver_rtos*c,int32_t*result){
 if(!m||!r||!q||!c||!result||!valid(address,16))return -1;uint8_t*work=at(m,address);uint32_t flags=w(work+12);int32_t value=0;
 if(flags&2u)value=-16;else if(flags&4u)value=0;else{
  uint32_t queue=*q;if(!queue){queue=w(work+8);*q=queue;}
  unsigned outcome=1;if(flags&1u){queue=w(work+8);*q=queue;outcome=2;}
  if(!queue)value=-22;else{
   if(!valid(queue,0xac))return -1;uint8_t*t=at(m,queue);uint32_t state=w(t+0xa8);
   if(!(state&1u))value=-19;else{
    int self_thread=queue==w(m+0x7170)&&!(c->exception_number&0x1ffu);int allowed=self_thread?(!(state&8u)||(state&4u)):!(state&12u);
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
int rr_receiver_work_submit(uint8_t*m,uint8_t*r,uint32_t address,uint32_t queue,rr_receiver_rtos*c,int32_t*result){
 if(!m||!r||!c||!result)return -1;c->entry=0;c->arg0=0;uint32_t old=lock(c);int rc=rr_receiver_work_submit_to_queue(m,r,address,&queue,c,result);if(rc)return rc;c->priority=old;
 if(*result>0){old=lock(c);if(!old&&!(c->exception_number&0x1ffu)&&w(m+0x717c)!=w(m+0x7170)){c->entry=0x0e0611cc;c->arg0=0;return 1;}c->priority=old;}return 0;
}
int rr_receiver_delayed_work_schedule(uint8_t*m,uint8_t*r,uint32_t queue,uint32_t work,uint64_t delay,int reschedule,rr_receiver_rtos*c,int32_t*result){
 if(!m||!r||!c||!result||!valid(work,44))return -1;c->entry=0;c->arg0=0;uint32_t old=lock(c);uint8_t*t=at(m,work);uint32_t flags=w(t+12);int rc;
 if(reschedule){pw(t+12,flags&~8u);if(flags&8u){int32_t ignored;rc=rr_receiver_timeout_abort(m,r,work+16,&ignored);if(rc)return rc;}}
 else if(flags&0x1eu){*result=0;c->priority=old;return 0;}
 if(!delay){rc=rr_receiver_work_submit_to_queue(m,r,work,&queue,c,result);if(rc)return rc;}
 else{pw(t+12,w(t+12)|8u);pw(t+40,queue);rc=rr_receiver_timeout_start(m,r,work+16,0x0e06d3a5u,delay);if(rc)return rc;*result=1;}
 c->priority=old;return 0;
}
int rr_receiver_delayed_work_expiry(uint8_t*m,uint8_t*r,uint32_t timeout,rr_receiver_rtos*c){
 if(!m||!r||!c||timeout<BASE+16u||!valid(timeout-16u,44))return -1;c->entry=0;c->arg0=0;uint8_t*work=at(m,timeout-16u);uint32_t old=lock(c),flags=w(work+12);pw(work+12,flags&~8u);
 if(flags&8u){uint32_t queue=w(work+40);int32_t ignored;int rc=rr_receiver_work_submit_to_queue(m,r,timeout-16u,&queue,c,&ignored);if(rc)return rc;}c->priority=old;return 0;
}

int rr_receiver_work_initialize(uint8_t*m,uint32_t address,uint32_t callback,int delayed){
 unsigned size=delayed?48u:16u;if(!m||!valid(address,size))return -1;uint8_t*t=at(m,address);memset(t,0,size);pw(t+4,callback);if(delayed)pw(t+12,0x100);return 0;
}
int rr_receiver_work_cancel(uint8_t*m,uint32_t address,rr_receiver_rtos*c,uint32_t*result){
 if(!m||!c||!result||!valid(address,16))return -1;c->entry=0;c->arg0=0;uint32_t old=lock(c);uint8_t*t=at(m,address);uint32_t flags=w(t+12);
 if(!(flags&2u)){
  pw(t+12,flags&~4u);if(flags&4u){uint32_t queue=w(t+8);if(!valid(queue,0xac))return -1;uint8_t*q=at(m,queue);uint32_t head=w(q+0x90),prev=0,atnode=head;unsigned count=0;
   while(atnode&&atnode!=address){if(!valid(atnode,4)||++count>128)return -1;prev=atnode;atnode=w(at(m,atnode));}
   if(atnode){uint32_t next=w(t);if(prev)pw(at(m,prev),next);else pw(q+0x90,next);if(w(q+0x94)==address)pw(q+0x94,prev?prev:next);pw(t,0);}
  }flags=w(t+12);
 }
 uint32_t out=flags&31u;if(out){pw(t+12,flags|2u);out|=2u;}c->priority=old;*result=out;return 0;
}
typedef struct {rr_receiver_init_hw*x;const uint8_t*f,*tail;} work_context;
static int work_user(uint32_t address,uint32_t cb,rr_receiver_rtos*c,void*user){
 work_context*k=user;uint32_t e=cb&~1u;
 if(e==0x230255d0u||e==0x230255f8u||e==0x23025640u||e==0x230256e8u)return rr_receiver_application_timer(k->x,k->f,e,k->tail,c);
 c->entry=e;c->arg0=address;return 1;
}
static int work_timeout(rr_receiver_rtc_hw*x,uint32_t address,uint32_t cb,rr_receiver_rtos*c,void*user){
 work_context*k=user;if(cb==0xe06d3a5u)return rr_receiver_delayed_work_expiry(x->ram,x->rtc,address,c);if(cb==0xe06eb01u)return rr_receiver_timer_expiry_with_handler(x->ram,x->rtc,k->f,address,c,work_user,user);
 c->entry=cb&~1u;c->arg0=address;return 1;
}
static int work_dispatch(uint8_t*m,uint8_t*r,uint8_t*s,const uint8_t*f,rr_receiver_rtos*c,rr_receiver_rtc_pending*p,work_context*k){
 if(!m||!r||!s||!f||!c||!p)return -1;memset(p,0,sizeof(*p));c->entry=0;c->arg0=0;
 uint32_t enabled=~w(m+0xab4)&0xe080u&w(m+0xab8),fired=0;
 for(unsigned ch=0;ch<32;ch++)if((enabled&(1u<<ch))&&w(r+0x100+ch*4)){pw(r+0x100+ch*4,0);fired|=1u<<ch;}fired&=w(r+0x350);
 for(unsigned i=0;i<4;i++){uint8_t*t=m+0xabc+12*i;unsigned ch=t[8];uint32_t bit=ch<32?1u<<ch:0;if(!(fired&bit))continue;uint32_t cb=w(t);if(!cb)continue;uint32_t lo=w(r+0x520+ch*16),hi=w(r+0x524+ch*16);
  int rc;if(cb==0xe05bde1u){uint32_t result;rc=rr_receiver_periodic_refresh(m,r,s,&result);}
  else if(cb==0xe0683a1u){rr_receiver_rtc_hw x={m,r};rc=k?rr_receiver_clock_announce_with_handler(&x,lo|(uint64_t)hi<<32,c,p,work_timeout,k):rr_receiver_clock_announce_timers(&x,f,lo|(uint64_t)hi<<32,c,p);}
  else{c->entry=p->entry=cb&~1u;c->arg0=p->args[0]=ch;p->args[1]=cb;p->args[2]=lo;p->args[3]=hi;p->args[4]=w(t+4);return 1;}
  if(rc)return rc;
 }return 0;
}

int rr_receiver_rtc_work_dispatch(rr_receiver_init_hw*x,uint8_t*s,const uint8_t*f,const uint8_t tail[32],rr_receiver_rtos*c,rr_receiver_rtc_pending*p){if(!x||!tail)return -1;work_context k={x,f,tail};return work_dispatch(x->ram,x->rtc,s,f,c,p,&k);}
