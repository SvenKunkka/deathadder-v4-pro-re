/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e4308. Types and names are inferred; NOT original source. */

void FUN_1c0e4308(void)

{
  char *pcVar1;
  int iVar2;
  byte *pbVar3;
  
  pbVar3 = DAT_1c0e4338;
  iVar2 = DAT_1c0e4334;
  pcVar1 = DAT_1c0e4330;
  if (*DAT_1c0e4330 == '\0') {
    return;
  }
  *(undefined4 *)(DAT_1c0e4334 + 0xc80) = 0;
  *(undefined4 *)(iVar2 + 0xc04) = 0;
  thunk_EXT_FUN_0e092b3c(1 << (uint)*pbVar3);
  *pcVar1 = '\0';
  return;
}


