#include "receiver_vendor_identity.h"
#include "receiver_config_producer.h"
#include "receiver_worker_runtime.h"
#include "business_tx.h"
#include <string.h>
static void checksum(uint8_t*m){
    uint8_t sum=0;for(unsigned i=0x2d1e;i<0x2d74;i++)sum^=m[i];m[0x2d74]=sum;
}
static int publish(rr_rt_bus*b,uint32_t entry,uint32_t value,uint32_t exception,
                   const uint8_t*tail,rr_rt_pending*p){
    uint8_t*rtc=rr_rt_mut(b,0x5f99c000,4096);if(!rtc)return -2;
    rr_receiver_rtos cpu={b->priority,exception,0,0};
    int rc=rr_receiver_config_value_publish(b->ram,rtc,entry==0x230252a4?8:9,value,tail,&cpu);
    b->priority=cpu.priority;
    if(rc==1)return rr_rt_stop(p,cpu.entry,cpu.arg0,0,0,1);
    return rc;
}
static int routed_tail(rr_rt_bus*b){
    uint8_t*m=b->ram;unsigned target=m[0x2d1d]>>5;
    unsigned peer=target==0?1:target==4?2:target==7?0:255;
    if(m[0x2d1c]==1){
        if(peer>=32||!((m[0x2c80]>>peer)&1)){m[0x2d1c]=4;checksum(m);}
        else if(peer==1||peer==2){
            unsigned n=m[0x2d21];if(n>80)return -2;
            m[0x2cb8]=0x5a;m[0x2cb9]=m[0x2d74];memcpy(m+0x2cba,m+0x2d1c,n+8);
            rr_bt_dongle_tx(m,peer-1,5,m+0x2cb8,n+10,NULL,NULL);
        }else{m[0x2d1c]=3;checksum(m);}
    }else checksum(m);
    m[0x71bb]=0;return 0;
}
static int identity_flow(rr_rt_bus*b,uint32_t entry,uint32_t incoming,uint32_t exception,
                         const uint8_t stack[512],unsigned depth,rr_rt_event*ev,rr_rt_pending*p){
    if(!b||!b->ram||!b->firmware||!p||!stack)return -1;
    memset(p,0,sizeof(*p));b->error=0;if(ev)ev->consumed=0;
    if(entry==0x230252a4||entry==0x23025300){
        if(depth>476)return -1;
        return publish(b,entry,incoming,exception,stack+512-depth-36,p);
    }
    int rc=rr_receiver_vendor_flow(b,entry,incoming,exception,ev,p);
    if(rc!=1||(p->entry!=0x230252a4&&p->entry!=0x23025300))return rc;
    unsigned offset=entry==0x2302604c?52:entry==0x23026090?76:84;
    if(depth>512-offset)return -1;
    uint32_t producer=p->entry,value=p->args[0];memset(p,0,sizeof(*p));
    rc=publish(b,producer,value,exception,stack+512-depth-offset,p);if(rc)return rc;
    /* 26212 sets status for op15. Op0B returns via26216 and retains status. */
    if(producer==0x230252a4)b->ram[0x2d1c]=2;
    if(entry!=0x2302604c){rc=routed_tail(b);if(rc)return rc;}
    /* pending flag is now clear: this executes only the real worker postlude. */
    if(entry==0x230205f8)return rr_receiver_vendor_flow(b,entry,incoming,exception,ev,p);
    return b->error?-2:0;
}
int rr_receiver_vendor_identity_flow(rr_rt_bus*b,uint32_t entry,uint32_t incoming,uint32_t exception,
                                    const uint8_t stack[512],rr_rt_event*ev,rr_rt_pending*p){
    return identity_flow(b,entry,incoming,exception,stack,0,ev,p);
}
typedef struct{rr_rt_bus*b;uint32_t exception;const uint8_t*stack;rr_rt_event*ev;rr_rt_pending*p;} context;
static int callback(void*user,uint32_t target,uint32_t work,rr_receiver_rtos*cpu){
    context*k=user;
    if(target!=0x230205f9){cpu->entry=target&~1u;cpu->arg0=work;return 1;}
    k->b->priority=cpu->priority;
    int rc=identity_flow(k->b,0x230205f8,work,k->exception,k->stack,64,k->ev,k->p);
    cpu->priority=k->b->priority;
    if(rc==1){cpu->entry=k->p->entry;cpu->arg0=k->p->args[0];}return rc;
}
int rr_receiver_vendor_identity_work_step(rr_rt_bus*b,uint32_t queue,uint32_t exception,
                                         const uint8_t stack[512],rr_rt_event*ev,rr_rt_pending*p){
    if(!b||!b->ram||!b->firmware||!p||!stack)return -1;
    memset(p,0,sizeof(*p));b->error=0;if(ev)ev->consumed=0;
    uint8_t*rtc=rr_rt_mut(b,0x5f99c000,4096),*aux=rr_rt_mut(b,0x5f9a2000,4096);if(!rtc||!aux)return -2;
    rr_receiver_rtos cpu={b->priority,exception,0,0};rr_receiver_usb_call usb={0,0,0,0};
    context k={b,exception,stack,ev,p};
    int rc=rr_receiver_work_thread_step_with_handler(b->ram,rtc,aux,queue,&cpu,NULL,NULL,&usb,callback,&k);
    b->priority=cpu.priority;
    if(rc==1&&!p->kind){
        if(usb.entry)return rr_rt_stop(p,usb.entry,usb.device,usb.length,usb.buffer,7);
        return rr_rt_stop(p,cpu.entry,cpu.arg0,0,0,1);
    }return rc;
}
