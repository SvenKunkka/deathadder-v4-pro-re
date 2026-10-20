#include "receiver_timeout.h"
#include <string.h>
#define BASE 0x23000000u
#define SENT 0x23000b48u
static uint32_t w(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static uint64_t q(const uint8_t*p){return (uint64_t)w(p)|(uint64_t)w(p+4)<<32;}
static void pw(uint8_t*p,uint32_t v){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(v>>(8*i));}
static void pq(uint8_t*p,uint64_t v){pw(p,(uint32_t)v);pw(p+4,(uint32_t)(v>>32));}
static int valid(uint32_t a,unsigned n){return a>=BASE&&a-BASE<=0x20000u-n;}
static uint8_t*at(uint8_t*m,uint32_t a){return m+a-BASE;}
static int negative(uint64_t v){return (v>>63)!=0;}
static int less(uint64_t a,uint64_t b){return (a^UINT64_C(0x8000000000000000))<(b^UINT64_C(0x8000000000000000));}
static uint64_t sx(uint32_t v){return (v&0x80000000u)?UINT64_C(0xffffffff00000000)|v:v;}
static int clock_read(uint8_t*r,uint64_t*out){uint32_t hi=w(r+0x774);if(hi>0x3fffffffu)return -4;*out=(uint64_t)w(r+0x770)|(uint64_t)(hi&0xfffffu)<<32;return 0;}
static int elapsed(uint8_t*m,uint8_t*r,uint64_t*out){uint64_t now;int rc=clock_read(r,&now);if(rc)return rc;*out=sx((uint32_t)(now-q(m+0x2840)));return 0;}
static uint32_t wait_value(uint64_t delta){return negative(delta)?0:delta>0x7fffffffu?0x7fffffffu:(uint32_t)delta;}
static int arm(uint8_t*m,uint8_t*r,uint32_t wait){
 uint64_t now;int rc=clock_read(r,&now);if(rc)return rc;
 uint64_t base=q(m+0x2840),due=now-base+wait;if(!due)due=1;uint64_t deadline=base+due;
 unsigned ch=m[0x960];uint32_t mask=ch<32?1u<<ch:0;
 if(!(mask&0xe080u)||!(~w(m+0xab4)&0xe080u&mask))return 0;
 unsigned slot=ch==7?0:ch==13?1:ch==14?2:3;
 pw(r+0x52c+16*ch,0);memcpy(m+0xabc+12*slot,m+0x958,8);m[0xac4+12*slot]=(uint8_t)ch;pw(m+0xab8,w(m+0xab8)|mask);
 pw(r+0x100+4*ch,0);pw(r+0x520+16*ch,(uint32_t)deadline);pw(r+0x524+16*ch,(uint32_t)(deadline>>32)&0xfffffu);pw(r+0x354,mask);return 0;
}
static int head_rearm(uint8_t*m,uint8_t*r){
 uint64_t e=0;if(!w(m+0x7198)){int rc=elapsed(m,r,&e);if(rc)return rc;}
 uint32_t first=w(m+0xb48),wait=0x7fffffffu;
 if(first&&first!=SENT){if(!valid(first,24))return -1;wait=wait_value(q(at(m,first)+0x10)-e);}
 return arm(m,r,wait);
}
int rr_receiver_timeout_abort(uint8_t*m,uint8_t*r,uint32_t address,int32_t*result){
 if(!m||!r||!result||!valid(address,24))return -1;uint8_t*t=at(m,address);uint32_t first=w(m+0xb48),next=w(t),prev=w(t+4);
 if(!next){*result=-22;return 0;}if(!valid(next,8)||!valid(prev,4))return -1;
 if(w(m+0xb4c)!=address){if(!valid(next,24))return -1;pq(at(m,next)+0x10,q(at(m,next)+0x10)+q(t+0x10));}
 pw(at(m,prev),next);pw(at(m,next)+4,prev);pw(t,0);pw(t+4,0);
 if(first!=SENT&&first==address){int rc=head_rearm(m,r);if(rc)return rc;}*result=0;return 0;
}
int rr_receiver_timeout_start(uint8_t*m,uint8_t*r,uint32_t address,uint32_t callback,uint64_t delay){
 if(!m||!r||!valid(address,24))return -1;if(delay==UINT64_MAX)return 0;uint8_t*t=at(m,address);pw(t+8,callback);uint64_t delta;
 if(!negative(delay)){delta=delay+1;if(!w(m+0x7198)){uint64_t e;int rc=elapsed(m,r,&e);if(rc)return rc;delta+=e;}}
 else{delta=UINT64_C(0xfffffffffffffffe)-q(m+0x2c78)-delay;if(negative(delta)||!delta)delta=1;}
 pq(t+0x10,delta);uint32_t first=w(m+0xb48),last=w(m+0xb4c);if(first==SENT)first=0;int inserted=0;
 unsigned bound=0;for(uint32_t i=first;i;){
  if(!valid(i,24)||++bound>128)return -1;uint8_t*v=at(m,i);uint64_t d=q(v+0x10);
  if(less(delta,d)){uint32_t prev=w(v+4);if(!valid(prev,4))return -1;pq(v+0x10,d-delta);pw(t,i);pw(t+4,prev);pw(at(m,prev),address);pw(v+4,address);inserted=1;break;}
  delta-=d;pq(t+0x10,delta);if(i==last)break;i=w(v);
 }
 if(!inserted){if(!valid(last,4))return -1;pw(t,SENT);pw(t+4,last);pw(at(m,last),address);pw(m+0xb4c,address);}
 if(w(m+0xb48)==address&&!w(m+0x7198)){uint64_t e;int rc=elapsed(m,r,&e);if(rc)return rc;return arm(m,r,wait_value(q(t+0x10)-e));}
 return 0;
}
typedef struct{uint8_t*m,*r;} time_context;
static int abort_op(void*p,uint32_t a){time_context*c=p;int32_t result;return rr_receiver_timeout_abort(c->m,c->r,a,&result);}
static int start_op(void*p,uint32_t a,uint32_t cb,uint64_t d){time_context*c=p;return rr_receiver_timeout_start(c->m,c->r,a,cb,d);}
int rr_receiver_semaphore_give_timed(uint8_t*m,uint8_t*r,uint32_t a,rr_receiver_rtos*c){time_context ctx={m,r};rr_receiver_rtos_ops ops={&ctx,abort_op,start_op};return rr_receiver_semaphore_give_with_ops(m,a,c,&ops);}
int rr_receiver_message_put_timed(uint8_t*m,uint8_t*r,uint32_t a,const uint8_t b[36],rr_receiver_rtos*c,int32_t*v){time_context ctx={m,r};rr_receiver_rtos_ops ops={&ctx,abort_op,start_op};return rr_receiver_message_put_with_ops(m,a,b,c,v,&ops);}
int rr_receiver_message_purge_timed(uint8_t*m,uint8_t*r,uint32_t a,rr_receiver_rtos*c){time_context ctx={m,r};rr_receiver_rtos_ops ops={&ctx,abort_op,start_op};return rr_receiver_message_purge_with_ops(m,a,c,&ops);}
int rr_receiver_disconnect_notice_timed(uint8_t*m,uint8_t*r,const uint8_t p[8],const uint8_t t[24],rr_receiver_rtos*c){time_context ctx={m,r};rr_receiver_rtos_ops ops={&ctx,abort_op,start_op};return rr_receiver_disconnect_notice_with_ops(m,p,t,c,&ops);}
int rr_receiver_timer_mode4_lifecycle_timed(uint8_t*m,const uint8_t*f,rr_receiver_radio_hw*h,uint8_t*r,rr_receiver_rtos*c,const uint8_t tail[24]){
 if(!m||!f||!h||!r||!c||!tail)return -1;c->entry=0;c->arg0=0;rr_receiver_timer_pending p;int rc=rr_receiver_timer_mode4(m,f,h,&p);if(rc!=1)return rc;
 rc=rr_receiver_semaphore_give_timed(m,r,p.arg0,c);if(rc)return rc;uint8_t pair[8];pw(pair,0);memcpy(pair+4,m+0x33f2,4);return rr_receiver_disconnect_notice_timed(m,r,pair,tail,c);
}
