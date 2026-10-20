/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07833c. Types and names are inferred; NOT original source. */

void FUN_0e07833c(void)

{
  char *pcVar1;
  int iVar2;
  sbyte *psVar3;
  
  iVar2 = DAT_0e078370;
  pcVar1 = DAT_0e07836c;
  if (*DAT_0e07836c != '\0') {
    return;
  }
  *(undefined4 *)(DAT_0e078370 + 0xc04) = 2;
  *(undefined4 *)(iVar2 + 0xc04) = 3;
  psVar3 = DAT_0e078374;
  *(undefined4 *)(iVar2 + 0xc80) = 0x82;
  FUN_0e078d74(1 << *psVar3);
  *pcVar1 = '\x01';
  return;
}


