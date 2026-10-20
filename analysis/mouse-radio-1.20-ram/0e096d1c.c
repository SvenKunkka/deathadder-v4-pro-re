/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e096d1c. Types and names are inferred; NOT original source. */

/* WARNING: Type propagation algorithm not settling */

char * FUN_0e096d1c(int param_1,byte *param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  byte *pbVar6;
  uint uVar7;
  char *pcVar8;
  uint *puVar9;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  char *pcVar13;
  uint uVar14;
  uint uVar15;
  char *pcVar16;
  uint uVar17;
  uint uVar18;
  bool bVar19;
  uint local_54;
  byte *local_4c;
  undefined4 local_44;
  char local_40 [28];
  
  pcVar5 = *(code **)(param_1 + 4);
  if ((int)((uint)*(byte *)(param_1 + 2) << 0x1e) < 0) {
    pcVar8 = (char *)0x0;
    do {
      while( true ) {
        uVar12 = (uint)*param_2;
        if (uVar12 == 0) {
          return pcVar8;
        }
        if (uVar12 != 0x25) break;
        uVar12 = (uint)param_2[1];
        local_4c = param_2 + 2;
        if (uVar12 == 0x25) goto LAB_0e096d44;
        uVar15 = 0;
        uVar17 = 0;
        puVar9 = param_3;
        uVar7 = 0;
        do {
          param_3 = puVar9;
          uVar14 = uVar7;
          if (uVar17 < 0x20) {
            switch(uVar12) {
            default:
              if (9 < uVar12 - 0x30) goto LAB_0e096d94;
LAB_0e096dfc:
              uVar17 = uVar17 | 0x20;
              uVar15 = uVar15 * 10 + (uVar12 - 0x30);
              break;
            case 0x23:
              uVar17 = uVar17 | 0x10;
              break;
            case 0x27:
              break;
            case 0x2b:
              uVar17 = uVar17 | 2;
            case 0x20:
              uVar17 = uVar17 | 4;
              break;
            case 0x2d:
              uVar17 = uVar17 | 8;
              break;
            case 0x30:
              uVar17 = uVar17 | 1;
            }
          }
          else {
            if (uVar17 < 0x80) {
              if (uVar12 - 0x30 < 10) {
                if ((uVar17 & 0x40) == 0) goto LAB_0e096dfc;
                uVar14 = uVar7 * 10 + (uVar12 - 0x30);
              }
              else {
LAB_0e096d94:
                if (uVar12 == 0x2a) {
                  param_3 = puVar9 + 1;
                  uVar12 = *puVar9;
                  uVar14 = uVar12;
                  if ((uVar17 & 0x40) == 0) {
                    if ((int)uVar12 < 0) {
                      uVar15 = -uVar12;
                      uVar17 = uVar17 | 0x28;
                      uVar14 = uVar7;
                    }
                    else {
                      uVar17 = uVar17 | 0x20;
                      uVar14 = uVar7;
                      uVar15 = uVar12;
                    }
                  }
                }
                else {
                  if (uVar12 != 0x2e) goto LAB_0e096e1a;
                  if ((uVar17 & 0x40) != 0) {
                    return pcVar8;
                  }
                  uVar17 = uVar17 | 0x40;
                }
              }
              goto switchD_0e096d76_caseD_27;
            }
LAB_0e096e1a:
            if (uVar12 == 0x6c) {
              if ((uVar17 & 0x80) != 0) {
                uVar17 = uVar17 | 0x200;
              }
              uVar17 = uVar17 | 0x80;
            }
            else if (uVar12 < 0x6d) {
              if (uVar12 == 0x68) {
                if ((uVar17 & 0x100) != 0) {
                  uVar17 = uVar17 | 0x200;
                }
                uVar17 = uVar17 | 0x100;
              }
              else {
                if ((uVar12 != 0x6a) && (uVar12 != 0x4c)) break;
                uVar17 = uVar17 | 0x280;
              }
            }
            else if ((uVar12 != 0x74) && (uVar12 != 0x7a)) break;
          }
switchD_0e096d76_caseD_27:
          pbVar6 = local_4c + 1;
          uVar12 = (uint)*local_4c;
          puVar9 = param_3;
          uVar7 = uVar14;
          local_4c = pbVar6;
        } while (uVar12 != 0);
        uVar7 = uVar12 | 0x20;
        if ((int)uVar14 < 0) {
          uVar17 = uVar17 & 0xffffffbf;
          uVar14 = 0;
        }
        if ((uVar7 - 0x65 < 3) || (uVar7 == 0x61)) {
          uVar12 = 7;
          pcVar16 = "*float*";
          puVar9 = (uint *)(((int)param_3 + 7U & 0xfffffff8) + 8);
          goto LAB_0e096e5a;
        }
        uVar18 = uVar14;
        local_54 = uVar14;
        switch(uVar12) {
        case 99:
          puVar9 = param_3 + 1;
          uVar12 = 1;
          pcVar16 = local_40;
          local_40[0] = (char)*param_3;
          goto LAB_0e096e5a;
        case 100:
        case 0x69:
          if ((uVar17 & 0x80) == 0) {
            puVar9 = param_3 + 1;
            uVar2 = *param_3;
            if ((uVar17 & 0x100) == 0) goto LAB_0e096fc4;
            if ((uVar17 & 0x200) == 0) {
              iVar1 = uVar2 << 0x10;
              uVar2 = (int)(short)uVar2;
            }
            else {
              iVar1 = uVar2 << 0x18;
              uVar2 = (int)(char)uVar2;
            }
            uVar4 = iVar1 >> 0x1f;
          }
          else if ((uVar17 & 0x200) == 0) {
            uVar2 = *param_3;
LAB_0e096fc4:
            puVar9 = param_3 + 1;
            uVar4 = (int)uVar2 >> 0x1f;
          }
          else {
            puVar10 = (uint *)((int)param_3 + 7U & 0xfffffff8);
            uVar4 = puVar10[1];
            puVar9 = puVar10 + 2;
            uVar2 = *puVar10;
          }
          uVar11 = uVar17 & 0xffffffef;
          if ((int)uVar4 < 0) {
            bVar19 = uVar2 != 0;
            uVar2 = -uVar2;
            uVar11 = uVar11 | 0x400;
            uVar4 = -uVar4 - (uint)bVar19;
LAB_0e096f86:
            uVar7 = 10;
            goto LAB_0e096f8c;
          }
          if (((uVar2 != 0 || uVar4 != 0) || ((uVar17 & 0x40) == 0)) || (uVar14 != 0))
          goto LAB_0e096f86;
          uVar17 = uVar17 & 0xffffffee;
          goto LAB_0e097006;
        default:
          if (uVar7 == 0x78) {
            uVar7 = 0x78 - uVar12 | 0x10;
            break;
          }
          iVar1 = (*pcVar5)(0x25,param_1);
          if (-1 < iVar1) {
            pcVar8 = pcVar8 + 2;
            goto LAB_0e096d46;
          }
          goto LAB_0e096f40;
        case 0x6f:
          uVar7 = 8;
          uVar12 = 0;
          break;
        case 0x70:
          uVar17 = uVar17 | 0x10;
          uVar7 = 0x10;
          uVar12 = 0x78;
          break;
        case 0x73:
          puVar9 = param_3 + 1;
          pcVar16 = (char *)*param_3;
          if (pcVar16 == (char *)0x0) {
            pcVar16 = "(null)";
          }
          if ((uVar17 & 0x40) == 0) {
            uVar14 = 0xffffffff;
          }
          uVar12 = FUN_0e0932f0(pcVar16,uVar14);
LAB_0e096e5a:
          uVar7 = uVar15;
          if ((uVar17 & 8) == 0) {
            for (; uVar12 < uVar7; uVar7 = uVar7 - 1) {
              iVar1 = (*pcVar5)(0x20,param_1);
              if (iVar1 < 0) goto LAB_0e096f40;
            }
            pcVar8 = pcVar8 + (uVar15 - uVar7);
          }
          pcVar13 = pcVar16;
          while (pcVar13 != pcVar16 + uVar12) {
            iVar1 = (*pcVar5)(*pcVar13,param_1);
            pcVar13 = pcVar13 + 1;
            if (iVar1 < 0) goto LAB_0e096f40;
          }
          iVar1 = uVar7 - uVar12;
          pcVar8 = pcVar13 + ((int)pcVar8 - (int)pcVar16);
          param_3 = puVar9;
          pcVar16 = pcVar8;
          goto LAB_0e0971c6;
        case 0x75:
          uVar17 = uVar17 & 0xffffffef;
          uVar7 = 10;
        }
        if ((uVar17 & 0x80) == 0) {
          puVar9 = param_3 + 1;
          uVar2 = *param_3;
          uVar4 = 0;
          if ((uVar17 & 0x100) != 0) {
            if ((uVar17 & 0x200) == 0) {
              uVar2 = uVar2 & 0xffff;
            }
            else {
              uVar2 = uVar2 & 0xff;
            }
            uVar4 = 0;
          }
        }
        else if ((uVar17 & 0x200) == 0) {
          puVar9 = param_3 + 1;
          uVar2 = *param_3;
          uVar4 = 0;
        }
        else {
          puVar10 = (uint *)((int)param_3 + 7U & 0xfffffff8);
          uVar4 = puVar10[1];
          puVar9 = puVar10 + 2;
          uVar2 = *puVar10;
        }
        if (uVar2 == 0 && uVar4 == 0) {
          uVar11 = uVar17 & 0xffffffe9;
          if (((uVar17 & 0x40) == 0) || (uVar14 != 0)) goto LAB_0e096f8c;
          uVar17 = uVar17 & 0xffffffe8;
LAB_0e097062:
          uVar11 = uVar17 & 0x10;
          uVar18 = local_54;
          if (uVar11 == 0) {
LAB_0e097006:
            if ((uVar17 & 0x406) != 0) {
              uVar18 = uVar18 + 1;
            }
            uVar11 = 0;
          }
          else {
            if (uVar12 != 0) goto LAB_0e0970f4;
            uVar18 = local_54 + 1;
          }
        }
        else {
          uVar11 = uVar17 & 0xfffffff9;
LAB_0e096f8c:
          iVar1 = FUN_0e09743e(uVar2,uVar4,local_40,uVar7);
          local_54 = iVar1 - (int)local_40;
          uVar17 = uVar11;
          if ((-1 < (int)(uVar11 << 0x19)) ||
             (uVar17 = uVar11 & 0xfffffffe, (int)uVar14 <= (int)local_54)) goto LAB_0e097062;
          if (uVar12 == 0) {
            uVar17 = uVar11 & 0xffffffee;
            goto LAB_0e097006;
          }
          uVar11 = uVar11 & 0x10;
          if (uVar11 == 0) goto LAB_0e097006;
LAB_0e0970f4:
          uVar18 = uVar18 + 2;
        }
        if (-1 < (int)(uVar17 << 0x1c)) {
          uVar7 = uVar18;
          if (((int)(uVar17 << 0x1f) < 0) && (uVar14 = local_54, (int)uVar18 < (int)uVar15)) {
            iVar1 = uVar15 - uVar18;
            uVar18 = uVar15;
            uVar7 = uVar15;
            uVar14 = iVar1 + local_54;
          }
          for (; (int)uVar18 < (int)uVar15; uVar18 = uVar18 + 1) {
            local_44 = uVar11;
            iVar1 = (*pcVar5)(0x20,param_1);
            if (iVar1 < 0) goto LAB_0e096f40;
            uVar11 = local_44;
          }
          pcVar8 = pcVar8 + (uVar18 - uVar7);
        }
        if (uVar11 == 0) {
          pcVar16 = pcVar8;
          if ((uVar17 & 0x406) != 0) {
            pcVar8 = pcVar8 + 1;
            if ((uVar17 & 2) == 0) {
              uVar12 = 0x20;
            }
            else {
              uVar12 = 0x2b;
            }
            if ((uVar17 & 0x400) != 0) {
              uVar12 = 0x2d;
            }
            goto LAB_0e097168;
          }
        }
        else {
          iVar1 = (*pcVar5)(0x30,param_1);
          if (iVar1 < 0) goto LAB_0e096f40;
          if (uVar12 != 0) {
            pcVar8 = pcVar8 + 2;
LAB_0e097168:
            iVar1 = (*pcVar5)(uVar12,param_1);
            pcVar16 = pcVar8;
            goto joined_r0x0e09716e;
          }
          pcVar8 = pcVar8 + 1;
          pcVar16 = pcVar8;
        }
        while (uVar12 = local_54, (int)local_54 < (int)(pcVar16 + (uVar14 - (int)pcVar8))) {
          pcVar8 = pcVar8 + 1;
          iVar1 = (*pcVar5)(0x30,param_1);
joined_r0x0e09716e:
          if (iVar1 < 0) goto LAB_0e096f40;
        }
        while (uVar12 != 0) {
          iVar1 = (*pcVar5)(local_40[uVar12 - 1],param_1);
          uVar12 = uVar12 - 1;
          if (iVar1 < 0) goto LAB_0e096f40;
        }
        iVar1 = uVar15 - uVar18;
        pcVar8 = pcVar8 + local_54;
        param_3 = puVar9;
        pcVar16 = pcVar8;
LAB_0e0971c6:
        while (param_2 = local_4c, 0 < (int)(pcVar16 + (iVar1 - (int)pcVar8))) {
          pcVar8 = pcVar8 + 1;
          iVar3 = (*pcVar5)(0x20,param_1);
          if (iVar3 < 0) goto LAB_0e096f40;
        }
      }
      local_4c = param_2 + 1;
LAB_0e096d44:
      pcVar8 = pcVar8 + 1;
LAB_0e096d46:
      iVar1 = (*pcVar5)(uVar12,param_1);
      param_2 = local_4c;
    } while (-1 < iVar1);
LAB_0e096f40:
    *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) | 4;
  }
  return (char *)0xffffffff;
}


