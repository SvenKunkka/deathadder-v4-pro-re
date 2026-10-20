# Receiver vendor dependencies: phase63 static map

Official receiver1.20 SHA-256 `f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162`. This map uses existing exports and original ROM/data bytes only. No headless task, C implementation, manifest edits, hardware action or dynamic equivalence test was performed. `receiver-vendor-dependency-map.json` records exact current source hashes and resolved device tables.

## Reuse priorities and continuation points

| Entry | Actual role | Existing implementation reusable | Missing work |
|---|---|---|---|
|23024DB4|Stats period update + AC class3 message + timer lifecycle|business_tx; receiver_config_control timer start/stop; application timer25640|Small wrapper and parent vendor continuation|
|23025954|Three-group fixed LED colors|None of current portable PWM modules (none found)|25CE0 conversion and real PWM driver chain|
|23025FE0|Three-group percentage-color lookup|Same LED dependency as above|Wrapper, ROM table, same PWM driver chain|
|E05BE8C|Firmware-update command class10|storage device-ready; mapped flash read/write; business TX for update-mode B1 messages|Partition adapters, update state machine, bootrequest/reset boundaries|

Vendor FE33/FE72 set packet status2 only **after** their real helper returns. Class00/op04 LED-clear path additionally clears71B2 after helper, then sets status2; mode71BD was already changed before entering helper. Outer23026090 must resume at checksum/forwarding/clear71BB stage rather than rerun local commands; work230205F8 subsequently calls test workerE05C774. Class10 handler writes its own packet status and has B1 tail actions; do not universally impose status2 on it. A nested CPU boundary is not a completed helper call.

## Stats helper23024DB4: precise reusable behavior

Argument from FE72 is zero-extended BE16 packet payload0..1. Original compares full incoming r0 with u16[659A]; same value returns with no changes. Changed value:

- Store low16(value) duplicated in word659A (sets659A and659C).
- **Clear659E with a halfword store; clear65B0 with a full word store**. Raw anchors23024DEC=`strh r5,[r4,#0xe]`;23024DEE=`str r5,[r4,#0x20]`, base r4=23006590. This clears all four65B0..65B3 bytes.
- Build exactly three initialized bytes `[AC, value>>8, value&FF]` on CPU stack; call230251E4(peer0,class3,length3), reusable as `rr_bt_dongle_tx`. It adds checksum byte. No old stack padding is transmitted; no invented36-byte queue tail is necessary.
- Reload u16[659A]. Nonzero and6598==0: set6598=1 **before** timer call. Start timer23001AD8 with duration100000 and period1000 viaE06EBE0, reusable `rr_receiver_timer_start_control`. ABI r1=1 is the alignment hole before64-bit duration inr2/r3; it is not an extra duration flag.
- Zero and6598!=0: clear6598 before tailcallingE06EC54, reusable `rr_receiver_timer_stop_control`.
- Otherwise return. Preserve earlier message/state changes on timer callback or CPU-switch boundary; do not repeat them on continuation.

Initialized timer callback word at23001AF8 (timer+20) is23025641; current `rr_receiver_application_timer` already implements callback23025640, including AC updates, half-period report and USB reports. Timer expiry still flows through existing timer/RTC infrastructure; calling the setup wrapper alone does not execute a future expiry.

Input domain for FE72 is u16. Calling helper directly with larger32-bit values can compare unequal then store a truncated period; do not silently use a u16 API if trying to claim arbitrary originalr0 equivalence. Business queue state must satisfy existing business_tx bounds. Stop/start helpers can reach CPU/callback boundaries and retain their existing explicit return contract.

## LED wrappers and genuine driver dependencies

23025954 computes index `(arg0-1)&FF`; indexes0..3 read three tables, others choose0,0,0. RGB driver argument triples for arg1..4 are respectively `(255,255,255)`, `(255,0,0)`, `(0,255,0)`, `(0,0,255)`; each is applied to groups0,1,2 via23025CE0. This matches raw table addressesF78C/F788/F784. Values congruent modulo256 alias because of UXTB.

23025FE0 computes unsigned wrapping multiplication `arg0*100`, divides by255, then indexes4-byte table atE06F7D4. Vendor payload suppliesu8, giving tableindex0..100; larger arbitrary input is not automatically safe. First three table bytes become colors and are applied to groups0..2.

