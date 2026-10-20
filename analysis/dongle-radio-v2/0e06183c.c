/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06183c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06183c(void)

{
  bool bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  byte bVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int local_2c [2];
  
  uVar5 = DAT_0e0619d8;
  puVar6 = DAT_0e0619d4;
  iVar2 = DAT_0e0619d0;
  uVar12 = *DAT_0e0619d4;
  if ((*(uint *)(DAT_0e0619d0 + 0x90) & 0xffff) >> 8 < uVar12) {
    uVar5 = 0xffffffff;
  }
  else {
    DataMemoryBarrier(0x1f);
    uVar10 = 0;
    *(undefined4 *)(DAT_0e0619d0 + 0x94) = 0;
    *(undefined4 *)(iVar2 + 0xc0) = uVar5;
    bVar11 = 0;
    if (uVar12 != 0) {
      puVar6 = (uint *)puVar6[1];
      do {
        uVar8 = puVar6[2];
        uVar9 = puVar6[3];
        uVar7 = *puVar6;
        *(uint *)(iVar2 + 0x98) = uVar10;
        uVar10 = uVar10 + 1;
        *(uint *)(iVar2 + 0x9c) = uVar7 & 0xffffffe0 | (byte)uVar8 & 0x1f;
        puVar6 = puVar6 + 4;
        *(uint *)(iVar2 + 0xa0) = uVar9 & 0xffffffe0 | (uint)(byte)((byte)uVar8 >> 5) << 1 | 1;
      } while (uVar12 != uVar10);
      bVar11 = (byte)uVar12;
    }
    pbVar3 = DAT_0e0619dc;
    *DAT_0e0619dc = bVar11;
    iVar4 = FUN_0e05fe84(local_2c);
    uVar12 = DAT_0e0619e0;
    iVar2 = DAT_0e0619d0;
    if (iVar4 == 0) {
      uVar10 = (uint)*pbVar3;
    }
    else {
      bVar1 = false;
      uVar10 = (uint)*pbVar3;
      iVar15 = 0;
      uVar8 = uVar10;
LAB_0e0618d4:
      do {
        uVar7 = *(uint *)(local_2c[0] + 0xc) & uVar12;
        if (uVar7 == 0x200000) {
          iVar13 = 2;
          uVar9 = *(uint *)(local_2c[0] + 4) & 0xffffffe0;
          uVar14 = 1;
          uVar7 = *(int *)(local_2c[0] + 8) + -1 + uVar9 & 0xffffffe0;
        }
        else if (uVar7 == 0x400000) {
          iVar13 = 0;
          uVar14 = 2;
          uVar9 = *(uint *)(local_2c[0] + 4) & 0xffffffe0;
          uVar7 = *(int *)(local_2c[0] + 8) + -1 + uVar9 & 0xffffffe0;
        }
        else {
          if (uVar7 != 0x100000) {
            iVar15 = iVar15 + 1;
            local_2c[0] = local_2c[0] + 0x10;
            if (iVar4 == iVar15) break;
            goto LAB_0e0618d4;
          }
          iVar13 = 1;
          uVar14 = 1;
          uVar9 = *(uint *)(local_2c[0] + 4) & 0xffffffe0;
          uVar7 = *(int *)(local_2c[0] + 8) + -1 + uVar9 & 0xffffffe0;
        }
        if (((*(uint *)(iVar2 + 0x90) & 0xffff) >> 8) - 1 < uVar8) {
          if (bVar1) {
            *pbVar3 = (byte)uVar8;
          }
          return 0xffffffea;
        }
        bVar1 = true;
        iVar15 = iVar15 + 1;
        *(uint *)(iVar2 + 0x98) = uVar8;
        local_2c[0] = local_2c[0] + 0x10;
        *(uint *)(iVar2 + 0x9c) = uVar9 | uVar14;
        uVar8 = uVar8 + 1 & 0xff;
        *(uint *)(iVar2 + 0xa0) = uVar7 | iVar13 << 1 | 1;
      } while (iVar4 != iVar15);
      if (bVar1) {
        *pbVar3 = (byte)uVar8;
        uVar10 = uVar8;
      }
    }
    iVar2 = DAT_0e0619d0;
    if (uVar10 < (*(uint *)(DAT_0e0619d0 + 0x90) & 0xffff) >> 8) {
      do {
        *(uint *)(iVar2 + 0x98) = uVar10;
        *(undefined4 *)(iVar2 + 0xa0) = 0;
        uVar10 = uVar10 + 1;
      } while ((int)uVar10 < (int)((*(uint *)(iVar2 + 0x90) & 0xffff) >> 8));
    }
    *(undefined4 *)(DAT_0e0619d0 + 0x94) = 5;
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
    uVar5 = 0;
  }
  return uVar5;
}


