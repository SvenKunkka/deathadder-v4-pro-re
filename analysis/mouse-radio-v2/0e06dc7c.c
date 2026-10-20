/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e06dc7c. Types and names are inferred; NOT original source. */

int FUN_0e06dc7c(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1 * 0xee0 + DAT_0e06dcc0;
  iVar1 = iVar2 + (param_2 & 0xff);
  if (*(char *)(iVar1 + 0x164) != *(char *)(iVar1 + 0x15e)) {
    iVar2 = iVar2 + param_2;
    iVar1 = (uint)*(byte *)(iVar2 + 0x164) * (uint)*(byte *)(iVar2 + 0x170) +
            *(int *)(DAT_0e06dcc0 + (param_1 * 0x3b8 + param_2 + 0x5e) * 4);
    *(undefined1 *)(iVar1 + 2) = 1;
    return iVar1 + 4;
  }
  return 0;
}


