/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069ba8. Types and names are inferred; NOT original source. */

int FUN_0e069ba8(int *param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  bool bVar5;
  
  iVar2 = *param_1;
  uVar4 = (uint)*(byte *)(param_1 + 1);
  *(undefined4 *)(iVar2 + 0x704) = *param_2;
  *(uint *)(iVar2 + 0x708) = (uint)*(ushort *)(param_2 + 1) << 1;
  *(undefined4 *)(iVar2 + 0x528) = param_2[2];
  *(undefined4 *)(iVar2 + 0x52c) = param_2[3];
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + 0x728) = *param_2;
  *(uint *)(iVar2 + 0x72c) = (uint)*(ushort *)(param_2 + 1) << 1;
  *(undefined4 *)(iVar2 + 0x548) = param_2[2];
  *(undefined4 *)(iVar2 + 0x54c) = param_2[3];
  uVar1 = param_3 & 1;
  *(uint *)(*param_1 + 0x514) = uVar1 + (param_3 >> 1);
  if ((int)(param_4 << 0x1f) < 0) {
    uVar3 = 0x10;
  }
  else {
    uVar3 = 0;
    if ((param_4 & 2) != 0) {
      if (uVar1 == 0) {
        uVar3 = 4;
      }
      else {
        uVar3 = 8;
      }
    }
  }
  *(undefined4 *)(*param_1 + 0x200) = uVar3;
  (&DAT_23006e0c)[uVar4 * 0x14] = 2;
  (&DAT_23006e10)[uVar4 * 5] = param_4;
  iVar2 = (&DAT_23006e04)[uVar4 * 5];
  *(undefined4 *)(*param_1 + 0x500) = 1;
  if (iVar2 != 0) {
    if ((param_4 & 4) == 0) {
      uVar4 = 0x82;
    }
    else {
      uVar4 = 0x92;
    }
    if ((int)(param_4 << 0x1c) < 0) {
      uVar4 = uVar4 | 0x20;
    }
    if ((int)(param_4 << 0x1b) < 0) {
      uVar4 = uVar4 & 0xffffff7f;
    }
    *(uint *)(*param_1 + 0x300) = uVar4;
  }
  bVar5 = (param_4 & 0x80) == 0;
  if (bVar5) {
    param_4 = 1;
  }
  iVar2 = uVar1 * 8 + 0x10;
  if (bVar5) {
    *(uint *)(*param_1 + iVar2) = param_4;
    iVar2 = 0;
  }
  else {
    iVar2 = *param_1 + iVar2;
  }
  return iVar2;
}


