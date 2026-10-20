/* 1.20 authored reconstruction; original-instruction evidence in analysis. */
#include "dongle_business_consumer.h"
#include <string.h>
static uint16_t r16(const uint8_t*p){return (uint16_t)(p[0]|p[1]<<8);}
static void w16(uint8_t*p,uint16_t x){p[0]=(uint8_t)x;p[1]=(uint8_t)(x>>8);}
static void w32(uint8_t*p,uint32_t x){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(x>>(8*i));}
uint8_t rr_dbc_usb_enqueue(uint8_t*r,unsigned c,const uint8_t*d,uint32_t n){
 uint8_t enabled=r[0x71e4];if(!enabled)return 0;
 unsigned q=r[0x48c+c],wr=r[0x6838+q],rd=r[0x6834+q];uint8_t next=(uint8_t)(wr+1);
 if(next==4){if(!rd)return 0;memcpy(r+0x683c+(q*4+3)*16,d,n);r[0x6838+q]=0;return enabled;}
 if(next==rd)return 0;
 if(wr<4){memcpy(r+0x683c+(wr+q*4)*16,d,n);r[0x6838+q]=next;return enabled;}
 memset(r+0x6838,0,3);memset(r+0x6834,0,3);return 0;
}
void rr_dbc_status(uint8_t*r,const uint8_t*f,unsigned op,uint32_t v){
 unsigned type=0,offset=0;
 switch(op){
 case 0xe0:if(v>=5)return;type=2;offset=0x1b7c0+4*v;break;
 case 0xe1:{unsigned i=0;while(i<7&&!(v&(1u<<i)))i++;if(i==7)return;type=3;offset=0x1b7a4+4*i;break;}
 case 0xe2:if(v>=5)return;type=4;offset=0x1b790+4*v;break;
 case 0xe3:r[0x71b9]=v<16;if(v<16)return;type=1;offset=0x1b7d4+4*((v*100u)/255u);break;
 case 0xff:for(unsigned i=0;i<3;i++)w32(r+0x2ca8+4*i,0x01000000);r[0x71b9]=0;return;
 default:return;
 }
 for(unsigned i=0;i<3;i++)if(r[0x2cb4+i]==type){memcpy(r+0x2ca8+4*i,f+offset,3);r[0x2cab+4*i]=1;}
}
uint32_t rr_dbc_management(uint8_t*r,const uint8_t*f,unsigned peer,const uint8_t*d){
 if(d[0]==0xab)return 1;
 if(d[0]==0xac){r[0x65b2+peer]=d[1];return 1;}
 if(d[0]!=0xa4)return 0;
 w32(r+0x65e2,0x50000);w16(r+0x6590,0);
 w16(r+0x2c80,(uint16_t)(r16(r+0x2c80)&~2u));
 const uint8_t report[16]={5,9,2,1,0,0,0,0,0,0,0,0,0,0,0,0};rr_dbc_usb_enqueue(r,4,report,16);
 rr_dbc_status(r,f,0xff,0);memset(r+0x353c,0,12);
 /* 230203FC(op0x14,0,0) falls through without side effects. */
 return 1;
}
void rr_dbc_resume_result(uint8_t*r,int32_t result){
 r[0x71e3]=1;
 if(result==0){r[0x6905]=0;r[0x6839]=0;r[0x6835]=0;const uint8_t neutral[8]={0};rr_dbc_usb_enqueue(r,1,neutral,8);}
}
enum rr_dbc_boundary rr_dbc_consume(uint8_t*r,const uint8_t*f,unsigned c,uint8_t*d,uint32_t n){
 if(r16(r+0x2c82)!=1){
  int active=0;unsigned kind=(uint8_t)c;
  if(kind==1||kind==2){for(uint32_t i=0;i<n;i++)if(d[i]){active=1;break;}}
  else if(kind==4&&d[0]==1)active=n>1;
  if(active&&r[0x71e3]==0&&r[0x71e6]==3)return RR_DBC_USB_RESUME;
  return RR_DBC_DONE;
 }
 switch(c){
 case 1:
  if(r[0x2c88]==1){d[0]|=r[0x2c8a];d[1]=(uint8_t)(d[1]+r[0x2c8c]);d[2]=(uint8_t)(d[2]+r[0x2c8d]);d[3]=(uint8_t)(d[3]+r[0x2c8b]);w16(d+4,(uint16_t)(r16(d+4)+r16(r+0x2c8e)));w16(d+6,(uint16_t)(r16(d+6)+r16(r+0x2c90)));memset(r+0x2c88,0,10);}
  if(!rr_dbc_usb_enqueue(r,1,d,(uint8_t)n)){r[0x2c88]=1;memcpy(r+0x2c8a,d,8);}break;
 case 2:rr_dbc_usb_enqueue(r,2,d,(uint8_t)n);break;
 case 3:if(d[0]==0xb1){r[0x71b4]=d[5];r[0x71b5]=d[6];r[0x71b6]=d[7];rr_dbc_status(r,f,0xe1,d[5]);rr_dbc_status(r,f,0xe2,d[6]);rr_dbc_status(r,f,0xe3,d[7]);r[0x71b8]=1;w16(r+0x341c,r[0x71b4]);}break;
 case 4:rr_dbc_usb_enqueue(r,4,d,(uint8_t)n);if(d[1]==0x31){r[0x71b6]=d[2];rr_dbc_status(r,f,0xe3,d[2]);}break;
 case 5:if(d[0]==0x5a){memcpy(r+0x2d1c,d+2,n-2);r[0x2d74]=d[1];}break;
 default:break;
 }return RR_DBC_DONE;
}
