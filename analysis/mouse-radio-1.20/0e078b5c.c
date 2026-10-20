/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e078b5c. Types and names are inferred; NOT original source. */

int thunk_FUN_0e084d3c(void)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint auStack_1c [2];
  
  iVar3 = FUN_0e094560(DAT_23000680);
  iVar1 = DAT_23000680;
  if (iVar3 == 0) {
    return 0;
  }
  uVar9 = (uint)DAT_23000686;
  uVar4 = (uint)DAT_23000684;
  uVar5 = 1 << uVar4;
  uVar7 = **(uint **)(DAT_23000680 + 0x10);
  puVar6 = *(undefined4 **)(DAT_23000680 + 8);
  if ((DAT_23000686 & 1) == 0) {
    uVar5 = uVar7 & ~uVar5;
  }
  else {
    uVar5 = uVar5 | uVar7;
  }
  **(uint **)(DAT_23000680 + 0x10) = uVar5;
  (*(code *)*puVar6)(iVar1,uVar4,uVar9 | 0x10010);
  FUN_0e094554(5);
  bVar2 = DAT_23000684;
  puVar8 = *(uint **)(DAT_23000680 + 0x10);
  iVar3 = (**(code **)(*(int *)(DAT_23000680 + 8) + 4))(DAT_23000680,auStack_1c);
  iVar1 = DAT_23000680;
  if (iVar3 == 0) {
    if (((auStack_1c[0] ^ *puVar8) & 1 << bVar2) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = 1;
    }
  }
  uVar9 = (uint)DAT_23000686;
  uVar4 = (uint)DAT_23000684;
  uVar5 = 1 << uVar4;
  uVar7 = **(uint **)(DAT_23000680 + 0x10);
  puVar6 = *(undefined4 **)(DAT_23000680 + 8);
  if ((DAT_23000686 & 1) == 0) {
    uVar5 = uVar7 & ~uVar5;
  }
  else {
    uVar5 = uVar5 | uVar7;
  }
  **(uint **)(DAT_23000680 + 0x10) = uVar5;
  (*(code *)*puVar6)(iVar1,uVar4,uVar9 | 0x10020);
  return iVar3;
}


