#include "receiver_radio_test_lifecycle.h"
#include "receiver_radio_test_log.h"
#include "receiver_radio_test_timer.h"
#include "receiver_radio_test_gppi.h"
#include "receiver_config_control.h"
#include <string.h>
#define RAM(a) (0x23000000u+(a))
#define RADIO 0x5302c000u
static void stop_tail(rr_rt_bus*b){
    uint32_t mask=0;for(unsigned i=0;i<8;i++){unsigned ch=rr_rt_r(b,RAM(0x71c6-i),1);if(ch<32)mask|=1u<<ch;}
    rr_rt_w(b,0x53022508,mask,4);rr_rt_w(b,0xe000e184,0x100,4);
    rr_rt_w(b,RAM(0x52f0),0,4);rr_rt_w(b,0x53028004,1,4);
    rr_rt_w(b,RADIO+0x100,0,4);rr_rt_w(b,RADIO+0x104,0,4);rr_rt_w(b,RADIO+0x110,0,4);rr_rt_w(b,RADIO+0x10c,0,4);
    rr_rt_w(b,RAM(0x3230),0,2);rr_rt_w(b,RADIO+0x10,1,4);
}
static int normal_stop(rr_rt_bus*b,uint32_t exception,rr_rt_pending*p){
    rr_receiver_rtos cpu={b->priority,exception,0,0};uint8_t*rtc=rr_rt_mut(b,0x5f99c000,4096);if(!rtc)return -2;
    int rc=rr_receiver_thread_suspend_control(b->ram,rtc,RAM(0x1fc0),&cpu);b->priority=cpu.priority;
    if(rc==1)return rr_rt_stop(p,cpu.entry,cpu.arg0,0,0,1);
    if(rc)return rc;
    rr_rt_w(b,RAM(0x3232),0,2);
    for(unsigned i=0;i<2;i++){
        rr_rt_w(b,RADIO+0x100,0,4);rr_rt_w(b,RADIO+0x104,0,4);rr_rt_w(b,RADIO+0x110,0,4);
        if(i==0)rr_rt_w(b,RAM(0x3252),0,2);
        rr_rt_w(b,RAM(0x3468+i*0xf84),0,4);
        rr_rt_w(b,RADIO+0x200,0,4);rr_rt_w(b,RADIO+0x218,0,4);rr_rt_w(b,RADIO+0x220,0,4);rr_rt_w(b,RADIO+0x10,1,4);
    }
    stop_tail(b);return b->error?-2:0;
}
static int log_message(rr_rt_bus*b,uint32_t fmt,uint32_t value,rr_rt_pending*p){
    uint32_t args[5]={fmt,value,0,0,0},result=0;
    return rr_receiver_radio_test_log(b,args,&result,p);
}
static int test_initialize(rr_rt_bus*b,uint32_t context,uint32_t*result,rr_rt_pending*p){
    /* Equivalent local config bytes. The source stores its config on CPU
     * stack; only its contents/context escape. This private window is not
     * projected RAM and is never retained after the synchronous helper. */
    if(b->window_count>16)return -2;
    uint8_t cfg[12]={0x40,0x42,0x0f,0,0,2,0,0,0,0,0,0};
    for(unsigned i=0;i<4;i++)cfg[8+i]=(uint8_t)(context>>(8*i));
    rr_rt_window win[17];for(size_t i=0;i<b->window_count;i++)win[i]=b->windows[i];
    win[b->window_count]=(rr_rt_window){0x2302efe4,cfg,sizeof(cfg)};
    rr_rt_bus local=*b;local.windows=win;local.window_count=b->window_count+1;
    uint32_t args[5]={0xe06fd14,0x2302efe4,0xe05cd05,0,0},value=0;
    int rc=rr_receiver_radio_test_timer(&local,0xe069ee8,args,&value,p);b->error=local.error;b->priority=local.priority;if(rc)return rc;
    if(value!=0xbad0000){rc=log_message(b,0xe06fca4,value,p);if(rc)return rc;}
    rr_rt_w(b,0xe000e429,0xe0,1);rr_rt_w(b,RAM(0x661c),context,4);
    args[0]=RAM(0x71df);rc=rr_receiver_radio_test_gppi(b,0xe06a658,args,&value,p);if(rc)return rc;
    if(value==0xbad0000){rc=log_message(b,0xe06fcec,rr_rt_r(b,RAM(0x71df),1),p);if(rc)return rc;*result=0;}
    else{rc=log_message(b,0xe06fcc8,0,p);if(rc)return rc;*result=(uint32_t)-14;}
    return b->error?-2:0;
}
int rr_receiver_radio_test_lifecycle(rr_rt_bus*b,uint32_t entry,const uint32_t args[5],uint32_t exception,uint32_t*result,rr_rt_pending*p){
    if(!b||!b->ram||!b->firmware||!args||!result||!p)return -1;
    memset(p,0,sizeof(*p));b->error=0;*result=0;int rc;
    switch(entry){
    case 0x23021f04:stop_tail(b);break;
    case 0x23021f88:return normal_stop(b,exception,p);
    case 0x23021d9c:rc=normal_stop(b,exception,p);if(rc)return rc;rr_rt_w(b,RAM(0x3230),5,2);break;
    case 0x23021db0:rr_rt_w(b,RAM(0x3230),0,2);break;
    case 0xe05d1ac:return test_initialize(b,args[0],result,p);
    case 0xe05d634:return rr_receiver_radio_test_log(b,args,result,p);
    case 0xe0612f0:{
        int32_t irq=(int16_t)args[0];uint8_t priority=(args[2]&1)?0:(uint8_t)((args[1]+2)*32);
        rr_rt_w(b,irq<0?0xe000ed14u+((uint32_t)irq&15):0xe000e400u+(uint32_t)irq,priority,1);break;
    }
    default:return -2;
    }
    return b->error?-2:0;
}
int rr_receiver_radio_test_dependencies(void*context,rr_rt_bus*b,uint32_t entry,const uint32_t args[5],rr_rt_pending*p){
    uint32_t result=0;return rr_receiver_radio_test_lifecycle(b,entry,args,context?*(const uint32_t*)context:0,&result,p);
}
