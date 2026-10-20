#!/usr/bin/env python3
"""Explicit host boundary contracts, separate from original instruction cases."""
import ctypes as C,json,zlib,base64
from pathlib import Path
A=Path(__file__).resolve().parent;U=C.c_uint8;W=C.c_uint32;P=C.POINTER(U)
f=C.CDLL(str(A/'libmouse_mode4_runtime.dylib'));f.rr_mouse_mode4_radio_lifecycle.argtypes=[P,P,P,P,C.POINTER(W),C.POINTER(W)]
row=next(json.loads(x) for x in (A/'mouse-mode4-ack-original.jsonl').read_text().splitlines() if json.loads(x)['case']==1)
def un(x):return zlib.decompress(base64.b64decode(x))
def p32(m,a,v):
 for i in range(4):m[a+i]=(v>>(i*8))&255
def u32(m,a):return int.from_bytes(bytes(m[a:a+4]),'little')
results=[]
for case in range(4):
 mem={k:(U*len(un(row[k+'_before_z']))).from_buffer_copy(un(row[k+'_before_z'])) for k in ['ram','radio','timer','rtc','clock']};m=mem['ram'];nv=W(0x12345678);oldread=m[0x2adf];oldseq=m[0x2a1e]
 if case==0:p32(m,0x6b68,0x23001235);expected=-2
 elif case==1:p32(m,0x15d4,0x23001235);expected=-2
 elif case==2:p32(m,0x15c8,0x23006000);expected=-3
 else:p32(mem['rtc'],0x774,0x40000000);expected=-4
 callback=u32(m,0x6b68);rc=f.rr_mouse_mode4_radio_lifecycle(m,mem['radio'],mem['timer'],mem['rtc'],C.cast(mem['clock'],C.POINTER(W)),C.byref(nv))
 assert rc==expected and u32(m,0x6b68)==callback and m[0x2adf]==(oldread+1)%32 and m[0x2a1e]==(1 if ((oldseq+1)&255)==8 else (oldseq+1)&255) and nv.value==0x12345678
 if case:assert u32(m,0x15b0)==0 and u32(m,0x15b4)==0
 results.append({'case':case,'return':rc,'callback_retained':True,'queue_pop_and_prior_sequence_preserved':True,'timer_unlinked':bool(case)})
report={'status':'PASS','boundary_cases':4,'cases':results,'original_cases_added':0,'limits':['host boundary behavior, not original execution of unknown callbacks/waiter scheduler/busy RTC']}
(A/'mouse-mode4-runtime-boundaries.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))
