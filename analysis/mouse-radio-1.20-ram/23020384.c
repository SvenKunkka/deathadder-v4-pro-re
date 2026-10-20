/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23020384. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ram_candidate_23020384(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + -8);
  *(int *)(param_1 + -8) = iVar1 + 1;
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x58) = 0xfffffff0;
    return;
  }
  _DAT_5f982500 = 1;
  if (*(char *)(param_1 + 0x6e) == '\0') {
    _DAT_5f982000 = 1;
    _DAT_5f982004 = 1;
    return;
  }
  _DAT_5f98200c = 1;
  return;
}


