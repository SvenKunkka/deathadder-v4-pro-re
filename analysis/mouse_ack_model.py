"""Bounded static model of DA V4 Pro 1.20 mode1/2 response paths.
No USB/RF/device access. Not a full radio stack or instruction emulator.
Address evidence and exclusions: mouse-ack-exact.md/json.
"""
from dataclasses import dataclass, field

IDLE, TX, RX = 0x18, 0x19, 0x1a

def tx_header(flag, sequence, low):
    return (low | (sequence << 4) | (flag << 7)) & 255

def class_sequence(kind, sequence):
    return (sequence | (kind << 3)) & 255

def decode_class_sequence(value):
    return (value >> 3) & 7, value & 7

def next_sequence(value):
    value = (value + 1) & 255
    return 1 if value == 8 else value

@dataclass
class State:
    mode: int = 1
    phase: int = RX
    bank: int = 0
    tx_queue_id: int = 0xffff
    sequence: int = 1
    failure_counts: list = field(default_factory=lambda: [0, 0])
    frequency_indices: list = field(default_factory=lambda: [0, 0])
    frequency_count: int = 4
    queue_heads: list = field(default_factory=lambda: [0]*6)
    queue_capacities: list = field(default_factory=lambda: [4]*6)
    received_sequences: list = field(default_factory=lambda: [0]*8)
    successful_response: bool = False
    pending_work: int = 0
    tx_cache_flag: int = 0
    failure_due: int = 0
    no_response_count: int = 0
    response: bytes = bytes(16)
    aggregate: bytes = bytes(24)
    swi_pending: bool = False
    cleared_subscriptions: list = field(default_factory=list)
    last_release: object = None

    def advance_frequency(self):
        index = (self.frequency_indices[self.bank] + 1) & 255
        self.frequency_indices[self.bank] = 0 if index == self.frequency_count else index

    def release(self):
        """2302145c; called with tx_queue_id, not received packet's class."""
        if self.tx_queue_id < 6:
            q = self.tx_queue_id
            head = (self.queue_heads[q] + 1) & 255
            self.queue_heads[q] = 0 if head == self.queue_capacities[q] else head
            self.last_release = q

    def disabled_irq(self, crc_ok, packet=bytes(16), *, disabled=True,
                     rate_selector=None, slot_phase=None, global_state=None, event_counter=None):
        """23022fbc / 230236ac modeled queue/state side effects only.
        Clock capture, callbacks and peripheral flags are intentionally omitted.
        """
        if self.mode not in (1, 2):
            raise NotImplementedError('Only mode1/2')
        if len(packet) < 16:
            raise ValueError('ISR copies 16 DMA bytes, provide backing buffer including stale tail')
        self.last_release = None
        if not disabled:
            return
        if self.phase == TX and self.mode == 2:
            self.cleared_subscriptions.append('TXEN')
            return
        if self.phase != RX:
            return
        self.cleared_subscriptions.append('RXEN')
        if self.mode == 2:
            self.cleared_subscriptions.extend(['DISABLE', 'TIMER_CAPTURE7'])
        if crc_ok:
            self.response = bytes(packet[:16])
            # There is no reply-sequence check before these operations.
            if self.mode == 1 and self.failure_counts[self.bank] > 2:
                self.advance_frequency()
            self.sequence = next_sequence(self.sequence)
            self.failure_counts[self.bank] = 0
            self.no_response_count = 0
            self.successful_response = True
            if self.mode == 1:
                self.tx_cache_flag = 0
                self.aggregate = bytes(24)
            self.release()
            self.swi_pending = True
        else:
            self.tx_cache_flag = 0
            self.pending_work = 2
            if self.mode == 1:
                if any(v is None for v in (rate_selector, slot_phase, global_state, event_counter)):
                    # Unknown scheduling inputs must not be silently fabricated.
                    self.phase = IDLE
                    return 'failure-counter scheduling requires rate_selector, slot_phase, global_state, event_counter'
                if rate_selector == 1:
                    self.failure_step(1, 0, global_state=global_state,
                                      rate_selector=rate_selector, event_counter=event_counter)
                elif slot_phase == 1:
                    self.failure_due = 1
                elif slot_phase == 3:
                    self.failure_step(1, 1, global_state=global_state,
                                      rate_selector=rate_selector, event_counter=event_counter)
        self.phase = IDLE

    def failure_step(self, argument0, require_due, *, global_state, rate_selector, event_counter):
        """230238f0 exact eligibility and counter/index update."""
        if require_due and not self.failure_due:
            return False
        allow = False
        if global_state == 3:
            if 0 <= rate_selector <= 8:
                allow = ((~0x116 >> rate_selector) & 1) == 0
            elif rate_selector in (16, 32, 64):
                allow = (event_counter & ({16:1, 32:3, 64:7}[rate_selector])) == 0
        elif global_state == 4:
            allow = argument0 == 1
        if allow:
            count = (self.failure_counts[self.bank] + 1) & 0xffff
            self.failure_counts[self.bank] = count
            if count > 3:
                self.advance_frequency()
                self.failure_counts[self.bank] = 0
        self.failure_due = 0
        return allow

    def deferred_receive(self):
        """SWI4 mode1/2, payload delivery decision; class0 diagnostics omitted."""
        packet = self.response
        length = packet[0]
        if not (0 < length < 128):  # LDRSB followed by signed BGT
            return None
        kind, sequence = decode_class_sequence(packet[2])
        if kind == 0:
            return None
        if self.received_sequences[kind] == sequence:
            return None
        self.received_sequences[kind] = sequence
        self.pending_work = 2
        # Firmware sign-extends length-2 then converts to unsigned16.
        signed = ((length - 2 + 128) & 255) - 128
        return {'class':kind, 'sequence':sequence,
                'callback_length':signed & 0xffff, 'payload_backing':packet[3:]}

def main():
    import argparse, json
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--example', action='store_true')
    parser.parse_args()
    s=State(mode=1, tx_queue_id=2, sequence=7)
    s.disabled_irq(True, bytes([5,0xff,0x19,0x40,0x41,0x42]+[0]*10))
    print(json.dumps({'queue_heads':s.queue_heads,'sequence':s.sequence,
                      'phase':s.phase,'delivered':str(s.deferred_receive())},indent=2))
if __name__ == '__main__': main()
