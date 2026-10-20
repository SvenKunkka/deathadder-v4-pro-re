/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d128. Types and names are inferred; NOT original source. */

void FUN_0e05d128(void)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  
  FUN_0e069ff8(DAT_0e05d188);
  FUN_0e06a018(DAT_0e05d188);
  pbVar2 = DAT_0e05d18c;
  bVar1 = *DAT_0e05d18c;
  *DAT_0e05d190 = 0;
  iVar3 = FUN_0e06ab68(bVar1);
  if (iVar3 != 0) {
    FUN_0e06abe8(1 << (uint)*pbVar2);
  }
  FUN_0e05c8f4();
  iVar3 = DAT_0e05d194;
  *(undefined4 *)(DAT_0e05d194 + 0x400) = 0;
  *(undefined4 *)(iVar3 + 0x490) = 0xffffffff;
  *(undefined4 *)(iVar3 + 0x220) = 0;
  *(undefined4 *)(iVar3 + 0x10) = 1;
  do {
  } while (*(int *)(iVar3 + 0x220) == 0);
  *(undefined4 *)(iVar3 + 0x220) = 0;
  return;
}


