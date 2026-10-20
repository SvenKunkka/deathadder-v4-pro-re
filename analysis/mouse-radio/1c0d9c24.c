/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0d9c24. Types and names are inferred; NOT original source. */

short FUN_1c0d9c24(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  
  param_2 = param_2 + param_1 * 0xee0 + DAT_1c0d9c5c;
  uVar2 = (ushort)*(byte *)(param_2 + 0x164);
  uVar1 = (ushort)*(byte *)(param_2 + 0x15e);
  if (uVar2 != uVar1) {
    if (uVar2 < uVar1) {
      uVar2 = uVar2 + *(byte *)(param_2 + 0x16a);
    }
    return (uVar2 - 1) - uVar1;
  }
  return *(byte *)(param_2 + 0x16a) - 1;
}


