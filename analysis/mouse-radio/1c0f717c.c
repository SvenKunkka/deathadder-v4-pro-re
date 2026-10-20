/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f717c. Types and names are inferred; NOT original source. */

undefined4 FUN_1c0f717c(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  char cVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  
  FUN_1c100d84(param_1 + 4,param_2,0xffffffff,0xffffffff,param_4);
  iVar3 = *(int *)(param_1 + 100);
  iVar8 = *(int *)(param_1 + 0x68);
  if (((iVar3 == 0) || (iVar8 == 0)) || ((int)((uint)*(byte *)(param_1 + 0x60) << 0x1f) < 0)) {
    uVar7 = 0xffffffff;
  }
  else {
    if (*(int *)(param_1 + 0x48) == 0) {
      *(int *)(param_1 + 0x48) = param_1 + 0x48;
      *(int *)(param_1 + 0x4c) = param_1 + 0x48;
    }
    if (*param_2 == 0) {
      cVar5 = *(char *)((int)param_2 + 0x11);
      if (cVar5 == '\x0f') {
        piVar6 = *(int **)(param_1 + 0x4c);
        param_2[1] = (int)piVar6;
        *param_2 = param_1 + 0x48;
        *piVar6 = (int)param_2;
        *(int **)(param_1 + 0x4c) = param_2;
        cVar5 = *(char *)((int)param_2 + 0x11);
      }
      if (cVar5 == '\x03') {
        piVar6 = *(int **)(param_1 + 0x48);
        if ((int *)(param_1 + 0x48) != piVar6) {
          for (; piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
            while (*(char *)((int)piVar6 + 0x11) == '\x03') {
              bVar1 = *(byte *)(piVar6 + 2);
              if ((piVar6 == *(int **)(param_1 + 0x4c)) ||
                 (piVar6 = (int *)*piVar6, piVar6 == (int *)0x0)) {
                *(byte *)(param_2 + 2) = bVar1 + 1;
                goto LAB_1c0f7234;
              }
              if ((*(char *)((int)piVar6 + 0x11) != '\x03') ||
                 ((uint)bVar1 != *(byte *)(piVar6 + 2) - 1)) {
                *(byte *)(param_2 + 2) = bVar1 + 1;
                piVar4 = (int *)piVar6[1];
                *param_2 = (int)piVar6;
                param_2[1] = (int)piVar4;
                *piVar4 = (int)param_2;
                piVar6[1] = (int)param_2;
                goto LAB_1c0f723e;
              }
            }
            if (piVar6 == *(int **)(param_1 + 0x4c)) break;
          }
        }
        *(undefined1 *)(param_2 + 2) = 0;
LAB_1c0f7234:
        piVar6 = *(int **)(param_1 + 0x4c);
        *param_2 = param_1 + 0x48;
        param_2[1] = (int)piVar6;
        *piVar6 = (int)param_2;
        *(int **)(param_1 + 0x4c) = param_2;
LAB_1c0f723e:
        cVar5 = *(char *)((int)param_2 + 9);
        if (cVar5 == '\x02') {
          iVar2 = param_2[2];
          *(char *)(iVar8 + 0xf) = (char)iVar2;
          *(char *)(iVar3 + 0xf) = (char)iVar2;
        }
        else if (cVar5 == '\x03') {
          iVar2 = param_2[2];
          *(char *)(iVar8 + 0x10) = (char)iVar2;
          *(char *)(iVar3 + 0x10) = (char)iVar2;
        }
        else if (cVar5 == '\x01') {
          iVar2 = param_2[2];
          *(char *)(iVar8 + 0xe) = (char)iVar2;
          *(char *)(iVar3 + 0xe) = (char)iVar2;
        }
      }
      uVar7 = 0;
    }
    else {
      uVar7 = 0xffffff88;
    }
  }
  FUN_1c100e80(param_1 + 4);
  return uVar7;
}


