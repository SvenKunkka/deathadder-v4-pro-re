/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e57e4. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0e0e57e4(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7,undefined1 param_8,undefined1 param_9)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  *(int *)(param_1 + 0x58) = param_1 + 0x58;
  *(int *)(param_1 + 0x5c) = param_1 + 0x58;
  *(undefined1 *)(param_1 + 0xc) = param_9;
  uVar4 = param_3 + 7U & 0xfffffff8;
  *(undefined1 *)(param_1 + 0xd) = 4;
  iVar5 = param_2 + uVar4;
  *(undefined1 *)(param_1 + 0xe) = param_8;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined1 *)(param_1 + 0xf) = 0;
  iVar1 = FUN_0e0e2fdc(param_1,iVar5);
  uVar2 = iVar1 + 7U & 0xfffffff8;
  *(uint *)(param_1 + 0x78) = uVar2;
  *(int *)(param_1 + 0x70) = param_2;
  *(uint *)(param_1 + 0x74) = uVar4;
  iVar5 = iVar5 - uVar2;
  FUN_0e0e3558(param_1,param_2,iVar5,param_4,param_5,param_6,param_7);
  *(undefined4 *)(param_1 + 0x54) = 0;
  iVar1 = _DAT_2f0118dc;
  *(undefined1 *)(param_1 + 0x6c) = 0;
  uVar3 = 0;
  if (iVar1 != 0) {
    uVar3 = *(undefined4 *)(iVar1 + 0x7c);
  }
  *(undefined4 *)(param_1 + 0x7c) = uVar3;
  return iVar5;
}


