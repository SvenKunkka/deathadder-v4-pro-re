/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06273c. Types and names are inferred; NOT original source. */

uint FUN_0e06273c(int param_1,int param_2,uint param_3)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  byte bVar4;
  int iVar5;
  char *pcVar6;
  byte *pbVar7;
  uint uVar8;
  char cVar9;
  undefined1 uVar10;
  short sVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined4 extraout_r3;
  int *piVar14;
  int extraout_r3_00;
  code *pcVar15;
  int extraout_r3_01;
  uint uVar16;
  int iVar17;
  undefined4 *puVar18;
  int iVar19;
  int iVar20;
  undefined4 *puVar21;
  byte local_5c;
  undefined1 local_5b;
  byte abStack_58 [16];
  undefined4 local_48;
  uint local_44;
  undefined1 local_40;
  undefined1 local_3f;
  
  uVar12 = (uint)*(byte *)(param_2 + 0x18);
  if ((*(byte *)(param_2 + 0x18) & 0x7f) != 0) {
    return 0xfffffffb;
  }
  bVar4 = *(byte *)(param_2 + 0x19);
  if ((param_3 == 0) || (param_3 == 0xfffffff4)) {
    if ((bVar4 & 1) != 0) goto LAB_0e062790;
    if ((bVar4 & 4) == 0) goto LAB_0e062798;
    if (uVar12 == 0) goto LAB_0e062782;
LAB_0e0627cc:
    if (uVar12 == 0x80) {
      FUN_0e061ac0(param_2);
      uVar12 = 0;
      if (*(int *)(param_1 + 0x28) != 1) {
        return 0;
      }
      if (*(char *)(param_1 + 0x35) == '\0') {
        return 0;
      }
      cVar9 = *(char *)(param_1 + 0x21);
      if (cVar9 == '\x05') {
        iVar19 = *(int *)(param_1 + 0x18);
        uVar10 = *(undefined1 *)(param_1 + 0x22);
        iVar17 = *(int *)(iVar19 + 8);
        if (*(int *)(*(int *)(iVar19 + 0x10) + 0xa0) << 0x1e < 0) {
          (**(code **)(iVar17 + 0x3c))(iVar19);
          uVar12 = (**(code **)(iVar17 + 0x24))(iVar19,uVar10);
          (**(code **)(iVar17 + 0x40))(iVar19);
          cVar9 = *(char *)(param_1 + 0x21);
        }
        else {
          uVar12 = 0xffffffff;
          cVar9 = *(char *)(param_1 + 0x21);
        }
      }
      if ((cVar9 == '\x03') && (*(short *)(param_1 + 0x22) == 2)) {
        iVar19 = *(int *)(param_1 + 0x18);
        uVar2 = *(ushort *)(param_1 + 0x24);
        iVar17 = *(int *)(iVar19 + 8);
        if (*(int *)(*(int *)(iVar19 + 0x10) + 0xa0) << 0x1e < 0) {
          if (*(int *)(iVar17 + 0x28) == 0) {
            uVar12 = 0xffffff7a;
          }
          else {
            (**(code **)(iVar17 + 0x3c))(iVar19);
            uVar12 = (**(code **)(iVar17 + 0x28))(iVar19,uVar2 >> 8,0);
            (**(code **)(iVar17 + 0x40))(iVar19);
          }
        }
        else {
          uVar12 = 0xffffffff;
        }
      }
      *(undefined1 *)(param_1 + 0x35) = 0;
      return uVar12;
    }
    goto LAB_0e062798;
  }
  if ((bVar4 & 1) == 0) {
    if (param_3 != 0xffffff8f) {
      FUN_0e061ac0(param_2);
      return param_3;
    }
LAB_0e062782:
    FUN_0e061ac0(param_2);
    return uVar12 & 0xffffff7f;
  }
