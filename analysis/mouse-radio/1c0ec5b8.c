/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0ec5b8. Types and names are inferred; NOT original source. */

void FUN_1c0ec5b8(undefined2 param_1,undefined2 param_2)

{
  byte bVar1;
  byte *pbVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  
  puVar3 = DAT_1c0ec5d8;
  pbVar2 = DAT_1c0ec5d4;
  bVar1 = *DAT_1c0ec5d4;
  *DAT_1c0ec5d8 = param_1;
  *pbVar2 = bVar1 | 1;
  puVar4 = DAT_1c0ec5dc;
  puVar3[1] = param_2;
  *puVar4 = param_1;
  puVar4[1] = param_2;
  return;
}


