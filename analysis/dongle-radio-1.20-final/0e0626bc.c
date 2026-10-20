/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0626bc. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0626bc(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  code *UNRECOVERED_JUMPTABLE_00;
  
  bVar3 = *(byte *)(param_1 + 0x20) & 0x1f;
  if (bVar3 == 1) {
    iVar1 = FUN_0e063a60(param_1,*(undefined1 *)(param_1 + 0x24));
  }
  else if (bVar3 == 2) {
    iVar1 = FUN_0e063a94(param_1,*(undefined1 *)(param_1 + 0x24));
  }
  else {
    if ((*(byte *)(param_1 + 0x20) & 0x1f) != 0) goto LAB_0e0626d4;
    iVar1 = FUN_0e063ad8(param_1,*(undefined1 *)(param_1 + 0x21));
  }
  if (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 4);
    if ((*(short *)(param_1 + 0x26) == 0) || (-1 < *(char *)(param_1 + 0x20))) {
      UNRECOVERED_JUMPTABLE_00 = *(code **)(*(int *)(iVar1 + 8) + 8);
      if (UNRECOVERED_JUMPTABLE_00 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0e062712. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (*UNRECOVERED_JUMPTABLE_00)(iVar1,param_1 + 0x20,param_2);
        return uVar2;
      }
    }
    else {
      UNRECOVERED_JUMPTABLE_00 = *(code **)(*(int *)(iVar1 + 8) + 0xc);
      if (UNRECOVERED_JUMPTABLE_00 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0e062720. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (*UNRECOVERED_JUMPTABLE_00)(iVar1,param_1 + 0x20,param_2);
        return uVar2;
      }
    }
  }
LAB_0e0626d4:
  iVar1 = FUN_0e06f4ac();
  *(undefined4 *)(iVar1 + 0xc) = 0xffffff7a;
  return 0;
}


