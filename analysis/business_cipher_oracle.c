/* Host-only independent C rendition of recovered update loops.
 * Newly authored test code, not target firmware. uint32_t wrap is intentional. */
#include <stdint.h>
void encrypt_words(uint32_t *v, unsigned n, const uint32_t *k) {
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
}
void decrypt_words(uint32_t *v, unsigned n, const uint32_t *k) {
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
}
