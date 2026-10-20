/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e065570. Types and names are inferred; NOT original source. */

undefined4 FUN_0e065570(int param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  uint uVar13;
  undefined4 uVar14;
  uint uVar15;
  int iVar16;
  
  iVar9 = *(int *)(param_1 + 0x10);
  iVar16 = *(int *)(param_2 + 0xac);
  bVar1 = *(byte *)(param_3 + 0x19);
  uVar15 = (*(ushort *)(param_3 + 0x1a) & 0x1fff) >> 0xb;
  bVar7 = bVar1 & 1;
  uVar11 = (uint)*(ushort *)(param_4 + 0x10);
  uVar5 = *(byte *)(param_3 + 0x18) & 0x7f;
  uVar3 = *(ushort *)(param_3 + 0x1a) & 0x7ff;
  if ((bVar1 & 1) != 0) {
    if ((bVar1 & 3) == 1) {
      uVar6 = uVar15 * uVar3 + uVar3;
      if (uVar6 <= uVar11) {
        uVar11 = uVar6;
      }
      bVar7 = 1;
    }
    else {
      bVar7 = 1;
    }
  }
  uVar6 = (*(uint *)(iVar9 + uVar5 * 0x20 + 0x918) & 0xffff) * 4;
  uVar10 = uVar3 + 3 & 0xfffffffc;
  uVar13 = uVar6 / uVar10;
  uVar6 = uVar3 * uVar13 + (uVar6 - uVar10 * uVar13);
  if ((uVar6 < uVar11) && (uVar13 < uVar15 + 1)) {
    uVar14 = 0xfffffff5;
  }
  else {
    if (uVar11 <= uVar6) {
      uVar6 = uVar11;
    }
    if (uVar6 == 0) {
      uVar11 = 0x80000;
      uVar10 = 1;
    }
    else {
      if ((*(byte *)(param_3 + 0x18) & 0x7f) == 0) {
        uVar11 = 3;
        uVar10 = 0x7f;
      }
      else {
        uVar10 = *(uint *)(iVar16 + 0x2b4);
        uVar11 = *(uint *)(iVar16 + 0x2b8);
      }
      if (uVar10 < uVar6) {
        uVar6 = uVar15 * uVar3 + uVar3;
        uVar6 = (uVar10 / uVar6) * uVar6;
      }
      uVar10 = ((uVar3 - 1) + uVar6) / uVar3;
      if (uVar11 < uVar10) {
        uVar10 = (uVar15 + 1) * (uVar11 / (uVar15 + 1));
        uVar6 = uVar3 * uVar10;
      }
      uVar11 = (uVar10 & 0x3ff) << 0x13 | uVar6 & 0x7ffff;
    }
    *(uint *)(iVar16 + uVar5 * 4 + 700) = uVar6;
    uVar14 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar14 = getBasePriority();
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    if (bVar7 != 0) {
      uVar11 = uVar11 | (uVar15 + 1) * 0x20000000 & 0x60000000;
    }
    *(uint *)(iVar9 + uVar5 * 0x20 + 0x910) = uVar11;
    iVar8 = iVar9 + uVar5 * 0x20;
    uVar11 = *(uint *)(iVar8 + 0x900);
    if ((uVar11 & 0x8000) == 0) {
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(uVar14);
      }
      InstructionSynchronizationBarrier(0xf);
      uVar14 = 0xfffffffe;
    }
    else {
      if ((bVar1 & 3) == 1) {
        if ((*(ushort *)(iVar16 + 0x360) & 1) == 0) {
          uVar11 = uVar11 | 0x20000000;
        }
        else {
          uVar11 = uVar11 | 0x10000000;
        }
      }
      *(uint *)(iVar8 + 0x900) = uVar11 | 0x84000000;
      *(undefined4 *)(uVar5 * 0x20 + iVar9 + 0x908) = 0x40;
      pbVar12 = *(byte **)(param_4 + 0xc);
      if (uVar10 != 0) {
        do {
          uVar11 = *(ushort *)(param_3 + 0x1a) & 0x7ff;
          if (uVar6 <= uVar11) {
            uVar11 = uVar6;
          }
          if (uVar11 != 0) {
            uVar3 = 0;
            pbVar4 = pbVar12;
            do {
              uVar15 = (uint)*pbVar4;
              if (uVar3 + 1 < uVar11) {
                uVar15 = (uint)CONCAT11(pbVar4[1],*pbVar4);
              }
              if (uVar3 + 2 < uVar11) {
                uVar15 = uVar15 | (uint)pbVar4[2] << 0x10;
              }
              if (uVar3 + 3 < uVar11) {
                uVar15 = uVar15 | (uint)pbVar4[3] << 0x18;
              }
              uVar3 = uVar3 + 4;
              *(uint *)(iVar9 + (uVar5 + 1) * 0x1000) = uVar15;
              pbVar4 = pbVar4 + 4;
            } while (uVar3 < uVar11);
          }
          uVar10 = uVar10 - 1;
          pbVar12 = pbVar12 + uVar11;
          uVar6 = uVar6 - uVar11;
        } while (uVar10 != 0);
      }
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(uVar14);
      }
      InstructionSynchronizationBarrier(0xf);
      uVar14 = 0;
    }
  }
  return uVar14;
}


