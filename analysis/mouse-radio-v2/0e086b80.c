/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e086b80. Types and names are inferred; NOT original source. */

int FUN_0e086b80(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 local_30;
  undefined1 local_2f;
  undefined2 local_2e;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  undefined1 auStack_20 [16];
  
  uVar4 = *(uint *)(param_1 + 8);
  local_2c = 0xffffffff;
  local_24 = 0xffffffff;
  local_2e = 0;
  local_28 = *(int *)(param_1 + 0x40) + uVar4;
  local_2f = *(undefined1 *)(param_1 + 0x20);
  uVar5 = *(uint *)(param_1 + 0xc);
  FUN_0e097512(auStack_20,*(undefined1 *)(*(int *)(param_1 + 0x3c) + 5),0x10);
  while (uVar4 != 0) {
    uVar2 = *(uint *)(param_1 + 0x10);
    uVar3 = *(uint *)(param_1 + 0x14);
    if (uVar5 <= uVar3 && (uint)(uVar2 <= uVar4) <= uVar5 - uVar3) break;
    iVar1 = FUN_0e0869a4(param_1,auStack_20,uVar2,(uVar5 - uVar3) - (uint)(uVar2 > uVar4));
    if (iVar1 != 0) {
      return iVar1;
    }
    uVar5 = *(uint *)(param_1 + 0xc);
    uVar4 = *(uint *)(param_1 + 8);
  }
  uVar2 = *(uint *)(param_1 + 0x18);
  uVar4 = *(int *)(param_1 + 0x40) * 2;
  if (uVar2 <= uVar4 && uVar4 - uVar2 != 0) {
    uVar5 = uVar5 - 1;
  }
  *(uint *)(param_1 + 8) = uVar2 + *(int *)(param_1 + 0x40) * -2;
  *(uint *)(param_1 + 0xc) = uVar5;
  local_30 = FUN_0e085c00(0xff,&local_2f,0xf);
  FUN_0e0869a4(param_1,&local_30);
  iVar1 = *(int *)(param_1 + 0xc) + 1;
  *(int *)(param_1 + 0xc) = iVar1;
  if (iVar1 == *(int *)(param_1 + 0x1c)) {
    iVar1 = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  iVar1 = FUN_0e086a98(param_1,param_1 + 0x20,*(undefined4 *)(param_1 + 8),iVar1,param_1 + 0x20);
  if (iVar1 == -2) {
    *(undefined1 *)(param_1 + 0x20) = 0;
  }
  else if (iVar1 != 0) {
    return iVar1;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0xc);
  return 0;
}


