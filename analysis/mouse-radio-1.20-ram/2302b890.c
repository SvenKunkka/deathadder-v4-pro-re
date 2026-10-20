/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302b890. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2302b890(void)

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
    iVar1 = FUN_23029d04(&DAT_0e099248,&local_24,0);
    if (iVar1 == 0xbad0000) {
LAB_2302b8ee:
      FUN_2302ba74();
      thunk_FUN_0e089e70(0x1c2,3,0);
      _DAT_e000e2b8 = 4;
      thunk_FUN_0e089e2c(0x1c2);
      DAT_2300774b = 1;
      return;
    }
    if (iVar1 == 0xbad000c) {
      FUN_23029dcc(&DAT_0e099248);
      iVar1 = FUN_23029d04(&DAT_0e099248,&local_24,0);
      if (iVar1 == 0xbad0000) goto LAB_2302b8ee;
    }
  }
  return;
}


