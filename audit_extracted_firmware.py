#!/usr/bin/env python3
"""Validate byte provenance and produce compact radio/application loading hints."""
import pathlib,json,struct
from extract_managed_firmware import OUT,INPUT,sha
from extract_suit_payloads import walk
def main():
    manifests=json.loads((OUT/'suit-extraction-manifest.json').read_text());out=[]
    source=INPUT/'DeviceUpdater.resources';src=source.read_bytes()
    for m in manifests:
        suit=pathlib.Path(m['file']).read_bytes();assert sha(suit)==m['sha256']
        chunk_ranges=[];cursor=0
        for chunk in m['chunks']:
            data=src[chunk['source_offset']:chunk['source_offset']+chunk['size']]
            assert sha(data)==chunk['sha256'];assert suit[cursor:cursor+len(data)]==data
            chunk_ranges.append((cursor,cursor+len(data),chunk));cursor+=len(data)
        assert cursor==len(suit)
        for p in m['payloads']:
            data=pathlib.Path(p['file']).read_bytes();start=p['suit_payload_offset'];end=start+len(data)
            assert sha(data)==p['sha256'];assert data==suit[start:end]
            segments=[]
            for cs,ce,c in chunk_ranges:
                lo=max(start,cs);hi=min(end,ce)
                if lo<hi:segments.append({'payload_offset':lo-start,'source_offset':c['source_offset']+lo-cs,'length':hi-lo,'resource_name':c['name']})
            assert b''.join(src[s['source_offset']:s['source_offset']+s['length']]for s in segments)==data
            row={**p,'original_source_file':str(source),'original_source_sha256':sha(src),'original_source_segments':segments,'provenance_verified':True}
            for key in ('radio','application'):
                if pathlib.Path(p['file']).name.endswith(f'__{key}_{key}.bin'):
                    tree=json.loads((OUT/(m['name']+'__'+key+'-cbor.json')).read_text())
                    memories=[];digests=[]
                    for node in walk(tree):
                        if node['major']==4 and node.get('items') and node['items'][0].get('decoded_bstr',{}).get('value')=='MEM':
                            memories.append({'offset_in_suit':node['offset'],'components':[i.get('decoded_bstr',{}).get('value')for i in node['items']]})
                        if node['major']==2 and node.get('length')==32 and suit[node['payload_offset']:node['payload_offset']+32].hex()==sha(data):digests.append(node['payload_offset'])
                    bases={v['components'][2]for v in memories};assert len(bases)==1;base=bases.pop();vectors=struct.unpack_from('<16I',data)
                    assert base<=vectors[1]-1<base+len(data);assert digests
                    row.update({'memory_components':memories,'load_base':hex(base),'initial_sp':hex(vectors[0]),'reset_vector':hex(vectors[1]),'reset_file_offset':hex(vectors[1]-1-base),'vector_words':[hex(v)for v in vectors],'raw_sha256_matches_manifest_digest_at_suit_offsets':digests,'architecture_inference':'ARM Cortex-M / Thumb little-endian, from vector table and nRF54H20 core descriptors'})
                    print(pathlib.Path(p['file']).name,hex(base),len(data),sha(data),digests)
            out.append(row)
    (OUT/'firmware-provenance-audit.json').write_text(json.dumps(out,indent=2)+'\n')
    print('Verified',len(out),'integrated payloads against original .resources byte ranges')
if __name__=='__main__':main()
