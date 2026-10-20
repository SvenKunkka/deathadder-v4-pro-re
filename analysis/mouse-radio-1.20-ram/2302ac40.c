/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302ac40. Types and names are inferred; NOT original source. */

void FUN_2302ac40(byte param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  DAT_2fc13041 = 0;
  DAT_23004cdc = param_2 + 2;
  DAT_2fc13040 = param_1 & 0x7f;
  DAT_23004ce0 = 2;
  if (DAT_230004d8._2_1_ == -0x72) {
    thunk_FUN_0e085e6c("tx DMA not accessible\n");
    if (DAT_230004d8._2_1_ == -0x72) {
      thunk_FUN_0e085e6c("rx DMA not accessible\n");
    }
  }
  uVar3 = DAT_23004ce0;
  iVar1 = DAT_230004d8;
  *(undefined1 **)(DAT_230004d8 + 0x73c) = &DAT_2fc13040;
  *(undefined4 *)(iVar1 + 0x740) = uVar3;
  iVar2 = DAT_23004cdc;
  *(undefined4 *)(iVar1 + 0x704) = 0x2fc13000;
  *(int *)(iVar1 + 0x708) = iVar2;
  *(undefined4 *)(iVar1 + 0x108) = 0;
  DAT_23007745 = 1;
  return;
}


