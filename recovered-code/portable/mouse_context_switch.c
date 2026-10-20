#include "mouse_context_switch.h"
#define BASE 0x23000000u
static uint32_t w(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void pw(uint8_t*p,uint32_t v){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(v>>(8*i));}
static int valid(uint32_t a,unsigned n){return a>=BASE&&a-BASE<=65536u-n;}
int rr_mouse_switch_request_inert(uint8_t*m,uint8_t*n,uint8_t*s,rr_mouse_context_cpu*c){
 if(!m||!n||!s||!c)return -1;pw(s+28,c->r[4]);c->r[4]=0xfffffff5u;c->r[2]=0x2300764cu;c->r[1]=0xe000ed00u;c->r[3]=w(m+0x7654);c->r[12]=0;
 if(!valid(c->r[3],0x90))return -1;uint8_t*t=m+c->r[3]-BASE;pw(t+0x88,c->r[0]);pw(t+0x8c,c->r[4]);c->r[3]=w(n+0xd04)|0x10000000u;pw(n+0xd04,c->r[3]);c->priority=0;
 c->r[3]=w(m+0x7654);c->r[4]=w(s+28);if(!valid(c->r[3],0x90))return -1;c->r[0]=w(m+c->r[3]-BASE+0x8c);c->pc=c->lr&~1u;return 0;
}
int rr_mouse_select_context(uint8_t*m,uint8_t*n,uint8_t*s,rr_mouse_context_cpu*c){
 if(!m||!n||!s||!c)return -1;pw(s+24,c->r[4]);pw(s+28,c->r[5]);c->r[3]=32;c->flags[1]=0;c->flags[2]=0;if(!c->priority||c->priority>32)c->priority=32;
 c->r[5]=0x08000000u;c->r[1]=0;c->flags[1]=1;c->r[2]=0x2300764cu;c->r[4]=0xe000ed00u;c->r[3]=w(m+0x7664);pw(m+0x7654,c->r[3]);pw(n+0xd04,c->r[5]);c->r[2]=0x23006d30u;
 if(!valid(c->r[3],0x90))return -1;uint8_t*t=m+c->r[3]-BASE;c->r[4]=w(t+0x84);pw(m+0x6d30,c->r[4]);c->r[2]=w(t+0x88);pw(t+0x88,0);c->priority=c->r[2];c->r[4]=w(s+24);c->r[5]=w(s+28);c->pc=c->lr&~1u;return 0;
}
int rr_mouse_set_psplim(uint8_t*m,rr_mouse_context_cpu*c){
 if(!m||!c||!valid(c->r[0],0x78))return -1;c->r[3]=w(m+c->r[0]-BASE+0x74);c->psplim=c->r[3];c->pc=c->lr&~1u;return 0;
}
int rr_mouse_pendsv_body(uint8_t*m,uint8_t*n,uint8_t*s,rr_mouse_context_cpu*c){
 if(!m||!n||!s||!c)return -1;c->r[1]=0x2300764cu;c->r[2]=w(m+0x7654);c->r[0]=c->r[2]+0x30;c->r[12]=c->psp;if(!valid(c->r[2],0x90))return -1;
 uint8_t*t=m+c->r[2]-BASE;for(unsigned i=0;i<9;i++)pw(t+0x30+4*i,c->r[4+i]);c->r[4]=c->lr;c->r[0]=c->lr;c->lr=0x0e089de7u;int rc=rr_mouse_select_context(m,n,s,c);if(rc)return rc;c->lr=c->r[4];
 c->r[1]=0x2300764cu;c->r[2]=w(m+0x7654);c->r[0]=c->r[2]+0x30;if(!valid(c->r[2],0x90))return -1;t=m+c->r[2]-BASE;for(unsigned i=0;i<9;i++)c->r[4+i]=w(t+0x30+4*i);c->psp=c->r[12];c->r[0]=c->r[2];
 pw(s+24,c->r[2]);pw(s+28,c->lr);c->lr=0x0e089e03u;rc=rr_mouse_set_psplim(m,c);if(rc)return rc;c->r[2]=w(s+24);c->lr=w(s+28);c->pc=0x0e089e06u;return 1;
}
