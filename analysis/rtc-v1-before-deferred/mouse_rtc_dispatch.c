#include "mouse_rtc_dispatch.h"
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


static uint64_t q64(const uint8_t*p){return w(p)|(uint64_t)w(p+4)<<32;}
static void pq64(uint8_t*p,uint64_t v){pw(p,(uint32_t)v);pw(p+4,(uint32_t)(v>>32));}
static uint64_t sx32(uint32_t v){return v&0x80000000u?UINT64_C(0xffffffff00000000)|v:v;}
static int slt(uint64_t a,uint64_t b){return (a^UINT64_C(0x8000000000000000))<(b^UINT64_C(0x8000000000000000));}
static int validhw(rr_mouse_scan_hw*x){return x&&x->ram&&x->radio&&x->timer&&x->rtc&&x->aux&&x->nvic&&x->clock&&x->image;}
static int pending(rr_mouse_rtos*c,rr_mouse_rtc_pending*p,uint32_t entry,uint32_t arg){c->entry=entry;c->arg0=arg;p->entry=entry;p->args[0]=arg;return 1;}
static int now(const uint8_t*r,uint64_t*out){uint32_t h=w(r+0x774);if(h>0x3fffffffu)return -4;*out=w(r+0x770)|(uint64_t)(h&0xfffffu)<<32;return 0;}
static int elapsed(uint8_t*m,uint8_t*r,uint64_t*out){uint64_t v;int rc=now(r,&v);if(rc)return rc;*out=sx32((uint32_t)((v-q64(m+0x21c0))>>5));return 0;}
static int arm(uint8_t*m,uint8_t*r,uint32_t wait){
 uint64_t v;int rc=now(r,&v);if(rc)return rc;uint64_t base=q64(m+0x21c0),due=v-base+((uint64_t)wait<<5);
 due=due<64?32:due&~UINT64_C(31);uint64_t deadline=base+due;
 unsigned ch=m[0x1304];uint32_t mask=ch<32?1u<<ch:0;
 if(!(mask&0xe080u)||!(~w(m+0x1458)&0xe080u&mask))return 0;
 unsigned slot=ch==7?0:ch-12;pw(r+0x52c+ch*16,0);memcpy(m+0x1460+slot*12,m+0x12fc,8);m[0x1468+slot*12]=(uint8_t)ch;pw(m+0x145c,w(m+0x145c)|mask);
 pw(r+0x100+ch*4,0);pw(r+0x520+ch*16,(uint32_t)deadline);pw(r+0x524+ch*16,(uint32_t)(deadline>>32)&0xfffffu);pw(r+0x354,mask);return 0;
}

