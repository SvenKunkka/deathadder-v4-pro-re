/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e078114. Types and names are inferred; NOT original source. */

void FUN_0e078114(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_24;
  undefined2 local_20;
  undefined1 local_1e;
  uint local_1c;
  
  pbVar1 = DAT_0e0781cc;
  local_1c = (uint)*DAT_0e0781cc;
  if (local_1c == 0) {
    local_24 = DAT_0e0781d0;
    local_20 = 0x300;
    local_1e = 3;
    iVar3 = FUN_0e0764a4(DAT_0e0781d4,&local_24,0);
    iVar2 = DAT_0e0781d8;
    if (iVar3 == DAT_0e0781d8) {
LAB_0e078160:
      iVar2 = DAT_0e0781e0;
      *(undefined4 *)(DAT_0e0781e0 + 0x540) = 0;
      *(undefined4 *)(iVar2 + 0x544) = 0;
      *(undefined4 *)(iVar2 + 0x548) = 0;
      *(undefined4 *)(iVar2 + 0x54c) = 0;
      *(undefined4 *)(iVar2 + 0x550) = 0;
      *(undefined4 *)(iVar2 + 0x554) = 0;
      uVar4 = DAT_0e0781d4;
      *(uint *)(iVar2 + 0x200) = *(uint *)(iVar2 + 0x200) & 0xff00ff00;
      *(undefined4 *)(iVar2 + 0x308) = 0xff0000;
      uVar4 = FUN_0e0765bc(uVar4,0x14);
      FUN_0e076444(DAT_0e0781d4,0,uVar4,0x10000,1);
      thunk_FUN_0e089ffc(0x1a2,3,0);
      *(undefined4 *)(DAT_0e0781e4 + 0x1b4) = 4;
      thunk_FUN_0e089fb8(0x1a2);
      *pbVar1 = 1;
      return;
    }
    if (iVar3 == DAT_0e0781dc) {
      FUN_0e07656c(DAT_0e0781d4);
      iVar3 = FUN_0e0764a4(DAT_0e0781d4,&local_24,0);
      if (iVar3 == iVar2) goto LAB_0e078160;
    }
  }
  return;
}


