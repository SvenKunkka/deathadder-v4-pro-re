#include "receiver_storage_startup.h"
static uint32_t w(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void pw(uint8_t*p,uint32_t n){for(unsigned j=0;j<4;j++)p[j]=(uint8_t)(n>>(j*8));}
int rr_receiver_storage_device_ready(uint32_t device,const uint8_t state[2]){return device&&(state[1]&1u)&&state[0]==0;}
int32_t rr_receiver_storage_page_info(const uint8_t*layout,uint32_t entries,uint32_t offset,uint32_t index,uint8_t out[12]){
 uint32_t start=0,page=0;pw(out,0);pw(out+8,0);
 for(uint32_t j=0;j<entries;j++){
  uint32_t count=w(layout+8u*j),size=w(layout+8u*j+4);pw(out+4,size);
  uint32_t selected=offset?(size?(offset-start)/size:0):index-page;
  if(selected>=count)selected=count;
  start+=selected*size;page+=selected;pw(out,start);pw(out+8,page);
  if(selected<count)return 0;
 }
 return -22;
}
int32_t rr_receiver_storage_mount_partitions(uint8_t*m,const uint8_t*image,rr_receiver_storage_io*io){
 const uint32_t device=0x0e06f6ccu;uint8_t info[12];
 for(unsigned j=0;j<2;j++){
  uint32_t ctx=0x1f30u+72u*j,base=j?0x1df000u:0x1db000u,bytes=j?0x3000u:0x2000u;
  pw(m+ctx+56,device);if(!rr_receiver_storage_device_ready(device,m+0x1a1a))return -22;
  pw(m+ctx,base);
  if(rr_receiver_storage_page_info(image+0x1c39c,1,base,0,info))return -22;
  uint32_t size=w(info+4);pw(m+ctx+24,size);pw(m+ctx+28,size?bytes/size:0);
  if(rr_receiver_storage_mount(m+ctx,0x23000000u+ctx,0x0e070394u,io))return -22;
 }
 return 0;
}
int32_t rr_receiver_storage_initialize(uint8_t*m,const uint8_t*image,rr_receiver_storage_io*io){
 m[0x71b0]=0;pw(m+0x2ca4,0x0e06f6ccu);
 if(rr_receiver_storage_device_ready(0x0e06f6ccu,m+0x1a1a))m[0x71b0]=1;
 return rr_receiver_storage_mount_partitions(m,image,io);
}
