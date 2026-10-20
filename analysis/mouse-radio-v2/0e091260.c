/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e091260. Types and names are inferred; NOT original source. */

int FUN_0e091260(int *param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  bool bVar7;
  
  iVar4 = *param_1;
  bVar1 = *(byte *)(param_1 + 1);
  *(undefined4 *)(iVar4 + 0x704) = *param_2;
  *(uint *)(iVar4 + 0x708) = (uint)*(ushort *)(param_2 + 1) << 1;
  *(undefined4 *)(iVar4 + 0x528) = param_2[2];
  *(undefined4 *)(iVar4 + 0x52c) = param_2[3];
  iVar4 = *param_1;
  *(undefined4 *)(iVar4 + 0x728) = *param_2;
  *(uint *)(iVar4 + 0x72c) = (uint)*(ushort *)(param_2 + 1) << 1;
  *(undefined4 *)(iVar4 + 0x548) = param_2[2];
  *(undefined4 *)(iVar4 + 0x54c) = param_2[3];
  uVar2 = param_3 & 1;
  *(uint *)(*param_1 + 0x514) = uVar2 + (param_3 >> 1);
  iVar4 = DAT_0e09132c;
  if ((int)(param_4 << 0x1f) < 0) {
    uVar6 = 0x10;
  }
  else {
    uVar6 = 0;
    if ((param_4 & 2) != 0) {
      if (uVar2 == 0) {
        uVar6 = 4;
      }
      else {
        uVar6 = 8;
      }
    }
  }
  *(undefined4 *)(*param_1 + 0x200) = uVar6;
  iVar5 = iVar4 + (uint)bVar1 * 0x14;
  *(undefined1 *)(iVar5 + 8) = 2;
  *(uint *)(iVar5 + 0xc) = param_4;
  iVar4 = *(int *)(iVar4 + (uint)bVar1 * 0x14);
  *(undefined4 *)(*param_1 + 0x500) = 1;
  if (iVar4 != 0) {
    if ((param_4 & 4) == 0) {
      uVar3 = 0x82;
    }
    else {
      uVar3 = 0x92;
    }
    if ((int)(param_4 << 0x1c) < 0) {
      uVar3 = uVar3 | 0x20;
    }
    if ((int)(param_4 << 0x1b) < 0) {
      uVar3 = uVar3 & 0xffffff7f;
    }
    *(uint *)(*param_1 + 0x300) = uVar3;
  }
  bVar7 = (param_4 & 0x80) == 0;
  if (bVar7) {
    param_4 = 1;
  }
  iVar4 = uVar2 * 8 + 0x10;
  if (bVar7) {
    *(uint *)(*param_1 + iVar4) = param_4;
    iVar4 = 0;
  }
  else {
    iVar4 = *param_1 + iVar4;
  }
  return iVar4;
}


