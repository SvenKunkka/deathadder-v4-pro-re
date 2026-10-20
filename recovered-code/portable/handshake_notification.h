/* Original receiver state3 notification path; no hardware/RTOS execution. */
#ifndef RR_HANDSHAKE_NOTIFICATION_H
#define RR_HANDSHAKE_NOTIFICATION_H
#include "handshake.h"
#define RR_UNMODELED_QUEUE (-2)
typedef struct {
 uint8_t queue[40];       /* Object at original RAM address 23001b8c. */
 uint8_t ring[180];       /* Five 36-byte messages, original base 23015760. */
 uint8_t opaque_tail[20]; /* Explicit prior stack bytes, never forced to zero. */
 uint32_t other_pending, base1, rxaddresses;
} rr_notification_context;
/* Extends rr_dongle_handshake with no-waiter notification enqueue/purge.
 * Context models a serialized queue operation; a waiting thread or invalid
 * queue layout returns -2 without applying this branch. Scheduler/wakeup
 * and interrupt interleavings remain unrecovered. Caller must supply ctx
 * for state3 pending!=0; NULL returns the existing -1 boundary.
 */
int rr_dongle_handshake_step(uint8_t memory[RR_SLOT_BYTES],
 const uint8_t incoming[RR_HANDSHAKE_BYTES],uint8_t slot,
 rr_handshake_globals *globals,rr_notification_context *context);
#endif
