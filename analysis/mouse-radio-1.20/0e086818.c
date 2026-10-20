/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e086818. Types and names are inferred; NOT original source. */

void FUN_0e086818(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0x10;
  iVar1 = FUN_0e086764(param_1,param_2,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),
                       param_2,0x10);
  if (iVar1 == 0) {
    uVar2 = **(uint **)(param_1 + 0x3c);
    if (1 < uVar2) {
      uVar3 = uVar2 + 0xf & -uVar2;
    }
    uVar2 = *(uint *)(param_1 + 8);
    *(uint *)(param_1 + 8) = uVar2 - uVar3;
    *(uint *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) - (uint)(uVar2 < uVar3);
  }
  return;
}


