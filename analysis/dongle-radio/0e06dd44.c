/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06dd44. Types and names are inferred; NOT original source. */

void FUN_0e06dd44(int *param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 *puVar6;
  
  bVar1 = *(byte *)((int)param_1 + 0xd);
  if (*(char *)((int)param_1 + 0xd) < '\0') {
    iVar2 = *param_1;
    piVar5 = (int *)param_1[1];
    *(byte *)((int)param_1 + 0xd) = bVar1 & 0x7f;
    *piVar5 = iVar2;
    *(int **)(iVar2 + 4) = piVar5;
    bVar1 = *(byte *)((int)param_1 + 0xd);
    *param_1 = 0;
    param_1[1] = 0;
  }
  iVar2 = DAT_0e06ddbc;
  *(byte *)((int)param_1 + 0xd) = bVar1 | 0x80;
  puVar3 = (undefined4 *)(iVar2 + 0x18);
  puVar4 = (undefined4 *)*puVar3;
  puVar6 = *(undefined4 **)(iVar2 + 0x1c);
  if (puVar4 == puVar3) {
    puVar4 = (undefined4 *)0x0;
  }
  for (; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {
    if ((*(char *)((int)param_1 + 0xe) != *(char *)((int)puVar4 + 0xe)) &&
       (*(char *)((int)param_1 + 0xe) < *(char *)((int)puVar4 + 0xe))) {
      puVar3 = (undefined4 *)puVar4[1];
      *param_1 = (int)puVar4;
      param_1[1] = (int)puVar3;
      *puVar3 = param_1;
      puVar4[1] = param_1;
      goto LAB_0e06dda0;
    }
    if (puVar4 == puVar6) break;
  }
  *param_1 = (int)puVar3;
  param_1[1] = (int)puVar6;
  *puVar6 = param_1;
  *(int **)(iVar2 + 0x1c) = param_1;
LAB_0e06dda0:
  FUN_0e06da68(*(int **)(iVar2 + 8) == param_1);
  return;
}


