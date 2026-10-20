/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ada24. Types and names are inferred; NOT original source. */

int FUN_0e0ada24(int param_1,uint param_2,uint param_3,byte param_4)

{
  code *pcVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  bool bVar11;
  undefined1 local_3e;
  byte local_3d;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 *local_30;
  undefined4 *puStack_2c;
  
  bVar11 = (int)(param_3 << 0x1b) < 0;
  local_3d = param_4;
  if (bVar11) {
    local_3d = 3;
  }
  iVar8 = *(int *)(param_1 + 4);
  uVar9 = param_3 & 0x306;
  if (!bVar11) {
    local_3d = (byte)((param_3 & 0x3f) >> 5);
  }
  bVar2 = *(byte *)(iVar8 + 0xc);
  if (uVar9 == 0x106) {
    uVar9 = 9;
  }
  else if (uVar9 < 0x107) {
    if (uVar9 == 6) {
      uVar9 = 8;
    }
    else if (uVar9 < 7) {
      if ((uVar9 != 0) && (uVar9 != 2)) {
        return -0x16;
      }
    }
    else {
      if (uVar9 != 0x100) {
        return -0x16;
      }
      uVar9 = 1;
    }
  }
  else if (uVar9 == 0x202) {
    uVar9 = 6;
  }
  else if (uVar9 == 0x300) {
    uVar9 = 5;
  }
  else {
    if (uVar9 != 0x200) {
      return -0x16;
    }
    uVar9 = 4;
  }
  iVar10 = 1 << (param_2 & 0xff);
  iVar3 = FUN_0e0b1ef0(iVar8,iVar10);
  if (iVar3 < 0) {
    return iVar3;
  }
  if ((int)(param_3 << 0xc) < 0) {
    *(int *)(*(int *)(iVar8 + 4) + 4) = iVar10;
  }
  else if ((int)(param_3 << 0xd) < 0) {
    *(int *)(*(int *)(iVar8 + 4) + 8) = iVar10;
  }
  uVar7 = param_2 & 0x1f | (uint)bVar2 << 5;
  if (*(int *)(iVar8 + 0x10) == 0) {
    if (0x13f < uVar7) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)software_udf(0xff,0xe0adbce);
      (*pcVar1)();
    }
    iVar8 = *(int *)(&DAT_0e0b3bd8 + (uint)bVar2 * 4) + (param_2 & 0x1f) * 4;
    *(uint *)(iVar8 + 0x80) =
         (param_3 & 0x3ffff) >> 0x11 | (((param_3 ^ 0x10000) & 0x1ffff) >> 0x10) << 1 |
         (uint)local_3d << 2 | *(uint *)(iVar8 + 0x80) & 0xfffff0f0 | uVar9 << 8;
    goto LAB_0e0adafe;
  }
  iVar8 = iVar8 + 0x10;
  iVar4 = FUN_0e0ae51c(iVar8,uVar7,&local_3e);
  if ((param_3 & 0x30000) == 0) {
    thunk_FUN_0e0ae20c(iVar8,uVar7);
LAB_0e0adb4c:
    if (iVar4 == 0xbad0000) {
      FUN_0e0ae5cc(iVar8,local_3e);
    }
  }
  else {
    local_30 = &local_3c;
    puStack_2c = (undefined4 *)0x0;
    local_3c = 0;
    uStack_38 = 0;
    local_34 = (byte *)0x0;
    iVar5 = FUN_0e0ae290(iVar8,uVar7,&local_34);
    if (iVar5 == 0xbad0000) {
      puVar6 = (undefined4 *)(param_3 & 0x20000);
      if (puVar6 == (undefined4 *)0x0) {
        local_34 = &local_3d;
        local_30 = puVar6;
        puStack_2c = puVar6;
        iVar5 = FUN_0e0ae290(iVar8,uVar7,&local_34);
      }
      else {
        local_34 = (byte *)CONCAT31(CONCAT12(local_34._3_1_,
                                             CONCAT11(local_3d,(byte)(((param_3 ^ 0x10000) << 0xf)
                                                                     >> 0x1f))),(char)uVar9);
        iVar5 = FUN_0e0ae408(iVar8,uVar7,&local_34,0);
      }
      if (iVar5 == 0xbad0000) goto LAB_0e0adb4c;
    }
    iVar3 = -0x16;
  }
LAB_0e0adafe:
  FUN_0e0b1f0c(*(undefined4 *)(param_1 + 4),iVar10,param_3);
  return iVar3;
}


