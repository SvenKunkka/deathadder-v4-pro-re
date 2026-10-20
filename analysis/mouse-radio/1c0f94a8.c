/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f94a8. Types and names are inferred; NOT original source. */

int FUN_1c0f94a8(int param_1,uint param_2,undefined4 param_3,ushort param_4,undefined1 param_5)

{
  int iVar1;
  undefined2 extraout_r2;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = param_2 & 0xf;
  if ((char)param_2 < '\0') {
    uVar2 = uVar2 + 0x10;
  }
  iVar3 = *(int *)(*(int *)(param_1 + 0x10) + uVar2 * 4);
  iVar4 = *(int *)(param_1 + 8);
  if (iVar3 != 0) {
    if ((int)((uint)*(byte *)(iVar3 + 0x14) << 0x1f) < 0) {
      return -0x78;
    }
    if ((char)param_2 < '\0') {
      iVar1 = (uint)*(byte *)(iVar3 + 0x12) << 0x1a;
    }
    else {
      iVar1 = (uint)*(byte *)(iVar3 + 0x12) << 0x19;
    }
    if (((iVar1 < 0) && ((param_4 & 0x7ff) <= (*(ushort *)(iVar3 + 0x10) & 0x7ff))) &&
       (iVar1 = FUN_1c0f9208(*(undefined4 *)(iVar3 + 0x10),param_3), iVar1 != 0)) {
      *(undefined2 *)(iVar3 + 0x1a) = extraout_r2;
      *(char *)(iVar3 + 0x19) = (char)param_3;
      *(undefined1 *)(iVar3 + 0x1c) = param_5;
      *(byte *)(iVar3 + 0x14) = *(byte *)(iVar3 + 0x14) & 0xf1;
      iVar4 = (**(code **)(iVar4 + 0x18))(param_1,iVar3);
      *(byte *)(iVar3 + 0x14) = *(byte *)(iVar3 + 0x14) & 0xfe | iVar4 == 0;
      return iVar4;
    }
  }
  return -0x13;
}


