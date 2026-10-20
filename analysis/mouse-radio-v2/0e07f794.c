/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07f794. Types and names are inferred; NOT original source. */

void FUN_0e07f794(void)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined2 *puVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  undefined4 unaff_r4;
  int iVar13;
  undefined4 unaff_r5;
  undefined4 *puVar14;
  undefined4 unaff_r6;
  uint uVar15;
  uint uVar16;
  undefined4 unaff_lr;
  
  piVar4 = DAT_0e07f980;
  iVar13 = *DAT_0e07f980;
  iVar10 = FUN_0e094688(iVar13);
  piVar5 = DAT_0e07f984;
  if (iVar10 == 0) {
    iVar10 = *DAT_0e07f984;
    iVar13 = FUN_0e094688(iVar10);
    piVar4 = DAT_0e07f988;
  }
  else {
    uVar2 = *(ushort *)((int)piVar4 + 6);
    uVar12 = (uint)*(byte *)(piVar4 + 1);
    uVar16 = 1 << uVar12;
    uVar15 = **(uint **)(iVar13 + 0x10);
    puVar14 = *(undefined4 **)(iVar13 + 8);
    if ((uVar2 & 1) == 0) {
      uVar16 = uVar15 & ~uVar16;
    }
    else {
      uVar16 = uVar16 | uVar15;
    }
    **(uint **)(iVar13 + 0x10) = uVar16;
    piVar5 = DAT_0e07f984;
    (*(code *)*puVar14)(iVar13,uVar12,uVar2 | 0x60000);
    iVar10 = *piVar5;
    iVar13 = FUN_0e094688(iVar10);
    piVar4 = DAT_0e07f988;
  }
  DAT_0e07f988 = piVar4;
  if (iVar13 == 0) {
    iVar10 = *piVar4;
    iVar13 = FUN_0e094688(iVar10);
    piVar5 = DAT_0e07f98c;
  }
  else {
    uVar2 = *(ushort *)((int)piVar5 + 6);
    bVar1 = *(byte *)(piVar5 + 1);
    uVar12 = 1 << (uint)bVar1;
    uVar16 = **(uint **)(iVar10 + 0x10);
    puVar14 = *(undefined4 **)(iVar10 + 8);
    if ((uVar2 & 1) == 0) {
      uVar12 = uVar16 & ~uVar12;
    }
    else {
      uVar12 = uVar12 | uVar16;
    }
    **(uint **)(iVar10 + 0x10) = uVar12;
    piVar4 = DAT_0e07f988;
    (*(code *)*puVar14)(iVar10,(uint)bVar1,uVar2 | 0x10000);
    iVar10 = *piVar4;
    iVar13 = FUN_0e094688(iVar10);
    piVar5 = DAT_0e07f98c;
  }
  DAT_0e07f98c = piVar5;
  if (iVar13 == 0) {
    iVar10 = *piVar5;
    iVar13 = FUN_0e094688(iVar10);
    piVar4 = DAT_0e07f990;
  }
  else {
    uVar2 = *(ushort *)((int)piVar4 + 6);
    bVar1 = *(byte *)(piVar4 + 1);
    uVar12 = 1 << (uint)bVar1;
    uVar16 = **(uint **)(iVar10 + 0x10);
    puVar14 = *(undefined4 **)(iVar10 + 8);
    if ((uVar2 & 1) == 0) {
      uVar12 = uVar16 & ~uVar12;
    }
    else {
      uVar12 = uVar12 | uVar16;
    }
    **(uint **)(iVar10 + 0x10) = uVar12;
    piVar5 = DAT_0e07f98c;
    (*(code *)*puVar14)(iVar10,(uint)bVar1,uVar2 | 0x10000);
    iVar10 = *piVar5;
    iVar13 = FUN_0e094688(iVar10);
    piVar4 = DAT_0e07f990;
  }
  DAT_0e07f990 = piVar4;
  if (iVar13 == 0) {
    iVar10 = *piVar4;
    iVar13 = FUN_0e094688(iVar10);
    piVar5 = DAT_0e07f994;
  }
  else {
    uVar2 = *(ushort *)((int)piVar5 + 6);
    bVar1 = *(byte *)(piVar5 + 1);
    uVar12 = 1 << (uint)bVar1;
    uVar16 = **(uint **)(iVar10 + 0x10);
    puVar14 = *(undefined4 **)(iVar10 + 8);
    if ((uVar2 & 1) == 0) {
      uVar12 = uVar16 & ~uVar12;
    }
    else {
      uVar12 = uVar12 | uVar16;
    }
    **(uint **)(iVar10 + 0x10) = uVar12;
    piVar4 = DAT_0e07f990;
    (*(code *)*puVar14)(iVar10,(uint)bVar1,uVar2 | 0x10000);
    iVar10 = *piVar4;
    iVar13 = FUN_0e094688(iVar10);
    piVar5 = DAT_0e07f994;
  }
  DAT_0e07f994 = piVar5;
  if (iVar13 == 0) {
    iVar10 = *piVar5;
    iVar13 = FUN_0e094688(iVar10);
    piVar4 = DAT_0e07f998;
  }
  else {
    uVar2 = *(ushort *)((int)piVar4 + 6);
    bVar1 = *(byte *)(piVar4 + 1);
    uVar12 = 1 << (uint)bVar1;
    uVar16 = **(uint **)(iVar10 + 0x10);
    puVar14 = *(undefined4 **)(iVar10 + 8);
    if ((uVar2 & 1) == 0) {
      uVar12 = uVar16 & ~uVar12;
    }
    else {
      uVar12 = uVar12 | uVar16;
    }
    **(uint **)(iVar10 + 0x10) = uVar12;
    piVar5 = DAT_0e07f994;
    (*(code *)*puVar14)(iVar10,(uint)bVar1,uVar2 | 0x10000);
    iVar10 = *piVar5;
    iVar13 = FUN_0e094688(iVar10);
    piVar4 = DAT_0e07f998;
  }
  DAT_0e07f998 = piVar4;
  if (iVar13 == 0) {
    iVar10 = *piVar4;
    iVar13 = FUN_0e094688(iVar10);
  }
  else {
    uVar2 = *(ushort *)((int)piVar5 + 6);
    bVar1 = *(byte *)(piVar5 + 1);
    uVar12 = 1 << (uint)bVar1;
    uVar16 = **(uint **)(iVar10 + 0x10);
    puVar14 = *(undefined4 **)(iVar10 + 8);
    if ((uVar2 & 1) == 0) {
      uVar12 = uVar16 & ~uVar12;
    }
    else {
      uVar12 = uVar12 | uVar16;
    }
    **(uint **)(iVar10 + 0x10) = uVar12;
    piVar4 = DAT_0e07f998;
    (*(code *)*puVar14)(iVar10,(uint)bVar1,uVar2 | 0x10000);
    iVar10 = *piVar4;
    iVar13 = FUN_0e094688(iVar10);
  }
  if (iVar13 != 0) {
    uVar2 = *(ushort *)((int)piVar4 + 6);
    bVar1 = *(byte *)(piVar4 + 1);
    uVar12 = 1 << (uint)bVar1;
    uVar16 = **(uint **)(iVar10 + 0x10);
    puVar14 = *(undefined4 **)(iVar10 + 8);
    if ((uVar2 & 1) == 0) {
      uVar12 = uVar16 & ~uVar12;
    }
    else {
      uVar12 = uVar12 | uVar16;
    }
    **(uint **)(iVar10 + 0x10) = uVar12;
    (*(code *)*puVar14)(iVar10,(uint)bVar1,uVar2 | 0x10000);
  }
  puVar6 = DAT_0e07f774;
  puVar14 = DAT_0e07f770;
  *DAT_0e07f770 = 0;
  puVar14[1] = 0;
  puVar14[2] = 0;
  puVar14[3] = 0;
  iVar10 = DAT_0e07f778;
  *puVar6 = 0;
  puVar6[1] = 0;
  puVar8 = DAT_0e07f788;
  puVar7 = DAT_0e07f784;
  puVar6 = DAT_0e07f780;
  puVar14 = DAT_0e07f77c;
  bVar1 = *(byte *)(iVar10 + 3);
  *DAT_0e07f77c = 0;
  puVar14[1] = 0;
  puVar14[2] = 0;
  puVar14[3] = 0;
  *puVar6 = 0;
  puVar6[1] = 0;
  puVar6[2] = 0;
  puVar6[3] = 0;
  uVar9 = DAT_0e07f78c;
  *puVar7 = 0;
  puVar7[1] = 0;
  puVar7[2] = 0;
  puVar7[3] = 0;
  *puVar8 = 0;
  FUN_0e0974c4(uVar9,(uint)bVar1 * 0xf4 + iVar10 + 0x91,0x80,puVar7,unaff_r4,unaff_r5,unaff_r6,
               unaff_lr);
  iVar10 = DAT_0e07f790;
  iVar13 = 0;
  do {
    iVar3 = iVar13 * 5;
    iVar13 = iVar13 + 1;
    iVar11 = iVar10 + iVar3;
    *(undefined1 *)(iVar10 + iVar3) = 0;
    *(undefined1 *)(iVar11 + 1) = 0;
    *(undefined1 *)(iVar11 + 2) = 0;
    *(undefined1 *)(iVar11 + 3) = 0;
    *(undefined1 *)(iVar11 + 4) = 0;
  } while (iVar13 != 8);
  return;
}


