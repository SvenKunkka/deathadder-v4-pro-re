/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e091e34. Types and names are inferred; NOT original source. */

undefined4 FUN_0e091e34(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(DAT_0e091e54 + (uint)*(byte *)(param_1 + 4) * 0x10);
  if (cVar1 == '\0') {
    return DAT_0e091e60;
  }
  if (cVar1 != '\x02') {
    FUN_0e091d88();
    return DAT_0e091e58;
  }
  return DAT_0e091e5c;
}


