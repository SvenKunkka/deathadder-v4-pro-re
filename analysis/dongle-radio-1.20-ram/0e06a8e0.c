/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06a8e0. Types and names are inferred; NOT original source. */

void FUN_0e06a8e0(int param_1,int param_2,int param_3)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  
  uVar2 = FUN_0e06ab80(param_2);
  uVar3 = FUN_0e06ab80(param_3);
  iVar4 = FUN_0e06ab70(uVar2);
  iVar13 = param_1 * 0xc;
  if (iVar4 == 0xf) {
    iVar4 = iVar13 + 8;
  }
  else {
    iVar4 = iVar13 + 9;
  }
  iVar5 = FUN_0e06ab70(uVar3);
  if (iVar5 == 0xf) {
    iVar5 = iVar13 + 8;
  }
  else {
    iVar5 = iVar13 + 9;
  }
  iVar6 = FUN_0e06ab70(uVar2);
  iVar7 = FUN_0e06ab70(uVar3);
  if (iVar6 == iVar7) {
    iVar4 = FUN_0e06a264(uVar2,uVar3,(&DAT_23006e58)[iVar4]);
  }
  else {
    piVar8 = (int *)FUN_0e06abf4(uVar2);
    piVar9 = (int *)FUN_0e06abf4(uVar3);
    uVar10 = FUN_0e06ab80(*piVar8);
    uVar11 = FUN_0e06ab80(*piVar9);
    iVar6 = FUN_0e06abec(piVar8);
    if (iVar6 == 0xf) {
      bVar1 = (&DAT_23006e62)[param_1 * 0xc];
    }
    else {
      bVar1 = (&DAT_23006e63)[param_1 * 0xc];
    }
    uVar12 = (uint)bVar1;
    iVar6 = FUN_0e06abec(piVar9);
    if (iVar6 == 0xf) {
      bVar1 = (&DAT_23006e62)[param_1 * 0xc];
    }
    else {
      bVar1 = (&DAT_23006e63)[param_1 * 0xc];
    }
    uVar14 = (uint)bVar1;
    if (uVar12 == 0xff) {
      return;
    }
    iVar6 = FUN_0e068a9c(piVar8[1],uVar12);
    if (iVar6 != 0xbad0000) {
      return;
    }
    if (uVar14 == 0xff) {
      return;
    }
    iVar6 = FUN_0e068a9c(piVar9[1],uVar14);
    if (iVar6 != 0xbad0000) {
      return;
    }
    *(uint *)(*piVar8 + 0x200) = *(uint *)(*piVar8 + 0x200) & ~(1 << uVar12);
    *(uint *)(*piVar9 + 0x200) = *(uint *)(*piVar9 + 0x200) & ~(1 << uVar14);
    *(undefined4 *)(*piVar8 + (uVar12 & 0x3f) * 4 + 0x80) = 0;
    *(undefined4 *)(*piVar9 + uVar14 * 4 + 0x180) = 0;
    iVar4 = FUN_0e06a264(uVar2,uVar10,(&DAT_23006e58)[iVar4]);
    if (iVar4 != 0xbad0000) {
      return;
    }
    iVar4 = FUN_0e06a264(uVar11,uVar3,(&DAT_23006e58)[iVar5]);
  }
  if (iVar4 == 0xbad0000) {
    if (param_2 + 0xacfd4000U < 0x1065) {
      iVar4 = 0x100;
    }
    else {
      iVar4 = 0x80;
    }
    if (param_3 + 0xacfd4000U < 0x1065) {
      iVar5 = 0x100;
    }
    else {
      iVar5 = 0x80;
    }
    *(undefined4 *)(&DAT_23006e58 + iVar13) = 0;
    *(undefined4 *)(&DAT_23006e5c + iVar13) = 0;
    *(undefined4 *)(&DAT_23006e60 + iVar13) = 0;
    *(undefined2 *)(&DAT_23006e60 + param_1 * 0xc) = 0xffff;
    (&DAT_23006e62)[param_1 * 0xc] = 0xff;
    *(undefined4 *)(iVar4 + param_2) = 0;
    *(undefined4 *)(iVar5 + param_3) = 0;
  }
  return;
}


