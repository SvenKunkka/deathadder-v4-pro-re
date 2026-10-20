/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06631c. Types and names are inferred; NOT original source. */

void FUN_0e06631c(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x18);
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((iVar2 != 0) && (pcVar3 = *(code **)(iVar2 + 0x24), pcVar3 != (code *)0x0)) {
    (*pcVar3)();
  }
  *(uint *)(iVar5 + 0x58) = *(uint *)(iVar5 + 0x58) & 0xffffffdf;
  FUN_0e06c750(1);
  *(uint *)(iVar5 + 0x58) = *(uint *)(iVar5 + 0x58) & 0xffffffef;
  FUN_0e06c750(1);
  *(uint *)(iVar5 + 0x58) = *(uint *)(iVar5 + 0x58) | 4;
  FUN_0e06c750(1);
  *(uint *)(iVar5 + 0x58) = *(uint *)(iVar5 + 0x58) & 0xfffffff7;
  if (param_2 != 0) {
    if ((int)((uint)*(byte *)(iVar8 + 0x362) << 0x1d) < 0) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0x32;
    }
    FUN_0e06c750(uVar1);
  }
  *(uint *)(iVar5 + 0x58) = *(uint *)(iVar5 + 0x58) | 0x10;
  FUN_0e06c750(1);
  *(uint *)(iVar5 + 0x58) = *(uint *)(iVar5 + 0x58) & 0xfffffffe;
  iVar7 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  uVar4 = *(uint *)(iVar7 + 0x2a8);
  uVar6 = uVar4 & 0xffffc000;
  *(undefined4 *)(iVar2 + 0x54) = *(undefined4 *)(iVar7 + 0xd0);
  if ((uVar4 & 0x18000000) == 0) {
    uVar6 = uVar6 | 0x20000;
  }
  *(undefined4 *)(iVar2 + 0x30) = *(undefined4 *)(iVar7 + 0xcc);
  *(uint *)(iVar2 + 0xe00) = uVar6;
  *(uint *)(iVar2 + 8) = *(uint *)(iVar7 + 0xb8) | 1;
  *(undefined4 *)(iVar2 + 0x14) = 0xffffffff;
  *(undefined4 *)(iVar2 + 0x18) = 0x10000;
  *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar7 + 0xbc);
  uVar1 = *(undefined4 *)(iVar7 + 0x114);
  *(undefined4 *)(iVar2 + 0x800) = uVar1;
  if (param_3 != 0) {
    *(undefined4 *)(iVar2 + 0x800) = uVar1;
  }
  if (param_2 == 0) {
    uVar6 = uVar6 | 0x208;
  }
  *(uint *)(iVar2 + 0xe00) = uVar6;
  FUN_0e06c750(1);
  *(uint *)(iVar2 + 0xe00) = uVar6 | 0x2000;
  FUN_0e0652d4(param_1,iVar2 + 0x14,0x10000);
  if ((int)((uint)*(byte *)(iVar7 + 0x362) << 0x1c) < 0) {
    *(uint *)(iVar2 + 0xe00) = uVar6;
    FUN_0e06c750(1);
  }
  if (param_3 == 0) {
    *(undefined4 *)(iVar2 + 0x14) = 0xffffffff;
  }
  *(uint *)(iVar5 + 0x58) = *(uint *)(iVar5 + 0x58) & 0xfffffffb;
  FUN_0e06c750(1);
  if (param_2 == 0) {
    *(uint *)(iVar5 + 0xe00) = *(uint *)(iVar5 + 0xe00) & 0xfffffff7;
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar8 + 0xbc);
    *(undefined4 *)(iVar5 + 0x800) = *(undefined4 *)(iVar8 + 0x114);
    *(undefined4 *)(iVar5 + 0x804) = *(undefined4 *)(iVar8 + 0x118);
    *(uint *)(iVar5 + 0x58) = *(uint *)(iVar5 + 0x58) & 0xfffffffd;
    FUN_0e06c750(5);
    *(uint *)(iVar5 + 0x804) = *(uint *)(iVar5 + 0x804) | 0x800;
  }
  else {
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar8 + 0xbc);
    *(undefined4 *)(iVar5 + 0x800) = *(undefined4 *)(iVar8 + 0x114);
    *(undefined4 *)(iVar5 + 0x804) = *(undefined4 *)(iVar8 + 0x118);
    *(uint *)(iVar5 + 0x58) = *(uint *)(iVar5 + 0x58) & 0xfffffffd;
    FUN_0e06c750(1);
    *(uint *)(iVar5 + 0x804) = *(uint *)(iVar8 + 0x118) | 1;
  }
  FUN_0e06e3d0(1000,0);
  *(undefined4 *)(iVar5 + 0x14) = 0xffffffff;
  return;
}


