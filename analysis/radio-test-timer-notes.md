# Receiver 1.20 radio-test TIMER notes

Static analysis, raw-instruction verified. No physical device access; no execution-equivalence claim.

Firmware SHA-256: `f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162`.

## Instance and critical corrections

`E06FD14` bytes `0090025301080000`: base `53029000`, index 1, eight compare channels. Callback/context/state are `23006E4C` / `23006E50` / `23006E54`.

`E069F84` is microseconds-to-ticks; `E069FF0` is **milliseconds-to-ticks**. Both use 64-bit multiply plus ARM register shifts. Preserve low-eight-bit shift behavior; do not use C modulo32 shifting. Test init sets 1 MHz through prescaler5, mode0 and bitmode2.

## Functions

### `0e069ee8` — timer_initialize

- index=u8(instance+4); state=23006e40+12*index
- if u8(state+8)!=0 return 0bad000c without writes
- store32(state,callback)
- if config==0: store8(state+8,1); return 0bad0000, context unchanged
- otherwise store32(state+4,read32(config+8)); call E069E04(instance,config); state+8=(result==0bad0000); return result

### `0e069e04` — timer_configure

- base=read32(instance); sourceHz=320000000 for 5f8e2000/5f8e3000; 32000000 for 53028000/53029000/5302a000; otherwise16000000
- freq=read32(config); quotient=sourceHz/freq, remainder=sourceHz-freq*quotient; reject remainder!=0 OR freq>sourceHz OR (quotient&(quotient-1))!=0 OR quotient>512 with 0bad0004
- accept: read config bytes 5 and4; mode +504=(old&~3)|(config[4]&3); bitmode +508=(old&~3)|(config[5]&3); prescaler +510=ctz(quotient)
- clear all eight compare events +140..15c in ascending order, each with write0 followed by readback
- call E0612AC((base>>12)&511); return 0bad0000

### `0e069f3c` — timer_start

- write32(base+0,1)
- state[index].state=2

### `0e069f5c` — timer_stop_and_clear

- write32(base+4,1)
- reload instance base, write32(base+12,1)
- state[index].state=1

### `0e069f7c` — timer_clear

- write32(base+12,1)

### `0e069f84` — microseconds_to_ticks

- multiplier selected from same base groups; read prescaler p at base+510
- uint64 product = uint32(argument)*multiplier; hi=product>>32; lo=(uint32)product
- return LSR(lo,p)|LSL(hi,32-p)|LSR(hi,p-32), ARM register shifts use low8 shift and yield0 for shifts>=32. For p in0..63 this is low32(product>>p). Outside range do not replace by unchecked C shift.

### `0e069ff0` — milliseconds_to_ticks

- Same multiply/shift algorithm as E069F84; factor1000 larger. Not microseconds.

### `0e06a064` — timer_compare_configure

- m=ARM_LSL(0x10000,channel); c=ARM_LSL(1,channel)
- base+200=(old&~(m|c)); reloadbase and shorts; base+200=old|shorts_mask
- enable0: write32(base+308,m)
- enable!=0: write32(base+140+channel*4,0), readback, write32(base+304,m)
- reload base; write32(base+(channel+0x150)*4,compare_value)
- No explicit channel bounds in firmware; host bounds must be reported as model-domain restriction

### `0e069d98` — timer_irq_common

- snapshot pending events by scanning eight +140..15c; clear and read back every nonzero event even if interrupt masked, record bit16+i
- after all clears snapshot enabled=read32(base+304)&00ff0000
- for each ascending channel where pending&enabled bit set: reload callback32(state); if nonzero reload context32(state+4); indirectcall(callback,event_offset=140+4*i,context)
- Event offset is uint16; 8 channels means140..15c. enabled snapshot is not reloaded after callbacks; callback/context are.

### `0e06a0c4` — timer021_irq

- tailcall E069D98(53029000,23006e4c)

### `0e05cd04` — radio_sweep_timer_callback

- if event_offset!=140 return
- type=descriptor[0]; if3 set71e0=1; call E05CBB8(mode=u8d1,power=s8d4,channel=u8[71e1]); reload start=d5,end=d6,step=d7
- if type4 set71e0=1; call E05CC4C(mode=u8d1,channel=u8[71e1],pattern=u8d4); reload start=d4,end=d5,step=d6
- for type3/4 after target returns: next=uint8(u8[71e1]+step); [71e1]=(next<=end?next:start); [71e0]=0
- other types tailcall E05D634(format E06FC88, type); no subsequent writes

### `0e05d1ac` — radio_test_init

- stack config {u32frequency=1000000,u8mode=0,u8bitmode=2,u16padding0,u32context=argument}
- call E069EE8(E06FD14,config,E05CD05); non-success calls logging E05D634 but continues
- call E0612F0(IRQ41,prio5,flags0) writes u8E000E429=E0
- write32(2300661c,argument)
- call E06A658(&230071df); success0bad0000 logs channel and returns0; other result logs failure and returnsFFFFFFF2

### `0e0612ac` — irq_enable

- irq=signextend16(argument); if irq>=0 write32(E000E100+4*(irq>>5),1<<(irq&31))
- For TIMER021 base53029000 IRQ41: write32(E000E104,0x200)

## Evidence and remaining boundaries

- New export: `radio-test-timer-expansion/` (16 decompilations, raw timer instructions).
- Original ROM bytes verified against SHA-256 and retained Ghidra project by export script.
- `E05CD04` raw branches checked in `dongle-radio-1.20-final/disassembly.txt`, including signed power load and wrapping channel addition.
- GPPI allocation `E06A658`, log formatting `E05D634`, and RF functions `E05CBB8` / `E05CC4C` remain dependencies in these notes.
- IRQ handler clears all recorded compare events before testing interrupt enable. Enable mask is a single snapshot; callback/context are loaded afresh each iteration.
- `E05D1AC` does not fail early when timer initialization fails. It logs then continues IRQ priority, descriptor store, GPPI allocation.

Machine-readable details: `radio-test-timer-notes.json`.

## Portable implementation

New `receiver_radio_test_timer.c/.h` implements the ten TIMER entries listed in the JSON. C11 warning-as-error compile passed. Parent owns original-Thumb comparison; no such pass is claimed here. Fifth compare-config argument uses `args[4]`. Void entries set result to zero as an API marker, not original incidental r0.
