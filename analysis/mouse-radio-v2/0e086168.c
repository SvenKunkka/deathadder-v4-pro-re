/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e086168. Types and names are inferred; NOT original source. */

undefined4 FUN_0e086168(int param_1,uint param_2,int param_3,int param_4,uint *param_5,int *param_6)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  uVar7 = param_3 + -1 + param_2;
  uVar10 = uVar7 & 0x1f;
  uVar11 = 1 << uVar10;
  param_5[3] = uVar10;
  uVar7 = uVar7 >> 5;
  uVar6 = param_2 >> 5;
  param_5[2] = param_2 & 0x1f;
  uVar10 = -(1 << (param_2 & 0x1f));
  uVar11 = uVar11 - 1 | uVar11;
  param_5[1] = uVar7;
  *param_5 = uVar6;
  param_5[4] = uVar10;
  param_5[5] = uVar11;
  if (uVar6 == uVar7) {
    uVar10 = uVar10 & uVar11;
    param_5[4] = uVar10;
    uVar7 = *(uint *)(*(int *)(param_1 + 8) + uVar6 * 4);
    if (param_4 == 0) {
      uVar7 = ~uVar7;
    }
    if ((uVar10 & ~uVar7) != 0) {
      uVar5 = uVar10 & ~uVar7;
      goto LAB_0e0861ae;
    }
  }
  else {
    iVar9 = *(int *)(param_1 + 8);
    uVar12 = *(uint *)(iVar9 + uVar6 * 4);
    uVar5 = uVar12 & uVar10;
    if (param_4 == 0) {
      if (uVar5 != 0) goto LAB_0e0861ae;
      uVar10 = ~*(uint *)(iVar9 + uVar7 * 4);
    }
    else {
      if (uVar5 != uVar10) {
        uVar5 = uVar10 & ~uVar12;
        goto LAB_0e0861ae;
      }
      uVar10 = *(uint *)(iVar9 + uVar7 * 4);
    }
    if ((uVar11 & ~uVar10) != 0) {
      uVar5 = uVar11 & ~uVar10;
      uVar6 = uVar7;
LAB_0e0861ae:
      if (param_6 != (int *)0x0) {
        bVar2 = (byte)uVar5;
        bVar3 = (byte)(uVar5 >> 8);
        bVar4 = (byte)(uVar5 >> 0x10);
        bVar1 = (byte)(uVar5 >> 0x18);
        iVar9 = LZCOUNT((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1)
                                         << 1 | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 |
                                      bVar2 >> 5 & 1) << 1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) <<
                        0x18 | (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 |
                                                bVar3 >> 2 & 1) << 1 | bVar3 >> 3 & 1) << 1 |
                                              bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 |
                                            bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
                        (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1)
                                         << 1 | bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 |
                                      bVar4 >> 5 & 1) << 1 | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8
                        | (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 |
                                           bVar1 >> 2 & 1) << 1 | bVar1 >> 3 & 1) << 1 |
                                         bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) << 1 |
                                       bVar1 >> 6 & 1) << 1 | bVar1 >> 7));
        if (uVar5 == 0) {
          iVar9 = -1;
        }
        *param_6 = iVar9 + uVar6 * 0x20;
      }
      return 0;
    }
    uVar10 = uVar6 + 1;
    if (uVar10 < uVar7) {
      puVar8 = (uint *)(iVar9 + uVar6 * 4);
      do {
        puVar8 = puVar8 + 1;
        uVar5 = *puVar8;
        if (param_4 != 0) {
          uVar5 = ~uVar5;
        }
        uVar6 = uVar10;
        if (uVar5 != 0) goto LAB_0e0861ae;
        uVar10 = uVar10 + 1;
      } while (puVar8 != (uint *)(iVar9 + uVar7 * 4 + -4));
    }
  }
  return 1;
}


