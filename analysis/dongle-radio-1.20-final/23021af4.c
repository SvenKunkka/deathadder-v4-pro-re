/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021af4. Types and names are inferred; NOT original source. */

undefined4 FUN_23021af4(int param_1)

{
  byte bVar1;
  uint uVar2;
  bool bVar3;
  
  if (DAT_230031aa != 0) {
    DAT_230031aa = DAT_230031aa + -1;
    return 0;
  }
  uVar2 = (uint)DAT_230031a8;
  (&DAT_23003452)[param_1 * 0xf84] = (&DAT_230003e8)[uVar2];
  DAT_230031a7 = DAT_230031a7 + 1;
  bVar1 = DAT_230031a8;
  if (9 < DAT_230031a7) {
    uVar2 = uVar2 + 1;
    DAT_230031a7 = 0;
    if ((uVar2 & 0xff) < 0x17) {
      DAT_230031a8 = (char)uVar2;
      return 1;
    }
    DAT_230031a8 = 0;
    bVar3 = DAT_230031a6 != 0xff;
    DAT_230031a6 = 0;
    bVar1 = 0;
    if (bVar3) {
      if (DAT_230033e8 == 3) {
        DAT_230031aa = 200;
      }
      else {
        DAT_230031aa = 5000;
      }
      DAT_230031a6 = 0;
      DAT_230031a9 = 1;
      bVar1 = DAT_230031a8;
    }
  }
  DAT_230031a8 = bVar1;
  return 1;
}


