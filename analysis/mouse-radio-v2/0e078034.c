/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e078034. Types and names are inferred; NOT original source. */

void FUN_0e078034(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  undefined4 local_24;
  undefined2 local_20;
  undefined1 local_1e;
  uint local_1c;
  
  local_24 = DAT_0e0780c4;
  iVar2 = DAT_0e0780c0;
  pbVar1 = DAT_0e0780bc;
  local_1c = (uint)*DAT_0e0780bc;
  if (local_1c == 0) {
    *(undefined4 *)(DAT_0e0780c0 + 4) = 1;
    *(undefined4 *)(iVar2 + 0xc) = 1;
    local_20 = 0x300;
    local_1e = 3;
    iVar3 = FUN_0e0764a4(DAT_0e0780c8,&local_24,0);
    iVar2 = DAT_0e0780cc;
    if (iVar3 == DAT_0e0780cc) {
LAB_0e078092:
      FUN_0e078218();
      thunk_FUN_0e089ffc(0x1c2,3,0);
      *(undefined4 *)(DAT_0e0780d4 + 0x1b8) = 4;
      thunk_FUN_0e089fb8(0x1c2);
      *pbVar1 = 1;
      return;
    }
    if (iVar3 == DAT_0e0780d0) {
      FUN_0e07656c(DAT_0e0780c8);
      iVar3 = FUN_0e0764a4(DAT_0e0780c8,&local_24,0);
      if (iVar3 == iVar2) goto LAB_0e078092;
    }
  }
  return;
}


