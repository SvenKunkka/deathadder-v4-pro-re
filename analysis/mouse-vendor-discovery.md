# Mouse 1.20 vendor command dispatcher discovery

## Evidence and status

Static analysis of official `Suit2FWData__radio_radio.bin`, SHA-256 `c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48`. Flash base `0E06C000`; copied executable RAM base `23020000`, file offset `79C`. Existing retained Ghidra mouse120 project reused read-only, original input bytes checked against loaded image. Newly exported missing test-worker entry `E07A338` and related 14 functions under `mouse-vendor-discovery-export/`; log confirms `MOUSE_VENDOR_EXPANDED=15` and discarded project changes. No device actions, no C implementation, no differential execution or hardware verification in this subtask.

`mouse-vendor-discovery.json` contains complete raw dispatch tables (11 tables / 532 entries), selector maps and exact firmware digest. `mouse-vendor-discovery-disassembly.txt` contains retained instruction evidence. Export script `../ghidra-scripts/ExpandMouseVendorDiscovery.java` binds the firmware digest before export. Decompilation is supporting evidence; code addresses, literal bytes, branch tables and stores are the primary basis.

## Complete top-level path

1. Business consumer `23025E38` completes class5 envelope with `5A` prefix, zeros 90 bytes at `23003EFC`, copies payload into that mailbox, stores envelope checksum at mailbox+58, sets bytes `23007715=1` and `23007797=1`. This is the already reconstructed mouse consumer, not new work here.
2. Main application loop `2302AE14` calls thunk `2302C448`, which branches to **`0E07D170`**, the actual vendor dispatcher. USB callback `2302C0F8` independently fills the same 90-byte mailbox, sets status1 and pending7715; USB read callback `2302BD14` copies it back. Source may therefore be USB or radio.
3. D170 returns immediately if7715==0. Otherwise XOR mailbox bytes2..87 and compare byte88. Bad checksum writes status3, clears7715; it does not recompute the bad checksum. Good checksum sets status1, dispatches by byte6 to class handler, recomputes XOR2..87 into byte88, changes status1→2 while preserving other statuses, then clears7715.
4. When mode byte7723==1, dispatcher tailcalls veneer E097538→**230211DC**. This function requires7797!=0 and7715==0, builds response `[5A,mailbox88,mailbox-prefix]` at23003E98, sends via **23025AB0(peer0,class5,buffer,length,FF)**, then clears7797. It scans trailing zero bytes from mailbox87 back through8, with minimum mailbox copy8 / envelope length10; highest nonzero index j>=8 gives copy j+1 and envelope length j+3. The business TX function performs its existing framing/checksum logic. Sending a queued response is not itself proof of over-air delivery.

Mailbox fields: +0 status; +1 transport/target byte (not interpreted by this dispatcher); +5 payload length; +6 class; +7 operation; +8 payload; +88 XOR; +89 not inspected. No target routing exists in D170 comparable to receiver target routing. Every class and out-of-range/default path is accounted for below; per-payload validity remains separate.

## Class and operation map

Hex selectors listed below are explicitly handled; other selectors go to each handler's default status path. Some recognized selectors have additional payload guards. Lists use outer operation selectors only, excluding nested-switch case numbers.

| Class | Handler | Explicit operation selectors |
|---|---|---|
| 00 | `0e07ae74` | 02, 04, 05, 06, 0B, 0D, 0E, 17, 24, 33, 40, 81, 82, 83, 84, 85, 86, 87, 8D, 8E, 97, A4, B3, C0 |
| 02 | `0e07b5e4` | 02, 0C, 18, 82, 84, 8C, 8E, 98 |
| 04 | `0e07b948` | 00, 02, 03, 04, 05, 06, 80, 82, 83, 84, 85, 86 |
| 05 | `0e07c98c` | 80, 81, 8A |
| 07 | `0e07c9e0` | 01, 02, 03, 0D, 11, 80, 81, 82, 83, 84, 85, 8D |
| 0B | `0e07c33c` | 03, 05, 0B, 10, 11, 12, 13, 14, 15, 80, 83, 85, 8B, 8E, 90, 91, 92, 93, 94, 95 |
| 10 | `0e07daec` | 01, 02, 04, 05, 80, 83 |
| FE | `0e07cc50` | 31, 32, 33, 35, 36, 37, 70, 71, 73, 7E, A9, B1, B6, C2, F1, F3, FE |

