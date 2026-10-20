/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e077f1c. Types and names are inferred; NOT original source. */

void FUN_0e077f1c(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_24;
  undefined2 local_20;
  undefined1 local_1e;
  uint local_1c;
  
  local_24 = DAT_0e077ff4;
  iVar2 = DAT_0e077ff0;
  pbVar1 = DAT_0e077fec;
  local_1c = (uint)*DAT_0e077fec;
  if (local_1c == 0) {
    *(undefined4 *)(DAT_0e077ff0 + 4) = 1;
    *(undefined4 *)(iVar2 + 0xc) = 1;
    local_20 = 0x300;
    local_1e = 4;
    iVar3 = FUN_0e0764a4(DAT_0e077ff8,&local_24,0);
    iVar2 = DAT_0e077ffc;
    if (iVar3 == DAT_0e077ffc) {
LAB_0e077f7a:
      iVar2 = DAT_0e077ff0;
      *(undefined4 *)(DAT_0e077ff0 + 0x540) = 0;
      *(undefined4 *)(iVar2 + 0x544) = 0;
      *(undefined4 *)(iVar2 + 0x548) = 0;
      *(undefined4 *)(iVar2 + 0x54c) = 0;
      *(undefined4 *)(iVar2 + 0x550) = 0;
      *(undefined4 *)(iVar2 + 0x554) = 0;
      uVar4 = DAT_0e077ff8;
      *(uint *)(iVar2 + 0x200) = *(uint *)(iVar2 + 0x200) & 0xff00ff00;
      *(undefined4 *)(iVar2 + 0x308) = 0xff0000;
      uVar4 = FUN_0e0765bc(uVar4,0x28);
      FUN_0e076444(DAT_0e077ff8,1,uVar4,0x20000,1);
      thunk_FUN_0e089ffc(0x1b3,4,0);
      *(undefined4 *)(DAT_0e078004 + 0x1b4) = 0x80000;
      thunk_FUN_0e089fb8(0x1b3);
      *pbVar1 = 1;
      return;
    }
    if (iVar3 == DAT_0e078000) {
      FUN_0e07656c(DAT_0e077ff8);
      iVar3 = FUN_0e0764a4(DAT_0e077ff8,&local_24,0);
      if (iVar3 == iVar2) goto LAB_0e077f7a;
    }
  }
  return;
}


