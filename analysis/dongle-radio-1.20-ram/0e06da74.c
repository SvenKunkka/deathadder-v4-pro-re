/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06da74. Types and names are inferred; NOT original source. */

void FUN_0e06da74(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (*(char *)((int)param_1 + 0xd) < '\0') {
    piVar1 = (int *)param_1[1];
    *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0x7f;
    iVar3 = *param_1;
    *piVar1 = iVar3;
    *(int **)(iVar3 + 4) = piVar1;
    *param_1 = 0;
    param_1[1] = 0;
  }
  FUN_0e06d9cc(DAT_23007170 == param_1);
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) | 2;
  if (param_2 != (undefined4 *)0x0) {
    param_1[2] = (int)param_2;
    puVar4 = (undefined4 *)*param_2;
    if (param_2 != puVar4) {
      for (; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {
        if ((*(char *)((int)param_1 + 0xe) != *(char *)((int)puVar4 + 0xe)) &&
           (*(char *)((int)param_1 + 0xe) < *(char *)((int)puVar4 + 0xe))) {
          puVar2 = (undefined4 *)puVar4[1];
          *param_1 = (int)puVar4;
          param_1[1] = (int)puVar2;
          *puVar2 = param_1;
          puVar4[1] = param_1;
          return;
        }
        puVar2 = (undefined4 *)param_2[1];
        if (puVar4 == puVar2) goto LAB_0e06dad8;
      }
    }
    puVar2 = (undefined4 *)param_2[1];
LAB_0e06dad8:
    *param_1 = (int)param_2;
    param_1[1] = (int)puVar2;
    *puVar2 = param_1;
    param_2[1] = param_1;
  }
  return;
}


