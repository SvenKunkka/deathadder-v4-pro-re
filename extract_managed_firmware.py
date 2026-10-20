#!/usr/bin/env python3
"""Static PE manifest/.resources extraction. Does not load target CLR or code."""
import pathlib, struct, hashlib, json, re, collections, math, os
ROOT=pathlib.Path(__file__).resolve().parent
VERSION=os.environ.get('TASK_FIRMWARE_VERSION','')
SUFFIX='-'+VERSION if VERSION else ''
OUT=ROOT/('firmware-extracted'+SUFFIX)
INPUT=ROOT/('updater-extracted'+SUFFIX)
def sha(b): return hashlib.sha256(b).hexdigest()
def u32(b,p): return struct.unpack_from('<I',b,p)[0]
def varint(b,p):
    n=s=0
    while True:
        v=b[p];p+=1;n|=(v&127)<<s
        if not v&128:return n,p
        s+=7
        assert s<35
def string(b,p,enc='utf-8'):
    n,p=varint(b,p);return b[p:p+n].decode(enc),p+n
def safe(s): return re.sub(r'[^A-Za-z0-9._-]','_',s)
def inspect_bytes(b):
    c=collections.Counter(b)
    entropy=-sum(n/len(b)*math.log2(n/len(b)) for n in c.values()) if b else 0
    return {'size':len(b),'sha256':sha(b),'head_hex':b[:64].hex(),'entropy':entropy}
def parse_resources(b,parent,parent_offset,label):
    assert u32(b,0)==0xbeefcace
    p=12+u32(b,8)
    ver,n,nt=struct.unpack_from('<III',b,p);p+=12
    assert ver==2
    types=[]
    for _ in range(nt):
        s,p=string(b,p);types.append(s)
    p=(p+7)&~7
    hashes=struct.unpack_from('<'+'I'*n,b,p);p+=n*4
    names=struct.unpack_from('<'+'I'*n,b,p);p+=n*4
    ds=u32(b,p);p+=4;ns=p
    rows=[]
    for ix,noff in enumerate(names):
        name,q=string(b,ns+noff,'utf-16le')
        doff=u32(b,q);pos=ds+doff;tc,q=varint(b,pos)
        row={'name':name,'type_code':tc,'record_offset':pos,'parent_file':str(parent),'parent_offset':parent_offset+pos}
        if tc==1:
            v,q=string(b,q);row['string_value']=v
        elif tc in (8,9):
            row['numeric_value']=struct.unpack_from('<i' if tc==8 else '<I',b,q)[0]
        elif tc in (10,11):
            row['numeric_value']=struct.unpack_from('<q' if tc==10 else '<Q',b,q)[0]
        elif tc in (32,33):
            ln=u32(b,q);q+=4;data=b[q:q+ln];assert len(data)==ln
            path=OUT/(safe(label)+'__'+safe(name)+'.bin');path.write_bytes(data)
            row.update(inspect_bytes(data));row.update({'output_file':str(path),'payload_parent_offset':parent_offset+q,'resource_payload_offset':q,'encoding':'plain .NET byte[]' if tc==32 else 'plain .NET stream'})
        elif tc>=64:
            row['serialized_type']=types[tc-64]
        rows.append(row)
    return {'label':label,'types':types,'count':n,'data_section_offset':ds,'entries':rows}
def main():
    OUT.mkdir(exist_ok=True)
    ev=json.loads((OUT/'rea-managed-evidence.json').read_text())
    src=INPUT/'WirelessCustomerFWUNew.exe';b=src.read_bytes()
    pe=u32(b,0x3c);ns=struct.unpack_from('<H',b,pe+6)[0];opt=struct.unpack_from('<H',b,pe+20)[0];st=pe+24+opt
    sections=[]
    for i in range(ns):
        p=st+i*40;name=b[p:p+8].rstrip(b'\0').decode();vs,rva,rs,rp=struct.unpack_from('<IIII',b,p+8);sections.append((name,vs,rva,rs,rp))
    def rva_offset(rva):
        for _,vs,base,rs,rp in sections:
            if base<=rva<base+rs:return rp+rva-base
        raise ValueError(rva)
    nr=ev['normalized_result'];base=rva_offset(nr['pe']['cli']['resources_rva'])
    manifest={'method':'Static PE resource RVA mapping + .NET resources version 2 parser; no target execution','rea_evidence_id':ev['evidence_id'],'source':str(src),'source_sha256':sha(b),'cli_resources_file_offset':base,'resource_sets':[]}
    for r in nr['resources']:
        off=base+r['declared_offset'];ln=u32(b,off);data=b[off+4:off+4+ln]
        assert sha(data)==r['data_sha256']
        dst=OUT/r['name'];dst.write_bytes(data)
        entry={'name':r['name'],'parent_file':str(src),'parent_offset':off+4,'size':ln,'sha256':sha(data),'file':str(dst),'parsed':parse_resources(data,src,off+4,r['name'])}
        manifest['resource_sets'].append(entry)
    src=INPUT/'DeviceUpdater.resources';b=src.read_bytes()
    manifest['resource_sets'].append({'name':src.name,'parent_file':str(src),'parent_offset':0,'size':len(b),'sha256':sha(b),'parsed':parse_resources(b,src,0,src.name)})
    (OUT/'extraction-manifest.json').write_text(json.dumps(manifest,indent=2,ensure_ascii=False)+'\n')
    for group in manifest['resource_sets']:
        for e in group['parsed']['entries']:
            if 'output_file'in e and e['size']!=1024: print(group['name'],json.dumps(e,ensure_ascii=False))
if __name__=='__main__':main()
