#include "business_keys.h"
#include "business_cipher.h"
#include <string.h>
static uint32_t le32(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
void rr_business_install_key(uint8_t ram[65536],int mouse,uint32_t selector,const uint8_t table[256]){
 memcpy(ram+(mouse?0x2600:0x3020),table+(selector&15u)*16,16);
}
int rr_business_cipher_wrapper(uint8_t *data,uint8_t length,const uint8_t ram[65536],int mouse){
 if(length>32)return -1;
 uint8_t local[32];uint32_t words[8],key[4];unsigned n=length>>2;
 memcpy(local,data,length);
 if(n){
  for(unsigned i=0;i<n;i++)words[i]=le32(local+i*4);
  for(unsigned i=0;i<4;i++)key[i]=le32(ram+(mouse?0x2600:0x3020)+i*4);
  if(mouse)(void)rr_cipher_encrypt_words(words,n,key);else(void)rr_cipher_decrypt_words(words,n,key);
  for(unsigned i=0;i<n;i++)for(unsigned j=0;j<4;j++)local[i*4+j]=(uint8_t)(words[i]>>(8*j));
 }
 memcpy(data,local,length);return 1;
}
