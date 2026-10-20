/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0de448. Types and names are inferred; NOT original source. */

void FUN_1c0de448(int param_1)

{
  short *psVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 local_30 [36];
  
  iVar2 = DAT_1c0de4a4;
  psVar1 = (short *)(DAT_1c0de4a4 + 0x12);
  *(bool *)(DAT_1c0de4a4 + 0xf) = param_1 != 0;
  if (*psVar1 == 0) {
    FUN_1c0db524();
  }
  else {
    local_30[0] = 0xa4;
    FUN_1c0de24c(0,3,local_30,1,0xff);
    puVar3 = DAT_1c0de4a8;
    *DAT_1c0de4a8 = DAT_1c0de4ac;
    thunk_EXT_FUN_0e096b78(DAT_1c0de4b0,puVar3,0x61b,0,0,0);
  }
  *(undefined1 *)(iVar2 + 0xc) = 0;
  *(undefined2 *)(iVar2 + 0x12) = 0;
  thunk_EXT_FUN_0e096bec(DAT_1c0de4b4);
  return;
}


