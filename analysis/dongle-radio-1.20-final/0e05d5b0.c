/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d5b0. Types and names are inferred; NOT original source. */

void FUN_0e05d5b0(undefined4 *param_1,int param_2,int param_3)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  undefined2 *puVar4;
  uint uVar5;
  
  puVar4 = (undefined2 *)(param_2 + 7U & 0xfffffff8);
  uVar2 = (param_2 + param_3 + -4 & 0xfffffff8U) - (int)puVar4;
  uVar5 = uVar2 >> 3;
  uVar3 = (0x24 - LZCOUNT(uVar5)) * 4 + 7U >> 3;
  *param_1 = puVar4;
  *(undefined4 *)(puVar4 + 6) = 0;
  *(uint *)(puVar4 + 4) = uVar5;
  FUN_0e06f3aa(puVar4 + 8,0,(0x20 - LZCOUNT(uVar5)) * 4);
  puVar4[1] = (ushort)(uVar3 << 1) | 1;
  sVar1 = (short)uVar5 - (short)uVar3;
  *puVar4 = 0;
  puVar4[uVar3 * 4 + 1] = sVar1 * 2;
  puVar4[uVar3 * 4] = (short)uVar3;
  *(short *)((int)puVar4 + uVar2) = sVar1;
  *(undefined2 *)((int)puVar4 + uVar2 + 2) = 1;
  FUN_0e05d2dc(puVar4,uVar3);
  return;
}


