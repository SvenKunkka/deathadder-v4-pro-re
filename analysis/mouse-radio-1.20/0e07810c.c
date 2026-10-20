/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07810c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e07810c(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_24;
  undefined2 local_20;
  undefined1 local_1e;
  uint local_1c;
  
  local_1c = (uint)DAT_2300774d;
  if (local_1c == 0) {
    local_24 = 16000000;
    local_20 = 0x300;
    local_1e = 3;
    iVar1 = FUN_0e0764a0(&DAT_0e099258,&local_24,0);
    if (iVar1 == 0xbad0000) {
LAB_0e078158:
      _DAT_5f9a2540 = 0;
      _DAT_5f9a2544 = 0;
      _DAT_5f9a2548 = 0;
      _DAT_5f9a254c = 0;
      _DAT_5f9a2550 = 0;
      _DAT_5f9a2554 = 0;
      _DAT_5f9a2200 = _DAT_5f9a2200 & 0xff00ff00;
      _DAT_5f9a2308 = 0xff0000;
      uVar2 = FUN_0e0765b8(&DAT_0e099258,0x14);
      FUN_0e076440(&DAT_0e099258,0,uVar2,0x10000,1);
      thunk_FUN_0e089e70(0x1a2,3,0);
      _DAT_e000e2b4 = 4;
      FUN_0e078e0c(0x1a2);
      DAT_2300774d = 1;
      return;
    }
    if (iVar1 == 0xbad000c) {
      FUN_0e076568(&DAT_0e099258);
      iVar1 = FUN_0e0764a0(&DAT_0e099258,&local_24,0);
      if (iVar1 == 0xbad0000) goto LAB_0e078158;
    }
  }
  return;
}


