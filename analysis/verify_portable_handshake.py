"""Compile recovered host C and compare against retained original Thumb runs.
Does not execute the vendor firmware natively or touch any physical device.
"""
from pathlib import Path
import ctypes as C
import subprocess,json,hashlib,sys
r=Path(__file__).resolve().parent.parent
src=r/'recovered-code'/'portable'
build=src/'build';build.mkdir(exist_ok=True)
lib=build/('librr_handshake.dylib' if sys.platform=='darwin' else 'librr_handshake.so')
command=['rtk','proxy','clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic',
         '-O2','-fPIC','-shared',str(src/'handshake.c'),str(src/'mouse_handshake.c'),'-o',str(lib)]
subprocess.run(command,check=True,capture_output=True,text=True)
U8=C.c_uint8;U16=C.c_uint16;U32=C.c_uint32
class Globals(C.Structure):
    _fields_=[('status0',U32),('status1',U32),('primary_cap',U16),('fallback_cap',U16),
              ('selector',U16),('selected_mode',U16),('index0',U8),('index1',U8),
              ('frequencies',U8*8),('mask',U8*5),('extra',U8)]
f=C.CDLL(str(lib.resolve()))
f.rr_dongle_handshake.argtypes=[C.POINTER(U8),C.POINTER(U8),U8,C.POINTER(Globals)]
f.rr_dongle_handshake.restype=C.c_int
f.rr_dongle_offer.argtypes=[C.POINTER(U8),U8,U8,U32,U8,U8,U8,U16]
f.rr_dongle_offer.restype=U8
source=r/'analysis'/'handshake-transition-original.jsonl'
rows=[json.loads(x) for x in source.read_text().splitlines()]
assert len(rows)==640
for row in rows:
    m=(U8*224).from_buffer_copy(bytes.fromhex(row['before']))
    rx=(U8*12).from_buffer_copy(bytes.fromhex(row['incoming']))
    g=Globals()
    for name in ('status0','status1','primary_cap','fallback_cap','selector','index0','index1','extra'):
        setattr(g,name,row[name])
    g.selected_mode=row['selected_before']
    g.frequencies[:]=bytes.fromhex(row['frequencies']);g.mask[:]=bytes.fromhex(row['mask'])
    ret=f.rr_dongle_handshake(m,rx,row['slot'],C.byref(g))
    assert bytes(m).hex()==row['after'],('state',row['case'])
    assert g.selected_mode==row['selected_after'],('mode',row['case'])
    assert ret==row['return'],('return',row['case'])
source2=r/'analysis'/'handshake-original-emulation.jsonl'
offers=[json.loads(x) for x in source2.read_text().splitlines()]
assert len(offers)==128
for row in offers:
    packet=(U8*12)(*([0xa5]*12))
    seq=f.rr_dongle_offer(packet,row['sequence'],row['slot'],row['base1'],
        row['capabilities'],row['flag7'],row['flag6'],row['event_counter'])
    assert bytes(packet).hex()==row['packet_hex'],('offer',row['case'])
    assert seq==row['next_sequence'],('offer_seq',row['case'])
source3=r/'analysis'/'mouse-handshake-original.jsonl'
mouse_rows=[json.loads(x) for x in source3.read_text().splitlines()]
assert len(mouse_rows)==256
f.rr_mouse_handshake_rx.argtypes=[C.POINTER(U8),U32,U32,U8,C.POINTER(U32)]
f.rr_mouse_handshake_rx.restype=C.c_int
registers=(0x5302c100,0x5302808c,0x53028004,0x5302800c,0x53028200,
           0x53028304,0x53028308,*range(0x53028540,0x53028560,4))
for row in mouse_rows:
    memory=(U8*992).from_buffer_copy(bytes.fromhex(row['before']))
    regs=(U32*15)()
    ret=f.rr_mouse_handshake_rx(memory,row['event'],row['crc_ok'],row['channel'],regs)
    assert ret==0,('mouse_unmodeled',row['case'])
    assert bytes(memory).hex()==row['after'],('mouse_memory',row['case'])
    expected=[int.from_bytes(bytes.fromhex(row['registers_after'][f'{a:x}']),'little') for a in registers]
    assert list(regs)==expected,('mouse_registers',row['case'])
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
result={'status':'PASS','original_instruction_comparisons':1024,
        'transition_cases':640,'offer_cases':128,'mouse_cases':256,
        'compiler':subprocess.run(['rtk','proxy','clang','--version'],check=True,capture_output=True,text=True).stdout,
        'compiler_flags':command[3:11],
        'sources':{str(p.relative_to(r)):sha(p) for p in [src/'handshake.c',src/'handshake.h',src/'mouse_handshake.c',src/'mouse_handshake.h',source,source2,source3]},
        'library_sha256':sha(lib),
        'limits':['host C compilation only, not Cortex-M target build',
                  'dongle state3 nonzero notification flag deliberately unresolved',
                  'mouse pairing flag zero, state0x14 only; inert MMIO registers',
                  'not complete radio firmware, no RF timing or hardware validation']}
(r/'analysis'/'portable-handshake-test-results.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(result,indent=2))
