#include "receiver_radio_test_control.h"
#include <string.h>

static uint16_t read16(const uint8_t *p) { return (uint16_t)(p[0] | p[1] << 8); }
static uint32_t read32(const uint8_t *p) {
    return (uint32_t)p[0] | (uint32_t)p[1] << 8 |
        (uint32_t)p[2] << 16 | (uint32_t)p[3] << 24;
}
static void write16(uint8_t *p, uint32_t v) { p[0]=(uint8_t)v; p[1]=(uint8_t)(v>>8); }
static void write32(uint8_t *p, uint32_t v) {
    for (unsigned i=0;i<4;i++) p[i]=(uint8_t)(v>>(8*i));
}
static int stop(rr_receiver_radio_test_pending *p, uint32_t entry,
        uint32_t arg, uint32_t valid) {
    p->entry=entry; p->arg0=arg; p->arg0_valid=valid; return 1;
}
static int pause_radio(rr_receiver_radio_test_pending *p) {
    /* 23021D9C calls this before writing halfword 3230=5. */
    return stop(p,0x23021f88,0,1);
}
static int stop_test(rr_receiver_radio_test_pending *p) {
    return stop(p,0x0e05d028,0,0);
}
static void mode(uint8_t *m, unsigned value) {
    if (value<=2) {
        const uint8_t modes[]={3,4,9};
        m[0x6601]=modes[value]; write32(m+0x6618,1u<<value);
    }
}
static uint8_t power(const uint8_t *fw, unsigned value) {
    return value<=16 ? fw[0x1bbe8+value] : 4;
}
static int descriptor_a(uint8_t *m,const uint8_t *fw,uint32_t arg0,
        uint32_t arg1,rr_receiver_radio_test_pending *p) {
    if (arg1) { m[0x71c9]=0; m[0x71c8]=0; if (!arg0) return 0; }
    if (arg0) {
        unsigned selection=m[0x71db],kind=0;
        if (selection>=1 && selection<=4) { kind=(selection&1)?1:2; m[0x6600]=0; }
        mode(m,m[0x71d9]); m[0x6602]=power(fw,m[0x71d4]);
        if (selection<6) m[0x6605]=2;
        write32(m+0x6608,m[0x71d7]<10?10:m[0x71d7]);
        write32(m+0x6610,m[0x71d3]);
        write32(m+0x660c,m[0x71d2]>99?100:m[0x71d2]);
        m[0x6603]=m[0x71d6]; m[0x6604]=m[0x71d5];
        if (kind==1) {
            write32(m+0x6614,0);
            m[0x71c9]=(uint8_t)(m[0x71d8]?4:m[0x71da]?(m[0x71d2]?3:2):1);
        } else if (kind==2) m[0x71c9]=(uint8_t)(m[0x71d8]?6:5);
    }
    unsigned type=m[0x71c9]; uint8_t *d=m+0x65e8;
    if (type<1 || type>6) return 0;
    if ((type==1 || type==2 || type==5) && m[0x71de]) return stop_test(p);
    /* The source clears 71DE after a test-stop return; here those paths stop
     * above, while paths entering with zero already have the same value. */
    memset(d,0,24); d[1]=m[0x6601];
    switch (type) {
    case 1: d[0]=0; d[4]=m[0x6602]; d[5]=m[0x6603]; break;
    case 2:
        d[0]=1; d[4]=m[0x6602]; d[5]=m[0x6600]; d[6]=m[0x6603];
        write32(d+8,read32(m+0x6614)); break;
    case 3:
        d[0]=5; d[4]=m[0x6602]; d[5]=m[0x6600]; d[6]=m[0x6603];
        write32(d+8,read32(m+0x660c)); write32(d+12,read32(m+0x6614)); break;
    case 4:
        d[0]=3; memcpy(d+4,m+0x6602,4); write32(d+8,read32(m+0x6608)); break;
    case 5: d[0]=2; d[4]=m[0x6600]; d[12]=m[0x6603]; break;
    case 6:
        d[0]=4; memcpy(d+4,m+0x6603,3); write32(d+8,read32(m+0x6608)); break;
    }
    return stop(p,0x0e05cd78,0x230065e8,1);
}
static int descriptor_b(uint8_t *m,const uint8_t *fw,rr_receiver_radio_test_pending *p) {
    if (m[0x71de]) return stop_test(p);
    mode(m,m[0x71cf]); m[0x6602]=power(fw,m[0x71ce]);
    m[0x6603]=m[0x71cd]; m[0x6600]=m[0x71cb];
    write32(m+0x6610,m[0x71cc]); unsigned divisor=m[0x71ca];
    if (divisor<2) { m[0x71ca]=1; write32(m+0x660c,50); }
    else if (divisor<99) write32(m+0x660c,100/(divisor+1));
    else { m[0x71ca]=99; write32(m+0x660c,1); }
    uint8_t *d=m+0x65e8; memset(d,0,24);
    d[0]=2; d[1]=m[0x6601]; d[4]=m[0x71cb]; d[12]=m[0x71cd];
    write32(d+8,m[0x71cc]); write32(d+16,0x0e05c0d5);
    write32(m+0x6614,read16(m+0x71ac));
    return stop(p,0x0e05cd78,0x230065e8,1);
}
int rr_receiver_radio_test_control(uint8_t *m,const uint8_t *fw,uint32_t entry,
        uint32_t arg0,uint32_t arg1,rr_receiver_radio_test_pending *p) {
    if (!m || !fw || !p) return -1;
    memset(p,0,sizeof(*p)); uint8_t *v=m+0x2d24;
    if ((entry==0x0e05c504 || entry==0x0e05c5ec || entry==0x0e05c6d4)
            && arg0!=0x23002d24) return -2;
    switch (entry) {
    case 0x0e05c504: {
        unsigned enabled=v[0];
        for (unsigned i=0;i<10;i++) m[0x71db-i]=v[i];
        if (enabled) {
            if (!m[0x71dd] && !m[0x71c7]) return pause_radio(p);
            m[0x71dd]=1; m[0x71dc]=1;
        } else {
            m[0x71dd]=0;
            if (m[0x71c7]) { write16(m+0x3230,0); return stop_test(p); }
        }
        return 0;
    }
    case 0x0e05c5ec:
        if (m[0x71d1] || m[0x71dd]==1) {
            if (m[0x71c7]) { write16(m+0x3230,0); return stop_test(p); }
            if (!m[0x71d1]) m[0x71dd]=0;
            return pause_radio(p);
        }
        if (!m[0x71c7]) return pause_radio(p);
        m[0x71d1]=1;
        for (unsigned i=0;i<6;i++) m[0x71cf-i]=v[i];
        for (unsigned i=0;i<4;i++) write16(m+0x71ac-i*2,(unsigned)v[6+i*2]*256+v[7+i*2]);
        m[0x71d0]=1; return 0;
    case 0x0e05c6d4:
        for (unsigned i=0;i<6;i++) v[i]=m[0x71cf-i];
        for (unsigned i=0;i<4;i++) { uint16_t n=read16(m+0x71ac-i*2); v[6+i*2]=(uint8_t)(n>>8); v[7+i*2]=(uint8_t)n; }
        return 0;
    case 0x0e05c774:
        if (m[0x71dd]==1 && m[0x71dc]==1) {
            m[0x71dc]=0;
            if (!m[0x71c7]) return pause_radio(p);
            int rc=descriptor_a(m,fw,1,0,p); if (rc) return rc;
        }
        if (m[0x71d1]==1 && m[0x71d0]==1) {
            m[0x71d0]=0; write16(m+0x71aa,0); write16(m+0x71a8,0); write16(m+0x71a6,0);
            return descriptor_b(m,fw,p);
        }
        return 0;
    case 0x0e05c214: return descriptor_a(m,fw,arg0,arg1,p);
    case 0x0e05c0e8: return descriptor_b(m,fw,p);
    case 0x0e05c200: m[0x71c9]=0; m[0x71c8]=0; return 0;
    case 0x0e05c0d4: write16(m+0x71a8,arg0); write16(m+0x71a6,arg1); return 0;
    default: return -1;
    }
}
