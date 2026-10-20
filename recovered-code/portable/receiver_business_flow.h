#ifndef RR_RECEIVER_BUSINESS_FLOW_H
#define RR_RECEIVER_BUSINESS_FLOW_H
#include <stdint.h>
/* Authored complete2302455C integration for classes0..5 within component bounds.
 * RAM maps23000000; flash is original1.20 receiver radio image. peer0/1.
 * nvic_pending modelsE000E208 only. No physical interrupt/device operations.
 * Returns0 done,1 explicit USB driver pending,-1 component-domain unsupported.
 * Cipher final message lengths8/16 only; fragment totals<=128. This is host
 * model coverage, not original firmware validation. State before an unsupported
 * boundary may already change; never interpret -1 as original rollback.
 */
typedef struct {uint8_t active,peer,metadata,reserved;uint32_t device;} rr_receiver_business_pending;
int rr_receiver_business_flow(uint8_t *ram,const uint8_t *flash,unsigned peer,uint32_t *nvic_pending,rr_receiver_business_pending *pending);
/* Explicit environment result after USB driver execution, not a success stub.
 * Applies real consumer continuation then delayed statistics/dispatch finish. */
int rr_receiver_business_resume(uint8_t *ram,int32_t driver_result,rr_receiver_business_pending *pending);
#endif
