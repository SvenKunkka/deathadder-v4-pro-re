#include "receiver_vendor_commands.h"
#include "business_tx.h"
#include <string.h>
static uint32_t rd(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void wr(uint8_t*p,uint32_t v){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(v>>(8*i));}
static uint32_t rev(uint32_t v){return v>>24|(v>>8&0xff00u)|(v<<8&0xff0000u)|v<<24;}
static int stop(rr_receiver_vendor_pending*p,uint32_t entry,uint32_t arg){p->entry=entry;p->arg0=arg;p->arg0_valid=1;return 1;}
static void dirty(uint8_t*m,unsigned kind){m[0x719e]=m[0x719f]=0;m[0x71ba]|=kind==2?1:2;}
static void checksum(uint8_t*m){uint8_t sum=0;for(unsigned i=0x2d1e;i<0x2d74;i++)sum^=m[i];m[0x2d74]=sum;}
static void led_status(uint8_t*m,const uint8_t*f){
 for(unsigned i=0;i<3;i++){uint8_t*t=m+0x2ca8+4*i;unsigned type=m[0x2cb4+i],off;
  if(type==1)off=0x1b7d4+4*((m[0x71b6]*100u)/255u);
  else if(type==2)off=0x1b7c0+4*m[0x71b3];
  else if(type==3){unsigned bit=0;while(bit<7&&!(m[0x71b4]&(1u<<bit)))bit++;if(bit==7)continue;off=0x1b7a4+4*bit;}
  else if(type==4)off=0x1b790+4*m[0x71b5];
  else{memset(t,0,3);t[3]=1;continue;}
  memcpy(t,f+off,3);t[3]=1;
 }
}
static int local(uint8_t*m,const uint8_t*f,const uint8_t*radio,const uint8_t*id,const uint8_t*boot,uint32_t incoming,rr_receiver_vendor_pending*p){
 uint8_t*d=m+0x2d1c,*v=d+8;unsigned cls=d[6],cmd=d[7],target=d[1]>>5;
 if(cls==15){d[0]=2;return 0;}if(cls==16)return stop(p,0x0e05be8c,incoming);
 if(cls==7){
  switch(cmd){
   case 0x95:memcpy(v,m+0x2cb4,3);d[0]=2;break;
   case 0x96:v[0]=m[0x71b3];d[0]=2;break;
   case 0x97:memcpy(v,m+0x2daa,3);d[0]=2;break;
   case 0x17:if(memcmp(v,m+0x2daa,3)){memcpy(m+0x2daa,v,3);dirty(m,2);}d[0]=2;break;
   case 0x15:if(v[0]>4||v[1]>4||v[2]>4){d[0]=3;break;}memcpy(m+0x2cb4,v,3);if(memcmp(v,m+0x2d91,3)){memcpy(m+0x2d91,v,3);dirty(m,2);}led_status(m,f);d[0]=2;break;
   default:break;
  }return 0;
 }
 if(cls==0){
  switch(cmd){
   case 4:if(target!=7)break;m[0x71bd]=v[0];if((v[0]==0||v[0]==3)&&m[0x71b2]){if(!m[0x2c80])return stop(p,0x23025954,0);led_status(m,f);m[0x71b2]=0;}d[0]=2;break;
   case 0x0b:if(v[0]==1)return stop(p,0x23025300,rev(rd(m+0x2d8b)));if(v[0]==3){m[0x2d82]=m[0x2d83]=255;dirty(m,2);d[0]=2;}else if(v[0]==5)d[0]=2;break;
   case 0x0d:memcpy(m+0x2db5,v,4);dirty(m,4);d[0]=2;break;
   case 0x12:memcpy(m+0x2db9,v,20);dirty(m,4);d[0]=2;break;
   case 0x15:if(rd(m+0x2dcf)!=rd(v)){uint32_t value=rd(v);wr(m+0x2dcf,value);wr(m+0x2d8b,value);if(value==0||value==UINT32_MAX){value=rev(rd(id));wr(m+0x2dcf,value);wr(m+0x2d8b,value);}dirty(m,4);dirty(m,2);return stop(p,0x230252a4,rev(value));}d[0]=2;break;
   case 0x3c:memcpy(m+0x2db3,v,2);dirty(m,4);d[0]=2;break;
   case 0x45:if(v[0]==1||v[0]==2){m[0x2dd3]=v[0];memcpy(m+(v[0]==1?0x2d82:0x2d84),v+1,2);d[0]=2;dirty(m,4);dirty(m,2);}break;
   case 0x46:case 0xc6:d[0]=2;break;
   case 0x8d:memcpy(v,m+0x2db5,4);d[0]=2;break;
   case 0x91:memcpy(v,f+0x1ba70,2);d[0]=2;break;
   case 0x92:memcpy(v,m+0x2db9,20);d[0]=2;break;
   case 0x93:memcpy(v,f+0x1ba70,4);d[0]=2;break;
   case 0x95:memcpy(v,m+0x2dcf,4);memcpy(v+4,m+0x2d8b,4);d[0]=2;break;
   case 0x9f:for(unsigned i=0;i<4;i++)v[i]=boot[4*i];d[0]=2;break;
   case 0xb8:v[0]=(uint8_t)((m[0x2c80]>>1)&3);d[0]=2;break;
   case 0xba:v[0]=2;v[1]=(m[0x2c80]>>1)&1;v[2]=(m[0x2c80]>>2)&1;d[0]=2;break;
   case 0xbc:memcpy(v,m+0x2db3,2);d[0]=2;break;
   case 0xbf:v[0]=2;v[1]=(m[0x2c80]>>1)&1;memcpy(v+2,m+0x2d82,2);v[4]=(m[0x2c80]>>2)&1;memcpy(v+5,m+0x2d84,2);d[0]=2;break;
   case 0xc3:memset(v,0,4);d[0]=2;break;
   case 0xc5:if(m[0x2dd3]==1||m[0x2dd3]==2){v[0]=m[0x2dd3];memcpy(v+1,m+(v[0]==1?0x2d82:0x2d84),2);d[0]=2;}break;
   default:break;
  }return 0;
 }
 if(cls!=0xfe)return 0;
 switch(cmd){
  case 0x33:if(target!=7)break;if(m[0x71bd]!=2){d[0]=3;break;}m[0x71b2]=1;if(v[0])return stop(p,0x23025fe0,v[1]);{unsigned color=0;if(v[1]==255){if(!v[2]&&!v[3])color=2;else if((v[2]&v[3])==255)color=1;}else if(!v[1]){if(v[2]==255&&!v[3])color=3;else if(!v[2]&&v[3]==255)color=4;}return stop(p,0x23025954,color);}
  case 0x70:m[0x6595]=1;return stop(p,0x0e05c504,0x23002d24);
  case 0x71:m[0x6595]=1;return stop(p,0x0e05c5ec,0x23002d24);
  case 0x72:return stop(p,0x23024db4,(unsigned)v[0]*256u+v[1]);
  case 0x73:if(target==7){memcpy(m+0x2d94,v,22);dirty(m,2);d[0]=2;}break;
  case 0x7f:{m[0x31fa]=v[0]!=0;m[0x31fb]=v[1];unsigned n=v[1];if(!n||n>40)m[0x31fa]=0;else for(unsigned i=0;i<n;i++){unsigned b=v[2+i],out=0;if(b>=2&&b<=128){unsigned value=(b>>4)*10+(b&15);if(value==2)out=37;else if(value<26)out=(value-4u)>>1;else if(value==26)out=38;else if(value<80)out=(unsigned)(((int)value-28)>>1)+11u;else out=39;}m[0x31fc+i]=(uint8_t)out;}d[0]=2;break;}
  case 0xf1:return stop(p,0x0e05c6d4,0x23002d24);
  case 0xf3:if(target==7){memcpy(v,m+0x2d94,22);d[0]=2;}break;
  case 0xfa:memcpy(v,id+4,4);memcpy(v+4,id,4);d[0]=2;break;
  case 0xfb:memset(v,0,32);memcpy(v,m+0x3244,4);memcpy(v+4,m+0x324c,4);memcpy(v+8,radio+0xe30,4);memcpy(v+12,radio+0xe34,4);v[19]=m[0x3230];v[24]=m[0x33e8];v[25]=m[0x3468];v[26]=m[0x34b0];v[27]=m[0x34b2];v[28]=m[0x34b4];v[29]=m[0x34b6];v[30]=m[0x34b8];d[0]=2;break;
  case 0xff:d[0]=2;break;
  default:break;
 }return 0;
}
int rr_receiver_vendor_commands(uint8_t*m,const uint8_t*f,const uint8_t*radio,const uint8_t id[8],const uint8_t boot[16],uint32_t entry,uint32_t incoming,rr_receiver_vendor_pending*p){
 if(!m||!f||!radio||!id||!boot||!p||(entry!=0x2302604c&&entry!=0x23026090&&entry!=0x230205f8))return -1;*p=(rr_receiver_vendor_pending){0,0,0};
 if(entry==0x2302604c)return local(m,f,radio,id,boot,incoming,p);
 if(m[0x71bb]){uint8_t sum=0;for(unsigned i=0x2d1e;i<0x2d74;i++)sum^=m[i];
  if(sum!=m[0x2d74])m[0x2d1c]=3;
  else{unsigned target=m[0x2d1d]>>5,peer=target==0?1:target==4?2:target==7?0:255;int rc=local(m,f,radio,id,boot,sum,p);if(rc)return rc;
   if(m[0x2d1c]==1){if(peer>=32||!((m[0x2c80]>>peer)&1)){m[0x2d1c]=4;checksum(m);}
    else if(peer==1||peer==2){unsigned n=m[0x2d21];if(n>80)return -2;m[0x2cb8]=0x5a;m[0x2cb9]=m[0x2d74];memcpy(m+0x2cba,m+0x2d1c,n+8);rr_bt_dongle_tx(m,peer-1,5,m+0x2cb8,n+10,0,0);}
    else{m[0x2d1c]=3;checksum(m);}
   }else checksum(m);
  }m[0x71bb]=0;
 }
 if(entry==0x230205f8){p->entry=0x0e05c774;p->arg0_valid=0;return 1;}return 0;
}
