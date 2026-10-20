#include "business_control.h"
#include "business_tx.h"
#include <string.h>
static uint16_t r16(const uint8_t*p){return (uint16_t)(p[0]|(uint16_t)p[1]<<8);}
static uint16_t be16(const uint8_t*p){return (uint16_t)((uint16_t)p[0]<<8|p[1]);}
static uint32_t r32(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void w16(uint8_t*p,uint16_t x){p[0]=(uint8_t)x;p[1]=(uint8_t)(x>>8);}
static void w32(uint8_t*p,uint32_t x){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(x>>(8*i));}
void rr_dongle_business_stats(uint8_t*m,unsigned peer,uint32_t value){
 if(value!=0&&value!=255){
  unsigned off[4]={0x6590+(peer+4)*4,0x6590+(peer+6)*4,0x6598+(peer+8)*4,0x6598+(peer+10)*4};
  for(unsigned i=0;i<4;i++)w32(m+off[i],r32(m+off[i])+(i%2?1:value));
 }
 w16(m+0x65e6,5);
}
int rr_control_consume(uint8_t*m,int mouse,unsigned peer,uint32_t *nvic){
 if(mouse){
  unsigned mode=r16(m+0x2798),len=m[0x2a96];
  if((mode!=1&&mode!=2&&mode!=4)||len==0||len>=128)return 0;
  if(((m[0x2a98]&63)>>3)!=0)return -1;
  if(mode==4){
   if(m[0x2a99]==0x28)memcpy(m+0x26be,m+0x2a9a,4);
   else if(m[0x2a99]==0x29){w16(m+0x2972,be16(m+0x2a9b));m[0x27c5]=1;m[0x26c2]=m[0x2a9a];}
  }
  if(m[0x29e0]){
   uint16_t count=(uint16_t)(r16(m+0x6b8a)+1);
   if(count>30000)w32(m+0x6b88,0);
   else {w16(m+0x6b88,(uint16_t)(r16(m+0x6b88)+m[0x29e5]));w16(m+0x6b8a,count);}
  }
  return 0;
 }
 unsigned base=0x33e8+peer*0xf84,len=m[base+0x114];
 if(len==0||len>=128)return 0;
 if(((m[base+0x116]&63)>>3)!=0)return -1;
 const uint8_t *p=m+base+0x117;
 if(p[0]==0x2b){
  w16(m+0x33d2,be16(p+2));w16(m+0x33d4,be16(p+4));w16(m+0x33ce,p[1]&63);w16(m+0x33d0,p[1]>>6);
  w16(m+0x71a2,0);w16(m+0x71a0,2);*nvic=0x08000000;
 }else if(p[0]==0x2c){w16(m+base+0x36,p[1]);w16(m+base+0x38,be16(p+2));}
 else if(p[0]==0x17)w32(m+base+0x8c,be16(p+1));
 rr_dongle_business_stats(m,peer,m[base+0x69]);w16(m+0x33dc,(uint16_t)(r16(m+0x33dc)+1));
 return 0;
}
void rr_mouse_control_interval(uint8_t*m,unsigned peer,uint32_t interval,uint32_t clock[2]){
 if(interval-1u>=64)return;
 unsigned offset=peer*0xee0;
 if(r16(m+0x2794)<3||r16(m+0x29ac+offset)==0){
  w16(m+0x29ac+offset,(uint16_t)interval);
  if(interval==1){if(m[0x76ee]==0){m[0x76ee]=1;clock[0]=1;}}
  else if(m[0x76ee]){m[0x76ee]=0;clock[1]=1;}
 }else{
  uint16_t at=(uint16_t)(r16(m+0x2a0a)+100);uint8_t packet[4]={0x2f,(uint8_t)interval,(uint8_t)(at>>8),(uint8_t)at};
  (void)rr_bt_enqueue(m,1,peer,0,packet,4,255);
  w16(m+0x29ae + offset,(uint16_t)interval);w16(m+0x29b0+offset,at);
 }
}
void rr_dongle_control_publish(uint8_t*m){
 uint8_t packet[5]={0x28,m[0x30de],m[0x30df],m[0x30e0],m[0x30e1]};
 (void)rr_bt_enqueue(m,0,0,0,packet,5,255);
 packet[0]=0x29;packet[1]=m[0x30e2];packet[2]=m[0x33d7];packet[3]=m[0x33d6];packet[4]=0;
 (void)rr_bt_enqueue(m,0,0,0,packet,5,255);
}
