#include "receiver_legacy_timer.h"
#include "business_tx.h"
#include "handshake.h"
#include <string.h>
#define R(o) h->radio[(o)/4]
#define T(o) h->timer[(o)/4]
static uint16_t u16(const uint8_t*p){return (uint16_t)(p[0]|p[1]<<8);}
static uint32_t u32(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void s16(uint8_t*p,uint16_t x){p[0]=(uint8_t)x;p[1]=(uint8_t)(x>>8);}
static void s32(uint8_t*p,uint32_t x){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(x>>(8*i));}
static void task(uint8_t*r,rr_receiver_radio_hw*h,unsigned b,unsigned reg,unsigned state){s32(r+b+0x80,state);R(0x200)=R(0x218)=R(0x220)=0;R(reg)=1;}
static uint16_t permute(uint16_t v,const uint8_t*f){const uint8_t*t=f+0x1bb74;return (uint16_t)(t[(v&255)>>4]|t[v&15]<<4|t[(v&4095)>>8]<<12|t[v>>12]<<8);}
static uint16_t next_frequency(uint8_t*r,const uint8_t*f,unsigned counter,unsigned channel){
 unsigned mode=u16(r+0x323e);if(mode<=1)return r[0x534b+4*channel+r[0x5349+channel]];
 if(mode!=2&&mode!=3)return 0x962;
 s16(r+0x30e4,(uint16_t)counter);uint16_t id=u16(r+0x30e6),v=(uint16_t)(counter^id);
 for(unsigned i=0;i<3;i++)v=(uint16_t)(17u*permute(v,f)+id);
 v^=id;uint8_t ch=r[0x3132+v%37];if(ch==255)ch=r[0x310d+r[0x30e8+((uint32_t)v*r[0x3157]>>16)]];
 r[0x30e3]=ch;s16(r+0x3228,ch);return f[0x1bb84+ch];
}
static void next_channel(uint8_t*r,unsigned ch){if(!r[0x5384]){uint8_t v=(uint8_t)(r[0x5349+ch]+1);r[0x5349+ch]=v==r[0x5353]?0:v;}}
/*23023708(1): deliberately operates peer0, even when IRQ selected another peer.*/
static void failure(uint8_t*r,int forced){
 if(!forced&&!r[0x348a])return;unsigned conn=u32(r+0x33e8),interval=u16(r+0x341c);int tick=0;
 if(conn==3){if(interval<9)tick=!((0xfffffee9u>>interval)&1);else if(interval==16)tick=!(u16(r+0x346e)&1);else if(interval==32)tick=!(u16(r+0x346e)&3);else if(interval==64)tick=!(u16(r+0x346e)&7);}
 else if(conn==4)tick=!(u16(r+0x5376)&0x1d);
 if(tick){unsigned ch=u16(r+0x32ca),a=0x3478+2*ch;uint16_t v=(uint16_t)(u16(r+a)+1);s16(r+a,v);if(v>3){next_channel(r,ch);s16(r+a,0);}}
 r[0x348a]=0;
}

static void tick(uint8_t*r,unsigned peer,int saturate){unsigned b=0x33e8+peer*0xf84;if(u32(r+b)>2){s16(r+b+0x86,(uint16_t)(u16(r+b+0x86)+1));s16(r+b+0x88,(uint16_t)(u16(r+b+0x88)+1));if(!saturate||u32(r+b+0x8c)<200)s32(r+b+0x8c,u32(r+b+0x8c)+1);}}
static void fallback(uint8_t*r,rr_receiver_radio_hw*h,unsigned peer){
 s16(r+0x3234,2);R(0x400)=0x80001;R(0x490)=0xffffffff;R(0x488)=0x100;R(0x500)=4;
 if(R(0x8a0)==0x80000000||R(0x8a0)==0x58120e)R(0x8a0)=0x58090e;R(0x8a4)=0xf8aa5f;R(0x8a8)=0xc00030;R(0x8ac)=0xa80030;R(0x7ac)=0x8672827a;R(0x7b0)=0x7e768672;R(0x7b4)=0x0406007e;R(0x7e4)=0x0412c384;
 R(0xe34)=0xc3c2c1e7;R(0xe20)=(uint32_t)r[0x3032]<<16|(uint32_t)r[0x3031]<<8|r[0x3030]|(uint32_t)r[0x3033]<<20|(uint32_t)r[0x3034]<<22|(uint32_t)r[0x3035]<<24|(uint32_t)r[0x3036]<<26|(uint32_t)r[0x3037]<<29;R(0xe28)=(uint32_t)r[0x303a]<<16|(uint32_t)r[0x3039]<<8|r[0x3038]|(uint32_t)r[0x303b]<<24|(uint32_t)r[0x303c]<<25;
 if(u32(r+0x3468)<11&&u32(r+0x43ec)<11){s16(r+0x5349,0);s32(r+0x5380,0);s32(r+0x5370,11);}r[0x353c+peer*0xf84]=0;r[0x3542+peer*0xf84]=0;
}
static int timeout(uint8_t*r,rr_receiver_radio_hw*h,unsigned mode,unsigned peer,uint8_t*rtc,rr_receiver_rtos*c,const uint8_t tails[2][24]){
 unsigned b=0x33e8+peer*0xf84;if(u32(r+b)<=2)return 0;if(u16(r+b+0x88)<100){s32(r+b,u32(r+b+0x8c)<200?3:4);return 0;}
 if(mode==1)R(0x104)=R(0x100)=R(0x110)=0;task(r,h,b,0x10,0);
 if(mode==2){s32(r+b,0);s32(r+b+0x80,11);}fallback(r,h,peer);r[b+4]=1;
 int rc=rr_receiver_semaphore_give_timed(r,rtc,0x23001c54,c);if(rc)return rc;uint8_t pair[8];s32(pair,peer);memcpy(pair+4,r+b+10,4);return rr_receiver_disconnect_notice_timed(r,rtc,pair,tails[peer],c);
}
static void select1(uint8_t*r,rr_receiver_radio_hw*h){unsigned slot=u16(r+0x32d0);if(u16(r+0x341c)==1){if(slot==0){s32(r+0x6274,0);R(0x104)=0;}else if(slot==4){s32(r+0x6274,2);R(0x100)=0;}}
 else if(slot==0||slot==2){s32(r+0x6274,0);R(0x104)=0;}else{s32(r+0x6274,2);R(0x100)=0;}}
static void subscribe1(uint8_t*r,rr_receiver_radio_hw*h){unsigned slot=u16(r+0x32d0);int fast=u16(r+0x341c)==1;if(fast&&slot!=0&&slot!=4)return;
 if(!fast||slot==0){R(0x708)=u16(r+0x3222);R(0xe30)=u32(r+0x3244);R(0xe3c)=3;R(0xe40)=6;}
 if(slot==0){R(0x104)=r[0x71c6]|0x80000000u;if(fast)R(0x400)|=0x20;}
 else if(!fast&&slot==2)R(0x104)=r[0x71c4]|0x80000000u;
 else{R(0x100)=r[0x71c4]|0x80000000u;if(fast)R(0x400)&=~0x20u;}}
static void action1(uint8_t*r,rr_receiver_radio_hw*h,unsigned a){unsigned state=u32(r+0x3468);int fast=u16(r+0x341c)==1;if(state!=11&&state!=12)return;
 if(state==11&&a==4){R(0xed0)=0x23003050;r[0x3050]=0;s32(r+0x3468,12);return;}
 if(a==1){if(state==11&&fast)s32(r+0x3468,12);select1(r,h);return;}
 if(fast&&a==2){task(r,h,0x33e8,0xc,11);return;}
 if(state==12&&a==5&&(unsigned)(r[0x3050]-1)>11){task(r,h,0x33e8,0xc,11);if(fast||u16(r+0x32d0)<2)r[0x348a]=1;else failure(r,0);}}
static unsigned sync_packet(uint8_t*r){r[0x53e4]=5;r[0x53e6]=r[0x5397];r[0x5397]++;if(r[0x5397]==8)r[0x5397]=1;r[0x53e7]=0x1f;r[0x53e8]=(uint8_t)((r[0x5349]&15)|(r[0x534a]<<4));return 0x53e4;}
static void ack1(uint8_t*r,rr_receiver_radio_hw*h){if(u32(r+0x5370)!=13)return;if(r[0x3484]){unsigned off=0;for(unsigned q=0;q<6;q++){uint32_t ptr=rr_bt_peek(r,0,0,q);if(ptr){off=ptr-0x23000000;s16(r+0x347e,(uint16_t)q);r[0x3488]=1;break;}}if(!off)off=sync_packet(r);r[off+1]=(uint8_t)(0x80|(r[0x3488]<<6)|r[0x5380+2*u16(r+0x32ca)]);memcpy(r+0x3070,r+off,16);R(0xed0)=0x23003070;}
 else{R(0x100)=0;task(r,h,0x52f0,0x10,13);if(u16(r+0x341c)==1)failure(r,1);}r[0x3484]=0;}
static void subscribe2(uint8_t*r,const uint8_t*f,rr_receiver_radio_hw*h,unsigned peer){unsigned b=0x33e8+peer*0xf84,state=u32(r+b),counter=u16(r+0x5376);if(state<2){R(0x708)=f[0x1bb84+((counter&128)?37:39)];R(0xe30)=u32(r+0x3240);R(0xe40)=128;R(0x104)=r[peer==0?0x71c6:0x71c4]|0x80000000u;R(0x110)=r[0x71c5]|0x80000000u;R(0xed0)=0x23000000+b+0xd4;s16(r+b+0xc8,0);return;}
 R(0xe30)=u32(r+0x3244);if(state>2){R(0x708)=u16(r+0x3222);R(0xe3c)=3;R(0xe40)=6;if(peer<2){R(0x104)=r[peer==0?0x71c6:0x71c4]|0x80000000u;R(0x110)=r[0x71c5]|0x80000000u;}else if(u32(r+0x5370)==13)R(0x100)=r[0x71c4]|0x80000000u;return;}
 R(0x708)=f[0x1bb84+f[0x1bbac+u16(r+b+0xca)]];R(0xed0)=0x23000000+b+0xd4;
 int marked=u32(r+b+0x14)!=0||u32(r+b+0x28)!=0;if(!(counter&1)){if(peer<2)R(0x100)=r[peer==0?0x71c6:0x71c4]|0x80000000u;R(0xe3c)=marked?0:peer+1;}
 else{if(peer<2){R(0x104)=r[peer==0?0x71c6:0x71c4]|0x80000000u;R(0x110)=r[0x71c5]|0x80000000u;}R(0xe40)=peer==0?10:peer==1?12:6;if(marked)R(0xe40)|=1;}}
static void action2(uint8_t*r,rr_receiver_radio_hw*h,unsigned peer){unsigned b=0x33e8+peer*0xf84,state=u32(r+b+0x80),counter=u16(r+0x5376);
 if(state==11){R(0xed0)=0x23003050;r[0x3050]=0;s32(r+b+0x80,12);return;}
 if(state==8){task(r,h,b,0x10,7);s16(r+b+0xc8,0);return;}if(state!=7)return;R(0xed0)=0x23000000+b+0xd4;
 uint16_t t=u16(r+b+0xce);if(t){s16(r+b+0xce,t-1);if(t==1)s16(r+b+0xc8,0);}
 if(!u16(r+b+0xc8)){if(!(counter&1)){s16(r+b+0xcc,(uint16_t)(u16(r+b+0xcc)+1));if(!(counter&3)&&u32(r+b+0x28)){r[b+0xd4]=7;r[b+0xd5]=(uint8_t)((peer&1)<<6);r[b+0xd6]=r[b+0xa7];r[b+0xd7]=0x24;r[b+0xa7]++;if(r[b+0xa7]==8)r[b+0xa7]=1;}
 else r[b+0xa7]=rr_dongle_offer(r+b+0xd4,r[b+0xa7],(uint8_t)peer,u32(r+0x3244),(uint8_t)u16(r+0x3238),r[b+0x85],(uint8_t)u16(r+b+0x1a),(uint16_t)counter);}
 else if(u16(r+b+0xcc)<20)memset(r+b+0xd4,0,32);else{unsigned i=(uint16_t)(u16(r+b+0xca)+1);s16(r+b+0xca,(uint16_t)(i>3?0:i));s16(r+b+0xcc,0);task(r,h,b,0x10,7);R(0x110)=0;}}
 if(counter&1){s32(r+b+0x80,9);r[b+0xd4]=0;}else s32(r+b+0x80,8);
}
static void ack2(uint8_t*r,rr_receiver_radio_hw*h){if(u32(r+0x5370)!=13)return;unsigned reply0=r[0x3484],reply1=r[0x4408],off=0,which=0,flag=0;if(!reply0&&!reply1){R(0x100)=0;task(r,h,0x52f0,0x10,13);goto done;}
 s16(r+0x347e,255);s16(r+0x4402,255);
 for(unsigned peer=0;peer<2&&!off;peer++)if((peer?reply1:reply0)==1)for(unsigned q=0;q<6;q++){uint32_t ptr=rr_bt_peek(r,0,peer,q);if(ptr){off=ptr-0x23000000;s16(r+0x347e +peer*0xf84,(uint16_t)q);which=peer;flag=peer==0;break;}}
 if(!off)off=sync_packet(r);r[off+1]=(uint8_t)(r[0x5380+2*u16(r+0x32ca)]|(flag<<4)|(which<<5)|(reply0<<6)|(reply1<<7));memcpy(r+0x3070,r+off,16);R(0xed0)=0x23003070;
 done:r[0x3484]=r[0x4408]=0;
}
int rr_receiver_legacy_timer(uint8_t*r,const uint8_t*f,rr_receiver_radio_hw*h,unsigned mode,uint8_t*rtc,rr_receiver_rtos*c,const uint8_t tails[2][24]){
 if(!r||!f||!h||!rtc||!c||!tails||(mode!=1&&mode!=2)||u16(r+0x32ca)>1)return -1;c->entry=c->arg0=0;
 unsigned event;for(event=0;event<8;event++)if(T(0x140+4*event)==1)break;if(event==8)return 0;T(0x140+4*event)=0;unsigned slot=u16(r+0x32d0);
 if(mode==1){int fast=u16(r+0x341c)==1;if(event==0){T(0x540)=16000;R(0x104)=0;T(0x544)=fast?2880:3680;T(0x548)=fast?3840:4640;T(0x54c)=fast?11200:2560;s16(r+0x32d0,0);action1(r,h,1);}
 else if(event==1){if(slot>(fast?4u:3u))return 0;if(slot==(fast?4u:3u)){s16(r+0x32d0,0);if(u16(r+0x341e)&&u16(r+0x3420)==u16(r+0x5376)){s16(r+0x341c,u16(r+0x341e));s16(r+0x341e,0);}subscribe1(r,h);action1(r,h,4);}
 else if(fast&&slot<3){s16(r+0x32d0,(uint16_t)(slot+1));subscribe1(r,h);}
 else{if(fast)action1(r,h,2);s16(r+0x32d0,(uint16_t)(slot+1));subscribe1(r,h);if(!fast&&slot==1)action1(r,h,4);else ack1(r,h);}}
 else if(event==2){int end=slot==(fast?4u:3u);if(end){T(0x544)=15040;T(0x548)=0;if(!fast)T(0x54c)=0;if(u32(r+0x5370)==13)select1(r,h);tick(r,0,1);tick(r,2,1);unsigned counter=u16(r+0x5376),ch=(counter>>1)&1;s16(r+0x32ca,(uint16_t)ch);s16(r+0x3222,next_frequency(r,f,counter,ch));return timeout(r,h,1,0,rtc,c,tails);}
 if(fast&&slot<4){static const unsigned a[]={2880,5600,8320,11840},b[]={3840,6560,9280,12640};T(0x544)=a[slot];T(0x548)=b[slot];action1(r,h,1);}
 else if(!fast){if(slot==0||slot==2){T(0x544)=slot==0?3680:11680;T(0x548)=slot==0?4640:12640;T(0x54c)=slot==0?0:10560;action1(r,h,1);}else if(slot==1){T(0x544)=7040;T(0x548)=8000;T(0x54c)=0;if(u32(r+0x5370)==13)select1(r,h);}}}
 else if(event==3){if(fast){T(0x54c)=0;action1(r,h,5);}else if((slot&0xfffd)==0)action1(r,h,5);}return 0;}
 if(event==0){T(0x540)=16000;R(0x100)=R(0x104)=0;T(0x544)=4160;T(0x548)=4640;action2(r,h,0);s16(r+0x32d0,0);}
 else if(event==1){R(0x110)=0;if(slot==0){subscribe2(r,f,h,1);if(u32(r+0x3468)==9){s32(r+0x3468,7);s16(r+0x34b0,0);}s16(r+0x32d0,1);}else if(slot==1){subscribe2(r,f,h,2);if(u32(r+0x43ec)==9){s32(r+0x43ec,7);s16(r+0x4434,0);}s16(r+0x32d0,2);ack2(r,h);}else if(slot==2){subscribe2(r,f,h,0);s16(r+0x32d0,0);}}
 else if(event==2){if(slot==1){R(0x100)=R(0x104)=0;T(0x544)=8800;T(0x548)=9600;action2(r,h,1);}else if(slot==2){R(0x100)=0;T(0x544)=14720;T(0x548)=0;if(u32(r+0x5370)==11)task(r,h,0x52f0,0x10,11);for(unsigned peer=0;peer<3;peer++)tick(r,peer,0);unsigned counter=u16(r+0x5376);s16(r+0x3222,next_frequency(r,f,counter,u16(r+0x32ca)));s16(r+0x32ca,(uint16_t)((counter>>1)&1));int rc=timeout(r,h,2,0,rtc,c,tails);if(rc)return rc;return timeout(r,h,2,1,rtc,c,tails);}}return 0;
}
