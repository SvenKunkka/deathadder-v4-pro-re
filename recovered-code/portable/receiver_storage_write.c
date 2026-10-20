#include "receiver_storage_write.h"
#include <string.h>
static uint32_t w(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static uint16_t h(const uint8_t*p){return (uint16_t)((unsigned)p[0]|(unsigned)p[1]<<8);}
static uint64_t pair(const uint8_t*p){return w(p)|(uint64_t)w(p+4)<<32;}
static void pw(uint8_t*p,uint32_t x){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(x>>(8*i));}
static void ph(uint8_t*p,uint16_t x){p[0]=(uint8_t)x;p[1]=(uint8_t)(x>>8);}
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

static uint32_t align_n(uint32_t n,uint32_t a){return a>1?(n+a-1u)&(0u-a):n;}
static void checksum(uint8_t*r){r[0]=rr_receiver_storage_crc8(r+1,15,255);}
static int valid(const uint8_t*c,const rr_receiver_storage_io*i){return c&&i&&i->read&&i->write&&i->block_size&&i->block_size<=32&&!(i->block_size&(i->block_size-1));}
int32_t rr_receiver_storage_write_bytes(uint8_t*c,uint64_t pos,const uint8_t*data,uint32_t n,rr_receiver_storage_io*i){
 if(!valid(c,i))return -22;if(!n)return 0;uint32_t addr=address(c,pos),whole=(0u-i->block_size)&n;
 if(whole){int32_t rc=i->write(i->user,w(c+56),addr,data,whole);if(rc)return rc;n-=whole;if(!n)return 0;addr+=whole;data+=whole;}
 uint8_t pad[32];memcpy(pad,data,n);memset(pad+n,i->erase_value,i->block_size-n);return i->write(i->user,w(c+56),addr,pad,i->block_size);
}
int32_t rr_receiver_storage_append_data(uint8_t*c,const uint8_t*data,uint32_t n,rr_receiver_storage_io*i){
 int32_t rc=rr_receiver_storage_write_bytes(c,pair(c+16),data,n,i);if(rc<0)return rc;pq(c+16,pair(c+16)+align_n(n,i->block_size));return 0;
}
int32_t rr_receiver_storage_append_record(uint8_t*c,const uint8_t record[16],rr_receiver_storage_io*i){
 int32_t rc=rr_receiver_storage_write_bytes(c,pair(c+8),record,16,i);if(!rc)pq(c+8,pair(c+8)-align_n(16,i->block_size));return rc;
}
int32_t rr_receiver_storage_initialize_page(uint8_t*c,uint32_t page,rr_receiver_storage_io*i){
 if(!valid(c,i))return -22;uint8_t epoch=0;int32_t rc=page_epoch(c,page,&epoch,i->read,i->user);if(rc==-2)epoch=0;else if(rc)return rc;
 uint8_t record[16]={0};record[1]=(uint8_t)(epoch+1);ph(record+2,65535);pw(record+4,UINT32_MAX);pw(record+12,0x4201);checksum(record);
 uint64_t saved=pair(c+8);pq(c+8,((uint64_t)page<<32)+w(c+24)-w(c+64));rc=rr_receiver_storage_append_record(c,record,i);if(!rc)pq(c+8,saved);return rc;
}
int32_t rr_receiver_storage_rotate(uint8_t*c,rr_receiver_storage_io*i){
 if(!valid(c,i))return -22;uint64_t pos=pair(c+8);uint8_t record[16]={0},empty[16];record[1]=c[32];pw(record+4,UINT32_MAX);pw(record+8,w(c+64)+(uint32_t)pos);pw(record+12,UINT32_MAX);memset(empty,i->erase_value,16);
 while((uint32_t)pos&&pos>=pair(c+16)){int32_t rc=rr_receiver_storage_append_record(c,empty,i);if(rc)return rc;pos=pair(c+8);}
 pq(c+8,((pos>>32)<<32)+w(c+24)-(uint32_t)(2u*w(c+64)));checksum(record);
 (void)rr_receiver_storage_append_record(c,record,i); /* Original ignores this result. */
 uint32_t page=w(c+12)+1u;if(page==w(c+28))page=0;pw(c+12,page);int32_t rc=page_epoch(c,page,c+32,i->read,i->user);
 if(rc==-2)c[32]=0;else if(rc)return rc;pq(c+16,(uint64_t)page<<32);return 0;
}
int32_t rr_receiver_storage_collect(uint8_t*c,rr_receiver_storage_io*i){
 if(!valid(c,i))return -22;int32_t rc=page_epoch(c,w(c+12),c+32,i->read,i->user);
 if(rc==-2){rc=rr_receiver_storage_initialize_page(c,w(c+12),i);if(rc)return rc;rc=page_epoch(c,w(c+12),c+32,i->read,i->user);}if(rc)return rc;
 uint8_t epoch=c[32];uint32_t page=w(c+12)+1u;if(page==w(c+28))page=0;
 uint64_t end=((uint64_t)page<<32)+w(c+24)-w(c+64);uint8_t head[16],close[16];rc=page_pair(c,(uint32_t)(end>>32),head,close,i->read,i->user);if(rc<0)return rc;
 if(rc){uint64_t scan=(end&UINT64_C(0xffffffff00000000))|w(close+8),stop=end-(uint32_t)(2u*w(c+64));c[32]=head[1];
  for(;;){uint64_t current=scan;uint8_t record[16];rc=read_at(c,current,record,16,i->read,i->user);if(rc)return rc;rc=advance(c,&scan,i->read,i->user);if(rc)return rc;
   if(record[1]==c[32]&&crc_ok(record)&&h(record+2)){
    uint64_t found=current;uint8_t latest[16];rc=find(c,w(record+4),pair(c+8),pair(c+8),latest,&found,i->read,i->user);if(rc<0)return rc;
    if(found==current){uint32_t remaining=h(record+2);
     if(remaining>8){uint64_t from=(current&UINT64_C(0xffffffff00000000))|w(record+8);pw(record+8,w(c+16));uint32_t chunk=(0u-i->block_size)&32u;
      while(remaining){uint32_t n=remaining<chunk?remaining:chunk;uint8_t data[32];rc=read_at(c,from,data,n,i->read,i->user);if(rc)return rc;rc=rr_receiver_storage_append_data(c,data,n,i);if(rc)return rc;from+=n;remaining-=n;}
     }
     record[1]=epoch;checksum(record);rc=rr_receiver_storage_append_record(c,record,i);if(rc)return rc;
    }
   }
   if(current==stop)break;
  }
 }
 c[32]=epoch;uint8_t marker[16]={0};marker[1]=epoch;pw(marker+4,UINT32_MAX);pw(marker+8,w(c+16));pw(marker+12,UINT32_MAX);checksum(marker);
 rc=rr_receiver_storage_append_record(c,marker,i);if(rc)return rc;return rr_receiver_storage_initialize_page(c,page,i);
}
int32_t rr_receiver_storage_write(uint8_t*c,uint32_t ctxaddr,uint32_t key,const uint8_t*data,uint32_t n,rr_receiver_storage_io*i){
 if(!valid(c,i))return -22;if(!c[33])return -13;uint32_t aligned=align_n(n,i->block_size),slot=w(c+64),allocation=aligned;
 if(n>w(c+24)-5u*slot||n>=65536u||(n&&!data))return -22;if(aligned)allocation=n>8?aligned+slot:slot;if(!i->lock||!i->unlock)return -22;
 (void)i->lock(i->user,ctxaddr+36,UINT64_MAX);int32_t result=-28;
 if(w(c+28)){uint32_t tries=0;for(;;){tries++;uint64_t writepos=pair(c+8),datapos=pair(c+16);
  if((uint32_t)writepos&&writepos>=datapos+allocation&&((uint32_t)writepos!=slot||!n)){
   uint8_t record[16]={0};record[1]=c[32];ph(record+2,(uint16_t)n);pw(record+4,key);
   if(n>8){pw(record+8,(uint32_t)datapos);checksum(record);result=rr_receiver_storage_append_data(c,data,n,i);if(result)break;}
   else{if(n)memcpy(record+8,data,n);checksum(record);}
   result=rr_receiver_storage_append_record(c,record,i);if(!result)result=(int32_t)n;break;
  }
  result=rr_receiver_storage_rotate(c,i);if(result)break;result=rr_receiver_storage_collect(c,i);if(result)break;if(tries==w(c+28)){result=-28;break;}
 }}
 (void)i->unlock(i->user,ctxaddr+36);return result;
}

int rr_receiver_settings_write_continue(uint8_t*m,const uint8_t*image,const uint8_t*deviceid,const uint8_t*rtc,rr_receiver_settings_state*s,rr_receiver_storage_io*i){
 if(!m||!image||!deviceid||!rtc||!s||!i)return -1;
 while(s->stage==3||s->stage==4){unsigned index=s->stage-3;uint32_t off=0x1f30+72*index;int32_t raw=rr_receiver_storage_write(m+off,0x23000000u+off,s->args[1],m+(index?0x2d80:0x2db0),index?47:70,i);
  int rc=rr_receiver_settings_resume(m,image,deviceid,rtc,s,(uint32_t)raw);if(rc<0)return rc;
 }
 return s->stage?1:0;
}
