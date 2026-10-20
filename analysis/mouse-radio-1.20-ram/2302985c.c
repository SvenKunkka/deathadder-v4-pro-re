/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302985c. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x23028cde) */

int FUN_2302985c(int param_1,uint param_2)

{
  ushort uVar1;
  bool bVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  ushort *puVar7;
  
  iVar6 = (uint)*(byte *)(param_1 + 4) * 0x52 +
          ((uint)(byte)(&DAT_0e09b6b0)[param_2 >> 5] + (param_2 & 0x1f) & 0xff) + 8;
  uVar1 = *(ushort *)(&DAT_2300130c + iVar6 * 2);
  if ((int)((uint)uVar1 << 0x17) < 0) {
    uVar4 = (uVar1 & 0x1fff) >> 9;
    *(ushort *)(&DAT_2300130c + iVar6 * 2) = uVar1 & 0xe0ff;
    iVar6 = (uint)*(byte *)(param_1 + 4) * 0xa4;
    puVar7 = (ushort *)(iVar6 + 0x2300131a);
    while( true ) {
      puVar7 = puVar7 + 1;
      if (((int)((uint)*puVar7 << 0x17) < 0) && (uVar4 == (*puVar7 & 0x1fff) >> 9)) break;
      if (puVar7 == (ushort *)(iVar6 + 0x2300139a)) {
        *(undefined4 *)(&DAT_2300130c + (uint)*(byte *)(param_1 + 4) * 0xa4 + uVar4 * 8) = 0;
        puVar3 = (uint *)(&DAT_230013a4 + (uint)*(byte *)(param_1 + 4) * 0xa4);
        uVar5 = *puVar3;
        if (-1 < (int)((uVar5 >> uVar4) << 0x1f)) {
          bVar2 = false;
          if (*puVar3 == uVar5) {
            *puVar3 = uVar5 | 1 << uVar4;
            bVar2 = true;
          }
          while (!bVar2) {
            bVar2 = false;
            if (*puVar3 == *puVar3) {
              *puVar3 = 1 << uVar4 | *puVar3;
              bVar2 = true;
            }
          }
          return 0xbad0000;
        }
        return 0xbad0004;
      }
    }
  }
  return param_1;
}


