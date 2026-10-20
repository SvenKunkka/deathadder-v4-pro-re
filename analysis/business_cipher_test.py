"""Static reconstruction tests, including newly compiled HOST C oracle.
Does not execute original ARM firmware or interact with any device.
"""
from pathlib import Path
import ctypes as C
import tempfile,subprocess,struct,random,json,hashlib
from business_software_cipher import encrypt,decrypt,select_key
base=Path(__file__).parent
mouse=(base.parent/'firmware-extracted-1.20/Suit2FWData__radio_radio.bin').read_bytes()
dongle=(base.parent/'firmware-extracted-1.20/Suit1FWData__radio_radio.bin').read_bytes()
count=0

def eq(a,b):
    global count
    assert a==b,(a,b)
    count+=1

vectors=[(bytes(range(8)),bytes(range(16)),bytes.fromhex('1f6acf9e18e5c6cf')),
         (bytes(range(16)),bytes(range(16)),bytes.fromhex('557024c2068744014b13416b0a583175'))]
with tempfile.TemporaryDirectory(prefix='mode4-host-cipher-') as temp:
    lib=Path(temp)/'oracle.dylib'
    subprocess.run(['/usr/bin/cc','-O2','-shared','-fPIC',str(base/'business_cipher_oracle.c'),'-o',str(lib)],check=True,capture_output=True)
    dll=C.CDLL(str(lib))
    def cfn(name,data,key):
        n=len(data)//4;v=(C.c_uint32*n)(*struct.unpack('<'+'I'*n,data))
        k=(C.c_uint32*4)(*struct.unpack('<4I',key))
        getattr(dll,name)(v,n,k)
        return struct.pack('<'+'I'*n,*v)
    for plain,key,cipher in vectors:
        eq(encrypt(plain,key),cipher);eq(cfn('encrypt_words',plain,key),cipher)
        eq(decrypt(cipher,key),plain);eq(cfn('decrypt_words',cipher,key),plain)
    rng=random.Random(0x54a20)
    for selector in range(256):
        km=select_key(mouse,'mouse',selector);kd=select_key(dongle,'dongle',selector)
        eq(km,kd);eq(km,select_key(mouse,'mouse',selector&15))
    cases=0
    for selector in range(16):
        km=select_key(mouse,'mouse',selector);kd=select_key(dongle,'dongle',selector)
        for n in [8,16]:
            for _ in range(64):
                plain=rng.randbytes(n);cipher=encrypt(plain,km)
                eq(cipher,cfn('encrypt_words',plain,km))
                eq(decrypt(cipher,kd),plain)
                eq(cfn('decrypt_words',cipher,kd),plain)
                cases+=1
result={'status':'passed','assertions':count,'random_differential_cases':cases,
 'table_sha256':hashlib.sha256(mouse[0x2c904:0x2ca04]).hexdigest(),
 'fixed_vectors':[{'plaintext':p.hex(),'key':k.hex(),'ciphertext':c.hex()} for p,k,c in vectors],
 'validation_level':'Python vs newly authored native-host C + roundtrip, NOT original ARM execution or RF capture'}
(base/'business-cipher-test-results.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(result,indent=2))
