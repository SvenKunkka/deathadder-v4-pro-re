/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05ce78. Types and names are inferred; NOT original source. */

void FUN_0e05ce78(undefined1 *param_1)

{
  undefined1 uVar1;
  char cVar2;
  bool bVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  ushort *puVar6;
  byte *pbVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  
  puVar5 = DAT_0e05d100;
  puVar4 = DAT_0e05c9f0;
  switch(*param_1) {
  case 0:
    FUN_0e05ccb8(param_1[1],(int)(char)param_1[4],param_1[5]);
    return;
  case 1:
    iVar10 = *(int *)(param_1 + 8);
    uVar8 = *(undefined4 *)(param_1 + 0xc);
    uVar12 = (uint)(byte)param_1[1];
    iVar14 = (int)(char)param_1[4];
    uVar11 = (uint)(byte)param_1[6];
    uVar1 = param_1[5];
    DAT_0e05d100[0x100] = 0;
    puVar5[0x124] = 0xffffffff;
    puVar5[0x88] = 0;
    puVar5[4] = 1;
    do {
    } while (puVar5[0x88] == 0);
    puVar5[0x88] = 0;
    FUN_0e05cbc4(uVar12,uVar1,uVar8,puVar5[0x88]);
    puVar4 = DAT_0e05d100;
    if (uVar12 < 7) {
      if (4 < uVar12) {
        puVar5[0x100] = puVar5[0x100] | 0x100001;
        puVar5[0x140] = uVar12;
        FUN_0e05c9fc(iVar14);
        goto LAB_0e05d04c;
      }
    }
    else if (uVar12 == 0xf) {
      puVar5[0x100] = puVar5[0x100] | 0x100001;
      puVar5[0x140] = 0xf;
      FUN_0e05c9fc(iVar14);
      if (uVar11 - 0xb < 0x10) {
        uVar11 = uVar11 * 5 - 0x32;
      }
      else {
        uVar11 = 5;
      }
      goto LAB_0e05d04c;
    }
    DAT_0e05d100[0x100] = DAT_0e05d100[0x100] | 0x21;
    puVar4[0x140] = uVar12;
    FUN_0e05c9fc(iVar14);
LAB_0e05d04c:
    puVar5 = DAT_0e05d10c;
    puVar4 = DAT_0e05d100;
    DAT_0e05d100[0x1c2] = uVar11;
    *puVar5 = 0;
    puVar4[0x86] = 0;
    if (iVar10 != 0) {
      puVar4[0x122] = 0x40;
    }
    *DAT_0e05d100 = 1;
    return;
  case 2:
    FUN_0e05cd4c(param_1[1],param_1[0xc],param_1[4]);
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
    uVar11 = *(uint *)(param_1 + 8);
    iVar10 = *(int *)(param_1 + 0xc);
    uVar13 = (uint)(byte)param_1[1];
    cVar2 = param_1[4];
    uVar12 = (uint)(byte)param_1[6];
    uVar1 = param_1[5];
    uVar8 = *(undefined4 *)(param_1 + 0x10);
    DAT_0e05d100[0x100] = 0;
    puVar5[0x124] = 0xffffffff;
    puVar5[0x88] = 0;
    puVar5[4] = 1;
    do {
    } while (puVar5[0x88] == 0);
    puVar5[0x88] = 0;
    FUN_0e05cbc4(uVar13,uVar1,uVar8,puVar5[0x88]);
    puVar5[0x140] = uVar13;
    puVar5[0x100] = puVar5[0x100] | 0x80001;
    FUN_0e05c9fc((int)cVar2);
    puVar6 = DAT_0e05d104;
    puVar4 = DAT_0e05d100;
    if (uVar13 == 0xf) {
      if (uVar12 - 0xb < 0x10) {
        uVar12 = uVar12 * 5 - 0x32;
      }
      else {
        uVar12 = 5;
      }
    }
    DAT_0e05d100[0x1c2] = uVar12;
    uVar8 = DAT_0e05d110;
    iVar9 = (uint)*puVar6 * (uint)*(byte *)(DAT_0e05d108 + uVar13);
    *DAT_0e05d10c = 0;
    FUN_0e069ff8(uVar8);
    FUN_0e05cc44(0);
    iVar14 = DAT_0e05d114;
    *(undefined4 *)(DAT_0e05d114 + 0x200) = 0;
    uVar8 = DAT_0e05d110;
    *(undefined4 *)(iVar14 + 0x308) = 0xffffffff;
    uVar8 = FUN_0e06a020(uVar8,(iVar9 * (100 - uVar11)) / uVar11 + iVar9);
    FUN_0e06a100(DAT_0e05d110,1,uVar8,2,0);
    if (iVar10 != 0) {
      puVar4[0x122] = 0x40;
    }
    pbVar7 = DAT_0e05d11c;
    uVar8 = 0;
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      uVar8 = getBasePriority();
    }
    bVar3 = (bool)isCurrentModePrivileged();
    if ((bVar3) && (uVar12 = getBasePriority(), uVar12 == 0 || 0x40 < uVar12)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    *DAT_0e05d118 = 1;
    iVar10 = FUN_0e06ab68(*pbVar7);
    if (iVar10 != 0) {
      FUN_0e06abe8(1 << *pbVar7);
    }
    FUN_0e05c8f4();
    FUN_0e06a7fc(*pbVar7,DAT_0e05d120,DAT_0e05d100);
    *DAT_0e05d124 = *DAT_0e05d124 | 0x100;
    FUN_0e06abc4(1 << (uint)*pbVar7);
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      setBasePriority(uVar8);
    }
    InstructionSynchronizationBarrier(0xf);
  default:
    return;
  }
  *DAT_0e05c9f4 = uVar1;
  FUN_0e069ff8(puVar4);
  iVar10 = DAT_0e05c9f8;
  *(undefined4 *)(DAT_0e05c9f8 + 0x200) = 0;
  *(undefined4 *)(iVar10 + 0x308) = 0xffffffff;
  uVar8 = FUN_0e06a08c(puVar4,uVar8);
  FUN_0e06a100(puVar4,0,uVar8,0x10001,1);
  iVar10 = DAT_0e069ff4;
  *(undefined4 *)*puVar4 = 1;
  *(undefined1 *)(iVar10 + (uint)*(byte *)(puVar4 + 1) * 0xc + 8) = 2;
  return;
}


