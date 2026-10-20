/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e086f0c. Types and names are inferred; NOT original source. */

int FUN_0e086f0c(int *param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  bool bVar11;
  undefined8 uVar12;
  byte *pbVar13;
  undefined1 *puVar14;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  byte local_78;
  char local_77;
  short local_76;
  byte local_68;
  char local_67 [15];
  undefined1 auStack_58 [16];
  byte local_48;
  undefined1 local_47;
  short local_46;
  int local_44;
  uint local_3c;
  byte local_38;
  undefined1 local_37;
  short local_36;
  int local_34;
  int local_30;
  undefined4 local_2c;
  
  piVar8 = param_1 + 9;
  FUN_0e094c4c(piVar8);
  uVar12 = (**(code **)(*(int *)(param_1[0xe] + 8) + 0xc))();
  puVar1 = (uint *)uVar12;
  param_1[0xf] = (int)puVar1;
  if (puVar1 == (uint *)0x0) {
    return -0x16;
  }
  uVar5 = *puVar1;
  if (uVar5 < 2) {
    uVar5 = 0x10;
  }
  else {
    uVar5 = -uVar5 & uVar5 + 0xf;
  }
  param_1[0x10] = uVar5;
  if (0x1f < *puVar1 - 1) {
    return -0x16;
  }
  if ((uint)param_1[7] < 2) {
    return -0x16;
  }
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  FUN_0e094c5c(piVar8,(int)((ulonglong)uVar12 >> 0x20),0xffffffff,0xffffffff);
  if (param_1[7] == 0) {
LAB_0e087018:
    FUN_0e094d58(piVar8);
    return -0x86;
  }
  puVar14 = auStack_58;
  uVar5 = 0;
  uVar9 = 0;
  pbVar13 = &local_48;
  bVar11 = false;
  do {
    uVar7 = param_1[6];
    uVar3 = param_1[0x10] * 2;
    uVar6 = uVar9;
    if (uVar7 <= uVar3 && uVar3 - uVar7 != 0) {
      uVar6 = uVar9 - 1;
    }
    uVar7 = uVar7 + param_1[0x10] * -2;
    local_88 = uVar7;
    local_84 = uVar6;
    iVar2 = FUN_0e086b0c(param_1,uVar3,uVar7,uVar6,pbVar13,puVar14);
    if (iVar2 < 0) goto LAB_0e087026;
    *(undefined1 *)(param_1 + 8) = local_47;
    if (iVar2 == 1) {
      uVar5 = uVar5 + 1;
      if ((local_3c & 0xff00) == 0x4200) {
        if ((local_3c & 0xff) != 1) {
          iVar2 = -0x7b;
          goto LAB_0e087228;
        }
        bVar11 = true;
      }
      local_84 = uVar6 + 1;
      if (uVar6 + 1 == param_1[7]) {
        local_84 = 0;
      }
      local_88 = uVar7;
      iVar2 = FUN_0e086b0c(param_1,param_1[7],uVar7,local_84,pbVar13,puVar14);
      if (iVar2 < 0) goto LAB_0e087026;
      *(undefined1 *)(param_1 + 8) = local_47;
      if (iVar2 == 0) {
        uVar6 = param_1[7];
        if (uVar5 == uVar6) goto LAB_0e087016;
        goto LAB_0e08703a;
      }
    }
    uVar6 = param_1[7];
    uVar9 = uVar9 + 1;
  } while (uVar9 < uVar6);
  if (uVar5 == uVar6) {
LAB_0e087016:
    if (!bVar11) goto LAB_0e087018;
  }
LAB_0e08703a:
  if (uVar9 == uVar6) {
    uVar12 = (*(code *)**(undefined4 **)(param_1[0xe] + 8))
                       (param_1[0xe],
                        (local_84 - (local_88 < (uint)param_1[0x10])) * param_1[6] +
                        *param_1 + (local_88 - param_1[0x10]),&local_68,0x10);
    uVar9 = local_84;
    uVar5 = local_88;
    uVar4 = (undefined4)((ulonglong)uVar12 >> 0x20);
    iVar2 = (int)uVar12;
    if (iVar2 != 0) goto LAB_0e087026;
    if ((char)param_1[8] == local_67[0]) {
      uVar12 = FUN_0e085a74(0xff,local_67,0xf);
      uVar4 = (undefined4)((ulonglong)uVar12 >> 0x20);
      if ((uint)local_68 != (uint)uVar12) goto LAB_0e087184;
    }
    else {
LAB_0e087184:
      local_84 = uVar9 + 1;
      uVar9 = local_84;
      local_88 = uVar5;
      if (local_84 == param_1[7]) {
        local_84 = 0;
        uVar9 = 0;
      }
    }
    iVar2 = FUN_0e086ab8(param_1,uVar4,uVar5,uVar9,pbVar13,puVar14);
    if (iVar2 != 0) goto LAB_0e087026;
    uVar12 = FUN_0e085a74(0xff,&local_47,0xf);
    if ((((uint)local_48 == (uint)uVar12) && (local_46 == -1)) && (local_44 == -1)) {
      if (((local_3c & 0xff00) == 0x4200) && ((local_3c & 0xff) != 1)) {
        FUN_0e094d58(piVar8);
        return -0x7b;
      }
    }
    else {
      iVar2 = FUN_0e086974(param_1,(int)((ulonglong)uVar12 >> 0x20),uVar5,uVar9);
      if (iVar2 != 0) goto LAB_0e087026;
    }
    iVar2 = FUN_0e08690c(param_1,param_1 + 8,uVar5,uVar9,param_1 + 8);
    if (iVar2 == -2) {
      *(undefined1 *)(param_1 + 8) = 0;
    }
    else if (iVar2 != 0) goto LAB_0e087026;
  }
  iVar2 = FUN_0e086850(param_1,&local_88,&local_80);
  if (iVar2 == 0) {
    param_1[5] = local_7c;
    param_1[2] = local_88;
    param_1[3] = local_84;
    param_1[4] = local_80;
    uVar5 = local_84;
    uVar9 = local_88;
    if (local_7c < local_84 || local_84 - local_7c < (uint)(local_80 <= local_88)) {
      do {
        iVar2 = (*(code *)**(undefined4 **)(param_1[0xe] + 8))
                          (param_1[0xe],uVar5 * param_1[6] + *param_1 + uVar9,&local_78,0x10);
        if (iVar2 != 0) goto LAB_0e087026;
        if (((char)param_1[8] != local_77) ||
           (uVar5 = FUN_0e085a74(0xff,&local_77,0xf), local_78 != uVar5)) {
          uVar6 = param_1[0x10];
          uVar5 = param_1[3];
          break;
        }
        uVar5 = param_1[2];
        uVar3 = param_1[5];
        if ((param_1[3] == uVar3 && uVar5 == param_1[4]) && (local_76 != 0)) {
          iVar2 = -0x1d;
          goto LAB_0e087228;
        }
        uVar6 = param_1[0x10];
        uVar9 = uVar5 - uVar6;
        uVar5 = param_1[3] - (uint)(uVar5 < uVar6);
        param_1[2] = uVar9;
        param_1[3] = uVar5;
      } while (uVar3 < uVar5 || uVar5 - uVar3 < (uint)((uint)param_1[4] <= uVar9));
    }
    else {
      uVar6 = param_1[0x10];
    }
    local_88 = param_1[6] + uVar6 * -2;
    local_84 = uVar5 + (uVar6 * 2 <= (uint)param_1[6]);
    if (local_84 == param_1[7]) {
      local_84 = 0;
    }
    iVar2 = FUN_0e086b0c(param_1);
    if (-1 < iVar2) {
      uVar6 = param_1[2];
      uVar5 = param_1[6];
      iVar10 = param_1[3];
      uVar9 = param_1[0x10];
      if (iVar2 != 1) {
LAB_0e0870d6:
        if (uVar6 == uVar5 + uVar9 * -3) {
          local_30 = param_1[4];
          local_36 = 0;
          local_37 = (undefined1)param_1[8];
          local_34 = -1;
          local_2c = 0xffffffff;
          local_38 = FUN_0e085a74(0xff,&local_37,0xf);
          iVar2 = FUN_0e086818(param_1,&local_38);
LAB_0e087228:
          FUN_0e094d58(piVar8);
          if (iVar2 != 0) {
            return iVar2;
          }
        }
        else {
          FUN_0e094d58(piVar8);
        }
        *(undefined1 *)((int)param_1 + 0x21) = 1;
        return 0;
      }
      uVar7 = uVar9 + uVar6;
      uVar3 = uVar5 + uVar9 * -2;
      uVar9 = iVar10 + (uint)CARRY4(uVar9,uVar6);
      *(undefined1 *)(param_1 + 8) = local_47;
      local_88 = uVar7;
      local_84 = uVar9;
      if (uVar7 < uVar3) {
        do {
          local_88 = uVar7;
          local_84 = uVar9;
          iVar2 = (*(code *)**(undefined4 **)(param_1[0xe] + 8))
                            (param_1[0xe],uVar9 * uVar5 + *param_1 + uVar7,&local_38,0x10,pbVar13,
                             puVar14);
          if (iVar2 != 0) goto LAB_0e087026;
          uVar12 = FUN_0e085a74(0xff,&local_37,0xf);
          uVar5 = (uint)((ulonglong)uVar12 >> 0x20);
          if ((((uint)local_38 == (uint)uVar12) && (local_36 == 0)) && (local_34 == -1)) break;
          uVar6 = param_1[0x10];
          uVar5 = param_1[6];
          bVar11 = CARRY4(uVar6,uVar7);
          uVar7 = uVar6 + uVar7;
          uVar9 = uVar9 + bVar11;
          local_88 = uVar7;
          local_84 = uVar9;
        } while (uVar7 < uVar5 + uVar6 * -2);
        uVar6 = param_1[2];
        iVar10 = param_1[3];
        uVar3 = uVar5;
      }
      iVar2 = FUN_0e086974(param_1,uVar3,uVar6,iVar10);
      if (iVar2 == 0) {
        param_1[4] = 0;
        param_1[2] = param_1[6] + param_1[0x10] * -3;
        param_1[5] = param_1[3];
        iVar2 = FUN_0e086ce0(param_1);
        if (iVar2 == 0) {
          uVar5 = param_1[6];
          uVar9 = param_1[0x10];
          uVar6 = param_1[2];
          goto LAB_0e0870d6;
        }
      }
    }
  }
LAB_0e087026:
  FUN_0e094d58(piVar8);
  return iVar2;
}


