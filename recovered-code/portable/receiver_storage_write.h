#ifndef RR_RECEIVER_STORAGE_WRITE_H
#define RR_RECEIVER_STORAGE_WRITE_H
#include "receiver_storage_read.h"
typedef int32_t (*rr_storage_write_fn)(void*,uint32_t,uint32_t,const uint8_t*,uint32_t);
typedef int32_t (*rr_storage_lock_fn)(void*,uint32_t,uint64_t);
typedef int32_t (*rr_storage_unlock_fn)(void*,uint32_t);
typedef struct {rr_storage_read_fn read;rr_storage_write_fn write;rr_storage_lock_fn lock;rr_storage_unlock_fn unlock;void*user;uint32_t block_size;uint8_t erase_value;} rr_receiver_storage_io;
/* The context is the original72-byte RAM object. block_size/erase_value are
 * explicit device-parameter inputs (original dereference of context+3C).
 * Supported mounted domain: power-of-two block_size1..32, slot=aligned16,
 * valid finite page graph. Driver callbacks provide actual synchronous effects.
 * Reads that return nonnegative must fill all requested bytes. Mutex effects
 * are external, not invented; lock/unlock returns are ignored as in firmware. */
int32_t rr_receiver_storage_write_bytes(uint8_t[72],uint64_t,const uint8_t*,uint32_t,rr_receiver_storage_io*);
int32_t rr_receiver_storage_append_data(uint8_t[72],const uint8_t*,uint32_t,rr_receiver_storage_io*);
int32_t rr_receiver_storage_append_record(uint8_t[72],const uint8_t[16],rr_receiver_storage_io*);
int32_t rr_receiver_storage_initialize_page(uint8_t[72],uint32_t,rr_receiver_storage_io*);
int32_t rr_receiver_storage_rotate(uint8_t[72],rr_receiver_storage_io*);
int32_t rr_receiver_storage_collect(uint8_t[72],rr_receiver_storage_io*);
int32_t rr_receiver_storage_write(uint8_t[72],uint32_t,uint32_t,const uint8_t*,uint32_t,rr_receiver_storage_io*);
/* Continue settings write stages using restored record writer; mounted context
 * and real external mutex semantics remain prerequisites. */
int rr_receiver_settings_write_continue(uint8_t*,const uint8_t*,const uint8_t*,const uint8_t*,rr_receiver_settings_state*,rr_receiver_storage_io*);
#endif
