/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e084e04. Types and names are inferred; NOT original source. */

void FUN_0e084e04(void)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  iVar3 = DAT_0e084ec4;
  iVar4 = FUN_0e094688(*(undefined4 *)(DAT_0e084ec4 + 4));
  if (iVar4 == 0) {
    iVar4 = FUN_0e094688(*(undefined4 *)(iVar3 + 0xc));
  }
  else {
    uVar2 = *(ushort *)(iVar3 + 10);
    iVar4 = *(int *)(iVar3 + 4);
    bVar1 = *(byte *)(iVar3 + 8);
    uVar5 = 1 << (uint)bVar1;
    uVar7 = **(uint **)(iVar4 + 0x10);
    if ((uVar2 & 1) == 0) {
      uVar5 = uVar7 & ~uVar5;
    }
    else {
      uVar5 = uVar5 | uVar7;
    }
    puVar6 = *(undefined4 **)(iVar4 + 8);
    **(uint **)(iVar4 + 0x10) = uVar5;
    (*(code *)*puVar6)(iVar4,(uint)bVar1,uVar2 | 0x60300);
    iVar4 = FUN_0e094688(*(undefined4 *)(iVar3 + 0xc));
  }
  if (iVar4 == 0) {
    iVar4 = FUN_0e094688(*(undefined4 *)(iVar3 + 0x24));
  }
  else {
    uVar2 = *(ushort *)(iVar3 + 0x12);
    iVar4 = *(int *)(iVar3 + 0xc);
    bVar1 = *(byte *)(iVar3 + 0x10);
    uVar5 = 1 << (uint)bVar1;
    uVar7 = **(uint **)(iVar4 + 0x10);
    if ((uVar2 & 1) == 0) {
      uVar5 = uVar7 & ~uVar5;
    }
    else {
      uVar5 = uVar5 | uVar7;
    }
    puVar6 = *(undefined4 **)(iVar4 + 8);
    **(uint **)(iVar4 + 0x10) = uVar5;
    (*(code *)*puVar6)(iVar4,(uint)bVar1,uVar2 | 0xa0000);
    iVar4 = FUN_0e094688(*(undefined4 *)(iVar3 + 0x24));
  }
  if (iVar4 == 0) {
    return;
  }
  uVar2 = *(ushort *)(iVar3 + 0x2a);
  iVar4 = *(int *)(iVar3 + 0x24);
  bVar1 = *(byte *)(iVar3 + 0x28);
  uVar5 = 1 << (uint)bVar1;
  uVar7 = **(uint **)(iVar4 + 0x10);
  puVar6 = *(undefined4 **)(iVar4 + 8);
  if ((uVar2 & 1) == 0) {
    uVar5 = uVar7 & ~uVar5;
  }
  else {
    uVar5 = uVar5 | uVar7;
  }
  **(uint **)(iVar4 + 0x10) = uVar5;
                    /* WARNING: Could not recover jumptable at 0x0e084ec0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar6)(iVar4,(uint)bVar1,uVar2 | 0x10020);
  return;
}


