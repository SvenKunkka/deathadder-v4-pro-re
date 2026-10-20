#include "mouse_work_thread.h"
static uint32_t w(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void pw(uint8_t*p,uint32_t v){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(v>>(i*8));}
static int valid(uint32_t a,unsigned n){return a>=0x23000000u&&a-0x23000000u<=65536u-n;}
static uint8_t*at(uint8_t*m,uint32_t a){return m+a-0x23000000u;}
static uint32_t lock(rr_mouse_rtos*c){uint32_t old=c->priority;if(!old||old>32)c->priority=32;return old;}
static int boundary(rr_mouse_rtos*c,uint32_t pc,uint32_t arg){c->entry=pc;c->arg0=arg;return 1;}
int rr_mouse_work_thread_step(uint8_t*m,uint8_t*r,uint8_t*a,uint32_t address,rr_mouse_rtos*c){
 if(!m||!r||!a||!c||!valid(address,0xac))return -1;c->entry=0;c->arg0=0;uint8_t*q=at(m,address);uint32_t old=lock(c),work=w(q+0x90),state;
 if(!work){state=w(q+0xa8);pw(q+0xa8,state&~4u);if(state&4u)return boundary(c,0x0e096220u,address+0xa0);return boundary(c,0x0e09628cu,0x23007670u);}
 if(!valid(work,16))return -1;uint8_t*v=at(m,work);uint32_t next=w(v);pw(q+0x90,next);if(work==w(q+0x94))pw(q+0x94,next);pw(q+0xa8,w(q+0xa8)|2u);uint32_t handler=w(v+4);pw(v+12,(w(v+12)&~4u)|1u);c->priority=old;
 if(handler!=0x23025df1u)return boundary(c,handler&~1u,work);
 int rc=rr_mouse_link_work_callback(m,r,a,c);if(rc)return rc;old=lock(c);uint32_t flags=w(v+12);
 if(flags&16u){pw(v+12,flags&~17u);rc=rr_mouse_work_semaphore_give(m,r,work+16u,c);if(rc)return rc;}else pw(v+12,flags&~1u);flags=w(v+12);
 if(flags&2u){
  pw(v+12,w(v+12)&~2u);uint32_t item=w(m+0x2548),prev=0;unsigned count=0;
  while(item){if(!valid(item,24)||++count>256)return -1;uint8_t*t=at(m,item);uint32_t n=w(t);
   if(w(t+4)==work){if(prev)pw(at(m,prev),n);else pw(m+0x2548,n);if(w(m+0x254c)==item)pw(m+0x254c,prev?prev:n);pw(t,0);rc=rr_mouse_work_semaphore_give(m,r,item+8,c);if(rc)return rc;break;}
   prev=item;item=n;
  }
 }
 state=w(q+0xa8)&~2u;pw(q+0xa8,state);c->priority=old;if(!(state&0x100u))return boundary(c,0x0e09600cu,0);return 0;
}
