#include "receiver_config_producer.h"
#include "dongle_business_consumer.h"
#include <string.h>
static uint32_t w(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void pw(uint8_t*p,uint32_t x){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(x>>(i*8));}
static void ph(uint8_t*p,uint16_t x){p[0]=(uint8_t)x;p[1]=(uint8_t)(x>>8);}
static int publish(uint8_t*m,uint8_t*r,const uint8_t message[36],rr_receiver_rtos*c){
 if(!m||!r||!c||w(m+0x1bbc)!=36)return -1;int32_t result;
 int rc=rr_receiver_message_put_timed(m,r,0x23001bb4u,message,c,&result);if(rc||!result)return rc;
 rc=rr_receiver_message_purge_timed(m,r,0x23001bb4u,c);if(rc)return rc;return rr_receiver_message_put_timed(m,r,0x23001bb4u,message,c,&result);
}
int rr_receiver_config_value_publish(uint8_t*m,uint8_t*r,uint32_t event,uint32_t value,const uint8_t tail[28],rr_receiver_rtos*c){
 if(!tail||(event!=1&&event!=8&&event!=9))return -1;uint8_t message[36];pw(message,event);pw(message+4,value);memcpy(message+8,tail,28);return publish(m,r,message,c);
}
int rr_receiver_config_signal_publish(uint8_t*m,uint8_t*r,uint32_t event,const uint8_t tail[32],rr_receiver_rtos*c){
 if(!tail)return -1;uint8_t message[36];pw(message,event);memcpy(message+4,tail,32);return publish(m,r,message,c);
}
int rr_receiver_stats_reset(uint8_t*m,uint32_t value){
 if(!m)return -1;memset(m+0x65b8,0,40);value&=65535u;pw(m+0x65b4,value|(value<<16));return 0;
}
int rr_receiver_identity_publish(uint8_t*m,uint8_t*r,const uint8_t tail[28],rr_receiver_rtos*c){
 if(!m)return -1;uint32_t id=w(m+0x2dcf),rev=(id<<24)|((id&0xff00)<<8)|((id>>8)&0xff00)|(id>>24);int rc=rr_receiver_config_value_publish(m,r,1,rev,tail,c);if(rc)return rc;return rr_receiver_stats_reset(m,2);
}
int rr_receiver_config_mode_publish(rr_receiver_init_hw*x,const uint8_t*f,uint32_t event,const uint8_t tail[32],rr_receiver_rtos*c){
 if(!x||!x->ram||!x->rtc||!f||!c||(event!=41&&event!=40&&event!=44&&event!=43))return -1;uint8_t*m=x->ram;ph(m+0x2c82,event==41||event==44);int rc=rr_receiver_config_signal_publish(m,x->rtc,event,tail,c);if(rc)return rc;
 if(event==43){rc=rr_receiver_thread_suspend_control(m,x->rtc,0x23001ea0u,c);if(rc)return rc;m[0x71b9]=0;c->entry=0x23025954;c->arg0=0;return 1;}
 rc=rr_receiver_thread_resume_control(m,x->rtc,0x23001ea0u,c);if(rc)return rc;if(event==41)rr_dbc_status(m,f,0xff,0);else if(event==44)m[0x71b7]=1;return 0;
}
