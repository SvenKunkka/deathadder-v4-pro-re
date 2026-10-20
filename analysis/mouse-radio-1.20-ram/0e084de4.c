/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e084de4. Types and names are inferred; NOT original source. */

void FUN_0e084de4(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  
  if (param_1 == 1) {
    iVar1 = FUN_0e094560(DAT_23000670);
    iVar2 = DAT_23000670;
    if (iVar1 != 0) {
      uVar3 = (uint)DAT_23000676;
      uVar4 = (uint)DAT_23000674;
      uVar5 = **(uint **)(DAT_23000670 + 0x10);
      uVar6 = 1 << uVar4;
      puVar8 = *(undefined4 **)(DAT_23000670 + 8);
      if ((DAT_23000676 & 1) == 0) {
        uVar6 = uVar5 & ~uVar6;
      }
      else {
        uVar6 = uVar6 | uVar5;
      }
      **(uint **)(DAT_23000670 + 0x10) = uVar6;
      (*(code *)*puVar8)(iVar2,uVar4,uVar3 | 0x10020);
    }
    iVar2 = FUN_0e094560(DAT_23000678);
    if (iVar2 == 0) {
      return;
    }
    uVar6 = (uint)DAT_2300067e;
    uVar4 = uVar6 | 0x10020;
  }
  else {
    iVar1 = FUN_0e094560(DAT_23000670);
    iVar2 = DAT_23000670;
    if (iVar1 == 0) {
      iVar2 = FUN_0e094560(DAT_23000678);
    }
    else {
      uVar3 = (uint)DAT_23000676;
      uVar4 = (uint)DAT_23000674;
      uVar5 = **(uint **)(DAT_23000670 + 0x10);
      uVar6 = 1 << uVar4;
      if ((DAT_23000676 & 1) == 0) {
        uVar6 = uVar5 & ~uVar6;
      }
      else {
        uVar6 = uVar6 | uVar5;
      }
      puVar8 = *(undefined4 **)(DAT_23000670 + 8);
      **(uint **)(DAT_23000670 + 0x10) = uVar6;
      (*(code *)*puVar8)(iVar2,uVar4,uVar3 | 0x10010);
      iVar2 = FUN_0e094560(DAT_23000678);
    }
    if (iVar2 == 0) {
      return;
    }
    uVar6 = (uint)DAT_2300067e;
    uVar4 = uVar6 | 0x10010;
  }
  iVar2 = DAT_23000678;
  uVar3 = (uint)DAT_2300067c;
  uVar7 = **(uint **)(DAT_23000678 + 0x10);
  uVar5 = 1 << uVar3;
  puVar8 = *(undefined4 **)(DAT_23000678 + 8);
  if ((uVar6 & 1) == 0) {
    uVar5 = uVar7 & ~uVar5;
  }
  else {
    uVar5 = uVar5 | uVar7;
  }
  **(uint **)(DAT_23000678 + 0x10) = uVar5;
                    /* WARNING: Could not recover jumptable at 0x0e084e34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar8)(iVar2,uVar3,uVar4);
  return;
}


