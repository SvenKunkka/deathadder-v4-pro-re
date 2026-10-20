/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0de140. Types and names are inferred; NOT original source. */

void FUN_1c0de140(uint param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  uint local_28 [2];
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  
  local_28[1] = 7;
  local_28[0] = param_1;
  local_20 = param_2;
  local_1e = param_3;
  local_1c = param_4;
  FUN_1c0db5c4(local_28);
  FUN_1c0d95c0(param_1 & 0xffff);
  puVar2 = DAT_1c0de180;
  iVar1 = DAT_1c0de17c;
  *(undefined2 *)(DAT_1c0de17c + 6) = param_2;
  *(undefined2 *)(iVar1 + 8) = param_3;
  *puVar2 = 0;
  *(undefined1 *)(iVar1 + 0xb) = 1;
  return;
}


