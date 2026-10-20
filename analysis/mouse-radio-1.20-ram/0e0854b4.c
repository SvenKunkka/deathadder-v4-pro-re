/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0854b4. Types and names are inferred; NOT original source. */

void FUN_0e0854b4(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  
  if ((1 << (uint)DAT_23000e10 & **(uint **)(DAT_23000e0c + 0x10)) == 0) {
    pcVar4 = *(code **)(*(int *)(DAT_23000e0c + 8) + 0xc);
  }
  else {
    pcVar4 = *(code **)(*(int *)(DAT_23000e0c + 8) + 0x10);
  }
  (*pcVar4)();
  iVar2 = FUN_0e094560(DAT_23000e14);
  iVar1 = DAT_23000e14;
  if (iVar2 == 0) {
    iVar2 = FUN_0e094560(DAT_23000e1c);
    iVar1 = DAT_23000e1c;
  }
  else {
    uVar8 = (uint)DAT_23000e1a;
    uVar3 = (uint)DAT_23000e18;
    uVar5 = 1 << uVar3;
    uVar7 = **(uint **)(DAT_23000e14 + 0x10);
    if ((DAT_23000e1a & 1) == 0) {
      uVar5 = uVar7 & ~uVar5;
    }
    else {
      uVar5 = uVar5 | uVar7;
    }
    puVar6 = *(undefined4 **)(DAT_23000e14 + 8);
    **(uint **)(DAT_23000e14 + 0x10) = uVar5;
    (*(code *)*puVar6)(iVar1,uVar3,uVar8 | 0x10010);
    iVar2 = FUN_0e094560(DAT_23000e1c);
    iVar1 = DAT_23000e1c;
  }
  if (iVar2 == 0) {
    DAT_23000e1c = iVar1;
    return;
  }
  uVar8 = (uint)DAT_23000e22;
  uVar3 = (uint)DAT_23000e20;
  uVar5 = 1 << uVar3;
  uVar7 = **(uint **)(iVar1 + 0x10);
  puVar6 = *(undefined4 **)(iVar1 + 8);
  if ((DAT_23000e22 & 1) == 0) {
    uVar5 = uVar7 & ~uVar5;
  }
  else {
    uVar5 = uVar5 | uVar7;
  }
  DAT_23000e1c = iVar1;
  **(uint **)(iVar1 + 0x10) = uVar5;
                    /* WARNING: Could not recover jumptable at 0x0e085546. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar6)(iVar1,uVar3,uVar8 | 0x60000);
  return;
}


