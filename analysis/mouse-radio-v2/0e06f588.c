/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e06f588. Types and names are inferred; NOT original source. */

void FUN_0e06f588(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_34 [4];
  undefined4 local_30;
  undefined4 local_14;
  
  iVar1 = DAT_0e06f5bc;
  if (*(short *)(DAT_0e06f5bc + 2) != 1) {
    local_30 = *(undefined4 *)(DAT_0e06f5bc + 0x18);
    local_14 = 4;
    *(undefined2 *)(DAT_0e06f5bc + 2) = 1;
    FUN_0e06e088(auStack_34);
    FUN_0e06dcc4(0);
    uVar2 = DAT_0e06f5c0;
    *(undefined1 *)(iVar1 + 0x27) = 1;
    thunk_FUN_0e095414(uVar2);
  }
  return;
}


