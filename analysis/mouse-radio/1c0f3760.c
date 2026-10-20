/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f3760. Types and names are inferred; NOT original source. */

undefined4 FUN_1c0f3760(int param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    return 0xffffffea;
  }
  if (param_3 == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    iVar2 = *(int *)(param_1 + 8);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0xc) != 0)) {
      *param_2 = param_1;
                    /* WARNING: Could not recover jumptable at 0x1c0f3778. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (**(code **)(iVar2 + 0xc))(param_1,param_2 + 1);
      return uVar1;
    }
    uVar1 = 0xfffffffb;
  }
  return uVar1;
}


