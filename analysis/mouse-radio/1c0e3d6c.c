/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e3d6c. Types and names are inferred; NOT original source. */

void FUN_1c0e3d6c(void)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_24;
  undefined2 local_20;
  undefined1 local_1e;
  uint local_1c;
  
  local_24 = DAT_1c0e3e08;
  iVar2 = DAT_1c0e3e00;
  pbVar1 = DAT_1c0e3dfc;
  local_1c = (uint)*DAT_1c0e3dfc;
  if (local_1c == 0) {
    *DAT_1c0e3e04 = 0;
    uVar3 = DAT_1c0e3e0c;
    *(undefined4 *)(iVar2 + 4) = 1;
    *(undefined4 *)(iVar2 + 0xc) = 1;
    local_20 = 0x300;
    local_1e = 4;
    iVar4 = FUN_1c0e24a4(uVar3,&local_24,0);
    iVar2 = DAT_1c0e3e10;
    if (iVar4 == DAT_1c0e3e10) {
LAB_1c0e3dd0:
      FUN_1c0e3ca8();
      thunk_EXT_FUN_0e089ffc(0x1b2,4,0);
      *(undefined4 *)(DAT_1c0e3e18 + 0x1b4) = 0x40000;
      thunk_EXT_FUN_0e089fb8(0x1b2);
      *pbVar1 = 1;
      return;
    }
    if (iVar4 == DAT_1c0e3e14) {
      FUN_1c0e256c(DAT_1c0e3e0c);
      iVar4 = FUN_1c0e24a4(DAT_1c0e3e0c,&local_24,0);
      if (iVar4 == iVar2) goto LAB_1c0e3dd0;
    }
  }
  return;
}


