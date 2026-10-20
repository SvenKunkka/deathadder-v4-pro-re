#include "receiver_config_control.h"
#include "business_tx.h"
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

static void pq(uint8_t*p,uint64_t v){pw(p,(uint32_t)v);pw(p+4,(uint32_t)(v>>32));}
static void ph(uint8_t*p,uint16_t v){p[0]=(uint8_t)v;p[1]=(uint8_t)(v>>8);}
static int unlink_thread(uint8_t*m,uint32_t a){if(!valid(a,0x90))return -1;uint8_t*t=at(m,a);uint32_t next=w(t),prev=w(t+4);if(!valid(next,8)||!valid(prev,4))return -1;pw(at(m,prev),next);pw(at(m,next)+4,prev);pw(t,0);pw(t+4,0);return 0;}
int rr_receiver_timer_start_control(uint8_t*m,uint8_t*r,uint32_t a,uint64_t duration,uint64_t period,rr_receiver_rtos*c){
 if(!m||!r||!c||!valid(a,0x38))return -1;c->entry=0;c->arg0=0;uint32_t old=lock(c);if(duration!=UINT64_MAX){uint64_t delay=duration;if(!(duration>>63))delay=duration?duration-1:0;int32_t ignored;int rc=rr_receiver_timeout_abort(m,r,a,&ignored);if(rc)return rc;pq(at(m,a)+0x28,period);pw(at(m,a)+0x30,0);rc=rr_receiver_timeout_start(m,r,a,0x0e06eb01u,delay);if(rc)return rc;}c->priority=old;return 0;
}
int rr_receiver_timer_stop_control(uint8_t*m,uint8_t*r,uint32_t a,rr_receiver_rtos*c){
 if(!m||!r||!c||!valid(a,0x38))return -1;c->entry=0;c->arg0=0;int32_t result;int rc=rr_receiver_timeout_abort(m,r,a,&result);if(rc||result)return rc;uint8_t*t=at(m,a);uint32_t cb=w(t+0x24);if(cb)return pending(c,cb&~1u,a);
 uint32_t old=lock(c),first=w(t+0x18);if(!first||first==a+0x18){c->priority=old;return 0;}if(!valid(first,0x90))return -1;rc=unlink_thread(m,first);if(rc)return rc;uint8_t*th=at(m,first);th[0xd]&=0xfdu;pw(th+8,0);c->priority=old;uint32_t oldready=lock(c);rc=ready(m,r,first);if(rc)return rc;c->priority=oldready;old=lock(c);return unlock(m,c,old);
}
int rr_receiver_thread_suspend_control(uint8_t*m,uint8_t*r,uint32_t a,rr_receiver_rtos*c){
 if(!m||!r||!c||!valid(a,0x90))return -1;c->entry=0;c->arg0=0;int32_t ignored;int rc=rr_receiver_timeout_abort(m,r,a+0x18,&ignored);if(rc)return rc;uint32_t old=lock(c);uint8_t*t=at(m,a);if(t[0xd]&16u){c->priority=old;return 0;}unsigned flags=t[0xd];t[0xd]=(uint8_t)((flags&127u)|16u);if(flags&128u){rc=unlink_thread(m,a);if(rc)return rc;}rc=schedule(m,r,1);if(rc)return rc;t[0xd]&=0x9fu;
 if(w(m+0x7170)==a&&!(c->exception_number&0x1ffu))return pending(c,0x0e0611cc,old);c->priority=old;return 0;
}
int rr_receiver_thread_resume_control(uint8_t*m,uint8_t*r,uint32_t a,rr_receiver_rtos*c){
 if(!m||!r||!c||!valid(a,0x90))return -1;c->entry=0;c->arg0=0;uint32_t old=lock(c);uint8_t*t=at(m,a);if(t[0xd]&16u){t[0xd]&=0xefu;int rc=ready(m,r,a);if(rc)return rc;return unlock(m,c,old);}c->priority=old;return 0;
}
static int radio_stop(rr_receiver_init_hw*x,rr_receiver_rtos*c){
 uint8_t*m=x->ram,*r=x->radio;int rc=rr_receiver_thread_suspend_control(m,x->rtc,0x23001fc0u,c);if(rc)return rc;ph(m+0x3232,0);
 for(unsigned i=0;i<2;i++){pw(r+0x100,0);pw(r+0x104,0);pw(r+0x110,0);ph(m+0x3252,0);pw(m+0x3468+i*0xf84,0);pw(r+0x200,0);pw(r+0x218,0);pw(r+0x220,0);pw(r+0x10,1);}
 uint32_t mask=0;for(unsigned i=0;i<8;i++)if(m[0x71c6-i]<32)mask|=1u<<m[0x71c6-i];pw(x->dppi+0x508,mask);pw(x->nvic+0x184,0x100);pw(m+0x52f0,0);pw(x->timer+4,1);pw(r+0x100,0);pw(r+0x104,0);pw(r+0x110,0);pw(r+0x10c,0);ph(m+0x3230,0);pw(r+0x10,1);return 0;
}
static int radio_start(rr_receiver_init_hw*x,rr_receiver_rtos*c){
 uint8_t*m=x->ram;ph(m+0x3232,1);int rc=rr_receiver_radio_initialize(x,w(m+0x3244),4);if(rc)return rc;m[0x3259]=1;m[0x3250]=h(m+0x323a)==1;m[0x3258]=!m[0x3250];m[0x3253]=1;m[0x33ec]=0;m[0x4370]=0;
 rc=rr_receiver_thread_resume_control(m,x->rtc,0x23001fc0u,c);if(rc)return rc;return rr_receiver_semaphore_give_timed(m,x->rtc,0x23001c54u,c);
}
static int reconnect_timers(rr_receiver_init_hw*x,rr_receiver_rtos*c){
 int rc=rr_receiver_timer_stop_control(x->ram,x->rtc,0x23001aa0u,c);if(rc)return rc;rc=rr_receiver_timer_stop_control(x->ram,x->rtc,0x23001a68u,c);if(rc)return rc;if(x->ram[0x6598]){rc=rr_receiver_timer_start_control(x->ram,x->rtc,0x23001ad8u,100000,1000,c);if(rc)return rc;}return rr_receiver_timer_start_control(x->ram,x->rtc,0x23001b10u,100000,1000000,c);
}
static int disconnect_timers(rr_receiver_init_hw*x,rr_receiver_rtos*c){
 uint8_t*m=x->ram;for(unsigned peer=0;peer<2;peer++)if(h(m+0x6590)&(1u<<peer)){uint8_t data[2]={0xa3,0};(void)rr_bt_dongle_tx(m,peer,3,data,1,0,0);}
 int rc=rr_receiver_timer_start_control(m,x->rtc,0x23001aa0u,2000000,0,c);if(rc)return rc;const uint32_t addresses[]={0x23001a68u,0x23001ad8u,0x23001b10u};for(unsigned i=0;i<3;i++){rc=rr_receiver_timer_stop_control(m,x->rtc,addresses[i],c);if(rc)return rc;}return 0;
}
int rr_receiver_config_control(rr_receiver_init_hw*x,uint32_t event,uint32_t value,uint8_t phy,const uint8_t*keytable,rr_receiver_rtos*c){
 if(!x||!c||!x->ram||!x->radio||!x->timer||!x->rtc||!x->nvic||!x->dppi)return -1;c->entry=0;c->arg0=0;uint8_t*m=x->ram;int rc;
 if(event==4){rc=radio_stop(x,c);if(rc)return rc;rc=radio_start(x,c);if(rc)return rc;ph(m+0x65e4,5);}
 else if(event==10||event==40){ph(m+0x6592,0);return reconnect_timers(x,c);}
 else if(event==41){ph(m+0x6592,0x101);ph(m+0x323a,1);rc=radio_start(x,c);if(rc)return rc;rc=rr_receiver_timer_start_control(m,x->rtc,0x23001b10u,100000,1000000,c);if(rc)return rc;ph(m+0x65e4,5);}
 else if(event==43){m[0x6592]=0;rc=disconnect_timers(x,c);if(rc)return rc;ph(m+0x323a,0);}
 else if(event==44){m[0x6592]=1;rc=reconnect_timers(x,c);if(rc)return rc;ph(m+0x323a,1);if(m[0x6593]){rc=radio_start(x,c);if(rc)return rc;ph(m+0x65e4,5);}}
 else return rr_receiver_config_event(x,event,value,phy,keytable);return 0;
}
