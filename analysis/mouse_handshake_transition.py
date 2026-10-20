"""Mouse 1.20 handshake RX transition, original function 0x230227b8.
Memory image is [0x23002688,0x23002a68). MMIO is inert dictionary state;
it records register writes but never models peripheral events or RF timing.
Terminal state0x17 is not covered here. Pairing identity and state0x16 are modeled.
"""
BASE=0x23002688
REGISTERS=(0x5302c100,0x5302808c,0x53028004,0x5302800c,0x53028200,
           0x53028304,0x53028308,*range(0x53028540,0x53028560,4))
STEP_REGISTERS=(*REGISTERS,0x5302c200,0x5302c218,0x5302c220,0x5302c004)
def transition(memory: bytes, *, event: int, crc_ok: int, channel: int,
               extended_registers: bool=False, initial_registers=None):
    if len(memory)!=0x3e0:raise ValueError('Expected 992-byte RAM window')
    m=bytearray(memory);selected=STEP_REGISTERS if extended_registers else REGISTERS
    regs={a:(initial_registers or {}).get(a,0) for a in selected}
    def read(a,n):return int.from_bytes(m[a-BASE:a-BASE+n],'little')
    def write(a,v,n):m[a-BASE:a-BASE+n]=v.to_bytes(n,'little')
    def copy(a,data):m[a-BASE:a-BASE+len(data)]=data
    def reset():
        write(0x23002a04,0x13,4);write(0x23002a4a,0,2);write(0x23002a52,0,2)
        regs.update({0x53028004:1,0x5302800c:1,0x53028200:1,0x53028304:0x7f0000,0x53028308:0x800000})
        for a in range(0x53028540,0x53028560,4):regs[a]=0
    state=read(0x23002a04,4)
    if event!=5 or state not in (0x14,0x16,0x17):return bytes(m),regs
    if state==0x17:raise NotImplementedError('Terminal initialization not modeled')
    if state==0x16:
        regs[0x5302c100]=0
        if extended_registers:
            regs.update({0x5302c200:0,0x5302c218:0,0x5302c220:0,0x5302c004:1})
        write(0x23002a04,0x14,4);write(0x23002a4e,0x50001,4)
        return bytes(m),regs
    if crc_ok==1:regs[0x5302808c]=0
    packet=bytes(m[0x23002a56-BASE:0x23002a62-BASE]);phase=read(0x23002a4a,2)
    valid=crc_ok==1 and not(packet[1]&0xc0) and packet[0]==11
    valid=valid and {0:0x11,1:0x13,4:0x15}.get(phase)==packet[3]
    if not valid:reset();return bytes(m),regs
    seq=read(0x23002a2a,1);p=bytearray(packet)
    if phase==0:
        write(0x23002846,int.from_bytes(packet[8:10],'little'),2)
        write(0x23002a09,packet[8]>>7,1)
        write(0x23002992,(packet[8]>>6)&1,2)
        cap=read(0x2300279c,2)
        if not(cap&packet[8]&15):reset();return bytes(m),regs
        if read(0x2300298c,4)!=0:
            if read(0x23002990,4)==0x10000:reset();return bytes(m),regs
            write(0x230027b0,int.from_bytes(packet[4:8],'big'),4)
        write(0x23002838,500,4)
        write(0x23002a0a,int.from_bytes(packet[10:12],'big'),2)
        p[4]=(cap&15)|((read(0x23002a08,1)<<7)&255);p[5]=0
        p[6:10]=m[0x2300297e-BASE:0x23002982-BASE]
        next_phase=1;command=0x12
        regs[0x53028540]=432
    elif phase==1:
        write(0x23002798,packet[4]&15,2)
        write(0x230029d5,packet[6]&15,1);write(0x230029d6,packet[6]>>4,1)
        write(0x230027a2,(packet[4]>>4)&3,2)
        p[4:8]=bytes((read(0x230029ac,2)&255,0,0,0))
        next_phase=4;command=0x14
    else:
        selector=read(0x230027a2,2)
        if selector<2:
            copy(0x230029d7,packet[4:12]);write(0x230029df,4,1)
        elif selector in (2,3):
            copy(0x230026b9,packet[4:9])
            if selector==2:write(0x23002738,packet[9],4)
        p[4:6]=bytes(2);next_phase=6;command=0x16
    p[:4]=bytes((11,0,seq,command));copy(0x23002a56,p)
    seq=(seq+1)&255;write(0x23002a2a,1 if seq==8 else seq,1)
    write(0x23002a4a,next_phase,2);write(0x23002a04,0x17 if phase==4 else 0x16,4)
    write(0x23002a4e,0x50001,4);write(0x23002a52,0,2)
    regs[0x5302c100]=channel|0x80000000
    return bytes(m),regs
