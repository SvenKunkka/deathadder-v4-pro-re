#include "receiver_legacy_business.h"
#include "business_rx.h"
#include "business_control.h"
#include "dongle_business_consumer.h"
#include <string.h>
static uint16_t r16(const uint8_t*p){return (uint16_t)(p[0]|p[1]<<8);}
static uint16_t be16(const uint8_t*p){return (uint16_t)(p[0]<<8|p[1]);}
static uint32_t r32(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void w16(uint8_t*p,uint16_t x){p[0]=(uint8_t)x;p[1]=(uint8_t)(x>>8);}
static void w32(uint8_t*p,uint32_t x){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(x>>(i*8));}
static void finish(uint8_t*r,unsigned selected,unsigned forwarded,unsigned meta){rr_dongle_business_stats(r,forwarded,meta);w32(r+0x33e8+selected*0xf84+0x8c,0);}
static int receive(uint8_t*r,const uint8_t*f,unsigned selected,unsigned forwarded,unsigned cls,const uint8_t*payload,unsigned size,unsigned meta,rr_receiver_legacy_pending*p){
 rr_business_rx_state rx;memset(&rx,0,sizeof(rx));memcpy(rx.data,r+0x6278,768);memcpy(rx.expected,r+0x6578,8);memcpy(rx.length,r+0x6580,8);memcpy(rx.motion,r+0x6588,8);rx.activity=r[0x6594];
 uint32_t key[4];for(unsigned i=0;i<4;i++)key[i]=r32(r+0x3020+4*i);rr_business_rx_event ev;
 if(rr_business_rx(0,&rx,cls,payload,size,key,&ev)!=0)return -1;
 memcpy(r+0x6278,rx.data,768);memcpy(r+0x6578,rx.expected,8);memcpy(r+0x6580,rx.length,8);memcpy(r+0x6588,rx.motion,8);r[0x6594]=rx.activity;
 int consume=ev.kind==RR_RX_DELIVER;if(ev.kind==RR_RX_MANAGEMENT)consume=!rr_dbc_management(r,f,forwarded,ev.payload);
 if(consume&&rr_dbc_consume(r,f,cls,ev.payload,ev.length)==RR_DBC_USB_RESUME){p->active=1;p->selected_peer=(uint8_t)selected;p->forward_peer=(uint8_t)forwarded;p->metadata=(uint8_t)meta;p->device=r32(r+0x690c);return 1;}
 finish(r,selected,forwarded,meta);return 0;
}
int rr_receiver_legacy_business(uint8_t*r,const uint8_t*f,unsigned mode,unsigned peer,rr_receiver_legacy_pending*p){
 memset(p,0,sizeof(*p));if((mode!=1&&mode!=2)||peer>2)return -1;
 unsigned b=0x33e8+peer*0xf84,len=r[b+0x114];if(len==0||len>=128)return 0;
 unsigned header=r[b+0x116],cls=(header&63u)>>3,seq=header&7u,meta=r[b+0x69];const uint8_t*body=r+b+0x117;
 if(cls>5)return -1;
 if(cls==0){if(mode==1){if(body[0]==0x17)w32(r+b+0x8c,be16(body+1));else if(body[0]==0x2c){w16(r+b+0x36,body[1]);w16(r+b+0x38,be16(body+2));}}rr_dongle_business_stats(r,peer,meta);return 0;}
 if(r[b+0xb7+cls]==seq){if(mode==1&&cls==1){if(r[b+0x9d]==1)memset(r+0x30a2,0,6);w32(r+b+0x8c,0);}return 0;}
 if(mode==2&&(len<2||(cls!=1&&len==2)))return -1;
 r[b+0xb7+cls]=(uint8_t)seq;
 if(mode==1&&cls!=1&&len<=2){w32(r+b+0x8c,0);return 0;}
 uint8_t tmp[128];unsigned size=len-2,forwarded=mode==1?0:peer;
 if(cls==1){tmp[0]=0;if(mode==2){memcpy(tmp+1,body,len-2);size=len-1;}
 else{uint16_t x=be16(body+2),y=be16(body+4),dx=(uint16_t)(x-r16(r+0x30a2)),dy=(uint16_t)(y-r16(r+0x30a4));uint8_t wheel=(uint8_t)(body[1]-r[0x30a6]);
  if(r[b+0x9d]==0){w16(r+0x30a2,x);w16(r+0x30a4,y);r[0x30a6]=body[1];r[0x30a7]=body[0];}else memset(r+0x30a2,0,6);
  tmp[1]=body[0];tmp[2]=wheel;tmp[3]=(uint8_t)(dx>>8);tmp[4]=(uint8_t)dx;tmp[5]=(uint8_t)(dy>>8);tmp[6]=(uint8_t)dy;size=7;}
 body=tmp;}
 return receive(r,f,peer,forwarded,cls,body,size,meta,p);
}
int rr_receiver_legacy_resume(uint8_t*r,int32_t result,rr_receiver_legacy_pending*p){if(!p->active)return -1;rr_dbc_resume_result(r,result);finish(r,p->selected_peer,p->forward_peer,p->metadata);p->active=0;return 0;}
