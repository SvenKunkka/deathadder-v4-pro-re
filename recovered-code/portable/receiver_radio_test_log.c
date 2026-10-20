#include "receiver_radio_test_log.h"
#include <string.h>
typedef struct { uint32_t address; const char *text; unsigned integer_bits; } log_format;
static const log_format formats[]={
    {0x0e06fbfcu,"TX power to enumerator conversion failed, defaulting to 0 dBm\n",0},
    {0x0e06fc3cu,"Requested tx output power: %hhi dBm\n",8},
    {0x0e06fc64u,"Tx output power set to: %hhi dBm\n",8},
    {0x0e06fc88u,"Unexpected test type: %d\n",32},
    {0x0e06fca4u,"nrfx_timer_init failed with: %d\n",32},
    {0x0e06fcc8u,"Failed to allocate gppi channel.\n",0},
    {0x0e06fcecu,"ppi_radio_start = %d\n",32}
};
static uint32_t decimal_count(uint32_t v,unsigned bits) {
    uint32_t sign,magnitude;
    if(bits==8u) {v&=255u;sign=v>>7;magnitude=sign ? 256u-v : v;}
    else {sign=v>>31;magnitude=sign ? 0u-v : v;}
    uint32_t n=1u+sign;
    while(magnitude>=10u) {magnitude/=10u;++n;}
    return n;
}
int rr_receiver_radio_test_log(rr_rt_bus *b,const uint32_t args[5],
    uint32_t *result,rr_rt_pending *pending) {
    if(!b || !args || !result || !pending || !b->ram || !b->firmware) return -2;
    memset(pending,0,sizeof(*pending));*result=0;
    const log_format *format=NULL;
    for(size_t i=0;i<sizeof(formats)/sizeof(formats[0]);i++)
        if(args[0]==formats[i].address) {format=&formats[i];break;}
    if(!format) return -2;
    size_t n=strlen(format->text);
    const uint8_t *rom=rr_rt_const(b,format->address,n+1u);
    if(!rom || memcmp(rom,format->text,n+1u)!=0 || b->error) return -2;
    uint32_t sink=rr_rt_r(b,0x23000494u,4);
    if(b->error || !(sink&1u)) return -2;
    if(sink!=0x0e05d625u)
        return rr_rt_stop(pending,sink&~1u,(uint8_t)format->text[0],0,0,1);
    uint32_t count=(uint32_t)n;
    if(format->integer_bits)
        count=count-(format->integer_bits==8u ? 4u : 2u)+decimal_count(args[1],format->integer_bits);
    *result=count;
    return 0;
}
