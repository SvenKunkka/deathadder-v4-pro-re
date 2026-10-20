/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068620. Types and names are inferred; NOT original source. */

void FUN_0e068620(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint local_18;
  int local_14;
  
  if (param_1 == 0xffffffff) {
    param_1 = 0x7fffffff;
  }
  else {
    param_1 = param_1 & ~((int)param_1 >> 0x1f);
  }
  FUN_0e0696e0(&local_18);
  uVar1 = *DAT_0e068670;
  uVar2 = (local_18 - uVar1) + param_1;
  iVar3 = ((local_14 - DAT_0e068670[1]) - (uint)(local_18 < uVar1)) +
          ((int)param_1 >> 0x1f) + (uint)CARRY4(local_18 - uVar1,param_1);
  if (uVar2 == 0 && iVar3 == 0) {
    uVar2 = 1;
    iVar3 = 0;
  }
  FUN_0e0697fc(DAT_0e068674,1,uVar2 + uVar1,DAT_0e068670[1] + iVar3 + (uint)CARRY4(uVar2,uVar1),1);
  return;
}


