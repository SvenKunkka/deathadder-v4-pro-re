/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e095b58. Types and names are inferred; NOT original source. */

void FUN_0e095b58(int *param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  bVar1 = *(byte *)((int)param_1 + 0xd);
  if (*(char *)((int)param_1 + 0xd) < '\0') {
    iVar2 = *param_1;
    piVar4 = (int *)param_1[1];
    *(byte *)((int)param_1 + 0xd) = bVar1 & 0x7f;
    *piVar4 = iVar2;
    *(int **)(iVar2 + 4) = piVar4;
    bVar1 = *(byte *)((int)param_1 + 0xd);
    *param_1 = 0;
    param_1[1] = 0;
  }
  *(byte *)((int)param_1 + 0xd) = bVar1 | 0x80;
  piVar4 = DAT_23007668;
  if ((int **)DAT_23007668 == &DAT_23007668) {
    piVar4 = (int *)0x0;
  }
  for (; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
    if ((*(char *)((int)param_1 + 0xe) != *(char *)((int)piVar4 + 0xe)) &&
       (*(char *)((int)param_1 + 0xe) < *(char *)((int)piVar4 + 0xe))) {
      puVar3 = (undefined4 *)piVar4[1];
      *param_1 = (int)piVar4;
      param_1[1] = (int)puVar3;
      *puVar3 = param_1;
      piVar4[1] = (int)param_1;
      goto LAB_0e095bb4;
    }
    if (piVar4 == DAT_2300766c) break;
  }
  *param_1 = (int)&DAT_23007668;
  param_1[1] = (int)DAT_2300766c;
  *DAT_2300766c = (int)param_1;
  DAT_2300766c = param_1;
LAB_0e095bb4:
  FUN_0e09587c(DAT_23007654 == param_1);
  return;
}


