/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f1ca0. Types and names are inferred; NOT original source. */

void FUN_1c0f1ca0(int param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = param_1 + param_2 * 8;
  uVar3 = 0x1f - LZCOUNT((uint)(*(ushort *)(iVar4 + 2) >> 1));
  iVar5 = param_1 + uVar3 * 4;
  iVar2 = *(int *)(iVar5 + 0x10);
  iVar6 = param_2 * 8 + 4;
  if (iVar2 == 0) {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 1 << (uVar3 & 0xff);
    *(uint *)(iVar5 + 0x10) = param_2;
    *(uint *)(param_1 + iVar6) = param_2 & 0xffff | param_2 << 0x10;
    return;
  }
  iVar5 = iVar2 * 8 + 4;
  uVar1 = *(ushort *)(param_1 + iVar5);
  *(ushort *)(param_1 + iVar6) = uVar1;
  *(short *)(iVar4 + 6) = (short)iVar2;
  *(short *)(param_1 + (uint)uVar1 * 8 + 6) = (short)param_2;
  *(short *)(param_1 + iVar5) = (short)param_2;
  return;
}


