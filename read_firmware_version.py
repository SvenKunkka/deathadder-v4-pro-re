"""Bounded firmware-version GET, using the upstream OpenRazer packet definition.
Does not change settings, update firmware, or enter bootloader mode.
"""
import ctypes as C
import datetime
import functools
import json
import operator
from pathlib import Path
import time

class Info(C.Structure):
    pass
Info._fields_ = [('path', C.c_char_p), ('vendor_id', C.c_ushort),
    ('product_id', C.c_ushort), ('serial_number', C.c_wchar_p),
    ('release_number', C.c_ushort), ('manufacturer_string', C.c_wchar_p),
    ('product_string', C.c_wchar_p), ('usage_page', C.c_ushort),
    ('usage', C.c_ushort), ('interface_number', C.c_int),
    ('next', C.POINTER(Info)), ('bus_type', C.c_int)]
lib = C.CDLL('/opt/homebrew/lib/libhidapi.dylib')
lib.hid_enumerate.argtypes = [C.c_ushort, C.c_ushort]
lib.hid_enumerate.restype = C.POINTER(Info)
lib.hid_free_enumeration.argtypes = [C.POINTER(Info)]
lib.hid_open_path.argtypes = [C.c_char_p]
lib.hid_open_path.restype = C.c_void_p
lib.hid_close.argtypes = [C.c_void_p]
lib.hid_error.argtypes = [C.c_void_p]
lib.hid_error.restype = C.c_wchar_p
for name in ('hid_send_feature_report', 'hid_get_feature_report'):
    f = getattr(lib, name)
    f.argtypes = [C.c_void_p, C.POINTER(C.c_ubyte), C.c_size_t]
    f.restype = C.c_int
lib.hid_darwin_set_open_exclusive(0)
head = lib.hid_enumerate(0x1532, 0x00be)
cur = head
path = None
while cur:
    i = cur.contents
    if i.usage_page == 1 and i.usage == 2:
        path = bytes(i.path)
        break
    cur = i.next
lib.hid_free_enumeration(head)
if path is None:
    raise SystemExit('Target mouse interface not found')
device = lib.hid_open_path(path)
if not device:
    raise SystemExit(lib.hid_error(None))
record = {'time_utc': datetime.datetime.now(datetime.timezone.utc).isoformat(),
          'vid_pid': '1532:00BE', 'query': 'firmware-version GET 00:81',
          'source': 'OpenRazer razer_chroma_standard_get_firmware_version; transaction 0x1f'}
try:
    report = bytearray(90)
    report[1] = 0x1f
    report[5] = 2
    report[7] = 0x81
    report[88] = functools.reduce(operator.xor, report[2:88], 0)
    packet = bytes([0]) + report
    tx = (C.c_ubyte * len(packet)).from_buffer_copy(packet)
    record['request_hex'] = packet.hex()
    record['send_result'] = lib.hid_send_feature_report(device, tx, len(tx))
    if record['send_result'] < 0:
        record['error'] = lib.hid_error(device)
    else:
        time.sleep(0.1)
        rx = (C.c_ubyte * 91)()
        count = lib.hid_get_feature_report(device, rx, len(rx))
        record['read_result'] = count
        record['response_hex'] = bytes(rx[:max(count, 0)]).hex()
        if count >= 90:
            data = bytes(rx[1:91]) if count == 91 else bytes(rx[:90])
            record['status'] = data[0]
            record['checksum_valid'] = data[88] == functools.reduce(operator.xor, data[2:88], 0)
            record['command_matches'] = data[6:8] == bytes([0, 0x81])
            if record['status'] == 2 and record['checksum_valid'] and record['command_matches']:
                record['version_argument_bytes'] = list(data[8:12])
                record['version_major_minor'] = f'{data[8]}.{data[9]}'
        else:
            record['error'] = lib.hid_error(device)
finally:
    lib.hid_close(device)
Path(__file__).with_name('firmware-version-live.json').write_text(json.dumps(record, indent=2))
print(json.dumps(record, indent=2))
