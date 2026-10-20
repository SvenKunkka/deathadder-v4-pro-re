/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e3ee0. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0e3ee0(int param_1,code *UNRECOVERED_JUMPTABLE)

{
  int iVar1;
  uint uVar2;
  
  *(code **)(param_1 + 0x1c) = UNRECOVERED_JUMPTABLE;
  uVar2 = (_DAT_2f011758 & 3) >> 1;
  if ((int)(_DAT_2f011758 << 0x1e) < 0) {
    iVar1 = FUN_0e0e4944(*(undefined1 *)(param_1 + 0x20),1,param_1);
    if (iVar1 == 0) {
      return;
    }
    uVar2 = 0xfffffffb;
  }
                    /* WARNING: Could not recover jumptable at 0x0e0e3efc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,uVar2);
  return;
}


