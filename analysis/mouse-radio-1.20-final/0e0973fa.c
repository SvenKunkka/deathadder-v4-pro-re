/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0973fa. Types and names are inferred; NOT original source. */

int FUN_0e0973fa(byte *param_1,int param_2,int param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  
  pbVar1 = (byte *)(param_2 + -1);
  pbVar2 = param_1 + param_3;
  while( true ) {
    if (param_1 == pbVar2) {
      return 0;
    }
    pbVar1 = pbVar1 + 1;
    if ((uint)*param_1 != (uint)*pbVar1) break;
    param_1 = param_1 + 1;
  }
  return (uint)*param_1 - (uint)*pbVar1;
}


