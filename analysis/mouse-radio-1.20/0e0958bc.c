/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0958bc. Types and names are inferred; NOT original source. */

void FUN_0e0958bc(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (((*(char *)((int)param_1 + 0xd) < '\0') || ((*(byte *)((int)param_1 + 0xd) & 0x1f) != 0)) ||
     (param_1[6] != 0)) {
    return;
  }
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) | 0x80;
  puVar2 = DAT_23007668;
  if ((undefined4 **)DAT_23007668 == &DAT_23007668) {
    puVar2 = (undefined4 *)0x0;
  }
  for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
    if ((*(char *)((int)param_1 + 0xe) != *(char *)((int)puVar2 + 0xe)) &&
       (*(char *)((int)param_1 + 0xe) < *(char *)((int)puVar2 + 0xe))) {
      puVar1 = (undefined4 *)puVar2[1];
      *param_1 = puVar2;
      param_1[1] = puVar1;
      *puVar1 = param_1;
      puVar2[1] = param_1;
      goto LAB_0e09590a;
    }
    if (puVar2 == DAT_2300766c) break;
  }
  *param_1 = &DAT_23007668;
  param_1[1] = DAT_2300766c;
  *DAT_2300766c = param_1;
  DAT_2300766c = param_1;
LAB_0e09590a:
  FUN_0e09587c(0);
  return;
}


