/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e085b70. Types and names are inferred; NOT original source. */

void FUN_0e085b70(int param_1,uint param_2,uint param_3)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = param_1 + param_2 * 8;
  uVar1 = *(ushort *)(iVar4 + 6);
  uVar3 = (uint)uVar1;
  if (param_2 != uVar3) {
    uVar2 = *(ushort *)(iVar4 + 4);
    *(uint *)(param_1 + (param_3 + 4) * 4) = uVar3;
    *(ushort *)(param_1 + (uint)uVar2 * 8 + 6) = uVar1;
    *(ushort *)(param_1 + uVar3 * 8 + 4) = uVar2;
    return;
  }
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & ~(1 << (param_3 & 0xff));
  *(undefined4 *)(param_1 + (param_3 + 4) * 4) = 0;
  return;
}


