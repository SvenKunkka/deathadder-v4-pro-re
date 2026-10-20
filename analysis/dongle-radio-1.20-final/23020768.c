/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020768. Types and names are inferred; NOT original source. */

short FUN_23020768(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  
  param_2 = param_2 + param_1 * 0xf84;
  uVar2 = (ushort)*(byte *)((int)&DAT_230033e8 + param_2 + 0x15a);
  uVar1 = (ushort)*(byte *)((int)&DAT_230033e8 + param_2 + 0x154);
  if (uVar2 != uVar1) {
    if (uVar2 < uVar1) {
      uVar2 = uVar2 + *(byte *)((int)&DAT_230033e8 + param_2 + 0x160);
    }
    return (uVar2 - 1) - uVar1;
  }
  return *(byte *)((int)&DAT_230033e8 + param_2 + 0x160) - 1;
}


