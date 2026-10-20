#include "receiver_business_flow.h"
#include "business_dispatch.h"
#include "business_rx.h"
#include "business_control.h"
#include "dongle_business_consumer.h"
#include <string.h>
static uint32_t r32(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void load_dispatch(rr_business_dispatch_state*s,const uint8_t*r,unsigned peer){memcpy(s->context,r+0x33e8+peer*0xf84,0x200);memcpy(s->motion,r+0x30a2,6);memcpy(s->counters,r+0x33dc,4);}
static void store_dispatch(const rr_business_dispatch_state*s,uint8_t*r,unsigned peer){memcpy(r+0x33e8+peer*0xf84,s->context,0x200);memcpy(r+0x30a2,s->motion,6);memcpy(r+0x33dc,s->counters,4);}
static void after_business(uint8_t*r,unsigned selected_peer,unsigned metadata){
 rr_dongle_business_stats(r,0,metadata); /* Original data branch forwards peer0. */
 rr_business_dispatch_state d;load_dispatch(&d,r,selected_peer);rr_business_dispatch_finish(&d);store_dispatch(&d,r,selected_peer);
}
int rr_receiver_business_flow(uint8_t*r,const uint8_t*f,unsigned peer,uint32_t*nvic,rr_receiver_business_pending*p){
 memset(p,0,sizeof(*p));unsigned base=0x33e8+peer*0xf84,len=r[base+0x114],cls=(r[base+0x116]&63u)>>3;
 if(len>0&&len<128&&cls==0)return rr_control_consume(r,0,peer,nvic);
 rr_business_dispatch_state d;rr_business_dispatch_event de;load_dispatch(&d,r,peer);
 if(rr_business_dispatch(&d,&de)!=0)return -1;store_dispatch(&d,r,peer);
 if(!de.forward)return 0;
 rr_business_rx_state rx;memset(&rx,0,sizeof(rx));
 memcpy(rx.data,r+0x6278,768);memcpy(rx.expected,r+0x6578,8);memcpy(rx.length,r+0x6580,8);memcpy(rx.motion,r+0x6588,8);rx.activity=r[0x6594];
 uint32_t key[4];for(unsigned i=0;i<4;i++)key[i]=r32(r+0x3020+4*i);
 rr_business_rx_event ev;
 if(rr_business_rx(0,&rx,de.business_class,de.payload,de.size,key,&ev)!=0)return -1;
 memcpy(r+0x6278,rx.data,768);memcpy(r+0x6578,rx.expected,8);memcpy(r+0x6580,rx.length,8);memcpy(r+0x6588,rx.motion,8);r[0x6594]=rx.activity;
 int consume=ev.kind==RR_RX_DELIVER;
 if(ev.kind==RR_RX_MANAGEMENT)consume=!rr_dbc_management(r,f,0,ev.payload);
 if(consume&&rr_dbc_consume(r,f,ev.business_class,ev.payload,ev.length)==RR_DBC_USB_RESUME){p->active=1;p->peer=(uint8_t)peer;p->metadata=de.metadata;p->device=r32(r+0x690c);return 1;}
 after_business(r,peer,de.metadata);return 0;
}
int rr_receiver_business_resume(uint8_t*r,int32_t result,rr_receiver_business_pending*p){
 if(!p->active)return -1;rr_dbc_resume_result(r,result);after_business(r,p->peer,p->metadata);p->active=0;return 0;
}
