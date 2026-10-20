/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e084c78. Types and names are inferred; NOT original source. */

void FUN_0e084c78(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  
  iVar2 = FUN_0e094560(DAT_23000660);
  iVar1 = DAT_23000660;
  if (iVar2 == 0) {
    iVar2 = FUN_0e094560(DAT_23000668);
    iVar1 = DAT_23000668;
  }
  else {
    uVar7 = (uint)DAT_23000666;
    uVar3 = (uint)DAT_23000664;
    uVar4 = 1 << uVar3;
    uVar6 = **(uint **)(DAT_23000660 + 0x10);
    if ((DAT_23000666 & 1) == 0) {
      uVar4 = uVar6 & ~uVar4;
    }
    else {
      uVar4 = uVar4 | uVar6;
    }
    puVar5 = *(undefined4 **)(DAT_23000660 + 8);
    **(uint **)(DAT_23000660 + 0x10) = uVar4;
    (*(code *)*puVar5)(iVar1,uVar3,uVar7 | 0x60300);
    iVar2 = FUN_0e094560(DAT_23000668);
    iVar1 = DAT_23000668;
  }
  DAT_23000668 = iVar1;
  if (iVar2 == 0) {
    iVar2 = FUN_0e094560(DAT_23000680);
    iVar1 = DAT_23000680;
  }
  else {
    uVar7 = (uint)DAT_2300066e;
    uVar3 = (uint)DAT_2300066c;
    uVar4 = 1 << uVar3;
    uVar6 = **(uint **)(iVar1 + 0x10);
    if ((DAT_2300066e & 1) == 0) {
      uVar4 = uVar6 & ~uVar4;
    }
    else {
      uVar4 = uVar4 | uVar6;
    }
    puVar5 = *(undefined4 **)(iVar1 + 8);
    **(uint **)(iVar1 + 0x10) = uVar4;
    (*(code *)*puVar5)(iVar1,uVar3,uVar7 | 0xa0000);
    iVar2 = FUN_0e094560(DAT_23000680);
    iVar1 = DAT_23000680;
  }
  if (iVar2 == 0) {
    DAT_23000680 = iVar1;
    return;
  }
  uVar7 = (uint)DAT_23000686;
  uVar3 = (uint)DAT_23000684;
  uVar4 = 1 << uVar3;
  uVar6 = **(uint **)(iVar1 + 0x10);
  puVar5 = *(undefined4 **)(iVar1 + 8);
  if ((DAT_23000686 & 1) == 0) {
    uVar4 = uVar6 & ~uVar4;
  }
  else {
    uVar4 = uVar4 | uVar6;
  }
  DAT_23000680 = iVar1;
  **(uint **)(iVar1 + 0x10) = uVar4;
                    /* WARNING: Could not recover jumptable at 0x0e084d34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar5)(iVar1,uVar3,uVar7 | 0x10020);
  return;
}


