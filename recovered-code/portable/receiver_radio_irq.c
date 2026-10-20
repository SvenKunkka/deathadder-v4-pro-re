#include "receiver_radio_irq.h"
#include "business_tx.h"
#include <string.h>
#define R(o) h->radio[(o)/4]
#define T(o) h->timer[(o)/4]
static uint16_t r16(const uint8_t*p){return (uint16_t)(p[0]|p[1]<<8);}
static uint32_t r32(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void w16(uint8_t*p,uint16_t x){p[0]=(uint8_t)x;p[1]=(uint8_t)(x>>8);}
static void w32(uint8_t*p,uint32_t x){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(x>>(i*8));}
static void pend(rr_receiver_radio_hw*h,uint32_t mask){h->nvic_last=mask;h->nvic_requests|=mask;}
static void notice(uint8_t*r,rr_receiver_radio_hw*h,unsigned peer,unsigned event){w16(r+0x71a2,(uint16_t)peer);w16(r+0x71a0,(uint16_t)event);pend(h,0x08000000);}
static void task(uint8_t*r,rr_receiver_radio_hw*h,unsigned stateaddr,unsigned reg,unsigned state){w32(r+stateaddr,state);R(0x200)=0;R(0x218)=0;R(0x220)=0;R(reg)=1;}
static int scan_next(uint8_t*r){
 uint16_t wait=r16(r+0x31aa);if(wait){w16(r+0x31aa,wait-1);return 0;}
 unsigned index=r[0x31a8];r[0x535a]=r[0x3e8+index];r[0x31a7]++;
 if(r[0x31a7]>9){r[0x31a7]=0;index=(uint8_t)(index+1);if(index<23)r[0x31a8]=(uint8_t)index;
 else{r[0x31a8]=0;if(r[0x31a6]!=255){w16(r+0x31aa,r32(r+0x33e8)==3?200:5000);r[0x31a9]=1;}r[0x31a6]=0;}}
 return 1;
}
static void radio_event(uint8_t*r,const uint8_t*f,rr_receiver_radio_hw*h,unsigned event){
 unsigned slot=r16(r+0x32d0),peer=(slot==2||slot==5)?2:0,b=0x33e8+peer*0xf84,state=r32(r+b+0x80);
 if(state==12){
  if(event!=4)return;
  unsigned length=r[0x3050];int valid=0;
  if(R(0x22c)==1&&length){R(0x22c)=0;r[0x3050]=(uint8_t)(length-1);uint8_t sum=0;for(unsigned i=1;i<length;i++)sum=(uint8_t)(sum+r[0x3050+i]);valid=r[0x3050+length]==(uint8_t)-sum;}
  if(valid){
   uint8_t packet[16];memcpy(packet,r+0x3050,16);r[0x3050]=0;memcpy(r+b+0x114,packet,16);r[b+0x9f]=1;
   unsigned header=r[b+0x115],reply=header>>7,sequence=(header&127)>>4;
   w16(r+b+0x9c,(uint16_t)(reply|(reply<<8)));r[b+0x9e]=header&15;
   if(r[b+0x9b]!=sequence){w16(r+b+0x88,0);w16(r+b+0x90+2*r16(r+0x32ca),0);unsigned q=r16(r+b+0x96);
    if(q<6){uint8_t seq=(uint8_t)(r[b+0x9a]+1);if(seq==8)seq=1;r[b+0x9a]=seq;rr_bt_pop(r,0,peer,q);w16(r+b+0x98,(uint16_t)q);}}
   r[b+0x9b]=(uint8_t)sequence;w16(r+b+0x96,255);w16(r+0x71a4,(uint16_t)peer);pend(h,0x10000000);
   r[0x3451]=(uint8_t)R(0x718);r[0x3452]=(uint8_t)r16(r+0x3224);r[0x3450]=0;notice(r,h,0,0);
  }else r[0x3050]=0;
  w32(r+b+0x80,11);return;
 }
 if(state==13){if(event==5)w32(r+b+0x80,13);return;}
 if(state==14){if(event!=5)return;if(scan_next(r)){R(0x110)=r[0x71c5]|0x80000000u;R(0x708)=f[0x1bb84+r[0x535a]];task(r,h,b+0x80,4,15);}
  else{if(r[0x31a9]==1){r[0x31a9]=0;notice(r,h,2,1);}w32(r+b+0x80,13);}return;}
 if(state==15){if(event==14)task(r,h,b+0x80,0x14,16);return;}
 if(state==16){R(0x110)=0;r[0x5359]=(uint8_t)R(0x718);r[0x5358]=1;notice(r,h,2,0);w32(r+b+0x80,13);}
}
int rr_receiver_radio_irq(uint8_t*r,const uint8_t*f,rr_receiver_radio_hw*h){
 if(r16(r+0x3230)==5||r16(r+0x3234)!=4)return -1;
 if(R(0x204)==1)R(0x204)=0;
 if(R(0x208)==1){R(0x208)=0;if(r16(r+0x3230)>1)radio_event(r,f,h,14);}
 if(R(0x20c)==1)R(0x20c)=0;
 if(R(0x218)!=0){R(0x218)=0;if(r16(r+0x3230)>1)radio_event(r,f,h,4);}
 if(R(0x220)==1){R(0x220)=0;if(r16(r+0x3230)>1)radio_event(r,f,h,5);R(0x22c)=0;R(0x230)=0;}
 return 0;
}
static void subscriptions(uint8_t*r,rr_receiver_radio_hw*h){
 unsigned slot=r16(r+0x32d0);
 if(slot==0){w16(r+0x322c,r16(r+0x3224));w32(r+0x3222,r32(r+0x3226));R(0x708)=r16(r+0x3226);R(0xe30)=r32(r+0x3244);R(0xe3c)=3;R(0xe40)=6;R(0x104)=r[0x71c6]|0x80000000u;R(0x400)=(R(0x400)&~0x80000u)|0x20;}
 else if(slot==1||slot==4)R(0x10c)=r[0x71c2]|0x80000000u;
 else if(slot==2||slot==5){if(r[0x3484]==1){R(0x100)=r[0x71c4]|0x80000000u;R(0x400)|=0x80000;}else r[0x325e]=1;}
 else if(slot==3){R(0x708)=r16(r+0x3222);R(0xe30)=r32(r+0x3244);R(0x104)=r[0x71c4]|0x80000000u;R(0x400)=(R(0x400)&~0x80000u)|0x20;}
}
static void rx_window(uint8_t*r,rr_receiver_radio_hw*h,unsigned action){
 unsigned state=r32(r+0x3468);if(state!=11&&state!=12)return;
 if(action==2){R(0x10c)=0;R(0x400)&=~0x20u;if(state==12)w32(r+0x3468,11);return;}
 if(action==1){R(0x104)=0;return;}
 if(action!=4)return;R(0xed0)=0x23003050;r[0x3050]=0;if(state==12)return;
 T(0x5c)=1;unsigned slot=r16(r+0x32d0);if((slot==0&&T(0x55c)<3200)||(slot==3&&T(0x55c)>8000))task(r,h,0x3468,4,12);else w32(r+0x3468,12);
}
int rr_receiver_timer_cc1(uint8_t*r,rr_receiver_radio_hw*h){
 if(r16(r+0x3230)<2)return 0;if(r16(r+0x3234)!=4)return -1;
 if(T(0x140)==1||T(0x144)!=1)return -2;
 T(0x144)=0;unsigned slot=r16(r+0x32d0);
 if(slot==1||slot==4){
  rx_window(r,h,2);w16(r+0x32d0,(uint16_t)(slot+1));subscriptions(r,h);if(r32(r+0x5370)!=13)return 0;
  if(!r[0x3484]){task(r,h,0x5370,0x10,14);r[0x3484]=0;return 0;}
  uint32_t ptr=0;unsigned q;
  for(q=0;q<6;q++){ptr=rr_bt_peek(r,0,0,q);if(ptr){w16(r+0x347e,(uint16_t)q);r[0x3488]=1;break;}}
  if(!ptr){w16(r+0x347e,255);r[0x53e4]=5;r[0x53e6]=r[0x5397];r[0x5397]++;if(r[0x5397]==8)r[0x5397]=1;r[0x53e7]=0x1f;uint16_t counter=r16(r+0x5376);r[0x53e8]=(uint8_t)(counter>>8);r[0x53e9]=(uint8_t)counter;ptr=0x230053e4;}
  unsigned off=ptr-0x23000000u;r[off+1]=(uint8_t)(0x80|(r[0x3488]<<6)|r[0x33e8+2*(r16(r+0x32ca)+0xfcc)]);memcpy(r+0x3070,r+off,16);R(0xed0)=0x23003070;T(0x5c)=1;
  unsigned next=slot+1;if((next==2&&T(0x55c)>5280)||(next==5&&T(0x55c)>13280))task(r,h,0x5370,0x10,13);else {h->aux[0x440/4]=1;h->aux[0]=1;}r[0x3484]=0;return 0;
 }
 if(slot==0||slot==2||slot==3||slot==5){w16(r+0x32d0,(uint16_t)(slot==5?0:slot+1));subscriptions(r,h);rx_window(r,h,4);}return 0;
}
static void swi_tail(uint8_t*r){
 unsigned peer=r16(r+0x71a4),value=r[0x33e8+peer*0xf84+0x9e],mode=r16(r+0x323e);
 if(mode<=1)w16(r+0x3478+2*r[0x32ca],(uint16_t)value);
 else if(mode<=3){unsigned a=0x3332+2*r16(r+0x3228);if(r16(r+a)<value)w16(r+a,(uint16_t)value);}
}
int rr_receiver_radio_swi4(uint8_t*r,const uint8_t*f,rr_receiver_radio_hw*h,rr_receiver_business_pending*p){
 if(r16(r+0x3234)!=4)return -1;
 unsigned peer=r16(r+0x71a4),b=0x33e8+peer*0xf84,len=r[b+0x114];
 /* The only ISPR store in this SWI business path is valid class0 opcode2B.
  * Record its write action, including a repeated same-value store; an old
  * nvic_last value alone does not imply a new request. */
 int writes_notice=len>0&&len<128&&((r[b+0x116]&63u)>>3)==0&&r[b+0x117]==0x2b;
 int rc=rr_receiver_business_flow(r,f,peer,&h->nvic_last,p);
 if(writes_notice)h->nvic_requests|=0x08000000u;
 if(rc==0)swi_tail(r);return rc;
}
int rr_receiver_radio_swi4_resume(uint8_t*r,int32_t result,rr_receiver_business_pending*p){int rc=rr_receiver_business_resume(r,result,p);if(rc==0)swi_tail(r);return rc;}
