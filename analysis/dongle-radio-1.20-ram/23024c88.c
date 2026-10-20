/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23024c88. Types and names are inferred; NOT original source. */

undefined4 FUN_23024c88(int param_1,char *param_2)

{
  char cVar1;
  
  cVar1 = *param_2;
  if (cVar1 != -0x55) {
    if (cVar1 != -0x54) {
      if (cVar1 != -0x5c) {
        return 0;
      }
      DAT_230065e2 = 0x50000;
      DAT_23006590 = 0;
      FUN_230201b4(1,0);
      FUN_230203fc(0x14,0,0);
      return 1;
    }
    *(char *)((int)&DAT_230065b0 + param_1 + 2) = param_2[1];
  }
  return 1;
}


