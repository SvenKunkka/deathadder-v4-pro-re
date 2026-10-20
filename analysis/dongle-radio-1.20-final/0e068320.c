/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068320. Types and names are inferred; NOT original source. */

uint FUN_0e068320(int param_1)

{
  int iVar1;
  uint uVar2;
  
  FUN_0e0612f0(0x1c4,1,0);
  iVar1 = FUN_0e069b50(*(int *)(param_1 + 4),*(int *)(param_1 + 4) + 8,&DAT_0e0680bd,
                       *(undefined4 *)(param_1 + 0x10));
  if (iVar1 == 0xbad0000) {
    uVar2 = FUN_0e0680d0(param_1);
    return uVar2 & (int)uVar2 >> 0x1f;
  }
  return 0xfffffff0;
}


