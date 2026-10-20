/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d9cc. Types and names are inferred; NOT original source. */

void FUN_0e06d9cc(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (((undefined4 **)DAT_23007180 == &DAT_23007180) ||
     (puVar1 = DAT_23007180, DAT_23007180 == (undefined4 *)0x0)) {
    puVar1 = DAT_23007174;
  }
  if (((((param_1 != 0) || ((*(byte *)((int)DAT_23007170 + 0xd) & 0x1f) != 0)) || (puVar1[6] != 0))
      || (puVar2 = DAT_23007170, *(ushort *)((int)DAT_23007170 + 0xe) < 0x80)) &&
     (puVar2 = puVar1, puVar1 != DAT_23007170)) {
    FUN_0e06e4ec(puVar1);
    DAT_2300717c = puVar1;
    return;
  }
  DAT_2300717c = puVar2;
  return;
}


