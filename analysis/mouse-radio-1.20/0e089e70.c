/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e089e70. Types and names are inferred; NOT original source. */

void FUN_0e089e70(short param_1,char param_2)

{
  uint uVar1;
  char cVar2;
  
  uVar1 = (uint)param_1;
  cVar2 = (param_2 + '\x01') * ' ';
  if (-1 < (int)uVar1) {
    *(char *)(uVar1 + 0xe000e400) = cVar2;
    return;
  }
  (&DAT_e000ed14)[uVar1 & 0xf] = cVar2;
  return;
}


