#ifndef RR_BUSINESS_KEYS_H
#define RR_BUSINESS_KEYS_H
#include <stdint.h>
/* Install original image table record into emulated RAM (base23000000).
 * table is the256 bytes extracted from the matching1.20 image, not generated.
 * All high28 bits of selector are ignored by the actual installer.
 */
void rr_business_install_key(uint8_t ram[65536],int mouse,uint32_t selector,const uint8_t table[256]);
/* Original32-byte-stack wrapper: copy length bytes, transform floor(length/4)
 * little-endian words, copy original length back; trailing1..3 bytes preserved.
 * length0..32 domain; return1 as original, or-1 without mutation outside domain.
 * key is read from installed RAM and unchanged. No nonce/authentication added.
 */
int rr_business_cipher_wrapper(uint8_t *data,uint8_t length,const uint8_t ram[65536],int mouse);
#endif
