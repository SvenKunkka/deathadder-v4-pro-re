/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026c58. Types and names are inferred; NOT original source. */

undefined4 FUN_23026c58(void)

{
  int iVar1;
  undefined4 in_r3;
  int iVar2;
  undefined4 *puVar3;
  undefined **ppuVar4;
  
  iVar2 = 0;
  DAT_23006900 = 0;
  DAT_23006902 = 0;
  DAT_230071e4 = 0;
  ppuVar4 = &PTR_LAB_23026c3c_1_23000420;
  puVar3 = &DAT_0e06fd34;
  DAT_23006904 = 0;
  DAT_23006908 = 0;
  DAT_23006906 = 0;
  DAT_2300690a = 0;
  DAT_230071e6 = 1;
  while( true ) {
    iVar1 = iVar2 * 2;
    iVar2 = iVar2 + 1;
    if ((&DAT_0e06fd1c)[iVar1] == 0) {
      return 1;
    }
    iVar1 = thunk_FUN_0e06450c((&DAT_0e06fd1c)[iVar1],*puVar3,*(undefined2 *)(puVar3 + 1),ppuVar4,
                               in_r3);
    puVar3 = puVar3 + 2;
    ppuVar4 = ppuVar4 + 9;
    if (iVar1 != 0) break;
    if (iVar2 == 3) {
      DAT_2300690c = thunk_FUN_0e05bd18(&LAB_23026b08_1);
      return 1;
    }
  }
  return 1;
}


