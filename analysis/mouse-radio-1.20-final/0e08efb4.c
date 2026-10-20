/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08efb4. Types and names are inferred; NOT original source. */

void FUN_0e08efb4(int param_1)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  code *UNRECOVERED_JUMPTABLE;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  undefined4 *puVar20;
  undefined4 local_2c [2];
  undefined4 *puVar21;
  
  iVar8 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
  iVar12 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((int)((uint)*(byte *)(iVar8 + 0x362) << 0x1b) < 0) {
    uVar11 = *(uint *)(iVar12 + 0x58);
    *(uint *)(iVar12 + 0x58) = uVar11;
    if (((int)(uVar11 << 0x18) < 0) && ((uVar11 & 0x1fffff) >> 0x13 == 2)) {
      FUN_0e096c30(iVar8 + 0x90,0x80);
    }
    if ((uVar11 & 0x200) != 0) {
      FUN_0e096c30(iVar8 + 0x90,0x40);
    }
  }
  else {
    uVar11 = *(uint *)(iVar12 + 0x18);
LAB_0e08efe0:
    uVar14 = *(uint *)(iVar12 + 0x14) & uVar11;
    if (uVar14 != 0) {
      do {
        if ((int)(uVar14 << 0x1c) < 0) {
          *(undefined4 *)(iVar12 + 0x14) = 8;
          *(ushort *)(iVar8 + 0x360) = (ushort)((uint)(*(int *)(iVar12 + 0x808) << 10) >> 0x12);
          FUN_0e08d270(param_1,5,0);
        }
        if ((int)(uVar14 << 0x13) < 0) {
          *(undefined4 *)(iVar12 + 0x14) = 0x1000;
          FUN_0e08dc0c(param_1);
          FUN_0e096c44(iVar8 + 0x90,0x20);
        }
        if ((int)(uVar14 << 0x12) < 0) {
          *(undefined4 *)(iVar12 + 0x14) = 0x2000;
          iVar16 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
          *(byte *)(iVar16 + 0x362) =
               (byte)((*(uint *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + 0x808) >> 1) << 6) | 0x20
               | *(byte *)(iVar16 + 0x362) & 0x1f;
          FUN_0e096c30(iVar16 + 0x90,1);
          FUN_0e08d270(param_1,4,0);
        }
        if ((int)uVar14 < 0) {
          *(undefined4 *)(iVar12 + 0x14) = 0x80000000;
          FUN_0e08d124(param_1,0);
          FUN_0e08d270(param_1,2,0);
          FUN_0e096c44(iVar8 + 0x90,0x20);
        }
        if ((int)(uVar14 << 0xd) < 0) {
          uVar3 = 0;
          iVar16 = *(int *)(*(int *)(param_1 + 4) + 0x10);
          uVar17 = *(uint *)(iVar16 + 0x810);
          uVar13 = *(uint *)(iVar16 + 0x818);
          do {
            while ((iVar18 = iVar16 + uVar3 * 0x20, -1 < (int)((uVar13 >> (uVar3 & 0xff)) << 0x1f)
                   || (uVar15 = uVar17 & *(uint *)(iVar18 + 0x908),
                      *(uint *)(iVar18 + 0x908) = uVar15, -1 < (int)(uVar15 << 0x1f)))) {
LAB_0e08f39c:
              uVar3 = uVar3 + 1;
              if (uVar3 == 0x10) goto LAB_0e08f42a;
            }
            iVar4 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
            iVar18 = FUN_0e08d154(param_1,(uVar3 | 0xffffff80) & 0xff);
            iVar9 = FUN_0e08d230(param_1,*(undefined1 *)(iVar18 + 0x18));
            if (iVar9 == 0) {
              FUN_0e08d270(param_1,7,0xffffff97);
              goto LAB_0e08f39c;
            }
            FUN_0e08a79c(iVar9 + 0xc,*(undefined4 *)(iVar4 + uVar3 * 4 + 700));
            if ((*(short *)(iVar9 + 0x10) != 0) &&
               (iVar18 = FUN_0e08e064(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x10),
                                      iVar18,iVar9), iVar18 == 0)) goto LAB_0e08f39c;
            FUN_0e096c30(iVar4 + 0xa8,1 << (uVar3 & 0xff));
            uVar3 = uVar3 + 1;
            FUN_0e096c30(iVar4 + 0x90,8);
          } while (uVar3 != 0x10);
LAB_0e08f42a:
          *(undefined4 *)(iVar16 + 0x14) = 0x40000;
        }
        if ((int)(uVar14 << 0x1b) < 0) {
          iVar16 = *(int *)(*(int *)(param_1 + 4) + 0x10);
          uVar17 = *(uint *)(iVar16 + 0x20);
          uVar13 = (uVar17 & 0x1fffff) >> 0x11;
          uVar3 = uVar17 & 0xf;
          uVar17 = (uVar17 & 0x7fff) >> 4;
          if (uVar13 == 2) {
            iVar16 = FUN_0e08d154(param_1,uVar3);
            iVar16 = FUN_0e08d230(param_1,*(undefined1 *)(iVar16 + 0x18));
            iVar18 = *(int *)(*(int *)(param_1 + 4) + 0x10);
            if (iVar16 == 0) {
              if (uVar17 != 0) {
                uVar3 = uVar17 + 3 >> 2;
                goto LAB_0e08f5f8;
              }
            }
            else {
              iVar16 = iVar16 + 0xc;
              uVar15 = FUN_0e08a7ac(iVar16);
              uVar13 = uVar17;
              if (uVar15 <= uVar17) {
                uVar13 = FUN_0e08a7ac(iVar16);
              }
              if (uVar13 >> 2 != 0) {
                uVar15 = 0;
                do {
                  uVar15 = uVar15 + 1;
                  FUN_0e08a77c(iVar16,*(undefined4 *)(iVar18 + (uVar3 + 1) * 0x1000));
                } while (uVar15 != uVar13 >> 2);
              }
              if ((uVar13 & 3) != 0) {
                local_2c[0] = *(undefined4 *)(iVar18 + (uVar3 + 1) * 0x1000);
                puVar21 = local_2c;
                do {
                  puVar20 = (undefined4 *)((int)puVar21 + 1);
                  FUN_0e08a748(iVar16,*(undefined1 *)puVar21);
                  puVar21 = puVar20;
                } while ((undefined4 *)((uVar13 & 3) + (int)local_2c) != puVar20);
              }
              if ((uVar13 < uVar17) && (uVar3 = (uVar17 + 3) - uVar13 >> 2, uVar3 != 0)) {
LAB_0e08f5f8:
                uVar13 = 0;
                do {
                  uVar13 = uVar13 + 1;
                } while (uVar13 != uVar3);
              }
            }
          }
          else if ((uVar13 == 6) && (uVar17 != 0)) {
            iVar18 = 0;
            uVar13 = uVar17;
            if (7 < uVar17) {
              uVar13 = 8;
            }
            iVar9 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
            do {
              uVar15 = iVar18 + 4;
              uVar6 = *(undefined4 *)(iVar16 + (uVar3 + 1) * 0x1000);
              *(char *)(iVar9 + 0x367) = (char)uVar6;
              *(char *)(iVar9 + 0x369) = (char)((uint)uVar6 >> 0x10);
              *(char *)(iVar9 + 0x368) = (char)((uint)uVar6 >> 8);
              *(char *)(iVar9 + 0x36a) = (char)((uint)uVar6 >> 0x18);
              iVar18 = 4;
              iVar9 = iVar9 + 4;
            } while (uVar15 < uVar13);
            for (; uVar15 < uVar17; uVar15 = uVar15 + 4) {
            }
          }
        }
        if ((int)(uVar14 << 0xc) < 0) {
          iVar16 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
          iVar18 = *(int *)(*(int *)(param_1 + 4) + 0x10);
          uVar3 = *(uint *)(iVar18 + 0x814);
          uVar13 = 0;
          uVar17 = *(uint *)(iVar18 + 0x818);
          do {
            while (-1 < (int)((uVar17 >> (uVar13 + 0x10 & 0xff)) << 0x1f)) {
LAB_0e08f20e:
              uVar13 = uVar13 + 1;
              if (uVar13 == 0x10) goto LAB_0e08f2be;
            }
            iVar9 = iVar18 + uVar13 * 0x20;
            uVar15 = *(uint *)(iVar9 + 0xb08) & uVar3;
            *(uint *)(iVar9 + 0xb08) = uVar15;
            if ((int)(uVar15 << 0x1c) < 0) {
              FUN_0e096c30(iVar16 + 0x90,4);
            }
            if (-1 < (int)(uVar15 << 0x1f)) goto LAB_0e08f20e;
            iVar9 = FUN_0e08d154(param_1,uVar13 & 0xff);
            uVar15 = *(uint *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + uVar13 * 0x20 + 0xb10);
            bVar1 = *(byte *)(iVar9 + 0x19);
            iVar19 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
            iVar4 = FUN_0e08d230(param_1,*(undefined1 *)(iVar9 + 0x18));
            if (iVar4 == 0) {
              FUN_0e08d270(param_1,7,0xffffff97);
              goto LAB_0e08f20e;
            }
            uVar5 = *(uint *)(iVar19 + uVar13 * 4 + 0x2fc);
            uVar10 = (uVar5 & 0x7ffff) - (uVar15 & 0x7ffff);
            if ((bVar1 & 3) == 1) {
              uVar10 = (uVar15 & 0x7fffffff) >> 0x1d;
              iVar9 = ((uVar5 & 0x1fffffff) >> 0x13) - ((uVar15 & 0x1fffffff) >> 0x13);
              if (uVar10 == 1) {
                if (iVar9 != 3) goto LAB_0e08f2fc;
              }
              else if (uVar10 == 2) {
                if (iVar9 != 2) goto LAB_0e08f2fc;
              }
              else if ((uVar10 != 0) || (iVar9 != 1)) {
LAB_0e08f2fc:
                FUN_0e08a78c(iVar4 + 0xc);
              }
            }
            else if (((uVar10 != 0) &&
                     (uVar15 = *(ushort *)(iVar9 + 0x1a) & 0x7ff,
                     uVar10 == uVar15 * (uVar10 / uVar15))) &&
                    (iVar7 = FUN_0e08a7ac(iVar4 + 0xc), iVar7 != 0)) {
              FUN_0e08df74(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x10),iVar4,iVar9)
              ;
              goto LAB_0e08f20e;
            }
            FUN_0e096c30(iVar19 + 0xa8,1 << (uVar13 + 0x10 & 0xff));
            uVar13 = uVar13 + 1;
            FUN_0e096c30(iVar19 + 0x90,8);
          } while (uVar13 != 0x10);
LAB_0e08f2be:
          *(undefined4 *)(iVar18 + 0x14) = 0x80000;
        }
        if ((int)(uVar14 << 0xb) < 0) {
          iVar16 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
          iVar18 = *(int *)(*(int *)(param_1 + 4) + 0x10);
          uVar3 = (uint)*(byte *)(iVar16 + 0x364);
          if (1 < uVar3) {
            uVar13 = 1;
            do {
              while ((1 < (3 << (uVar13 << 1 & 0xff) & *(uint *)(iVar16 + 0x2ac)) >>
                          (uVar13 << 1 & 0xff) ||
                     ((*(uint *)(*(int *)(*(int *)(param_1 + 4) + 0x10) +
                                ((uVar13 & 0x7f) + 0x48) * 0x20) & 0x800c8000) != 0x80048000))) {
                uVar13 = uVar13 + 1 & 0xff;
                if (uVar3 <= uVar13) goto LAB_0e08f1dc;
              }
              iVar9 = FUN_0e08d154(param_1,uVar13 | 0x80);
              FUN_0e08e280(param_1,iVar9,0);
              iVar4 = FUN_0e08d1cc(param_1,*(undefined1 *)(iVar9 + 0x18));
              if (iVar4 != 0) {
                FUN_0e08d290(param_1,iVar4,0);
                FUN_0e08e228(param_1,iVar9);
              }
              uVar3 = (uint)*(byte *)(iVar16 + 0x364);
              uVar13 = uVar13 + 1 & 0xff;
            } while (uVar13 < uVar3);
          }
LAB_0e08f1dc:
          *(undefined4 *)(iVar18 + 0x14) = 0x100000;
        }
        if ((int)(uVar14 << 10) < 0) {
          iVar16 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
          iVar18 = *(int *)(*(int *)(param_1 + 4) + 0x10);
          uVar2 = *(ushort *)(iVar16 + 0x360);
          uVar3 = (uint)*(byte *)(iVar16 + 0x364);
          if (1 < uVar3) {
            uVar13 = 1;
            do {
              while (((3 << (uVar13 << 1 & 0xff) & *(uint *)(iVar16 + 0x2ac)) >>
                      (uVar13 << 1 & 0xff) & 0xfffffffd) != 0) {
LAB_0e08f052:
                uVar13 = uVar13 + 1 & 0xff;
                if (uVar3 <= uVar13) goto LAB_0e08f0d4;
              }
              iVar9 = (uVar13 & 0x7f) + 0x58;
              if ((uVar13 & 0x80) != 0) {
                iVar9 = (uVar13 & 0x7f) + 0x48;
              }
              if (((uVar2 & 1) << 0x10 | 0x80048000) !=
                  (*(uint *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + iVar9 * 0x20) & 0x800d8000))
              goto LAB_0e08f052;
              iVar9 = FUN_0e08d154(param_1,uVar13);
              FUN_0e08e280(param_1,iVar9,0);
              iVar9 = FUN_0e08d1cc(param_1,*(undefined1 *)(iVar9 + 0x18));
              if (iVar9 != 0) {
                FUN_0e08d290(param_1,iVar9,0);
              }
              uVar3 = (uint)*(byte *)(iVar16 + 0x364);
              uVar13 = uVar13 + 1 & 0xff;
            } while (uVar13 < uVar3);
          }
LAB_0e08f0d4:
          *(undefined4 *)(iVar18 + 0x14) = 0x200000;
        }
        if (-1 < (int)(uVar14 << 0x14)) goto LAB_0e08efe0;
        *(undefined4 *)(iVar12 + 0x14) = 0x800;
        FUN_0e08d124(param_1,1);
        FUN_0e08d270(param_1,3,0);
        if (*(char *)(iVar8 + 0x363) != '\x01') goto LAB_0e08efe0;
        FUN_0e096c30(iVar8 + 0x90,0x20);
        uVar14 = *(uint *)(iVar12 + 0x14) & uVar11;
        if (uVar14 == 0) break;
      } while( true );
    }
  }
  iVar8 = *(int *)(*(int *)(param_1 + 4) + 0x18);
  if ((iVar8 != 0) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(iVar8 + 0x14), UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0e08f13c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_1);
    return;
  }
  return;
}


