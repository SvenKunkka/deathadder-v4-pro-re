#include "mouse_mode4_lifecycle.h"
#include "mouse_mode4_radio.h"
#include "mouse_timer_lifecycle.h"
#include <string.h>
static uint32_t w(const uint8_t*p){return p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static unsigned h(const uint8_t*p){return p[0]|(unsigned)p[1]<<8;}
static void ph(uint8_t*p,unsigned v){p[0]=(uint8_t)v;p[1]=(uint8_t)(v>>8);}
static void pw(uint8_t*p,uint32_t v){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(v>>(8*i));}
struct context{uint8_t *m,*r,*t,*rtc;uint32_t*c;rr_mouse_mode4_pending*p;};
static int ack(void*opaque,uint16_t cls){struct context*x=opaque;return rr_mouse_ack_callback(x->m,x->r,x->t,x->rtc,x->c,cls);}
static int timeout(void*opaque){
 struct context*x=opaque;uint8_t*m=x->m,*r=x->r,*t=x->t;
 pw(m+0x2a04,0);pw(r+0x200,0);pw(r+0x218,0);pw(r+0x220,0);pw(r+0x10,1);
 pw(r+0x100,0);pw(r+0x108,0);pw(r+0x104,0);pw(r+0x110,0);pw(t+0xdc,0);pw(t+0x558,0);pw(t+4,1);
 ph(m+0x2794,0);pw(m+0x2978,0);
 /*23022c3c resets only queue0 indices and restores mode2 radio config. */
 m[0x2ad6]=0;m[0x2adc]=0;pw(r+0x400,0x80001);pw(r+0x490,0xffffffffu);pw(r+0x488,0x100);pw(r+0xe34,0xc3c2c1e7u);
 const uint8_t*c=m+0x2610;
 pw(r+0xe20,c[0]|(uint32_t)c[1]<<8|(uint32_t)c[2]<<16|(uint32_t)c[3]<<20|(uint32_t)c[4]<<22|(uint32_t)c[5]<<24|(uint32_t)c[6]<<26|(uint32_t)c[7]<<29);
 pw(r+0xe28,c[8]|(uint32_t)c[9]<<8|(uint32_t)c[10]<<16|(uint32_t)c[11]<<24|(uint32_t)c[12]<<25);
 ph(m+0x2798,2);pw(r+0x500,4);uint32_t v=w(r+0x8a0);if(v==0x80000000u||v==0x58120eu)pw(r+0x8a0,0x58090e);
 pw(r+0x8a4,0xf8aa5f);pw(r+0x8a8,0xc00030);pw(r+0x8ac,0xa80030);pw(r+0x7ac,0x8672827a);pw(r+0x7b0,0x7e768672);pw(r+0x7b4,0x0406007e);pw(r+0x7e4,0x0412c384);
 /*23022f5c marks connection state then real work-submit, NOT semaphore. */
 m[0x297c]=1;x->p->active=1;
 if(!(w(m+0x3864)&6u)){x->p->entry=0x0e0952ec;x->p->args[0]=0x23003858;return 1;}
 /* Flags2/4 execute original natural -16/0 work fast-return. Then the caller
  * writes a zero stack word, and23025ed4 stores its upper16 into6B82. */
 ph(m+0x6b82,0);x->p->entry=0x0e096a50;x->p->args[0]=0x23001578;x->p->args[1]=0;x->p->args[2]=(h(m+0x6b80)*31250u+999u)/1000u;x->p->args[3]=0;return 1;
}
int rr_mouse_mode4_radio_lifecycle(uint8_t*m,uint8_t*r,uint8_t*t,uint8_t*rtc,uint32_t*c,uint32_t*n){if(!rtc||!c)return -1;struct context x={m,r,t,rtc,c,0};return rr_mouse_mode4_radio_with_ack(m,r,t,n,ack,&x);}
int rr_mouse_mode4_timer_lifecycle(uint8_t*m,uint8_t*r,uint8_t*t,uint8_t*s,const uint8_t*f,uint32_t*c,uint32_t*n,rr_mouse_mode4_pending*p){if(!p)return -1;memset(p,0,sizeof(*p));struct context x={m,r,t,0,c,p};return rr_mouse_mode4_timer_with_runtime(m,r,t,s,n,f,c,timeout,&x);}
