/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0612f0. Types and names are inferred; NOT original source. */

void FUN_0e0612f0(short param_1,char param_2,int param_3)

{
  uint uVar1;
  bool bVar2;
  
  bVar2 = -1 < param_3 << 0x1f;
  if (bVar2) {
    param_2 = (param_2 + '\x02') * ' ';
  }
  uVar1 = (uint)param_1;
  if (!bVar2) {
    param_2 = '\0';
  }
  if (-1 < (int)uVar1) {
    *(char *)(uVar1 + 0xe000e400) = param_2;
    return;
  }
  (&DAT_e000ed14)[uVar1 & 0xf] = param_2;
  return;
}