LAB_0e062790:
  if (uVar12 != 0) {
    if ((bVar4 & 4) == 0) goto LAB_0e062798;
    goto LAB_0e0627cc;
  }
  iVar17 = *(int *)(*(int *)(param_1 + 0x18) + 0x10);
  if (*(ushort *)(param_2 + 0x10) < 8) {
LAB_0e06286c:
    FUN_0e061ac0(param_2);
    goto LAB_0e062798;
  }
  uVar13 = (*(undefined4 **)(param_2 + 0xc))[1];
  *(undefined4 *)(param_1 + 0x20) = **(undefined4 **)(param_2 + 0xc);
  *(undefined4 *)(param_1 + 0x24) = uVar13;
  if (*(int *)(param_2 + 4) == 0) goto LAB_0e06286c;
  uVar12 = (uint)*(byte *)(*(int *)(param_2 + 4) + 0x19);
  if (*(short *)(param_1 + 0x26) == 0) {
    iVar19 = uVar12 << 0x1d;
  }
  else {
    iVar19 = uVar12 << 0x1e;
  }
  if (-1 < iVar19) goto LAB_0e06286c;
  iVar19 = FUN_0e061b48(0);
  *(undefined4 *)(iVar17 + 0xa8) = 0;
  if (iVar19 == 0) goto LAB_0e062798;
  iVar17 = FUN_0e06f4ac();
  bVar4 = *(byte *)(param_1 + 0x20);
  uVar12 = (uint)bVar4;
  *(undefined4 *)(iVar17 + 0xc) = extraout_r3;
  if ((bVar4 & 0x60) != 0) {
    if ((uVar12 & 0x7f) >> 5 != 3) {
LAB_0e062852:
      uVar12 = FUN_0e0626bc(param_1,iVar19);
      goto LAB_0e06285c;
    }
    goto switchD_0e0628a4_caseD_3;
  }
  uVar8 = (uint)*(ushort *)(param_1 + 0x26);
  uVar10 = *(undefined1 *)(param_1 + 0x21);
  if (uVar8 != 0) {
    if (-1 < (char)bVar4) {
      switch(uVar10) {
      case 5:
        goto switchD_0e0628a4_caseD_5;
      case 9:
        goto switchD_0e0628a4_caseD_9;
      }
      goto switchD_0e0628a4_caseD_3;
    }
    switch(uVar10) {
    case 0:
      sVar11 = *(short *)(param_1 + 0x24);
      if (uVar8 == 2) {
        if (*(char *)(param_1 + 0x2c) == '\0') goto LAB_0e0629ec;
        if (*(char *)(param_1 + 0x2c) == '\x01') {
          if (sVar11 != 0) goto LAB_0e0629ec;
          if ((bVar4 & 0x1f) == 0) goto LAB_0e062e6c;
          if ((uVar12 & 0x1f) == 2) goto LAB_0e062a7a;
          uVar12 = 0;
        }
        else if ((bVar4 & 0x1f) == 0) {
          if (sVar11 != 0) goto LAB_0e0629ec;
LAB_0e062e6c:
          uVar12 = *(byte *)(param_1 + 0x60) >> 2 & 2;
        }
        else if ((uVar12 & 0x1f) == 2) {
LAB_0e062a7a:
          uVar12 = FUN_0e063f78(param_1,(char)sVar11);
        }
        else {
          uVar12 = 0;
        }
        uVar8 = FUN_0e061bfc(iVar19 + 0xc);
        if (uVar8 < *(ushort *)(param_1 + 0x26)) goto LAB_0e062db4;
        FUN_0e061bac(iVar19 + 0xc,uVar12);
        goto LAB_0e06290c;
      }
      break;
    case 6:
      uVar10 = (undefined1)*(ushort *)(param_1 + 0x22);
      if ((bVar4 & 0x1f) != 0) goto LAB_0e062852;
      iVar17 = (*(ushort *)(param_1 + 0x22) >> 8) - 1;
      switch(iVar17) {
      case 0:
        iVar17 = iVar19 + 0xc;
        uVar12 = FUN_0e061bfc(iVar17);
        if (uVar8 < uVar12) {
          uVar12 = (uint)*(ushort *)(param_1 + 0x26);
        }
        else {
          uVar12 = FUN_0e061bfc(iVar17);
        }
        iVar20 = FUN_0e062244(param_1);
        if (iVar20 == 0) {
          pbVar7 = *(byte **)(param_1 + 100);
        }
        else {
          if (iVar20 != 1) break;
          pbVar7 = *(byte **)(param_1 + 0x68);
        }
        uVar8 = (uint)*pbVar7;
        if (uVar12 <= *pbVar7) {
          uVar8 = uVar12;
        }
        FUN_0e061b84(iVar17,pbVar7,uVar8);
        goto LAB_0e06290c;
      case 1:
        uVar12 = FUN_0e0625ac(param_1,iVar19,uVar10,0);
        goto LAB_0e06285c;
      case 2:
        iVar17 = FUN_0e06246c(param_1,3);
        if (iVar17 != 0) {
          iVar20 = FUN_0e0625a0();
          if (iVar20 != 0) {
            local_5c = 0;
            uVar2 = *(ushort *)(param_1 + 0x26);
            local_5b = *(undefined1 *)(iVar17 + 0x11);
            if ((*(uint *)(iVar17 + 8) & 0x2ff00) == 0x20300) {
              iVar17 = FUN_0e067a94(abStack_58);
              if (iVar17 < 0) break;
              pcVar6 = (char *)&local_48;
              pbVar7 = abStack_58;
              for (iVar20 = 0; iVar17 != iVar20; iVar20 = iVar20 + 1) {
                cVar9 = "/0123456789ABCDEF"[(*pbVar7 & 0xf) + 1];
                *pcVar6 = "/0123456789ABCDEF"[(*pbVar7 >> 4) + 1];
                pcVar6[1] = cVar9;
                pcVar6 = pcVar6 + 2;
                pbVar7 = pbVar7 + 1;
              }
              local_5c = (char)iVar17 * '\x04' + 2;
              puVar18 = &local_48;
            }
            else {
              local_5c = *(byte *)(iVar17 + 0x10);
              puVar18 = *(undefined4 **)(iVar17 + 0xc);
            }
            iVar17 = iVar19 + 0xc;
            uVar8 = FUN_0e061bfc(iVar17);
            uVar12 = (uint)local_5c;
            if ((uint)uVar2 <= (uint)local_5c) {
              uVar12 = (uint)uVar2;
            }
            if (uVar8 < uVar12) {
              uVar12 = FUN_0e061bfc(iVar17);
            }
            uVar8 = uVar12;
            if (1 < uVar12) {
              uVar8 = 2;
            }
            uVar12 = uVar12 - uVar8;
            FUN_0e061b84(iVar17,&local_5c);
            for (puVar21 = puVar18; (undefined4 *)((int)puVar18 + (uVar12 >> 1)) != puVar21;
                puVar21 = (undefined4 *)((int)puVar21 + 1)) {
              FUN_0e061bac(iVar17,*(undefined1 *)puVar21);
            }
            if ((uVar12 & 1) != 0) {
              FUN_0e061b98(iVar17,*(undefined1 *)((int)puVar18 + (uVar12 >> 1)));
            }
            goto LAB_0e06290c;
          }
          local_48 = CONCAT22(**(undefined2 **)(iVar17 + 0xc),*(undefined2 *)(iVar17 + 0x10));
LAB_0e062ba6:
          iVar17 = iVar19 + 0xc;
          uVar2 = *(ushort *)(param_1 + 0x26);
          uVar12 = FUN_0e061bfc(iVar17);
          if (uVar2 < uVar12) {
            uVar12 = (uint)*(ushort *)(param_1 + 0x26);
          }
          else {
            uVar12 = FUN_0e061bfc(iVar17);
          }
          uVar8 = local_48 & 0xff;
          if (uVar12 <= (local_48 & 0xff)) {
            uVar8 = uVar12;
          }
          FUN_0e061b84(iVar17,&local_48,uVar8);
          goto LAB_0e06290c;
        }
        break;
      case 5:
        iVar17 = FUN_0e062244(param_1,iVar17,uVar10);
        piVar14 = (int *)(param_1 + 100);
        if (iVar17 == 0) {
          piVar14 = (int *)(param_1 + 0x68);
        }
        iVar17 = *piVar14;
        local_48 = CONCAT22(*(undefined2 *)(iVar17 + 2),0x60a);
        local_44 = *(uint *)(iVar17 + 4);
        local_40 = *(undefined1 *)(iVar17 + 0x11);
        local_3f = 0;
        iVar17 = FUN_0e062250(param_1);
        if (iVar17 == 1) goto LAB_0e062ba6;
        goto LAB_0e062b6c;
      case 6:
        uVar12 = FUN_0e0625ac(param_1,iVar19,uVar10,1);
LAB_0e06285c:
        if (uVar12 != 0) {
LAB_0e062860:
          FUN_0e061ac0(iVar19);
          return uVar12;
        }
LAB_0e06290c:
        iVar17 = FUN_0e06f4ac();
        if (*(int *)(iVar17 + 0xc) == 0) {
          sVar11 = *(short *)(param_1 + 0x26);
LAB_0e06291a:
          *(undefined4 *)(param_1 + 0x28) = 1;
          uVar12 = 0;
          if ((sVar11 != 0) && (uVar12 = (uint)(*(byte *)(param_1 + 0x20) >> 7), uVar12 == 0)) {
            do {
              iVar19 = FUN_0e061b48(0,iVar19);
              if (iVar19 == 0) goto LAB_0e062798;
              uVar12 = (uint)*(byte *)(iVar19 + 0x19);
            } while (-1 < (int)(uVar12 << 0x1d));
          }
          if ((*(byte *)(iVar19 + 0x18) & 0x7f) != 0) {
            return 0xffffffea;
          }
          uVar8 = (uint)*(byte *)(iVar19 + 0x18) << 0x18;
          if ((int)uVar8 < 0) {
            iVar17 = FUN_0e06232c();
            if (iVar17 != 0) {
              return 0xffffffff;
            }
            uVar16 = (uint)*(ushort *)(iVar19 + 0x10);
            uVar8 = (uint)*(ushort *)(param_1 + 0x26);
            if (uVar16 != 0) {
              if (uVar8 <= uVar16) {
                uVar16 = uVar8;
              }
              if (((uVar16 < uVar8) && ((uVar16 & 0x3f) == 0)) && (*(char *)(iVar19 + 0x18) < '\0'))
              {
                *(byte *)(iVar19 + 0x19) = *(byte *)(iVar19 + 0x19) | 8;
              }
            }
          }
          uVar12 = FUN_0e064ab4(*(undefined4 *)(param_1 + 0x18),iVar19,uVar8,uVar12);
          return uVar12;
        }
        goto LAB_0e062880;
      case 0xe:
        iVar17 = FUN_0e062244(param_1,iVar17,uVar10);
        if (iVar17 == 0) {
          iVar17 = *(int *)(param_1 + 100);
        }
        else {
          if (iVar17 != 1) goto LAB_0e062b6c;
          iVar17 = *(int *)(param_1 + 0x68);
        }
        if (0x200 < *(ushort *)(iVar17 + 2)) {
          local_48 = 0x50f05;
          piVar14 = *(int **)(param_1 + 0x48);
          local_44 = local_44 & 0xffffff00;
          if ((int *)(param_1 + 0x48) != piVar14) {
            for (; piVar14 != (int *)0x0; piVar14 = (int *)*piVar14) {
              if (*(char *)((int)piVar14 + 0x11) == '\x0f') {
                local_48 = CONCAT22((ushort)*(byte *)(piVar14 + 4) + local_48._2_2_,
                                    (undefined2)local_48);
                local_44 = CONCAT31(local_44._1_3_,(char)local_44 + '\x01');
              }
              if (piVar14 == (int *)*(int *)(param_1 + 0x4c)) break;
            }
          }
          iVar17 = iVar19 + 0xc;
          uVar8 = FUN_0e061bfc(iVar17);
          uVar12 = local_48 >> 0x10;
          if ((uint)*(ushort *)(param_1 + 0x26) <= local_48 >> 0x10) {
            uVar12 = (uint)*(ushort *)(param_1 + 0x26);
          }
          if (uVar8 < uVar12) {
            uVar12 = FUN_0e061bfc(iVar17);
          }
          if (uVar12 < 6) {
            uVar8 = 0;
          }
          else {
            uVar8 = uVar12 - 5;
          }
          uVar16 = local_48 & 0xff;
          if (uVar12 <= (local_48 & 0xff)) {
            uVar16 = uVar12;
          }
          FUN_0e061b84(iVar17,&local_48,uVar16);
          if ((uVar8 != 0) &&
             (piVar14 = *(int **)(param_1 + 0x48), piVar14 != (int *)(param_1 + 0x48))) {
            for (; piVar14 != (int *)0x0; piVar14 = (int *)*piVar14) {
              if (*(char *)((int)piVar14 + 0x11) == '\x0f') {
                uVar12 = (uint)*(byte *)(piVar14 + 4);
                if (uVar8 <= *(byte *)(piVar14 + 4)) {
                  uVar12 = uVar8;
                }
                FUN_0e061b84(iVar17,piVar14[3],uVar12);
                if (uVar8 < *(byte *)(piVar14 + 4)) {
                  uVar8 = 0;
                }
                else {
                  uVar8 = uVar8 - *(byte *)(piVar14 + 4);
                }
                if (uVar8 == 0) break;
              }
              if (piVar14 == (int *)*(int *)(param_1 + 0x4c)) break;
            }
          }
          goto LAB_0e06290c;
        }
LAB_0e062b6c:
        iVar17 = FUN_0e06f4ac();
        *(undefined4 *)(iVar17 + 0xc) = 0xffffff7a;
        goto LAB_0e06290c;
      }
      break;
    case 8:
      uVar10 = *(undefined1 *)(param_1 + 0x34);
      if (*(char *)(param_1 + 0x2c) == '\0') goto LAB_0e0629ec;
LAB_0e062aac:
      if (uVar8 == 1) {
        uVar12 = FUN_0e061bfc(iVar19 + 0xc);
        if (*(ushort *)(param_1 + 0x26) <= uVar12) {
          FUN_0e061b98(iVar19 + 0xc,uVar10);
          goto LAB_0e06290c;
        }
LAB_0e062db4:
        iVar17 = FUN_0e06f4ac();
        *(undefined4 *)(iVar17 + 0xc) = 0xfffffff4;
        goto LAB_0e062880;
      }
      break;
    case 10:
      if (((uVar12 & 0x1f) != 1) || (iVar17 = FUN_0e063754(param_1), iVar17 == 0))
      goto LAB_0e0629ec;
      uVar12 = (uint)*(ushort *)(param_1 + 0x24);
      if ((uVar12 < 0x100) && ((uVar12 <= *(byte *)(*(int *)(iVar17 + 4) + 4) && (uVar12 < 0x10))))
      {
        uVar10 = *(undefined1 *)(uVar12 + param_1 + 0x36);
        uVar8 = (uint)*(ushort *)(param_1 + 0x26);
        goto LAB_0e062aac;
      }
    }
    goto switchD_0e0628a4_caseD_3;
  }
  sVar11 = 0;
  switch(uVar10) {
  case 1:
    sVar1 = *(short *)(param_1 + 0x24);
    if (*(char *)(param_1 + 0x2c) != '\0') {
      if (*(char *)(param_1 + 0x2c) == '\x01') {
        if (sVar1 == 0) {
          if ((bVar4 & 0x1f) == 0) goto LAB_0e062e12;
          goto LAB_0e062cf2;
        }
      }
      else {
        if ((bVar4 & 0x1f) != 0) {
LAB_0e062cf2:
          if (((uVar12 & 0x1f) != 2) || (*(short *)(param_1 + 0x22) != 0)) goto LAB_0e06291a;
          uVar10 = (undefined1)sVar1;
          FUN_0e063f4c(param_1,uVar10);
          iVar17 = FUN_0e06f4ac();
          *(int *)(iVar17 + 0xc) = extraout_r3_01;
          if (extraout_r3_01 == -1) goto LAB_0e063104;
          iVar17 = FUN_0e063a94(param_1,uVar10);
          if (iVar17 != 0) {
            pcVar15 = (code *)**(undefined4 **)(*(int *)(iVar17 + 4) + 8);
            if (pcVar15 != (code *)0x0) {
              (*pcVar15)(*(int *)(iVar17 + 4),uVar10,0);
            }
          }
          goto LAB_0e06290c;
        }
        if (sVar1 == 0) {
LAB_0e062e12:
          if (*(short *)(param_1 + 0x22) == 1) {
            *(byte *)(param_1 + 0x60) = *(byte *)(param_1 + 0x60) & 0xf7;
          }
          goto LAB_0e06291a;
        }
      }
    }
LAB_0e0629ec:
    iVar17 = FUN_0e06f4ac();
    *(undefined4 *)(iVar17 + 0xc) = 0xffffffff;
    goto LAB_0e062880;
  case 3:
    sVar1 = *(short *)(param_1 + 0x22);
    uVar2 = *(ushort *)(param_1 + 0x24);
    cVar9 = (char)uVar2;
    if (sVar1 != 2) {
      if (*(char *)(param_1 + 0x2c) != '\0') {
        if (*(char *)(param_1 + 0x2c) == '\x01') {
          if (uVar2 == 0) {
            if ((bVar4 & 0x1f) == 0) goto LAB_0e062e9e;
            goto LAB_0e062c90;
          }
        }
        else {
          if ((bVar4 & 0x1f) != 0) {
LAB_0e062c90:
            if (((uVar12 & 0x1f) != 2) || (sVar1 != 0)) goto LAB_0e06291a;
            FUN_0e063f20(param_1,cVar9);
            iVar17 = FUN_0e06f4ac();
            *(int *)(iVar17 + 0xc) = extraout_r3_00;
            if (extraout_r3_00 == -1) goto LAB_0e063104;
            iVar17 = FUN_0e063a94(param_1,cVar9);
            if (iVar17 != 0) {
              pcVar15 = (code *)**(undefined4 **)(*(int *)(iVar17 + 4) + 8);
              if (pcVar15 != (code *)0x0) {
                (*pcVar15)(*(int *)(iVar17 + 4),cVar9,1);
              }
            }
            goto LAB_0e06290c;
          }
          if (uVar2 == 0) {
LAB_0e062e9e:
            if (sVar1 == 1) {
              *(byte *)(param_1 + 0x60) = *(byte *)(param_1 + 0x60) | 8;
            }
            goto LAB_0e06291a;
          }
        }
      }
      goto LAB_0e0629ec;
    }
    if ((*(byte *)(param_1 + 0x20) & 0x1f) == 0 && cVar9 == '\0') {
      iVar17 = *(int *)(param_1 + 0x18);
      iVar20 = *(int *)(iVar17 + 8);
      if ((*(int *)(*(int *)(iVar17 + 0x10) + 0xa0) << 0x1e < 0) && (*(int *)(iVar20 + 0x28) != 0))
      {
        (**(code **)(iVar20 + 0x3c))(iVar17);
        iVar5 = (**(code **)(iVar20 + 0x28))(iVar17,uVar2 >> 8,1);
        (**(code **)(iVar20 + 0x40))(iVar17);
        if (iVar5 == 0) {
          *(undefined1 *)(param_1 + 0x35) = 1;
          goto LAB_0e06290c;
        }
      }
    }
    break;
  case 5:
switchD_0e0628a4_caseD_5:
    iVar17 = *(int *)(param_1 + 0x18);
    uVar2 = *(ushort *)(param_1 + 0x22);
    if (((0x7f < uVar2) || (*(short *)(param_1 + 0x24) != 0 || *(ushort *)(param_1 + 0x26) != 0)) ||
       ((*(byte *)(param_1 + 0x20) & 0x1f) != 0)) break;
    cVar9 = *(char *)(param_1 + 0x2c);
    if (cVar9 == '\x02') goto LAB_0e0629ec;
    if (*(int *)(*(int *)(iVar17 + 0x10) + 0x80) << 0x1c < 0) {
      iVar20 = *(int *)(iVar17 + 8);
      if (-1 < *(int *)(*(int *)(iVar17 + 0x10) + 0xa0) << 0x1e) {
LAB_0e063104:
        uVar12 = 0xffffffff;
        goto LAB_0e062860;
      }
      (**(code **)(iVar20 + 0x3c))(iVar17);
      uVar12 = (**(code **)(iVar20 + 0x24))(iVar17,(char)uVar2);
      (**(code **)(iVar20 + 0x40))(iVar17);
      if (uVar12 != 0) goto LAB_0e062860;
      cVar9 = *(char *)(param_1 + 0x2c);
    }
    else {
      *(undefined1 *)(param_1 + 0x35) = 1;
    }
    if ((cVar9 == '\x01') && (*(short *)(param_1 + 0x22) == 0)) {
      uVar10 = 0;
    }
    else {
      uVar10 = 1;
    }
    *(undefined1 *)(param_1 + 0x2c) = uVar10;
    goto LAB_0e06290c;
  case 9:
switchD_0e0628a4_caseD_9:
    uVar13 = FUN_0e062244(param_1);
    uVar2 = *(ushort *)(param_1 + 0x22);
    if (((uVar2 < 0x100) && (*(short *)(param_1 + 0x26) == 0)) &&
       ((*(byte *)(param_1 + 0x20) & 0x1f) == 0)) {
      if (*(char *)(param_1 + 0x2c) != '\0') {
        uVar3 = 0;
        if (uVar2 != 0) {
          iVar17 = FUN_0e063778(param_1,uVar13,(char)uVar2);
          if (iVar17 == 0) goto LAB_0e0629ec;
          uVar3 = *(ushort *)(param_1 + 0x22);
        }
        if (*(byte *)(param_1 + 0x34) != uVar3) {
          uVar12 = FUN_0e063788(param_1,uVar3 & 0xff);
          if (uVar12 != 0) goto LAB_0e062860;
          if (*(short *)(param_1 + 0x22) == 0) {
            uVar10 = 1;
          }
          else {
            uVar10 = 2;
          }
          *(undefined1 *)(param_1 + 0x2c) = uVar10;
          FUN_0e064050(param_1,5);
        }
        goto LAB_0e06290c;
      }
      goto LAB_0e0629ec;
    }
    break;
  case 0xb:
    if ((((*(byte *)(param_1 + 0x20) & 0x1f) != 1) || (0xff < *(ushort *)(param_1 + 0x22))) ||
       (0xff < *(ushort *)(param_1 + 0x24))) break;
    if (*(char *)(param_1 + 0x2c) != '\x02') goto LAB_0e0629ec;
    uVar12 = FUN_0e063d7c(param_1,(char)*(ushort *)(param_1 + 0x24),
                          (char)*(ushort *)(param_1 + 0x22));
    if (uVar12 != 0xfffffffe) goto LAB_0e06285c;
    iVar17 = FUN_0e06f4ac();
    *(undefined4 *)(iVar17 + 0xc) = 0xfffffffe;
    goto LAB_0e062880;
  }
switchD_0e0628a4_caseD_3:
  iVar17 = FUN_0e06f4ac();
  *(undefined4 *)(iVar17 + 0xc) = 0xffffff7a;
LAB_0e062880:
  FUN_0e061ac0(iVar19);
LAB_0e062798:
  if ((*(short *)(param_1 + 0x26) == 0) || (*(char *)(param_1 + 0x20) < '\0')) {
    uVar12 = FUN_0e0649e8(*(undefined4 *)(param_1 + 0x18),0x80);
  }
  else {
    uVar12 = FUN_0e0649e8(*(undefined4 *)(param_1 + 0x18),(uint)(param_3 != 0xfffffff4) << 7);
  }
  *(undefined4 *)(param_1 + 0x28) = 0;
  return uVar12;
}