Decompilers show a spurious fifth argument forwarded from incomingr3. Original wrappers overwrite all four argument registers to25CE0(group,r,g,b); **there is no incoming fifth stack parameter requirement**. In25CE0 the PWM setter fifth argument is flags read from each ROM record, explicitly written to[sp] beforeBLX. Getter writes both words of64-bitfrequency, so stock path contains no leaked prior stack rate. If a substituted device getter reports success without initializing its out-parameter, that would be an external residue domain, not stock behavior.

Each group consists of3 records `{device,channel,period_ns,flags}` at E06F968+group*48+color*16. Allperiods=2048000ns,flags0,channels0/1/2. Resolution:

| Group | Device | Config | PWM base | State | DMA sequence |
|---|---|---|---|---|---|
|0|E06F708|E07064C|5F9A4000|23006DA8|2FC13010|
|1|E06F6F4|E0705E8|5F9B4000|23006DA0|2FC13008|
|2|E06F6E0|E070584|5F9C4000|23006D98|2FC13000|

VtableE0706B0 resolves get_cycles_per_second **E0680C0**, setter **E068170**. Getter returns u64(config+3C)=16000000. Therefore period conversion gives32768cycles; pulse uses `floor(floor(2048000*color/255)*16000000/1e9)` with the original order of integer divisions, not simply32768*color/255.

25CE0 includes64-bit division through thunk23027208→E05BA10; implement exact unsigned arithmetic or reuse an audited pure division implementation, no driver success substitution. Original guards reject conversion overflow and pulse>period before setter call. Forstocku8colors/fixed16MHz these are bounded.

E068170 is missing from portable modules. It validates channel<=3, optionally halves cycle counts if config modebyte+1E==1, manages period/prescaler and active-channel bitmap in state, writes waveform halfwords to DMA sequence, and then:

- If config+40 bit0 set, calls cache flush **E067318**. Stock configs+40=8 so this branch is disabled, but preserve for mutable configurations. Cache registersE0083400/04/10 andE0083018 require explicit memory/event domain if modeled.
- Static-duty0/full cases may drive GPIO through PWM PSEL_OUT registers and tableE070538; invalidpin>319 goes to software UDF boundaries E0682D2/E0682D8. GPIO windows are additional hardware dependencies, not part of current radio bus.
- Active waveform starts **E069BA8**, which programs sequence pointers/counts, shortcuts, enabled interrupt bits and task register, and marks state6E0C+index*20=2.
- All channels inactive calls **E069C78** stop; restart waits on **E069D20** until hardware stopped event becomes available. Stable snapshots with STOPPED==0 and state2 can wait forever. Expose genuine event wait; never assume immediate completion.

Current radio_test_timer andgppi modules are not PWM substitutes. New required windows include3 PWM blocks, DMA2FC13000..17, relevant GPIO and optionallycache. No existing portable LED implementation was found by entry/symbol search. Host output snapshots do not prove electrical LED brightness.

## Class10 E05BE8C: state and reusable flash backend

Packet2D1C,op2D23,payload2D24. State:2DFC lastchunkaddress;2E00/2E04 bootaddress/sizepair;2E08..3007 512-bytebuffer;3008 writegranule;300C bufferedcount;3010 writeoffset;3014 expectedsize;3018 receivedend;301C area pointer;71BE erasefill byte.

Selector80 sets payloadword00103B07,word0,byteBF,status2 then tailcallsE06F4B8→230203CC(1). Unknown selectors except1/2/4/5/80/83 set5. Selector83 raw instruction path is retained: if300C nonzero, round it up to writegranule3008, callE05FE20(area,offset,buffer,count); nonzero result sets3 and returns. Otherwise clearbufferedcount; read lengthpayload0 at BE32packet+9 into packet+13 viaE05FDE8; status2 on success3 on failure.

