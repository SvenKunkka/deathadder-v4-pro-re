#include "receiver_usb_reports.h"
#include <string.h>
static uint32_t rd(const uint8_t*m,uint32_t a){return (uint32_t)m[a]|(uint32_t)m[a+1]<<8|(uint32_t)m[a+2]<<16|(uint32_t)m[a+3]<<24;}
static void wr(uint8_t*m,uint32_t a,uint32_t v){for(unsigned i=0;i<4;i++)m[a+i]=(uint8_t)(v>>(8*i));}
static void clear_indices(uint8_t*m){memset(m+0x6834,0,3);memset(m+0x6838,0,3);}
static void advance(uint8_t*m,unsigned ch){uint8_t v=(uint8_t)(m[0x6834+ch]+1);m[0x6834+ch]=v==4?0:v;}
static int invoke(uint8_t*m,rr_receiver_usb_external_driver driver,void*user,rr_receiver_usb_call*call,uint32_t dev,uint32_t len,uint32_t buf,int32_t*result){
 *call=(rr_receiver_usb_call){0x0e064288,dev,len,0x23000000+buf};
 if(!driver)return 1;
 *result=driver(user,m,call);return 0;
}
int rr_receiver_usb_reports(uint8_t*m,uint8_t*aux,uint32_t entry,rr_receiver_usb_external_driver driver,void*user,rr_receiver_usb_call*pending){
 if(!m||!pending||(entry!=0x23026948&&entry!=0x23026d28)||(entry==0x23026d28&&!aux))return -1;
 *pending=(rr_receiver_usb_call){0,0,0,0};
 if(entry==0x23026d28){for(unsigned i=0;i<21;i++){wr(aux,0x48,1);if(rd(aux,0x548)-1>0x44||m[0x6838]!=m[0x6834])break;}}
 uint32_t buffer=(rd(m,0x6830)&1)?0x1e80:0x1e60;int32_t result;
 if(!m[0x71e4])return 0;
 if(m[0x6904]<=1&&m[0x6834]!=m[0x6838]){
  if(m[0x6834]<4){memcpy(m+buffer,m+0x683c+16*m[0x6834],8);if(m[0x6904]<=1)m[0x6904]++;
   if(invoke(m,driver,user,pending,0x0e06f6a4,8,buffer,&result))return 1;
   if(!result){advance(m,0);wr(m,0x6830,1-rd(m,0x6830));}else if(m[0x6904])m[0x6904]--;
  }else clear_indices(m);
 }
 for(unsigned ch=1;ch<3;ch++){
  if(!m[0x6900+ch]&&m[0x6834+ch]!=m[0x6838+ch]){
   if(m[0x6834+ch]<4){uint32_t len=ch==1?16:8;buffer=ch==1?0x1e40:0x1e20;
    m[0x6900+ch]=1;m[0x6908+ch]=3;memcpy(m+buffer,m+0x683c+16*(m[0x6834+ch]+4*ch),len);
    if(invoke(m,driver,user,pending,ch==1?0x0e06f690:0x0e06f67c,len,buffer,&result))return 1;
    if(!result)advance(m,ch);else{m[0x6900+ch]=0;m[0x6908+ch]=0;}
   }else clear_indices(m);
  }
 }
 *pending=(rr_receiver_usb_call){0,0,0,0};return 0;
}
