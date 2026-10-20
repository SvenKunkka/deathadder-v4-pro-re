/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07802c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e07802c(void)

{
  int iVar1;
  undefined4 local_24;
  undefined2 local_20;
  undefined1 local_1e;
  uint local_1c;
  
  local_1c = (uint)DAT_2300774b;
  if (local_1c == 0) {
    _DAT_5f9c2004 = 1;
    _DAT_5f9c200c = 1;
    local_24 = 16000000;
    local_20 = 0x300;
    local_1e = 3;
    iVar1 = FUN_0e0764a0(&DAT_0e099248,&local_24,0);
    if (iVar1 == 0xbad0000) {
LAB_0e07808a:
      FUN_0e078210();
      thunk_FUN_0e089e70(0x1c2,3,0);
      _DAT_e000e2b8 = 4;
      FUN_0e078e0c(0x1c2);
      DAT_2300774b = 1;
      return;
    }
    if (iVar1 == 0xbad000c) {
      FUN_0e076568(&DAT_0e099248);
      iVar1 = FUN_0e0764a0(&DAT_0e099248,&local_24,0);
      if (iVar1 == 0xbad0000) goto LAB_0e07808a;
    }
  }
  return;
}


