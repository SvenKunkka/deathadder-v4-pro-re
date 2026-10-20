/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e433c. Types and names are inferred; NOT original source. */

void FUN_1c0e433c(void)

{
  char *pcVar1;
  int iVar2;
  sbyte *psVar3;
  
  iVar2 = DAT_1c0e4370;
  pcVar1 = DAT_1c0e436c;
  if (*DAT_1c0e436c != '\0') {
    return;
  }
  *(undefined4 *)(DAT_1c0e4370 + 0xc04) = 2;
  *(undefined4 *)(iVar2 + 0xc04) = 3;
  psVar3 = DAT_1c0e4374;
  *(undefined4 *)(iVar2 + 0xc80) = 0x82;
  thunk_EXT_FUN_0e092b18(1 << *psVar3);
  *pcVar1 = '\x01';
  return;
}


