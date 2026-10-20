#ifndef RR_RECEIVER_STORAGE_SCAN_H
#define RR_RECEIVER_STORAGE_SCAN_H
#include "receiver_storage_read.h"
/* Reconstructed 0E05E018. Positions are distinct little-endian 8-byte objects,
 * separate from context and callback storage. Successful reads fill 16 bytes.
 * block_size is the original parameter word reached through context+3C.
 * This helper scans an already selected page; it does not perform full mount.
 * Finite traversal and valid callback/context pointers are caller preconditions.
 */
int32_t rr_receiver_storage_scan(const uint8_t[72],uint8_t[8],uint8_t[8],uint32_t,rr_storage_read_fn,void*);
#endif
