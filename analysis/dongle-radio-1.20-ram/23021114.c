/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021114. Types and names are inferred; NOT original source. */

void FUN_23021114(byte *param_1)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  if (DAT_230031f6 != 0) {
    pbVar2 = (byte *)((int)&DAT_230031aa + 1);
    do {
      while( true ) {
        pbVar1 = pbVar2 + 1;
        uVar4 = (uint)*pbVar1;
        if (uVar4 < 8) break;
        if (0xf < uVar4) {
          if (uVar4 < 0x18) {
            param_1[2] = (byte)(1 << (uVar4 - 0x10 & 0xff)) | param_1[2];
          }
          else if (uVar4 < 0x20) {
            param_1[3] = (byte)(1 << (uVar4 - 0x18 & 0xff)) | param_1[3];
          }
          else if (uVar4 < 0x28) {
            param_1[4] = (byte)(1 << (uVar4 - 0x20 & 0xff)) | param_1[4];
          }
          goto LAB_2302113c;
        }
        param_1[1] = (byte)(1 << (uVar4 - 8 & 0xff)) | param_1[1];
        pbVar3 = pbVar2 + -0x230031aa;
        pbVar2 = pbVar1;
        if ((int)(uint)DAT_230031f6 <= (int)pbVar3) {
          return;
        }
      }
      *param_1 = *param_1 | (byte)(1 << uVar4);
LAB_2302113c:
      pbVar3 = pbVar2 + -0x230031aa;
      pbVar2 = pbVar1;
    } while ((int)pbVar3 < (int)(uint)DAT_230031f6);
  }
  return;
}


