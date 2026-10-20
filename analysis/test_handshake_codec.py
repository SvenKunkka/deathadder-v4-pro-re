"""Byte-write regression vectors derived from explicit Thumb STR/STRH sites.
These tests do not emulate the firmware or prove RF interoperability.
"""
import unittest
from handshake_codec import *


class HandshakeByteContract(unittest.TestCase):
    def test_six_messages_with_retained_tail(self):
        offer = dongle_offer(bytes([0xa5]*12), sequence=7, slot=1,
                            base1=0x12345678, capabilities=7, flag7=True,
                            flag6=False, event_counter=0xbeef)
        self.assertEqual(offer.hex(), '0b400711123456788700beef')
        reply = mouse_offer_reply(offer, sequence=3, capabilities=5,
                                  flag7=False, identity_bytes=bytes.fromhex('a1b2c3d4'))
        self.assertEqual(reply.hex(), '0b0003120500a1b2c3d4beef')
        selected = dongle_selection(offer, sequence=1, slot=1, mode=4,
                                    channel_selector=2, index0=3, index1=9)
        self.assertEqual(selected.hex(), '0b400113240093788700beef')
        selected_reply = mouse_selection_reply(selected, sequence=4, local_value=0x1234)
        self.assertEqual(selected_reply.hex(), '0b000414340000008700beef')
        parameters = dongle_channel_parameters(selected, sequence=2, slot=1,
                      selector=2, mask=bytes.fromhex('012345670f'), selector2_value=0x55)
        self.assertEqual(parameters.hex(), '0b400215012345670f55beef')
        final = mouse_channel_reply(parameters, sequence=5)
        self.assertEqual(final.hex(), '0b000516000045670f55beef')

    def test_partial_write_contract(self):
        previous = bytes(range(12))
        third = dongle_channel_parameters(previous, sequence=1, slot=0,
                 selector=3, mask=bytes.fromhex('ffffffff1f'))
        self.assertEqual(third[9:12], previous[9:12])
        second = dongle_channel_parameters(previous, sequence=1, slot=0,
                 selector=2, mask=bytes.fromhex('ffffffff1f'),selector2_value=0x55)
        self.assertEqual(second[10:12], previous[10:12])
        fixed = dongle_channel_parameters(previous, sequence=1, slot=0,
                 selector=0, fixed_frequencies=bytes(range(20,28)))
        self.assertEqual(fixed[4:12], bytes(range(20,28)))
        self.assertEqual(mouse_channel_reply(previous,sequence=1)[6:],previous[6:])

    def test_priority_for_every_capability_intersection(self):
        # Exhaustive expected table, independently laid out from branch predicates.
        expected = [None,1,2,1,4,4,4,4,8,8,8,8,8,8,8,8]
        for left in range(16):
            for right in range(16):
                self.assertEqual(select_mode(left,right),expected[left & right])

    def test_valid_sequence_domain_and_view(self):
        self.assertEqual([next_sequence(n) for n in range(1,8)],[2,3,4,5,6,7,1])
        p = mouse_channel_reply(bytes(range(12)),sequence=7)
        self.assertEqual(inspect_packet(p).command,0x16)
        for value in (0,8,255):
            with self.assertRaises(ValueError): next_sequence(value)
        with self.assertRaises(ValueError): inspect_packet(b'\0'*11)


if __name__ == '__main__': unittest.main(verbosity=2)
