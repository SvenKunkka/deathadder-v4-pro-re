/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e0d48. Types and names are inferred; NOT original source. */

void FUN_1c0e0d48(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  piVar1 = DAT_1c0e0e20;
  if (*DAT_1c0e0e1c == '\0') {
    return;
  }
  FUN_1c0e2ebc();
  iVar3 = *piVar1;
  iVar2 = thunk_EXT_FUN_0e094688(iVar3);
  if (iVar2 != 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(iVar3 + 8) + 0x18);
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
      (*UNRECOVERED_JUMPTABLE)(iVar3,(char)piVar1[1],0x1400000,0x2000000);
    }
  }
  piVar1 = DAT_1c0e0e24;
  iVar3 = *DAT_1c0e0e24;
  iVar2 = thunk_EXT_FUN_0e094688(iVar3);
  if (iVar2 != 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(iVar3 + 8) + 0x18);
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
      (*UNRECOVERED_JUMPTABLE)(iVar3,(char)piVar1[1],0x1400000,0x2000000);
    }
  }
  piVar1 = DAT_1c0e0e28;
  iVar3 = *DAT_1c0e0e28;
  iVar2 = thunk_EXT_FUN_0e094688(iVar3);
  if (iVar2 != 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(iVar3 + 8) + 0x18);
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
      (*UNRECOVERED_JUMPTABLE)(iVar3,(char)piVar1[1],0x1400000,0x2000000);
    }
  }
  piVar1 = DAT_1c0e0e2c;
  iVar3 = *DAT_1c0e0e2c;
  iVar2 = thunk_EXT_FUN_0e094688(iVar3);
  if (iVar2 != 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(iVar3 + 8) + 0x18);
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
      (*UNRECOVERED_JUMPTABLE)(iVar3,(char)piVar1[1],0x1400000,0x2000000);
    }
  }
  iVar2 = DAT_1c0e0e34;
  if (*DAT_1c0e0e30 != '\0') {
    iVar3 = thunk_EXT_FUN_0e094688(*(undefined4 *)(DAT_1c0e0e34 + 0xc));
    if (iVar3 != 0) {
      iVar3 = *(int *)(iVar2 + 0xc);
      UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(iVar3 + 8) + 0x18);
      if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x1c0e0db8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)(iVar3,*(undefined1 *)(iVar2 + 0x10),0x1400000,0x2000000);
        return;
      }
    }
  }
  return;
}


