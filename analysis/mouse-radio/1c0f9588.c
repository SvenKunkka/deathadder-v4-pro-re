/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f9588. Types and names are inferred; NOT original source. */

int FUN_1c0f9588(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  
  uVar3 = param_2 & 0xf;
  if ((int)(param_2 << 0x18) < 0) {
    uVar3 = uVar3 + 0x10;
  }
  iVar5 = *(int *)(*(int *)(param_1 + 0x10) + uVar3 * 4);
  if (iVar5 != 0) {
    if ((int)((uint)*(byte *)(iVar5 + 0x14) << 0x1f) < 0) {
      pcVar4 = *(code **)(*(int *)(param_1 + 8) + 0x1c);
      iVar1 = (*pcVar4)(param_1,iVar5,*(int *)(param_1 + 0x10),pcVar4,param_4);
      if (iVar1 == 0) {
        bVar2 = 0;
      }
      else {
        bVar2 = *(byte *)(iVar5 + 0x14) & 1;
      }
      *(byte *)(iVar5 + 0x14) = *(byte *)(iVar5 + 0x14) & 0xfe | bVar2;
      return iVar1;
    }
    return -0x78;
  }
  return -0x13;
}


