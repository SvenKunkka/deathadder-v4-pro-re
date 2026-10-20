"""Recovered special-frame decision fragment; no device access.
Static source/assembly derivation, not target emulation or RF validation.
Scope: invocation of mode4 TX candidate handler (event=3), slots0/3.
"""
from dataclasses import dataclass

@dataclass(frozen=True)
class SpecialInput:
    radio_state: int = 0x18
    handler_event: int = 3
    protocol_mode: int = 4
    slot: int = 0
    interval: int = 1
    cached_motion: int = 0  # byte23002671
    retry_holdoff: int = 0  # byte230029D0
    link_state: int = 3    # halfword23002794
    idle_channel_count: int = 0  # byte230029D1[channel]
    read_indices: tuple = (0,0,0,0,0,0)   #23002ADC..AE1
    write_indices: tuple = (0,0,0,0,0,0)  #23002AD6..ADB
    capture7: int = 470


def select_special(s: SpecialInput):
    """Returns whether frame is built and then armed, preserving timing rejection.
    Does not model ordinary packet fallback or interrupt races.
    """
    if len(s.read_indices)!=6 or len(s.write_indices)!=6:
        raise ValueError("exactly six queue indices required")
    entry=(s.protocol_mode==4 and s.radio_state==0x18 and s.handler_event==3)
    queues_empty=all(a==b for a,b in zip(s.read_indices,s.write_indices))
    threshold=4 if s.link_state==3 else 16
    built=(entry and s.slot in (0,3) and s.interval==1 and not s.cached_motion
           and queues_empty and s.retry_holdoff==0 and s.idle_channel_count<threshold)
    timing_ok=((s.capture7&0xffffffff)>99 if s.slot==0 else (s.capture7&0xffffffff)<=250)
    return {"built":bool(built),"armed":bool(built and timing_ok),
            "frame_hex":"025500" if built else None,
            "txen_dppi_channel":(0 if s.slot==0 else 2) if built else None,
            "after_software_state":(0x19 if timing_ok else 0x18) if built else s.radio_state}


def receiver_special_result(*, hardware_crc_ok=True):
    """Normal mode4 state0xC / END path only. Negative sum of 0x55 is0xAB.
    Failure clears length and changes state to0xB, without packet notification.
    """
    return {"accepted":False,"expected_check":0xab if hardware_crc_ok else None,
            "received_check":0,"rx_length_after":0,"software_state_after":0xb,
            "notification_called":False,"reply_flag_written":False,
            "sequence_written":False,"miss_counter_reset":False}
