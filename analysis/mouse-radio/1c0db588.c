/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0db588. Types and names are inferred; NOT original source. */

void FUN_1c0db588(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_34 [4];
  undefined4 local_30;
  undefined4 local_14;
  
  iVar1 = DAT_1c0db5bc;
  if (*(short *)(DAT_1c0db5bc + 2) != 1) {
    local_30 = *(undefined4 *)(DAT_1c0db5bc + 0x18);
    local_14 = 4;
    *(undefined2 *)(DAT_1c0db5bc + 2) = 1;
    FUN_1c0da088(auStack_34);
    FUN_1c0d9cc4(0);
    uVar2 = DAT_1c0db5c0;
    *(undefined1 *)(iVar1 + 0x27) = 1;
    thunk_EXT_FUN_0e095414(uVar2);
  }
  return;
}


