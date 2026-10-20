/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e084f70. Types and names are inferred; NOT original source. */

void FUN_0e084f70(int param_1)

{
  ushort uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  
  iVar3 = DAT_0e085048;
  if (param_1 == 1) {
    iVar4 = FUN_0e094688(*(undefined4 *)(DAT_0e085048 + 0x14));
    if (iVar4 != 0) {
      uVar1 = *(ushort *)(iVar3 + 0x1a);
      iVar4 = *(int *)(iVar3 + 0x14);
      bVar2 = *(byte *)(iVar3 + 0x18);
      uVar7 = **(uint **)(iVar4 + 0x10);
      uVar5 = 1 << (uint)bVar2;
      puVar9 = *(undefined4 **)(iVar4 + 8);
      if ((uVar1 & 1) == 0) {
        uVar5 = uVar7 & ~uVar5;
      }
      else {
        uVar5 = uVar5 | uVar7;
      }
      **(uint **)(iVar4 + 0x10) = uVar5;
      (*(code *)*puVar9)(iVar4,(uint)bVar2,uVar1 | 0x10020);
    }
    iVar4 = FUN_0e094688(*(undefined4 *)(iVar3 + 0x1c));
    if (iVar4 == 0) {
      return;
    }
    uVar7 = (uint)*(ushort *)(iVar3 + 0x22);
    iVar4 = *(int *)(iVar3 + 0x1c);
    bVar2 = *(byte *)(iVar3 + 0x20);
    uVar5 = uVar7 | 0x10020;
  }
  else {
    iVar4 = FUN_0e094688(*(undefined4 *)(DAT_0e085048 + 0x14));
    if (iVar4 == 0) {
      iVar4 = FUN_0e094688(*(undefined4 *)(iVar3 + 0x1c));
    }
    else {
      uVar1 = *(ushort *)(iVar3 + 0x1a);
      iVar4 = *(int *)(iVar3 + 0x14);
      bVar2 = *(byte *)(iVar3 + 0x18);
      uVar7 = **(uint **)(iVar4 + 0x10);
      uVar5 = 1 << (uint)bVar2;
      if ((uVar1 & 1) == 0) {
        uVar5 = uVar7 & ~uVar5;
      }
      else {
        uVar5 = uVar5 | uVar7;
      }
      puVar9 = *(undefined4 **)(iVar4 + 8);
      **(uint **)(iVar4 + 0x10) = uVar5;
      (*(code *)*puVar9)(iVar4,(uint)bVar2,uVar1 | 0x10010);
      iVar4 = FUN_0e094688(*(undefined4 *)(iVar3 + 0x1c));
    }
    if (iVar4 == 0) {
      return;
    }
    uVar7 = (uint)*(ushort *)(iVar3 + 0x22);
    iVar4 = *(int *)(iVar3 + 0x1c);
    bVar2 = *(byte *)(iVar3 + 0x20);
    uVar5 = uVar7 | 0x10010;
  }
  uVar8 = **(uint **)(iVar4 + 0x10);
  uVar6 = 1 << (uint)bVar2;
  puVar9 = *(undefined4 **)(iVar4 + 8);
  if ((uVar7 & 1) == 0) {
    uVar6 = uVar8 & ~uVar6;
  }
  else {
    uVar6 = uVar6 | uVar8;
  }
  **(uint **)(iVar4 + 0x10) = uVar6;
                    /* WARNING: Could not recover jumptable at 0x0e084fc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar9)(iVar4,(uint)bVar2,uVar5);
  return;
}