Class00 default status5. Class02 default5, with 8E payload profile0 producing3. Class04 default3. Class05 unknown3. Class07 default5. Class0B unknown3. Class10 unknown5. ClassFE unknown3. Unknown class D170 sets5. Generic successful handlers generally preserve status1 until D170 converts it to2.

Table locations (instruction address, bias/count, entry encoding): D1A4 class0/17 TBB; AE86 op2/191 TBH; B5FC op82/23 TBB; B966 op80/7 TBH and B97C op0/7 TBH; C34A op3/147 TBH; C9FC op80/14 TBB; CA20 op1/17 absolute Thumb pointers atCA24; CC66 op31/78 TBH; CD14 opA9/26 TBB; DB04 op1/5 TBH. Raw values and decoded targets retained in JSON. For TBB/TBH, target is instruction+4 + 2*unsigned table value. Remaining op branches are direct comparisons visible in the retained instruction slice.

## Radio-changing commands and actionable callees

### Class00 operations17/24: radio address / identity

Payload first4 bytes copied as little-endian word into230049CB. Invalid/sentinel identities invoke device-ID-derived fallback (the precise arithmetic condition is retained at handler AE74 and requires original emulation before simplification). Marks dirty kind4 viaE07D4AC. If peer identities at497B/497F equal byte sequence66778899, update them from original packet payload; mark dirtykind2, clear halfword768E, and call E07D590. Finally byte-swap the stored49CB and call **23025C48→23021C40**.

Raw 23021C40 stores radio-order identity to RAM27AC, writes **RADIO5302CE30 (BASE1)**, and stores its complement to27B4. Thus this command directly changes a RADIO address register, beyond a configuration-only marker. Reads97/A4 return49CB,497B,497F,497A. No pairing-success claim follows from these writes alone.

### Class00 operation40: rate/timing change and link notification

Payload0 is profile selector; payload1 is requested rate code. In radio mode7723==1, permitted only if7771!=0 or rate>=8; otherwise handler setsstatus5. Profile0 updates pending rate7781; nonzero profile writes profile table byte44D1+(profile-1)*F4 and dirtykind8, updating7781 only for active profile4476. Then call **23026CE0(1,7781)** and **230212D8(current4A5F)**.

23026CE0 mode1 change writes SPIM stop-like task registers5F9C2004 and5F9C200C=1, stores4A5F, invokes2302B934,2302B4E8,23026BD0 and clears timing/aggregation fields7786,76DE,7787,7785,7792,76DC. Mode4 path uses4A5D,5F9A2004/0C and BB64/BB98; command40 mode4 is gated by779E and stores profile44CF.

**230212D8→23025C70→23021C6C** applies rate1..64. If link state2794<3 or29AC==0, write29AC and toggle5302E040/044 when entering/leaving rate1 (flag76EE). Otherwise construct control payload `[2F,rate,BE16(2A0A+100)]`, enqueue through230215AC(peer0,class0,...), write pendingrate29AE and activationtime29B0. 230212D8 also calls23021278, which sends B1 status reply class3 via23025AB0 and calls25C70 again. Preserve this ordering; do not collapse repeated calls blindly. C0 reads current/profile rate values. Rate code is not unconditionally a physical Hz value.

Class00 operations05/0E change profile timing bytes4A5E (mode1) or4A5C (other mode), corresponding profile44D0/44CE, mark dirtykind8 and clear aggregation via23028044. They do not directly call the radio rate helper above. These controls should be included in complete host configuration recovery but not conflated with command40.

### ClassFE operation70: ten-byte RF test A

**2302111C(payload)** initializes test subsystem once when779A==0 through23025D1C, sets779A=1, waits via E096164(625,0), then **23025C50→E07A0C8(payload)→E07A338()**.

