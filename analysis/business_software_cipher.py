"""Static reconstruction of mouse23020D50 and dongle2302003C.
XXTEA/Corrected Block TEA structure identified from full update expression.
This module handles only proven business lengths8/16, not arbitrary buffers.
No device I/O; this is not original-source recovery or RF verification.
"""
import struct
from pathlib import Path
MASK=0xffffffff
DELTA=0x9e3779b9
TABLE_OFFSETS={"mouse":0x2c904,"dongle":0x1ba74}


def select_key(image: bytes, side: str, connection_base: int) -> bytes:
    off=TABLE_OFFSETS[side]+((connection_base&15)<<4)
    key=image[off:off+16]
    if len(key)!=16: raise ValueError("image too short")
    return key


def _mx(z,y,total,p,e,k):
    left=(((z>>5)^((y<<2)&MASK))+((y>>3)^((z<<4)&MASK)))&MASK
    right=((total^y)+(k[(p&3)^e]^z))&MASK
    return left^right


def transform(payload: bytes,key: bytes,*,decrypt=False) -> bytes:
    if len(payload) not in (8,16) or len(key)!=16:
        raise ValueError("recovered business contract:8/16 byte payload,16 byte key")
    n=len(payload)//4;v=list(struct.unpack('<'+'I'*n,payload));k=struct.unpack('<4I',key)
    rounds=6+52//n
    if not decrypt:
        total=0;z=v[-1]
        for _ in range(rounds):
            total=(total+DELTA)&MASK;e=(total>>2)&3
            for p in range(n-1):
                y=v[p+1];v[p]=(v[p]+_mx(z,y,total,p,e,k))&MASK;z=v[p]
            p=n-1;y=v[0];v[p]=(v[p]+_mx(z,y,total,p,e,k))&MASK;z=v[p]
    else:
        total=(rounds*DELTA)&MASK;y=v[0]
        for _ in range(rounds):
            e=(total>>2)&3
            for p in range(n-1,0,-1):
                z=v[p-1];v[p]=(v[p]-_mx(z,y,total,p,e,k))&MASK;y=v[p]
            z=v[-1];v[0]=(v[0]-_mx(z,y,total,0,e,k))&MASK;y=v[0]
            total=(total-DELTA)&MASK
    return struct.pack('<'+'I'*n,*v)


def encrypt(payload: bytes,key: bytes) -> bytes:
    return transform(payload,key)


def decrypt(payload: bytes,key: bytes) -> bytes:
    return transform(payload,key,decrypt=True)
