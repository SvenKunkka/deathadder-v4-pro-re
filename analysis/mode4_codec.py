"""Static reconstruction of selected Razer DA V4 Pro 1.20 mode-4 operations.

These are RADIO EasyDMA memory frames, NOT full over-the-air bit streams.
No device I/O. Not original source; not validated against RF captures/emulation.
Source: mouse 23024BAA..23024BF4; dongle 2302427A..230242BC.
Only the normal mouse uplink path gets the extra additive check byte.
"""
from dataclasses import dataclass


def check_byte(payload: bytes) -> int:
    return (-sum(payload)) & 0xff


def encode_mouse_uplink(source_frame: bytes) -> bytes:
    """Add check byte to [payload_length, payload...] for the recovered 16-byte copy.

    Limit 15 is this reconstruction's safe input contract, not a proven firmware
    length rejection. Firmware copies 16 bytes before its append loop.
    """
    if not source_frame or source_frame[0] != len(source_frame)-1:
        raise ValueError("source length mismatch")
    if source_frame[0] > 15:
        raise ValueError("outside recovered 16-byte source-copy contract")
    payload = source_frame[1:]
    return bytes([len(payload)+1]) + payload + bytes([check_byte(payload)])


def decode_mouse_uplink(dma_frame: bytes, *, hardware_crc_ok: bool) -> bytes:
    """Mirror receiver integrity acceptance and strip extra check byte.

    Requires the caller's actual hardware-CRC status. Framing bounds are explicit
    host API validation, not a claimed firmware software bounds check.
    """
    if not hardware_crc_ok:
        raise ValueError("hardware CRC failed")
    if not dma_frame or not 1 <= dma_frame[0] <= 31:
        raise ValueError("invalid length")
    if len(dma_frame) != dma_frame[0]+1:
        raise ValueError("frame length mismatch")
    payload, received = dma_frame[1:-1], dma_frame[-1]
    if check_byte(payload) != received:
        raise ValueError("extra additive checksum failed")
    return bytes([len(payload)]) + payload


def mouse_header(request_reply: int, sequence: int, failure_count: int) -> int:
    """2302168C + 230221EC: caller fields bounded; counter saturates to 15."""
    if request_reply not in (0,1) or not 0 <= sequence <= 7 or failure_count < 0:
        raise ValueError("invalid field")
    return (request_reply << 7) | (sequence << 4) | min(failure_count,15)


def dongle_header(flag7: int, queued_flag6: int, low_value: int) -> int:
    """230209D0: shift is 6, unlike the mouse sequence shift of 4.

    low_value is a raw byte in firmware; do not claim its upper bits are masked.
    """
    if flag7 not in (0,1) or queued_flag6 not in (0,1) or not 0 <= low_value <= 255:
        raise ValueError("invalid field")
    return ((flag7 << 7) | (queued_flag6 << 6) | low_value) & 0xff


def next_sequence(sequence: int) -> int:
    if not 0 <= sequence <= 7:
        raise ValueError("invalid sequence")
    return 1 if sequence == 7 else sequence+1


def make_mouse_status(sequence: int, body_sequence: int, idle_counter: int,
                      failure_count: int = 0) -> bytes:
    """23024CEE: 0x17 is this status body's byte-3 marker, not all packets' opcode."""
    if not 1 <= body_sequence <= 7 or not 0 <= idle_counter <= 0xffff:
        raise ValueError("invalid field")
    src = bytes([5,mouse_header(1,sequence,failure_count),body_sequence,0x17])
    return encode_mouse_uplink(src+idle_counter.to_bytes(2,"big"))


def make_dongle_sync(header: int, body_sequence: int, event_counter: int) -> bytes:
    """230248BE / TIMER ISR fallback: length 5; NO additive byte appended."""
    if not 0 <= header <= 255 or not 1 <= body_sequence <= 7 or not 0 <= event_counter <= 0xffff:
        raise ValueError("invalid field")
    return bytes([5,header,body_sequence,0x1f])+event_counter.to_bytes(2,"big")


def sync_counter(old: int, received: int, capture7: int) -> int:
    """Mouse 23024846..23024898, unsigned comparisons cross-checked in assembly."""
    if ((capture7-166) & 0xffffffff) <= 83:
        return received & 0xffff
    if ((capture7-416) & 0xffffffff) <= 83:
        return (received+1) & 0xffff
    return old & 0xffff


def tx_guard(slot: int, capture7: int) -> bool:
    """Mouse 23024BFA..23024DA6 / 23024F1C: readiness guard, not exact TX time."""
    capture7 &= 0xffffffff
    return {0: capture7 > 99, 1: capture7 <= 100,
            3: capture7 <= 250, 4: capture7 <= 350}.get(slot,True)


@dataclass(frozen=True)
class MotionAccumulator:
    """Mode-4 queue-1 aggregation at 23025020. Signed meaning is inferred;
    actual operations wrap modulo 256/65536. ACK clears this entire cache.
    Byte-3 buttons OR, byte-4 wheel add, bytes-5..6/7..8 big-endian add.
    """
    buttons: int = 0
    wheel: int = 0
    x: int = 0
    y: int = 0

    def add(self, frame: bytes, latched_buttons: int = 0):
        if len(frame) < 9:
            raise ValueError("motion source needs bytes 0 through 8")
        a=MotionAccumulator(self.buttons|frame[3]|latched_buttons,
            (self.wheel+frame[4])&255,
            (self.x+int.from_bytes(frame[5:7],"big"))&65535,
            (self.y+int.from_bytes(frame[7:9],"big"))&65535)
        out=bytearray(frame)
        out[3:9]=bytes([a.buttons,a.wheel])+a.x.to_bytes(2,"big")+a.y.to_bytes(2,"big")
        return a,bytes(out)

    def on_crc_ok_downlink(self):
        return MotionAccumulator()


def dongle_sequence_transition(last_mouse_sequence: int, received_mouse_sequence: int,
                               selected_queue: int, tx_sequence: int):
    """230243xx: only a changed uplink sequence pops a selected queue <6.
    Duplicate packets still pass integrity processing / notification elsewhere.
    """
    changed=received_mouse_sequence != last_mouse_sequence
    pop=changed and selected_queue < 6
    return {"last_mouse_sequence":received_mouse_sequence,
            "tx_sequence":next_sequence(tx_sequence) if pop else tx_sequence,
            "pop_selected_queue":pop,"selected_queue":255,
            "reset_link_miss_counter":changed}
