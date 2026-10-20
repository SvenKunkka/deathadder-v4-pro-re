/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e093f18. Types and names are inferred; NOT original source. */

/* WARNING: Type propagation algorithm not settling */

void FUN_0e093f18(int *param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  bool bVar7;
  code *UNRECOVERED_JUMPTABLE;
  int iVar8;
  undefined *puVar9;
  byte bVar10;
  byte bVar11;
  bool bVar12;
  undefined4 uVar13;
  
  if (param_3 < 5) {
    bVar10 = 0xff;
    bVar11 = 0xff;
    UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
      puVar9 = (undefined *)0x0;
      uVar13 = 0xffffffb3;
      bVar10 = 0xff;
      goto LAB_0e093fa8;
    }
    uVar13 = 0xffffffb3;
    puVar9 = (undefined *)0x0;
    bVar11 = 0xff;
    goto LAB_0e093fae;
  }
  bVar11 = *param_2;
  uVar5 = (uint)param_2[2];
  bVar1 = param_2[3];
  bVar3 = param_2[4];
  bVar10 = param_2[1];
  uVar4 = (ushort)bVar3;
  if ((char)*param_2 < '\0') {
    if (bVar3 < DAT_230077c9) {
      puVar9 = &DAT_0e09d120 + (short)uVar4 * 0x28;
      *(undefined1 *)((&DAT_0e09d128)[(short)uVar4 * 10] + 0x14) = 1;
      if (uVar5 == 0xff) {
switchD_0e093f64_default:
        FUN_0e090ab4(param_2,param_3);
        iVar8 = *(int *)(*param_1 + 0x10);
        uVar13 = extraout_r1_01;
      }
      else {
        bVar11 = 0x80;
switchD_0e093f64_caseD_1:
        if (7 < uVar5) {
          uVar13 = 0xffffffb3;
          UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
          if (UNRECOVERED_JUMPTABLE != (code *)0x0) goto LAB_0e093fa8;
          goto LAB_0e093fae;
        }
        if (((*(code **)(&DAT_2300752c + uVar5 * 0x24) != (code *)0x0) && (bVar11 == 1)) &&
           (*(int *)(*param_1 + 0x10) == 0)) {
          (**(code **)(&DAT_2300752c + uVar5 * 0x24))
                    (puVar9,param_2 + 5,param_3 - 5,*(undefined4 *)(&DAT_23007530 + uVar5 * 0x24));
          FUN_0e090ad8(&DAT_23007534 + uVar5 * 0x24,1,0);
          UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
          goto joined_r0x0e094082;
        }
        FUN_0e090ad8(&DAT_23007534 + uVar5 * 0x24,param_2);
        iVar8 = *(int *)(*param_1 + 0x10);
        uVar13 = extraout_r1_00;
      }
      if (iVar8 != 0) {
        return;
      }
      puVar9 = (undefined *)(*(int *)(puVar9 + 8) + 4);
      goto LAB_0e093fd0;
    }
    bVar11 = 0x80;
LAB_0e093f9a:
    UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
    if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
      uVar13 = 0xffffffb3;
      puVar9 = (undefined *)0x0;
    }
    else {
      puVar9 = (undefined *)0x0;
      uVar13 = 0xffffffb3;
LAB_0e093fa8:
      (*UNRECOVERED_JUMPTABLE)(param_1,param_2);
    }
  }
  else {
    if (bVar11 < 4) {
      if (bVar3 < DAT_230077c9) {
        iVar8 = (short)uVar4 * 0x28;
        puVar9 = &DAT_0e09d120 + iVar8;
        *(undefined1 *)((&DAT_0e09d128)[(short)uVar4 * 10] + 0x14) = 1;
        switch(bVar11) {
        case 1:
          goto switchD_0e093f64_caseD_1;
        case 2:
          if (*(code **)(&DAT_0e09d130 + iVar8) == (code *)0x0) {
LAB_0e094122:
            UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
          }
          else {
            (**(code **)(&DAT_0e09d130 + iVar8))(bVar10,*(undefined4 *)(&DAT_0e09d134 + iVar8));
            UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
          }
          break;
        case 3:
          if (param_3 < 9) {
            uVar13 = 0xffffffb3;
          }
          else {
            uVar13 = *(undefined4 *)(param_2 + 5);
          }
          FUN_0e093e14(uVar13,2,puVar9,bVar10,0xff);
          UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
          break;
        default:
          goto switchD_0e093f64_default;
        }
joined_r0x0e094082:
        if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
          return;
        }
                    /* WARNING: Could not recover jumptable at 0x0e09406e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)(param_1,param_2);
        return;
      }
      goto LAB_0e093f9a;
    }
    if ((bVar11 != 4) || (param_3 == 5)) goto LAB_0e093f9a;
    iVar8 = param_3 - 6;
    if (iVar8 == 0) goto LAB_0e093f9a;
    if ((param_2[5] & 0xf) != 0) {
      UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
      if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
        uVar13 = 0xffffffd5;
        puVar9 = (undefined *)0x0;
        goto LAB_0e093fae;
      }
      puVar9 = (undefined *)0x0;
      uVar13 = 0xffffffd5;
      goto LAB_0e093fa8;
    }
    puVar9 = &DAT_0e09d120;
    do {
      uVar13 = *(undefined4 *)(puVar9 + 0x18);
      iVar6 = FUN_0e079630(uVar13);
      if ((iVar8 == iVar6) && (iVar6 = FUN_0e0973fa(param_2 + 6,uVar13,iVar8), iVar6 == 0)) {
        cVar2 = *(char *)(*(int *)(puVar9 + 8) + 1);
        *(byte *)(*(int *)(puVar9 + 8) + 1) = bVar1;
        if (cVar2 == -1) {
          bVar12 = bVar3 == 0xff;
          bVar7 = false;
          if ((*(uint *)(puVar9 + 0x24) & 1) != 0) {
            DAT_230077c7 = DAT_230077c7 + '\x01';
            bVar7 = DAT_230077c8 == DAT_230077c7;
          }
        }
        else {
          if (bVar3 != 0xff) goto LAB_0e094122;
          bVar12 = true;
          bVar7 = false;
        }
        DAT_23007500 = 0;
        DAT_23007508 = CONCAT31(CONCAT12(DAT_23007508._3_1_,CONCAT11(bVar7,bVar12)),cVar2 == -1);
        DAT_23007504 = puVar9;
        FUN_0e090ab4(&DAT_23007500,0x10);
        FUN_0e094fc8(&DAT_230074f0,extraout_r1_02,0xffffffff,0xffffffff);
        goto LAB_0e094122;
      }
      puVar9 = puVar9 + 0x28;
    } while (puVar9 < &UNK_0e09d148);
    UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
      puVar9 = (undefined *)0x0;
      uVar13 = 0xfffffff2;
      goto LAB_0e093fa8;
    }
    uVar13 = 0xfffffff2;
    puVar9 = (undefined *)0x0;
  }
LAB_0e093fae:
  DAT_2300750d = bVar11;
  DAT_23007500 = 1;
  DAT_23007504 = puVar9;
  DAT_23007508 = uVar13;
  DAT_2300750c = bVar10;
  FUN_0e090ab4(&DAT_23007500,0x10);
  puVar9 = &DAT_230074f0;
  uVar13 = extraout_r1;
LAB_0e093fd0:
  FUN_0e094fc8(puVar9,uVar13,0xffffffff,0xffffffff);
  return;
}


