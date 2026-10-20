/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e4034. Types and names are inferred; NOT original source. */

void FUN_1c0e4034(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  undefined4 local_24;
  undefined2 local_20;
  undefined1 local_1e;
  uint local_1c;
  
  local_24 = DAT_1c0e40c4;
  iVar2 = DAT_1c0e40c0;
  pbVar1 = DAT_1c0e40bc;
  local_1c = (uint)*DAT_1c0e40bc;
  if (local_1c == 0) {
    *(undefined4 *)(DAT_1c0e40c0 + 4) = 1;
    *(undefined4 *)(iVar2 + 0xc) = 1;
    local_20 = 0x300;
    local_1e = 3;
    iVar3 = FUN_1c0e24a4(DAT_1c0e40c8,&local_24,0);
    iVar2 = DAT_1c0e40cc;
    if (iVar3 == DAT_1c0e40cc) {
LAB_1c0e4092:
      FUN_1c0e4218();
      thunk_EXT_FUN_0e089ffc(0x1c2,3,0);
      *(undefined4 *)(DAT_1c0e40d4 + 0x1b8) = 4;
      thunk_EXT_FUN_0e089fb8(0x1c2);
      *pbVar1 = 1;
      return;
    }
    if (iVar3 == DAT_1c0e40d0) {
      FUN_1c0e256c(DAT_1c0e40c8);
      iVar3 = FUN_1c0e24a4(DAT_1c0e40c8,&local_24,0);
      if (iVar3 == iVar2) goto LAB_1c0e4092;
    }
  }
  return;
}


