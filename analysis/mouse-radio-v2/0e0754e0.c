/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0754e0. Types and names are inferred; NOT original source. */

void FUN_0e0754e0(int param_1,int param_2)

{
  code *pcVar1;
  byte bVar2;
  ushort uVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  uint uVar14;
  int *piVar15;
  byte *pbVar16;
  uint uVar17;
  byte *pbVar18;
  uint uVar20;
  int local_40 [7];
  byte *pbVar19;
  
  uVar17 = *(uint *)(param_2 + 0x90);
  uVar8 = *(uint *)(param_1 + 0x354);
  if (uVar17 == 0) {
    if (*(int *)(param_1 + 0x154) == 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x154) = 0;
    uVar14 = 0;
  }
  else {
    uVar14 = 0;
    uVar9 = 0;
    do {
      uVar10 = 1 << (uVar9 & 0xff);
      iVar11 = (uVar9 & 0xff) * 4 + 0x100;
      if ((((uVar8 & 0xff | 0x200000) & uVar10) != 0) && (*(int *)(param_1 + iVar11) != 0)) {
        *(undefined4 *)(param_1 + iVar11) = 0;
        uVar14 = uVar14 | uVar10;
      }
      uVar9 = uVar9 + 1;
    } while (uVar17 != uVar9);
    if (*(int *)(param_1 + 0x154) == 0) {
      if (-1 < (int)(uVar14 << 10)) goto joined_r0x0e075538;
    }
    else {
      *(undefined4 *)(param_1 + 0x154) = 0;
    }
  }
  local_40[0] = 0;
  local_40[1] = 0;
  local_40[2] = 0;
  local_40[3] = 0;
  local_40[4] = 0;
  local_40[5] = 0;
  FUN_0e075764(local_40,*(undefined4 *)(param_2 + 0x9c));
  do {
    piVar15 = local_40;
    pbVar16 = DAT_0e075754;
    pbVar19 = DAT_0e075750;
    do {
      while( true ) {
        pbVar18 = pbVar19 + 1;
        bVar2 = *(byte *)(param_2 + 0x9c + (uint)(*pbVar19 >> 3));
        uVar8 = (uint)bVar2;
        if ((int)((uint)(bVar2 >> (*pbVar19 & 7)) << 0x1f) < 0) break;
LAB_0e0755aa:
        piVar15 = piVar15 + 1;
        pbVar16 = pbVar16 + 1;
        pbVar19 = pbVar18;
        if (pbVar18 == DAT_0e075758) goto LAB_0e07568a;
      }
      iVar11 = *piVar15;
      uVar8 = 0;
      if (iVar11 == 0) goto LAB_0e0755aa;
      bVar2 = *pbVar16;
      do {
        bVar5 = (byte)iVar11;
        bVar6 = (byte)((uint)iVar11 >> 8);
        bVar7 = (byte)((uint)iVar11 >> 0x10);
        bVar4 = (byte)((uint)iVar11 >> 0x18);
        uVar9 = LZCOUNT((uint)(byte)((((((((bVar5 & 1) << 1 | bVar5 >> 1 & 1) << 1 | bVar5 >> 2 & 1)
                                         << 1 | bVar5 >> 3 & 1) << 1 | bVar5 >> 4 & 1) << 1 |
                                      bVar5 >> 5 & 1) << 1 | bVar5 >> 6 & 1) << 1 | bVar5 >> 7) <<
                        0x18 | (uint)(byte)((((((((bVar6 & 1) << 1 | bVar6 >> 1 & 1) << 1 |
                                                bVar6 >> 2 & 1) << 1 | bVar6 >> 3 & 1) << 1 |
                                              bVar6 >> 4 & 1) << 1 | bVar6 >> 5 & 1) << 1 |
                                            bVar6 >> 6 & 1) << 1 | bVar6 >> 7) << 0x10 |
                        (uint)(byte)((((((((bVar7 & 1) << 1 | bVar7 >> 1 & 1) << 1 | bVar7 >> 2 & 1)
                                         << 1 | bVar7 >> 3 & 1) << 1 | bVar7 >> 4 & 1) << 1 |
                                      bVar7 >> 5 & 1) << 1 | bVar7 >> 6 & 1) << 1 | bVar7 >> 7) << 8
                        | (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 |
                                           bVar4 >> 2 & 1) << 1 | bVar4 >> 3 & 1) << 1 |
                                         bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1 |
                                       bVar4 >> 6 & 1) << 1 | bVar4 >> 7));
        uVar17 = uVar9 | (uint)bVar2 << 5;
        uVar10 = uVar17 >> 5;
        uVar8 = uVar9 & 0x1f;
        uVar3 = *(ushort *)(param_2 + ((*(byte *)(DAT_0e07575c + uVar10) + uVar8 & 0xff) + 8) * 2);
        *(byte *)((int)piVar15 + (uVar9 >> 3)) =
             *(byte *)((int)piVar15 + (uVar9 >> 3)) & ~(byte)(1 << (uVar9 & 7));
        if (9 < uVar10) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)software_udf(0xff,0xe0756de);
          (*pcVar1)();
        }
        uVar20 = (uVar3 & 0x1f) >> 2;
        iVar12 = *(int *)(DAT_0e075760 + uVar10 * 4);
        iVar11 = iVar12 + uVar8 * 4;
        uVar9 = (*(uint *)(iVar11 + 0x80) & 0x3ffff) >> 0x10;
        if ((uVar3 & 0x10) == 0) {
          if (uVar9 == 2) {
            *(uint *)(iVar11 + 0x80) = *(uint *)(iVar11 + 0x80) | 0x30000;
            if ((uVar20 & 5) == 1) goto LAB_0e0756f4;
          }
          else {
            *(uint *)(iVar11 + 0x80) = *(uint *)(iVar11 + 0x80) & 0xfffcffff | 0x20000;
            if ((uVar20 == 3) || ((uVar9 == 3 && (uVar20 == 2)))) {
LAB_0e0756f4:
              FUN_0e075490(param_2,uVar17,uVar20);
            }
          }
        }
        else {
          FUN_0e075490(param_2,uVar17,uVar20);
          if (uVar9 == (*(uint *)(iVar11 + 0x80) & 0x3ffff) >> 0x10) {
            *(uint *)(iVar11 + 0x80) = *(uint *)(iVar11 + 0x80) & 0xfffcffff;
            *(uint *)(iVar11 + 0x80) = *(uint *)(iVar11 + 0x80) & 0xfffcffff | uVar9 << 0x10;
          }
        }
        iVar11 = *piVar15;
        *(int *)(iVar12 + 0x20) = 1 << uVar8;
      } while (iVar11 != 0);
      piVar15 = piVar15 + 1;
      pbVar16 = pbVar16 + 1;
      uVar8 = 0;
      pbVar19 = pbVar18;
    } while (pbVar18 != DAT_0e075758);
