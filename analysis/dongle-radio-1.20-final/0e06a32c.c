/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06a32c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06a32c(int *param_1,int *param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  sbyte *psVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  byte *local_2c;
  
  uVar3 = FUN_0e06ab80(*param_1);
  uVar4 = FUN_0e06ab80(*param_2);
  iVar5 = FUN_0e06ab70(uVar3);
  if (iVar5 == 0xf) {
    local_2c = (byte *)(param_3 + 0xb);
    bVar1 = *(byte *)(param_3 + 8);
    bVar2 = *(byte *)(param_3 + 9);
    psVar7 = (sbyte *)(param_3 + 10);
  }
  else {
    iVar5 = FUN_0e06ab70(uVar4);
    if (iVar5 != 0xf) {
      return 0xbad0004;
    }
    local_2c = (byte *)(param_3 + 10);
    bVar1 = *(byte *)(param_3 + 9);
    bVar2 = *(byte *)(param_3 + 8);
    psVar7 = (sbyte *)(param_3 + 0xb);
  }
  puVar8 = (uint *)param_1[1];
  uVar6 = *(uint *)param_2[1];
  uVar10 = *puVar8;
  uVar9 = param_2[3];
  uVar13 = uVar10 & param_1[2];
  do {
    uVar10 = uVar10 & uVar13;
    if (uVar10 == 0) {
      return 0xbad0002;
    }
    uVar11 = 0x1f - LZCOUNT(uVar10);
    uVar12 = *puVar8;
    *puVar8 = uVar12 & ~(1 << (uVar11 & 0xff));
    uVar10 = *puVar8;
  } while (uVar12 == uVar10);
  *psVar7 = (sbyte)uVar11;
  puVar8 = (uint *)param_2[1];
  uVar10 = *puVar8;
  do {
    uVar10 = uVar10 & uVar6 & uVar9;
    if (uVar10 == 0) {
      if (*psVar7 != -1) {
        FUN_0e068a9c(param_1[1]);
      }
      return 0xbad0002;
    }
    uVar13 = 0x1f - LZCOUNT(uVar10);
    uVar11 = *puVar8;
    *puVar8 = uVar11 & ~(1 << (uVar13 & 0xff));
    uVar10 = *puVar8;
  } while (uVar11 == uVar10);
  *local_2c = (byte)uVar13;
  *(uint *)(*param_1 + 0x200) = 1 << *psVar7 | *(uint *)(*param_1 + 0x200);
  *(uint *)(*param_2 + 0x200) = 1 << *local_2c | *(uint *)(*param_2 + 0x200);
  *(uint *)(*param_1 + (byte)(*psVar7 << 2) + 0x80) = bVar1 | 0x80000000;
  *(uint *)(*param_2 + (uint)*local_2c * 4 + 0x180) = bVar2 | 0x80000000;
  return 0xbad0000;
}


