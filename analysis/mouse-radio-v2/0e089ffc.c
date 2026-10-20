/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e089ffc. Types and names are inferred; NOT original source. */

void FUN_0e089ffc(short param_1,char param_2)

{
  uint uVar1;
  char cVar2;
  
  uVar1 = (uint)param_1;
  cVar2 = (param_2 + '\x01') * ' ';
  if (-1 < (int)uVar1) {
    *(char *)(uVar1 + 0xe000e400) = cVar2;
    return;
  }
  *(char *)(DAT_0e08a024 + (uVar1 & 0xf) + 0x18) = cVar2;
  return;
}


