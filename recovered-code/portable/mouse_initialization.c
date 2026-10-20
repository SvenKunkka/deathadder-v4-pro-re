#include "mouse_initialization.h"
#include "business_keys.h"
#include <string.h>
static uint32_t w(const uint8_t*p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void pw(uint8_t*p,uint32_t v){for(unsigned i=0;i<4;i++)p[i]=(uint8_t)(v>>(i*8));}
static void ph(uint8_t*p,uint32_t v){p[0]=(uint8_t)v;p[1]=(uint8_t)(v>>8);}
static void irq(uint8_t*n,unsigned number,unsigned priority){
    n[0x400+number]=(uint8_t)priority;
    pw(n+0x280+4*(number/32),1u<<(number%32));
    pw(n+0x100+4*(number/32),1u<<(number%32));
}
int rr_mouse_radio_queue_initialize(uint8_t*m,uint32_t index){
    if(!m||index>31)return -1;unsigned off=index*0xee0;
    memset(m+0x2ad6+off,0,12);
    pw(m+0x2ae6+off,0x10106020);pw(m+0x2ae2+off,0x20100520);pw(m+0x2aea+off,0x10101010);
    static const unsigned pointers[]={0x2b08,0x2d08,0x2d58,0x2e58,0x3058,0x3258};
    for(unsigned i=0;i<6;i++)pw(m+0x2af0+off+4*i,0x23000000u+off+pointers[i]);
    return 0;
}
int rr_mouse_radio_reset(uint8_t*m){
    if(!m)return -1;
    memset(m+0x2978,0,0xee0);memset(m+0x2794,0,0x1e4);memset(m+0x2688,0,0x10c);
    memset(m+0x2a3a,255,16);return rr_mouse_radio_queue_initialize(m,0);
}
int rr_mouse_radio_dppi(rr_mouse_init_hw*x){
    if(!x||!x->ram||!x->timer||!x->radio||!x->dppi)return -1;
    x->ram[0x76f4]=1;x->ram[0x76f5]=0;
    for(unsigned i=2;i<=6;i++)x->ram[0x76f5-i]=(uint8_t)i;
    for(unsigned i=0;i<6;i++)pw(x->timer+0x1c0+4*i,0x80000000u+i);
    pw(x->radio+0x30c,0x80000006);pw(x->dppi+0x504,0x7f);return 0;
}
int rr_mouse_radio_initialize(rr_mouse_init_hw*x,uint32_t identity,uint8_t phy){
    if(!x||!x->ram||!x->radio||!x->nvic)return -1;
    uint8_t*m=x->ram,*r=x->radio,*n=x->nvic;
    pw(n+0x184,0x1000);pw(r+0x10,1);pw(r+0x704,1);pw(r+0xe3c,1);pw(r+0xe40,10);
    pw(r+0xe34,0xc3c2c1e7);pw(r+0xe38,0xc7c6c5c4);pw(r+0xe2c,0xeb8a542c);pw(r+0xe30,identity);
    pw(r+0x500,phy);pw(r+0x710,0x18);
    ph(m+0x261b,0x101);pw(m+0x2610,0);pw(m+0x2614,0);ph(m+0x2618,0);
    m[0x261a]=3;m[0x2610]=5;m[0x2618]=31;m[0x2615]=1;
    m[0x2625]=1;m[0x262c]=1;pw(r+0xe20,0x1000005);pw(r+0xe28,0x303001f);
    ph(m+0x2620,5);m[0x2622]=0;
    pw(r+0xe44,0x102);pw(r+0xe48,0x11021);pw(r+0xe4c,0xffff);
    pw(r+0x400,w(r+0x400)|0x80001);pw(m+0x2628,0x102001f);pw(r+0x488,0x108);
    pw(r+0x20c,0);pw(r+0x200,0);pw(r+0x218,0);pw(r+0x220,0);irq(n,44,0);return 0;
}
int rr_mouse_initialize(rr_mouse_init_hw*x,uint32_t identity,uint32_t capability,
                        uint32_t field_a,uint32_t field_b,uint32_t rate){
    if(!x||!x->ram||!x->radio||!x->timer||!x->nvic||!x->dppi||!x->clock)return -1;
    uint8_t*m=x->ram,*t=x->timer,*n=x->nvic;
    rr_mouse_radio_reset(m);rr_mouse_radio_dppi(x);
    pw(m+0x27ac,identity);ph(m+0x279c,capability);pw(m+0x27b4,~identity);
    uint32_t packed=((field_a>>8)&255u)|((field_a&255u)<<8)|((field_b&0xff00u)<<8)|((field_b&255u)<<24);
    pw(m+0x297e,packed);rr_mouse_radio_initialize(x,identity,4);
    rate&=65535u;
    if(rate>=1&&rate<=64){
        ph(m+0x29ac,rate);
        if(rate==1){if(!m[0x76ee]){pw(x->clock+0x40,1);m[0x76ee]=1;}}
        else if(m[0x76ee]){pw(x->clock+0x44,1);m[0x76ee]=0;}
    }
    pw(n+0x184,0x100);pw(t+4,1);pw(t+12,1);pw(t+0x510,5);
    pw(t+0x504,w(t+0x504)&~3u);pw(t+0x508,(w(t+0x508)&~3u)|2u);
    for(unsigned i=0;i<8;i++)pw(t+0x540+4*i,0);
    pw(t+0x308,0xff0000);irq(n,40,0x20);irq(n,92,0x40);irq(n,91,0x40);return 0;
}
int rr_mouse_application_initialize(rr_mouse_init_hw*x,uint32_t identity,
                                    uint32_t field_a,uint32_t field_b,uint32_t rate,
                                    const uint8_t key_table[256]){
    if(!key_table)return -1;
    int rc=rr_mouse_initialize(x,identity,7,field_a,field_b,rate);if(rc)return rc;
    rr_business_install_key(x->ram,1,identity&65535u,key_table);
    ph(x->ram+0x6b72,field_a);ph(x->ram+0x6b74,field_b);pw(x->ram+0x6b68,0);x->ram[0x6b77]=1;
    return 0;
}
