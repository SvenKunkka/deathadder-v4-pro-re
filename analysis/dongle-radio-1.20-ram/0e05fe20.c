/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05fe20. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05fe20(int param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_2 < 0) {
    return 0xffffffea;
  }
  if ((uint)(param_4 + param_2) <= *(uint *)(param_1 + 8)) {
                    /* WARNING: Could not recover jumptable at 0x0e05fe46. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0xc) + 8) + 4))
                      (*(int *)(param_1 + 0xc),param_2 + *(int *)(param_1 + 4));
    return uVar1;
  }
  return 0xffffffea;
}


