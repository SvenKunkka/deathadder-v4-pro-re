/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068608. Types and names are inferred; NOT original source. */

int FUN_0e068608(undefined4 param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  
  DAT_23006e00 = param_1;
  iVar1 = FUN_0e06d0b4(&DAT_23006db8,8);
  if (-1 < iVar1) {
    DAT_23006db4 = 0xff000000;
    FUN_0e06cbb8(&DAT_23006dc8,&DAT_23006df0,8,2);
    puVar4 = &DAT_23011d00;
    puVar2 = &DAT_23002848;
    do {
      puVar3 = puVar2 + 0x90;
      FUN_0e06d8f8(puVar2,puVar4,0x400,0xe0685dd,0,0,0,2,0);
      puVar4 = puVar4 + 0x400;
      puVar2 = puVar3;
    } while (puVar3 != &DAT_230029f8);
    iVar1 = 0;
  }
  return iVar1;
}


