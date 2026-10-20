# Receiver 1.20 vendor identity message ABI

This is a static, original-instruction and raw-byte study. The receiver image SHA-256 is `f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162`. RAM executable bytes map to file offset `address - 0x23020000 + 0x79c`; initialized RAM maps to file offset `RAM offset + 0x1c854`. No C, manifests, retained projects, or device state were changed. The companion JSON records current source hashes and raw evidence bytes.

## Exact stack coordinates

Let **S be the SP on entry to the selected function**, before its prologue. Inclusive ranges below are bytes. Both event 8 and event 9 have the same layout.

| Selected entry | SP at class-0 handler 2617C | SP at producer | 36-byte message | 28-byte tail |
|---|---:|---:|---:|---:|
| 230252A4 / 23025300 directly | — | S | S-44 .. S-9 | S-36 .. S-9 |
| 2302604C | S | S-16 | S-60 .. S-25 | S-52 .. S-25 |
| 23026090 | S-24 | S-40 | S-84 .. S-49 | S-76 .. S-49 |
| 230205F8 | S-32 | S-48 | S-92 .. S-57 | S-84 .. S-57 |
| E06D19C first nonempty iteration, callback 230205F9 | S-96 | S-112 | S-156 .. S-121 | S-148 .. S-121 |

For producer-entry SP=P, `252A6/25302 PUSH {r4,lr}` consumes 8 bytes; `252A8/25304 SUB sp,#0x28` consumes 40. `STRD r3,r0,[sp,#4]` initializes only message bytes 0..7: LE32 event followed by LE32 value. `ADD r1,sp,#4` selects the 36-byte object. Its remaining bytes are P-36..P-9. The saved r4 at P-8..P-5 and saved LR at P-4..P-1 are **outside** the message. Do not append the saved registers to the tail or substitute a zero-initialized buffer.

Raw producer prefixes are `082310b58ab0cde90130074c02e0` (252A4) and `092310b58ab0cde90130074c02e0` (25300). The difference is the event constant, not a frame-size difference.

## Prior-write and saved-register ledger

All these pushes write increasing register numbers to increasing addresses. An allocated local slot without a store is not initialized. Each row uses its own function's entry SP; translate it through the table above. The tail lies below every frame/saved-register write listed here.

| Function | Actual stack writes before producer | Effect on eventual tail |
|---|---|---|
| E06D19C | PUSH r4,r5,r6,r7,r8,r9,r10,r11,lr: S-36..S-1; SUB sp,#28; STR at current SP+20 = S-44..S-41 with queue+0xA0 | None on immediate nonempty first iteration |
| 230205F8 | PUSH r3,lr: entrySP-8..entrySP-1 | None |
| 23026090 | PUSH r4,r5,r6,r7,r8,lr: entrySP-24..entrySP-1 | None |
| 2302604C | No push, sub-SP or stack store; dispatches by tail branch | None |
| 2302617C | PUSH r4,r5,r6,lr: entrySP-16..entrySP-1 | None |
| 23026F30, called twice for event 8 | No frame; writes only dirty-state RAM, then BX LR | None |
| 23026F68, called once for event 9 | BX LR (`7047`) | None |
| 23020674 / 2302067C | B.W to producer; no frame | None |
| Producer | PUSH r4,lr then STRD event,value; no stores to its 28-byte tail | None |

Consequently **all 28 tail bytes preserve the initial selected-entry stack bytes in the bounded first-call domain**. This follows from the full prior call path, not merely the producer decompile. Leaf dirty helpers set dirty bits and reset the dirty timer halfword; they do not create a temporary frame. The packet-value fallback reads the device ID and writes configuration RAM but adds no calls or stack stores.

For E06D19C's immediate callback specifically: worker SP becomes S-64. The instruction at E06D204 is BLX r1, passing r0=work; for handler pointer 230205F9 this reaches 230205F8 with SP=S-64 and LR=E06D207. Callback PUSH r3,lr writes S-72..S-65. The router then saves r4=queue, r5=0x40, r6=23002BC8, r7=work, r8=FFFFFFFF and LR=230205FF at S-96..S-73. Class-0 saves router r4=23002D1D, r5=230071BB, r6=23002D1C, LR=230260DB at S-112..S-97. Producer saves class r4=23002D1C and LR=230262FF (event 8) or 2302656B (event 9) at S-120..S-113. The tail ends at S-121, one byte before those producer saves.

Worker `STRD r8,r9,[sp]` at E06D2A8 and `STR r3,[sp,#8]` at E06D2AC are only on the empty-queue sleep path, not on this immediate callback path. They write S-64..S-53, also outside this tail, but their callees can leave deeper residues. A prior sleep, scheduling path, prior callback, or a second loop iteration invalidates the claim that the deeper bytes still equal the original thread-entry snapshot. That broader domain requires its own provenance or a live pre-producer stack snapshot. Exceptions/preemption are likewise external stack writers unless their behavior is explicitly modeled.

