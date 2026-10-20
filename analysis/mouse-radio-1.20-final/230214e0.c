/* Automatically decompiled from Suit2FWData__radio_radio.bin at 230214e0. Types and names are inferred; NOT original source. */

int FUN_230214e0(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = (param_2 & 0xff) + param_1 * 0xee0;
  if (*(char *)((int)&DAT_23002978 + iVar1 + 0x164) != *(char *)((int)&DAT_23002978 + iVar1 + 0x15e)
     ) {
    iVar1 = param_2 + param_1 * 0xee0;
    iVar1 = (uint)*(byte *)((int)&DAT_23002978 + iVar1 + 0x164) *
            (uint)*(byte *)((int)&DAT_23002978 + iVar1 + 0x170) +
            (&DAT_23002978)[param_1 * 0x3b8 + param_2 + 0x5e];
    *(undefined1 *)(iVar1 + 2) = 1;
    return iVar1 + 4;
  }
  return 0;
}


