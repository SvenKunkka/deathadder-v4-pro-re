"""Offline reconstruction of the 1.20 handshake buffer-write contract.

Evidence: dongle 23022360/230223F0; mouse 230227B8, cross-checked
against original Thumb instructions. These are 12-byte DMA buffers, not
encoded RF waveforms. Authentication, radio timing and persistent pairing
are intentionally outside this codec's contract. No hardware I/O.

Unwritten bytes are inherited from the caller's buffer. Validation here is
an analysis-interface safeguard, not a claim about device validation.
"""
from dataclasses import dataclass


def _buffer(previous: bytes) -> bytearray:
    if len(previous) != 12:
        raise ValueError('Supply all 12 existing DMA-buffer bytes')
    return bytearray(previous)


def _header(previous: bytes, command: int, sequence: int, slot=None):
    if not 1 <= sequence <= 7:
        raise ValueError('Codec models the observed valid sequence domain 1..7')
    result = _buffer(previous)
    result[:4] = bytes((11, 0 if slot is None else (slot & 1) << 6,
                        sequence, command))
    return result


def next_sequence(sequence: int) -> int:
    if not 1 <= sequence <= 7:
        raise ValueError('Expected sequence 1..7')
    return 1 if sequence == 7 else sequence + 1


def dongle_offer(previous: bytes, *, sequence: int, slot: int, base1: int,
                 capabilities: int, flag7: bool, flag6: bool,
                 event_counter: int) -> bytes:
    """Command 0x11. All 12 bytes are assigned by this producer."""
    packet = _header(previous, 0x11, sequence, slot)
    packet[4:8] = (base1 & 0xffffffff).to_bytes(4, 'big')
    packet[8] = capabilities & 15 | int(flag7) << 7 | int(flag6) << 6
    packet[9] = 0
    packet[10:12] = (event_counter & 0xffff).to_bytes(2, 'big')
    return bytes(packet)


def mouse_offer_reply(incoming: bytes, *, sequence: int, capabilities: int,
                      flag7: bool, identity_bytes: bytes) -> bytes:
    """Command 0x12; bytes 10..11 retain the received event counter.

    identity_bytes is the exact four bytes loaded from mouse local state;
    a semantic serial-number interpretation is not assumed.
    """
    if len(identity_bytes) != 4:
        raise ValueError('Expected four identity bytes')
    packet = _header(incoming, 0x12, sequence)
    packet[4] = capabilities & 15 | int(flag7) << 7
    packet[5] = 0
    packet[6:10] = identity_bytes
    return bytes(packet)


def select_mode(local_mask: int, remote_mask: int):
    """Exact priority in dongle 230223F0: 8, 4, 1, then 2.

    Returns None for no intersection. This does not assert the mouse has
    a complete mode-8 branch; that transition is a separate open question.
    """
    available = local_mask & remote_mask & 15
    return next((mode for mode in (8, 4, 1, 2) if available & mode), None)


def dongle_selection(previous_tx: bytes, *, sequence: int, slot: int,
                     mode: int, channel_selector: int,
                     index0: int, index1: int) -> bytes:
    """Command 0x13. Bytes 7..11 remain in the dongle's TX buffer."""
    packet = _header(previous_tx, 0x13, sequence, slot)
    packet[4] = (mode & 15) | (channel_selector & 3) << 4
    packet[5] = 0
    packet[6] = (index0 & 15) | (index1 & 15) << 4
    return bytes(packet)


def mouse_selection_reply(incoming: bytes, *, sequence: int, local_value: int) -> bytes:
    """Command 0x14. Writes 4..7; incoming bytes 8..11 are untouched."""
    packet = _header(incoming, 0x14, sequence)
    packet[4:8] = bytes((local_value & 255, 0, 0, 0))
    return bytes(packet)


def dongle_channel_parameters(previous_tx: bytes, *, sequence: int, slot: int,
                              selector: int, fixed_frequencies: bytes=b'',
                              mask: bytes=b'', selector2_value: int=0) -> bytes:
    """Command 0x15. Selector 0/1 writes 8 bytes, 2 writes 6, 3 writes 5.

    mask preserves all five source bytes, including the three upper bits;
    their later use is separate from this producer's byte-copy contract.
    """
    packet = _header(previous_tx, 0x15, sequence, slot)
    if selector in (0, 1):
        if len(fixed_frequencies) != 8:
            raise ValueError('Two banks of four frequency bytes required')
        packet[4:12] = fixed_frequencies
    elif selector in (2, 3):
        if len(mask) != 5:
            raise ValueError('Five mask bytes required')
        packet[4:9] = mask
        if selector == 2:
            packet[9] = selector2_value & 255
    else:
        raise ValueError('Only selectors 0..3 are modeled')
    return bytes(packet)


def mouse_channel_reply(incoming: bytes, *, sequence: int) -> bytes:
    """Command 0x16. Zeros 4..5 and retains incoming bytes 6..11."""
    packet = _header(incoming, 0x16, sequence)
    packet[4:6] = b'\0\0'
    return bytes(packet)


@dataclass(frozen=True)
class HandshakeView:
    command: int
    header0: int
    header1: int
    data: bytes


def inspect_packet(packet: bytes) -> HandshakeView:
    """Expose bytes without assigning unproven authentication semantics."""
    p = _buffer(packet)
    if p[0] != 11 or p[3] not in range(0x11, 0x17):
        raise ValueError('Not a modeled handshake DMA buffer')
    return HandshakeView(p[3], p[1], p[2], bytes(p[4:12]))