E07A0C8 copies payload0..9 to770D,770C,...,7704. If payload0==0 clears770F; when76F9!=0 call23022BA8 (resume/stop-related wrapper) thenE07ADF4 and clear76F9. Nonzero payload0, when770F==0 and76F9==0, calls23022B80 thenE07AD70(23003868), sets76F9=1. Finally sets770F=1,770E=1.

Newly exported **E07A338**: if770F==1 &&770E==1, clear770E, initialize via22B80/AD70 if76F9==0, then call **E079DD8(1,0)**. Then evaluate B-test pending pair below. This worker mirrors receiver test-control structure but addresses and bytes come from mouse binary, not assumed reuse.

### ClassFE operation71: fourteen-byte RF test B

**2302118C(payload)** initializes subsystem if needed, invokes230212F4 when7798==0, then calls **E07A1B0(payload)** and **E07A338**. E07A1B0 handles previous mode7703/770F/76F9 transitions with23022BA8,E07ADF4,23022B80,E07AD70. Stores payload0..5 to7701,7700,76FF,76FE,76FD,76FC; BE16 payload6/8/10/12 to768A,7688,7686,7684; flags7703=1 and7702=1.

E07A338 sees7703==1 &&7702==1, clears7702 and halfword counters7688/7686/7684, then calls **E079CAC()**. E07A298 (FE:F1) reads the same 14-byte state, including four big-endian halfwords. These control entries are precise next targets for original-instruction recovery; actual test RF engine execution has not been established here.

23025D1C dependencies:23022D68; thread-createE0957A8(TCB1BB8,stack109E0,size400,entry23025D91,...priority10); work initE0952A0 at67C0→23025DF1,67B0→23025EB1,67A0→23025E39; E079DC4. Neither creation success nor live worker execution is inferred from static registration.

### ClassFE operation7E: forced channel/control override

Payload0,1→**230212E8→23025C78→23021D24**. Wrapper pins leading selector arguments to zero, yielding RAM29FC=0;29FD=(payload0!=0). If payload0==0 set word2A00=24. If payload0!=0 and payload1<=31 set2A00=payload1; for payload1>31 return with29FC/FD already updated and2A00 preserved. Do not roll back flags or silently clamp invalid channel. Address23021D24 is the real shared body; decompiler inlines it under wrappers. The exact MHz/channel interpretation requires examining subsequent users of2A00 and is not assumed here.

## Other classes and boundaries

Class02 maps/buttons; class04 profiles/DPI tables, including profile load touching timing block4A5C; class05 profile availability; class07 power/status and sensor configuration; class0B sensor/motion settings. These classifications summarize data references, not claimed public protocol names. Their outer dispatch domains are complete in JSON; semantics are not all restored.

Class10 is firmware-update transport with open/write/close/commit/read operations1,2,4,5,80,83. Handler E07DAEC has flash dependenciesE088910/996/960/964 and rebootE085ED0. During open, mode4 high-speed state may temporarily change via23026CE0(4,8) and restore on close; this is an update side effect, not a radio packet opcode. Nothing was executed against the mouse.

ClassFE includes test/debug, sensor register writes and resets. Operation73 stores24 bytes at4994..49A8 and marks dirty+commit; F3 reads them. Existing E07D4AC only marks dirty flags7726 and age768E; it does not itself prove persistent Flash write. Profile reset, mode changes and firmware commit reach real reset/update boundaries and must remain explicit during emulation.

## Recommended next reconstruction units

1. D170 wrapper and230211DC reply serializer with exhaustive class/op coverage and bounded payload fixtures, preserving90-byte mailbox checksum and status behavior.
2. Class00 identity17/24 and rate40, extending the existing control/rate modules with real register and enqueue behavior; test primary current-profile and other-profile paths separately.
3. Mouse test A/B wrappers E07A0C8,E07A1B0,E07A298,E07A338, then E079DD8,E079CAC,E07AD70,E07ADF4. Do not reuse receiver memory offsets.
4. Complete remaining class handlers and persistence/update edges. A finite selector inventory does not make all payload/profile inputs valid; button search and profile indexing need explicit domains and preserved original boundary behavior.
