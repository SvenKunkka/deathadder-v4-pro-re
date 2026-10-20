/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e390c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e0e390c(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  char cVar8;
  undefined8 uVar9;
  int local_2c;
  uint local_28;
  undefined4 uStack_24;
  byte local_20;
  uint local_1c;
  
  if ((_DAT_e000ed90 & 0xffff) >> 8 < 2) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar9 = FUN_0e0e382c(0);
    *(undefined4 *)((int)((ulonglong)uVar9 >> 0x20) + 0xc0) = 0x44ffaa;
    for (iVar1 = (int)uVar9; iVar1 != 2; iVar1 = iVar1 + 1) {
      iVar1 = FUN_0e0e3674(iVar1,iVar1 * 0x10 + 0x2f01121c);
    }
    DAT_2f011910 = 2;
    iVar1 = FUN_0e0e2cd0(&local_2c);
    for (iVar7 = 0; iVar1 != iVar7; iVar7 = iVar7 + 1) {
      iVar3 = iVar7 * 0x10;
      iVar6 = local_2c + iVar7 * 0x10;
      uVar4 = *(uint *)(iVar6 + 0xc) & 0xfff00000;
      if (uVar4 == 0x200000) {
        local_28 = *(uint *)(iVar6 + 4);
        uStack_24 = *(undefined4 *)(local_2c + iVar3);
        cVar8 = '\x02';
        local_20 = 1;
        local_1c = *(int *)(iVar6 + 8) + -1 + (local_28 & 0xffffffe0) & 0xffffffe0;
LAB_0e0e39a2:
        local_20 = local_20 | cVar8 << 5;
        iVar3 = FUN_0e0e36a8(DAT_2f011910,&local_28);
        if (iVar3 < 0) {
          return 0xffffffea;
        }
        DAT_2f011910 = DAT_2f011910 + 1;
      }
      else {
        if (uVar4 == 0x400000) {
          local_28 = *(uint *)(iVar6 + 4);
          uStack_24 = *(undefined4 *)(local_2c + iVar3);
          cVar8 = '\0';
          local_20 = 6;
          local_1c = *(int *)(iVar6 + 8) + -1 + (local_28 & 0xffffffe0) & 0xffffffe0;
          goto LAB_0e0e39a2;
        }
        if (uVar4 == 0x100000) {
          local_28 = *(uint *)(iVar6 + 4);
          uStack_24 = *(undefined4 *)(local_2c + iVar3);
          local_20 = 1;
          cVar8 = '\x01';
          local_1c = *(int *)(iVar6 + 8) + -1 + (local_28 & 0xffffffe0) & 0xffffffe0;
          goto LAB_0e0e39a2;
        }
      }
    }
    uVar4 = (uint)DAT_2f011910;
    while (uVar5 = uVar4, (int)uVar5 < (int)((_DAT_e000ed90 & 0xffff) >> 8)) {
      _DAT_e000eda0 = 0;
      _DAT_e000ed98 = uVar5;
      uVar4 = uVar5 + 1;
    }
    FUN_0e0e3814();
    uVar2 = 0;
  }
  return uVar2;
}


