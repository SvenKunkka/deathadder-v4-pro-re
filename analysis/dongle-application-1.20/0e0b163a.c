/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b163a. Types and names are inferred; NOT original source. */

void FUN_0e0b163a(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int extraout_r1;
  code *pcVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  int iVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int local_30;
  undefined4 local_2c [2];
  
  if (*(int *)(param_1 + 0x6c) < 0) {
    iVar9 = param_1 + -0x8c;
    if (*(char *)(param_1 + 0x70) == '\0') {
      iVar1 = param_1 + -0x14;
      FUN_0e0af598(iVar1,param_2,0xffffffff,0xffffffff);
      puVar8 = (ushort *)(param_1 + 0x62);
      uVar6 = 0;
      do {
        puVar8 = puVar8 + 1;
        if (*puVar8 != 0xffff) {
          thunk_FUN_0e0af688(iVar1);
          iVar2 = *(int *)(param_1 + -0x8c);
          iVar7 = *(int *)(iVar2 + 0x14) * (uint)*puVar8 + *(int *)(iVar2 + 0x10) + 4;
          FUN_0e0b287c(iVar7,((*(int *)(iVar2 + 0x18) * *(int *)(iVar2 + 0x14) +
                              *(int *)(iVar2 + 0x10)) - iVar7) + -1);
          iVar2 = 0;
          piVar5 = (int *)(param_1 + 0x24);
          do {
            iVar3 = *piVar5;
            if ((iVar3 == 1) &&
               (uVar10 = FUN_0e0b2858(*(undefined4 *)piVar5[-1],iVar7),
               iVar3 = (int)((ulonglong)uVar10 >> 0x20), (int)uVar10 == 0)) {
              *(char *)(param_1 + iVar2 * 0x10 + 0x2c) = (char)uVar6;
              *(char *)(param_1 + 0x60 + uVar6) = (char)iVar2;
              iVar3 = *piVar5;
              if (iVar3 == 1) {
                *piVar5 = 3;
                iVar2 = *(int *)(param_1 + iVar2 * 0x10 + 0x20);
                pcVar4 = *(code **)(iVar2 + 8);
                if (pcVar4 != (code *)0x0) {
                  (*pcVar4)(*(undefined4 *)(iVar2 + 0x14));
                }
                FUN_0e0b146e(iVar9,iVar7,3,uVar6 & 0xff);
                iVar3 = extraout_r1;
              }
              FUN_0e0af598(iVar1,iVar3,0xffffffff,0xffffffff);
              *puVar8 = 0xffff;
              goto LAB_0e0b17bc;
            }
            iVar2 = iVar2 + 1;
            piVar5 = piVar5 + 4;
          } while (iVar2 != 4);
          FUN_0e0af598(iVar1,iVar3,0xffffffff,0xffffffff);
        }
LAB_0e0b17bc:
        uVar6 = uVar6 + 1;
      } while (uVar6 != 4);
      thunk_FUN_0e0af688(iVar1);
    }
    else {
      piVar5 = (int *)(param_1 + 0x24);
      do {
        if (*piVar5 == 1) {
          *piVar5 = 2;
          iVar1 = FUN_0e0ab7e4(*(undefined4 *)piVar5[-1]);
          uVar11 = 0xffffffff;
          uVar12 = 0xffffffff;
          local_30 = iVar1 + 1;
          iVar2 = FUN_0e0b1326(iVar9,&local_30,local_2c);
          if (-1 < iVar2) {
            FUN_0e0ab7d4(local_2c[0],*(undefined4 *)piVar5[-1],(undefined4 *)piVar5[-1],iVar2,uVar11
                         ,uVar12);
            iVar1 = FUN_0e0b1532(iVar9,2,(char)piVar5[2],iVar2,iVar1 + 1);
            if (-1 < iVar1) goto LAB_0e0b16d4;
          }
          *piVar5 = 0;
        }
LAB_0e0b16d4:
        piVar5 = piVar5 + 4;
      } while (piVar5 != (int *)(param_1 + 100));
    }
    piVar5 = (int *)(param_1 + 0x28);
    do {
      if (*piVar5 == 2) {
        *piVar5 = 0;
        pcVar4 = *(code **)(piVar5[-2] + 8);
        if (pcVar4 != (code *)0x0) {
          (*pcVar4)(*(undefined4 *)(piVar5[-2] + 0x14));
        }
      }
      piVar5 = piVar5 + 4;
    } while (piVar5 != (int *)(param_1 + 0x68));
  }
  return;
}


