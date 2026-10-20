#include "receiver_initialization.h"
#include "business_keys.h"
#include <string.h>
static uint32_t w(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void pw(uint8_t*p,uint32_t v){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(v>>(i*8));}
static void ph(uint8_t*p,uint16_t v){p[0]=(uint8_t)v;p[1]=(uint8_t)(v>>8);}
static void irq(uint8_t*n,unsigned number,unsigned priority){n[0x400+number]=(uint8_t)priority;pw(n+0x280+4*(number/32),1u<<(number%32));pw(n+0x100+4*(number/32),1u<<(number%32));}
int rr_receiver_radio_initialize(rr_receiver_init_hw*x,uint32_t id,uint8_t phy){
 if(!x||!x->ram||!x->radio||!x->nvic)return -1;uint8_t*m=x->ram,*r=x->radio,*n=x->nvic;
 pw(n+0x184,0x1000);pw(r+0x10,1);pw(r+0x704,1);pw(r+0xe3c,3);pw(r+0xe40,6);pw(r+0xe34,0xc3c2c1e7);pw(r+0xe38,0xc7c6c5c4);pw(r+0xe2c,0xeb8a542c);pw(r+0xe30,id);pw(r+0x500,phy);pw(r+0x710,0x1a);
 ph(m+0x303b,0x101);pw(m+0x3030,0);pw(m+0x3034,0);ph(m+0x3038,0);m[0x303a]=3;m[0x3030]=5;m[0x3038]=31;m[0x3035]=1;
 m[0x3045]=1;m[0x304c]=1;pw(r+0xe20,0x1000005);pw(r+0xe28,0x303001f);ph(m+0x3040,5);m[0x3042]=0;
 pw(r+0xe44,0x102);pw(r+0xe48,0x11021);pw(r+0xe4c,0xffff);pw(r+0x400,w(r+0x400)|0x80001);pw(m+0x3048,0x102001f);pw(r+0x488,0x100);
 pw(r+0x20c,0);pw(r+0x200,0);pw(r+0x218,0);pw(r+0x220,0);irq(n,44,0);return 0;
}
static void reset(uint8_t*m){
 memset(m+0x33e8,0,0x2e8c);memset(m+0x3230,0,0x1b8);memset(m+0x30a8,0,0x188);
 for(unsigned i=0;i<3;i++){unsigned off=i*0xf84;memset(m+0x349f+off,255,16);
  const unsigned ptr[]={0x356c,0x376c,0x386c,0x396c,0x3b6c,0x3d6c};
  pw(m+0x3548+off,0x20101020);pw(m+0x354c+off,0x10106020);pw(m+0x3550+off,0x10101010);
  for(unsigned j=0;j<6;j++)pw(m+0x3554+off+j*4,0x23000000u+ptr[j]+off);
 }
}
static uint8_t random_byte(uint8_t*m,uint32_t counter){
 uint64_t state=w(m+0x230)|(uint64_t)w(m+0x234)<<32;
 state=(state+counter)*UINT64_C(0x27bb2ee687b0b0fd)+UINT64_C(0xb504f32d);
 pw(m+0x230,(uint32_t)state);pw(m+0x234,(uint32_t)(state>>32));return (uint8_t)(state>>32);
}
int rr_receiver_initialize(rr_receiver_init_hw*x,uint32_t id,uint32_t cap,uint8_t phy){
 if(!x||!x->ram||!x->radio||!x->timer||!x->nvic||!x->dppi||!x->rtc||!x->clock0||!x->clock1||!x->clock2||!x->deviceid)return -1;
 uint8_t*m=x->ram,*t=x->timer,*r=x->radio,*n=x->nvic;
 for(unsigned i=0x3b8;i<=0x3da;i++)if(m[i]>=37)return -1;
 pw(x->clock0+0x40,1);pw(x->clock1+0x40,1);pw(x->clock2+0x40,1);reset(m);
 if(!w(x->dppi+0x500)){for(unsigned i=0;i<8;i++)m[0x71c6-i]=(uint8_t)i;for(unsigned i=0;i<6;i++)pw(t+0x1c0+4*i,0x80000000u+i);pw(r+0x30c,0x80000006);pw(x->dppi+0x504,255);}
 pw(m+0x3244,id);ph(m+0x3238,(uint16_t)cap);pw(m+0x324c,~id);rr_receiver_radio_initialize(x,id,phy);ph(m+0x3234,2);ph(m+0x323e,3);
 if(w(x->rtc+0x774)>0x3fffffff)return -4;uint32_t tick=w(x->rtc+0x770);uint8_t b;
 for(unsigned i=0;i<3;i++){b=random_byte(m,tick);m[0x31d1+2*i]=m[0x3b8+10*i+(b&15)%5];m[0x31d2+2*i]=m[0x3bd+10*i+(b>>4)%5];}
 b=random_byte(m,tick);m[0x31d7]=m[0x3da];unsigned choice=(b>>4)%3;
 m[0x31ac]=m[choice==0?0x31d3:0x31d1];m[0x31ad]=m[choice==2?0x31d3:0x31d5];m[0x31f6]=2;
 for(unsigned j=0;j<2;j++){unsigned ch=m[0x31ac+j];m[0x30d9+ch/8]|=(uint8_t)(1u<<(ch%8));}
 unsigned count=0;for(unsigned ch=0;ch<37;ch++){int enabled=(m[0x30d9+ch/8]>>(ch%8))&1;m[0x3132+ch]=enabled?(uint8_t)ch:255;if(enabled){m[0x30e8+count]=(uint8_t)count;m[0x310d+count]=(uint8_t)ch;count++;}}
 m[0x3157]=(uint8_t)count;ph(m+0x30e6,(uint16_t)(id^(id>>16)));
 for(unsigned i=0;i<2;i++){uint32_t chip=w(x->deviceid+4*i);for(unsigned j=0;j<4;j++)m[0x534b+4*i+j]=m[0x400+16*i+4*j+((chip>>(6-2*j))&3)];}
 pw(n+0x184,0x100);pw(t+4,1);pw(t+12,1);pw(t+0x510,0);pw(t+0x504,w(t+0x504)&~3u);pw(t+0x508,(w(t+0x508)&~3u)|2u);
 for(unsigned i=0;i<8;i++)pw(t+0x540+4*i,0);pw(t+0x308,0xff0000);irq(n,40,0x20);irq(n,92,0x60);irq(n,91,0x60);return 0;
}
int rr_receiver_config_event(rr_receiver_init_hw*x,uint32_t event,uint32_t value,uint8_t phy,const uint8_t*table){
 if(!x||!x->ram||!x->radio)return -1;uint8_t*m=x->ram;
 if(event==1){if(!table)return -1;int rc=rr_receiver_initialize(x,value,4,phy);if(rc)return rc;rr_business_install_key(m,0,value,table);}
 else if(event==8){if(!table)return -1;pw(x->radio+0xe30,value);pw(m+0x3244,value);pw(m+0x324c,~value);ph(m+0x30e6,(uint16_t)(value^(value>>16)));rr_business_install_key(m,0,value,table);}
 else if(event==9)pw(m+0x3240,value);
 else if(event==4||event==10||event==40||event==41||event==43||event==44)return -2;
 return 0;
}
