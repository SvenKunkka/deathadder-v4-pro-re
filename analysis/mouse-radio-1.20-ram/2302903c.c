/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302903c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_2302903c(void)

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
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int *piVar15;
  byte *pbVar16;
  byte *pbVar17;
  uint uVar19;
  int local_40 [7];
  byte *pbVar18;
  
  uVar11 = DAT_23001440;
  if (DAT_23001440 == 0) {
    if (_DAT_5f934154 == 0) {
      return;
    }
    uVar14 = 0;
    _DAT_5f934154 = DAT_23001440;
  }
  else {
    uVar14 = 0;
    uVar9 = 0;
    uVar8 = _DAT_5f934354 & 0xff;
    do {
      iVar12 = (uVar9 & 0xff) * 4;
      uVar10 = 1 << (uVar9 & 0xff);
      if ((((uVar8 | 0x200000) & uVar10) != 0) && (*(int *)(iVar12 + 0x5f934100) != 0)) {
        *(undefined4 *)(iVar12 + 0x5f934100) = 0;
        uVar14 = uVar14 | uVar10;
      }
      uVar9 = uVar9 + 1;
    } while (uVar11 != uVar9);
    if (_DAT_5f934154 == 0) {
      if (-1 < (int)(uVar14 << 10)) goto joined_r0x23028d98;
    }
    else {
      _DAT_5f934154 = 0;
    }
  }
  local_40[0] = 0;
  local_40[1] = 0;
  local_40[2] = 0;
  local_40[3] = 0;
  local_40[4] = 0;
  local_40[5] = 0;
  FUN_23028fc4(local_40,DAT_2300144c);
  do {
    pbVar16 = &DAT_0e09b6c0;
    piVar15 = local_40;
    pbVar18 = &DAT_0e09b6c0;
    do {
      while( true ) {
        pbVar17 = pbVar18 + 1;
        bVar2 = *(byte *)((int)&DAT_2300144c + (uint)(*pbVar18 >> 3));
        uVar11 = (uint)bVar2;
        if ((int)((uint)(bVar2 >> (*pbVar18 & 7)) << 0x1f) < 0) break;
LAB_23028e0a:
        piVar15 = piVar15 + 1;
        pbVar16 = pbVar16 + 1;
        pbVar18 = pbVar17;
        if (pbVar17 == &DAT_0e09b6c6) goto LAB_23028eea;
      }
      iVar12 = *piVar15;
      uVar11 = 0;
      if (iVar12 == 0) goto LAB_23028e0a;
      bVar2 = *pbVar16;
      do {
        bVar5 = (byte)iVar12;
        bVar6 = (byte)((uint)iVar12 >> 8);
        bVar7 = (byte)((uint)iVar12 >> 0x10);
        bVar4 = (byte)((uint)iVar12 >> 0x18);
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
        uVar8 = uVar9 | (uint)bVar2 << 5;
        uVar10 = uVar8 >> 5;
        uVar11 = uVar9 & 0x1f;
        uVar3 = *(ushort *)
                 (&DAT_230013b0 + (((byte)(&DAT_0e09b6b0)[uVar10] + uVar11 & 0xff) + 8) * 2);
        *(byte *)((int)piVar15 + (uVar9 >> 3)) =
             *(byte *)((int)piVar15 + (uVar9 >> 3)) & ~(byte)(1 << (uVar9 & 7));
        if (9 < uVar10) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)software_udf(0xff,0x23028f3e);
          (*pcVar1)();
        }
        uVar19 = (uVar3 & 0x1f) >> 2;
        iVar13 = *(int *)(&DAT_0e09b688 + uVar10 * 4);
        iVar12 = iVar13 + uVar11 * 4;
        uVar9 = (*(uint *)(iVar12 + 0x80) & 0x3ffff) >> 0x10;
        if ((uVar3 & 0x10) == 0) {
          if (uVar9 == 2) {
            *(uint *)(iVar12 + 0x80) = *(uint *)(iVar12 + 0x80) | 0x30000;
            if ((uVar19 & 5) == 1) goto LAB_23028f54;
          }
          else {
            *(uint *)(iVar12 + 0x80) = *(uint *)(iVar12 + 0x80) & 0xfffcffff | 0x20000;
            if ((uVar19 == 3) || ((uVar9 == 3 && (uVar19 == 2)))) {
LAB_23028f54:
              FUN_23028cf0(&DAT_230013b0,uVar8,uVar19);
            }
          }
        }
        else {
          FUN_23028cf0(&DAT_230013b0,uVar8,uVar19);
          if (uVar9 == (*(uint *)(iVar12 + 0x80) & 0x3ffff) >> 0x10) {
            *(uint *)(iVar12 + 0x80) = *(uint *)(iVar12 + 0x80) & 0xfffcffff;
            *(uint *)(iVar12 + 0x80) = *(uint *)(iVar12 + 0x80) & 0xfffcffff | uVar9 << 0x10;
          }
        }
        iVar12 = *piVar15;
        *(int *)(iVar13 + 0x20) = 1 << uVar11;
      } while (iVar12 != 0);
      piVar15 = piVar15 + 1;
      pbVar16 = pbVar16 + 1;
      uVar11 = 0;
      pbVar18 = pbVar17;
    } while (pbVar17 != &DAT_0e09b6c6);
LAB_23028eea:
    if (DAT_23001440 != 0) {
      uVar11 = 0;
      do {
        if (((uVar11 & 0xff) == 0x15) && (_DAT_5f934154 != 0)) {
          _DAT_5f934154 = 0;
        }
        uVar11 = uVar11 + 1;
      } while (DAT_23001440 != uVar11);
    }
    if (_DAT_5f934154 != 0) {
      _DAT_5f934154 = 0;
    }
    iVar12 = FUN_23028fc4(local_40,DAT_2300144c,uVar11,0);
  } while (iVar12 != 0);
  uVar14 = uVar14 & 0xffdfffff;
joined_r0x23028d98:
  for (; uVar14 != 0; uVar14 = uVar14 & ~(1 << iVar13)) {
    bVar4 = (byte)uVar14;
    bVar5 = (byte)(uVar14 >> 8);
    bVar6 = (byte)(uVar14 >> 0x10);
    bVar2 = (byte)(uVar14 >> 0x18);
    iVar13 = LZCOUNT((uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) <<
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
    iVar12 = iVar13 * 4;
    FUN_23028cf0(&DAT_230013b0,(*(uint *)(iVar12 + 0x5f934510) & 0x1fff) >> 4,
                 (*(uint *)(iVar12 + 0x5f934510) & 0x3ffff) >> 0x10);
  }
  return;
}


