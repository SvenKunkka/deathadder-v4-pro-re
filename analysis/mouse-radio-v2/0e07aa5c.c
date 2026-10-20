/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07aa5c. Types and names are inferred; NOT original source. */

void FUN_0e07aa5c(undefined1 *param_1)

{
  undefined1 uVar1;
  char cVar2;
  bool bVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  ushort *puVar6;
  byte *pbVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  
  puVar4 = DAT_0e07ace4;
  uVar9 = DAT_0e07a5d4;
  switch(*param_1) {
  case 0:
    FUN_0e07a89c(param_1[1],(int)(char)param_1[4],param_1[5]);
    return;
  case 1:
    iVar11 = *(int *)(param_1 + 8);
    uVar9 = *(undefined4 *)(param_1 + 0xc);
    uVar13 = (uint)(byte)param_1[1];
    iVar15 = (int)(char)param_1[4];
    uVar12 = (uint)(byte)param_1[6];
    uVar1 = param_1[5];
    DAT_0e07ace4[0x100] = 0;
    puVar4[0x124] = 0xffffffff;
    puVar4[0x88] = 0;
    puVar4[4] = 1;
    do {
    } while (puVar4[0x88] == 0);
    puVar4[0x88] = 0;
    FUN_0e07a7a8(uVar13,uVar1,uVar9,puVar4[0x88]);
    puVar5 = DAT_0e07ace4;
    if (uVar13 < 7) {
      if (4 < uVar13) {
        puVar4[0x100] = puVar4[0x100] | 0x100001;
        puVar4[0x140] = uVar13;
        FUN_0e07a5e0(iVar15);
        goto LAB_0e07ac30;
      }
    }
    else if (uVar13 == 0xf) {
      puVar4[0x100] = puVar4[0x100] | 0x100001;
      puVar4[0x140] = 0xf;
      FUN_0e07a5e0(iVar15);
      if (uVar12 - 0xb < 0x10) {
        uVar12 = uVar12 * 5 - 0x32;
      }
      else {
        uVar12 = 5;
      }
      goto LAB_0e07ac30;
    }
    DAT_0e07ace4[0x100] = DAT_0e07ace4[0x100] | 0x21;
    puVar5[0x140] = uVar13;
    FUN_0e07a5e0(iVar15);
LAB_0e07ac30:
    puVar5 = DAT_0e07acf0;
    puVar4 = DAT_0e07ace4;
    DAT_0e07ace4[0x1c2] = uVar12;
    *puVar5 = 0;
    puVar4[0x86] = 0;
    if (iVar11 != 0) {
      puVar4[0x122] = 0x40;
    }
    *DAT_0e07ace4 = 1;
    return;
  case 2:
    FUN_0e07a930(param_1[1],param_1[0xc],param_1[4]);
    return;
  case 3:
    uVar8 = *(undefined4 *)(param_1 + 8);
    uVar1 = param_1[5];
    break;
  case 4:
    uVar8 = *(undefined4 *)(param_1 + 8);
    uVar1 = param_1[4];
    break;
  case 5:
    uVar12 = *(uint *)(param_1 + 8);
    iVar11 = *(int *)(param_1 + 0xc);
    uVar14 = (uint)(byte)param_1[1];
    cVar2 = param_1[4];
    uVar13 = (uint)(byte)param_1[6];
    uVar1 = param_1[5];
    uVar9 = *(undefined4 *)(param_1 + 0x10);
    DAT_0e07ace4[0x100] = 0;
    puVar4[0x124] = 0xffffffff;
    puVar4[0x88] = 0;
    puVar4[4] = 1;
    do {
    } while (puVar4[0x88] == 0);
    puVar4[0x88] = 0;
    FUN_0e07a7a8(uVar14,uVar1,uVar9,puVar4[0x88]);
    puVar4[0x140] = uVar14;
    puVar4[0x100] = puVar4[0x100] | 0x80001;
    FUN_0e07a5e0((int)cVar2);
    puVar6 = DAT_0e07ace8;
    puVar4 = DAT_0e07ace4;
    if (uVar14 == 0xf) {
      if (uVar13 - 0xb < 0x10) {
        uVar13 = uVar13 * 5 - 0x32;
      }
      else {
        uVar13 = 5;
      }
    }
    DAT_0e07ace4[0x1c2] = uVar13;
    uVar9 = DAT_0e07acf4;
    iVar10 = (uint)*puVar6 * (uint)*(byte *)(DAT_0e07acec + uVar14);
    *DAT_0e07acf0 = 0;
    FUN_0e0977b0(uVar9);
    FUN_0e07a828(0);
    iVar15 = DAT_0e07acf8;
    *(undefined4 *)(DAT_0e07acf8 + 0x200) = 0;
    uVar9 = DAT_0e07acf4;
    *(undefined4 *)(iVar15 + 0x308) = 0xffffffff;
    uVar9 = FUN_0e097810(uVar9,(iVar10 * (100 - uVar12)) / uVar12 + iVar10);
    FUN_0e0976c0(DAT_0e07acf4,1,uVar9,2,0);
    if (iVar11 != 0) {
      puVar4[0x122] = 0x40;
    }
    pbVar7 = DAT_0e07ad00;
    uVar9 = 0;
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      uVar9 = getBasePriority();
    }
    bVar3 = (bool)isCurrentModePrivileged();
    if ((bVar3) && (uVar13 = getBasePriority(), uVar13 == 0 || 0x20 < uVar13)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    *DAT_0e07acfc = 1;
    iVar11 = FUN_0e092abc(*pbVar7);
    if (iVar11 != 0) {
      FUN_0e092b3c(1 << *pbVar7);
    }
    FUN_0e07a4d8();
    FUN_0e092750(*pbVar7,DAT_0e07ad04,DAT_0e07ace4);
    *DAT_0e07ad08 = *DAT_0e07ad08 | 0x100;
    FUN_0e092b18(1 << (uint)*pbVar7);
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      setBasePriority(uVar9);
    }
    InstructionSynchronizationBarrier(0xf);
  default:
    return;
  }
  *DAT_0e07a5d8 = uVar1;
  FUN_0e0977b0(uVar9);
  iVar11 = DAT_0e07a5dc;
  *(undefined4 *)(DAT_0e07a5dc + 0x200) = 0;
  *(undefined4 *)(iVar11 + 0x308) = 0xffffffff;
  uVar8 = FUN_0e097758(uVar9,uVar8);
  FUN_0e0976c0(uVar9,0,uVar8,0x10001,1);
                    /* WARNING: Could not recover jumptable at 0x0e0977b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0e0977bc)(uVar9);
  return;
}


