"""Recovered state transitions of original dongle 1.20 function 0x230223f0.

Pure memory model, no hardware access. Inputs are exact per-slot bytes starting
at 0x230033e8 + slot*0xf84, plus explicit globals. The notification-producing
terminal branch (state3 with nonzero flag at offset0x14) is not implemented.
The model preserves all bytes not written by these original paths.
"""
from dataclasses import dataclass

@dataclass(frozen=True)
class Transition:
    memory: bytes
    selected_mode: int
    result: int

def transition(memory: bytes, incoming: bytes, *, slot: int, status0: int,
               status1: int, primary_cap: int, fallback_cap: int,
               selector: int, index0: int, index1: int, frequencies: bytes,
               mask: bytes, extra: int, selected_mode: int) -> Transition:
    if len(memory)!=0xe0 or len(incoming)!=12 or len(frequencies)!=8 or len(mask)!=5:
        raise ValueError('Exact saved memory and packet lengths required')
    m=bytearray(memory); rx=incoming
    u16=lambda o:int.from_bytes(m[o:o+2],'little')
    u32=lambda o:int.from_bytes(m[o:o+4],'little')
    def put(o,v,n):m[o:o+n]=int(v).to_bytes(n,'little')
    def finish(result):return Transition(bytes(m),selected_mode,result)
    state=u16(0xc8)
    if rx[1]&0x80:return finish(0)
    if rx[0]!=11:return finish(0)
    if state==0:
        if rx[3]!=0x12:return finish(0)
        if u32(0x14)!=0 and u16(6)!=0xffff and rx[6:8]!=m[6:8]:return finish(0)
        m[0x84]=rx[4]>>7 # Written even when capability intersection is empty.
        cap=primary_cap if status0<=2 and status1<=2 else fallback_cap
        common=rx[4]&cap&15
        if not common:return finish(0)
        m[6:10]=rx[6:10]
        m[10:14]=bytes((rx[7],rx[6],rx[9],rx[8]))
        selected_mode=next(v for v in (8,4,1,2) if common&v)
        m[0xd4:0xdb]=bytes((11,(slot&1)<<6,m[0xa7],0x13,
                           selected_mode|((selector&3)<<4),0,
                           ((index0&15)|(index1<<4))&255))
        put(0xc8,2,2)
    elif state==2:
        if rx[3]!=0x14:return finish(0)
        put(0x34,rx[4],2)
        m[0xd4:0xd8]=bytes((11,(slot&1)<<6,m[0xa7],0x15))
        if selector in (0,1):m[0xd8:0xe0]=frequencies
        elif selector in (2,3):
            m[0xd8:0xdd]=mask
            if selector==2:m[0xdd]=extra&255
        # For any other uint16 selector the original writes no payload bytes.
        put(0xc8,3,2)
    elif state==3:
        if rx[3]!=0x16:return finish(0)
        if u32(0x14)!=0:
            raise NotImplementedError('Notification/queue side effects not modeled')
        put(0xc8,6,2);put(0xcc,0,4)
        return finish(2)
    else:return finish(0)
    m[0xa7]=(m[0xa7]+1)&255
    if m[0xa7]==8:m[0xa7]=1
    put(0xcc,0x40000,4)
    return finish(1)
