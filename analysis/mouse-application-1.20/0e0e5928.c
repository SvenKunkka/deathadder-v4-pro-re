/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e5928. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0e5928(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (((*(char *)((int)param_1 + 0xd) < '\0') || ((*(byte *)((int)param_1 + 0xd) & 0x1f) != 0)) ||
     (param_1[6] != 0)) {
    return;
  }
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) | 0x80;
  puVar2 = (undefined4 *)0x0;
  if (_DAT_2f0118f0 != (undefined4 *)&DAT_2f0118f0) {
    puVar2 = _DAT_2f0118f0;
  }
  for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
    if ((*(char *)((int)param_1 + 0xe) != *(char *)((int)puVar2 + 0xe)) &&
       (*(char *)((int)param_1 + 0xe) < *(char *)((int)puVar2 + 0xe))) {
      puVar1 = (undefined4 *)puVar2[1];
      *param_1 = puVar2;
      param_1[1] = puVar1;
      *puVar1 = param_1;
      puVar2[1] = param_1;
      goto LAB_0e0e5978;
    }
    if (_DAT_2f0118f4 == puVar2) break;
  }
  *param_1 = &DAT_2f0118f0;
  param_1[1] = _DAT_2f0118f4;
  *_DAT_2f0118f4 = param_1;
  _DAT_2f0118f4 = param_1;
LAB_0e0e5978:
  FUN_0e0e58bc(0);
  return;
}


