/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230207ec. Types and names are inferred; NOT original source. */

int FUN_230207ec(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = (param_2 & 0xff) + param_1 * 0xf84;
  if (*(char *)((int)&DAT_230033e8 + iVar1 + 0x15a) != *(char *)((int)&DAT_230033e8 + iVar1 + 0x154)
     ) {
    iVar1 = param_2 + param_1 * 0xf84;
    iVar1 = (uint)*(byte *)((int)&DAT_230033e8 + iVar1 + 0x15a) *
            (uint)*(byte *)((int)&DAT_230033e8 + iVar1 + 0x166) +
            *(int *)(&DAT_23003554 + (param_2 + param_1 * 0x3e1) * 4);
    *(undefined1 *)(iVar1 + 2) = 1;
    return iVar1 + 4;
  }
  return 0;
}


