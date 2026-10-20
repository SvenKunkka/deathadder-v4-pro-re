/* Reconstructed from exact1.20 Thumb routines. See business-tx-exact.md. */
#include "business_tx.h"
#include "business_cipher.h"
#include <string.h>
static uint32_t r32(const uint8_t *p){return p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void w32(uint8_t*p,uint32_t x){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(x>>(i*8));}
static uint16_t r16(const uint8_t*p){return (uint16_t)(p[0]|p[1]<<8);}
static void w16(uint8_t*p,uint16_t x){p[0]=(uint8_t)x;p[1]=(uint8_t)(x>>8);}
static unsigned ctx(int m,unsigned peer){return (m?0x2978u:0x33e8u)+peer*(m?0xee0u:0xf84u);}
static unsigned wo(int m){return m?0x15eu:0x154u;}
static unsigned ro(int m){return m?0x164u:0x15au;}
static unsigned co(int m){return m?0x16au:0x160u;}
static unsigned so(int m){return m?0x170u:0x166u;}
static unsigned po(int m){return m?0x178u:0x16cu;}
static unsigned qo(int m){return m?0xb2u:0xa7u;}
void rr_bt_init(uint8_t *ram,int m,unsigned peer){
 unsigned b=ctx(m,peer),stride=peer*(m?0xee0u:0xf84u);
 const uint8_t caps[2][6]={{32,16,16,32,32,96},{32,5,16,32,32,96}};
 const uint32_t bases[2][6]={{0x356c,0x376c,0x386c,0x396c,0x3b6c,0x3d6c},{0x2b08,0x2d08,0x2d58,0x2e58,0x3058,0x3258}};
 memset(ram+b+wo(m),0,12);memcpy(ram+b+co(m),caps[m],6);memset(ram+b+so(m),16,6);
 for(unsigned c=0;c<6;c++)w32(ram+b+po(m)+4*c,0x23000000u+stride+bases[m][c]);
 /* Sequence bytes and old entries are deliberately not reset. */
}
uint16_t rr_bt_free(const uint8_t*ram,int m,unsigned peer,unsigned c){
 unsigned b=ctx(m,peer)+c,r=ram[b+ro(m)],w=ram[b+wo(m)],n=ram[b+co(m)];
 if(r==w)return (uint16_t)(n-1);if(r<w)r+=n;return (uint16_t)(r-1-w);
}
uint32_t rr_bt_peek(uint8_t*ram,int m,unsigned peer,unsigned c){
 unsigned b=ctx(m,peer),i=b+c;if(ram[i+ro(m)]==ram[i+wo(m)])return 0;
 uint32_t a=r32(ram+b+po(m)+4*c)+(unsigned)ram[i+ro(m)]*ram[i+so(m)];
 ram[a-0x23000000u+2]=1;return a+4;
}
void rr_bt_pop(uint8_t*ram,int m,unsigned peer,unsigned c){
 unsigned i=ctx(m,peer)+c;uint8_t n=(uint8_t)(ram[i+ro(m)]+1);
 if(n==ram[i+co(m)])n=0;ram[i+ro(m)]=n; /* no empty check */
}
int rr_bt_enqueue(uint8_t*ram,int m,unsigned peer,unsigned c,const uint8_t*body,uint32_t len,uint16_t meta){
 if(m&&c==1){len=(uint16_t)(len-1);body++;ram[0x2a19]=*body;} /* global, even peer1/full */
 unsigned b=ctx(m,peer),i=b+c;uint8_t next=(uint8_t)(ram[i+wo(m)]+1);
 if(next>=ram[i+co(m)])next=0;if(next==ram[i+ro(m)])return 0;
 unsigned a=r32(ram+b+po(m)+4*c)-0x23000000u+(unsigned)ram[i+wo(m)]*ram[i+so(m)];
 ram[a]=(uint8_t)len;ram[a+1]=(uint8_t)meta;ram[a+2]=0;ram[a+4]=(uint8_t)(len+2);
 ram[a+6]=(uint8_t)(ram[i+qo(m)]|(c<<3));memcpy(ram+a+7,body,len);
 next=(uint8_t)(ram[i+wo(m)]+1);if(next==ram[i+co(m)])next=0;ram[i+wo(m)]=next;
 next=(uint8_t)(ram[i+qo(m)]+1);if(next==8)next=1;ram[i+qo(m)]=next;return 1;
}
uint32_t rr_bt_mouse_tx(uint8_t*ram,unsigned peer,unsigned c,uint8_t*data,uint32_t len,rr_bt_before_enqueue hook,void*opaque){
 if(c>=6)return 0;uint8_t tmp[32]={0},frag[68];uint32_t effective=len;
 if(c==1){
  ram[0x6b60]|=data[0];ram[0x6b61]=(uint8_t)(ram[0x6b61]+data[1]);
  w16(ram+0x6b64,(uint16_t)(r16(ram+0x6b64)+(data[2]<<8|data[3])));
  w16(ram+0x6b66,(uint16_t)(r16(ram+0x6b66)+(data[4]<<8|data[5])));
  data[0]=ram[0x6b60];data[1]=ram[0x6b61];data[2]=ram[0x6b65];data[3]=ram[0x6b64];data[4]=ram[0x6b67];data[5]=ram[0x6b66];
 }else if(c==2||c==4){
  memcpy(tmp,data,len);effective=c==2?8:16;uint32_t words[4],key[4];
  for(unsigned i=0;i<4;i++){words[i]=r32(tmp+4*i);key[i]=r32(ram+0x2600+4*i);}
  rr_cipher_encrypt_words(words,effective/4,key);for(unsigned i=0;i<effective/4;i++)w32(tmp+4*i,words[i]);data=tmp;
 }else if(c==3)w32(ram+0x6b68,0);
 uint16_t last=(uint16_t)((effective+5u)/6u-1u);
 if(last>=rr_bt_free(ram,1,peer,c))return 0;
 uint32_t remaining=effective;
 for(unsigned index=0;;index++){
  unsigned chunk=(uint16_t)index==last?remaining:6;
  frag[0]=(uint8_t)(((uint16_t)index==last?0:0x80)|index);memcpy(frag+1,data,chunk);data+=chunk;
  if(hook)hook(opaque,ram,index);
  int ok=rr_bt_enqueue(ram,1,peer,c,frag,(uint16_t)(chunk+1),0xff);
  if(!ok)break; /* r8 retains pre-attempt remaining on failure */
  remaining=(uint16_t)(remaining-chunk);if((uint16_t)(index+1)>last)break;
 }
 if(remaining==0&&c==1)memset(ram+0x6b60,0,8);
 return effective;
}
uint32_t rr_bt_dongle_tx(uint8_t*ram,unsigned peer,unsigned c,uint8_t*data,uint32_t len,rr_bt_before_enqueue hook,void*opaque){
 uint8_t sum=0,frag[68];for(uint32_t i=0;i<len;i++)sum=(uint8_t)(sum+data[i]);data[len]=(uint8_t)-sum;
 uint16_t remaining=(uint16_t)(len+1),last=(uint16_t)(((remaining+3u)>>2)-1u);
 uint32_t result=rr_bt_free(ram,0,peer,c);if(last>=result)return result;
 for(unsigned index=0;;index++){
  unsigned chunk=(uint16_t)index==last?remaining:4;
  frag[0]=(uint8_t)(((uint16_t)index==last?0:0x80)|index);memcpy(frag+1,data,chunk);data+=chunk;
  if(hook)hook(opaque,ram,index);
  result=rr_bt_enqueue(ram,0,peer,c,frag,(uint16_t)(chunk+1),0xff);
  remaining=(uint16_t)(remaining-chunk);if(!result||(uint16_t)(index+1)>last)break;
 }return result;
}