## Route, value, and queue semantics

Class 0's TBB table at 2302605C begins with byte 0x11, targeting 2302607E and then 2617C. The op table word at 23026274 is 23026291 (op 0x15), and at 2302624C is 2302633B (op 0x0B).

- **00:15 event 8:** changed payload LE32 is written at 23002DCF and 23002D8B. Zero/all-ones take the existing device-ID fallback. Calls 26F30(4), 26F30(2); at 262F4 reloads 2DCF, REV at 262F8, BL 20674 at 262FA. Producer value is byte-reversed stored value. On return 262FE branches to 26212, which sets packet status 2.
- **00:0B, payload byte 1, event 9:** BL 26F68 at 2655A; loads current word 2D8B at 26560, REV at 26564, BL 2067C at 26566. Return 2656A goes straight to 26216 (return 1), **without assigning packet status 2** on this branch. Preserve that status behavior.

Both producers use queue 23001BB4. Initialized metadata has message_size=36, capacity=10, ring=[230155F8,23015760). The put thunk 23027108 resolves through literal 2302710C to E06CBDD, canonical entry E06CBDC. Producer r2/r3 are both zero: no-wait timeout. On nonzero return, it calls purge thunk 230271A0 -> E06CD54 and loops back to put until success.

E06CBDC copies exactly queue+8 bytes from the message pointer, either to a waiting reader's destination (`E06CC2C -> E06F35C`) or the ring write cursor (`E06CC50 -> E06F35C`). It does not initialize or write its source buffer. Its own push and local allocation are below producer local SP=P-48 (saved registers P-72..P-49); these do not overlap the source tail. Full-queue purge similarly pushes below P-48. The unchanged-tail claim assumes valid nonoverlapping queue/waiter destinations and ordinary downward-growing ABI stacks; corrupt queue metadata can invalidate it.

A queue handoff can reach E0611CC context switching. A successful enqueue or wakeup is not proof the consumer has executed yet. Preserve continuation at that boundary rather than restarting the vendor command or publishing twice. After callback 205F8 finishes it restores its 8-byte frame and tailcalls 230271D0 -> E05C774.

## Actual consumer and radio/key effects

Configuration thread entry **23024E38** pushes 24 and allocates 56 bytes. It dequeues 36 bytes from 23001BB4 at SP+0x14 (`consumer initial SP-60`), using thunk 230271E8 -> E06CC94. Event and value live at SP+0x14 and SP+0x18. Table slots are original words 23024E80=23024F29 (event 8) and 23024E84=23024F1F (event 9). Events 8/9 do not consume message bytes 8..35, although the queue still copies them.

**Event 8:** 24F28 sets r0=0, loads value into r1 and calls 20FCC at 24F2C. The writes are word RADIO **BASE1** at **5302CE30** (20FD6), word 23003244=value (20FDA), word 2300324C=~value (20FDC). Its tailcall 215B4 writes halfword 230030E6=`value XOR (value>>16)` truncated to 16 bits (215BA). Then 24F30 loads the value's low halfword and calls **20108**: select `value & 15`, copy exactly 16 bytes from **E06FA74+16*index** to **23003020..2300302F**. The raw 20108 LDM/STM writes four words. The selector is the numeric producer value, already byte-reversed from packet storage.

**Event 9:** 24F1E sets r0=0, loads value and calls **21094**, which writes only word **23003240=value** (21096). It does not immediately alter RADIO or the installed key. Later **226C8(peer)**, when unsigned state at `230033E8+peer*0xF84` is <=1, loads 3240 at **227B4** and writes **5302CE30** at **227B6**. This is the scan/pairing BASE1 selection; state>=2 instead selects 3244. Timer mode-2 entry **23022ED4** calls 226C8 at 23023066, 2302309E and 23023196 according to its slot. Those hardware/slot preconditions must occur; enqueue alone does not demonstrate them.

Existing portable chain: `rr_receiver_config_value_publish` -> queue API; `rr_receiver_config_iteration` -> `rr_receiver_config_control` -> `rr_receiver_config_event`; event 8 uses `rr_business_install_key`, event 9 only stores 3240. The later event-9 hardware selection is `rr_receiver_legacy_timer` mode 2, helper `subscribe2`. No new cryptographic derivation is needed: this firmware selects one of the existing 16-byte ROM records.

## Remaining boundaries

The bounded ABI offsets are resolved statically. Parent original-byte emulation should check patterned initial stack bytes for all four entry routes, both events, zero/FFFFFFFF device-ID fallback, unchanged-identity no-publish, full queue purge/retry and waiting-reader handoff. Broader arbitrary work iterations, asynchronous interrupts, stack-aliasing queue structures, context-switch continuation and non-36 queue sizes are separate domains. This report is not an execution-equivalence or real-device RF claim.
