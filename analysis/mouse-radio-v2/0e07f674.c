/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07f674. Types and names are inferred; NOT original source. */

void FUN_0e07f674(void)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  
  FUN_0e07ea0c(DAT_0e07f6e0,DAT_0e07f6dc,1);
  FUN_0e07e8c8(DAT_0e07f6e0,DAT_0e07f6dc,1);
  FUN_0e07eb74(DAT_0e07f6e4 + -0x11,DAT_0e07f6dc,DAT_0e07f6e4,DAT_0e07f6e8,1);
  pbVar3 = DAT_0e07f700;
  pbVar2 = DAT_0e07f6fc;
  if (*DAT_0e07f6ec != '\0') {
    iVar4 = (int)((ulonglong)DAT_0e07f6f4 * (ulonglong)*DAT_0e07f6f0 >> 0x20);
    if (-1 < iVar4 << 0x1a) {
      bVar1 = (byte)((uint)(iVar4 << 0x1a) >> 0x1f);
      *DAT_0e07f6f8 = bVar1;
      *pbVar2 = bVar1;
      *pbVar3 = bVar1;
      return;
    }
    *DAT_0e07f6f8 = 0;
    *pbVar2 = 0xff;
    *pbVar3 = 0;
  }
  return;
}


