/* Authored reconstruction of mouse23020d50 / dongle2302003c.
 * Original business callers use n=2 or n=4, 32/19 rounds respectively.
 * Wrapper domain n=1..8 is supported; guard is an analysis boundary, not device validation. */
#include "business_cipher.h"
int rr_cipher_encrypt_words(uint32_t *v, unsigned n, const uint32_t *k) {
    if(n<1u || n>8u)return -1;
    uint32_t sum=0, z=v[n-1], y, e;
    unsigned rounds=6+52/n;
    for(unsigned r=0;r<rounds;r++) {
        sum+=UINT32_C(0x9e3779b9);e=sum>>2;
        for(unsigned p=0;p<n;p++) {
            y=v[p==n-1?0:p+1];
            uint32_t a=(y<<2 ^ z>>5)+(z<<4 ^ y>>3);
            uint32_t b=(k[(e^p)&3]^z)+(sum^y);
            v[p]+=a^b;z=v[p];
        }
    }
    return 0;
}
int rr_cipher_decrypt_words(uint32_t *v, unsigned n, const uint32_t *k) {
    if(n<1u || n>8u)return -1;
    uint32_t sum=(6+52/n)*UINT32_C(0x9e3779b9), y=v[0],z,e;
    do {
        e=sum>>2;
        for(unsigned p=n;p--;) {
            z=v[p==0?n-1:p-1];
            uint32_t a=(z<<4 ^ y>>3)+(y<<2 ^ z>>5);
            uint32_t b=(k[(e^p)&3]^z)+(sum^y);
            v[p]-=a^b;y=v[p];
        }
        sum+=UINT32_C(0x61c88647);
    } while(sum);
    return 0;
}
