/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e087354. Types and names are inferred; NOT original source. */

uint FUN_0e087354(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  uint uVar1;
  bool bVar2;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  undefined4 uStack_2c;
  
  if (*(char *)(param_1 + 0x21) == '\0') {
    return 0xfffffff3;
  }
  uVar7 = **(uint **)(param_1 + 0x3c);
  uVar5 = param_4;
  if (1 < uVar7) {
    uVar5 = (param_4 + uVar7) - 1 & -uVar7;
  }
  uVar7 = *(uint *)(param_1 + 0x40);
  if ((*(int *)(param_1 + 0x18) + uVar7 * -5 < param_4) || (0xffff < param_4)) {
LAB_0e0874a2:
    uVar5 = 0xffffffea;
  }
  else {
    uVar9 = uVar5;
    if (param_4 == 0) {
      if (uVar5 != 0) {
        uVar9 = uVar7;
      }
    }
    else {
      if (param_3 == 0) goto LAB_0e0874a2;
      if ((uVar5 != 0) && (uVar9 = uVar7, 8 < param_4)) {
        uVar9 = uVar5 + uVar7;
      }
    }
    FUN_0e094c5c(param_1 + 0x24,uVar7 * 5,0xffffffff,0xffffffff);
    if (*(int *)(param_1 + 0x1c) != 0) {
      iVar8 = 0;
      do {
        uVar7 = *(uint *)(param_1 + 8);
        uVar5 = *(uint *)(param_1 + 0xc);
        iVar8 = iVar8 + 1;
        if (uVar7 != 0) {
          uVar4 = *(uint *)(param_1 + 0x10);
          uVar6 = *(int *)(param_1 + 0x14) + (uint)CARRY4(uVar9,uVar4);
          bVar10 = uVar9 + uVar4 <= uVar7;
          uVar1 = uVar5 - uVar6;
          bVar2 = uVar6 < uVar5;
          uVar5 = (uVar5 - uVar6) - (uint)!bVar10;
          if (bVar2 || uVar1 < bVar10) {
            if (uVar7 == *(uint *)(param_1 + 0x40)) {
              if (param_4 != 0) goto LAB_0e0873f0;
              local_38 = (uint)*(byte *)(param_1 + 0x20) << 8;
              local_30 = 0;
              uStack_2c = 0;
              local_34 = param_2;
LAB_0e087490:
              uVar3 = FUN_0e085a74(0xff,(int)&local_38 + 1,0xf);
              local_38 = CONCAT31(local_38._1_3_,uVar3);
            }
            else {
              local_30 = 0;
              uStack_2c = 0;
              local_38 = (uint)CONCAT21((short)param_4,*(undefined1 *)(param_1 + 0x20)) << 8;
              if (param_4 < 9) {
                local_34 = param_2;
                if (param_4 - 1 < 8) {
                  FUN_0e09739c(&local_30,param_3,param_4);
                }
                goto LAB_0e087490;
              }
              local_34 = param_2;
              local_30 = uVar4;
              uVar3 = FUN_0e085a74(0xff,(int)&local_38 + 1,0xf);
              local_38 = CONCAT31(local_38._1_3_,uVar3);
              uVar5 = FUN_0e0867dc(param_1,param_3,param_4);
              if (uVar5 != 0) goto LAB_0e0873fc;
            }
            uVar5 = FUN_0e086818(param_1,&local_38);
            if (uVar5 == 0) {
              uVar5 = param_4;
            }
            goto LAB_0e0873fc;
          }
        }
LAB_0e0873f0:
        uVar5 = FUN_0e0869f4(param_1,uVar5);
        if ((uVar5 != 0) || (uVar5 = FUN_0e086ce0(param_1), uVar5 != 0)) goto LAB_0e0873fc;
      } while (*(int *)(param_1 + 0x1c) != iVar8);
    }
    uVar5 = 0xffffffe4;
LAB_0e0873fc:
    FUN_0e094d58(param_1 + 0x24);
  }
  return uVar5;
}


