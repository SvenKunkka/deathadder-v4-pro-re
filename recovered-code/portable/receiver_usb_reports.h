#ifndef RR_RECEIVER_USB_REPORTS_H
#define RR_RECEIVER_USB_REPORTS_H
#include <stdint.h>
/* Reconstructed official1.20 USB report software, not an actual USB driver.
 * RAM128KiB and auxiliary MMIO4KiB at5F9A2000 are inert serialized snapshots.
 * Driver arguments are original r0/r1/r2; entry is the actual vtable target.
 * A NULL external_driver stops before its first instruction, return1.
 * An explicitly supplied hook provides external return/side effects; it does
 * NOT mean that the original driver has been recovered or executed.
 * Return0: callback completed; -1: invalid host pointer/entry selection.
 */
typedef struct {uint32_t entry,device,length,buffer;} rr_receiver_usb_call;
typedef int32_t (*rr_receiver_usb_external_driver)(void*,uint8_t*,const rr_receiver_usb_call*);
int rr_receiver_usb_reports(uint8_t*,uint8_t*,uint32_t,rr_receiver_usb_external_driver,void*,rr_receiver_usb_call*);
#endif
