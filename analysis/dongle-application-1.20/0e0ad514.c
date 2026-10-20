/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ad514. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0ad514(int param_1,code *UNRECOVERED_JUMPTABLE)

{
  int iVar1;
  uint uVar2;
  
  *(code **)(param_1 + 0x1c) = UNRECOVERED_JUMPTABLE;
  uVar2 = (_DAT_2f0119f0 & 3) >> 1;
  if ((int)(_DAT_2f0119f0 << 0x1e) < 0) {
    iVar1 = FUN_0e0aec24(*(undefined1 *)(param_1 + 0x20),1,param_1);
    if (iVar1 == 0) {
      return;
    }
    uVar2 = 0xfffffffb;
  }
                    /* WARNING: Could not recover jumptable at 0x0e0ad530. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,uVar2);
  return;
}


