#ifndef RR_BUSINESS_TX_H
#define RR_BUSINESS_TX_H
#include <stdint.h>
/* Authored RAM-layout model for 1.20 business TX. No device I/O.
 * ram maps VMA 0x23000000..0x2300ffff; pointers stored in it are LE32 VMAs.
 * Caller owns and initializes RAM. side: 0 dongle, 1 mouse. peer: 0 or 1.
 * Preconditions: class0..5 (mouse_tx additionally rejects >=6 as firmware does),
 * valid ring fields/storage, lengths fitting source/storage. TX<=90 bytes;
 * mouse class1 must supply exactly6; class2/4 source length<=32. These are host
 * analysis-domain preconditions, NOT validation performed by original firmware.
 * Input mutable: mouse class1 rewrites first6 bytes; dongle writes data[len].
 * Original enqueue stores length low8 but copies full argument (class1 adjusts
 * it to uint16_t(len-1)); do not use oversized bodies in a16-byte ring entry.
 * IRQ instructions are serialized here; PRIMASK enable/disable is not modeled.
 */
typedef void (*rr_bt_before_enqueue)(void *opaque,uint8_t *ram,unsigned fragment);
void rr_bt_init(uint8_t *ram,int mouse,unsigned peer);
uint16_t rr_bt_free(const uint8_t *ram,int mouse,unsigned peer,unsigned cls);
uint32_t rr_bt_peek(uint8_t *ram,int mouse,unsigned peer,unsigned cls);
void rr_bt_pop(uint8_t *ram,int mouse,unsigned peer,unsigned cls);
int rr_bt_enqueue(uint8_t *ram,int mouse,unsigned peer,unsigned cls,const uint8_t *body,uint32_t length,uint16_t metadata);
/* Hook represents an explicitly injected external interleaving before enqueue;
 * NULL is normal serialized execution. It is test instrumentation, not firmware.
 * mouse returns effective message length after admission even on later failure.
 * dongle returns final r0 observed at machine entrypoint (free count if rejected,
 * last enqueue result otherwise); no claim that original C exposed this result.
 */
uint32_t rr_bt_mouse_tx(uint8_t *ram,unsigned peer,unsigned cls,uint8_t *data,uint32_t length,rr_bt_before_enqueue hook,void *opaque);
uint32_t rr_bt_dongle_tx(uint8_t *ram,unsigned peer,unsigned cls,uint8_t *data,uint32_t length,rr_bt_before_enqueue hook,void *opaque);
#endif
