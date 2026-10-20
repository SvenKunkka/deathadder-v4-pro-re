#include "receiver_application_timers.h"
#include "receiver_notification_runtime.h"
#include "receiver_config_producer.h"
#include "dongle_business_consumer.h"
#include "business_tx.h"
#include <string.h>
static uint16_t h(const uint8_t*p){return (uint16_t)(p[0]|(unsigned)p[1]<<8);}
static uint32_t w(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void pw(uint8_t*p,uint32_t x){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(x>>(8*i));}
static void ph(uint8_t*p,uint16_t x){p[0]=(uint8_t)x;p[1]=(uint8_t)(x>>8);}
static uint32_t div32(uint32_t a,uint32_t b){return b?a/b:0;}
static int radio_stop(rr_receiver_init_hw*x,rr_receiver_rtos*c){
 uint8_t*m=x->ram,*r=x->radio;int rc=rr_receiver_thread_suspend_control(m,x->rtc,0x23001fc0u,c);if(rc)return rc;ph(m+0x3232,0);
 for(unsigned i=0;i<2;i++){pw(r+0x100,0);pw(r+0x104,0);pw(r+0x110,0);ph(m+0x3252,0);pw(m+0x3468+i*0xf84,0);pw(r+0x200,0);pw(r+0x218,0);pw(r+0x220,0);pw(r+0x10,1);}
 uint32_t mask=0;for(unsigned i=0;i<8;i++)if(m[0x71c6-i]<32)mask|=1u<<m[0x71c6-i];pw(x->dppi+0x508,mask);pw(x->nvic+0x184,0x100);pw(m+0x52f0,0);pw(x->timer+4,1);pw(r+0x100,0);pw(r+0x104,0);pw(r+0x110,0);pw(r+0x10c,0);ph(m+0x3230,0);pw(r+0x10,1);return 0;
}
static int radio_start(rr_receiver_init_hw*x,rr_receiver_rtos*c){
 uint8_t*m=x->ram;ph(m+0x3232,1);int rc=rr_receiver_radio_initialize(x,w(m+0x3244),4);if(rc)return rc;m[0x3259]=1;m[0x3250]=h(m+0x323a)==1;m[0x3258]=!m[0x3250];m[0x3253]=1;m[0x33ec]=0;m[0x4370]=0;
 rc=rr_receiver_thread_resume_control(m,x->rtc,0x23001fc0u,c);if(rc)return rc;return rr_receiver_semaphore_give_timed(m,x->rtc,0x23001c54u,c);
}

int rr_receiver_application_timer(rr_receiver_init_hw*x,const uint8_t*f,uint32_t callback,const uint8_t tail[32],rr_receiver_rtos*c){
 if(!x||!x->ram||!x->radio||!x->timer||!x->rtc||!x->nvic||!x->dppi||!f||!tail||!c)return -1;
 uint8_t*m=x->ram;c->entry=0;c->arg0=0;int rc;
 if(callback==0x230255d0u){rc=rr_receiver_timer_start_control(m,x->rtc,0x23001aa0u,100000,0,c);if(rc)return rc;return radio_start(x,c);}
 if(callback==0x230255f8u){rc=rr_receiver_timer_start_control(m,x->rtc,0x23001a68u,400000,0,c);if(rc)return rc;rc=radio_stop(x,c);if(rc)return rc;if(h(m+0x6590)){ph(m+0x6590,0);ph(m+0x65e2,0);return rr_receiver_connection_notice(m,f,1,0);}return 0;}
 if(callback==0x23025640u){
  uint16_t n=h(m+0x659c);if(n){n--;ph(m+0x659c,n);if(!n){uint16_t period=h(m+0x659a);ph(m+0x659c,period);ph(m+0x659e,(uint16_t)(period>>1));m[0x65b0]=(uint8_t)div32(w(m+0x65a0),w(m+0x65a8));pw(m+0x65a0,0);pw(m+0x65a8,0);m[0x65b1]=(uint8_t)div32(w(m+0x65a4),w(m+0x65ac));pw(m+0x65a4,0);pw(m+0x65ac,0);uint8_t data[4]={0xac,(uint8_t)(period>>8),(uint8_t)period,0};(void)rr_bt_dongle_tx(m,0,3,data,3,0,0);}}
  n=h(m+0x659e);if(n){n--;ph(m+0x659e,n);if(!n){uint8_t report[7]={5,0xfe,0x72,m[0x65b0],m[0x65b2],m[0x65b1],m[0x65b3]};(void)rr_dbc_usb_enqueue(m,4,report,7);}}return 0;
 }
 if(callback!=0x230256e8u)return -2;
 uint16_t n=h(m+0x65b6);if(n){n--;ph(m+0x65b6,n);if(!n){ph(m+0x65b6,h(m+0x65b4));for(unsigned i=0;i<2;i++){uint32_t numerator=w(m+0x65b8+4*i),denominator=w(m+0x65c0+4*i);uint8_t value=(uint8_t)div32(numerator,denominator);m[0x65d8+i]=value;if(!m[0x65e0])m[0x65dc+i]=!value?0:value<=m[0x2daa]?4:value<=m[0x2dab]?3:value<=m[0x2dac]?2:1;pw(m+0x65b8+4*i,0);pw(m+0x65c0+4*i,0);}memset(m+0x65c8,0,16);if(h(m+0x65dc)!=h(m+0x65de)){if(h(m+0x6590)){rc=rr_receiver_mode_notice(m,f,m[0x65dc]);if(rc)return rc;}ph(m+0x65de,h(m+0x65dc));}}}
 n=h(m+0x65e2);if(n){n--;ph(m+0x65e2,n);if(!n){ph(m+0x6590,0);ph(m+0x65e4,5);rc=rr_receiver_timer_stop_control(m,x->rtc,0x23001a30u,c);if(rc)return rc;rc=rr_receiver_connection_notice(m,f,1,0);if(rc)return rc;}}
 if(!m[0x6595]){n=h(m+0x65e4);if(n){n--;ph(m+0x65e4,n);if(!n){rc=rr_receiver_config_signal_publish(m,x->rtc,4,tail,c);if(rc)return rc;}}}
 if(h(m+0x6590)){n=h(m+0x65e6);if(n){n--;ph(m+0x65e6,n);}if(!n){c->entry=0x0e05d698u;c->arg0=0;return 1;}}
 return 0;
}

typedef struct {rr_receiver_init_hw*x;const uint8_t*f,*tail;} app_context;
static int app_user(uint32_t address,uint32_t cb,rr_receiver_rtos*c,void*user){
 app_context*a=user;uint32_t entry=cb&~1u;
 if(entry==0x230255d0u||entry==0x230255f8u||entry==0x23025640u||entry==0x230256e8u)return rr_receiver_application_timer(a->x,a->f,entry,a->tail,c);
 c->entry=entry;c->arg0=address;return 1;
}
static int app_timeout(rr_receiver_rtc_hw*x,uint32_t address,uint32_t cb,rr_receiver_rtos*c,void*user){
 app_context*a=user;if(cb==0x0e06eb01u)return rr_receiver_timer_expiry_with_handler(x->ram,x->rtc,a->f,address,c,app_user,user);
 c->entry=cb&~1u;c->arg0=address;return 1;
}
int rr_receiver_rtc_application_timers(rr_receiver_init_hw*x,const uint8_t*f,const uint8_t tail[32],rr_receiver_rtos*c,rr_receiver_rtc_pending*p){
 if(!x||!f||!tail)return -1;app_context a={x,f,tail};rr_receiver_rtc_hw h={x->ram,x->rtc};return rr_receiver_rtc_dispatch_with_handler(&h,c,p,app_timeout,&a);
}
