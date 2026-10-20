"""Tests use real instruction encodings + independent boundary/event fixtures.
They do not emulate the full firmware, prove RF behavior, or validate all scheduling.
"""
import pathlib, re, struct, subprocess, unittest
from mouse_ack_model import State, RX, IDLE, TX, tx_header, class_sequence, decode_class_sequence
ROOT=pathlib.Path(__file__).parent
IMAGE=ROOT/'runtime-images/mouse-ram-1.20.bin'
RAW=IMAGE.read_bytes()
def code(address,n): return RAW[address-0x23020000:address-0x23020000+n]

class BinaryEvidence(unittest.TestCase):
    def test_thumb_header_extractors_exhaustive(self):
        # UBFX encodes lsb=(imm3<<2)|imm2, width=widthminus1+1.
        for address,which in [(0x230216a8,0),(0x230216a0,1)]:
            a,b=struct.unpack('<HH',code(address,4))
            if which==0:
                self.assertEqual(a,0xf3c0)
                shift=((b>>12)&7)*4+((b>>6)&3);mask=(1<<((b&31)+1))-1
            else:
                self.assertEqual(a,0xf000);shift=0;mask=b&255
            for x in range(256): self.assertEqual(decode_class_sequence(x)[which],(x>>shift)&mask)
    def test_header_builder_instruction_constants(self):
        self.assertEqual(code(0x2302168c,12).hex(),'090141eac0110a43d0b27047')
        self.assertEqual(code(0x23021698,8).hex(),'41eac000c0b27047')
        # Extract immediates from independently disassembled official bytes.
        text=subprocess.check_output(['arm-none-eabi-objdump','-D','-b','binary','-marm','-Mforce-thumb','--adjust-vma=0x23020000','--start-address=0x2302168c','--stop-address=0x230216a0',str(IMAGE)],text=True)
        shifts=[int(x) for x in re.findall(r'(?:lsls\s+r1, r1, #|lsl #)(\d+)',text)]
        self.assertEqual(shifts,[4,7,3])
        for flag in range(2):
            for seq in range(8):
                for low in range(16): self.assertEqual(tx_header(flag,seq,low),((flag<<shifts[1])|(seq<<shifts[0])|low)&255)
        for kind in range(8):
            for seq in range(8): self.assertEqual(class_sequence(kind,seq),(kind<<shifts[2])|seq)
    def test_binary_thresholds_and_dispatch(self):
        # CMP queue<=5, sequence wrap8, mode1 success failure>2, retry>3.
        for address,expected in [(0x230230b6,'0529'),(0x23023092,'082b'),(0x230237b6,'022e'),(0x23023938,'032a')]:
            self.assertEqual(code(address,2).hex(),expected)
        firmware=(ROOT.parent/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin').read_bytes()
        self.assertEqual(struct.unpack_from('<I',firmware,0xf0)[0],0x23021705)
        self.assertEqual(struct.unpack_from('<I',firmware,0x1b0)[0],0x23022509)

class TransitionFixtures(unittest.TestCase):
    def test_success_releases_tx_queue_without_rx_sequence_match(self):
        for mode in (1,2):
            for reply_seq in range(8):
                s=State(mode=mode,tx_queue_id=2,sequence=7)
                s.queue_heads[2]=3
                # RX payload category5 intentionally differs from TX queue2.
                s.disabled_irq(True,bytes([5,0xff,(5<<3)|reply_seq]+[0]*13))
                self.assertEqual((s.sequence,s.phase,s.queue_heads[2],s.last_release),(1,IDLE,0,2))
    def test_duplicate_payload_does_not_undo_prior_release(self):
        s=State(tx_queue_id=1);s.received_sequences[3]=2
        s.disabled_irq(True,bytes([5,0,26]+[0]*13))
        self.assertEqual(s.queue_heads[1],1)
        self.assertIsNone(s.deferred_receive())
        s.response=bytes([5,0,27,1,2,3]+[0]*10)
        self.assertEqual(s.deferred_receive()['callback_length'],3)
        self.assertIsNone(s.deferred_receive())
    def test_guards_and_invalid_length_boundary(self):
        s=State(tx_queue_id=6)
        s.disabled_irq(True,bytes(16),disabled=False);self.assertEqual(s.phase,RX)
        s.disabled_irq(True,bytes(16));self.assertEqual(s.queue_heads,[0]*6)
        self.assertIsNone(s.deferred_receive())
        # Known firmware behavior: ISR accepts CRCOK before SWI signed length guard.
        self.assertEqual(s.sequence,2)
        s.response=bytes([128,0,9]+[0]*13);self.assertIsNone(s.deferred_receive())
        s.response=bytes([1,0,9]+[0]*13)
        self.assertEqual(s.deferred_receive()['callback_length'],65535)
    def test_mode1_success_and_failure_frequency_boundaries(self):
        s=State(mode=1,failure_counts=[3,0],frequency_indices=[3,0])
        s.disabled_irq(True,bytes(16));self.assertEqual(s.frequency_indices,[0,0])
        s=State(mode=2,failure_counts=[3,0],frequency_indices=[3,0])
        s.disabled_irq(True,bytes(16));self.assertEqual(s.frequency_indices,[3,0])
        s=State(failure_counts=[2,0],frequency_indices=[3,0])
        s.failure_step(0,0,global_state=3,rate_selector=1,event_counter=0)
        self.assertEqual((s.failure_counts,s.frequency_indices),([3,0],[3,0]))
        s.failure_step(0,0,global_state=3,rate_selector=1,event_counter=0)
        self.assertEqual((s.failure_counts,s.frequency_indices),([0,0],[0,0]))
    def test_failure_gate_rate_masks_and_unknown_parameters(self):
        allowed=[]
        for rate in range(9):
            s=State()
            if s.failure_step(0,0,global_state=3,rate_selector=rate,event_counter=0):allowed.append(rate)
        self.assertEqual(allowed,[1,2,4,8]) # independent mask fixture from MVN #0x116
        for rate,period in [(16,2),(32,4),(64,8)]:
            observed=[]
            for event in range(16):
                s=State()
                if s.failure_step(0,0,global_state=3,rate_selector=rate,event_counter=event):observed.append(event)
            self.assertEqual(observed,list(range(0,16,period)))
        s=State(tx_queue_id=2,sequence=5)
        msg=s.disabled_irq(False);self.assertIn('requires',msg)
        self.assertEqual((s.sequence,s.queue_heads[2],s.pending_work,s.phase),(5,0,2,IDLE))

if __name__=='__main__': unittest.main(verbosity=2)