static int slice_reset(uint8_t*m,uint8_t*r,uint32_t address){
 if(!valid(address,0x90))return -1;uint8_t*t=at(m,address);unsigned cpu=m[0x765c];uint32_t timeout=0x230025e0u+cpu*24u;if(!valid(timeout,0x38))return -1;int32_t original;int rc=rr_mouse_timer_abort(m,r,timeout,&original);if(rc)return rc;m[0x7674+cpu]=0;
 if(h(t+0xe)<128u&&w(m+0x767c)&&(int32_t)w(m+0x7678)<=(int8_t)t[0xe]&&!(t[0xd]&31u)&&address!=0x23002378u)return rr_mouse_timeout_start(m,r,timeout,0x0e0962f5u,sx32(w(m+0x767c)-1));return 0;
}
static int requeue_current(uint8_t*m,uint8_t*r,uint32_t address){
 if(!valid(address,0x90))return -1;uint8_t*t=at(m,address);if(t[0xd]&128u){uint32_t next=w(t),prev=w(t+4);if(!valid(next,8)||!valid(prev,4))return -1;t[0xd]&=127u;pw(at(m,prev),next);pw(at(m,next)+4,prev);pw(t,0);pw(t+4,0);}
 t[0xd]|=128u;uint32_t first=w(m+0x7668),last=w(m+0x766c);if(first==0x23007668u)first=0;unsigned count=0;int inserted=0;
 for(uint32_t n=first;n;){if(!valid(n,0x90)||++count>128)return -1;uint8_t*v=at(m,n);if((int8_t)t[0xe]<(int8_t)v[0xe]){uint32_t prev=w(v+4);if(!valid(prev,4))return -1;pw(t,n);pw(t+4,prev);pw(at(m,prev),address);pw(v+4,address);inserted=1;break;}if(n==last)break;n=w(v);}
 if(!inserted){if(!valid(last,4))return -1;pw(t,0x23007668);pw(t+4,last);pw(at(m,last),address);pw(m+0x766c,address);}
 uint32_t next=w(m+0x7668);if(!next||next==0x23007668)next=w(m+0x7658);if(next!=w(m+0x7654)){int rc=slice_reset(m,r,next);if(rc)return rc;}pw(m+0x7664,next);return 0;
}
static int slice_finish(uint8_t*m,uint8_t*r,rr_mouse_rtos*c){
 uint32_t old=lock(c),cur=w(m+0x7654);if(!valid(cur,0x90))return -1;uint8_t*t=at(m,cur);int rc=0;
 if(w(m+0x7670)!=cur){pw(m+0x7670,0);if(!m[0x7674+m[0x765c]]||h(t+0xe)>=128||!w(m+0x767c)||(int8_t)t[0xe]<(int32_t)w(m+0x7678)||(t[0xd]&31u)||cur==0x23002378u){c->priority=old;return 0;}rc=requeue_current(m,r,cur);if(rc)return rc;}
 rc=slice_reset(m,r,cur);if(rc)return rc;c->priority=old;return 0;
}
static int thread_expiry(uint8_t*m,uint8_t*r,uint32_t timeout,rr_mouse_rtos*c){
 if(timeout<BASE+0x18||!valid(timeout-0x18,0x90))return -1;uint32_t old=lock(c),address=timeout-0x18;uint8_t*t=at(m,address);
 if(t[0x6c]){t[0x6c]=0;c->priority=old;return 0;}if(t[0xd]&0x28u){c->priority=old;return 0;}
 if(w(t+8)){uint32_t next=w(t),prev=w(t+4);if(!valid(next,8)||!valid(prev,4))return -1;pw(at(m,prev),next);pw(at(m,next)+4,prev);pw(t,0);pw(t+4,0);pw(t+8,0);t[0xd]&=0xfdu;}
 t[0xd]&=(uint8_t)~0x14u;int rc=ready(m,r,address);if(rc)return rc;c->priority=old;return 0;
}
int rr_mouse_timeout_announce(rr_mouse_scan_hw*x,uint32_t ticks,rr_mouse_rtos*c,rr_mouse_rtc_pending*p){
 if(!validhw(x)||!c||!p)return -1;memset(p,0,sizeof(*p));c->entry=0;c->arg0=0;uint8_t*m=x->ram,*r=x->rtc;uint32_t old=lock(c);pw(m+0x7680,ticks);unsigned count=0;
 for(;;){uint32_t head=w(m+0x14f4);if(!head||head==0x230014f4)break;if(!valid(head,24))return -1;if(++count>4096)return -5;uint8_t*t=at(m,head);uint64_t delta=q64(t+16);
  if(slt(sx32(ticks),delta)){pq64(t+16,delta-sx32(ticks));break;}
  pq64(m+0x25f8,q64(m+0x25f8)+sx32((uint32_t)delta));pq64(t+16,0);uint32_t next=w(t),prev=w(t+4);if(!valid(next,8)||!valid(prev,4))return -1;pw(at(m,prev),next);pw(at(m,next)+4,prev);pw(t,0);pw(t+4,0);c->priority=old;
  uint32_t cb=w(t+8);int rc=0;
  if(cb==0x0e096951u)rc=rr_mouse_timer_expiry_scanning(x,head,c);
  else if(cb==0x0e0962f5u){uint32_t d=head-0x230025e0u;if(head<0x230025e0u||d%24||d/24>255)return -1;m[0x7674+d/24]=1;}
  else if(cb==0x0e0959a5u)rc=thread_expiry(m,r,head,c);
  else return pending(c,p,cb&~1u,head);
  if(rc){if(rc==1){p->entry=c->entry;p->args[0]=c->arg0;}return rc;}old=lock(c);ticks=w(m+0x7680)-(uint32_t)delta;pw(m+0x7680,ticks);
 }
 pw(m+0x7680,0);pq64(m+0x25f8,q64(m+0x25f8)+sx32(ticks));uint64_t elapsed_ticks;int rc=elapsed(m,r,&elapsed_ticks);if(rc)return rc;uint32_t head=w(m+0x14f4),wait=0x7fffffff;
 if(head&&head!=0x230014f4){if(!valid(head,24))return -1;uint64_t remaining=q64(at(m,head)+16)-elapsed_ticks;if(remaining>>63)wait=0;else if(remaining<0x80000000u)wait=(uint32_t)remaining;}
 rc=arm(m,r,wait);if(rc)return rc;c->priority=old;return slice_finish(m,r,c);
}
int rr_mouse_clock_announce(rr_mouse_scan_hw*x,uint64_t deadline,rr_mouse_rtos*c,rr_mouse_rtc_pending*p){
 if(!validhw(x)||!c||!p)return -1;memset(p,0,sizeof(*p));c->entry=0;c->arg0=0;uint64_t current;int rc=now(x->rtc,&current);if(rc)return rc;if(current<deadline)return 0;uint64_t base=q64(x->ram+0x21c0),delta=deadline-base;pq64(x->ram+0x21c0,base+(delta&~UINT64_C(31)));return rr_mouse_timeout_announce(x,(uint32_t)(delta>>5),c,p);
}
int rr_mouse_rtc_dispatch(rr_mouse_scan_hw*x,rr_mouse_rtos*c,rr_mouse_rtc_pending*p){
 if(!validhw(x)||!c||!p)return -1;memset(p,0,sizeof(*p));c->entry=0;c->arg0=0;uint8_t*m=x->ram,*r=x->rtc;uint32_t enabled=(~w(m+0x1458))&0xe080u&w(m+0x145c),fired=0;
 for(unsigned ch=0;ch<32;ch++)if((enabled&(1u<<ch))&&w(r+0x100+ch*4)){pw(r+0x100+ch*4,0);fired|=1u<<ch;}fired&=w(r+0x350);
 for(unsigned i=0;i<4;i++){uint8_t*s=m+0x1460+i*12;unsigned ch=s[8];uint32_t mask=ch<32?1u<<ch:0;if(!(mask&fired))continue;uint32_t cb=w(s);if(!cb)continue;uint32_t lo=w(r+0x520+ch*16),hi=w(r+0x524+ch*16);
  if(cb!=0x23028c09u){int rc=pending(c,p,cb&~1u,ch);p->args[1]=cb;p->args[2]=lo;p->args[3]=hi;p->args[4]=w(s+4);return rc;}
  int rc=rr_mouse_clock_announce(x,lo|(uint64_t)hi<<32,c,p);if(rc)return rc;
 }return 0;
}
