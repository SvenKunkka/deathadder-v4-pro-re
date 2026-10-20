#ifndef RR_DONGLE_BUSINESS_CONSUMER_H
#define RR_DONGLE_BUSINESS_CONSUMER_H
#include <stdint.h>
/* Raw RAM maps0x23000000..0x2300ffff. flash is the verified original dongle
 * radio image at0x0e054000 (lookup tables retained, no device I/O).
 * Preconditions: class0..5, buffers large enough; USB-copy length<=16;
 * vendor message2..90bytes. Consumer ignores length when reading fixed fields
 * exactly as original; caller must provide those bytes. No new device guards.
 * Return of consume is an ANALYSIS boundary enum, not original void r0.
 */
enum rr_dbc_boundary {RR_DBC_DONE=0,RR_DBC_USB_RESUME=1};
uint8_t rr_dbc_usb_enqueue(uint8_t *ram,unsigned cls,const uint8_t *data,uint32_t length);
void rr_dbc_status(uint8_t *ram,const uint8_t *flash,unsigned opcode,uint32_t value);
uint32_t rr_dbc_management(uint8_t *ram,const uint8_t *flash,unsigned peer,const uint8_t *data);
enum rr_dbc_boundary rr_dbc_consume(uint8_t *ram,const uint8_t *flash,unsigned cls,uint8_t *data,uint32_t length);
/* Continuation after external driver resume returns. This deliberately takes
 * an environment result; it does not implement driver/RTOS or claim success. */
void rr_dbc_resume_result(uint8_t *ram,int32_t driver_result);
#endif
