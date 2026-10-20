/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e077d64. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e077d64(void)

{
  int iVar1;
  undefined4 local_24;
  undefined2 local_20;
  undefined1 local_1e;
  uint local_1c;
  
  local_1c = (uint)DAT_2300774c;
  if (local_1c == 0) {
    _DAT_5f9b2004 = 1;
    _DAT_5f9b200c = 1;
    local_24 = 16000000;
    local_20 = 0x300;
    local_1e = 4;
    DAT_23004ce4 = local_1c;
    iVar1 = FUN_0e0764a0(&DAT_0e099250,&local_24,0);
    if (iVar1 == 0xbad0000) {
LAB_0e077dc8:
      FUN_0e077ca0();
      thunk_FUN_0e089e70(0x1b2,4,0);
      _DAT_e000e2b4 = 0x40000;
      FUN_0e078e0c(0x1b2);
      DAT_2300774c = 1;
      return;
    }
    if (iVar1 == 0xbad000c) {
      FUN_0e076568(&DAT_0e099250);
      iVar1 = FUN_0e0764a0(&DAT_0e099250,&local_24,0);
      if (iVar1 == 0xbad0000) goto LAB_0e077dc8;
    }
  }
  return;
}


