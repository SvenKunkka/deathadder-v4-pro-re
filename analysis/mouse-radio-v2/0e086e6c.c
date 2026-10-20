/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e086e6c. Types and names are inferred; NOT original source. */

void FUN_0e086e6c(int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  bool bVar13;
  undefined8 uVar14;
  uint local_98;
  int iStack_94;
  uint local_90;
  int iStack_8c;
  undefined1 auStack_88 [8];
  uint local_80;
  byte local_78;
  char local_77;
  ushort local_76;
  undefined4 local_74;
  uint local_70;
  undefined1 auStack_68 [16];
  undefined1 uStack_58;
  undefined1 local_57;
  undefined1 local_48;
  char local_47 [7];
  int local_40;
  undefined4 local_3c;
  
  uVar14 = FUN_0e086a98(param_1,param_2,param_1[2],param_1[3],param_1 + 8);
  iVar11 = (int)uVar14;
  if (iVar11 == -2) {
    uVar14 = FUN_0e086b00(param_1,(int)((ulonglong)uVar14 >> 0x20),param_1[2],param_1[3]);
    if ((int)uVar14 != 0) {
      return;
    }
    iVar11 = FUN_0e086a98(param_1,(int)((ulonglong)uVar14 >> 0x20),param_1[2],param_1[3],param_1 + 8
                         );
  }
  if (iVar11 == 0) {
    iVar11 = param_1[3] + 1;
    cVar1 = (char)param_1[8];
    if (iVar11 == param_1[7]) {
      iVar11 = 0;
    }
    uVar6 = param_1[0x10];
    uVar7 = param_1[6] - uVar6;
    iVar10 = iVar11 - (uint)((uint)param_1[6] < uVar6);
    local_98 = uVar7;
    iStack_94 = iVar10;
    iVar2 = FUN_0e086c98(param_1,uVar6,uVar7,iVar10,&uStack_58,auStack_88);
    if (-1 < iVar2) {
      if (iVar2 != 0) {
        uVar6 = uVar7 + param_1[0x10] * -2;
        local_98 = local_80;
        iVar2 = iVar10 - (uint)(uVar7 < (uint)(param_1[0x10] * 2));
        *(undefined1 *)(param_1 + 8) = local_57;
        iStack_94 = iVar10;
        do {
          while( true ) {
            iVar10 = iStack_94;
            uVar7 = local_98;
            iVar3 = (*(code *)**(undefined4 **)(param_1[0xe] + 8))
                              (param_1[0xe],iStack_94 * param_1[6] + *param_1 + local_98,&local_78,
                               0x10);
            if (iVar3 != 0) {
              return;
            }
            iVar3 = FUN_0e086d14(param_1,&local_98);
            if (iVar3 != 0) {
              return;
            }
            if ((((char)param_1[8] == local_77) &&
                (uVar4 = FUN_0e085c00(0xff,&local_77,0xf), local_78 == uVar4)) && (local_76 != 0))
            break;
LAB_0e086f16:
            if (iVar2 == iVar10 && uVar6 == uVar7) goto LAB_0e08704c;
          }
          local_90 = uVar7;
          iStack_8c = iVar10;
          iVar3 = FUN_0e086d74(param_1,local_74,param_1[2],param_1[3],param_1[2],param_1[3],
                               auStack_68,&local_90);
          if (iVar3 < 0) {
            return;
          }
          if (iStack_8c != iVar10 || local_90 != uVar7) goto LAB_0e086f16;
          uVar4 = (uint)local_76;
          if (8 < uVar4) {
            iVar8 = *(int *)param_1[0xf];
            uVar12 = local_70;
            iVar3 = iVar10;
            local_70 = param_1[4];
            do {
              uVar9 = -iVar8 & 0x20U;
              if (uVar4 <= (-iVar8 & 0x20U)) {
                uVar9 = uVar4;
              }
              iVar5 = (*(code *)**(undefined4 **)(param_1[0xe] + 8))
                                (param_1[0xe],iVar3 * param_1[6] + *param_1 + uVar12,&local_48,uVar9
                                );
              if (iVar5 != 0) {
                return;
              }
              iVar5 = FUN_0e086968(param_1,&local_48,uVar9);
              if (iVar5 != 0) {
                return;
              }
              bVar13 = CARRY4(uVar9,uVar12);
              uVar12 = uVar9 + uVar12;
              iVar3 = iVar3 + (uint)bVar13;
              uVar4 = uVar4 - uVar9;
            } while (uVar4 != 0);
          }
          local_77 = cVar1;
          local_78 = FUN_0e085c00(0xff,&local_77,0xf);
          iVar3 = FUN_0e0869a4(param_1,&local_78);
          if (iVar3 != 0) {
            return;
          }
        } while (iVar2 != iVar10 || uVar6 != uVar7);
      }
LAB_0e08704c:
      *(char *)(param_1 + 8) = cVar1;
      local_40 = param_1[4];
      local_47[3] = -1;
      local_47[4] = -1;
      local_47[5] = -1;
      local_47[6] = -1;
      local_3c = 0xffffffff;
      local_47[1] = '\0';
      local_47[2] = '\0';
      local_47[0] = cVar1;
      local_48 = FUN_0e085c00(0xff,local_47,0xf);
      uVar14 = FUN_0e0869a4(param_1,&local_48);
      if ((int)uVar14 == 0) {
        FUN_0e086b00(param_1,(int)((ulonglong)uVar14 >> 0x20),0,iVar11);
        return;
      }
    }
  }
  return;
}


