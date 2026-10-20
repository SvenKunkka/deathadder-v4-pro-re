/* Reconstructed23022508->mode dispatch->23025e04->230259ec. */
#include "mouse_business_flow.h"
#include "business_rx.h"
#include "business_control.h"
#include <string.h>
static unsigned r16(const uint8_t*p){return p[0]|(unsigned)p[1]<<8;}
static uint32_t r32(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void w16(uint8_t*p,unsigned x){p[0]=(uint8_t)x;p[1]=(uint8_t)(x>>8);}
static void stats(uint8_t*m,unsigned metadata){
 unsigned count=(uint16_t)(r16(m+0x6b8a)+1);
 if(count>30000)memset(m+0x6b88,0,4);
 else{w16(m+0x6b88,r16(m+0x6b88)+metadata);w16(m+0x6b8a,count);}
}
int rr_mouse_business_flow(uint8_t*m,rr_mouse_business_flow_event*event){
 if(!m||!event)return -1;
 rr_mouse_business_flow_event out={0};
 unsigned mode=r16(m+0x2798),len=m[0x2a96];
 if((mode!=1&&mode!=2&&mode!=4)||len==0||len>=128){*event=out;return 0;}
 unsigned cls=(m[0x2a98]&63u)>>3,seq=m[0x2a98]&7u;
 out.business_class=(uint8_t)cls;out.sequence=(uint8_t)seq;
 if(cls==0){uint32_t unused=0;(void)rr_control_consume(m,1,0,&unused);*event=out;return 0;}
 if(m[0x2a3a+cls]==seq){*event=out;return 0;}
 if(cls>=6)return -2;
 unsigned index=m[0x2a99]&31u,offset=index?m[0x6b58+cls]:0;
 unsigned size=(uint8_t)(len-2),total=offset+size-1;
 int mismatch=index&&m[0x6b50+cls]!=index;
 int completed=!mismatch&&!(m[0x2a99]&128u);
 if(!mismatch&&(size<1||size>129||total>128))return -2;
 uint32_t flags=r32(m+0x67ac);
 if(completed&&!(flags&6u))return -3;
 rr_business_rx_state s={0};rr_business_rx_event rx;
 memcpy(s.data,m+0x6850,sizeof(s.data));memcpy(s.expected,m+0x6b50,8);memcpy(s.length,m+0x6b58,8);
 memcpy(s.completed,m+0x67d0,128);s.completed_class=m[0x779b];s.completed_length=m[0x779c];
 /* Mismatch precedes memcpy even when length2 produces a zero size. The
  * generic RX interface rejects zero; preserve that natural original path. */
 if(mismatch){s.expected[cls]=0;s.length[cls]=0;memset(&rx,0,sizeof(rx));rx.kind=RR_RX_MISMATCH;}
 else if(rr_business_rx(1,&s,cls,m+0x2a99,size,0,&rx)!=0)return -2;
 m[0x2a3a+cls]=(uint8_t)seq;
 memcpy(m+0x6850,s.data,sizeof(s.data));memcpy(m+0x6b50,s.expected,8);memcpy(m+0x6b58,s.length,8);
 memcpy(m+0x67d0,s.completed,128);m[0x779b]=s.completed_class;m[0x779c]=s.completed_length;
 out.accepted=1;out.reassembly_kind=rx.kind;
 if(completed){out.work_requested=1;out.work_return=(flags&2u)?-16:0;}
 stats(m,mode==4?m[0x29e5]:0);
 memset(m+0x2a10,0,4);m[0x29d0]=2;
 *event=out;return 0;
}
