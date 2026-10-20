/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08f950. Types and names are inferred; NOT original source. */

void FUN_0e08f950(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  char cVar8;
  undefined4 *puVar9;
  uint *puVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  code *pcVar15;
  int iVar16;
  byte bVar17;
  undefined4 *puVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  bool bVar22;
  ulonglong uVar23;
  
  do {
    iVar21 = *(int *)(param_1 + 4);
    iVar20 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
    iVar12 = *(int *)(iVar21 + 0x10);
    iVar19 = iVar20 + 0x90;
    uVar23 = FUN_0e096d74(iVar19,0xffffffff,0,iVar12,0xffffffff,0xffffffff);
    iVar4 = (int)uVar23;
    FUN_0e094d84(*(int *)(param_1 + 0x10) + 0x84,(int)(uVar23 >> 0x20),0xffffffff,0xffffffff);
    if (iVar4 << 0x1e < 0) {
      FUN_0e096d6c(iVar19,2);
      if ((*(byte *)(iVar20 + 0x362) & 0x10) == 0) {
        uVar5 = FUN_0e096d74(iVar20 + 0x9c,0xffffffff,*(byte *)(iVar20 + 0x362) & 0x10,0,0,0);
        FUN_0e096d6c(iVar20 + 0x9c,uVar5);
      }
      else {
        uVar5 = 0;
      }
      while (uVar5 != 0) {
        bVar1 = (byte)uVar5;
        bVar2 = (byte)(uVar5 >> 8);
        bVar3 = (byte)(uVar5 >> 0x10);
        bVar17 = (byte)(uVar5 >> 0x18);
        uVar13 = LZCOUNT((uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1
                                          ) << 1 | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 |
                                       bVar1 >> 5 & 1) << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7) <<
                         0x18 | (uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 |
                                                 bVar2 >> 2 & 1) << 1 | bVar2 >> 3 & 1) << 1 |
                                               bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) << 1 |
                                             bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x10 |
                         (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1
                                          ) << 1 | bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 |
                                       bVar3 >> 5 & 1) << 1 | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) <<
                         8 | (uint)(byte)((((((((bVar17 & 1) << 1 | bVar17 >> 1 & 1) << 1 |
                                              bVar17 >> 2 & 1) << 1 | bVar17 >> 3 & 1) << 1 |
                                            bVar17 >> 4 & 1) << 1 | bVar17 >> 5 & 1) << 1 |
                                          bVar17 >> 6 & 1) << 1 | bVar17 >> 7));
        if (uVar13 < 0x10) {
          uVar7 = uVar13 | 0x80;
        }
        else {
          uVar7 = uVar13 - 0x10 & 0xff;
        }
        uVar5 = uVar5 & ~(1 << uVar13);
        iVar14 = FUN_0e08d27c(param_1,uVar7);
        iVar16 = FUN_0e08d290(param_1,*(undefined1 *)(iVar14 + 0x18));
        if (iVar16 == 0) {
          FUN_0e08e350(param_1,iVar14);
        }
      }
    }
    if (iVar4 << 0x1c < 0) {
      FUN_0e096d6c(iVar19,8);
      if ((*(byte *)(iVar20 + 0x362) & 0x10) == 0) {
        uVar5 = FUN_0e096d74(iVar20 + 0xa8,0xffffffff,*(byte *)(iVar20 + 0x362) & 0x10,0,0,0);
        FUN_0e096d6c(iVar20 + 0xa8,uVar5);
      }
      else {
        uVar5 = 0;
      }
LAB_0e08fb84:
      if (uVar5 != 0) {
        do {
          bVar1 = (byte)uVar5;
          bVar2 = (byte)(uVar5 >> 8);
          bVar3 = (byte)(uVar5 >> 0x10);
          bVar17 = (byte)(uVar5 >> 0x18);
          uVar13 = LZCOUNT((uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 |
                                            bVar1 >> 2 & 1) << 1 | bVar1 >> 3 & 1) << 1 |
                                          bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) << 1 |
                                        bVar1 >> 6 & 1) << 1 | bVar1 >> 7) << 0x18 |
                           (uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 |
                                            bVar2 >> 2 & 1) << 1 | bVar2 >> 3 & 1) << 1 |
                                          bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) << 1 |
                                        bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x10 |
                           (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 |
                                            bVar3 >> 2 & 1) << 1 | bVar3 >> 3 & 1) << 1 |
                                          bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 |
                                        bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 8 |
                           (uint)(byte)((((((((bVar17 & 1) << 1 | bVar17 >> 1 & 1) << 1 |
                                            bVar17 >> 2 & 1) << 1 | bVar17 >> 3 & 1) << 1 |
                                          bVar17 >> 4 & 1) << 1 | bVar17 >> 5 & 1) << 1 |
                                        bVar17 >> 6 & 1) << 1 | bVar17 >> 7));
          uVar5 = uVar5 & ~(1 << uVar13);
          if (uVar13 < 0x10) {
            iVar14 = FUN_0e08d27c(param_1,uVar13 | 0x80);
            iVar16 = FUN_0e08d358(param_1,*(undefined1 *)(iVar14 + 0x18));
            if (iVar16 == 0) {
              FUN_0e08d398(param_1,7,0xffffff97);
            }
            else if (*(short *)(iVar16 + 0x10) == 0) {
              cVar8 = *(char *)(iVar14 + 0x18);
              if (cVar8 == -0x80) {
                iVar11 = FUN_0e08d384();
                if (iVar11 != 0) {
                  FUN_0e08d38c(iVar16);
                  goto LAB_0e08fc66;
                }
                cVar8 = *(char *)(iVar14 + 0x18);
              }
              iVar16 = FUN_0e08d2f4(param_1,cVar8);
              FUN_0e08d2a8(param_1,*(undefined1 *)(iVar14 + 0x18),0);
              if (*(char *)(iVar14 + 0x18) != -0x80) goto LAB_0e08fbe0;
              iVar11 = FUN_0e08db54(param_1);
              if ((iVar11 != 0) || (iVar11 = FUN_0e08db68(param_1), iVar11 != 0)) {
                FUN_0e08dad0(param_1,iVar16);
              }
              FUN_0e08db7c(param_1,iVar16);
              iVar11 = FUN_0e08db40(param_1);
              if (iVar11 != 0) {
                FUN_0e08df14(param_1,8);
                FUN_0e08a7fc(iVar16);
              }
            }
            else {
LAB_0e08fc66:
              FUN_0e08e18c(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x10),iVar14,
                           iVar16);
            }
          }
          else {
            iVar14 = FUN_0e08d27c(param_1,uVar13 - 0x10 & 0xff);
            iVar16 = FUN_0e08d2f4(param_1,*(undefined1 *)(iVar14 + 0x18));
            if (iVar16 != 0) {
              FUN_0e08d2a8(param_1,*(undefined1 *)(iVar14 + 0x18),0);
              if (*(char *)(iVar14 + 0x18) == '\0') {
                iVar11 = FUN_0e08db40(param_1);
                if (iVar11 != 0) {
                  FUN_0e08dad0(param_1,iVar16);
                }
                FUN_0e08db7c(param_1,iVar16);
                iVar11 = FUN_0e08db54(param_1);
                if (iVar11 != 0) {
                  FUN_0e08d980(param_1,iVar16);
                }
              }
              else {
LAB_0e08fbe0:
                FUN_0e08d3b8(param_1,iVar16,0);
              }
            }
          }
          iVar16 = FUN_0e08d290(param_1,*(undefined1 *)(iVar14 + 0x18));
          if (iVar16 != 0) goto LAB_0e08fb84;
          FUN_0e08e350(param_1,iVar14);
          if (uVar5 == 0) break;
        } while( true );
      }
    }
    if (iVar4 << 0x1d < 0) {
      FUN_0e096d6c(iVar19,4);
      iVar16 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
      FUN_0e096d6c(iVar16 + 0xa8,0x10001);
      iVar14 = FUN_0e08d310(param_1,0);
      if (iVar14 != 0) {
        FUN_0e08a7fc();
      }
      iVar14 = FUN_0e08d310(param_1,0x80);
      if (iVar14 != 0) {
        uVar6 = FUN_0e08d27c(param_1,0x80);
        FUN_0e08e3a8(param_1,uVar6,0);
        FUN_0e08a7fc(iVar14);
      }
      FUN_0e08d2a8(param_1,0);
      FUN_0e08d2a8(param_1,0x80,0);
      iVar14 = thunk_FUN_0e08d784(param_1,0,8);
      if (iVar14 != 0) {
        FUN_0e08a8c0(iVar14 + 0xc,iVar16 + 0x367,8);
        FUN_0e08d374(iVar14);
        FUN_0e08db7c(param_1,iVar14);
        iVar16 = FUN_0e08db18(param_1);
        if (iVar16 == 0) {
          iVar14 = FUN_0e08db2c(param_1);
          if (iVar14 == 0) {
            FUN_0e08da68(param_1);
          }
          else {
            FUN_0e08d9f4(param_1);
          }
        }
        else {
          iVar16 = FUN_0e08df14(param_1,*(undefined2 *)(*(int *)(iVar14 + 0xc) + 6));
          if (iVar16 == -0xc) {
            FUN_0e08d3b8(param_1,iVar14,0xfffffff4);
          }
        }
      }
    }
    if (iVar4 << 0x1b < 0) {
      FUN_0e096d6c(iVar19,0x30);
      bVar17 = *(byte *)(iVar20 + 0x362) & 0x10;
      if ((*(byte *)(iVar20 + 0x362) & 0x10) == 0) {
        *(uint *)(iVar12 + 0x804) = *(uint *)(iVar12 + 0x804) | 1;
        FUN_0e08d24c(param_1,bVar17);
        FUN_0e08d398(param_1,2,bVar17);
        FUN_0e09628c(0x3f,0);
        *(uint *)(iVar12 + 0x804) = *(uint *)(iVar12 + 0x804) & 0xfffffffe;
      }
      else {
        (**(code **)(iVar21 + 0x24))(param_1);
        FUN_0e08f778(param_1,1,0);
        (**(code **)(iVar21 + 0x20))(param_1);
      }
    }
    if (iVar4 << 0x1a < 0) {
      (**(code **)(iVar21 + 0x24))(param_1);
      iVar12 = FUN_0e096d6c(iVar19,0x20);
      if (iVar12 << 0x1a < 0) {
        puVar18 = *(undefined4 **)(*(int *)(param_1 + 4) + 0x10);
        iVar12 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
        bVar17 = *(byte *)(iVar12 + 0x365);
        *(undefined4 *)(iVar12 + 0xb4) = *puVar18;
        *(undefined4 *)(iVar12 + 0xb8) = puVar18[2];
        *(undefined4 *)(iVar12 + 0xbc) = puVar18[3];
        *(undefined4 *)(iVar12 + 0xc0) = puVar18[6];
        *(undefined4 *)(iVar12 + 0xc4) = puVar18[9];
        *(undefined4 *)(iVar12 + 200) = puVar18[10];
        *(undefined4 *)(iVar12 + 0xcc) = puVar18[0xc];
        *(undefined4 *)(iVar12 + 0xd0) = puVar18[0x15];
        *(undefined4 *)(iVar12 + 0xd4) = puVar18[0x17];
        if (1 < bVar17) {
          uVar5 = 0;
          puVar9 = (undefined4 *)(iVar12 + 0xd4);
          do {
            iVar14 = uVar5 + 0x41;
            uVar5 = uVar5 + 1;
            puVar9 = puVar9 + 1;
            *puVar9 = puVar18[iVar14];
          } while (uVar5 != (byte)(bVar17 - 1));
        }
        *(undefined4 *)(iVar12 + 0x114) = puVar18[0x200];
        *(undefined4 *)(iVar12 + 0x118) = puVar18[0x201];
        uVar5 = *(uint *)(iVar12 + 0x2ac);
        *(undefined4 *)(iVar12 + 0x11c) = puVar18[0x204];
        puVar10 = (uint *)(iVar12 + 0x128);
        *(undefined4 *)(iVar12 + 0x120) = puVar18[0x205];
        *(undefined4 *)(iVar12 + 0x124) = puVar18[0x207];
        iVar14 = 0;
        do {
          while (uVar13 = (3 << (iVar14 << 1 & 0xffU) & uVar5) >> (iVar14 << 1 & 0xffU), 1 < uVar13)
          {
            if (uVar13 != 2) goto LAB_0e08fd5c;
LAB_0e08fda4:
            uVar13 = puVar18[(iVar14 + 0x58) * 8];
            bVar22 = (int)(uVar13 << 0xf) < 0;
            if (bVar22) {
              uVar13 = uVar13 | 0x20000000;
            }
            iVar16 = iVar12 + iVar14 * 4;
            if (!bVar22) {
              uVar13 = uVar13 | 0x10000000;
            }
            *(uint *)(iVar16 + 0x1e8) = uVar13;
            iVar11 = iVar14 + 1;
            *(undefined4 *)(iVar16 + 0x228) = puVar18[iVar14 * 8 + 0x2c4];
            *(undefined4 *)(iVar16 + 0x268) = puVar18[iVar14 * 8 + 0x2c5];
            puVar10 = puVar10 + 1;
            iVar14 = iVar11;
            if (iVar11 == 0x10) goto LAB_0e08fdde;
          }
          uVar7 = puVar18[(iVar14 + 0x48) * 8];
          if ((int)(uVar7 << 0xf) < 0) {
            uVar7 = uVar7 | 0x20000000;
          }
          else {
            uVar7 = uVar7 | 0x10000000;
          }
          *puVar10 = uVar7;
          puVar10[0x10] = puVar18[iVar14 * 8 + 0x244];
          puVar10[0x20] = puVar18[iVar14 * 8 + 0x245];
          if (uVar13 == 0) goto LAB_0e08fda4;
LAB_0e08fd5c:
          iVar14 = iVar14 + 1;
          puVar10 = puVar10 + 1;
        } while (iVar14 != 0x10);
LAB_0e08fdde:
        *(undefined4 *)(iVar12 + 0x2a8) = puVar18[0x380];
        puVar18[0x16] = puVar18[0x16] | 2;
        FUN_0e09467c(1);
        puVar18[0x380] = puVar18[0x380] | 1;
        FUN_0e09467c(1);
        puVar18[0x16] = puVar18[0x16] | 1;
        FUN_0e09467c(1);
        puVar18[0x16] = puVar18[0x16] | 0x41500;
        FUN_0e09467c(1);
        puVar18[0x16] = puVar18[0x16] | 8;
        FUN_0e09467c(1);
        puVar18[0x16] = puVar18[0x16] | 0x20;
        iVar14 = *(int *)(*(int *)(param_1 + 4) + 0x18);
        if ((iVar14 != 0) && (pcVar15 = *(code **)(iVar14 + 0x20), pcVar15 != (code *)0x0)) {
          (*pcVar15)();
        }
        *(byte *)(iVar12 + 0x362) = *(byte *)(iVar12 + 0x362) | 0x10;
      }
      (**(code **)(iVar21 + 0x20))(param_1);
    }
    if ((uVar23 & 0xc0) != 0) {
      (**(code **)(iVar21 + 0x24))(param_1);
      uVar5 = FUN_0e096d6c(iVar19,0xc0);
      if ((int)((uint)*(byte *)(iVar20 + 0x362) << 0x1b) < 0) {
        FUN_0e08f778(param_1,0,(uVar5 & 0x7f) >> 6);
      }
      (**(code **)(iVar21 + 0x20))(param_1);
    }
    if (iVar4 << 0x1f < 0) {
      FUN_0e096d6c(iVar19,1);
    }
    FUN_0e094e80(*(int *)(param_1 + 0x10) + 0x84);
  } while( true );
}


