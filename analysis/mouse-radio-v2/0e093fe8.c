/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e093fe8. Types and names are inferred; NOT original source. */

void FUN_0e093fe8(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined4 param_5)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(param_4 + 1);
  while( true ) {
    if ((byte *)*param_4 <= pbVar1) {
      FUN_0e093d24(param_5);
      FUN_0e093f3c(0xfffffffe,0,param_5,param_1);
      return;
    }
    if (*pbVar1 == param_1) break;
    pbVar1 = pbVar1 + 0xc;
  }
                    /* WARNING: Could not recover jumptable at 0x0e09401a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(pbVar1 + 4))(param_5,param_2,param_3,*(undefined4 *)(pbVar1 + 8));
  return;
}


