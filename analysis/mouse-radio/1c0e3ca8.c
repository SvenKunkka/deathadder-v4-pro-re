/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e3ca8. Types and names are inferred; NOT original source. */

void FUN_1c0e3ca8(void)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = DAT_1c0e3d5c;
  if (*DAT_1c0e3d54 == '\x04') {
    if (*DAT_1c0e3d68 != '\0') {
      bVar1 = *(byte *)(DAT_1c0e3d64 + 1);
      goto joined_r0x1c0e3d46;
    }
  }
  else {
    if (*DAT_1c0e3d54 != '\x01') {
      iVar4 = 0;
      goto LAB_1c0e3cba;
    }
    bVar1 = *(byte *)(DAT_1c0e3d64 + 3);
joined_r0x1c0e3d46:
    if (bVar1 < 8) {
      iVar4 = (short)(ushort)bVar1 * 0x7d + -0x5f;
      goto LAB_1c0e3cba;
    }
  }
  iVar4 = 700;
LAB_1c0e3cba:
  if (*DAT_1c0e3d58 != iVar4) {
    *DAT_1c0e3d58 = iVar4;
    *(undefined4 *)(iVar2 + 0x540) = 0;
    *(undefined4 *)(iVar2 + 0x544) = 0;
    *(undefined4 *)(iVar2 + 0x548) = 0;
    *(undefined4 *)(iVar2 + 0x54c) = 0;
    *(undefined4 *)(iVar2 + 0x550) = 0;
    *(undefined4 *)(iVar2 + 0x554) = 0;
    *(uint *)(iVar2 + 0x200) = *(uint *)(iVar2 + 0x200) & 0xff00ff00;
    uVar3 = DAT_1c0e3d60;
    *(undefined4 *)(iVar2 + 0x308) = 0xff0000;
    uVar3 = FUN_1c0e25bc(uVar3,iVar4);
    FUN_1c0e2444(DAT_1c0e3d60,0,uVar3,0x20000,0);
    uVar3 = FUN_1c0e25bc(DAT_1c0e3d60,iVar4 + 0x1e);
    FUN_1c0e2444(DAT_1c0e3d60,1,uVar3,0x20000,1);
  }
  return;
}


