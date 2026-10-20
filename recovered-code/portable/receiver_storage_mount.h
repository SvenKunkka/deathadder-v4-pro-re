#ifndef RR_RECEIVER_STORAGE_MOUNT_H
#define RR_RECEIVER_STORAGE_MOUNT_H
#include "receiver_storage_write.h"
#include "receiver_storage_scan.h"
/* Original E6D4 mount; includes CD9C mutex-object initialization.
 * parameter_address is the result of the device parameter getter. IO carries
 * its stable block/erase values. The actual device uses16/FF at0E070394.
 * Supported continuation: power-of-two block1..32, finite consistent page
 * geometry. Read callbacks return0 with a full buffer, or negative error.
 * Distinct context and storage; mutex callbacks may return any value, ignored
 * by firmware, but must not modify context. Actual blocking is not modeled.
 * No physical hardware access is performed by this module itself. */
int32_t rr_receiver_storage_mount(uint8_t[72],uint32_t,uint32_t,rr_receiver_storage_io*);
#endif
