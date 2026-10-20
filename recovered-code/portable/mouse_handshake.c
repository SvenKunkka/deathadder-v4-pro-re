#include "mouse_handshake.h"
#include <string.h>
#define O(address) ((address)-0x23002688u)
static uint16_t g16(const uint8_t *p){return (uint16_t)(p[0]|((uint16_t)p[1]<<8));}
static uint32_t g32(const uint8_t *p){return (uint32_t)p[0]|((uint32_t)p[1]<<8)|((uint32_t)p[2]<<16)|((uint32_t)p[3]<<24);}
static void s16(uint8_t *p,uint16_t v){p[0]=(uint8_t)v;p[1]=(uint8_t)(v>>8);}
static void s32(uint8_t *p,uint32_t v){p[0]=(uint8_t)v;p[1]=(uint8_t)(v>>8);p[2]=(uint8_t)(v>>16);p[3]=(uint8_t)(v>>24);}
static void reset(uint8_t *m,uint32_t *r){
 s32(m+O(0x23002a04),0x13);s16(m+O(0x23002a4a),0);s16(m+O(0x23002a52),0);
 r[2]=1;r[3]=1;r[4]=1;r[5]=0x7f0000;r[6]=0x800000;
 for(unsigned i=7;i<15;i++)r[i]=0;
}
int rr_mouse_handshake_step(uint8_t m[RR_MOUSE_RAM_BYTES],uint32_t event,uint32_t crc_ok,
 uint8_t channel,uint32_t regs[RR_MOUSE_STEP_REGISTER_WORDS]) {
 uint32_t state=g32(m+O(0x23002a04));
 if(event!=5u || (state!=0x14u && state!=0x16u && state!=0x17u))return 0;
 if(state==0x17u)return -1;
 if(state==0x16u){
  regs[0]=0;regs[15]=0;regs[16]=0;regs[17]=0;regs[18]=1;
  s32(m+O(0x23002a04),0x14);s32(m+O(0x23002a4e),0x50001);return 0;
 }
 if(crc_ok==1u)regs[1]=0;
 uint8_t p[12];memcpy(p,m+O(0x23002a56),12);
 uint16_t phase=g16(m+O(0x23002a4a));
 uint8_t expected=phase==0u?0x11u:phase==1u?0x13u:phase==4u?0x15u:0u;
 if(crc_ok!=1u || (p[1]&0xc0u)!=0u || p[0]!=11u || expected==0u || p[3]!=expected){reset(m,regs);return 0;}
 uint8_t seq=m[O(0x23002a2a)],command;
 uint16_t next_phase;
 if(phase==0u){
  uint16_t cap=g16(m+O(0x2300279c));
  s16(m+O(0x23002846),g16(p+8));m[O(0x23002a09)]=(uint8_t)(p[8]>>7);
  s16(m+O(0x23002992),(uint16_t)((p[8]>>6)&1u));
  if((cap&p[8]&15u)==0u){reset(m,regs);return 0;}
  if(g32(m+O(0x2300298c))!=0u){
   if(g32(m+O(0x23002990))==0x10000u){reset(m,regs);return 0;}
   s32(m+O(0x230027b0),((uint32_t)p[4]<<24)|((uint32_t)p[5]<<16)|((uint32_t)p[6]<<8)|p[7]);
  }
  s32(m+O(0x23002838),500);
  s16(m+O(0x23002a0a),(uint16_t)(((uint16_t)p[10]<<8)|p[11]));
  p[4]=(uint8_t)((cap&15u)|(m[O(0x23002a08)]<<7));p[5]=0;
  memcpy(p+6,m+O(0x2300297e),4);
  next_phase=1;command=0x12;regs[7]=432;
 }else if(phase==1u){
  s16(m+O(0x23002798),(uint16_t)(p[4]&15u));
  m[O(0x230029d5)]=(uint8_t)(p[6]&15u);m[O(0x230029d6)]=(uint8_t)(p[6]>>4);
  s16(m+O(0x230027a2),(uint16_t)((p[4]>>4)&3u));
  p[4]=m[O(0x230029ac)];p[5]=0;p[6]=0;p[7]=0;next_phase=4;command=0x14;
 }else{
  uint16_t selector=g16(m+O(0x230027a2));
  if(selector<2u){memcpy(m+O(0x230029d7),p+4,8);m[O(0x230029df)]=4;}
  else if(selector==2u || selector==3u){
   memcpy(m+O(0x230026b9),p+4,5);
   if(selector==2u)s32(m+O(0x23002738),p[9]);
  }
  p[4]=0;p[5]=0;next_phase=6;command=0x16;
 }
 p[0]=11;p[1]=0;p[2]=seq;p[3]=command;memcpy(m+O(0x23002a56),p,12);
 seq=(uint8_t)(seq+1u);m[O(0x23002a2a)]=seq==8u?1u:seq;
 s16(m+O(0x23002a4a),next_phase);s32(m+O(0x23002a04),phase==4u?0x17u:0x16u);
 s32(m+O(0x23002a4e),0x50001);s16(m+O(0x23002a52),0);
 regs[0]=channel|0x80000000u;return 0;
}

/* Retained ABI: zero-initialized 15-word register projection. */
int rr_mouse_handshake_rx(uint8_t m[RR_MOUSE_RAM_BYTES],uint32_t event,uint32_t crc_ok,
 uint8_t channel,uint32_t regs[RR_MOUSE_REGISTER_WORDS]) {
 uint32_t all[RR_MOUSE_STEP_REGISTER_WORDS]={0};
 int status=rr_mouse_handshake_step(m,event,crc_ok,channel,all);
 memcpy(regs,all,RR_MOUSE_REGISTER_WORDS*sizeof(*regs));return status;
}
