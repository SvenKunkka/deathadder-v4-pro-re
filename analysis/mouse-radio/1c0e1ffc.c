/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e1ffc. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x1c0e147e) */

int FUN_1c0e1ffc(int param_1,uint param_2)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  
  iVar3 = DAT_1c0e2080;
  iVar7 = (uint)*(byte *)(param_1 + 4) * 0x52 +
          ((uint)*(byte *)(DAT_1c0e207c + (param_2 >> 5)) + (param_2 & 0x1f) & 0xff) + 8;
  uVar1 = *(ushort *)(DAT_1c0e2080 + iVar7 * 2);
  if ((int)((uint)uVar1 << 0x17) < 0) {
    uVar5 = (uVar1 & 0x1fff) >> 9;
    *(ushort *)(DAT_1c0e2080 + iVar7 * 2) = uVar1 & 0xe0ff;
    iVar7 = (uint)*(byte *)(param_1 + 4) * 0xa4;
    puVar8 = (ushort *)(iVar7 + 0xe + iVar3);
    while( true ) {
      puVar8 = puVar8 + 1;
      if (((int)((uint)*puVar8 << 0x17) < 0) && (uVar5 == (*puVar8 & 0x1fff) >> 9)) break;
      if (puVar8 == (ushort *)(iVar3 + 0x8e + iVar7)) {
        *(undefined4 *)(iVar3 + (uint)*(byte *)(param_1 + 4) * 0xa4 + uVar5 * 8) = 0;
        puVar4 = (uint *)((uint)*(byte *)(param_1 + 4) * 0xa4 + iVar3 + 0x98);
        uVar6 = *puVar4;
        if (-1 < (int)((uVar6 >> uVar5) << 0x1f)) {
          bVar2 = false;
          if (*puVar4 == uVar6) {
            *puVar4 = uVar6 | 1 << uVar5;
            bVar2 = true;
          }
          while (!bVar2) {
            bVar2 = false;
            if (*puVar4 == *puVar4) {
              *puVar4 = 1 << uVar5 | *puVar4;
              bVar2 = true;
            }
          }
          return DAT_1c0e1480;
        }
        return DAT_1c0e1484;
      }
    }
  }
  return param_1;
}


