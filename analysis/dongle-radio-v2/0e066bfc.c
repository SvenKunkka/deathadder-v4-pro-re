/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e066bfc. Types and names are inferred; NOT original source. */

void FUN_0e066bfc(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  
  iVar6 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  iVar5 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
  FUN_0e06631c();
  iVar8 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
  puVar2 = *(undefined4 **)(*(int *)(param_1 + 4) + 0x10);
  *puVar2 = *(undefined4 *)(iVar8 + 0xb4);
  puVar2[2] = *(undefined4 *)(iVar8 + 0xb8);
  puVar2[3] = *(undefined4 *)(iVar8 + 0xbc);
  puVar2[6] = *(undefined4 *)(iVar8 + 0xc0);
  puVar2[9] = *(undefined4 *)(iVar8 + 0xc4);
  puVar2[10] = *(undefined4 *)(iVar8 + 200);
  puVar2[0x17] = *(undefined4 *)(iVar8 + 0xd4);
  if (1 < *(byte *)(iVar8 + 0x365)) {
    uVar3 = 1;
    do {
      puVar2[uVar3 + 0x40] = *(undefined4 *)(iVar8 + uVar3 * 4 + 0xd4);
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < *(byte *)(iVar8 + 0x365));
  }
  if (param_2 == 0) {
    puVar2[0x201] = *(undefined4 *)(iVar8 + 0x118);
  }
  iVar4 = 0;
  puVar2[0x204] = *(undefined4 *)(iVar8 + 0x11c);
  puVar2[0x205] = *(undefined4 *)(iVar8 + 0x120);
  puVar7 = (undefined4 *)(iVar8 + 0x128);
  puVar2[0x207] = *(undefined4 *)(iVar8 + 0x124);
  do {
    while( true ) {
      uVar3 = (3 << (iVar4 << 1 & 0xffU) & *(uint *)(iVar8 + 0x2ac)) >> (iVar4 << 1 & 0xffU);
      if (uVar3 < 2) break;
      if (uVar3 == 2) {
LAB_0e066cb0:
        iVar1 = iVar8 + iVar4 * 4;
        puVar2[iVar4 * 8 + 0x2c4] = *(undefined4 *)(iVar1 + 0x228);
        puVar2[iVar4 * 8 + 0x2c5] = *(undefined4 *)(iVar1 + 0x268);
        puVar2[(iVar4 + 0x58) * 8] = *(undefined4 *)(iVar1 + 0x1e8);
      }
      iVar4 = iVar4 + 1;
      puVar7 = puVar7 + 1;
      if (iVar4 == 0x10) goto LAB_0e066d28;
    }
    puVar2[iVar4 * 8 + 0x244] = puVar7[0x10];
    puVar2[iVar4 * 8 + 0x245] = puVar7[0x20];
    puVar2[(iVar4 + 0x48) * 8] = *puVar7;
    if (uVar3 == 0) goto LAB_0e066cb0;
    iVar4 = iVar4 + 1;
    puVar7 = puVar7 + 1;
  } while (iVar4 != 0x10);
LAB_0e066d28:
  *(byte *)(iVar5 + 0x362) = *(byte *)(iVar5 + 0x362) & 0xef;
  FUN_0e0646c8(param_1,0);
  FUN_0e064814(param_1,2,0);
  if (param_2 != 0) {
    FUN_0e06e3d0(1000,0);
    *(uint *)(iVar6 + 0x804) = *(uint *)(iVar6 + 0x804) & 0xfffffffe;
  }
  if (param_3 != 0) {
    FUN_0e06ee70(iVar5 + 0x9c,0xffffffff);
    FUN_0e06ee70(iVar5 + 0xa8,0xffffffff);
    FUN_0e0651b0(param_1);
    return;
  }
  iVar6 = FUN_0e06ee78(iVar5 + 0x9c,0xffffffff,0,0,0,0);
  if (iVar6 != 0) {
    FUN_0e06ee5c(iVar5 + 0x90,2);
  }
  iVar6 = FUN_0e06ee78(iVar5 + 0xa8,0xffffffff,0);
  if (iVar6 == 0) {
    return;
  }
  FUN_0e06ee5c(iVar5 + 0x90,8);
  return;
}


