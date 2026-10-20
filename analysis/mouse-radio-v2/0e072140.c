/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e072140. Types and names are inferred; NOT original source. */

void FUN_0e072140(uint param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

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
  FUN_0e06f5c4(local_28);
  FUN_0e06d5c0(param_1 & 0xffff);
  puVar2 = DAT_0e072180;
  iVar1 = DAT_0e07217c;
  *(undefined2 *)(DAT_0e07217c + 6) = param_2;
  *(undefined2 *)(iVar1 + 8) = param_3;
  *puVar2 = 0;
  *(undefined1 *)(iVar1 + 0xb) = 1;
  return;
}


