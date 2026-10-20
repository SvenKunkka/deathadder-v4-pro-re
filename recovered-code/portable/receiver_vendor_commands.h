#ifndef RR_RECEIVER_VENDOR_COMMANDS_H
#define RR_RECEIVER_VENDOR_COMMANDS_H
#include <stdint.h>
typedef struct {uint32_t entry,arg0,arg0_valid;} rr_receiver_vendor_pending;
/* Receiver1.20: RAM128KiB, radio4KiB, ID8B from0FFFE010 and boot16B
 * from0000F000; official radio flash image124596B. Static snapshots only.
 * entry2604C=local dispatch (incoming_r0 retained for the opaque class10 call),
 * entry26090=checksum/local-or-peer routing, entry205F8=work callback wrapper.
 * Return0=full software return,1=real pending callee BEFORE execution,
 * -2=out-of-domain forwarded data length>80, -1=bad host argument.
 * Pending arg0_valid is0 for no-argument opaque callback0E05C774.
 * Existing peer queues must be coherently initialized. No physical device I/O.
 * Does not preserve unspecified returnr0 or recreateCPU stack/PRIMASK.
 */
int rr_receiver_vendor_commands(uint8_t*,const uint8_t*,const uint8_t*,const uint8_t[8],const uint8_t[16],uint32_t,uint32_t,rr_receiver_vendor_pending*);
#endif
