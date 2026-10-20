#include "mouse_lifecycle_runtime.h"
static uint32_t g32(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void s16(uint8_t*p,uint16_t v){p[0]=(uint8_t)v;p[1]=(uint8_t)(v>>8);}
static void s32(uint8_t*p,uint32_t v){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(v>>(i*8));}
int rr_mouse_disconnect_runtime(uint8_t*m,uint8_t*r,uint8_t*t,uint8_t*rtc,uint32_t*c,uint32_t reason,rr_mouse_rtos*cpu){
 if(!m||!r||!t||!rtc||!c||!cpu)return -1;cpu->entry=0;cpu->arg0=0;
 s16(m+0x27ba,0);s16(m+0x2796,(uint16_t)reason);
 if(m[0x76ee]){c[1]=1;m[0x76ee]=0;}s32(t+0x8c,0);
 int rc=rr_mouse_timer_stop_runtime(m,rtc,0x23001540u,cpu);if(rc)return rc;
 rc=rr_mouse_timer_stop_runtime(m,rtc,0x23001540u,cpu);if(rc)return rc;
 for(unsigned mode=0;mode<3;mode++){
  s32(m+0x2a04,0);s32(r+0x200,0);s32(r+0x218,0);s32(r+0x220,0);s32(r+0x10,1);
  if(mode==2){s32(r+0x100,0);s32(r+0x108,0);s32(t+0x558,0);}
  s32(r+0x104,0);s32(r+0x110,0);s32(t+0xdc,0);s32(t+4,1);s32(m+0x2978,0);s16(m+0x2794,0);
 }
 s32(t+0x558,0);s32(t+4,1);s32(t+0xc,1);
 return rr_mouse_timer_stop_runtime(m,rtc,0x23001540u,cpu);
}
int rr_mouse_disconnect_ack_runtime(uint8_t*m,uint8_t*r,uint8_t*t,uint8_t*rtc,uint32_t*c,rr_mouse_rtos*cpu){
 int rc=rr_mouse_timer_stop_runtime(m,rtc,0x230015b0u,cpu);if(rc)return rc;return rr_mouse_disconnect_runtime(m,r,t,rtc,c,m[0x6b7b],cpu);
}
int rr_mouse_ack_callback_runtime(uint8_t*m,uint8_t*r,uint8_t*t,uint8_t*rtc,uint32_t*c,uint16_t cls,rr_mouse_rtos*cpu){
 if(!m||!cpu)return -1;cpu->entry=0;cpu->arg0=0;if(cls!=3||!g32(m+0x6b68))return 0;
 if(g32(m+0x6b68)!=0x23025c2du)return -2;
 int rc=rr_mouse_disconnect_ack_runtime(m,r,t,rtc,c,cpu);if(!rc)s32(m+0x6b68,0);return rc;
}

