/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e084ec8. Types and names are inferred; NOT original source. */

int FUN_0e084ec8(void)

{
  byte bVar1;
  sbyte sVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint *puVar10;
  uint local_1c [2];
  
  iVar4 = DAT_0e084f6c;
  iVar5 = FUN_0e094688(*(undefined4 *)(DAT_0e084f6c + 0x24));
  if (iVar5 != 0) {
    uVar3 = *(ushort *)(iVar4 + 0x2a);
    iVar5 = *(int *)(iVar4 + 0x24);
    bVar1 = *(byte *)(iVar4 + 0x28);
    uVar7 = 1 << (uint)bVar1;
    uVar9 = **(uint **)(iVar5 + 0x10);
    puVar8 = *(undefined4 **)(iVar5 + 8);
    if ((uVar3 & 1) == 0) {
      uVar7 = uVar9 & ~uVar7;
    }
    else {
      uVar7 = uVar7 | uVar9;
    }
    **(uint **)(iVar5 + 0x10) = uVar7;
    (*(code *)*puVar8)(iVar5,(uint)bVar1,uVar3 | 0x10010);
    FUN_0e09467c(5);
    iVar5 = *(int *)(iVar4 + 0x24);
    sVar2 = *(sbyte *)(iVar4 + 0x28);
    puVar10 = *(uint **)(iVar5 + 0x10);
    iVar5 = (**(code **)(*(int *)(iVar5 + 8) + 4))(iVar5,local_1c);
    if (iVar5 == 0) {
      if (((local_1c[0] ^ *puVar10) & 1 << sVar2) == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = 1;
      }
    }
    uVar3 = *(ushort *)(iVar4 + 0x2a);
    iVar6 = *(int *)(iVar4 + 0x24);
    bVar1 = *(byte *)(iVar4 + 0x28);
    uVar7 = 1 << (uint)bVar1;
    uVar9 = **(uint **)(iVar6 + 0x10);
    puVar8 = *(undefined4 **)(iVar6 + 8);
    if ((uVar3 & 1) == 0) {
      uVar7 = uVar9 & ~uVar7;
    }
    else {
      uVar7 = uVar7 | uVar9;
    }
    **(uint **)(iVar6 + 0x10) = uVar7;
    (*(code *)*puVar8)(iVar6,(uint)bVar1,uVar3 | 0x10020);
    return iVar5;
  }
  return 0;
}


