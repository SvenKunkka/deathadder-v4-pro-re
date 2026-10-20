/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06c114. Types and names are inferred; NOT original source. */

/* WARNING: Type propagation algorithm not settling */

void FUN_0e06c114(int *param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  undefined1 *puVar6;
  uint uVar7;
  uint uVar8;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  bool bVar9;
  code *UNRECOVERED_JUMPTABLE;
  int iVar10;
  int iVar11;
  byte bVar12;
  byte bVar13;
  int iVar14;
  bool bVar15;
  undefined4 uVar16;
  
  uVar7 = DAT_0e06c3e8;
  if (param_3 < 5) {
    bVar12 = 0xff;
    bVar13 = 0xff;
    UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
      iVar11 = 0;
      uVar16 = 0xffffffb3;
      bVar12 = 0xff;
      bVar13 = 0xff;
      goto LAB_0e06c1a4;
    }
    uVar16 = 0xffffffb3;
    iVar11 = 0;
    goto LAB_0e06c1aa;
  }
  bVar13 = *param_2;
  bVar5 = param_2[4];
  bVar1 = param_2[3];
  uVar8 = (uint)param_2[2];
  bVar12 = param_2[1];
  if ((char)*param_2 < '\0') {
    if (bVar5 < *DAT_0e06c3d0) {
      iVar11 = (short)(ushort)bVar5 * 0x28 + 4 + DAT_0e06c3d4;
      *(undefined1 *)(*(int *)(iVar11 + 8) + 0x14) = 1;
      if (uVar8 == 0xff) {
switchD_0e06c160_default:
        FUN_0e068740(param_2,param_3);
        iVar10 = *(int *)(*param_1 + 0x10);
        uVar16 = extraout_r1_01;
      }
      else {
        bVar13 = 0x80;
switchD_0e06c160_caseD_1:
        if (7 < uVar8) {
          uVar16 = 0xffffffb3;
          UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
          if (UNRECOVERED_JUMPTABLE != (code *)0x0) goto LAB_0e06c1a4;
          goto LAB_0e06c1aa;
        }
        iVar10 = DAT_0e06c3e0 + uVar8 * 0x24;
        UNRECOVERED_JUMPTABLE = *(code **)(iVar10 + 4);
        iVar14 = uVar8 * 0x24 + DAT_0e06c3e0 + 0xc;
        if (((UNRECOVERED_JUMPTABLE != (code *)0x0) && (bVar13 == 1)) &&
           (*(int *)(*param_1 + 0x10) == 0)) {
          (*UNRECOVERED_JUMPTABLE)(iVar11,param_2 + 5,param_3 - 5,*(undefined4 *)(iVar10 + 8));
          FUN_0e068764(iVar14,1,0);
          UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
          goto joined_r0x0e06c27e;
        }
        FUN_0e068764(iVar14,param_2);
        iVar10 = *(int *)(*param_1 + 0x10);
        uVar16 = extraout_r1_00;
      }
      if (iVar10 != 0) {
        return;
      }
      iVar11 = *(int *)(iVar11 + 8) + 4;
      goto LAB_0e06c1cc;
    }
    bVar13 = 0x80;
LAB_0e06c196:
    UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
    if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
      uVar16 = 0xffffffb3;
      iVar11 = 0;
    }
    else {
      iVar11 = 0;
      uVar16 = 0xffffffb3;
LAB_0e06c1a4:
      (*UNRECOVERED_JUMPTABLE)(param_1,param_2);
    }
  }
  else {
    if (bVar13 < 4) {
      if (bVar5 < *DAT_0e06c3d0) {
        iVar11 = (short)(ushort)bVar5 * 0x28 + 4 + DAT_0e06c3d4;
        *(undefined1 *)(*(int *)(iVar11 + 8) + 0x14) = 1;
        switch(bVar13) {
        case 1:
          goto switchD_0e06c160_caseD_1;
        case 2:
          if (*(code **)(iVar11 + 0x10) == (code *)0x0) {
LAB_0e06c31e:
            UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
          }
          else {
            (**(code **)(iVar11 + 0x10))(bVar12,*(undefined4 *)(iVar11 + 0x14));
            UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
          }
          break;
        case 3:
          if (param_3 < 9) {
            uVar16 = 0xffffffb3;
          }
          else {
            uVar16 = *(undefined4 *)(param_2 + 5);
          }
          FUN_0e06c010(uVar16,2,iVar11,bVar12,0xff);
          UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
          break;
        default:
          goto switchD_0e06c160_default;
        }
joined_r0x0e06c27e:
        if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
          return;
        }
                    /* WARNING: Could not recover jumptable at 0x0e06c26a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)(param_1,param_2);
        return;
      }
      goto LAB_0e06c196;
    }
    if ((bVar13 != 4) || (param_3 == 5)) goto LAB_0e06c196;
    iVar11 = param_3 - 6;
    if (iVar11 == 0) goto LAB_0e06c196;
    if ((param_2[5] & 0xf) != 0) {
      UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
      if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
        uVar16 = 0xffffffd5;
        iVar11 = 0;
        goto LAB_0e06c1aa;
      }
      iVar11 = 0;
      uVar16 = 0xffffffd5;
      goto LAB_0e06c1a4;
    }
    if (DAT_0e06c3e4 < DAT_0e06c3e8) {
      uVar8 = DAT_0e06c3e4;
      do {
        uVar16 = *(undefined4 *)(uVar8 + 0x18);
        iVar10 = FUN_0e05bc30(uVar16);
        if ((iVar11 == iVar10) && (iVar10 = FUN_0e06f456(param_2 + 6,uVar16,iVar11), iVar10 == 0)) {
          cVar2 = *(char *)(*(int *)(uVar8 + 8) + 1);
          *(byte *)(*(int *)(uVar8 + 8) + 1) = bVar1;
          if (cVar2 == -1) {
            bVar15 = bVar5 == 0xff;
            bVar9 = false;
            if ((*(uint *)(uVar8 + 0x24) & 1) != 0) {
              cVar3 = *DAT_0e06c3ec;
              cVar4 = *DAT_0e06c3f0;
              *DAT_0e06c3ec = cVar3 + '\x01';
              bVar9 = cVar4 == (char)(cVar3 + '\x01');
            }
          }
          else {
            if (bVar5 != 0xff) goto LAB_0e06c31e;
            bVar15 = true;
            bVar9 = false;
          }
          puVar6 = DAT_0e06c3d8;
          *DAT_0e06c3d8 = 0;
          *(uint *)(puVar6 + 4) = uVar8;
          puVar6[9] = bVar15;
          puVar6[10] = bVar9;
          puVar6[8] = cVar2 == -1;
          FUN_0e068740(puVar6,0x10);
          FUN_0e06d1b4(DAT_0e06c3dc,extraout_r1_02,0xffffffff,0xffffffff);
          goto LAB_0e06c31e;
        }
        uVar8 = uVar8 + 0x28;
      } while (uVar8 < uVar7);
    }
    UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
      iVar11 = 0;
      uVar16 = 0xfffffff2;
      goto LAB_0e06c1a4;
    }
    uVar16 = 0xfffffff2;
    iVar11 = 0;
  }
LAB_0e06c1aa:
  puVar6 = DAT_0e06c3d8;
  *(int *)(DAT_0e06c3d8 + 4) = iVar11;
  *(undefined4 *)(puVar6 + 8) = uVar16;
  puVar6[0xd] = bVar13;
  puVar6[0xc] = bVar12;
  *puVar6 = 1;
  FUN_0e068740(puVar6,0x10);
  iVar11 = DAT_0e06c3dc;
  uVar16 = extraout_r1;
LAB_0e06c1cc:
  FUN_0e06d1b4(iVar11,uVar16,0xffffffff,0xffffffff);
  return;
}


