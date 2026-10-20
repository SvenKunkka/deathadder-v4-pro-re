#!/usr/bin/env python3
"""Decode definite-length CBOR losslessly by offsets, extract SUIT integrated payloads."""
import pathlib, json, re, struct
from extract_managed_firmware import OUT,sha,inspect_bytes
def parse(b,p=0,base=0):
    start=p;v=b[p];p+=1;major=v>>5;ai=v&31
    if ai<24:n=ai
    elif ai in (24,25,26,27):
        ln=1<<(ai-24);n=int.from_bytes(b[p:p+ln],'big');p+=ln
    else:raise ValueError('indefinite CBOR unsupported')
    node={'offset':base+start,'major':major,'argument':n}
    if major in (0,1,7):node['value']=n if major!=1 else -1-n
    elif major in (2,3):
        assert p+n<=len(b);v=b[p:p+n];node['payload_offset']=base+p;node['length']=n
        if major==3:node['value']=v.decode('utf-8')
        else:
            node['sha256']=sha(v);node['head_hex']=v[:32].hex()
            if n<=2048:
                try:
                    child,end=parse(v,0,base+p)
                    if end==len(v):node['decoded_bstr']=child
                except (ValueError,AssertionError,IndexError,UnicodeError,RecursionError):pass
        p+=n
    elif major==4:
        node['items']=[]
        for _ in range(n):
            child,p=parse(b,p,base);node['items'].append(child)
    elif major==5:
        node['entries']=[]
        for _ in range(n):
            k,p=parse(b,p,base);v,p=parse(b,p,base);node['entries'].append({'key':k,'value':v})
    elif major==6:node['tagged'],p=parse(b,p,base)
    else:raise ValueError(major)
    node['end']=base+p;return node,p
def walk(n):
    yield n
    for k in ('decoded_bstr','tagged'):
        if k in n:yield from walk(n[k])
    for i in n.get('items',[]):yield from walk(i)
    for e in n.get('entries',[]):
        yield from walk(e['key']);yield from walk(e['value'])
def main():
    manifest=json.loads((OUT/'extraction-manifest.json').read_text()); es=manifest['resource_sets'][-1]['parsed']['entries'];result=[]
    for suit in (1,2):
        prefix=f'Suit{suit}FWData';vs=[]
        for e in es:
            mat=re.fullmatch(prefix+r'(\d+)',e['name'])
            if mat:vs.append((int(mat[1]),e))
        vs.sort();assert [i for i,e in vs]==list(range(len(vs)))
        b=b''.join(pathlib.Path(e['output_file']).read_bytes()for i,e in vs);dst=OUT/(prefix+'.bin');dst.write_bytes(b)
        declared=next(e['numeric_value']for e in es if e['name']==f'Suit{suit}FWFileSize');assert len(b)==declared
        n,end=parse(b);assert end==len(b)
        (OUT/(prefix+'-cbor.json')).write_text(json.dumps(n,indent=2)+'\n')
        entry={'name':prefix,'file':str(dst),**inspect_bytes(b),'chunks':[{'index':i,'name':e['name'],'source_offset':e['payload_parent_offset'],'size':e['size'],'sha256':e['sha256']}for i,e in vs],'payloads':[]}
        def extract(node,label,parent):
            for e in node.get('entries',[]):
                key=e['key'].get('value');v=e['value']
                if isinstance(key,str) and (key.startswith('#') or key.startswith('file://')) and v['major']==2:
                    o=v['payload_offset'];ln=v['length'];part=b[o:o+ln]
                    keyname=key[1:] if key.startswith('#') else key[7:]
                    path=OUT/(prefix+'__'+label+keyname+('' if keyname.endswith('.bin') else '.bin'));path.write_bytes(part)
                    row={'key':key,'parent_file':parent,'suit_payload_offset':o,'file':str(path),**inspect_bytes(part)};entry['payloads'].append(row)
                    row['encoding']='raw payload'
                    try:
                        sub,subend=parse(part,0,o)
                        if subend==len(part):
                            row['encoding']='CBOR';(OUT/(path.stem+'-cbor.json')).write_text(json.dumps(sub,indent=2)+'\n')
                            for inner in walk(sub):extract(inner,label+key[1:]+'_',str(path))
                    except (ValueError,AssertionError,IndexError,UnicodeError,RecursionError):row['encoding']='opaque/raw payload'
        for node in walk(n):extract(node,'',str(dst))
        result.append(entry)
        print(prefix,len(b),[(r['key'],r['size'],r['suit_payload_offset'],r.get('encoding'))for r in entry['payloads']])
    (OUT/'suit-extraction-manifest.json').write_text(json.dumps(result,indent=2)+'\n')
if __name__=='__main__':main()
