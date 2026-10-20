#ifndef RR_RECEIVER_STORAGE_STARTUP_H
#define RR_RECEIVER_STORAGE_STARTUP_H
#include "receiver_storage_mount.h"
/* C6C0: state is the two-byte state reached through device+12; NULL device
 * returns false without touching state. Valid pointers otherwise required. */
int rr_receiver_storage_device_ready(uint32_t,const uint8_t[2]);
/* 673E8: explicit stable layout getter output, count entries of two LE words:
 * page count, page size. Output is12 bytes(start,size,index). No entries leaves
 * output size unchanged. Offset0 selects index mode. Unsigned arithmetic and
 * the configured ARM divide-by-zero result0 are preserved. */
int32_t rr_receiver_storage_page_info(const uint8_t*,uint32_t,uint32_t,uint32_t,uint8_t[12]);
/* 23025874/23025848 for the exact official1.20 descriptor/layout binding.
 * RAM128KiB and firmware124596 bytes must be valid. Device state RAM1A1A is
 * supplied by preceding device initialization, not set ready here. IO and
 * parameter values must match official16/FF. Mutex scheduling remains external.
 */
int32_t rr_receiver_storage_mount_partitions(uint8_t*,const uint8_t*,rr_receiver_storage_io*);
int32_t rr_receiver_storage_initialize(uint8_t*,const uint8_t*,rr_receiver_storage_io*);
#endif
