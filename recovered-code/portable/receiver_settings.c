#include "receiver_settings.h"
#include <string.h>
static uint32_t w(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static uint16_t h(const uint8_t*p){return (uint16_t)((unsigned)p[0]|(unsigned)p[1]<<8);}
static void pw(uint8_t*p,uint32_t x){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(x>>(8*i));}
static void ph(uint8_t*p,uint16_t x){p[0]=(uint8_t)x;p[1]=(uint8_t)(x>>8);}
uint16_t rr_receiver_settings_crc(const uint8_t*p,size_t n,uint16_t seed){
 uint32_t c=seed;for(size_t i=0;i<n;i++){c=((c&255u)<<8)|(c>>8);c^=p[i];c^=(c>>4)&15u;c^=c<<12;c=((c<<5)&0x1fe0u)^(c&65535u);}return (uint16_t)c;
}
static int request(rr_receiver_settings_state*s,unsigned stage){
 unsigned index=(stage==2||stage==4);s->stage=stage;s->entry=stage<3?0x0e05ed64u:0x0e05eb1cu;
 s->args[0]=0x23001f30u+72u*index;s->args[1]=0xa001u+index;s->args[2]=index?0x23002d80u:0x23002db0u;s->args[3]=index?47u:70u;return 1;
}
static int done(rr_receiver_settings_state*s){memset(s,0,sizeof(*s));return 0;}
static int write_record(uint8_t*m,rr_receiver_settings_state*s,unsigned stage){
 unsigned off=stage==3?0x2db0:0x2d80,n=stage==3?70:47;ph(m+off,(uint16_t)n);ph(m+off+n-2,rr_receiver_settings_crc(m+off,n-2,65535));return request(s,stage);
}
static int flush_b(uint8_t*m,rr_receiver_settings_state*s){return (m[0x71ba]&1)?write_record(m,s,4):done(s);}
int rr_receiver_settings_mark(uint8_t*m,uint32_t event){
 if(!m)return -1;if(event==2||event==4){ph(m+0x719e,0);m[0x71ba]|=(uint8_t)(event==2?1:2);}return 0;
}
int rr_receiver_settings_load(uint8_t*m,rr_receiver_settings_state*s){if(!m||!s)return -1;return request(s,1);}
int rr_receiver_settings_flush(uint8_t*m,rr_receiver_settings_state*s){
 if(!m||!s)return -1;if(!m[0x71ba]||h(m+0x719e))return done(s);if(m[0x71ba]&2)return write_record(m,s,3);return flush_b(m,s);
}
int rr_receiver_settings_resume(uint8_t*m,const uint8_t*f,const uint8_t*deviceid,const uint8_t*rtc,rr_receiver_settings_state*s,uint32_t result){
 if(!m||!s)return -1;
 if(s->stage==1){if(!f)return -1;if(h(m+0x2db0)!=70||h(m+0x2df4)!=rr_receiver_settings_crc(m+0x2db0,68,65535))memcpy(m+0x2db0,f+0x1ba28,70);return request(s,2);}
 if(s->stage==2){
  if(!f||!deviceid||!rtc)return -1;
  if(h(m+0x2d80)!=47||h(m+0x2dad)!=rr_receiver_settings_crc(m+0x2d80,45,65535)){
   uint8_t keep[22];memcpy(keep,m+0x2d94,22);memcpy(m+0x2d80,f+0x1b9f8,47);memcpy(m+0x2d94,keep,22);
  }
  uint32_t id=w(m+0x2dcf);if(id==0||id==UINT32_MAX){uint32_t chip=w(deviceid);pw(m+0x2dcf,(chip<<24)|((chip&0xff00)<<8)|((chip>>8)&0xff00)|(chip>>24));rr_receiver_settings_mark(m,4);}
  id=w(m+0x2d8b);if(id==0||id==UINT32_MAX){pw(m+0x2d8b,w(m+0x2dcf));rr_receiver_settings_mark(m,2);}
  if(w(deviceid+4)==0xc000&&w(deviceid)==0x80000000&&w(m+0x2dcf)==0x80){
   if(w(rtc+0x774)>0x3fffffffu)return -4;
   uint64_t state=w(m+0x230)|(uint64_t)w(m+0x234)<<32;state=(state+w(rtc+0x770))*UINT64_C(0x27bb2ee687b0b0fd)+UINT64_C(0xb504f32d);
   pw(m+0x230,(uint32_t)state);pw(m+0x234,(uint32_t)(state>>32));pw(m+0x2dcf,(uint32_t)(state>>32));rr_receiver_settings_mark(m,4);
  }
  return rr_receiver_settings_flush(m,s);
 }
 if(s->stage==3){if(result==0||result==70)m[0x71ba]&=253;return flush_b(m,s);}
 if(s->stage==4){if(result==0||result==47)m[0x71ba]&=254;return done(s);}
 return -1;
}
