/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23021488. Types and names are inferred; NOT original source. */

short FUN_23021488(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  
  param_2 = param_2 + param_1 * 0xee0;
  uVar2 = (ushort)*(byte *)((int)&DAT_23002978 + param_2 + 0x164);
  uVar1 = (ushort)*(byte *)((int)&DAT_23002978 + param_2 + 0x15e);
  if (uVar2 != uVar1) {
    if (uVar2 < uVar1) {
      uVar2 = uVar2 + *(byte *)((int)&DAT_23002978 + param_2 + 0x16a);
    }
    return (uVar2 - 1) - uVar1;
  }
  return *(byte *)((int)&DAT_23002978 + param_2 + 0x16a) - 1;
}