The switch paths1/2/4/5 are present in existing decompilation but **absent in retained instruction listing** after computedTBB. Their provisional state map:1 opensarea3, checks *old* expectedsize3014 againstarea size before replacing it fromBE32payload+4, initializesbuffer/count/offset andlastchunkFFFFFFFF, tailmode0;2 ignores duplicatechunkaddress, appendslengthbyte frompacket+13, flushes only when bufferedcount==512, thenmode0;4 closes/resetstates,status2,mode2;5 constructsbootrequest if receivedend==expectedsize, closes/resetstates and calls bootrequestE0689C0 then rebootE05D698. Parent must export missing basic blocks before claiming instruction-verified exact continuations. The decompiler's apparent fallthrough after reboot into write-flush is not evidence reboot returns.

### Area and driver resolution

RAM230004F8 initially pointsE0700B4. Count is ROM **E0700B0=4**, notRAM4FC. Four16-byte area records: id6 offset54000 size57000;id3 offset100000 sizeDB000;id4 offset1DB000 size2000;id5 offset1DF000 size3000. All use deviceE06F6CC. Area3 record isE0700C4. Device readiness state address1A1A is already handled by `rr_receiver_storage_device_ready` (state1 bit0 set,state0==0).

E05FD94 returns-13 iftablepointer0,-2 ifidmissing,-19 ifdevice absent/notready; otherwise writesrecordpointer andreturns0. E05FDE4 rawbytes7047=BXLR: no-op close; no filesystem handle deletion is implied.

E05FDE8/E05FE20 validate signedoffset>=0 and unsigned32(offset+length)<=area size, then tailcall devicevtable read/write with absoluteoffset=area.offset+offset and unchangedbuffer/length. Preserve wrapping addition and original absence of complete overflow protection; a safehost domain must avoid offsets that wrap rather than pretending original validated them.

DeviceE06F6CC vtableE0703B4: readE067488,writeE0674B4,eraseE0674F0,parametersE067470,page-layoutE067478. Retained raw instructions show these mappeddrivers are exactly existing `rr_receiver_storage_mapped_read/write/erase`: total2MiBoffset/lengthbounds,write/erase16bytealignment; readusesmapped E000000+offset,write memcpy plusDMB,erase memsetFF plusDMB. These are appropriate local modeled backend reuse, not physical-flash persistence proof.

E067470 returns pointerE070394; bytes indicate writeblocksize16,erasevalueFF at+5. E05FE58 returnsword0 fromthatparameterstructure;E05FE68 returnsbyte+5. They are small missingadapter functions. Settings journal mount/CRC logic is unrelated and must not be applied to raw firmwarechunks.

E068A38 lacks retained disassembly/decompile; rawbytes `20f0805000f160607047` indicate an address transformation, not evidence of memoryallocation. Do not label it allocator. E0689C0 bootdescriptor/action routine remains missing (no retainedfunctionexport), andresetE05D698 remains a real terminal boundary. Do not fabricate successful boot validation.

### Update-mode B1 side effect is already reconstructible

230203CC(0) clears **halfword2C86**, preserving lower2C84 halfword; it returns withouttransmission. Argument1 storesword2C84=1 andbyte71BD=1;othernonzero storesword2C84=0 and71BD=0. Both tailcall2302060C(1).

2302060C builds six initialized bytes `[B1,71BD,71BC,1,71E5,low8(2C82)]` and zeroes further localpadding, then230251E4(peer=(arg!=1),class3,len6). Thus actualmode1/2 paths usepeer0. Reuse `rr_bt_dongle_tx` with7-byte mutablebuffer; no queue36-byte residue is involved. This is a distinct B1 update-mode message, not anack thatfirmwarewrite completed.

## Stack and bounded-domain conclusions

Stats AC body, stockLED getter/setter arguments, andupdate-mode B1 contain no escaped uninitialized bytes. Existing identity/reset publishers230252A4/23025300 remain distinct: their36-bytequeue messages initialize8bytes and require explicit28-byteoldstacktail; reuse receiver_config_value_publish withthatinput. Never infer zeroresidue because similar wrappers usefullyinitializedsmallpackets.

For class10 chunk modeling, explicitly bound source within suppliedpacketmemory and bufferedcount+length within512; original only flushes equality512 and doesnot protectovershoot. Roundupflush bytes must preserve actualbufferpadding filled witherasevalue. Switching unknown livevtable/device addresses requires a realboundary or declaredexternalimplementation; fixedstocktable evidence doesnot authorize arbitrarycallback success. All helper continuationclaims still require originalThumb differentialvalidation.
