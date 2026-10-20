#include "receiver_storage_read.h"
#include <string.h>
static uint32_t w(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static uint16_t h(const uint8_t*p){return (uint16_t)((unsigned)p[0]|(unsigned)p[1]<<8);}
static uint64_t pair(const uint8_t*p){return w(p)|(uint64_t)w(p+4)<<32;}
uint8_t rr_receiver_storage_crc8(const uint8_t*p,size_t n,uint8_t seed){
 static const uint8_t tab[16]={0,7,14,9,28,27,18,21,56,63,54,49,36,35,42,45};uint8_t c=seed;
 for(size_t i=0;i<n;i++){c^=p[i];c=(uint8_t)(tab[c>>4]^(uint8_t)(c<<4));c=(uint8_t)(tab[c>>4]^(uint8_t)(c<<4));}return c;
}
static uint32_t address(const uint8_t*c,uint64_t pos){return w(c)+(uint32_t)pos+(uint32_t)(pos>>32)*w(c+24);}
static int32_t read_at(const uint8_t*c,uint64_t pos,uint8_t*b,uint32_t n,rr_storage_read_fn f,void*u){return f(u,w(c+56),address(c,pos),b,n);}
static int crc_ok(const uint8_t*b){return b[0]==rr_receiver_storage_crc8(b+1,15,255);}
static int32_t page_epoch(const uint8_t*c,uint32_t page,uint8_t*epoch,rr_storage_read_fn f,void*u){
 uint8_t b[16];uint64_t pos=((uint64_t)page<<32)+w(c+24)-w(c+64);int32_t rc=read_at(c,pos,b,16,f,u);if(rc<0)return rc;
 if(!crc_ok(b)||h(b+2)!=65535||w(b+4)!=UINT32_MAX)return -2;*epoch=b[1];return 0;
}
static int32_t page_pair(const uint8_t*c,uint32_t page,uint8_t*head,uint8_t*close,rr_storage_read_fn f,void*u){
 uint64_t pos=((uint64_t)page<<32)+w(c+24)-(uint32_t)(2u*w(c+64));int32_t rc=read_at(c,pos,close,16,f,u);if(rc)return rc;
 rc=read_at(c,pos+w(c+64),head,16,f,u);if(rc)return rc;
 if(!crc_ok(head)||h(head+2)!=65535||w(head+4)!=UINT32_MAX||!crc_ok(close)||h(close+2)!=0||w(close+4)!=UINT32_MAX)return 0;
 uint32_t delta=w(c+24)-w(close+8),align=w(c+64);
 /* ARM unsigned divide by zero yields0 for this configured emulation domain. */
 if((align?delta%align:delta)!=0)return 0;return head[1]==close[1];
}
static int32_t advance(const uint8_t*c,uint64_t*pos,rr_storage_read_fn f,void*u){
 *pos+=w(c+64);if((uint32_t)*pos!=w(c+24)-2u*w(c+64))return 0;
 uint32_t page=(uint32_t)(*pos>>32);page=(page? page:w(c+28))-1u;*pos=(*pos&UINT32_MAX)|((uint64_t)page<<32);
 uint8_t head[16],close[16];int32_t rc=page_pair(c,page,head,close,f,u);if(rc<0)return rc;
 if(!rc)*pos=pair(c+8);else *pos=(*pos&UINT64_C(0xffffffff00000000))|w(close+8);return 0;
}
static int32_t find(const uint8_t*c,uint32_t key,uint64_t start,uint64_t end,uint8_t*out,uint64_t*found,rr_storage_read_fn f,void*u){
 uint64_t next=start;int32_t cached=-1;uint8_t epoch=0,record[16];
 for(;;){uint64_t current=next;int32_t rc=read_at(c,current,record,16,f,u);if(rc)return rc;rc=advance(c,&next,f,u);if(rc)return rc;
  if(w(record+4)==key){uint32_t page=(uint32_t)(current>>32);if(cached<0||(uint32_t)cached!=page){rc=page_epoch(c,page,&epoch,f,u);if(rc==-2)epoch=0;else if(rc)return rc;}
   if(record[1]==epoch&&crc_ok(record)){memcpy(out,record,16);*found=current;return 1;}cached=(int32_t)page;
  }
  if(next==end){memcpy(out,record,16);*found=current;return 0;}
 }
}
int32_t rr_receiver_storage_read_history(const uint8_t*c,uint32_t key,uint8_t*dest,uint32_t capacity,uint32_t history,const uint8_t prior[16],rr_storage_read_fn f,void*u){
 if(!c||!f||!prior)return -22;if(!c[33])return -13;uint64_t pos=pair(c+8);uint32_t seen=0;uint8_t record[16];memcpy(record,prior,16);
 for(;;){int32_t rc=find(c,key,pos,pair(c+8),record,&pos,f,u);seen++;if(rc<0)return rc;if(!rc)return -2;
  uint32_t page=(uint32_t)(pos>>32);rc=advance(c,&pos,f,u);if(rc)return rc;if(seen<=history)continue;
  if(w(record+4)!=key||!h(record+2))return -2;uint32_t n=h(record+2),copy=capacity<n?capacity:n;
  if(dest){if(n<9)memcpy(dest,record+8,copy);else{rc=read_at(c,((uint64_t)page<<32)|w(record+8),dest,copy,f,u);if(rc)return rc;}}
  return (int32_t)n;
 }
}
int32_t rr_receiver_storage_read(const uint8_t*c,uint32_t key,uint8_t*dest,uint32_t capacity,const uint8_t prior[16],rr_storage_read_fn f,void*u){
 int32_t rc=rr_receiver_storage_read_history(c,key,dest,capacity,0,prior,f,u);return rc>=0&&(uint32_t)rc>=capacity?(int32_t)capacity:rc;
}

int32_t rr_receiver_storage_mapped_read(void*u,uint32_t device,uint32_t offset,uint8_t*dest,uint32_t n){
 (void)device;if(offset>=0x200000u||n>0x200000u-offset)return -22;if(n)memcpy(dest,(const uint8_t*)u+offset,n);return 0;
}
int32_t rr_receiver_storage_mapped_write(uint8_t*flash,uint32_t offset,const uint8_t*data,uint32_t n){
 if(offset>=0x200000u||n>0x200000u-offset||((offset|n)&15u))return -22;if(n)memcpy(flash+offset,data,n);return 0;
}
int32_t rr_receiver_storage_mapped_erase(uint8_t*flash,uint32_t offset,uint32_t n){
 if(offset>=0x200000u||n>0x200000u-offset||((offset|n)&15u))return -22;if(n)memset(flash+offset,255,n);return 0;
}
int rr_receiver_settings_read_continue(uint8_t*m,const uint8_t*image,const uint8_t*deviceid,const uint8_t*rtc,rr_receiver_settings_state*s,const uint8_t prior[32],rr_storage_read_fn f,void*u){
 if(!m||!image||!deviceid||!rtc||!s||!prior||!f)return -1;
 while(s->stage==1||s->stage==2){unsigned index=s->stage-1;int32_t raw=rr_receiver_storage_read(m+0x1f30+72*index,s->args[1],m+(index?0x2d80:0x2db0),index?47:70,prior+16*index,f,u);
  int rc=rr_receiver_settings_resume(m,image,deviceid,rtc,s,(uint32_t)raw);if(rc<0)return rc;
 }
 return s->stage?1:0;
}
