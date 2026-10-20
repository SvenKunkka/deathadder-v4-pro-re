/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e077f14. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e077f14(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_24;
  undefined2 local_20;
  undefined1 local_1e;
  uint local_1c;
  
  local_1c = (uint)DAT_2300774e;
  if (local_1c == 0) {
    _DAT_5f9b3004 = 1;
    _DAT_5f9b300c = 1;
    local_24 = 16000000;
    local_20 = 0x300;
    local_1e = 4;
    iVar1 = FUN_0e0764a0(&DAT_0e099260,&local_24,0);
    if (iVar1 == 0xbad0000) {
LAB_0e077f72:
      _DAT_5f9b3540 = 0;
      _DAT_5f9b3544 = 0;
      _DAT_5f9b3548 = 0;
      _DAT_5f9b354c = 0;
      _DAT_5f9b3550 = 0;
      _DAT_5f9b3554 = 0;
      _DAT_5f9b3200 = _DAT_5f9b3200 & 0xff00ff00;
      _DAT_5f9b3308 = 0xff0000;
      uVar2 = FUN_0e0765b8(&DAT_0e099260,0x28);
      FUN_0e076440(&DAT_0e099260,1,uVar2,0x20000,1);
      thunk_FUN_0e089e70(0x1b3,4,0);
      _DAT_e000e2b4 = 0x80000;
      FUN_0e078e0c(0x1b3);
      DAT_2300774e = 1;
      return;
    }
    if (iVar1 == 0xbad000c) {
      FUN_0e076568(&DAT_0e099260);
      iVar1 = FUN_0e0764a0(&DAT_0e099260,&local_24,0);
      if (iVar1 == 0xbad0000) goto LAB_0e077f72;
    }
  }
  return;
}


