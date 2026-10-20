/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07f944. Types and names are inferred; NOT original source. */

uint FUN_0e07f944(byte *param_1,int param_2)

{
  uint uVar1;
  byte *pbVar2;
  uint uVar4;
  byte *pbVar3;
  
  uVar1 = 0xffff;
  if (param_2 != 0) {
    pbVar3 = param_1;
    do {
      pbVar2 = pbVar3 + 1;
      uVar4 = (uint)*pbVar3 ^ uVar1 >> 8;
      uVar4 = uVar4 ^ uVar4 >> 4;
      uVar1 = ((uVar4 | uVar1 << 8) ^ uVar4 << 0xc ^ uVar4 << 5) & 0xffff;
      pbVar3 = pbVar2;
    } while (pbVar2 != param_1 + param_2);
    return uVar1;
  }
  return 0xffff;
}


