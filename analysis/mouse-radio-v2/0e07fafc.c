/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07fafc. Types and names are inferred; NOT original source. */

uint FUN_0e07fafc(int param_1,int param_2,ushort *param_3)

{
  uint uVar1;
  byte *pbVar2;
  
  if (param_3 == (ushort *)0x0) {
    uVar1 = 0xffff;
  }
  else {
    uVar1 = (uint)*param_3;
  }
  if (param_2 != 0) {
    pbVar2 = (byte *)(param_1 + -1);
    do {
      pbVar2 = pbVar2 + 1;
      uVar1 = ((uVar1 & 0xff) << 8 | uVar1 >> 8) ^ (uint)*pbVar2;
      uVar1 = (uVar1 & 0xff) >> 4 ^ uVar1;
      uVar1 = uVar1 ^ uVar1 << 0xc;
      uVar1 = (uVar1 & 0xff) << 5 ^ uVar1 & 0xffff;
    } while (pbVar2 != (byte *)(param_2 + param_1 + -1));
  }
  return uVar1;
}


