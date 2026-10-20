#include "receiver_radio_test_engine.h"
#include "receiver_radio_test_gppi.h"
#include "receiver_radio_test_timer.h"
#include "receiver_radio_test_control.h"
#include <string.h>
#define RAM(a) (0x23000000u+(a))
#define RADIO 0x5302c000u
#define TIMER 0x53029000u
#define EGU 0x53025000u
#define DESC 0x0e06fd14u
static uint32_t rb(rr_rt_bus*b,uint32_t a){return rr_rt_r(b,a,1);}
static uint32_t rw(rr_rt_bus*b,uint32_t a){return rr_rt_r(b,a,4);}
static void wb(rr_rt_bus*b,uint32_t a,uint32_t v){rr_rt_w(b,a,v,1);}
static void ww(rr_rt_bus*b,uint32_t a,uint32_t v){rr_rt_w(b,a,v,4);}
static uint32_t bit(uint32_t n){return (n&255)<32?1u<<(n&255):0;}
static int gp(rr_rt_bus*b,uint32_t entry,uint32_t a,uint32_t c,uint32_t d,uint32_t *out,rr_rt_pending*p){
    uint32_t args[4]={a,c,d,0};return rr_receiver_radio_test_gppi(b,entry,args,out,p);
}
static int timer(rr_rt_bus*b,uint32_t entry,uint32_t a,uint32_t c,uint32_t d,uint32_t e,uint32_t *out,rr_rt_pending*p){
    uint32_t args[5]={DESC,a,c,d,e};return rr_receiver_radio_test_timer(b,entry,args,out,p);
}
static int disable(rr_rt_bus*b,uint32_t pc,rr_rt_event*event,rr_rt_pending*p){
    ww(b,RADIO+0x400,0);ww(b,RADIO+0x490,UINT32_MAX);ww(b,RADIO+0x220,0);ww(b,RADIO+0x10,1);
    if(!event || !event->disabled_value){
        p->kind=2;p->entry=pc;p->args[0]=RADIO+0x220;p->arg_mask=1;return 1;
    }
    event->consumed++;ww(b,RADIO+0x220,event->disabled_value);ww(b,RADIO+0x220,0);return 0;
}
static int dependency(rr_rt_bus*b,rr_rt_dependency fn,void*user,rr_rt_pending*p,uint32_t entry,uint32_t a0,uint32_t a1,uint32_t mask){
    if(!fn)return rr_rt_stop(p,entry,a0,a1,0,mask);
    uint32_t args[5]={a0,a1,0,0,0};return fn(user,b,entry,args,p);
}
static int power(rr_rt_bus*b,uint32_t value,rr_rt_pending*p,rr_rt_dependency fn,void*user){
    uint32_t encoded;
    switch(value){
    case (uint32_t)-70:encoded=0;break;case (uint32_t)-40:encoded=1;break;
    case (uint32_t)-30:encoded=2;break;case (uint32_t)-20:encoded=3;break;
    case (uint32_t)-16:encoded=8;break;case (uint32_t)-12:encoded=9;break;
    case (uint32_t)-8:encoded=10;break;case (uint32_t)-4:encoded=11;break;
    case (uint32_t)-2:encoded=12;break;case UINT32_MAX:encoded=13;break;
    case 0:encoded=14;break;case 1:encoded=15;break;
    case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:encoded=value+20;break;
    case 10:encoded=31;break;
    default:{int rc=dependency(b,fn,user,p,0x0e05d634,0x0e06fbfc,0,1);if(rc)return rc;encoded=14;break;}
    }
    ww(b,RADIO+0x710,encoded);
    if(!rb(b,RAM(0x71e0))){int rc=dependency(b,fn,user,p,0x0e05d634,0x0e06fc3c,value,3);if(rc)return rc;return dependency(b,fn,user,p,0x0e05d634,0x0e06fc64,value,3);}
    return 0;
}
static int packet_config(rr_rt_bus*b,uint32_t mode,uint32_t pattern,uint32_t length){
    ww(b,RADIO+0x704,1);ww(b,RADIO+0xe44,0);ww(b,RADIO+0xe48,0);ww(b,RADIO+0xe3c,0);ww(b,RADIO+0xe40,1);
    ww(b,RADIO+0xe34,pattern==0?0xab:pattern==2?0xcc:0x6a);
    ww(b,RADIO+0xe2c,pattern==0?0xabababab:pattern==2?0xcccccccc:0x58fe811b);
    length=(length?length:255)&255;
    uint32_t conf=8,conf1=length|0x3040000,bytes=length+7;
    if(mode==4){conf=0x1000008;bytes=length+8;}
    else if(mode==5 || mode==6){ww(b,RADIO+0xe44,0x103);ww(b,RADIO+0xe48,0);conf=0x63800008;conf1=length|0x2030000;bytes=length+0x17;}
    else if(mode==15){conf=0x2000008;conf1=127;bytes=0x85;}
    rr_rt_w(b,RAM(0x71ae),bytes,2);ww(b,RADIO+0xe20,conf);ww(b,RADIO+0xe28,conf1);return b->error?-2:0;
}
static int packet(rr_rt_bus*b,uint32_t mode,uint32_t pattern,uint32_t length){
    int rc=packet_config(b,mode,pattern,length);if(rc)return rc;
    wb(b,RAM(0x6730),mode==15?126:length?length:255);
    if(pattern){
        uint8_t*dst=rr_rt_mut(b,RAM(0x6731),255);if(!dst)return -2;
        memset(dst,pattern==1?240:pattern==2?204:(uint8_t)pattern,255);
    }else{
        uint32_t old=b->priority;if(!old||old>64)b->priority=64;
        if(rw(b,0x5f99c774)>0x3fffffff)return -4;
        b->priority=old;
        for(unsigned i=0;i<255;i+=4){
            uint64_t state=rw(b,RAM(0x230))|((uint64_t)rw(b,RAM(0x234))<<32);
            state=(state+rw(b,0x5f99c770))*UINT64_C(0x27bb2ee687b0b0fd)+UINT64_C(0xb504f32d);
            ww(b,RAM(0x230),(uint32_t)state);ww(b,RAM(0x234),(uint32_t)(state>>32));
            for(unsigned j=0;j<4&&i+j<255;j++)wb(b,RAM(0x6731+i+j),(uint32_t)(state>>(32+j*8)));
        }
    }
    ww(b,RADIO+0xed0,RAM(0x6730));return b->error?-2:0;
}
static int unlink_all(rr_rt_bus*b,rr_rt_pending*p){
    const uint32_t flags[]={0x10000,4,16,256};uint32_t out=0;
    for(unsigned i=0;i<4;i++){
        uint32_t old=rw(b,RAM(0x6620));ww(b,RAM(0x6620),old&~flags[i]);
        if(old&flags[i]){
            uint32_t h=rb(b,RAM(0x71df));int rc;
            if(i==0)rc=gp(b,0xe06a708,h,TIMER,0,&out,p);
            else rc=gp(b,0xe06a8e0,h,i==3?TIMER+0x140:EGU+0x100,i==2?RADIO+4:RADIO,&out,p);
            if(rc)return rc;
        }
    }return b->error?-2:0;
}
static int link_start(rr_rt_bus*b,uint32_t receive,rr_rt_pending*p){
    uint32_t out=0;int rc=unlink_all(b,p);if(rc)return rc;
    rc=gp(b,0xe06a760,rb(b,RAM(0x71df)),EGU+0x100,receive?RADIO+4:RADIO,&out,p);if(rc)return rc;
    ww(b,RAM(0x6620),rw(b,RAM(0x6620))|(receive?16:4));
    rc=gp(b,0xe06a6a0,rb(b,RAM(0x71df)),TIMER,0,&out,p);if(rc)return rc;
    ww(b,RAM(0x6620),rw(b,RAM(0x6620))|0x10000);
    return gp(b,0xe06ab28,bit(rb(b,RAM(0x71df))),0,0,&out,p);
}
static uint32_t frequency(uint32_t mode,uint32_t channel){return mode==15?(channel-11<16?channel*5-50:5):channel;}
static int tx_carrier(rr_rt_bus*b,uint32_t mode,uint32_t txpower,uint32_t channel,rr_rt_event*ev,rr_rt_pending*p,rr_rt_dependency fn,void*user){
    int rc=disable(b,0xe05cbdc,ev,p);if(rc)return rc;
    ww(b,RADIO+0x500,mode);ww(b,RADIO+0x400,rw(b,RADIO+0x400)|1);
    rc=power(b,txpower,p,fn,user);if(rc)return rc;ww(b,RADIO+0x708,frequency(mode,channel));
    if(rb(b,RAM(0x71e0))){rc=link_start(b,0,p);if(rc)return rc;}
    ww(b,rb(b,RAM(0x71e0))?EGU:RADIO,1);return b->error?-2:0;
}
static int receive(rr_rt_bus*b,uint32_t mode,uint32_t channel,uint32_t pattern,rr_rt_event*ev,rr_rt_pending*p){
    int rc=disable(b,0xe05cc70,ev,p);if(rc)return rc;
    ww(b,RADIO+0x500,mode);ww(b,RADIO+0x400,rw(b,RADIO+0x400)|0x21);ww(b,RADIO+0xed0,RAM(0x6630));
    rc=packet_config(b,mode,pattern,0);if(rc)return rc;ww(b,RADIO+0x708,frequency(mode,channel));
    ww(b,RAM(0x6628),0);ww(b,RAM(0x6624),0);ww(b,RADIO+0x488,0x800);
    if(rb(b,RAM(0x71e0))){rc=link_start(b,1,p);if(rc)return rc;}
    ww(b,rb(b,RAM(0x71e0))?EGU:RADIO+4,1);return b->error?-2:0;
}
static int sweep_start(rr_rt_bus*b,uint32_t channel,uint32_t interval,rr_rt_pending*p){
    uint32_t out=0;wb(b,RAM(0x71e1),channel);int rc=timer(b,0xe069f5c,0,0,0,0,&out,p);if(rc)return rc;
    ww(b,TIMER+0x200,0);ww(b,TIMER+0x308,UINT32_MAX);
    rc=timer(b,0xe069ff0,interval,0,0,0,&out,p);if(rc)return rc;
    rc=timer(b,0xe06a064,0,out,0x10001,1,&out,p);if(rc)return rc;
    return timer(b,0xe069f3c,0,0,0,0,&out,p);
}
static int engine(rr_rt_bus*b,uint32_t address,rr_rt_event*ev,rr_rt_pending*p,rr_rt_dependency fn,void*user){
    const uint8_t*d=rr_rt_const(b,address,24);if(!d)return -2;
    uint32_t kind=d[0],mode=d[1],channel=d[6],txpower=(uint32_t)(int32_t)(int8_t)d[4];
    if(kind==0)return tx_carrier(b,mode,txpower,d[5],ev,p,fn,user);
    if(kind==2)return receive(b,mode,d[12],d[4],ev,p);
    if(kind==3 || kind==4)return sweep_start(b,d[kind==3?5:4],rw(b,address+8),p);
    if(kind!=1 && kind!=5)return 0;
    uint32_t arg8=rw(b,address+8),arg12=rw(b,address+12),pattern=d[5],length=rw(b,address+(kind==1?12:16));
    int rc=disable(b,kind==1?0xe05cf14:0xe05ce86,ev,p);if(rc)return rc;
    rc=packet(b,mode,pattern,length);if(rc)return rc;
    uint32_t shorts=kind==5?0x80001:(mode==5||mode==6||mode==15)?0x100001:0x21;
    ww(b,RADIO+0x400,rw(b,RADIO+0x400)|shorts);ww(b,RADIO+0x500,mode);
    rc=power(b,txpower,p,fn,user);if(rc)return rc;ww(b,RADIO+0x708,frequency(mode,channel));ww(b,RAM(0x662c),0);
    if(kind==1){ww(b,RADIO+0x218,0);if(arg8)ww(b,RADIO+0x488,0x40);ww(b,RADIO,1);return b->error?-2:0;}
    uint32_t symbols=rr_rt_r(b,RAM(0x71ae),2)*rb(b,0xe06fd04+mode);
    uint32_t product=symbols*(100-arg8),interval=symbols+(arg8?product/arg8:0),out=0;
    rc=timer(b,0xe069f5c,0,0,0,0,&out,p);if(rc)return rc;
    rc=link_start(b,0,p);if(rc)return rc;
    ww(b,TIMER+0x200,0);ww(b,TIMER+0x308,UINT32_MAX);
    rc=timer(b,0xe069f84,interval,0,0,0,&out,p);if(rc)return rc;
    rc=timer(b,0xe06a064,1,out,2,0,&out,p);if(rc)return rc;
    if(arg12)ww(b,RADIO+0x488,0x40);
    uint32_t old=b->priority;if(!old||old>64)b->priority=64;ww(b,EGU,1);
    rc=gp(b,0xe06aacc,rb(b,RAM(0x71df)),0,0,&out,p);if(rc)return rc;
    if(out){rc=gp(b,0xe06ab4c,bit(rb(b,RAM(0x71df))),0,0,&out,p);if(rc)return rc;}
    rc=unlink_all(b,p);if(rc)return rc;
    rc=gp(b,0xe06a760,rb(b,RAM(0x71df)),TIMER+0x144,RADIO,&out,p);if(rc)return rc;
    ww(b,RAM(0x6620),rw(b,RAM(0x6620))|256);
    rc=gp(b,0xe06ab28,bit(rb(b,RAM(0x71df))),0,0,&out,p);if(rc)return rc;
    b->priority=old;return b->error?-2:0;
}
static int engine_dispatch(rr_rt_bus*b,uint32_t entry,const uint32_t args[5],rr_rt_event*ev,rr_rt_pending*p,rr_rt_dependency fn,void*user){
    if(!b||!b->ram||!b->firmware||!args||!p)return -1;
    memset(p,0,sizeof(*p));b->error=0;if(ev)ev->consumed=0;uint32_t out=0;int rc;
    switch(entry){
    case 0xe05c8fc:return power(b,args[0],p,fn,user);
    case 0xe05c9ec:return packet_config(b,args[0],args[1],args[2]);
    case 0xe05cac4:return packet(b,args[0],args[1],args[2]);
    case 0xe05c7f4:return unlink_all(b,p);
    case 0xe05cb44:return link_start(b,args[0],p);
    case 0xe05cbb8:return tx_carrier(b,args[0],args[1],args[2],ev,p,fn,user);
    case 0xe05cc4c:return receive(b,args[0],args[1],args[2],ev,p);
    case 0xe05c8a0:return sweep_start(b,args[0],args[1],p);
    case 0xe05cd78:return engine(b,args[0],ev,p,fn,user);
    case 0xe05d028:
        rc=timer(b,0xe069f5c,0,0,0,0,&out,p);if(rc)return rc;
        rc=timer(b,0xe069f7c,0,0,0,0,&out,p);if(rc)return rc;
        wb(b,RAM(0x71e0),0);rc=gp(b,0xe06aacc,rb(b,RAM(0x71df)),0,0,&out,p);if(rc)return rc;
        if(out){rc=gp(b,0xe06ab4c,bit(rb(b,RAM(0x71df))),0,0,&out,p);if(rc)return rc;}
        rc=unlink_all(b,p);if(rc)return rc;return disable(b,0xe05d066,ev,p);
    case 0xe05cd04:{
        if(args[0]!=0x140)return 0;uint32_t a=args[1],kind=rb(b,a);
        if(kind!=3 && kind!=4){if(!fn)return rr_rt_stop(p,0xe05d634,rr_rt_r(b,0xe05cd74,4),0,0,1);return dependency(b,fn,user,p,0xe05d634,rr_rt_r(b,0xe05cd74,4),kind,3);}
        wb(b,RAM(0x71e0),1);
        if(kind==3)rc=tx_carrier(b,rb(b,a+1),(uint32_t)(int32_t)(int8_t)rb(b,a+4),rb(b,RAM(0x71e1)),ev,p,fn,user);
        else rc=receive(b,rb(b,a+1),rb(b,RAM(0x71e1)),rb(b,a+4),ev,p);
        if(rc)return rc;
        unsigned start=kind==3?5:4;uint32_t next=(rb(b,RAM(0x71e1))+rb(b,a+start+2))&255;
        wb(b,RAM(0x71e1),next<=rb(b,a+start+1)?next:rb(b,a+start));wb(b,RAM(0x71e0),0);return b->error?-2:0;
    }
    default:return -2;
    }
}
static int engine_call(rr_rt_bus*b,uint32_t entry,uint32_t arg0,rr_rt_event*ev,rr_rt_pending*p,rr_rt_dependency fn,void*user){
    uint32_t args[5]={arg0,0,0,0,0};rr_rt_event one={ev?ev->disabled_value:0,0};
    int rc=engine_dispatch(b,entry,args,&one,p,fn,user);
    if(ev)ev->consumed+=one.consumed;return rc;
}
static int pause_initialize(rr_rt_bus*b,rr_rt_pending*p,rr_rt_dependency fn,void*user){
    int rc=dependency(b,fn,user,p,0x23021f88,0,0,1);if(rc)return rc;
    rr_rt_w(b,RAM(0x3230),5,2);
    return dependency(b,fn,user,p,0xe05d1ac,RAM(0x65e8),0,1);
}
static void copy_group_b(rr_rt_bus*b){
    uint8_t*m=b->ram,*v=m+0x2d24;m[0x71d1]=1;
    for(unsigned i=0;i<6;i++)m[0x71cf-i]=v[i];
    for(unsigned i=0;i<4;i++)rr_rt_w(b,RAM(0x71ac-i*2),(uint32_t)v[6+i*2]*256+v[7+i*2],2);
    m[0x71d0]=1;
}
static int control_flow(rr_rt_bus*b,uint32_t entry,uint32_t a0,uint32_t a1,rr_rt_event*ev,rr_rt_pending*p,rr_rt_dependency fn,void*user){
    if(entry==0xe05c774){
        if(rb(b,RAM(0x71dd))==1 && rb(b,RAM(0x71dc))==1){
            wb(b,RAM(0x71dc),0);
            if(!rb(b,RAM(0x71c7))){int rc=pause_initialize(b,p,fn,user);if(rc)return rc;wb(b,RAM(0x71c7),1);}
            int rc=control_flow(b,0xe05c214,1,0,ev,p,fn,user);if(rc)return rc;
        }
        if(rb(b,RAM(0x71d1))==1 && rb(b,RAM(0x71d0))==1){
            wb(b,RAM(0x71d0),0);rr_rt_w(b,RAM(0x71aa),0,2);rr_rt_w(b,RAM(0x71a8),0,2);rr_rt_w(b,RAM(0x71a6),0,2);
            return control_flow(b,0xe05c0e8,0,0,ev,p,fn,user);
        }
        return b->error?-2:0;
    }
    rr_receiver_radio_test_pending cp;
    int rc=rr_receiver_radio_test_control(b->ram,b->firmware,entry,a0,a1,&cp);
    if(rc!=1)return rc;
    if(cp.entry==0xe05d028){
        rc=engine_call(b,cp.entry,0,ev,p,fn,user);if(rc)return rc;
        if(entry==0xe05c504){wb(b,RAM(0x71c7),0);return 0;}
        if(entry==0xe05c5ec){
            wb(b,RAM(0x71c7),0);
            if(!rb(b,RAM(0x71d1)))wb(b,RAM(0x71dd),0);
            rc=pause_initialize(b,p,fn,user);if(rc)return rc;wb(b,RAM(0x71c7),1);copy_group_b(b);return 0;
        }
        wb(b,RAM(0x71de),0);
        /* C214's post-stop labels only construct the already selected
         * descriptor. Its argument-zero path enters that same switch; no
         * parameter initialization or preceding test-stop is repeated.
         * C0E8's post-stop path reloads all source fields and converts them. */
        if(entry!=0xe05c214 && entry!=0xe05c0e8)return -2;
        rc=rr_receiver_radio_test_control(b->ram,b->firmware,entry,0,0,&cp);
        if(rc!=1)return rc;
    }
    if(cp.entry==0xe05cd78){
        rc=engine_call(b,cp.entry,cp.arg0,ev,p,fn,user);if(rc)return rc;
        if(entry==0xe05c214){
            uint32_t selected=rb(b,RAM(0x71c9));wb(b,RAM(0x71c8),selected);wb(b,RAM(0x71c9),0);
            if(selected==3||selected==4||selected==6)wb(b,RAM(0x71de),1);
        }
        return b->error?-2:0;
    }
    if(cp.entry==0x23021f88 && (entry==0xe05c504 || entry==0xe05c5ec)){
        rc=pause_initialize(b,p,fn,user);if(rc)return rc;wb(b,RAM(0x71c7),1);
        if(entry==0xe05c504){wb(b,RAM(0x71dd),1);wb(b,RAM(0x71dc),1);}else copy_group_b(b);
        return b->error?-2:0;
    }
    return rr_rt_stop(p,cp.entry,cp.arg0,0,0,cp.arg0_valid?1:0);
}
int rr_receiver_radio_test_control_flow(rr_rt_bus*b,uint32_t entry,const uint32_t args[5],rr_rt_event*ev,rr_rt_pending*p){
    if(!b||!b->ram||!b->firmware||!args||!p)return -1;
    memset(p,0,sizeof(*p));b->error=0;if(ev)ev->consumed=0;
    return control_flow(b,entry,args[0],args[1],ev,p,NULL,NULL);
}

int rr_receiver_radio_test_engine(rr_rt_bus*b,uint32_t entry,const uint32_t args[5],rr_rt_event*ev,rr_rt_pending*p){
    return engine_dispatch(b,entry,args,ev,p,NULL,NULL);
}
int rr_receiver_radio_test_engine_with_dependencies(rr_rt_bus*b,uint32_t entry,const uint32_t args[5],rr_rt_event*ev,rr_rt_pending*p,rr_rt_dependency fn,void*user){
    return engine_dispatch(b,entry,args,ev,p,fn,user);
}
int rr_receiver_radio_test_flow_with_dependencies(rr_rt_bus*b,uint32_t entry,const uint32_t args[5],rr_rt_event*ev,rr_rt_pending*p,rr_rt_dependency fn,void*user){
    if(!b||!b->ram||!b->firmware||!args||!p)return -1;
    memset(p,0,sizeof(*p));b->error=0;if(ev)ev->consumed=0;
    return control_flow(b,entry,args[0],args[1],ev,p,fn,user);
}
