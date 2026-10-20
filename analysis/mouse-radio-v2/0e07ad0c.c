/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07ad0c. Types and names are inferred; NOT original source. */

void FUN_0e07ad0c(void)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  
  FUN_0e0977b0(DAT_0e07ad6c);
  FUN_0e0976f8(DAT_0e07ad6c);
  pbVar2 = DAT_0e07ad70;
  bVar1 = *DAT_0e07ad70;
  *DAT_0e07ad74 = 0;
  iVar3 = FUN_0e092abc(bVar1);
  if (iVar3 != 0) {
    FUN_0e092b3c(1 << (uint)*pbVar2);
  }
  FUN_0e07a4d8();
  iVar3 = DAT_0e07ad78;
  *(undefined4 *)(DAT_0e07ad78 + 0x400) = 0;
  *(undefined4 *)(iVar3 + 0x490) = 0xffffffff;
  *(undefined4 *)(iVar3 + 0x220) = 0;
  *(undefined4 *)(iVar3 + 0x10) = 1;
  do {
  } while (*(int *)(iVar3 + 0x220) == 0);
  *(undefined4 *)(iVar3 + 0x220) = 0;
  return;
}


