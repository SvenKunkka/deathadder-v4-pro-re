#ifndef RR_MOUSE_INITIALIZATION_H
#define RR_MOUSE_INITIALIZATION_H
#include <stdint.h>
/* Official mouse radio firmware1.20. RAM128KiB at23000000; each remaining
 * window is4KiB: RADIO5302C000, TIMER53028000, NVIC E000E000,
 * DPPI53022000, clock5302E000. Inert snapshots, not live hardware pointers.
 * 0=software function returned; negative=invalid modeled input.
 * Final memory effects are reproduced, not peripheral timing/write traces. */
typedef struct{uint8_t *ram,*radio,*timer,*nvic,*dppi,*clock;} rr_mouse_init_hw;
/* 21528 initializes metadata only. Index0..31 is a bounded address domain;
 * it does not assert support for that many connected peers. */
int rr_mouse_radio_queue_initialize(uint8_t *ram,uint32_t index);
int rr_mouse_radio_reset(uint8_t *ram);
int rr_mouse_radio_dppi(rr_mouse_init_hw*);
int rr_mouse_radio_initialize(rr_mouse_init_hw*,uint32_t identity,uint8_t phy);
/* 22E28 takes the corresponding14-byte original config fields. Capability
 * and last three fields are truncated to16bits. Full init fixes PHY to4,
 * resets one peer and applies rate only when low16bits are1..64. */
int rr_mouse_initialize(rr_mouse_init_hw*,uint32_t identity,uint32_t capability,
                        uint32_t field_a,uint32_t field_b,uint32_t rate);
/* 259A4: full config(capability7), then actual key installation and metadata.
 * table is the matching official256B key table; no key derivation invented. */
int rr_mouse_application_initialize(rr_mouse_init_hw*,uint32_t identity,
                                    uint32_t field_a,uint32_t field_b,uint32_t rate,
                                    const uint8_t key_table[256]);
#endif
