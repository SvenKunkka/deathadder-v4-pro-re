# Mouse 1.20 initialization map

Firmware: `Suit2FWData__radio_radio.bin`, SHA-256 `c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48`. ROM base E06C000; RAM executable bytes use file offset `address-23020000+79C` (code span C6B0). This report checks retained original instructions against image bytes. It does not claim runtime or RF validation. Only this Markdown and its JSON companion were written; the JSON contains raw byte spans, store PCs, and hashes of the sources reviewed.

## Resolved call tree and boundaries

`259A4 -> 22E28 -> {225CC -> memset x3 -> 21528(0), 21800, 217DC, 217A0, 218EC, 21C6C(0,rate), IRQ veneers}`. After 22E28 returns, 259A4 installs the key using 20E24, then updates application metadata. Both 217DC and 217A0 are literal `7047` (BX LR), not clock-start functions. Fullinit has no CPU callback, scheduling operation or hardware polling on its ordinary nonaliasing path. Its MMIO task writes do not establish that hardware has finished transitioning.

Standalone 218EC consumes only identity at input+4 (word) and PHY at input+20h (byte). **Fullinit fixes PHY to 4**: 22E84 writes identity at local SP+8; 22E86 sets r3=4; 22E88 sets r0=SP+4; 22E8C writes word4 at SP+24h. Thus radioinit's byte input+20h is exactly initialized4. Other local descriptor bytes are uninitialized but not consumed. Fullinit's frame is64 bytes, wrapper's40, radioinit's40; the nested maximum on this ordinary route is144 bytes. The receiver's residual-PHY behavior must not be transferred to this mouse routine.

## Parameters and wrapper stores

The direct fullinit descriptor reads word identity at+0, word capability at+4 (stores only its low16), halfwords A at+8, B at+A, and unsigned halfword rate at+C: at least14 readable bytes. 259A4 constructs it on its stack with identity=r0, capability=7, A=low16(r1), B=low16(r2), rate=low16(r3). It does not sign-extend rate; the LDRH at22E92 supplies unsigned0..65535.

Fullinit writes word27AC=identity, halfword279C=capability, word27B4=~identity. At22E76 it writes an **unaligned word at297E** with value `swap16(A) | swap16(B)<<16`. In memory the four bytes are `[A_hi,A_lo,B_hi,B_lo]`. It is not a REV32 of the pair and not two aligned words.

Wrapper postlude: 20E24 receives low16(original identity), selects `identity&15` and copies16 bytes from `E098904+16*selector` into2600..260F. Then halfword6B72=low16(r1), halfword6B74=low16(r2), **word6B68=0**, byte6B77=1. Surrounding metadata is preserved. Direct22E28 and218EC do not install a key.

## Reset and queue initialization

225CC calls thunk2C560 -> E0973EA, a bytewise memset loop, in this exact order:

| Start | Size | Exclusive end |
|---|---|---|
| 23002978 | EE0 | 23003858 |
| 23002794 | 1E4 | 23002978 |
| 23002688 | 10C | 23002794 |

The union is [2688,3858), exactly one peer's state. Bytes2687 and3858 are not reset. Word stores of FFFFFFFF at2A3A,2A3E,2A42,2A46 fill16 bytes through2A49. Tailcall21528(0) then sets queue metadata.

For 21528(index), add `index*EE0` to every destination and pointer value below. The original helper has no index bounds; the portable index0..31 domain keeps these metadata writes within128KiB and is not a supported-peer-count claim.

| Destination offset | Width | Value |
|---|---:|---|
| 2ADC,2AE0 | 4,2 | zero |
| 2AD6,2ADA | 4,2 | zero |
| 2AE6 | 4 | 10106020 |
| 2AE2 | 4 | 20100520 |
| 2AEA | 4 | 10101010 |
| 2AF0,2AF4,2AF8,2AFC,2B00,2B04 | 4 each | 23002B08,23002D08,23002D58,23002E58,23003058,23003258 |

The two zero groups form exactly12 bytes[2AD6,2AE2), with no gap. Bytes2AEE..2AEF are not touched by standalone21528 (but full reset already zeroed them). The helper installs pointers and metadata, not queue payload clearing beyond the separately documented reset.

## DPPI, radio and preserved fields

21800 is **unconditional**; there is no CHEN test. It writes byte76F5=0,76F4=1,76F3=2,76F2=3,76F1=4,76F0=5,76EF=6. TIMER base53028000 +1C0+4*i gets80000000|i for i0..5. RADIO5302C30C=80000006; DPPI53022504=7F. It leaves76EE unchanged.

218EC's radio word stores, in program order, are listed below (base5302C000). Detailed PCs and RAM store widths are in JSON.

| Offset | Value |
|---|---|
| 10,704,E3C | 1 each |
| E40 | A |
| E34,E38 | C3C2C1E7,C7C6C5C4 |
| E2C,E30 | EB8A542C,identity |
| 500,710 | supplied PHY byte,18 |
| E20,E28 | 01000005,0303001F |
| E44,E48,E4C | 102,11021,FFFF |
| 400 SHORTS | previous value OR80001 |
| 488 INTENSET | **108** |
| 20C,200,218,220 | zero each |

Packet-format RAM: half261B=0101; word2610=0; word2614=0; half2618=0; byte261A=3; byte2610=5; byte2618=1F; byte2615=1. Then byte2625=1,byte262C=1,half2620=5,byte2622=0,word2628=0102001F. Preserve261D..261F,2623..2624,2626..2627 and other unspecified bytes; no blanket clearing of this region is justified.

The decompiler names the zeroed +200/+20C/+218/+220 registers as events, but the decisive evidence is these exact offsets; do not substitute conventional +100-series offsets based on names. TASKS_DISABLE is written once with no DISABLED-event polling.

