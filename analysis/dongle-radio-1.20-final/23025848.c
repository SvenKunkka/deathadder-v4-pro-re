/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23025848. Types and names are inferred; NOT original source. */

undefined4 FUN_23025848(void)

{
  int iVar1;
  undefined1 auStack_1c [4];
  uint local_18;
  
  DAT_230071b0 = 0;
  DAT_23002ca4 = &DAT_0e06f6cc;
  iVar1 = thunk_FUN_0e06c6c0();
  if (iVar1 != 0) {
    DAT_230071b0 = 1;
  }
  DAT_23001f68 = &DAT_0e06f6cc;
  iVar1 = thunk_FUN_0e06c6c0(&DAT_0e06f6cc);
  if (iVar1 != 0) {
    DAT_23001f30 = 0x1db000;
    iVar1 = thunk_FUN_0e067468(DAT_23001f68,0x1db000,auStack_1c);
    if (iVar1 == 0) {
      DAT_23001f4c = 0x2000 / local_18;
      DAT_23001f48 = local_18;
      iVar1 = thunk_FUN_0e05e6d4(&DAT_23001f30);
      if (iVar1 == 0) {
        DAT_23001fb0 = &DAT_0e06f6cc;
        iVar1 = thunk_FUN_0e06c6c0(&DAT_0e06f6cc);
        if (iVar1 != 0) {
          DAT_23001f78 = 0x1df000;
          iVar1 = thunk_FUN_0e067468(DAT_23001fb0,0x1df000,auStack_1c);
          if (iVar1 == 0) {
            DAT_23001f94 = 0x3000 / local_18;
            DAT_23001f90 = local_18;
            iVar1 = thunk_FUN_0e05e6d4(&DAT_23001f78);
            if (iVar1 == 0) {
              return 0;
            }
          }
        }
      }
    }
  }
  return 0xffffffea;
}


