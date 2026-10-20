/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08537c. Types and names are inferred; NOT original source. */

void FUN_0e08537c(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  
  iVar2 = FUN_0e094560(DAT_23000e0c);
  iVar1 = DAT_23000e0c;
  if (iVar2 == 0) {
    iVar2 = FUN_0e094560(DAT_23000e14);
    iVar1 = DAT_23000e14;
  }
  else {
    uVar7 = (uint)DAT_23000e12;
    uVar3 = (uint)DAT_23000e10;
    uVar4 = 1 << uVar3;
    uVar6 = **(uint **)(DAT_23000e0c + 0x10);
    if ((DAT_23000e12 & 1) == 0) {
      uVar4 = uVar6 & ~uVar4;
    }
    else {
      uVar4 = uVar4 | uVar6;
    }
    puVar5 = *(undefined4 **)(DAT_23000e0c + 8);
    **(uint **)(DAT_23000e0c + 0x10) = uVar4;
    (*(code *)*puVar5)(iVar1,uVar3,uVar7 | 0x60300);
    iVar2 = FUN_0e094560(DAT_23000e14);
    iVar1 = DAT_23000e14;
  }
  DAT_23000e14 = iVar1;
  if (iVar2 == 0) {
    iVar2 = FUN_0e094560(DAT_23000e1c);
    iVar1 = DAT_23000e1c;
  }
  else {
    uVar7 = (uint)DAT_23000e1a;
    uVar3 = (uint)DAT_23000e18;
    uVar4 = 1 << uVar3;
    uVar6 = **(uint **)(iVar1 + 0x10);
    if ((DAT_23000e1a & 1) == 0) {
      uVar4 = uVar6 & ~uVar4;
    }
    else {
      uVar4 = uVar4 | uVar6;
    }
    puVar5 = *(undefined4 **)(iVar1 + 8);
    **(uint **)(iVar1 + 0x10) = uVar4;
    (*(code *)*puVar5)(iVar1,uVar3,uVar7 | 0x10010);
    iVar2 = FUN_0e094560(DAT_23000e1c);
    iVar1 = DAT_23000e1c;
  }
  if (iVar2 == 0) {
    DAT_23000e1c = iVar1;
    return;
  }
  uVar7 = (uint)DAT_23000e22;
  uVar3 = (uint)DAT_23000e20;
  uVar4 = 1 << uVar3;
  uVar6 = **(uint **)(iVar1 + 0x10);
  puVar5 = *(undefined4 **)(iVar1 + 8);
  if ((DAT_23000e22 & 1) == 0) {
    uVar4 = uVar6 & ~uVar4;
  }
  else {
    uVar4 = uVar4 | uVar6;
  }
  DAT_23000e1c = iVar1;
  **(uint **)(iVar1 + 0x10) = uVar4;
  (*(code *)*puVar5)(iVar1,uVar3,uVar7 | 0x60000);
  return;
}


