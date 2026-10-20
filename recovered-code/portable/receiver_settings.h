#ifndef RR_RECEIVER_SETTINGS_H
#define RR_RECEIVER_SETTINGS_H
#include <stdint.h>
#include <stddef.h>
/* Explicit storage boundary state. stage=0 complete; stages1/2 read A/B,
 * 3/4 write A/B. entry and args are original low-level API entry/registers.
 * Caller supplies actual read-buffer effects and raw return value before resume.
 * No storage success, flash write, hardware entropy or scheduler is simulated. */
typedef struct {uint32_t stage,entry,args[4];} rr_receiver_settings_state;
uint16_t rr_receiver_settings_crc(const uint8_t*,size_t,uint16_t);
int rr_receiver_settings_mark(uint8_t*,uint32_t);
int rr_receiver_settings_load(uint8_t*,rr_receiver_settings_state*);
int rr_receiver_settings_flush(uint8_t*,rr_receiver_settings_state*);
int rr_receiver_settings_resume(uint8_t*,const uint8_t*,const uint8_t*,const uint8_t*,rr_receiver_settings_state*,uint32_t);
#endif
