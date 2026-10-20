/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e077d6c. Types and names are inferred; NOT original source. */

void FUN_0e077d6c(void)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_24;
  undefined2 local_20;
  undefined1 local_1e;
  uint local_1c;
  
  local_24 = DAT_0e077e08;
  iVar2 = DAT_0e077e00;
  pbVar1 = DAT_0e077dfc;
  local_1c = (uint)*DAT_0e077dfc;
  if (local_1c == 0) {
    *DAT_0e077e04 = 0;
    uVar3 = DAT_0e077e0c;
    *(undefined4 *)(iVar2 + 4) = 1;
    *(undefined4 *)(iVar2 + 0xc) = 1;
    local_20 = 0x300;
    local_1e = 4;
    iVar4 = FUN_0e0764a4(uVar3,&local_24,0);
    iVar2 = DAT_0e077e10;
    if (iVar4 == DAT_0e077e10) {
LAB_0e077dd0:
      FUN_0e077ca8();
      thunk_FUN_0e089ffc(0x1b2,4,0);
      *(undefined4 *)(DAT_0e077e18 + 0x1b4) = 0x40000;
      thunk_FUN_0e089fb8(0x1b2);
      *pbVar1 = 1;
      return;
    }
    if (iVar4 == DAT_0e077e14) {
      FUN_0e07656c(DAT_0e077e0c);
      iVar4 = FUN_0e0764a4(DAT_0e077e0c,&local_24,0);
      if (iVar4 == iVar2) goto LAB_0e077dd0;
    }
  }
  return;
}


