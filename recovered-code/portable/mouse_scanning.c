#include "mouse_scanning.h"
#include "mouse_timer_start.h"
#include "mouse_timer_lifecycle.h"
#include "business_tx.h"
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


static void ph(uint8_t*p,uint16_t v){p[0]=(uint8_t)v;p[1]=(uint8_t)(v>>8);}
static int hwvalid(const rr_mouse_scan_hw*x){return x&&x->ram&&x->radio&&x->timer&&x->rtc&&x->aux&&x->nvic&&x->clock&&x->image;}
static void timer_clear_config(uint8_t*t){for(unsigned i=0;i<8;i++)pw(t+0x540+4*i,0);pw(t+0x200,1);pw(t+0x304,0x7f0000);pw(t+0x308,0x800000);}
static void action(uint8_t*m,uint8_t*r,uint32_t state,unsigned task){pw(m+0x2a04,state);pw(r+0x200,0);pw(r+0x218,0);pw(r+0x220,0);pw(r+task,1);}
static void reset_scan(uint8_t*m,uint8_t*t){pw(m+0x2a04,19);pw(t+0x558,0);ph(m+0x2a4a,0);ph(m+0x2a52,0);pw(t+4,1);pw(t+12,1);timer_clear_config(t);}
int rr_mouse_scan_start(rr_mouse_scan_hw*x,rr_mouse_rtos*c){
 if(!hwvalid(x)||!c)return -1;c->entry=0;c->arg0=0;uint8_t*m=x->ram,*t=x->timer,*n=x->nvic;
 pw(m+0x2998,1000);pw(m+0x298c,0);pw(m+0x2990,0);pw(m+0x2a04,19);ph(m+0x2a4a,0);ph(m+0x2844,h(m+0x2842));pw(m+0x2978,2);ph(m+0x2794,2);
 pw(t+0x8c,0x80000000u|m[0x76ef]);pw(n+0x184,0x100);pw(n+0x284,0x100);pw(t+12,1);pw(n+0x104,0x100);
 uint32_t old=lock(c);int rc=rr_mouse_timer_start(m,x->rtc,0x23001540u,32,32);if(rc)return rc;c->priority=old;return 0;
}
int rr_mouse_scan_work(rr_mouse_scan_hw*x,rr_mouse_rtos*c){
 if(!hwvalid(x)||!c)return -1;c->entry=0;c->arg0=0;uint8_t*m=x->ram,*r=x->radio;
 if(!m[0x27bb]){if(!m[0x297c])return 0;m[0x297c]=0;}else{m[0x27bb]=0;pw(m+0x2a04,0);ph(m+0x2a4e,0);pw(m+0x2a1a,0);}
 pw(m+0x2978,0);ph(m+0x2794,0);pw(r+0x500,4);uint32_t v=w(r+0x8a0);if(v==0x80000000u||v==0x58120eu)pw(r+0x8a0,0x58090e);
 pw(r+0x8a4,0xf8aa5f);pw(r+0x8a8,0xc00030);pw(r+0x8ac,0xa80030);pw(r+0x7ac,0x8672827a);pw(r+0x7b0,0x7e768672);pw(r+0x7b4,0x0406007e);pw(r+0x7e4,0x0412c384);timer_clear_config(x->timer);return rr_mouse_scan_start(x,c);
}
int rr_mouse_scan_advance(rr_mouse_scan_hw*x){
 if(!hwvalid(x))return -1;uint8_t*m=x->ram,*r=x->radio,*t=x->timer;uint16_t dwell=(uint16_t)(h(m+0x2a4e)+1);ph(m+0x2a4e,dwell);
 if(dwell==1){unsigned i=h(m+0x2a4c);if(i>=4)return -1;unsigned channel=x->image[0x2ca3c+i];pw(r+0x708,x->image[0x2ca14+channel]);pw(r+0xed0,0x23002a56);action(m,r,20,4);pw(t+12,1);pw(t,1);}
 else if(dwell>7){ph(m+0x2a4e,0);uint16_t i=(uint16_t)(h(m+0x2a4c)+1);if(i>=4)i=0;ph(m+0x2a4c,i);action(m,r,19,16);}return 0;
}
static int stop1540(rr_mouse_scan_hw*x,rr_mouse_rtos*c){uint32_t old=lock(c);int rc=rr_mouse_timer_stop(x->ram,x->rtc,0x23001540);if(rc==-4)return rc;c->priority=old;return rc;}
static void discovery_radio(rr_mouse_scan_hw*x){
 uint8_t*m=x->ram,*r=x->radio,*n=x->nvic;pw(n+0x184,0x1000);pw(r+0x10,1);pw(r+0x704,1);pw(r+0xe3c,1);pw(r+0xe40,10);pw(r+0xe34,0xc3c2c1e7);pw(r+0xe38,0xc7c6c5c4);pw(r+0xe2c,0xeb8a542c);pw(r+0xe30,w(m+0x27ac));pw(r+0x500,4);pw(r+0x710,0x18);
 ph(m+0x261b,0x101);memset(m+0x2610,0,10);m[0x261a]=3;m[0x2610]=5;m[0x2618]=31;m[0x2615]=1;m[0x2625]=1;m[0x262c]=1;pw(r+0xe20,0x1000005);pw(r+0xe28,0x303001f);ph(m+0x2620,5);m[0x2622]=0;pw(r+0xe44,0x102);pw(r+0xe48,0x11021);pw(r+0xe4c,0xffff);pw(r+0x400,w(r+0x400)|0x80001);pw(m+0x2628,0x102001f);pw(r+0x488,0x108);
 pw(r+0x20c,0);pw(r+0x200,0);pw(r+0x218,0);pw(r+0x220,0);n[0x42c]=0;pw(n+0x284,0x1000);pw(n+0x104,0x1000);
}
int rr_mouse_scan_tick(rr_mouse_scan_hw*x,rr_mouse_rtos*c){
 if(!hwvalid(x)||!c)return -1;c->entry=0;c->arg0=0;uint8_t*m=x->ram,*r=x->radio,*t=x->timer;uint32_t state=w(m+0x2a04);int rc;
 if(state==19){pw(r+0x20c,0);timer_clear_config(t);pw(t+12,1);pw(t,1);pw(t+0x8c,0x80000000u|m[0x76ef]);rc=rr_mouse_scan_advance(x);if(rc)return rc;}
 else if(state==20){uint16_t wait=h(m+0x2a50);if(wait){wait--;ph(m+0x2a50,wait);if(!wait)reset_scan(m,t);else{rc=rr_mouse_scan_advance(x);if(rc)return rc;}}else{rc=rr_mouse_scan_advance(x);if(rc)return rc;}}
 else if(state==22||state==23){uint16_t retry=(uint16_t)(h(m+0x2a52)+1);ph(m+0x2a52,retry);if(retry>4)reset_scan(m,t);}
 uint32_t remaining=w(m+0x2998)-1;if(remaining)pw(m+0x2998,remaining);else{
  pw(r+16,1);pw(m+0x2998,1000);pw(t+0x8c,0);rc=stop1540(x,c);if(rc)return rc;rc=stop1540(x,c);if(rc)return rc;
  uint32_t old=lock(c);rc=rr_mouse_disconnect(m,r,t,x->rtc,x->clock,0);if(rc==-4)return rc;c->priority=old;if(rc)return rc;
  if(h(m+0x2796)!=1){ph(m+0x2796,1);discovery_radio(x);rr_bt_init(m,1,0);m[0x27bb]=1;int32_t result;rc=rr_mouse_work_submit(m,x->rtc,0x23003858,c,&result);if(rc)return rc;}
 }
 if(m[0x774b]){pw(x->aux+12,1);pw(x->aux,1);}return 0;
}
int rr_mouse_timer_expiry_scanning(rr_mouse_scan_hw*x,uint32_t address,rr_mouse_rtos*c){
 if(!hwvalid(x)||!c)return -1;int rc=rr_mouse_timer_expiry(x->ram,x->rtc,address,c);if(rc!=1||c->entry!=0x23022310u)return rc;
 rc=rr_mouse_scan_tick(x,c);if(rc)return rc;uint8_t*m=x->ram,*t=at(m,address);uint32_t old=lock(c),waiter=w(t+0x18);
 if(waiter&&waiter!=address+0x18){if(!valid(waiter,0x90))return -1;uint8_t*v=at(m,waiter);if(w(v+8)){uint32_t next=w(v),prev=w(v+4);if(!valid(next,8)||!valid(prev,4))return -1;pw(at(m,prev),next);pw(at(m,next)+4,prev);pw(v,0);pw(v+4,0);v[0xd]&=0xfdu;pw(v+8,0);}pw(v+0x8c,0);c->priority=old;uint32_t oldready=lock(c);rc=ready(m,x->rtc,waiter);if(rc)return rc;c->priority=oldready;return 0;}c->priority=old;return 0;
}
static int bound(rr_mouse_rtos*c,uint32_t entry,uint32_t arg0){c->entry=entry;c->arg0=arg0;return 1;}
int rr_mouse_work_thread_scanning(rr_mouse_scan_hw*x,uint32_t address,rr_mouse_rtos*c){
 if(!hwvalid(x)||!c)return -1;uint8_t*m=x->ram;int rc=rr_mouse_work_thread_step(m,x->rtc,x->aux,address,c);if(rc!=1||c->entry!=0x23022620u)return rc;
 uint32_t work=c->arg0;rc=rr_mouse_scan_work(x,c);if(rc)return rc;uint8_t*q=at(m,address),*v=at(m,work);uint32_t old=lock(c),flags=w(v+12);
 if(flags&16u){pw(v+12,flags&~17u);rc=rr_mouse_work_semaphore_give(m,x->rtc,work+16u,c);if(rc)return rc;}else pw(v+12,flags&~1u);flags=w(v+12);
 if(flags&2u){pw(v+12,flags&~2u);uint32_t item=w(m+0x2548),prev=0;unsigned count=0;while(item){if(!valid(item,24)||++count>256)return -1;uint8_t*z=at(m,item);uint32_t next=w(z);if(w(z+4)==work){if(prev)pw(at(m,prev),next);else pw(m+0x2548,next);if(w(m+0x254c)==item)pw(m+0x254c,prev?prev:next);pw(z,0);rc=rr_mouse_work_semaphore_give(m,x->rtc,item+8,c);if(rc)return rc;break;}prev=item;item=next;}}
 uint32_t state=w(q+0xa8)&~2u;pw(q+0xa8,state);c->priority=old;if(!(state&0x100u))return bound(c,0x0e09600c,0);return 0;
}
