/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e971c. Types and names are inferred; NOT original source. */

void FUN_1c0e971c(void)

{
  byte *pbVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 in_r3;
  uint uVar5;
  
  puVar2 = DAT_1c0e9844;
  pbVar1 = DAT_1c0e982c;
  uVar5 = (uint)*DAT_1c0e982c;
  if ((uVar5 != 0) && (*DAT_1c0e9830 == 0)) {
    if ((int)(uVar5 << 0x1e) < 0) {
      *DAT_1c0e9844 = 0x29;
      uVar3 = FUN_1c0ebafc(puVar2,0x27,0,uVar5,in_r3);
      *(undefined2 *)((int)puVar2 + 0x27) = uVar3;
      iVar4 = FUN_1c0e9f88(0,0xa001,puVar2,0x29);
      uVar5 = (uint)*pbVar1;
      if (iVar4 != 0) {
        uVar5 = uVar5 & 0xfd;
        *pbVar1 = (byte)uVar5;
      }
    }
    puVar2 = DAT_1c0e9840;
    if ((int)(uVar5 << 0x1f) < 0) {
      *DAT_1c0e9840 = 0x54;
      uVar3 = FUN_1c0ebafc(puVar2,0x52,0,uVar5,in_r3);
      puVar2[0x29] = uVar3;
      iVar4 = FUN_1c0e9f88(1,0xa002,puVar2,0x54);
      uVar5 = (uint)*pbVar1;
      if (iVar4 != 0) {
        uVar5 = uVar5 & 0xfe;
        *pbVar1 = (byte)uVar5;
      }
    }
    puVar2 = DAT_1c0e983c;
    if ((int)(uVar5 << 0x1d) < 0) {
      *DAT_1c0e983c = 0x4e4;
      uVar3 = FUN_1c0ebafc(puVar2,0x4e2,0,uVar5,in_r3);
      puVar2[0x271] = uVar3;
      iVar4 = FUN_1c0e9f88(2,0xa003,puVar2,0x4e4);
      if (iVar4 != 0) {
        *pbVar1 = *pbVar1 & 0xfb;
      }
    }
  }
  pbVar1 = DAT_1c0e9834;
  uVar5 = (uint)*DAT_1c0e9834;
  if ((int)(uVar5 << 0x1f) < 0) {
    uVar5 = uVar5 & 0xfe;
    *DAT_1c0e9834 = (byte)uVar5;
  }
  if ((int)(uVar5 << 0x1e) < 0) {
    uVar5 = uVar5 & 0xfd;
    *pbVar1 = (byte)uVar5;
  }
  if ((int)(uVar5 << 0x1d) < 0) {
    uVar5 = uVar5 & 0xfb;
    *pbVar1 = (byte)uVar5;
  }
  iVar4 = DAT_1c0e9838;
  if ((int)(uVar5 << 0x1c) < 0) {
    uVar3 = FUN_1c0ebafc(DAT_1c0e9838,0x5dc,0,uVar5 << 0x1c,in_r3);
    *(undefined2 *)(iVar4 + 0x5dc) = uVar3;
    iVar4 = FUN_1c0e9f88(4,0xa006,iVar4,0x5de);
    if (iVar4 != 0) {
      *pbVar1 = *pbVar1 & 0xf7;
      return;
    }
  }
  return;
}


