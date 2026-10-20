/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e09587c. Types and names are inferred; NOT original source. */

void FUN_0e09587c(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (((undefined4 **)DAT_23007668 == &DAT_23007668) ||
     (puVar1 = DAT_23007668, DAT_23007668 == (undefined4 *)0x0)) {
    puVar1 = DAT_23007658;
  }
  if (((((param_1 != 0) || ((*(byte *)((int)DAT_23007654 + 0xd) & 0x1f) != 0)) || (puVar1[6] != 0))
      || (puVar2 = DAT_23007654, *(ushort *)((int)DAT_23007654 + 0xe) < 0x80)) &&
     (puVar2 = puVar1, puVar1 != DAT_23007654)) {
    FUN_0e096318(puVar1);
    DAT_23007664 = puVar1;
    return;
  }
  DAT_23007664 = puVar2;
  return;
}


