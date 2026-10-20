/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b0d0c. Types and names are inferred; NOT original source. */

undefined4
FUN_0e0b0d0c(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
            int *param_6)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  
  puVar5 = (uint *)FUN_0e0b0c42(param_5);
  uVar6 = *puVar5;
  uVar8 = puVar5[1];
  iVar9 = *(int *)(param_1 + 8);
  uVar7 = puVar5[4];
  if (uVar6 == uVar8) {
    uVar8 = *(uint *)(iVar9 + uVar6 * 4);
    if (param_4 == 0) {
      uVar8 = ~uVar8;
    }
    if ((uVar7 & ~uVar8) == 0) {
      return 1;
    }
    uVar7 = uVar7 & ~uVar8;
  }
  else {
    uVar10 = *(uint *)(iVar9 + uVar6 * 4);
    if (param_4 == 0) {
      uVar10 = ~uVar10;
    }
    if ((uVar7 & ~uVar10) == 0) {
      uVar7 = *(uint *)(iVar9 + uVar8 * 4);
      if (param_4 == 0) {
        uVar7 = ~uVar7;
      }
      if ((puVar5[5] & ~uVar7) == 0) {
        do {
          uVar6 = uVar6 + 1;
          if (uVar8 <= uVar6) {
            return 1;
          }
          uVar7 = *(uint *)(iVar9 + uVar6 * 4);
          if (param_4 != 0) {
            uVar7 = ~uVar7;
          }
        } while (uVar7 == 0);
      }
      else {
        uVar7 = puVar5[5] & ~uVar7;
        uVar6 = uVar8;
      }
    }
    else {
      uVar7 = uVar7 & ~uVar10;
    }
  }
  if (param_6 != (int *)0x0) {
    bVar2 = (byte)uVar7;
    bVar3 = (byte)(uVar7 >> 8);
    bVar4 = (byte)(uVar7 >> 0x10);
    bVar1 = (byte)(uVar7 >> 0x18);
    iVar9 = LZCOUNT((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) <<
                                     1 | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 |
                                  bVar2 >> 5 & 1) << 1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18
                    | (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1)
                                       << 1 | bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 |
                                    bVar3 >> 5 & 1) << 1 | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) <<
                      0x10 | (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 |
                                              bVar4 >> 2 & 1) << 1 | bVar4 >> 3 & 1) << 1 |
                                            bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1 |
                                          bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
                    (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) <<
                                     1 | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 |
                                  bVar1 >> 5 & 1) << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7));
    if (uVar7 == 0) {
      iVar9 = -1;
    }
    *param_6 = iVar9 + uVar6 * 0x20;
  }
  return 0;
}


