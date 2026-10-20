/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0727cc. Types and names are inferred; NOT original source. */

int FUN_0e0727cc(int param_1,uint param_2,uint param_3)

{
  code *pcVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  undefined1 local_3e;
  byte local_3d;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 *local_30;
  undefined4 *local_2c;
  
  if ((int)(param_3 << 0x1b) < 0) {
    local_3d = 3;
  }
  else {
    local_3d = (byte)((param_3 << 0x1a) >> 0x1f);
  }
  iVar4 = 0x306;
  iVar8 = *(int *)(param_1 + 4);
  uVar6 = param_3 & 0x306;
  bVar2 = *(byte *)(iVar8 + 0xc);
  if (uVar6 == 0x106) {
    uVar6 = 9;
LAB_0e072814:
    iVar9 = 1 << (param_2 & 0xff);
    if (*(char *)(iVar8 + 0x18) != '\x01') goto LAB_0e072824;
LAB_0e0728c0:
    iVar4 = thunk_FUN_0e08add4();
    if (iVar4 < 0) {
      return iVar4;
    }
    iVar4 = *(int *)(iVar8 + 4);
    *(int *)(iVar4 + 0x48) = iVar9;
    if ((int)(param_3 << 0xc) < 0) goto LAB_0e0728d6;
LAB_0e072828:
    bVar10 = (int)(param_3 << 0xd) < 0;
    if (bVar10) {
      iVar4 = *(int *)(iVar8 + 4);
    }
    if (bVar10) {
      *(int *)(iVar4 + 8) = iVar9;
    }
    uVar7 = param_2 & 0x1f | (uint)bVar2 << 5;
    if (*(int *)(iVar8 + 0x10) != 0) goto LAB_0e072846;
LAB_0e0728ee:
    if (0x13f < uVar7) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)software_udf(0xff,0xe0729de);
      (*pcVar1)();
    }
    iVar4 = *(int *)(DAT_0e0729e4 + (uVar7 >> 5) * 4) + (uVar7 & 0x1f) * 4;
    *(uint *)(iVar4 + 0x80) =
         (param_3 & 0x3ffff) >> 0x11 | (((param_3 ^ 0x10000) & 0x1ffff) >> 0x10) << 1 |
         (uint)local_3d << 2 | *(uint *)(iVar4 + 0x80) & 0xfffff0f0 | uVar6 << 8;
  }
  else {
    if (uVar6 < 0x107) {
      if (uVar6 == 6) {
        uVar6 = 8;
      }
      else if (uVar6 < 7) {
        if ((uVar6 != 0) && (uVar6 != 2)) {
          return -0x16;
        }
      }
      else {
        if (uVar6 != 0x100) {
          return -0x16;
        }
        uVar6 = 1;
      }
      goto LAB_0e072814;
    }
    if (uVar6 == 0x202) {
      uVar6 = 6;
      goto LAB_0e072814;
    }
    if (uVar6 == 0x300) {
      uVar6 = 5;
      goto LAB_0e072814;
    }
    if (uVar6 != 0x200) {
      return -0x16;
    }
    uVar6 = 4;
    iVar9 = 1 << (param_2 & 0xff);
    if (*(char *)(iVar8 + 0x18) == '\x01') goto LAB_0e0728c0;
LAB_0e072824:
    if (-1 < (int)(param_3 << 0xc)) goto LAB_0e072828;
LAB_0e0728d6:
    *(int *)(*(int *)(iVar8 + 4) + 4) = iVar9;
    uVar7 = param_2 & 0x1f | (uint)bVar2 << 5;
    if (*(int *)(iVar8 + 0x10) == 0) goto LAB_0e0728ee;
LAB_0e072846:
    iVar8 = iVar8 + 0x10;
    iVar4 = FUN_0e07581c(iVar8,uVar7,&local_3e);
    if ((param_3 & 0x30000) != 0) {
      local_30 = &local_3c;
      local_3c = 0;
      uStack_38 = 0;
      local_34 = (byte *)0x0;
      local_2c = (undefined4 *)0x0;
      iVar3 = FUN_0e075924(iVar8,uVar7,&local_34);
      if (iVar3 == DAT_0e0729e0) {
        puVar5 = (undefined4 *)(param_3 & 0x20000);
        if (puVar5 == (undefined4 *)0x0) {
          local_34 = &local_3d;
          local_30 = puVar5;
          local_2c = puVar5;
          iVar3 = FUN_0e075924(iVar8,uVar7,&local_34);
        }
        else {
          local_34 = (byte *)CONCAT31(CONCAT21(CONCAT11(local_34._3_1_,local_3d),
                                               (byte)(((param_3 ^ 0x10000) << 0xf) >> 0x1f)),
                                      (char)uVar6);
          iVar3 = FUN_0e075c3c(iVar8,uVar7,&local_34,0);
        }
        if (iVar3 == DAT_0e0729e0) goto LAB_0e072866;
      }
      iVar4 = -0x16;
      goto LAB_0e072872;
    }
    thunk_FUN_0e075f40(iVar8,uVar7);
LAB_0e072866:
    if (iVar4 == DAT_0e0729e0) {
      FUN_0e075804(iVar8,local_3e);
    }
  }
  iVar4 = 0;
LAB_0e072872:
  if (*(char *)(*(int *)(param_1 + 4) + 0x18) == '\x01') {
    if ((int)(param_3 << 0xe) < 0) {
      *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x44) = iVar9;
    }
    thunk_FUN_0e08ae84(1);
  }
  return iVar4;
}


