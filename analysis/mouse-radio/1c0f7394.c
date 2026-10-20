/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f7394. Types and names are inferred; NOT original source. */

undefined4 FUN_1c0f7394(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  code *UNRECOVERED_JUMPTABLE_00;
  
  bVar3 = *(byte *)(param_1 + 0x20) & 0x1f;
  if (bVar3 == 1) {
    iVar1 = FUN_1c0f8738(param_1,*(undefined1 *)(param_1 + 0x24));
  }
  else if (bVar3 == 2) {
    iVar1 = FUN_1c0f876c(param_1,*(undefined1 *)(param_1 + 0x24));
  }
  else {
    if ((*(byte *)(param_1 + 0x20) & 0x1f) != 0) goto LAB_1c0f73ac;
    iVar1 = FUN_1c0f87b0(param_1,*(undefined1 *)(param_1 + 0x21));
  }
  if (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 4);
    if ((*(short *)(param_1 + 0x26) == 0) || (-1 < *(char *)(param_1 + 0x20))) {
      UNRECOVERED_JUMPTABLE_00 = *(code **)(*(int *)(iVar1 + 8) + 8);
      if (UNRECOVERED_JUMPTABLE_00 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x1c0f73ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (*UNRECOVERED_JUMPTABLE_00)(iVar1,param_1 + 0x20,param_2);
        return uVar2;
      }
    }
    else {
      UNRECOVERED_JUMPTABLE_00 = *(code **)(*(int *)(iVar1 + 8) + 0xc);
      if (UNRECOVERED_JUMPTABLE_00 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x1c0f73f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (*UNRECOVERED_JUMPTABLE_00)(iVar1,param_1 + 0x20,param_2);
        return uVar2;
      }
    }
  }
LAB_1c0f73ac:
  iVar1 = FUN_1c103614();
  *(undefined4 *)(DAT_1c0f7410 + iVar1) = 0xffffff7a;
  return 0;
}


