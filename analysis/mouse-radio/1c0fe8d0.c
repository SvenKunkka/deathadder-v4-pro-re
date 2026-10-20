/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0fe8d0. Types and names are inferred; NOT original source. */

void FUN_1c0fe8d0(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined1 *puVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  
  uVar3 = FUN_1c0feb70(param_2);
  uVar4 = FUN_1c0feb70(param_3);
  iVar5 = FUN_1c0feb60(uVar3);
  iVar2 = DAT_1c0feab4;
  iVar14 = param_1 * 0xc;
  if (iVar5 == 0xf) {
    iVar5 = iVar14 + 8;
  }
  else {
    iVar5 = iVar14 + 9;
  }
  puVar12 = (undefined1 *)(iVar5 + DAT_1c0feab4);
  iVar5 = FUN_1c0feb60(uVar4);
  if (iVar5 == 0xf) {
    iVar5 = iVar14 + 8;
  }
  else {
    iVar5 = iVar14 + 9;
  }
  iVar6 = FUN_1c0feb60(uVar3);
  iVar7 = FUN_1c0feb60(uVar4);
  if (iVar6 == iVar7) {
    iVar5 = FUN_1c0fe254(uVar3,uVar4,*puVar12);
  }
  else {
    piVar8 = (int *)FUN_1c0febe4(uVar3);
    piVar9 = (int *)FUN_1c0febe4(uVar4);
    uVar10 = FUN_1c0feb70(*piVar8);
    uVar11 = FUN_1c0feb70(*piVar9);
    iVar6 = FUN_1c0febdc(piVar8);
    iVar7 = iVar2 + param_1 * 0xc;
    if (iVar6 == 0xf) {
      bVar1 = *(byte *)(iVar7 + 10);
    }
    else {
      bVar1 = *(byte *)(iVar7 + 0xb);
    }
    uVar13 = (uint)bVar1;
    iVar6 = FUN_1c0febdc(piVar9);
    iVar7 = iVar2 + param_1 * 0xc;
    if (iVar6 == 0xf) {
      bVar1 = *(byte *)(iVar7 + 10);
    }
    else {
      bVar1 = *(byte *)(iVar7 + 0xb);
    }
    uVar15 = (uint)bVar1;
    if (uVar13 == 0xff) {
      return;
    }
    iVar6 = FUN_1c1037e0(piVar8[1],uVar13);
    if (iVar6 != DAT_1c0feab8) {
      return;
    }
    if (uVar15 == 0xff) {
      return;
    }
    iVar7 = FUN_1c1037e0(piVar9[1],uVar15);
    if (iVar7 != iVar6) {
      return;
    }
    *(uint *)(*piVar8 + 0x200) = *(uint *)(*piVar8 + 0x200) & ~(1 << uVar13);
    *(uint *)(*piVar9 + 0x200) = *(uint *)(*piVar9 + 0x200) & ~(1 << uVar15);
    *(undefined4 *)(*piVar8 + (uVar13 & 0x3f) * 4 + 0x80) = 0;
    *(undefined4 *)(*piVar9 + uVar15 * 4 + 0x180) = 0;
    iVar6 = FUN_1c0fe254(uVar3,uVar10,*puVar12);
    if (iVar6 != iVar7) {
      return;
    }
    iVar5 = FUN_1c0fe254(uVar11,uVar4,*(undefined1 *)(iVar5 + iVar2));
  }
  if (iVar5 == DAT_1c0feab8) {
    if (param_2 + 0xacfd4000U < 0x1065) {
      iVar5 = 0x100;
    }
    else {
      iVar5 = 0x80;
    }
    if (param_3 + 0xacfd4000U < 0x1065) {
      iVar6 = 0x100;
    }
    else {
      iVar6 = 0x80;
    }
    *(undefined4 *)(iVar2 + iVar14) = 0;
    *(undefined4 *)(iVar2 + iVar14 + 4) = 0;
    *(undefined4 *)(iVar2 + iVar14 + 8) = 0;
    *(undefined2 *)(iVar2 + param_1 * 0xc + 8) = 0xffff;
    *(undefined1 *)(iVar2 + param_1 * 0xc + 10) = 0xff;
    *(undefined4 *)(iVar5 + param_2) = 0;
    *(undefined4 *)(iVar6 + param_3) = 0;
  }
  return;
}


