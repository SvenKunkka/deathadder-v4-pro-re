"""Readable reconstruction of selected DeathAdder V4 Pro receiver 1.20 algorithms.

Analyst reconstruction from static instructions, NOT vendor source or a complete
wireless stack. No device access, RF transmission, or pairing is performed.
Image SHA256 f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162.
RAM image mapping: flash0x0E05479C -> runtime0x23020000, size0x7270.
"""

# Literal table0x0E06FB84. Values are RADIO.FREQUENCY offsets for MAP=0.
FREQUENCY_OFFSETS_MHZ = (
    4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 28, 30, 32, 34,
    36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62,
    64, 66, 68, 70, 72, 74, 76, 78, 2, 26, 80,
)
# Literal table0x0E06FBAC, bounded by code0x23022888 resetting index after3.
ACQUISITION_CHANNEL_INDICES = (37, 38, 22, 39)


def reverse_bits_within_each_byte(value: int) -> int:
    """0x23021B8C, 16-bit operation; nibble LUT at0x0E06FB74."""
    value &= 0xFFFF
    value = ((value & 0xAAAA) >> 1) | ((value & 0x5555) << 1)
    value = ((value & 0xCCCC) >> 2) | ((value & 0x3333) << 2)
    return ((value & 0xF0F0) >> 4) | ((value & 0x0F0F) << 4)


def channel_identifier(base1: int) -> int:
    """0x23020FCC / 0x23021700: low16(BASE1) XOR high16(BASE1)."""
    return ((base1 >> 16) ^ base1) & 0xFFFF


def select_channel(event_counter: int, base1: int, enabled_mask: int) -> dict:
    """0x23021534 + 0x23021654 + 0x23021700, channel-selector modes2/3.

    This follows the observed permutation/multiply/add/remap sequence. It has
    the structure of BLE CSA#2, but no claim of BLE interoperability is made.
    A zero mask is rejected here for defined offline behavior; this guard is
    analyst-added and does not describe the target's zero-mask behavior.
    """
    enabled = [i for i in range(37) if enabled_mask & (1 << i)]
    if not enabled:
        raise ValueError('At least one channel must be enabled')
    cid = channel_identifier(base1)
    value = (event_counter & 0xFFFF) ^ cid
    for _ in range(3):
        value = (17 * reverse_bits_within_each_byte(value) + cid) & 0xFFFF
    prn = value ^ cid
    unmapped = prn % 37
    channel = unmapped if enabled_mask & (1 << unmapped) else enabled[(prn * len(enabled)) >> 16]
    offset = FREQUENCY_OFFSETS_MHZ[channel]
    return {'channel_identifier': cid, 'prn': prn, 'unmapped_channel': unmapped,
            'channel': channel, 'frequency_register': offset,
            'frequency_mhz_if_map0': 2400 + offset}


def crc16_ccitt(data: bytes, seed: int = 0xFFFF) -> int:
    """0x23020000 (flash0x0E05479C), algebraic byte update reconstructed.

    Firmware seed comes from optional ushort pointer, default0xFFFF. This is a
    software helper; radio CRC coverage is independently configured by CRCCNF.
    """
    crc = seed & 0xFFFF
    for byte in data:
        crc = ((crc & 0xFF) << 8 | crc >> 8) ^ byte
        crc ^= (crc & 0xFF) >> 4
        crc ^= crc << 12
        crc = ((crc & 0xFF) << 5) ^ (crc & 0xFFFF)
    return crc & 0xFFFF


def decode_receive_header(byte: int) -> dict:
    """Helpers0x230209A8/AC/B4; field meanings beyond bit positions inferred."""
    return {'bit7': (byte & 0xFF) >> 7,
            'sequence_candidate_bits6_4': (byte & 0x7F) >> 4,
            'low_nibble': byte & 0x0F}


def pack_ack_header(bit7: int, bit6: int, bit5: int, bit4: int, low: int) -> int:
    """0x2302098C. Callers are expected to supply single-bit values/low nibble."""
    return (low | bit4 << 4 | bit5 << 5 | bit6 << 6 | bit7 << 7) & 0xFF


def additive_checksum(data: bytes) -> int:
    """Receive validation at0x23024190: final byte equals negative byte sum."""
    return (-sum(data)) & 0xFF
