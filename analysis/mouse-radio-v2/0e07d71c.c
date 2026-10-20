/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07d71c. Types and names are inferred; NOT original source. */

void FUN_0e07d71c(void)

{
  byte *pbVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 in_r3;
  uint uVar5;
  
  puVar2 = DAT_0e07d844;
  pbVar1 = DAT_0e07d82c;
  uVar5 = (uint)*DAT_0e07d82c;
  if ((uVar5 != 0) && (*DAT_0e07d830 == 0)) {
    if ((int)(uVar5 << 0x1e) < 0) {
      *DAT_0e07d844 = 0x29;
      uVar3 = FUN_0e07fafc(puVar2,0x27,0,uVar5,in_r3);
      *(undefined2 *)((int)puVar2 + 0x27) = uVar3;
      iVar4 = FUN_0e07df88(0,0xa001,puVar2,0x29);
      uVar5 = (uint)*pbVar1;
      if (iVar4 != 0) {
        uVar5 = uVar5 & 0xfd;
        *pbVar1 = (byte)uVar5;
      }
    }
    puVar2 = DAT_0e07d840;
    if ((int)(uVar5 << 0x1f) < 0) {
      *DAT_0e07d840 = 0x54;
      uVar3 = FUN_0e07fafc(puVar2,0x52,0,uVar5,in_r3);
      puVar2[0x29] = uVar3;
      iVar4 = FUN_0e07df88(1,0xa002,puVar2,0x54);
      uVar5 = (uint)*pbVar1;
      if (iVar4 != 0) {
        uVar5 = uVar5 & 0xfe;
        *pbVar1 = (byte)uVar5;
      }
    }
    puVar2 = DAT_0e07d83c;
    if ((int)(uVar5 << 0x1d) < 0) {
      *DAT_0e07d83c = 0x4e4;
      uVar3 = FUN_0e07fafc(puVar2,0x4e2,0,uVar5,in_r3);
      puVar2[0x271] = uVar3;
      iVar4 = FUN_0e07df88(2,0xa003,puVar2,0x4e4);
      if (iVar4 != 0) {
        *pbVar1 = *pbVar1 & 0xfb;
      }
    }
  }
  pbVar1 = DAT_0e07d834;
  uVar5 = (uint)*DAT_0e07d834;
  if ((int)(uVar5 << 0x1f) < 0) {
    uVar5 = uVar5 & 0xfe;
    *DAT_0e07d834 = (byte)uVar5;
  }
  if ((int)(uVar5 << 0x1e) < 0) {
    uVar5 = uVar5 & 0xfd;
    *pbVar1 = (byte)uVar5;
  }
  if ((int)(uVar5 << 0x1d) < 0) {
    uVar5 = uVar5 & 0xfb;
    *pbVar1 = (byte)uVar5;
  }
  iVar4 = DAT_0e07d838;
  if ((int)(uVar5 << 0x1c) < 0) {
    uVar3 = FUN_0e07fafc(DAT_0e07d838,0x5dc,0,uVar5 << 0x1c,in_r3);
    *(undefined2 *)(iVar4 + 0x5dc) = uVar3;
    iVar4 = FUN_0e07df88(4,0xa006,iVar4,0x5de);
    if (iVar4 != 0) {
      *pbVar1 = *pbVar1 & 0xf7;
      return;
    }
  }
  return;
}


