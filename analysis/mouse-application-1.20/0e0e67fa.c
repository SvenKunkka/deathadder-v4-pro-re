/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e67fa. Types and names are inferred; NOT original source. */

void FUN_0e0e67fa(undefined4 *param_1,int param_2,int param_3)

{
  short sVar1;
  undefined2 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  puVar2 = (undefined2 *)(param_2 + 7U & 0xfffffff8);
  uVar4 = (param_2 + param_3 + -4 & 0xfffffff8U) - (int)puVar2;
  uVar5 = uVar4 >> 3;
  uVar3 = (0x24 - LZCOUNT(uVar5)) * 4 + 7U >> 3;
  *param_1 = puVar2;
  *(uint *)(puVar2 + 4) = uVar5;
  *(undefined4 *)(puVar2 + 6) = 0;
  FUN_0e0e74d0(puVar2 + 8,0,(0x20 - LZCOUNT(uVar5)) * 4);
  puVar2[1] = (ushort)(uVar3 << 1) | 1;
  sVar1 = (short)uVar5 - (short)uVar3;
  *puVar2 = 0;
  puVar2[uVar3 * 4 + 1] = sVar1 * 2;
  puVar2[uVar3 * 4] = (short)uVar3;
  *(undefined2 *)((int)puVar2 + uVar4 + 2) = 0;
  *(short *)((int)puVar2 + uVar4) = sVar1;
  puVar2[uVar5 * 4 + 1] = puVar2[uVar5 * 4 + 1] | 1;
  FUN_0e0e67ac(puVar2,uVar3);
  return;
}


