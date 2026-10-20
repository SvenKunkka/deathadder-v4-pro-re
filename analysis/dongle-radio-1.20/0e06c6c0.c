/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06c6c0. Types and names are inferred; NOT original source. */

bool FUN_0e06c6c0(int param_1)

{
  byte bVar1;
  bool bVar2;
  
  bVar2 = false;
  if (param_1 != 0) {
    bVar1 = (*(char **)(param_1 + 0xc))[1];
    bVar2 = (bool)(bVar1 & 1);
    if ((bVar1 & 1) != 0) {
      bVar2 = **(char **)(param_1 + 0xc) == '\0';
    }
  }
  return bVar2;
}


