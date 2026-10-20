/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e075804. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e07547e) */

undefined4 FUN_0e075804(int param_1,uint param_2)

{
  bool bVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
  puVar2 = (uint *)((short)(ushort)*(byte *)(param_1 + 4) * 0xa4 + 0x94 + DAT_0e075818);
  uVar4 = *puVar2;
  if (-1 < (int)((uVar4 >> (param_2 & 0xff)) << 0x1f)) {
    uVar3 = 1 << (param_2 & 0xff);
    bVar1 = false;
    if (*puVar2 == uVar4) {
      *puVar2 = uVar4 | uVar3;
      bVar1 = true;
    }
    while (!bVar1) {
      bVar1 = false;
      if (*puVar2 == *puVar2) {
        *puVar2 = uVar3 | *puVar2;
        bVar1 = true;
      }
    }
    return DAT_0e075480;
  }
  return DAT_0e075484;
}


