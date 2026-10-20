/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07ece0. Types and names are inferred; NOT original source. */

void FUN_0e07ece0(void)

{
  byte bVar1;
  byte *pbVar2;
  
  pbVar2 = DAT_0e07ed04;
  bVar1 = *DAT_0e07ed04;
  *DAT_0e07ed00 = *DAT_0e07ed00 + '\x01';
  if ((int)((uint)bVar1 << 0x1e) < 0) {
    *(short *)(pbVar2 + 0x24) = *(short *)(pbVar2 + 0x24) + 1;
  }
  *(short *)(DAT_0e07ed08 + 0x22) = *(short *)(DAT_0e07ed08 + 0x22) + 1;
  return;
}


