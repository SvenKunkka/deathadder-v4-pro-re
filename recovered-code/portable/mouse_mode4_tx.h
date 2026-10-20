#ifndef RR_MOUSE_MODE4_TX_H
#define RR_MOUSE_MODE4_TX_H
#include <stdint.h>
/* Original23024918 idle/action3. RAM/MMIO snapshot only, no PHY completion.
 * Returns0 for modeled return; -1 null, -9 malformed analysis-domain queue/
 * bank/channel layout before mutation. Caller supplies initialized rings.
 * Payload length is original byte: checksum can read stale bytes beyond the
 * 16-byte source copy. No extra firmware length validation is invented. */
int rr_mouse_mode4_tx(uint8_t *ram,uint8_t *radio,uint8_t *timer);
#endif
