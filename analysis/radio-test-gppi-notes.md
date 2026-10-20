# Receiver 1.20 radio-test GPPI: exact static evidence

This worker read original Thumb instructions, literal words and initialized data from `Suit1FWData__radio_radio.bin`, SHA-256 `f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162`. Firmware base is `0E054000`; initialized RAM comes from file offset `1C854`. No hardware was touched. No native C reconstruction or differential execution is claimed here. Full original-byte region extracts, descriptor words and initialization values are retained in `radio-test-gppi-notes.json`; bounded instructions in `radio-test-gppi-disassembly.txt`. Decompiler output was cross-checked against these instructions, not accepted as original source.

## Critical behavior for the actual RF test engine

Endpoints `53025100` (EGU event0), `53029000` (timer start), `53029140/144` (timer compare0/1), and `5302C000/004` (RADIO TXEN/RXEN) all map to descriptor `0E0707A4`. This is established from caller literals at `E05C88C..C89C`, `E05CBA4..CBB4`, the original resolver `E06AB80`, and the ROM descriptor table. Thus actual RF test use follows the same-descriptor allocation path; it does not require cross-domain bridging.

Descriptor `0E0707A4` contains six words: hardware base `53022000`, free-bitmap pointer `23000AFC`, source mask `3`, destination mask `C`, bridge base `53023000`, match granule `10000`. Initial free bitmap is `F`. Same-descriptor allocation selects the **highest** free bit from `bitmap & (3|C)`, so channels initially allocate 3,2,1,0. The logical handle allocator is independent: bitmap `23000AF8` initially `FFFFFFFF`, allocating handles 31,30,...,0.

Most significant non-obvious behavior: `E06AACC` always reads handle slot byte **+8**, even for domain 3 whose channel is at **+9**. After reset then RF linking, +8 remains `FF`, so AACC returns zero immediately. It must not be replaced by a more intuitive +9 lookup. Likewise SET/CLR writes are actual writes to `53022504/508`, not software writes to `53022500`. A stable MMIO model must preserve this distinction; real hardware side effects need separate modeling and evidence.

## Shared layout and primitives

Handle slot `s = 23006E58 + 12*h`, with original allocator's valid handles 0..31:

| Offset | Meaning |
|---|---|
| +0 | source domain descriptor pointer (u32) |
| +4 | destination domain descriptor pointer (u32) |
| +8 | domain F channel (u8) |
| +9 | other/domain3 channel (u8) |
| +A | domain F bridge channel (u8) |
| +B | other/domain3 bridge channel (u8) |

Reset writes words +0,+4,+8=0, then halfword +8=FFFF, then byte +A=FF. Result is `00000000 00000000 FFFFFF00`, not four FF bytes at the end.

`E06AB70(d)` returns `(u8[d+3] & 15)`, the top nibble of the descriptor's base address. `E06AB78()` returns `0E070744`; it performs no writes. `E06A0D4(a,b)` returns true exactly when `(domain(a)==15 || domain(b)==15) && a!=0E070744 && b!=0E070744 && a!=b`.

`E06AB80(endpoint)` selects four descriptors starting `0E070744` if bits24..27 of endpoint are F, otherwise the single descriptor at `0E0707A4`. For each descriptor d, compare `((d[0] & -d[5]) >>16)&FF` to `((endpoint & -d[5])>>16)&FF`; first match wins, otherwise return zero. This is intentionally not full address-range validation.

Endpoint publication/subscription register offset is `100` if unsigned32 `(endpoint - 5302C000) <= 1064`, else `80`.

`E068A5C(bitmap, outByte)` atomically removes highest set bit, writes its index to outByte, returns BAD0000. Zero bitmap returns BAD0002 without output write. `E068A9C(bitmap, channel)` atomically sets the bit if clear, returning BAD0000; already-set returns BAD0004. Original ARM shifts use low8 count and yield zero for counts >=32, unlike undefined C shifts. These functions use exclusive-access instructions; serialized reconstruction does not prove concurrency equivalence.

## Requested function semantics

### E06A658(outHandle)

Calls A5C on bitmap `23000AF8`. Failure returns unchanged error. On success resets corresponding slot as above, preserving BAD0000 in r0. Instruction anchors A660,A664,A682..A68E. Writable output pointer must be supplied; no original null guard.

### E06A760(h, sourceEndpoint, destinationEndpoint)

Resolve both endpoints; choose channel byte +8 for domain F, otherwise +9. For equal domains call A484(sourceDesc,destDesc,channelByte). Success saves descriptor pointers at slot+0/+4, writes `80000000|channel` to both endpoint publication/subscription registers. Failure calls A264(sourceDesc,destDesc,currentChannel), then resets slot regardless of cleanup return. This does not return a reliable logical success status: success path loads r0=1064 while calculating endpoint offsets (A868); original callers treat it as void.

For the RF same-descriptor case A484 consumes highest free bitmap channel and writes slot+9, with no other MMIO; A760 then writes source register then destination register. If bitmap has no channel, A484 returns BAD0002 without channel output modification. A760 still calls A264 using the prior byte, then resets slot; when prior byte is FF, A264 returns BAD0004 and makes no bitmap change.

Cross-domain general branch resolves bridge descriptors using ABF4; allocates source-to-sourceBridge channel, destinationBridge-to-destination channel, then bridge pair via A32C. Failure calls A264 twice and **calls A32C again**, then resets slot. This surprising second allocation call is present at A81E in original code; do not replace it with a guessed cleanup. Static notes do not claim this generic failure branch has been emulation-validated.

### E06A6A0(h, endpoint) and E06A708(h, endpoint)

