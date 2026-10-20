/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e090a18. Types and names are inferred; NOT original source. */

int FUN_0e090a18(undefined4 param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  
  DAT_23007278 = param_1;
  iVar1 = FUN_0e094f64(&DAT_23007230,8);
  if (-1 < iVar1) {
    DAT_2300722c = 0xff000000;
    FUN_0e094ab0(&DAT_23007240,&DAT_23007268,8,2);
    puVar4 = &DAT_23011ee0;
    puVar2 = &DAT_230021c8;
    do {
      puVar3 = puVar2 + 0x90;
      FUN_0e0957a8(puVar2,puVar4,0x400,0xe0909ed,0,0,0,2,0);
      puVar4 = puVar4 + 0x400;
      puVar2 = puVar3;
    } while (puVar3 != &DAT_23002378);
    iVar1 = 0;
  }
  return iVar1;
}


