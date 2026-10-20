#include "receiver_storage_mount.h"
#include <string.h>
static uint32_t w(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static uint16_t h(const uint8_t*p){return (uint16_t)((unsigned)p[0]|(unsigned)p[1]<<8);}
static uint64_t pair(const uint8_t*p){return w(p)|(uint64_t)w(p+4)<<32;}
static void pw(uint8_t*p,uint32_t x){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(x>>(8*i));}
static void pq(uint8_t*p,uint64_t x){pw(p,(uint32_t)x);pw(p+4,(uint32_t)(x>>32));}
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

static int32_t raw_pair(const uint8_t*c,uint32_t page,uint8_t*head,uint8_t*close,rr_receiver_storage_io*i){
 uint64_t pos=((uint64_t)page<<32)+w(c+24)-(uint32_t)(2u*w(c+64));
 int32_t rc=read_at(c,pos,close,16,i->read,i->user);if(rc)return rc;
 return read_at(c,pos+w(c+64),head,16,i->read,i->user);
}
int32_t rr_receiver_storage_mount(uint8_t*c,uint32_t ctxaddr,uint32_t parameter_address,rr_receiver_storage_io*i){
 uint32_t mutex=ctxaddr+36;pw(c+36,mutex);pw(c+40,mutex);pw(c+44,0);pw(c+48,0);
 pw(c+60,parameter_address);if(!parameter_address)return -22;
 uint32_t block=i->block_size;pw(c+64,block<=1?16:(block+15u)&(0u-block));
 if(block-1u>31u||w(c+28)<=1)return -22;
 uint8_t recordpos[8]={0},datapos[8]={0},head[16],close[16],record[16];
 (void)i->lock(i->user,mutex,UINT64_MAX);
 int32_t rc=0;uint32_t index=0,closed=0;int modern=0;
 if(!w(c+28)){rc=-134;goto done;}
 for(;;){
  uint64_t at=((uint64_t)index<<32)+w(c+24)-(uint32_t)(2u*w(c+64));pq(recordpos,at);
  rc=page_pair(c,(uint32_t)(at>>32),head,close,i->read,i->user);if(rc<0)goto done;
  c[32]=head[1];
  if(rc==1){
   closed++;uint32_t version=w(head+12);
   if((version&0xff00u)==0x4200u){if((version&255u)!=1u){rc=-123;goto done;}modern=1;}
   uint32_t page=(uint32_t)(at>>32)+1u;if(page==w(c+28))page=0;
   pq(recordpos,((uint64_t)page<<32)|(uint32_t)at);
   rc=page_pair(c,page,head,close,i->read,i->user);if(rc<0)goto done;c[32]=head[1];
   if(rc==0)break;
  }
  index++;if(index>=w(c+28))break;
 }
 if(closed==w(c+28)&&!modern){rc=-134;goto done;}
 if(index==w(c+28)){
  uint64_t pos=pair(recordpos);rc=read_at(c,pos-w(c+64),record,16,i->read,i->user);if(rc)goto done;
  if(record[1]!=c[32]||!crc_ok(record)){
   uint32_t page=(uint32_t)(pos>>32)+1u;if(page==w(c+28))page=0;
   pos=((uint64_t)page<<32)|(uint32_t)pos;pq(recordpos,pos);
  }
  uint32_t page=(uint32_t)(pos>>32);rc=raw_pair(c,page,head,close,i);if(rc)goto done;
  if(crc_ok(head)&&h(head+2)==65535&&w(head+4)==UINT32_MAX){
   uint32_t version=w(head+12);if((version&0xff00u)==0x4200u&&(version&255u)!=1u){rc=-123;goto done;}
  }else{rc=rr_receiver_storage_initialize_page(c,page,i);if(rc)goto done;}
  rc=page_epoch(c,page,c+32,i->read,i->user);if(rc==-2)c[32]=0;else if(rc)goto done;
 }
 rc=rr_receiver_storage_scan(c,recordpos,datapos,block,i->read,i->user);if(rc)goto done;
 memcpy(c+8,recordpos,8);memcpy(c+16,datapos,8);
 while(pair(c+8)>=pair(c+16)){
  rc=read_at(c,pair(c+8),record,16,i->read,i->user);if(rc)goto done;
  if(record[1]!=c[32]||!crc_ok(record))break;
  if(pair(c+8)==pair(c+16)&&h(record+2)!=0){rc=-29;goto done;}
  pq(c+8,pair(c+8)-w(c+64));
 }
 {
  uint32_t twice=2u*w(c+64),page=w(c+12)+(w(c+24)>=twice?1u:0u);if(page==w(c+28))page=0;
  rc=page_pair(c,page,head,close,i->read,i->user);if(rc<0)goto done;
  if(rc==1){
   uint64_t scan=pair(c+8)+w(c+64);c[32]=head[1];
   while((uint32_t)scan<w(c+24)-2u*w(c+64)){
    rc=read_at(c,scan,record,16,i->read,i->user);if(rc)goto done;
    if(crc_ok(record)&&h(record+2)==0&&w(record+4)==UINT32_MAX)break;
    scan+=w(c+64);
   }
   rc=rr_receiver_storage_initialize_page(c,w(c+12),i);if(rc)goto done;
   pq(c+16,(uint64_t)w(c+12)<<32);pw(c+8,w(c+24)-3u*w(c+64));
   rc=rr_receiver_storage_collect(c,i);if(rc)goto done;
  }
 }
 if(w(c+8)==w(c+24)-3u*w(c+64)){
  memset(record,0,16);record[1]=c[32];pw(record+4,UINT32_MAX);pw(record+8,w(c+16));pw(record+12,UINT32_MAX);
  record[0]=rr_receiver_storage_crc8(record+1,15,255);rc=rr_receiver_storage_append_record(c,record,i);if(rc)goto done;
 }
 (void)i->unlock(i->user,mutex);c[33]=1;return 0;
done:
 (void)i->unlock(i->user,mutex);return rc;
}
