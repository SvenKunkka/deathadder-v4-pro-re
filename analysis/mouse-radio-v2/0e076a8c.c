/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e076a8c. Types and names are inferred; NOT original source. */

void FUN_0e076a8c(void)

{
  byte bVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  
  piVar3 = DAT_0e076b4c;
  iVar7 = *DAT_0e076b4c;
  iVar4 = thunk_FUN_0e094688(iVar7);
  if (iVar4 != 0) {
    uVar2 = *(ushort *)((int)piVar3 + 6);
    uVar5 = (uint)*(byte *)(piVar3 + 1);
    uVar6 = 1 << uVar5;
    uVar9 = **(uint **)(iVar7 + 0x10);
    puVar8 = *(undefined4 **)(iVar7 + 8);
    if ((uVar2 & 1) == 0) {
      uVar6 = uVar9 & ~uVar6;
    }
    else {
      uVar6 = uVar6 | uVar9;
    }
    **(uint **)(iVar7 + 0x10) = uVar6;
    (*(code *)*puVar8)(iVar7,uVar5,uVar2 | 0x60000);
  }
  piVar3 = DAT_0e076b54;
  *(undefined4 *)(DAT_0e076b50 + 0x500) = 0;
  iVar7 = *piVar3;
  iVar4 = thunk_FUN_0e094688(iVar7);
  if (iVar4 != 0) {
    uVar2 = *(ushort *)((int)piVar3 + 6);
    bVar1 = *(byte *)(piVar3 + 1);
    uVar5 = 1 << (uint)bVar1;
    uVar6 = **(uint **)(iVar7 + 0x10);
    puVar8 = *(undefined4 **)(iVar7 + 8);
    if ((uVar2 & 1) == 0) {
      uVar5 = uVar6 & ~uVar5;
    }
    else {
      uVar5 = uVar5 | uVar6;
    }
    **(uint **)(iVar7 + 0x10) = uVar5;
    (*(code *)*puVar8)(iVar7,(uint)bVar1,uVar2 | 0x10000);
  }
  piVar3 = DAT_0e076b58;
  iVar7 = *DAT_0e076b58;
  iVar4 = thunk_FUN_0e094688(iVar7);
  if (iVar4 != 0) {
    uVar2 = *(ushort *)((int)piVar3 + 6);
    uVar5 = (uint)*(byte *)(piVar3 + 1);
    uVar6 = 1 << uVar5;
    uVar9 = **(uint **)(iVar7 + 0x10);
    puVar8 = *(undefined4 **)(iVar7 + 8);
    if ((uVar2 & 1) == 0) {
      uVar6 = uVar9 & ~uVar6;
    }
    else {
      uVar6 = uVar6 | uVar9;
    }
    **(uint **)(iVar7 + 0x10) = uVar6;
    (*(code *)*puVar8)(iVar7,uVar5,uVar2 | 0x10000);
  }
  puVar8 = DAT_0e076b5c;
  *(undefined4 *)(DAT_0e076b50 + 0x500) = 1;
  *puVar8 = 0;
  return;
}


