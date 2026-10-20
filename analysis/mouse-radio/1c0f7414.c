/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f7414. Types and names are inferred; NOT original source. */

/* WARNING: Control flow encountered bad instruction data */

uint FUN_1c0f7414(int param_1,int param_2,uint param_3)

{
  ushort uVar1;
  byte bVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 extraout_r3;
  uint uVar9;
  int iVar10;
  int iVar11;
  
  uVar7 = (uint)*(byte *)(param_2 + 0x18);
  if ((*(byte *)(param_2 + 0x18) & 0x7f) != 0) {
    return 0xfffffffb;
  }
  bVar2 = *(byte *)(param_2 + 0x19);
  if ((param_3 == 0) || (param_3 == 0xfffffff4)) {
    if ((bVar2 & 1) != 0) goto LAB_1c0f7468;
    if ((bVar2 & 4) == 0) goto LAB_1c0f7470;
    if (uVar7 == 0) goto LAB_1c0f745a;
  }
  else {
    if ((bVar2 & 1) == 0) {
      if (param_3 != 0xffffff8f) {
        FUN_1c0f67fc(param_2);
        return param_3;
      }
LAB_1c0f745a:
      FUN_1c0f67fc(param_2);
      return uVar7 & 0xffffff7f;
    }
LAB_1c0f7468:
    if (uVar7 == 0) {
      iVar10 = *(int *)(*(int *)(param_1 + 0x18) + 0x10);
      if (7 < *(ushort *)(param_2 + 0x10)) {
        uVar8 = (*(undefined4 **)(param_2 + 0xc))[1];
        *(undefined4 *)(param_1 + 0x20) = **(undefined4 **)(param_2 + 0xc);
        *(undefined4 *)(param_1 + 0x24) = uVar8;
        if (*(int *)(param_2 + 4) != 0) {
          uVar7 = (uint)*(byte *)(*(int *)(param_2 + 4) + 0x19);
          if (*(short *)(param_1 + 0x26) == 0) {
            iVar11 = uVar7 << 0x1d;
          }
          else {
            iVar11 = uVar7 << 0x1e;
          }
          if (iVar11 < 0) {
            iVar11 = FUN_1c0f6884(0);
            *(undefined4 *)(iVar10 + 0xa8) = 0;
            if (iVar11 == 0) goto LAB_1c0f7470;
            iVar4 = FUN_1c103614();
            iVar10 = DAT_1c0f7804;
            bVar2 = *(byte *)(param_1 + 0x20);
            *(undefined4 *)(DAT_1c0f7804 + iVar4) = extraout_r3;
            if ((bVar2 & 0x60) == 0) {
              uVar3 = *(undefined1 *)(param_1 + 0x21);
              if (*(short *)(param_1 + 0x26) == 0) {
                switch(uVar3) {
                case 1:
                    /* WARNING: Bad instruction - Truncating control flow here */
                  halt_baddata();
                case 2:
                case 4:
                case 6:
                case 7:
                case 8:
                case 10:
                  goto switchD_1c0f757c_caseD_3;
                case 3:
                    /* WARNING: Bad instruction - Truncating control flow here */
                  halt_baddata();
                case 5:
switchD_1c0f757c_caseD_5:
                    /* WARNING: Bad instruction - Truncating control flow here */
                  halt_baddata();
                case 9:
switchD_1c0f757c_caseD_9:
                    /* WARNING: Bad instruction - Truncating control flow here */
                  halt_baddata();
                case 0xb:
                    /* WARNING: Bad instruction - Truncating control flow here */
                  halt_baddata();
                }
              }
              else if ((char)bVar2 < '\0') {
                switch(uVar3) {
                case 0:
                    /* WARNING: Bad instruction - Truncating control flow here */
                  halt_baddata();
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 7:
                case 9:
                  goto switchD_1c0f757c_caseD_3;
                case 6:
                    /* WARNING: Bad instruction - Truncating control flow here */
                  halt_baddata();
                case 8:
                    /* WARNING: Bad instruction - Truncating control flow here */
                  halt_baddata();
                case 10:
                    /* WARNING: Bad instruction - Truncating control flow here */
                  halt_baddata();
                }
              }
              else {
                switch(uVar3) {
                case 3:
                case 4:
                case 6:
                case 7:
                case 8:
                case 10:
                case 0xb:
switchD_1c0f757c_caseD_3:
                    /* WARNING: Bad instruction - Truncating control flow here */
                  halt_baddata();
                case 5:
                  goto switchD_1c0f757c_caseD_5;
                case 9:
                  goto switchD_1c0f757c_caseD_9;
                }
              }
switchD_1c0f757c_default:
              iVar4 = FUN_1c103614();
              *(undefined4 *)(iVar10 + iVar4) = 0xffffff7a;
            }
            else {
              if ((bVar2 & 0x7f) >> 5 == 3) goto switchD_1c0f757c_default;
              uVar7 = FUN_1c0f7394(param_1,iVar11);
              if (uVar7 != 0) {
                FUN_1c0f67fc(iVar11);
                return uVar7;
              }
              iVar4 = FUN_1c103614();
              if (*(int *)(iVar10 + iVar4) == 0) {
                *(undefined4 *)(param_1 + 0x28) = 1;
                uVar7 = 0;
                if ((*(short *)(param_1 + 0x26) != 0) &&
                   (uVar7 = (uint)(*(byte *)(param_1 + 0x20) >> 7), uVar7 == 0)) {
                  do {
                    iVar11 = FUN_1c0f6884(0,iVar11);
                    if (iVar11 == 0) goto LAB_1c0f7470;
                    uVar7 = (uint)*(byte *)(iVar11 + 0x19);
                  } while (-1 < (int)(uVar7 << 0x1d));
                }
                if ((*(byte *)(iVar11 + 0x18) & 0x7f) != 0) {
                  return 0xffffffea;
                }
                uVar5 = (uint)*(byte *)(iVar11 + 0x18) << 0x18;
                if ((int)uVar5 < 0) {
                  iVar10 = FUN_1c0f7004();
                  if (iVar10 != 0) {
                    return 0xffffffff;
                  }
                  uVar9 = (uint)*(ushort *)(iVar11 + 0x10);
                  uVar5 = (uint)*(ushort *)(param_1 + 0x26);
                  if (uVar9 != 0) {
                    if (uVar5 <= uVar9) {
                      uVar9 = uVar5;
                    }
                    if (((uVar9 < uVar5) && ((uVar9 & 0x3f) == 0)) &&
                       (*(char *)(iVar11 + 0x18) < '\0')) {
                      *(byte *)(iVar11 + 0x19) = *(byte *)(iVar11 + 0x19) | 8;
                    }
                  }
                }
                uVar7 = FUN_1c0f96d4(*(undefined4 *)(param_1 + 0x18),iVar11,uVar5,uVar7);
                return uVar7;
              }
            }
            FUN_1c0f67fc(iVar11);
            goto LAB_1c0f7470;
          }
        }
      }
      FUN_1c0f67fc(param_2);
      goto LAB_1c0f7470;
    }
    if ((bVar2 & 4) == 0) goto LAB_1c0f7470;
  }
  if (uVar7 == 0x80) {
    FUN_1c0f67fc(param_2);
    uVar7 = 0;
    if (*(int *)(param_1 + 0x28) != 1) {
      return 0;
    }
    if (*(char *)(param_1 + 0x35) == '\0') {
      return 0;
    }
    cVar6 = *(char *)(param_1 + 0x21);
    if (cVar6 == '\x05') {
      iVar11 = *(int *)(param_1 + 0x18);
      uVar3 = *(undefined1 *)(param_1 + 0x22);
      iVar10 = *(int *)(iVar11 + 8);
      if (*(int *)(*(int *)(iVar11 + 0x10) + 0xa0) << 0x1e < 0) {
        (**(code **)(iVar10 + 0x3c))(iVar11);
        uVar7 = (**(code **)(iVar10 + 0x24))(iVar11,uVar3);
        (**(code **)(iVar10 + 0x40))(iVar11);
        cVar6 = *(char *)(param_1 + 0x21);
      }
      else {
        uVar7 = 0xffffffff;
        cVar6 = *(char *)(param_1 + 0x21);
      }
    }
    if ((cVar6 == '\x03') && (*(short *)(param_1 + 0x22) == 2)) {
      iVar11 = *(int *)(param_1 + 0x18);
      uVar1 = *(ushort *)(param_1 + 0x24);
      iVar10 = *(int *)(iVar11 + 8);
      if (*(int *)(*(int *)(iVar11 + 0x10) + 0xa0) << 0x1e < 0) {
        if (*(int *)(iVar10 + 0x28) == 0) {
          uVar7 = 0xffffff7a;
        }
        else {
          (**(code **)(iVar10 + 0x3c))(iVar11);
          uVar7 = (**(code **)(iVar10 + 0x28))(iVar11,uVar1 >> 8,0);
          (**(code **)(iVar10 + 0x40))(iVar11);
        }
      }
      else {
        uVar7 = 0xffffffff;
      }
    }
    *(undefined1 *)(param_1 + 0x35) = 0;
    return uVar7;
  }
LAB_1c0f7470:
  if ((*(short *)(param_1 + 0x26) == 0) || (*(char *)(param_1 + 0x20) < '\0')) {
    uVar7 = FUN_1c0f9608(*(undefined4 *)(param_1 + 0x18),0x80);
  }
  else {
    uVar7 = FUN_1c0f9608(*(undefined4 *)(param_1 + 0x18),(uint)(param_3 != 0xfffffff4) << 7);
  }
  *(undefined4 *)(param_1 + 0x28) = 0;
  return uVar7;
}


