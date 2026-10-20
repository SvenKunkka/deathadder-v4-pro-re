#include "receiver_vendor_flow.h"
#include "receiver_vendor_commands.h"
#include "receiver_radio_test_lifecycle.h"
#include "receiver_work_queue.h"
#include "receiver_config_control.h"
#include "business_tx.h"
#include "receiver_worker_runtime.h"
#include <string.h>
#define RAM(a) (0x23000000u+(a))
static int test_call(rr_rt_bus*b,uint32_t entry,uint32_t arg,uint32_t exception,rr_rt_event*ev,rr_rt_pending*p){
    uint32_t args[5]={arg,0,0,0,0};rr_rt_event one={ev?ev->disabled_value:0,0};
    int rc=rr_receiver_radio_test_flow_with_dependencies(b,entry,args,&one,p,rr_receiver_radio_test_dependencies,&exception);
    if(ev)ev->consumed+=one.consumed;return rc;
}
static int test_wrapper(rr_rt_bus*b,uint32_t entry,uint32_t arg,uint32_t exception,rr_rt_event*ev,rr_rt_pending*p){
    int rc=test_call(b,entry,arg,exception,ev,p);if(rc)return rc;
    uint8_t*rtc=rr_rt_mut(b,0x5f99c000,4096);if(!rtc)return -2;
    rr_receiver_rtos cpu={b->priority,exception,0,0};int32_t result;
    rc=rr_receiver_work_submit(b->ram,rtc,RAM(0x2c94),RAM(0x2b18),&cpu,&result);b->priority=cpu.priority;
    if(rc==1)return rr_rt_stop(p,cpu.entry,cpu.arg0,0,0,1);return rc;
}
static int statistics(rr_rt_bus*b,uint32_t value,uint32_t exception,rr_rt_pending*p){
    if(rr_rt_r(b,RAM(0x659a),2)==value)return 0;
    rr_rt_w(b,RAM(0x659a),(value&65535u)|(value<<16),4);rr_rt_w(b,RAM(0x659e),0,2);rr_rt_w(b,RAM(0x65b0),0,4);
    uint8_t data[4]={0xac,(uint8_t)(value>>8),(uint8_t)value,0};rr_bt_dongle_tx(b->ram,0,3,data,3,NULL,NULL);
    uint8_t*rtc=rr_rt_mut(b,0x5f99c000,4096);if(!rtc)return -2;rr_receiver_rtos cpu={b->priority,exception,0,0};int rc=0;
    if((value&65535u)==0){if(b->ram[0x6598]){b->ram[0x6598]=0;rc=rr_receiver_timer_stop_control(b->ram,rtc,RAM(0x1ad8),&cpu);}}
    else if(!b->ram[0x6598]){b->ram[0x6598]=1;rc=rr_receiver_timer_start_control(b->ram,rtc,RAM(0x1ad8),100000,1000,&cpu);}
    b->priority=cpu.priority;if(rc==1)return rr_rt_stop(p,cpu.entry,cpu.arg0,0,0,1);return rc;
}
static void checksum(uint8_t*m){uint8_t sum=0;for(unsigned i=0x2d1e;i<0x2d74;i++)sum^=m[i];m[0x2d74]=sum;}
int rr_receiver_vendor_flow(rr_rt_bus*b,uint32_t entry,uint32_t incoming,uint32_t exception,rr_rt_event*ev,rr_rt_pending*p){
    if(!b||!b->ram||!b->firmware||!p)return -1;memset(p,0,sizeof(*p));b->error=0;if(ev)ev->consumed=0;
    if(entry==0x23024db4)return statistics(b,incoming,exception,p);
    if(entry==0x2302048c||entry==0x23020510||entry==0x23020530){
        uint32_t target=entry==0x2302048c?0xe05c504:entry==0x23020510?0xe05c5ec:0xe05c6d4;
        if(entry!=0x23020530)b->ram[0x6595]=1;
        return test_wrapper(b,target,incoming,exception,ev,p);
    }
    if(entry!=0x2302604c&&entry!=0x23026090&&entry!=0x230205f8)return -2;
    const uint8_t*radio=rr_rt_const(b,0x5302c000,4096),*id=rr_rt_const(b,0x0fffe010,8),*boot=rr_rt_const(b,0x0000f000,16);
    if(!radio||!id||!boot)return -2;
    rr_receiver_vendor_pending call;int rc=rr_receiver_vendor_commands(b->ram,b->firmware,radio,id,boot,entry,incoming,&call);if(rc!=1)return rc;
    if(call.entry==0xe05c774)return test_call(b,call.entry,0,exception,ev,p);
    if(call.entry!=0xe05c504&&call.entry!=0xe05c5ec&&call.entry!=0xe05c6d4&&call.entry!=0x23024db4)return rr_rt_stop(p,call.entry,call.arg0,0,0,call.arg0_valid?1:0);
    rc=call.entry==0x23024db4?statistics(b,call.arg0,exception,p):test_wrapper(b,call.entry,call.arg0,exception,ev,p);if(rc)return rc;
    b->ram[0x2d1c]=2;
    if(entry!=0x2302604c){checksum(b->ram);b->ram[0x71bb]=0;}
    if(entry==0x230205f8)return test_call(b,0xe05c774,0,exception,ev,p);
    return b->error?-2:0;
}
typedef struct {rr_rt_bus*b;uint32_t exception;rr_rt_event*event;rr_rt_pending*pending;} vendor_context;
static int work_callback(void*context,uint32_t cb,uint32_t work,rr_receiver_rtos*cpu){
    vendor_context*k=context;
    if(cb!=0x230205f9){cpu->entry=cb&~1u;cpu->arg0=work;return 1;}
    k->b->priority=cpu->priority;
    int rc=rr_receiver_vendor_flow(k->b,0x230205f8,work,k->exception,k->event,k->pending);
    cpu->priority=k->b->priority;
    if(rc==1){cpu->entry=k->pending->entry;cpu->arg0=k->pending->args[0];}return rc;
}
int rr_receiver_vendor_work_step(rr_rt_bus*b,uint32_t queue,uint32_t exception,rr_rt_event*ev,rr_rt_pending*p){
    if(!b||!b->ram||!b->firmware||!p)return -1;memset(p,0,sizeof(*p));b->error=0;if(ev)ev->consumed=0;
    uint8_t*rtc=rr_rt_mut(b,0x5f99c000,4096),*aux=rr_rt_mut(b,0x5f9a2000,4096);if(!rtc||!aux)return -2;
    rr_receiver_rtos cpu={b->priority,exception,0,0};rr_receiver_usb_call usb={0,0,0,0};vendor_context ctx={b,exception,ev,p};
    int rc=rr_receiver_work_thread_step_with_handler(b->ram,rtc,aux,queue,&cpu,NULL,NULL,&usb,work_callback,&ctx);b->priority=cpu.priority;
    if(rc==1&&!p->kind){if(usb.entry)return rr_rt_stop(p,usb.entry,usb.device,usb.length,usb.buffer,7);return rr_rt_stop(p,cpu.entry,cpu.arg0,0,0,1);}
    return rc;
}
