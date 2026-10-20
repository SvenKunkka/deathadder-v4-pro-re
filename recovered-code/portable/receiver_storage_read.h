#ifndef RR_RECEIVER_STORAGE_READ_H
#define RR_RECEIVER_STORAGE_READ_H
#include <stdint.h>
#include <stddef.h>
#include "receiver_settings.h"
/* 72-byte initialized context from RAM1F30/1F78. The callback implements the
 * external device's read entry: device, 32-bit physical address, destination,
 * length. Its actual result and bytes are consumed without assuming success.
 * Firmware startup/mount and flash driver are not part of this module.
 * Serialized callbacks must fill every requested byte when returning success.
 * prior[16] is the original caller frame record tail. Unexpected positive
 * driver errors can be treated as find-success by firmware, exposing this tail.
 * The API retains it explicitly instead of inventing zeroes. */
typedef int32_t (*rr_storage_read_fn)(void*,uint32_t,uint32_t,uint8_t*,uint32_t);
uint8_t rr_receiver_storage_crc8(const uint8_t*,size_t,uint8_t);
int32_t rr_receiver_storage_read_history(const uint8_t[72],uint32_t,uint8_t*,uint32_t,uint32_t,const uint8_t[16],rr_storage_read_fn,void*);
int32_t rr_receiver_storage_read(const uint8_t[72],uint32_t,uint8_t*,uint32_t,const uint8_t[16],rr_storage_read_fn,void*);
/* Original device vtable entries0E067488/74B4/74F0 operate on a 2MiB
 * mapped region. These functions modify caller-owned memory ONLY; they are
 * not hardware flash programming and do not establish physical persistence. */
int32_t rr_receiver_storage_mapped_read(void*,uint32_t,uint32_t,uint8_t*,uint32_t);
int32_t rr_receiver_storage_mapped_write(uint8_t*,uint32_t,const uint8_t*,uint32_t);
int32_t rr_receiver_storage_mapped_erase(uint8_t*,uint32_t,uint32_t);
/* Compose restored read backend with existing settings state until the next
 * write boundary or completion. Mounted contexts remain a caller precondition. */
int rr_receiver_settings_read_continue(uint8_t*,const uint8_t*,const uint8_t*,const uint8_t*,rr_receiver_settings_state*,const uint8_t[32],rr_storage_read_fn,void*);
#endif
