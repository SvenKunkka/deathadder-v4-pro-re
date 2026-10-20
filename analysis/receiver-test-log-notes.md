# Receiver 1.20 radio-test logging path

The default initialized logging sink is a real two-instruction no-op (`MOVS r0,0; BX LR`). Logs can return without external hardware when RAM `23000494` retains its original value `E05D625`. The initial static finding has now been validated by original Thumb execution against the portable logger.

## Exact chain

`E05D634(format,...)` builds a 16-byte stack stream and calls `E06EEA8(stream,format,va_list)`. Stream words are `00020000,E05D629,0,0`. Each output byte invokes `E05D628`, which reads `23000494` and branches to that pointer. Initialized data at firmware offset `1CCE8` sets the pointer to `E05D625`. Target `E05D624` bytes are `00207047`, returning zero with no global/MMIO changes.

The wrapper returns the formatter character count in r0. Its inferred void decompilation must not be used to replace that result by zero. On callback failure (signed r0<0), the formatter sets bit4 in stream byte2 and returns FFFFFFFF. With the initialized sink, formatting writes only stack scratch/stream state; no hardware dependency remains.

Incoming stack S: stream at S-40, va_list at S-12 (saved r1), then r2/r3 and caller stack arguments.

## Radio formats

| Address | Format | Argument |
|---|---|---|
| `0e06fbfc` | `TX power to enumerator conversion failed, defaulting to 0 dBm\n` | none |
| `0e06fc3c` | `Requested tx output power: %hhi dBm\n` | signed8 |
| `0e06fc64` | `Tx output power set to: %hhi dBm\n` | signed8 |
| `0e06fc88` | `Unexpected test type: %d\n` | signed32 |
| `0e06fca4` | `nrfx_timer_init failed with: %d\n` | signed32 |
| `0e06fcc8` | `Failed to allocate gppi channel.\n` | none |
| `0e06fcec` | `ppi_radio_start = %d\n` | signed32 |

`%hhi` signextends the promoted argument’s low byte; `%d` signextends32. Both handle zero and minimum negatives normally. F3FE returns its end pointer in r0 despite inferred void declaration.

## Implementation boundary

For the seven known RF literal strings and runtime sink exactly E05D625, an exact host implementation can render the literal plus signed decimal value and return the byte count without any global/MMIO write. This executes recovered sink semantics; no external return is invented.

If the pointer differs, retain a genuine callback boundary with emitted character and stream pointer. Do not infer a successful UART operation or replace an unknown sink with the default. An empty format has no callback and returns0 independently of sink.

Only one absolute23000494 word exists in the complete official image (ROM literal E05D630); retained Ghidra exposes one READ reference and no direct setter. This does not exclude derived-pointer writes, so runtime pointer gating remains necessary.

## Evidence

- `receiver-test-log-expansion/`: six decompilations plus raw formatter instructions.
- `receiver-test-log-expansion/sink-references.tsv`: actual retained-project references.
- `receiver-test-log-expansion.log`: successful read-only export; official image hash checked.
- `receiver-test-log-notes.json`: exact addresses, count rules, stack layout, and reconstruction choices.

No existing C/h or manifests changed. No physical device operations.

## Implemented logger module

New `receiver_radio_test_log.c/.h` implements the seven-format/default-sink path and a changed-sink boundary. Exact ROM string bytes are checked. Strict C11 compilation passed. Other odd sink pointers stop at their normalized address with first-character arg0; the stack stream pointer is not projected. Unsupported formats, changed ROM text, even/null sink, or inaccessible memory return -2. Original Thumb comparison completed in this subtask; see results below.

## Original execution validation — PASS

`receiver-radio-log-comparison.json`: 3,328 cases and 3,315,467 original Thumb steps, with zero differences. The original formatter and real default sink executed for 3,072 returns; 256 runs stopped at the actual changed callback. Both `%hhi` formats covered all 256 low-byte values, and `%d` formats exercised 1,284 distinct 32-bit inputs. Full128KiB RAM, six4KiB MMIO snapshots, meaningful return counts, and boundary argument matched. Stack scratch is excluded. No callback return was injected.

New artifacts: `EmulateReceiverRadioLog.java`, `receiver-radio-log-run.py`, `receiver-radio-log-verify.py`, `receiver-radio-log-original.jsonl`, `libreceiver_radio_log_phase62.dylib`, and per-batch logs. Existing C/h files required no fixes.