A6A0 resolves endpoint and selects current slot channel byte by resolved domain. It writes `80000000|byte` at endpoint+offset. A708 writes zero there. Both compare the endpoint descriptor to existing source/destination; if neither matches and A0D4(existingSource,existingDestination) is true, they call AB78. That call simply returns a constant pointer and has no memory effects; it neither allocates nor substitutes a channel. A6A0 does not allocate a channel for the added endpoint.

### E06A8E0(h, sourceEndpoint, destinationEndpoint)

Resolve endpoints/select channel byte. Equal-domain path calls A264; on success reset slot, then clear source endpoint register and destination endpoint register (in this order). Error exits without these reset/endpoint writes. Same-descriptor A264 returns BAD0004 if channel==FF, otherwise frees bitmap bit via 68A9C. Already-free channel fails without resetting slot. The slot reset does not free logical handle bit in AF8.

Cross-domain: obtain bridge objects; slot+A or+B chosen per bridge domain. Reject FF; free first bridge bitmap then second; failure can leave the first bitmap already freed. Clear corresponding bits in bridge base+200, zero source bridge base+80+4*(channel&63) and destination bridge base+180+4*channel. Free source-to-bridge then bridge-to-destination via A264; only when both succeed reset slot and clear both endpoints. No rollback is added by original code.

### E06AACC(h)

Read slot+8. FF returns0 before descriptor dereference. Otherwise read bit at that index from source hardware base+500; if zero return0. Then same index from destination hardware base+500; if zero return0. If both set and A0D4(source,destination) true, return that bit from descriptor E070744 hardware base+500; otherwise return1. Uses ARM logical right shifts; byte index >=32 yields0. No writes.

### E06AB28(mask), E06AB4C(mask), E06A108(h, enable)

Zero mask returns immediately. Else repeatedly compute `ctz(mask)` via RBIT+CLZ, call A108(index,1) or A108(index,0), clear that lowest bit, continue. Handles are processed ascending.

A108 loads slot descriptor pointers, selects channel by each domain. Write source hardware base+(enable?504:508) with `1<<sourceChannel`, then destination equivalent with `1<<destinationChannel`. If A0D4 true, also write shared descriptor E070744 base+sameOffset with `1<<slot[8]`. If domains differ, resolve each bridge through ABF4 and AB80, then write corresponding bridge-domain hardware base+sameOffset with the already calculated source/destination masks. Same-descriptor RF paths therefore write the identical SET/CLR address twice. Original has no uninitialized-slot null guard.

## Allocation and freeing dependencies

`E06A484(a,b,outChannel)`: equal-descriptor path intersects bitmap with `source_mask|destination_mask`, consumes highest bit, writes output, BAD0000 or BAD0002. Different descriptor path enters BASEPRI 40 critical section, intersects source mask of a with destination mask of b and both free bitmaps; if A0D4 true also intersects shared domain mask8&maskC&free. Consumes matching highest bits on source, destination, and possibly shared descriptor. Domain3 different-descriptor success additionally programs a.bridge+80+4*(ch&63) and b.bridge+180+4*ch to `80000000|ch`. Source/domain failures have explicit release paths; the original output-byte state influences cleanup. See complete retained instructions for nonserialized atomic retry/rollback details before implementing that larger domain.

`E06A264(a,b,ch)`: same descriptor only frees bitmap (FF rejected); different descriptors free source then destination and optionally shared bitmap under BASEPRI critical section, stopping on error without general rollback. If a has domain3, also clears a.bridge+80+4*(ch&63), b.bridge+180+4*ch. No channel-enable register changes.

`E06A32C(bridgeA,bridgeB,slot)`: cross-domain bridge helper, requires one side's mapped descriptor domainF; consumes highest available source bridge bit using mask+8 and destination bridge bit using mask+C; stores bridge indexes in slot+A/B according to domain. Sets bridge base+200 corresponding bits and programs source publish +80+4*(channel&63), destination subscribe +180+4*channel to `80000000|associated slot channel`. Destination exhaustion frees source allocated bit. Domain mismatch returns BAD0004; exhaustion BAD0002.

ABF4 returns bridge object E0707CC for nonF descriptors. For supported F descriptors, returns E0707BC. Objects are `{base,freeBitmap,sourceMask,destMask}`: E0707BC = `{5F921000,23000B14,5,5}`; E0707CC = `{53024000,23000B10,FF,FF}`. ABF4 can return0 for an unsupported F descriptor not matching its special masked92 test or known descriptor bases.

## Validity and outstanding verification

Actual RF callers use one logical handle from A658, known endpoints, channel pool initialized at AFC. Preserve original ordering, failure side effects, and unusual AACC +8 behavior. Do not extrapolate semantics for null descriptor lookup, out-of-range logical handle, arbitrary endpoint aliases or race-modified allocator snapshots. No actual firmware run, RF capture, or device linkage was performed by this worker. Generic cross-domain paths have instruction evidence but still need original-instruction differential tests before a portable implementation can be claimed equivalent. Physical event routing and SET/CLR register effects remain hardware behavior, not established by static snapshots.

## Authored portable implementation delivered to main agent

`../recovered-code/portable/receiver_radio_test_gppi.c` and `.h` now implement the RF same-descriptor domain using the shared inert-snapshot bus. Entry API supports A658, A760, A8E0, A6A0, A708, AACC, A108, AB28, AB4C and the referenced small domain/allocator helpers. Generic allocation/free/toggle with distinct descriptors returns -2; no cross-domain success is manufactured. AACC and read-only descriptor lookup retain their explicit general behavior. Build validation: clang C11 with Wall/Wextra/Werror/pedantic/O2 syntax check passed. No original-instruction differential tests have yet been executed by this worker; main agent owns those checks and manifest integration. Result output is promised only for original nonvoid entries; residual r0 from original void functions is excluded.
