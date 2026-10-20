/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d47c. Types and names are inferred; NOT original source. */

uint FUN_0e05d47c(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar6 = LZCOUNT(param_2);
  iVar5 = 0x1f - iVar6;
  iVar9 = param_1 + iVar5 * 4;
  uVar8 = *(uint *)(iVar9 + 0x10);
  if (uVar8 != 0) {
    iVar10 = 3;
    uVar7 = uVar8;
    do {
      iVar11 = param_1 + uVar7 * 8;
      if (param_2 <= *(ushort *)(iVar11 + 2) >> 1) goto LAB_0e05d4d4;
      uVar7 = (uint)*(ushort *)(iVar11 + 6);
      iVar10 = iVar10 + -1;
      *(uint *)(iVar9 + 0x10) = uVar7;
    } while ((iVar10 != 0) && (uVar8 != uVar7));
  }
  uVar8 = -1 << (0x20U - iVar6 & 0xff) & *(uint *)(param_1 + 0xc);
  if (uVar8 == 0) {
    return 0;
  }
  bVar2 = (byte)uVar8;
  bVar3 = (byte)(uVar8 >> 8);
  bVar4 = (byte)(uVar8 >> 0x10);
  bVar1 = (byte)(uVar8 >> 0x18);
  iVar5 = LZCOUNT((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1
                                  | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) <<
                                1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18 |
                  (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) << 1
                                  | bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) <<
                                1 | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
                  (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) << 1
                                  | bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) <<
                                1 | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
                  (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) << 1
                                  | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) <<
                                1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7));
  iVar6 = iVar5 + 4;
  uVar7 = *(uint *)(param_1 + iVar6 * 4);
LAB_0e05d4d4:
  FUN_0e05d438(param_1,uVar7,iVar5,iVar6,param_4);
  return uVar7;
}


