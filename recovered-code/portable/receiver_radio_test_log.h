#ifndef RR_RECEIVER_RADIO_TEST_LOG_H
#define RR_RECEIVER_RADIO_TEST_LOG_H
#include "receiver_radio_test_bus.h"
/* E05D634 for seven verified RF-test firmware formats only.
 * args[0]=format, args[1]=promoted integer. Returns 0 only after the
 * actual initialized no-op sink semantics; result=formatted byte count.
 * 1=real changed-sink boundary (arg0 character valid; stream is stack-local
 * and omitted from projection), -2=unsupported format/invalid memory/sink.
 * No UART behavior, callback return, or CR/LF translation is fabricated. */
int rr_receiver_radio_test_log(rr_rt_bus *b,const uint32_t args[5],
    uint32_t *result,rr_rt_pending *pending);
#endif
