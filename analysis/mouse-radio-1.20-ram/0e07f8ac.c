/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07f8ac. Types and names are inferred; NOT original source. */

void FUN_0e07f8ac(byte *param_1,int param_2)

{
  byte *pbVar1;
  uint uVar2;
  
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  if (param_2 << 0x1f < 0) {
    uVar2 = 2;
    pbVar1 = (byte *)((int)&DAT_23006738 + 1);
    *param_1 = (byte)DAT_23006738;
    do {
      pbVar1 = pbVar1 + 1;
      if (*pbVar1 != 0) {
        param_1[uVar2] = *pbVar1;
        uVar2 = uVar2 + 1 & 0xff;
      }
    } while (pbVar1 != (byte *)((int)&DAT_2300673c + 3));
  }
  else {
    uVar2 = 2;
  }
  if (param_2 << 0x1e < 0) {
    *param_1 = *param_1 | (byte)DAT_23006740;
    pbVar1 = (byte *)((int)&DAT_23006740 + 1);
    do {
      pbVar1 = pbVar1 + 1;
      if (*pbVar1 != 0) {
        if (7 < uVar2) break;
        param_1[uVar2] = *pbVar1;
        uVar2 = uVar2 + 1 & 0xff;
      }
    } while (pbVar1 != (byte *)((int)&DAT_23006744 + 3));
  }
  if (param_2 << 0x1d < 0) {
    *param_1 = *param_1 | DAT_23006748;
    pbVar1 = &DAT_23006749;
    do {
      pbVar1 = pbVar1 + 1;
      if (*pbVar1 != 0) {
        if (7 < uVar2) {
          return;
        }
        param_1[uVar2] = *pbVar1;
        uVar2 = uVar2 + 1 & 0xff;
      }
    } while (pbVar1 != (byte *)((int)&DAT_2300674c + 3));
  }
  return;
}


