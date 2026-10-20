from pathlib import Path
import ctypes as C,json,subprocess,hashlib,gzip,base64,struct
R=Path(__file__).resolve().parent.parent;P=R/'recovered-code/portable';A=R/'analysis';U=C.c_uint8;W=C.c_uint32;I=C.c_int32;Ptr=C.POINTER(U)
files=sorted(P.glob('*.c'));lib=P/'build/librr_recovered.dylib'
subprocess.run(['clang','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-O2','-dynamiclib',*[str(p) for p in files],'-o',str(lib)],check=True)
f=C.CDLL(str(lib))
class CPU(C.Structure):_fields_=[('priority',W),('exception',W),('entry',W),('arg0',W)]
class State(C.Structure):_fields_=[('mutex',W),('changed',W),('phase',W)]
f.rr_receiver_mutex_lock.argtypes=[Ptr,Ptr,W,C.c_uint64,C.POINTER(CPU),C.POINTER(State),C.POINTER(I)]
f.rr_receiver_mutex_unlock.argtypes=[Ptr,Ptr,W,C.POINTER(CPU),C.POINTER(State),C.POINTER(I)]
f.rr_receiver_mutex_resume.argtypes=[Ptr,Ptr,C.POINTER(CPU),C.POINTER(State),I,C.POINTER(I)]
for name in ['rr_receiver_switch_request_inert','rr_receiver_pendsv_body']:getattr(f,name).argtypes=[Ptr,Ptr,Ptr,C.POINTER(W)]
un=lambda s:gzip.decompress(base64.b64decode(s))
def r(b,o):return struct.unpack_from('<I',b,o)[0]
rows=[json.loads(x) for x in (A/'receiver-mutex-original.jsonl').open()];counts={}
for t in rows:
 if not t['boundary']:continue
 m=bytearray(un(t['ram_before']));rtc=bytearray(un(t['rtc_before']));mb=(U*len(m)).from_buffer(m);rb=(U*len(rtc)).from_buffer(rtc)
 c=CPU(t['initial_priority'],t['exception'],0,0);state=State(0x23007000,t['changed'],1);result=I(0x12345678)
 if t['op']==0:rc=f.rr_receiver_mutex_lock(mb,rb,0x23007000,int(t['timeout']),C.byref(c),C.byref(state),C.byref(result))
 elif t['op']==1:rc=f.rr_receiver_mutex_unlock(mb,rb,0x23007000,C.byref(c),C.byref(state),C.byref(result))
 else:
  assert t['op']==3
  rc=f.rr_receiver_mutex_resume(mb,rb,C.byref(c),C.byref(state),I(t['pendresult']),C.byref(result))
 assert rc==1 and (c.entry,c.arg0)==(t['boundary'],t['arg0']) and result.value==0x12345678
 assert m==un(t['ram_after']) and rtc==un(t['rtc_after'])
 old=r(m,0x7170)-0x23000000;target=r(m,0x717c)-0x23000000
 assert 0<=old<len(m)-0x90 and 0<=target<len(m)-0x90 and target!=old
 expected=[r(m,target+0x30+4*k) for k in range(8)]
 psp=r(m,target+0x50);limit=r(m,target+0x74);tls=r(m,target+0x84);priority=r(m,target+0x88)
 nv=bytearray(4096);scratch=bytearray(32);nb=(U*4096).from_buffer(nv);sb=(U*32).from_buffer(scratch);cpu=(W*24)()
 cpu[0]=c.arg0;cpu[13]=0x2302f000;cpu[14]=0x2302df01;cpu[15]=c.entry;cpu[16]=0x2300e000;cpu[18]=c.priority
 live=[0x41000000+t['case']*16+k for k in range(8)]
 for k,v in enumerate(live):cpu[4+k]=v
 assert f.rr_receiver_switch_request_inert(mb,nb,sb,cpu)==0
 assert cpu[0]==0xfffffff5 and r(m,old+0x88)==c.arg0 and r(m,old+0x8c)==0xfffffff5
 # Explicit exception-handler entry. Request ran with inert ICSR; this is
 # component composition, not an actual suspended request/exception return.
 cpu[14]=0xfffffffd;cpu[15]=0xe06124c
 assert f.rr_receiver_pendsv_body(mb,nb,sb,cpu)==1
 assert list(cpu)[4:12]==expected and cpu[16]==psp and cpu[17]==limit and cpu[18]==priority
 assert r(m,0x7170)==0x23000000+target and r(m,0x6930)==tls and r(m,target+0x88)==0
 assert [r(m,old+0x30+4*k) for k in range(8)]==live and r(m,old+0x50)==0x2300e000
 assert cpu[15]==0xe061286 and cpu[14]==0xfffffffd and result.value==0x12345678
 counts[str(t['op'])]=counts.get(str(t['op']),0)+1
paths=files+list(P.glob('*.h'))+[Path(__file__),lib,A/'receiver-mutex-original.jsonl']
d={'status':'PASS','mutex_CPU_boundaries':sum(counts.values()),'operation_counts':counts,'sources':{str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},'not_added_to_original_input_count':True,'limits':['Existing392 mutex original fixtures reused; no new original execution cases','Real reconstructed mutex output feeds CPU request and PendSV body without replacing selected thread or list state','Live registers/PSP and handler entry explicitly supplied; incoming saved context comes from fixture RAM','Request runs inert then explicit handler segment, not real preemption or resumed lock acquisition','Stops before BX LR; no hardware exception return, RTOS task execution or RF proof']}
(A/'receiver-mutex-context-comparison.json').write_text(json.dumps(d,indent=2)+'\n');print(json.dumps({k:v for k,v in d.items() if k!='sources'},indent=2))
