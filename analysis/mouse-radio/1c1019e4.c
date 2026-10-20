/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c1019e4. Types and names are inferred; NOT original source. */

void FUN_1c1019e4(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = DAT_1c101a48;
  if (((*(char *)((int)param_1 + 0xd) < '\0') || ((*(byte *)((int)param_1 + 0xd) & 0x1f) != 0)) ||
     (param_1[6] != 0)) {
    return;
  }
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) | 0x80;
  puVar2 = (undefined4 *)(iVar1 + 0x1c);
  puVar3 = (undefined4 *)*puVar2;
  puVar4 = *(undefined4 **)(iVar1 + 0x20);
  if (puVar3 == puVar2) {
    puVar3 = (undefined4 *)0x0;
  }
  for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
    if ((*(char *)((int)param_1 + 0xe) != *(char *)((int)puVar3 + 0xe)) &&
       (*(char *)((int)param_1 + 0xe) < *(char *)((int)puVar3 + 0xe))) {
      puVar2 = (undefined4 *)puVar3[1];
      *param_1 = (int)puVar3;
      param_1[1] = (int)puVar2;
      *puVar2 = param_1;
      puVar3[1] = param_1;
      goto LAB_1c101a32;
    }
    if (puVar3 == puVar4) break;
  }
  *param_1 = (int)puVar2;
  param_1[1] = (int)puVar4;
  *puVar4 = param_1;
  *(int **)(iVar1 + 0x20) = param_1;
LAB_1c101a32:
  FUN_1c1019a4(0);
  return;
}


