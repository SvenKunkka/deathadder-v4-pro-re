#ifndef RR_BUSINESS_CIPHER_H
#define RR_BUSINESS_CIPHER_H
#include <stdint.h>
/* Software XXTEA update loops used by the recovered 8/16-byte business paths.
 * Four key words and data words are loaded/stored as little endian in original
 * firmware. Caller supplies numeric uint32_t words; transform is in place.
 * n=1..8 matches the recovered wrappers' 32-byte local buffer domain;
 * -1 rejects other counts without mutation (analysis boundary, not firmware).
 * No key selection, framing, radio I/O or authentication policy is implied.
 */
int rr_cipher_encrypt_words(uint32_t *v,unsigned n,const uint32_t *k);
int rr_cipher_decrypt_words(uint32_t *v,unsigned n,const uint32_t *k);
#endif
