/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06283c. Types and names are inferred; NOT original source. */

uint FUN_0e06283c(int param_1,int param_2,uint param_3)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
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
    if ((bVar4 & 1) != 0) goto LAB_0e062890;
    if ((bVar4 & 4) == 0) goto LAB_0e062898;
    if (uVar12 == 0) goto LAB_0e062882;
LAB_0e0628cc:
    if (uVar12 == 0x80) {
      FUN_0e061bc0(param_2);
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
    goto LAB_0e062898;
  }
  if ((bVar4 & 1) == 0) {
    if (param_3 != 0xffffff8f) {
      FUN_0e061bc0(param_2);
      return param_3;
    }
LAB_0e062882:
    FUN_0e061bc0(param_2);
    return uVar12 & 0xffffff7f;
  }
LAB_0e062890:
  if (uVar12 != 0) {
    if ((bVar4 & 4) == 0) goto LAB_0e062898;
    goto LAB_0e0628cc;
  }
  iVar17 = *(int *)(*(int *)(param_1 + 0x18) + 0x10);
  if (*(ushort *)(param_2 + 0x10) < 8) {
LAB_0e06296c:
    FUN_0e061bc0(param_2);
    goto LAB_0e062898;
  }
  uVar13 = (*(undefined4 **)(param_2 + 0xc))[1];
  *(undefined4 *)(param_1 + 0x20) = **(undefined4 **)(param_2 + 0xc);
  *(undefined4 *)(param_1 + 0x24) = uVar13;
  if (*(int *)(param_2 + 4) == 0) goto LAB_0e06296c;
  uVar12 = (uint)*(byte *)(*(int *)(param_2 + 4) + 0x19);
  if (*(short *)(param_1 + 0x26) == 0) {
    iVar19 = uVar12 << 0x1d;
  }
  else {
    iVar19 = uVar12 << 0x1e;
  }
  if (-1 < iVar19) goto LAB_0e06296c;
  iVar19 = FUN_0e061c48(0);
  *(undefined4 *)(iVar17 + 0xa8) = 0;
  if (iVar19 == 0) goto LAB_0e062898;
  iVar5 = FUN_0e06f548();
  iVar17 = DAT_0e062c2c;
  bVar4 = *(byte *)(param_1 + 0x20);
  uVar12 = (uint)bVar4;
  *(undefined4 *)(DAT_0e062c2c + iVar5) = extraout_r3;
  if ((bVar4 & 0x60) != 0) {
    if ((uVar12 & 0x7f) >> 5 != 3) {
LAB_0e062952:
      uVar12 = FUN_0e0627bc(param_1,iVar19);
      goto LAB_0e06295c;
    }
    goto switchD_0e0629a4_caseD_3;
  }
  uVar8 = (uint)*(ushort *)(param_1 + 0x26);
  uVar10 = *(undefined1 *)(param_1 + 0x21);
  if (uVar8 != 0) {
    if (-1 < (char)bVar4) {
      switch(uVar10) {
      case 5:
        goto switchD_0e0629a4_caseD_5;
      case 9:
        goto switchD_0e0629a4_caseD_9;
      }
      goto switchD_0e0629a4_caseD_3;
    }
    switch(uVar10) {
    case 0:
      sVar11 = *(short *)(param_1 + 0x24);
      if (uVar8 == 2) {
        if (*(char *)(param_1 + 0x2c) == '\0') goto LAB_0e062aec;
        if (*(char *)(param_1 + 0x2c) == '\x01') {
          if (sVar11 != 0) goto LAB_0e062aec;
          if ((bVar4 & 0x1f) == 0) goto LAB_0e062f6c;
          if ((uVar12 & 0x1f) == 2) goto LAB_0e062b7a;
          uVar12 = 0;
        }
        else if ((bVar4 & 0x1f) == 0) {
          if (sVar11 != 0) goto LAB_0e062aec;
LAB_0e062f6c:
          uVar12 = *(byte *)(param_1 + 0x60) >> 2 & 2;
        }
        else if ((uVar12 & 0x1f) == 2) {
LAB_0e062b7a:
          uVar12 = FUN_0e064014(param_1,(char)sVar11);
        }
        else {
          uVar12 = 0;
        }
        uVar8 = FUN_0e061cfc(iVar19 + 0xc);
        if (uVar8 < *(ushort *)(param_1 + 0x26)) goto LAB_0e062eb4;
        FUN_0e061cac(iVar19 + 0xc,uVar12);
        goto LAB_0e062a0c;
      }
      break;
    case 6:
      uVar10 = (undefined1)*(ushort *)(param_1 + 0x22);
      if ((bVar4 & 0x1f) != 0) goto LAB_0e062952;
      iVar5 = (*(ushort *)(param_1 + 0x22) >> 8) - 1;
      switch(iVar5) {
      case 0:
        iVar5 = iVar19 + 0xc;
        uVar12 = FUN_0e061cfc(iVar5);
        if (uVar8 < uVar12) {
          uVar12 = (uint)*(ushort *)(param_1 + 0x26);
        }
        else {
          uVar12 = FUN_0e061cfc(iVar5);
        }
        iVar20 = FUN_0e062344(param_1);
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
        FUN_0e061c84(iVar5,pbVar7,uVar8);
        goto LAB_0e062a0c;
      case 1:
        uVar12 = FUN_0e0626ac(param_1,iVar19,uVar10,0);
        goto LAB_0e06295c;
      case 2:
        iVar5 = FUN_0e06256c(param_1,3);
        if (iVar5 != 0) {
          iVar20 = FUN_0e0626a0();
          if (iVar20 != 0) {
            local_5c = 0;
            uVar2 = *(ushort *)(param_1 + 0x26);
            local_5b = *(undefined1 *)(iVar5 + 0x11);
            if ((DAT_0e063228 & *(uint *)(iVar5 + 8)) == DAT_0e06322c) {
              iVar5 = FUN_0e067b30(abStack_58);
              if (iVar5 < 0) break;
              puVar18 = &local_48;
              pbVar7 = abStack_58;
              for (iVar20 = 0; iVar5 != iVar20; iVar20 = iVar20 + 1) {
                uVar10 = *(undefined1 *)(DAT_0e063230 + (*pbVar7 & 0xf));
                *(undefined1 *)puVar18 = *(undefined1 *)(DAT_0e063230 + (uint)(*pbVar7 >> 4));
                *(undefined1 *)((int)puVar18 + 1) = uVar10;
                puVar18 = (undefined4 *)((int)puVar18 + 2);
                pbVar7 = pbVar7 + 1;
              }
              local_5c = (char)iVar5 * '\x04' + 2;
              puVar18 = &local_48;
            }
            else {
              local_5c = *(byte *)(iVar5 + 0x10);
              puVar18 = *(undefined4 **)(iVar5 + 0xc);
            }
            iVar5 = iVar19 + 0xc;
            uVar8 = FUN_0e061cfc(iVar5);
            uVar12 = (uint)local_5c;
            if ((uint)uVar2 <= (uint)local_5c) {
              uVar12 = (uint)uVar2;
            }
            if (uVar8 < uVar12) {
              uVar12 = FUN_0e061cfc(iVar5);
            }
            uVar8 = uVar12;
            if (1 < uVar12) {
              uVar8 = 2;
            }
            uVar12 = uVar12 - uVar8;
            FUN_0e061c84(iVar5,&local_5c);
            for (puVar21 = puVar18; (undefined4 *)((int)puVar18 + (uVar12 >> 1)) != puVar21;
                puVar21 = (undefined4 *)((int)puVar21 + 1)) {
              FUN_0e061cac(iVar5,*(undefined1 *)puVar21);
            }
            if ((uVar12 & 1) != 0) {
              FUN_0e061c98(iVar5,*(undefined1 *)((int)puVar18 + (uVar12 >> 1)));
            }
            goto LAB_0e062a0c;
          }
          local_48 = CONCAT22(**(undefined2 **)(iVar5 + 0xc),*(undefined2 *)(iVar5 + 0x10));
LAB_0e062ca6:
          iVar5 = iVar19 + 0xc;
          uVar2 = *(ushort *)(param_1 + 0x26);
          uVar12 = FUN_0e061cfc(iVar5);
          if (uVar2 < uVar12) {
            uVar12 = (uint)*(ushort *)(param_1 + 0x26);
          }
          else {
            uVar12 = FUN_0e061cfc(iVar5);
          }
          uVar8 = local_48 & 0xff;
          if (uVar12 <= (local_48 & 0xff)) {
            uVar8 = uVar12;
          }
          FUN_0e061c84(iVar5,&local_48,uVar8);
          goto LAB_0e062a0c;
        }
        break;
      case 5:
        iVar5 = FUN_0e062344(param_1,iVar5,uVar10);
        piVar14 = (int *)(param_1 + 100);
        if (iVar5 == 0) {
          piVar14 = (int *)(param_1 + 0x68);
        }
        iVar5 = *piVar14;
        local_48 = CONCAT22(*(undefined2 *)(iVar5 + 2),0x60a);
        local_44 = *(uint *)(iVar5 + 4);
        local_40 = *(undefined1 *)(iVar5 + 0x11);
        local_3f = 0;
        iVar5 = FUN_0e062350(param_1);
        if (iVar5 == 1) goto LAB_0e062ca6;
        goto LAB_0e062c6c;
      case 6:
        uVar12 = FUN_0e0626ac(param_1,iVar19,uVar10,1);
LAB_0e06295c:
        if (uVar12 != 0) {
LAB_0e062960:
          FUN_0e061bc0(iVar19);
          return uVar12;
        }
LAB_0e062a0c:
        iVar5 = FUN_0e06f548();
        if (*(int *)(iVar17 + iVar5) == 0) {
          sVar11 = *(short *)(param_1 + 0x26);
LAB_0e062a1a:
          *(undefined4 *)(param_1 + 0x28) = 1;
          uVar12 = 0;
          if ((sVar11 != 0) && (uVar12 = (uint)(*(byte *)(param_1 + 0x20) >> 7), uVar12 == 0)) {
            do {
              iVar19 = FUN_0e061c48(0,iVar19);
              if (iVar19 == 0) goto LAB_0e062898;
              uVar12 = (uint)*(byte *)(iVar19 + 0x19);
            } while (-1 < (int)(uVar12 << 0x1d));
          }
          if ((*(byte *)(iVar19 + 0x18) & 0x7f) != 0) {
            return 0xffffffea;
          }
          uVar8 = (uint)*(byte *)(iVar19 + 0x18) << 0x18;
          if ((int)uVar8 < 0) {
            iVar17 = FUN_0e06242c();
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
          uVar12 = FUN_0e064b50(*(undefined4 *)(param_1 + 0x18),iVar19,uVar8,uVar12);
          return uVar12;
        }
        goto LAB_0e062980;
      case 0xe:
        iVar5 = FUN_0e062344(param_1,iVar5,uVar10);
        if (iVar5 == 0) {
          iVar5 = *(int *)(param_1 + 100);
        }
        else {
          if (iVar5 != 1) goto LAB_0e062c6c;
          iVar5 = *(int *)(param_1 + 0x68);
        }
        if (0x200 < *(ushort *)(iVar5 + 2)) {
          local_48 = DAT_0e062c30;
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
          iVar5 = iVar19 + 0xc;
          uVar8 = FUN_0e061cfc(iVar5);
          uVar12 = local_48 >> 0x10;
          if ((uint)*(ushort *)(param_1 + 0x26) <= local_48 >> 0x10) {
            uVar12 = (uint)*(ushort *)(param_1 + 0x26);
          }
          if (uVar8 < uVar12) {
            uVar12 = FUN_0e061cfc(iVar5);
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
          FUN_0e061c84(iVar5,&local_48,uVar16);
          if ((uVar8 != 0) &&
             (piVar14 = *(int **)(param_1 + 0x48), piVar14 != (int *)(param_1 + 0x48))) {
            for (; piVar14 != (int *)0x0; piVar14 = (int *)*piVar14) {
              if (*(char *)((int)piVar14 + 0x11) == '\x0f') {
                uVar12 = (uint)*(byte *)(piVar14 + 4);
                if (uVar8 <= *(byte *)(piVar14 + 4)) {
                  uVar12 = uVar8;
                }
                FUN_0e061c84(iVar5,piVar14[3],uVar12);
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
          goto LAB_0e062a0c;
        }
LAB_0e062c6c:
        iVar5 = FUN_0e06f548();
        *(undefined4 *)(iVar17 + iVar5) = 0xffffff7a;
        goto LAB_0e062a0c;
      }
      break;
    case 8:
      uVar10 = *(undefined1 *)(param_1 + 0x34);
      if (*(char *)(param_1 + 0x2c) == '\0') goto LAB_0e062aec;
LAB_0e062bac:
      if (uVar8 == 1) {
        uVar12 = FUN_0e061cfc(iVar19 + 0xc);
        if (*(ushort *)(param_1 + 0x26) <= uVar12) {
          FUN_0e061c98(iVar19 + 0xc,uVar10);
          goto LAB_0e062a0c;
        }
LAB_0e062eb4:
        iVar5 = FUN_0e06f548();
        *(undefined4 *)(iVar17 + iVar5) = 0xfffffff4;
        goto LAB_0e062980;
      }
      break;
    case 10:
      if (((uVar12 & 0x1f) != 1) || (iVar5 = FUN_0e063854(param_1), iVar5 == 0)) goto LAB_0e062aec;
      uVar12 = (uint)*(ushort *)(param_1 + 0x24);
      if ((uVar12 < 0x100) && ((uVar12 <= *(byte *)(*(int *)(iVar5 + 4) + 4) && (uVar12 < 0x10)))) {
        uVar10 = *(undefined1 *)(uVar12 + param_1 + 0x36);
        uVar8 = (uint)*(ushort *)(param_1 + 0x26);
        goto LAB_0e062bac;
      }
    }
    goto switchD_0e0629a4_caseD_3;
  }
  sVar11 = 0;
  switch(uVar10) {
  case 1:
    sVar1 = *(short *)(param_1 + 0x24);
    if (*(char *)(param_1 + 0x2c) != '\0') {
      if (*(char *)(param_1 + 0x2c) == '\x01') {
        if (sVar1 == 0) {
          if ((bVar4 & 0x1f) == 0) goto LAB_0e062f12;
          goto LAB_0e062df2;
        }
      }
      else {
        if ((bVar4 & 0x1f) != 0) {
LAB_0e062df2:
          if (((uVar12 & 0x1f) != 2) || (*(short *)(param_1 + 0x22) != 0)) goto LAB_0e062a1a;
          uVar10 = (undefined1)sVar1;
          FUN_0e063fe8(param_1,uVar10);
          iVar5 = FUN_0e06f548();
          *(int *)(iVar17 + iVar5) = extraout_r3_01;
          if (extraout_r3_01 == -1) goto LAB_0e063204;
          iVar5 = FUN_0e063b94(param_1,uVar10);
          if (iVar5 != 0) {
            pcVar15 = (code *)**(undefined4 **)(*(int *)(iVar5 + 4) + 8);
            if (pcVar15 != (code *)0x0) {
              (*pcVar15)(*(int *)(iVar5 + 4),uVar10,0);
            }
          }
          goto LAB_0e062a0c;
        }
        if (sVar1 == 0) {
LAB_0e062f12:
          if (*(short *)(param_1 + 0x22) == 1) {
            *(byte *)(param_1 + 0x60) = *(byte *)(param_1 + 0x60) & 0xf7;
          }
          goto LAB_0e062a1a;
        }
      }
    }
LAB_0e062aec:
    iVar5 = FUN_0e06f548();
    *(undefined4 *)(iVar17 + iVar5) = 0xffffffff;
    goto LAB_0e062980;
  case 3:
    sVar1 = *(short *)(param_1 + 0x22);
    uVar2 = *(ushort *)(param_1 + 0x24);
    cVar9 = (char)uVar2;
    if (sVar1 != 2) {
      if (*(char *)(param_1 + 0x2c) != '\0') {
        if (*(char *)(param_1 + 0x2c) == '\x01') {
          if (uVar2 == 0) {
            if ((bVar4 & 0x1f) == 0) goto LAB_0e062f9e;
            goto LAB_0e062d90;
          }
        }
        else {
          if ((bVar4 & 0x1f) != 0) {
LAB_0e062d90:
            if (((uVar12 & 0x1f) != 2) || (sVar1 != 0)) goto LAB_0e062a1a;
            FUN_0e063fbc(param_1,cVar9);
            iVar5 = FUN_0e06f548();
            *(int *)(iVar17 + iVar5) = extraout_r3_00;
            if (extraout_r3_00 == -1) goto LAB_0e063204;
            iVar5 = FUN_0e063b94(param_1,cVar9);
            if (iVar5 != 0) {
              pcVar15 = (code *)**(undefined4 **)(*(int *)(iVar5 + 4) + 8);
              if (pcVar15 != (code *)0x0) {
                (*pcVar15)(*(int *)(iVar5 + 4),cVar9,1);
              }
            }
            goto LAB_0e062a0c;
          }
          if (uVar2 == 0) {
LAB_0e062f9e:
            if (sVar1 == 1) {
              *(byte *)(param_1 + 0x60) = *(byte *)(param_1 + 0x60) | 8;
            }
            goto LAB_0e062a1a;
          }
        }
      }
      goto LAB_0e062aec;
    }
    if ((*(byte *)(param_1 + 0x20) & 0x1f) == 0 && cVar9 == '\0') {
      iVar5 = *(int *)(param_1 + 0x18);
      iVar20 = *(int *)(iVar5 + 8);
      if ((*(int *)(*(int *)(iVar5 + 0x10) + 0xa0) << 0x1e < 0) && (*(int *)(iVar20 + 0x28) != 0)) {
        (**(code **)(iVar20 + 0x3c))(iVar5);
        iVar6 = (**(code **)(iVar20 + 0x28))(iVar5,uVar2 >> 8,1);
        (**(code **)(iVar20 + 0x40))(iVar5);
        if (iVar6 == 0) {
          *(undefined1 *)(param_1 + 0x35) = 1;
          goto LAB_0e062a0c;
        }
      }
    }
    break;
  case 5:
switchD_0e0629a4_caseD_5:
    iVar5 = *(int *)(param_1 + 0x18);
    uVar2 = *(ushort *)(param_1 + 0x22);
    if (((0x7f < uVar2) || (*(short *)(param_1 + 0x24) != 0 || *(ushort *)(param_1 + 0x26) != 0)) ||
       ((*(byte *)(param_1 + 0x20) & 0x1f) != 0)) break;
    cVar9 = *(char *)(param_1 + 0x2c);
    if (cVar9 == '\x02') goto LAB_0e062aec;
    if (*(int *)(*(int *)(iVar5 + 0x10) + 0x80) << 0x1c < 0) {
      iVar20 = *(int *)(iVar5 + 8);
      if (-1 < *(int *)(*(int *)(iVar5 + 0x10) + 0xa0) << 0x1e) {
LAB_0e063204:
        uVar12 = 0xffffffff;
        goto LAB_0e062960;
      }
      (**(code **)(iVar20 + 0x3c))(iVar5);
      uVar12 = (**(code **)(iVar20 + 0x24))(iVar5,(char)uVar2);
      (**(code **)(iVar20 + 0x40))(iVar5);
      if (uVar12 != 0) goto LAB_0e062960;
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
    goto LAB_0e062a0c;
  case 9:
switchD_0e0629a4_caseD_9:
    uVar13 = FUN_0e062344(param_1);
    uVar2 = *(ushort *)(param_1 + 0x22);
    if (((uVar2 < 0x100) && (*(short *)(param_1 + 0x26) == 0)) &&
       ((*(byte *)(param_1 + 0x20) & 0x1f) == 0)) {
      if (*(char *)(param_1 + 0x2c) != '\0') {
        uVar3 = 0;
        if (uVar2 != 0) {
          iVar5 = FUN_0e063878(param_1,uVar13,(char)uVar2);
          if (iVar5 == 0) goto LAB_0e062aec;
          uVar3 = *(ushort *)(param_1 + 0x22);
        }
        if (*(byte *)(param_1 + 0x34) != uVar3) {
          uVar12 = FUN_0e063888(param_1,uVar3 & 0xff);
          if (uVar12 != 0) goto LAB_0e062960;
          if (*(short *)(param_1 + 0x22) == 0) {
            uVar10 = 1;
          }
          else {
            uVar10 = 2;
          }
          *(undefined1 *)(param_1 + 0x2c) = uVar10;
          FUN_0e0640ec(param_1,5);
        }
        goto LAB_0e062a0c;
      }
      goto LAB_0e062aec;
    }
    break;
  case 0xb:
    if ((((*(byte *)(param_1 + 0x20) & 0x1f) != 1) || (0xff < *(ushort *)(param_1 + 0x22))) ||
       (0xff < *(ushort *)(param_1 + 0x24))) break;
    if (*(char *)(param_1 + 0x2c) != '\x02') goto LAB_0e062aec;
    uVar12 = FUN_0e063e18(param_1,(char)*(ushort *)(param_1 + 0x24),
                          (char)*(ushort *)(param_1 + 0x22));
    if (uVar12 != 0xfffffffe) goto LAB_0e06295c;
    iVar5 = FUN_0e06f548();
    *(undefined4 *)(iVar17 + iVar5) = 0xfffffffe;
    goto LAB_0e062980;
  }
switchD_0e0629a4_caseD_3:
  iVar5 = FUN_0e06f548();
  *(undefined4 *)(iVar17 + iVar5) = 0xffffff7a;
LAB_0e062980:
  FUN_0e061bc0(iVar19);
LAB_0e062898:
  if ((*(short *)(param_1 + 0x26) == 0) || (*(char *)(param_1 + 0x20) < '\0')) {
    uVar12 = FUN_0e064a84(*(undefined4 *)(param_1 + 0x18),0x80);
  }
  else {
    uVar12 = FUN_0e064a84(*(undefined4 *)(param_1 + 0x18),(uint)(param_3 != 0xfffffff4) << 7);
  }
  *(undefined4 *)(param_1 + 0x28) = 0;
  return uVar12;
}


