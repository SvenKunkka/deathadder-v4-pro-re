/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f92a8. Types and names are inferred; NOT original source. */

void FUN_1c0f92a8(int param_1,uint param_2,byte param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_2 & 0xf;
  if ((int)(param_2 << 0x18) < 0) {
    uVar1 = uVar1 + 0x10;
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + uVar1 * 4);
  *(byte *)(iVar2 + 0x14) = *(byte *)(iVar2 + 0x14) & 0xef | (param_3 & 1) << 4;
  return;
}


