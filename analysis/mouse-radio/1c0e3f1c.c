/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e3f1c. Types and names are inferred; NOT original source. */

void FUN_1c0e3f1c(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_24;
  undefined2 local_20;
  undefined1 local_1e;
  uint local_1c;
  
  local_24 = DAT_1c0e3ff4;
  iVar2 = DAT_1c0e3ff0;
  pbVar1 = DAT_1c0e3fec;
  local_1c = (uint)*DAT_1c0e3fec;
  if (local_1c == 0) {
    *(undefined4 *)(DAT_1c0e3ff0 + 4) = 1;
    *(undefined4 *)(iVar2 + 0xc) = 1;
    local_20 = 0x300;
    local_1e = 4;
    iVar3 = FUN_1c0e24a4(DAT_1c0e3ff8,&local_24,0);
    iVar2 = DAT_1c0e3ffc;
    if (iVar3 == DAT_1c0e3ffc) {
LAB_1c0e3f7a:
      iVar2 = DAT_1c0e3ff0;
      *(undefined4 *)(DAT_1c0e3ff0 + 0x540) = 0;
      *(undefined4 *)(iVar2 + 0x544) = 0;
      *(undefined4 *)(iVar2 + 0x548) = 0;
      *(undefined4 *)(iVar2 + 0x54c) = 0;
      *(undefined4 *)(iVar2 + 0x550) = 0;
      *(undefined4 *)(iVar2 + 0x554) = 0;
      uVar4 = DAT_1c0e3ff8;
      *(uint *)(iVar2 + 0x200) = *(uint *)(iVar2 + 0x200) & 0xff00ff00;
      *(undefined4 *)(iVar2 + 0x308) = 0xff0000;
      uVar4 = FUN_1c0e25bc(uVar4,0x28);
      FUN_1c0e2444(DAT_1c0e3ff8,1,uVar4,0x20000,1);
      thunk_EXT_FUN_0e089ffc(0x1b3,4,0);
      *(undefined4 *)(DAT_1c0e4004 + 0x1b4) = 0x80000;
      thunk_EXT_FUN_0e089fb8(0x1b3);
      *pbVar1 = 1;
      return;
    }
    if (iVar3 == DAT_1c0e4000) {
      FUN_1c0e256c(DAT_1c0e3ff8);
      iVar3 = FUN_1c0e24a4(DAT_1c0e3ff8,&local_24,0);
      if (iVar3 == iVar2) goto LAB_1c0e3f7a;
    }
  }
  return;
}


