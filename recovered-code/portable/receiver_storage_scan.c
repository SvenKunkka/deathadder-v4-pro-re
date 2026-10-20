#include "receiver_storage_scan.h"
static uint32_t word(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static uint64_t wide(const uint8_t*p){return (uint64_t)word(p)|((uint64_t)word(p+4)<<32);}
static void put(uint8_t*p,uint64_t n){for(unsigned j=0;j<8;j++)p[j]=(uint8_t)(n>>(j*8));}
int32_t rr_receiver_storage_scan(const uint8_t c[72],uint8_t record[8],uint8_t data[8],uint32_t block,rr_storage_read_fn read,void*user){
 uint64_t pos=wide(record)-(uint32_t)(word(c+64)<<1);
 uint64_t page=pos&UINT64_C(0xffffffff00000000);
 uint32_t end=0;
 put(record,pos);put(data,page);
 if((uint32_t)pos==0)return 0;
 do{
  uint8_t item[16];
  uint32_t address=word(c)+(uint32_t)pos+(uint32_t)(pos>>32)*word(c+24);
  int32_t result=read(user,word(c+56),address,item,16);
  if(result!=0)return result;
  if(item[1]==c[32]&&item[0]==rr_receiver_storage_crc8(item+1,15,255)){
   uint32_t length=(uint32_t)item[2]|(uint32_t)item[3]<<8;
   end=0;
   if(length>8){
    if(block>1)length=(length-1+block)&(0u-block);
    /* ADD at E0B4 does not set flags. E0B6 adds the known-zero driver
     * result, so overflow of data offset+length does not carry into page. */
    end=word(item+8)+length;
    put(data,page|end);
   }
   put(record,pos);
  }
  pos-=word(c+64);
 }while(pos>(page|end));
 return 0;
}