## Rate and clock-flag domain

21C6C guard is unsigned `(rate-1)<=63`, accepting all integer rates1..64. Full reset set half2794=0, so the direct path always stores half29AC=rate. It never takes the connected-peer queue path during fullinit.

- Rate1 and old76EE=0: word5302E040=1, then byte76EE=1. Existing nonzero76EE is preserved (including values other than1), with no clock write.
- Rate2..64 and old76EE!=0: word5302E044=1, then byte76EE=0. Old zero causes no clock write.
- Invalid rate: no rate or clock/76EE writes;29AC remains the zero from reset.

Standalone21C6C has a separate connected case: half2794>2 and current peer rate nonzero -> send `[2F,rate,BE16(half2A0A+100)]` through215AC(peer,0,body,4,FF), then store requested rate at peer+36 and targettick atpeer+38. Its queue semantics are not needed for fullinit equivalence.

## TIMER and exact IRQ veneers

After radio and rate: disableIRQ40, TIMER+4=1,+C=1,+510=5,+504=old&~3,+508=(old&~3)|2, zero all eight words+540..55C, and write+308=FF0000. TIMER COMPARE events+140..15C and unrelated bits/registers are preserved.

2C6A0 -> E089E48 sign-extends IRQ number to16 bits; nonnegative numbers write a one-bit ICER mask at E000E180+4*(irq>>5), followed by DSB/ISB. 2C670 -> E089E2C writes the matching ISER mask at E000E100+4*(irq>>5). 2C590 -> E089E70 ignores r2 and writes byte `((priority+1)<<5)&FF` at E000E400+irq. Its negative IRQ path writes E000ED14+(irq&15), unused here.

| IRQ | Veneer priority byte | Caller's subsequent overwrite | ICPR / ISER mask |
|---|---:|---:|---|
| 44 radio | 40 | 00 | word index1:1000 |
| 40 timer | 40 | 20 | word index1:100 |
| 92 | 60 | 40 | word index2:10000000 |
| 91 | 60 | 40 | word index2:08000000 |

Radio disable writes ICER1=1000; later timer disable writes ICER1=100. In inert word-backed snapshots, final ICER1/ICPR1/ISER1=100, final ICPR2/ISER2=08000000. Real NVIC set/clear semantics apply both masks cumulatively; the snapshot's last written mask is not a claim onlyIRQ91 is enabled. Instruction-sequence fidelity must include transient priority writes; final-memory fidelity may omit the overwritten intermediate values.

## Portable review and fixtures

Read-only review of new `mouse_initialization.c/.h` found no concrete mismatch in its explicit final-memory-effects domain: queue zero span/constants/pointers,297E packing, width of all initialized fields,PHY4,rate conditional flag preservation and finalIRQ snapshots agree. The rate1 path now writes clock+40h=1 before76EE=1, matching raw21D0C/21D0E. Intermediate IRQ veneer writes remain outside the final-memory-effects scope stated in the header. No C files were edited or executed for this review.

Use descriptor23010000 with at least40 allocated bytes and example stackSP2301F000 with at least100h backed below it. These avoid all documented reset/global windows and the nested144-byte stack use. Directradio needs33 bytes; fullinit needs14. Pattern oldRAM/SHORTS/MODE/BITMODE/76EE and sentinel bytes2687/3858. Distinct A/B high and low bytes expose packing errors; wrapper parameters with different high16 bits verify truncation. Values rate0,1,2,64,65,FFFF and76EE0,1,FF exercise the important branches.

Input pointers that overlap reset RAM, code, output globals or active stack can change original read-after-write behavior. They are excluded from the scalar-parameter portable model. The physical meaning of A/B and the unnamed5302E000 clock block remains a semantic naming question; the exact byte and register effects are resolved.

## Next high-value upstream path

Retained instructions show `23026A00` mode switching -> **2302869C(1)** -> **23021150(identity,rate)** ->259A4. At286B8, identity comes from unaligned word49AC+1F=49CB;286BE reverses it;286BC loads byte4A5C+3=4A5F. At2115C..21164 the wrapper arguments are exactly `(identity,0xBF,0,rate)`. On return2116C sets byte7799=1.

21150 has a real first-use split. If779A==0 it calls25D1C, sets779A=1, calls thunk2C5F8 -> **E096164(271h,0)**, then enters259A4.25D1C calls22D68, creates the thread at1BB8 with stack109E0,size400,entry25D91, initializes callbacks67C0->25DF1,67B0->25EB1,67A0->25E39, then callsE079DC4.22D68 initializes3858 with callback22621 and sets76F8=1. E096164's finite path callsE0960A8, which updates timeout/current-thread state and calls **E089D4C at E09610C** for the CPU switch. These are real upstream continuation points, not no-ops or part of22E28.

Configuration provenance: E07D23C callsE07DE2C(index0,keyA001,destination49AC,length29h) atE07D27C. Identity is record offset1F; all-zero/all-FF fallback uses deviceID0FFFE010 bytes in big-endian order. Rate is loaded through E07D23C ->2678C(0)->**26800**, which copies44 bytes from `44CE+F4*U8[4477]` to4A5C; rate is source+3. The profile storage group isA003 at4474,length4E4, with CRC/default fallback. The broad storage validation/backend and all callbacks are not claimed implemented by this static addendum.

Recommended next bounded work: model21150's already-created-infrastructure branch first, then25D1C's thread/callback setup and sleep continuation, and connect2869C to actual profile/identity inputs. This advances the wireless startup chain; LED and upgrade handlers are unrelated to the remaining initialization gap.
