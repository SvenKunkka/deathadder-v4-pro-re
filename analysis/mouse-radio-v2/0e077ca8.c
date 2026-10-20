/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e077ca8. Types and names are inferred; NOT original source. */

void FUN_0e077ca8(void)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = DAT_0e077d5c;
  if (*DAT_0e077d54 == '\x04') {
    if (*DAT_0e077d68 != '\0') {
      bVar1 = *(byte *)(DAT_0e077d64 + 1);
      goto joined_r0x0e077d46;
    }
  }
  else {
    if (*DAT_0e077d54 != '\x01') {
      iVar4 = 0;
      goto LAB_0e077cba;
    }
    bVar1 = *(byte *)(DAT_0e077d64 + 3);
joined_r0x0e077d46:
    if (bVar1 < 8) {
      iVar4 = (short)(ushort)bVar1 * 0x7d + -0x5f;
      goto LAB_0e077cba;
    }
  }
  iVar4 = 700;
LAB_0e077cba:
  if (*DAT_0e077d58 != iVar4) {
    *DAT_0e077d58 = iVar4;
    *(undefined4 *)(iVar2 + 0x540) = 0;
    *(undefined4 *)(iVar2 + 0x544) = 0;
    *(undefined4 *)(iVar2 + 0x548) = 0;
    *(undefined4 *)(iVar2 + 0x54c) = 0;
    *(undefined4 *)(iVar2 + 0x550) = 0;
    *(undefined4 *)(iVar2 + 0x554) = 0;
    *(uint *)(iVar2 + 0x200) = *(uint *)(iVar2 + 0x200) & 0xff00ff00;
    uVar3 = DAT_0e077d60;
    *(undefined4 *)(iVar2 + 0x308) = 0xff0000;
    uVar3 = FUN_0e0765bc(uVar3,iVar4);
    FUN_0e076444(DAT_0e077d60,0,uVar3,0x20000,0);
    uVar3 = FUN_0e0765bc(DAT_0e077d60,iVar4 + 0x1e);
    FUN_0e076444(DAT_0e077d60,1,uVar3,0x20000,1);
  }
  return;
}


