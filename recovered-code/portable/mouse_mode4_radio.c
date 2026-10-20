#include "mouse_mode4_radio.h"
#include "mouse_mode4_tx.h"
#include "business_tx.h"
#include "mouse_adaptive_control.h"
#include <string.h>
static unsigned h(const uint8_t*p){return p[0]|(unsigned)p[1]<<8;}
static uint32_t w(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void ph(uint8_t*p,unsigned x){p[0]=(uint8_t)x;p[1]=(uint8_t)(x>>8);}
static void pw(uint8_t*p,uint32_t x){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(x>>(8*i));}
static void inc(uint8_t*m,unsigned a){ph(m+a,h(m+a)+1);}
static void tx_off(uint8_t*r){pw(r+0x100,0);pw(r+0x108,0);}
static void disable(uint8_t*m,uint8_t*r,uint32_t state){pw(m+0x2a04,state);pw(r+0x200,0);pw(r+0x218,0);pw(r+0x220,0);pw(r+0x10,1);}
int rr_mouse_mode4_radio_with_ack(uint8_t*m,uint8_t*r,uint8_t*t,uint32_t*n,rr_mouse_mode4_ack_fn ack,void*context){
 if(!m||!r||!t||!n)return -1;
 uint32_t state=w(m+0x2a04);if(w(r+0x218)==1&&state==0x19)state=0x18;
 int rx=w(r+0x220)==1&&state==0x1a,ok=w(r+0x22c)==1;unsigned bank=h(m+0x2836),ch=h(m+0x278e),qid=h(m+0x2a1a);
 if(rx&&(bank>2||ch>36))return -3;
 if(rx&&ok&&qid==3&&w(m+0x6b68)&&!ack)return -2;
 for(unsigned off=0x204;off<=0x20c;off+=4)if(w(r+off)==1)pw(r+off,0);
 if(w(r+0x218)==1){pw(r+0x218,0);if(w(m+0x2a04)==0x19)pw(m+0x2a04,0x18);}
 if(w(r+0x220)!=1)return 0;
 pw(r+0x220,0);
 if(state==0x19)pw(r+0x400,w(r+0x400)&~0x80000u);
 else if(state==0x1a){
  pw(r+0x104,0);pw(r+0x110,0);pw(r+0x400,w(r+0x400)&~0x80000u);
  if(ok){
   pw(r+0x22c,0);
   uint32_t cc=w(t+0x55c);
   if(!(w(m+0x29c4)|w(m+0x29cc))){if(h(m+0x283c)==2)pw(m+0x29c4,cc);else if(h(m+0x283c)==5)pw(m+0x29c4,cc-250);}
   if(m[0x2633]==0x1f){unsigned value=(unsigned)m[0x2634]<<8|m[0x2635];if(cc-166u<=83)ph(m+0x2a0a,value);else if(cc-416u<=83)ph(m+0x2a0a,value+1);}
   memcpy(m+0x2a96,m+0x2630,16);m[0x2630]=0;
   m[0x2a1e]=(uint8_t)(m[0x2a1e]+1);if(m[0x2a1e]==8)m[0x2a1e]=1;
   ph(m+0x2a14+bank*2,0);ph(m+0x2a0c,0);memset(m+0x2670,0,24);m[0x2a26]=0;m[0x27c7]=0;m[0x2a22]=1;
   if(qid<6){rr_bt_pop(m,1,0,qid);if(qid>1&&ack){int result=ack(context,(uint16_t)qid);if(result)return result;}}
   *n=0x10000000u;ph(m+0x28e8+ch*2,0);
   unsigned reason=255;if(m[0x29e0]||m[0x29e4]){reason=w(r+0x718)&255;m[0x29e5]=(uint8_t)reason;}
   rr_mouse_adaptive_request(m,1,ch,reason,n);
  }else{m[0x2a26]=0;inc(m,0x289e + ch*2);inc(m,0x28e8+ch*2);inc(m,0x293a);m[0x29d0]=2;rr_mouse_adaptive_request(m,0,ch,255,n);}
  inc(m,0x2854+ch*2);inc(m,0x2932);inc(m,0x2938);pw(r+0x400,w(r+0x400)&~16u);pw(m+0x2a04,0x18);
 }
 pw(r+0x22c,0);pw(r+0x230,0);return 0;
}
int rr_mouse_mode4_radio(uint8_t*m,uint8_t*r,uint8_t*t,uint32_t*n){return rr_mouse_mode4_radio_with_ack(m,r,t,n,0,0);}
static int action_check(const uint8_t*m,const uint8_t*r,uint32_t action){
 uint32_t state=w(m+0x2a04);if(state==0x18&&action==3)return -4;
 if(state==0x1a&&action==8){uint32_t p=w(r+0xed0);if(p<0x23000000u||p>=0x23010000u)return -8;}
 return 0;
}
int rr_mouse_mode4_action(uint8_t*m,uint8_t*r,uint32_t action){
 if(!m||!r)return -1;int check=action_check(m,r,action);if(check)return check;
 uint32_t state=w(m+0x2a04);
 if(state==0x19){if(action==1)tx_off(r);}
 else if(state==0x1a){if(action==8&&((unsigned)m[w(r+0xed0)-0x23000000u]-1u)>9u)disable(m,r,state);}
 else if(state==0x18&&action==6){
  if(m[0x2a20]!=1)disable(m,r,state);
  else{pw(r+0x110,0x80000000u|m[0x76f4]);pw(r+0x400,w(r+0x400)|0x80000u);m[0x2a20]=0;pw(m+0x2a04,0x1a);pw(r+0xed0,0x23002630);if(m[0x29e0]||m[0x29e4])pw(r+0x400,w(r+0x400)|16u);}
 }
 return 0;
}
static void clear_stats(uint8_t*m){pw(m+0x2932,0);memset(m+0x2854,0,0xde);}
static void rebuild(uint8_t*m,const uint8_t*r){
 unsigned n=0;for(unsigned i=0;i<37;i++){uint8_t v=255;if(m[0x26b9+i/8]&(1u<<(i%8))){m[0x26c8+n]=(uint8_t)n;m[0x26ed+n]=(uint8_t)i;n++;v=(uint8_t)i;}m[0x2712+i]=v;}
 m[0x2737]=(uint8_t)n;uint32_t base=w(r+0xe30);ph(m+0x26c6,base^(base>>16));
}
static unsigned permute(const uint8_t*f,unsigned x){const uint8_t*p=f+0x2ca04;return (p[(x>>4)&15]|p[x&15]<<4|p[(x>>8)&15]<<12|p[x>>12]<<8)&65535u;}
static unsigned hop(uint8_t*m,const uint8_t*f,unsigned counter){
 unsigned seed=h(m+0x26c6);ph(m+0x26c4,counter);unsigned v=permute(f,counter^seed);v=permute(f,(seed+(v*17u&65535u))&65535u);v=permute(f,(seed+(v*17u&65535u))&65535u);v=seed^((seed+(v*17u&65535u))&65535u);
 unsigned ch=m[0x2712+v%37];if(ch==255)ch=m[0x26ed+m[0x26c8+((v*m[0x2737])>>16)]];m[0x26c3]=(uint8_t)ch;ph(m+0x2792,ch);return f[0x2ca14+ch];
}
static void maintenance(uint8_t*m,uint8_t*r,int extended){
 unsigned counter=h(m+0x2a0a);
 if(m[0x27c5]&&h(m+0x2972)==counter){m[0x27c5]=0;memcpy(m+0x26b9,m+0x26be,4);m[0x26bd]=m[0x26c2];if(extended&&(h(m+0x27a2)==2||h(m+0x27a2)==3))rebuild(m,r);clear_stats(m);}
 if(!(counter&511u))clear_stats(m);
 if(!(counter&2047u)){unsigned level=h(m+0x293c);if((h(m+0x2938)>>3)<h(m+0x293a)){if(level<60)level++;}else if(level)level--;ph(m+0x293c,level);m[0x27c8]=level>14;pw(m+0x2938,0);}
}
static uint32_t asr2(uint32_t x){return (x>>2)|(x&0x80000000u?0xc0000000u:0);}
static void clock_sample(uint8_t*m){
 uint32_t sample=w(m+0x29c4);if(!sample)return;
 uint32_t sum=w(m+0x29b8)+sample,count=w(m+0x29bc)+1,base=w(m+0x29b4);
 pw(m+0x29b8,sum);pw(m+0x29bc,count);
 if(!base){if(count==4){pw(m+0x29b4,asr2(sum));pw(m+0x29b8,0);pw(m+0x29bc,0);}}
 else{
  uint32_t limit=h(m+0x2794)==3?4:1;
  if(count==limit){pw(m+0x29b8,0);pw(m+0x29bc,0);pw(m+0x29c8,limit==4?asr2(sum):sum);}
  else if((int32_t)count>(int32_t)limit){pw(m+0x29b8,0);pw(m+0x29bc,0);}
  uint32_t avg=w(m+0x29c8);if(avg){if(base<avg&&(int32_t)(avg-base)>1){pw(m+0x29c0,1);pw(m+0x29cc,4);}else if(base>avg&&(int32_t)(base-avg)>1){pw(m+0x29c0,2);pw(m+0x29cc,4);}pw(m+0x29c8,0);}
 }
 pw(m+0x29c4,0);
}
static void cc(uint8_t*t,unsigned i,uint32_t v){pw(t+0x540+i*4,v);}
static int timer_impl(uint8_t*m,uint8_t*r,uint8_t*t,uint8_t*s,uint32_t*n,int full,const uint8_t*image,uint32_t*clock,rr_mouse_mode4_timeout_fn timeout,void*context){
 if(!m||!r||!t||!s||!n)return -1;
 unsigned event=8;for(unsigned i=0;i<8;i++)if(w(t+0x140+i*4)==1){event=i;break;}
 unsigned rate=h(m+0x29ac),slot=h(m+0x283c),selector=h(m+0x27a2);uint32_t state=w(m+0x2a04),action=0;
 if(full<2&&event==0&&m[0x27c5]&&h(m+0x2972)==h(m+0x2a0a)&&(selector==2||selector==3))return -7;
 if(event==1){switch(w(t+0x544)){case 75:case 325:case 470:action=3;break;case 220:if(rate<=4)action=3;break;case 140:case 390:action=6;break;default:break;}}
 if(event==3&&(slot==2||slot==5))action=8;
 if(action){int check=action_check(m,r,action);if(check&&!(full&&check==-4))return check;}
 if(full<2&&event==2&&slot==5&&h(m+0x2794)>2){if((uint16_t)(h(m+0x2a0c)+1)>=100)return -5;if(h(m+0x29ae))return -6;if(selector==2||selector==3)return -7;}
 if(event==8)return 0;pw(t+0x140+event*4,0);
 if(event==0){
  cc(t,0,500);
  if(rate==1||(rate==2&&m[0x27c7])){cc(t,1,75);cc(t,2,100);cc(t,3,0);cc(t,4,160);}
  else if(rate<=4||state==0x19){cc(t,1,140);cc(t,2,165);cc(t,3,0);cc(t,4,140);}
  else{cc(t,1,390);cc(t,2,415);cc(t,3,0);cc(t,4,0);}
  ph(m+0x283c,0);if(state==0x19)tx_off(r);clock_sample(m);maintenance(m,r,full>=2);if(m[0x774b]){pw(s+12,1);pw(s,1);}return 0;
 }
 if(event==1){switch(w(t+0x544)){case 75:ph(m+0x283c,1);break;case 140:ph(m+0x283c,2);break;case 220:ph(m+0x283c,3);if(rate>4){cc(t,1,390);cc(t,2,415);cc(t,4,0);}break;case 325:ph(m+0x283c,4);break;case 390:ph(m+0x283c,5);break;case 470:ph(m+0x283c,0);break;default:return 0;}}
 if(action)return full?rr_mouse_mode4_action_full(m,r,t,action):rr_mouse_mode4_action(m,r,action);
 if(event!=2)return 0;
 switch(slot){
 case 1:cc(t,1,140);cc(t,2,165);cc(t,3,0);break;
 case 2:cc(t,1,220);cc(t,2,rate<5?250:0);cc(t,4,0);break;
 case 3:if(rate==1||(rate==2&&m[0x27c7])){cc(t,1,325);cc(t,2,350);cc(t,3,0);cc(t,4,410);}else{cc(t,1,390);cc(t,2,415);cc(t,3,0);cc(t,4,390);}break;
 case 4:cc(t,1,390);cc(t,2,415);cc(t,3,0);break;
 case 5:cc(t,1,470);cc(t,2,0);cc(t,4,0);break;
 default:return 0;
 }
 if(state==0x19)tx_off(r);
 if(slot==5){
  if(h(m+0x2794)>2){
   inc(m,0x2a0a);inc(m,0x2a0c);if(w(m+0x2a10)<200)pw(m+0x2a10,w(m+0x2a10)+1);
   unsigned bank=(h(m+0x2a0a)>>1)&2u;ph(m+0x2836,bank);if(m[0x29d0])m[0x29d0]--;if(w(m+0x29cc))pw(m+0x29cc,w(m+0x29cc)-1);m[0x29d1+bank]++;
   unsigned frequency=selector<=1?m[0x29d7+bank*4+m[0x29d5+bank]]:selector<=3&&full>=2?hop(m,image,h(m+0x2a0a)):2402;ph(m+0x2790,frequency);
   unsigned counter=h(m+0x2a0a);
   if(m[0x29f9]&&!(counter&2047u)){if(!(counter&0x1800u)){if(!m[0x29e4]){ph(m+0x29e2,0);pw(m+0x29e8,0);m[0x29e4]=1;}}else if(m[0x29e4]==1){rr_mouse_adaptive_request(m,2,0,0,n);m[0x29e4]=0;}}
  }
  if(full>=2&&h(m+0x2794)>2&&h(m+0x29ae)){
   unsigned rate_new=h(m+0x29ae);ph(m+0x29ac,rate_new);ph(m+0x29ae,0);
   if(rate_new==1){if(!m[0x76ee]){clock[0]=1;m[0x76ee]=1;}}else if(m[0x76ee]){clock[1]=1;m[0x76ee]=0;}
   unsigned mode=h(m+0x2798);m[0x29f9]=(uint8_t)(mode==4||mode==8?(rate_new==4||rate_new>7):(rate_new==1||rate_new==2||rate_new==4||rate_new>7));
   ph(m+0x29e2,0);pw(m+0x29e8,0);m[0x29e4]=0;
  }
  uint32_t corr=w(m+0x29c0);if(corr==1)cc(t,0,503);else if(corr==2)cc(t,0,497);pw(m+0x29c0,0);
  if(h(m+0x2794)>2){if(full>=2&&h(m+0x2a0c)>=100)return timeout(context);ph(m+0x2794,w(m+0x2a10)<200?3:4);}
 }
 return 0;
}

int rr_mouse_mode4_action_full(uint8_t*m,uint8_t*r,uint8_t*t,uint32_t action){
 if(!m||!r||!t)return -1;
 if(action==3&&w(m+0x2a04)==0x18)return rr_mouse_mode4_tx(m,r,t);
 return rr_mouse_mode4_action(m,r,action);
}
int rr_mouse_mode4_timer(uint8_t*m,uint8_t*r,uint8_t*t,uint8_t*s,uint32_t*n){return timer_impl(m,r,t,s,n,0,0,0,0,0);}
int rr_mouse_mode4_timer_full(uint8_t*m,uint8_t*r,uint8_t*t,uint8_t*s,uint32_t*n){return timer_impl(m,r,t,s,n,1,0,0,0,0);}

int rr_mouse_mode4_timer_with_runtime(uint8_t*m,uint8_t*r,uint8_t*t,uint8_t*s,uint32_t*n,const uint8_t*f,uint32_t*c,rr_mouse_mode4_timeout_fn fn,void*ctx){if(!f||!c||!fn)return -1;return timer_impl(m,r,t,s,n,2,f,c,fn,ctx);}
