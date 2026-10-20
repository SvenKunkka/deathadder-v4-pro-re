#ifndef RR_BUSINESS_CONTROL_H
#define RR_BUSINESS_CONTROL_H
#include <stdint.h>
/* Both class0 SWI paths, complete return for the domain. ram maps23000000.
 * nvic_pending models the stored word atE000E208, not actual IRQ effects.
 * peer0/1 on dongle; mouse ignores peer as original no-argument dispatcher.
 * -1 is explicit non-class0 boundary, not firmware return code. */
int rr_control_consume(uint8_t ram[65536],int mouse,unsigned peer,uint32_t *nvic_pending);
/* Original class0 RSSI/statistics updater2302552c, also the after-reassembly
 * statistics used by230254a0 when called with zero-extended16-bit metadata. */
void rr_dongle_business_stats(uint8_t ram[65536],unsigned peer,uint32_t metadata);
/* Mouse23021c6c interval setter/control enqueue; fast_clock[0/1] model
 *5302e040/5302e044. Valid peer0/1; original interval accepted1..64. */
void rr_mouse_control_interval(uint8_t ram[65536],unsigned peer,uint32_t interval,uint32_t fast_clock[2]);
/* Dongle230214bc enqueues28 and29, even if first enqueue fails. */
void rr_dongle_control_publish(uint8_t ram[65536]);
#endif