LAB_0e07568a:
    uVar17 = *(uint *)(param_2 + 0x90);
    if (uVar17 != 0) {
      uVar8 = 0;
      do {
        if (((uVar8 & 0xff) == 0x15) && (*(int *)(param_1 + 0x154) != 0)) {
          *(undefined4 *)(param_1 + 0x154) = 0;
        }
        uVar8 = uVar8 + 1;
      } while (uVar17 != uVar8);
    }
    uVar13 = 0;
    if (*(int *)(param_1 + 0x154) != 0) {
      *(undefined4 *)(param_1 + 0x154) = 0;
      uVar13 = *(undefined4 *)(param_1 + 0x154);
    }
    iVar11 = FUN_0e075764(local_40,*(undefined4 *)(param_2 + 0x9c),uVar8,uVar13);
  } while (iVar11 != 0);
  uVar14 = uVar14 & 0xffdfffff;
joined_r0x0e075538:
  for (; uVar14 != 0; uVar14 = uVar14 & ~(1 << iVar12)) {
    bVar4 = (byte)uVar14;
    bVar5 = (byte)(uVar14 >> 8);
    bVar6 = (byte)(uVar14 >> 0x10);
    bVar2 = (byte)(uVar14 >> 0x18);
    iVar12 = LZCOUNT((uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) <<
                                      1 | bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 |
                                   bVar4 >> 5 & 1) << 1 | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 0x18
                     | (uint)(byte)((((((((bVar5 & 1) << 1 | bVar5 >> 1 & 1) << 1 | bVar5 >> 2 & 1)
                                        << 1 | bVar5 >> 3 & 1) << 1 | bVar5 >> 4 & 1) << 1 |
                                     bVar5 >> 5 & 1) << 1 | bVar5 >> 6 & 1) << 1 | bVar5 >> 7) <<
                       0x10 | (uint)(byte)((((((((bVar6 & 1) << 1 | bVar6 >> 1 & 1) << 1 |
                                               bVar6 >> 2 & 1) << 1 | bVar6 >> 3 & 1) << 1 |
                                             bVar6 >> 4 & 1) << 1 | bVar6 >> 5 & 1) << 1 |
                                           bVar6 >> 6 & 1) << 1 | bVar6 >> 7) << 8 |
                     (uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) <<
                                      1 | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 |
                                   bVar2 >> 5 & 1) << 1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7));
    iVar11 = param_1 + iVar12 * 4;
    FUN_0e075490(param_2,(*(uint *)(iVar11 + 0x510) & 0x1fff) >> 4,
                 (*(uint *)(iVar11 + 0x510) & 0x3ffff) >> 0x10);
  }
  return;
}


