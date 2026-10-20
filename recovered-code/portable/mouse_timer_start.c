#include "mouse_timer_start.h"
#include "mouse_timer_lifecycle.h"
#include <string.h>
static uint32_t g32(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static uint64_t g64(const uint8_t*p){return g32(p)|(uint64_t)g32(p+4)<<32;}
static void s32(uint8_t*p,uint32_t v){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(v>>(8*i));}
static void s64(uint8_t*p,uint64_t v){s32(p,(uint32_t)v);s32(p+4,(uint32_t)(v>>32));}
static int valid(uint32_t a,unsigned n){return a>=0x23000000u&&a-0x23000000u<=65536u-n;}
static int slt(uint64_t a,uint64_t b){return (a^UINT64_C(0x8000000000000000))<(b^UINT64_C(0x8000000000000000));}
static uint64_t sx32(uint32_t x){return x&0x80000000u?UINT64_C(0xffffffff00000000)|x:x;}
static int now(const uint8_t*r,uint64_t*out){uint32_t h=g32(r+0x774);if(h>0x3fffffffu)return -4;*out=g32(r+0x770)|(uint64_t)(h&0xfffffu)<<32;return 0;}
static int elapsed(uint8_t*m,uint8_t*r,uint64_t*out){uint64_t v;int rc=now(r,&v);if(rc)return rc;*out=sx32((uint32_t)((v-g64(m+0x21c0))>>5));return 0;}
static int arm(uint8_t*m,uint8_t*r,uint32_t wait){
 uint64_t v;int rc=now(r,&v);if(rc)return rc;uint64_t base=g64(m+0x21c0),due=v-base+((uint64_t)wait<<5);
 due=due<64?32:due&~UINT64_C(31);uint64_t deadline=base+due;
 unsigned ch=m[0x1304];uint32_t mask=ch<32?1u<<ch:0;
 if(!(mask&0xe080u)||!(~g32(m+0x1458)&0xe080u&mask))return 0;
 unsigned slot=ch==7?0:ch-12;s32(r+0x52c+ch*16,0);memcpy(m+0x1460+slot*12,m+0x12fc,8);m[0x1468+slot*12]=(uint8_t)ch;s32(m+0x145c,g32(m+0x145c)|mask);
 s32(r+0x100+ch*4,0);s32(r+0x520+ch*16,(uint32_t)deadline);s32(r+0x524+ch*16,(uint32_t)(deadline>>32)&0xfffffu);s32(r+0x354,mask);return 0;
}
int rr_mouse_timeout_start(uint8_t*m,uint8_t*r,uint32_t address,uint32_t callback,uint64_t delay){
 if(!m||!r)return -1;if(delay==UINT64_MAX)return 0;if(!valid(address,24))return -1;
 unsigned t=address-0x23000000u;s32(m+t+8,callback);uint64_t delta;
 if(!(delay>>63)){delta=delay+1;if(!g32(m+0x7680)){uint64_t e;int rc=elapsed(m,r,&e);if(rc)return rc;delta+=e;}}
 else{delta=UINT64_MAX-1-g64(m+0x25f8)-delay;if(!delta||(delta>>63))delta=1;}
 s64(m+t+16,delta);uint32_t node=g32(m+0x14f4),last=g32(m+0x14f8);unsigned count=0;int inserted=0;
 if(node!=0x230014f4u)while(node){
  if(++count>2730||!valid(node,24)||node==address)return -1;unsigned n=node-0x23000000u;uint64_t nd=g64(m+n+16);
  if(slt(delta,nd)){uint32_t prev=g32(m+n+4);if(!valid(prev,8))return -1;s64(m+n+16,nd-delta);s32(m+t,node);s32(m+t+4,prev);s32(m+prev-0x23000000u,address);s32(m+n+4,address);inserted=1;break;}
  delta-=nd;s64(m+t+16,delta);if(node==last)break;node=g32(m+n);
 }
 if(!inserted){if(!valid(last,8))return -1;s32(m+t,0x230014f4u);s32(m+t+4,last);s32(m+last-0x23000000u,address);s32(m+0x14f8,address);}
 if(g32(m+0x14f4)==address&&!g32(m+0x7680)){uint64_t e;int rc=elapsed(m,r,&e);if(rc)return rc;uint64_t wait=g64(m+t+16)-e;if(wait>>63)wait=0;if(wait>0x7fffffffu)wait=0x7fffffffu;return arm(m,r,(uint32_t)wait);}
 return 0;
}
int rr_mouse_timer_start(uint8_t*m,uint8_t*r,uint32_t address,uint64_t duration,uint64_t period){
 if(!m||!r)return -1;if(duration==UINT64_MAX)return 0;if(!valid(address,0x38))return -1;
 uint64_t delay=duration;if(!(duration>>63))delay=duration?duration-1:0;
 int32_t result;int rc=rr_mouse_timer_abort(m,r,address,&result);if(rc)return rc;
 unsigned t=address-0x23000000u;s64(m+t+0x28,period);s32(m+t+0x30,0);
 return rr_mouse_timeout_start(m,r,address,0x0e096951u,delay);
}
