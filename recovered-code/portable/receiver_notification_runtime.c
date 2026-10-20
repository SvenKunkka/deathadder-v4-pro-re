#include "receiver_notification_runtime.h"
#include "dongle_business_consumer.h"
#include "business_tx.h"
#include <string.h>
static uint16_t h(const uint8_t*p){return (uint16_t)((unsigned)p[0]|(unsigned)p[1]<<8);}
static uint32_t w(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void ph(uint8_t*p,uint16_t x){p[0]=(uint8_t)x;p[1]=(uint8_t)(x>>8);}
static void pw(uint8_t*p,uint32_t x){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(x>>(i*8));}
static uint32_t mask(uint32_t x){x&=255u;return x<32?1u<<x:0;}
int rr_receiver_connection_notice(uint8_t*m,const uint8_t*f,uint32_t peer,uint32_t connected){
 if(!m||!f)return -1;uint8_t report[16]={0};ph(report,peer==1?0x0905:0x3509);report[2]=connected==1?3:2;report[3]=(uint8_t)peer;
 uint16_t flags=h(m+0x2c80);ph(m+0x2c80,(uint16_t)(connected==1?flags|mask(peer):flags&~mask(peer)));
 (void)rr_dbc_usb_enqueue(m,4,report,16);
 if(connected==1){uint8_t data[7]={0xb1,m[0x71bd],m[0x71bc],1,m[0x71e5],(uint8_t)h(m+0x2c82),0};(void)rr_bt_dongle_tx(m,(uint8_t)peer!=1,3,data,6,0,0);}
 else{rr_dbc_status(m,f,0xff,0);memset(m+0x353c,0,12);}return 0;
}
int rr_receiver_mode_notice(uint8_t*m,const uint8_t*f,uint8_t mode){
 if(!m||!f)return -1;if(h(m+0x2c80)&&h(m+0x2c82)==1){m[0x71b3]=mode;rr_dbc_status(m,f,0xe0,mode);uint8_t report[16]={5,0x56,mode};(void)rr_dbc_usb_enqueue(m,4,report,16);}return 0;
}
int rr_receiver_notification_dispatch(rr_receiver_init_hw*x,const uint8_t*f,const uint8_t message[36],rr_receiver_rtos*c){
 if(!x||!x->ram||!x->rtc||!f||!message||!c)return -1;c->entry=0;c->arg0=0;uint8_t*m=x->ram;uint32_t event=w(message);unsigned peer=h(message+4);int rc;
 if(event==1){ph(m+0x6590,(uint16_t)(h(m+0x6590)|mask(peer)));ph(m+0x65e6,5);if(peer==0){rc=rr_receiver_connection_notice(m,f,1,1);if(rc)return rc;rc=rr_receiver_mode_notice(m,f,4);if(rc)return rc;rc=rr_receiver_timer_stop_control(m,x->rtc,0x23001a30u,c);if(rc)return rc;pw(m+0x65e2,0);}}
 else if(event==2&&peer==0&&h(m+0x65e2)==0){rc=rr_receiver_timer_start_control(m,x->rtc,0x23001a30u,2000000,0,c);if(rc)return rc;ph(m+0x65de,0);ph(m+0x65e2,4);}return 0;
}
int rr_receiver_notification_iteration(rr_receiver_init_hw*x,const uint8_t*f,uint32_t message_address,uint8_t message[36],rr_receiver_rtos*c){
 if(!x)return -1;int32_t result;int rc=rr_receiver_message_get(x->ram,x->rtc,0x23001b8cu,message_address,message,UINT64_MAX,c,&result);if(rc)return rc;if(result)return -2;return rr_receiver_notification_dispatch(x,f,message,c);
}

int rr_receiver_connection_publish(uint8_t*m,uint8_t*r,const uint8_t pair[8],const uint8_t tail[24],rr_receiver_rtos*c){
 if(!m||!r||!pair||!tail||!c||w(m+0x1b94)!=36||w(m+0x1b98)!=5)return -1;
 uint8_t message[36];pw(message,1);memcpy(message+4,pair,8);memcpy(message+12,tail,24);int32_t result;int rc=rr_receiver_message_put_timed(m,r,0x23001b8cu,message,c,&result);if(rc||!result)return rc;
 rc=rr_receiver_message_purge_timed(m,r,0x23001b8cu,c);if(rc)return rc;return rr_receiver_message_put_timed(m,r,0x23001b8cu,message,c,&result);
}

int rr_receiver_disconnect_expiry(uint8_t*m,const uint8_t*f){
 if(!m||!f)return -1;ph(m+0x6590,0);pw(m+0x65e2,0x50000);return rr_receiver_connection_notice(m,f,1,0);
}
