#ifndef RR_RECEIVER_LEGACY_BUSINESS_H
#define RR_RECEIVER_LEGACY_BUSINESS_H
#include <stdint.h>
/* Exact valid-domain adapters for receiver mode1 23023968 / mode2 23022D90.
 * 0=completed,1=real USB driver boundary pending,-1=unsupported model domain.
 * Requires valid RAM and existing RX bounds (class0..5, bank<=128B,
 * class2/4 completed encrypted8/16B). Mode2 short malformed len1/2 that
 * underflow original copy lengths are explicitly unsupported, not firmware
 * validation. A downstream unsupported result may retain original prefix
 * mutations; this API does not promise transactional rollback.
 */
typedef struct {uint8_t active,selected_peer,forward_peer,metadata;uint32_t device;} rr_receiver_legacy_pending;
int rr_receiver_legacy_business(uint8_t *ram,const uint8_t *flash,unsigned mode,unsigned peer,rr_receiver_legacy_pending *pending);
int rr_receiver_legacy_resume(uint8_t *ram,int32_t driver_result,rr_receiver_legacy_pending *pending);
#endif
