/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0551d0. Types and names are inferred; NOT original source. */

void FUN_0e0551d0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  dword dVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  
  thunk_FUN_0e06f3aa(param_1,0,0x20,param_4,param_4);
  *param_1 = DAT_23003244;
  uVar2 = DAT_23003230;
  param_1[1] = DAT_2300324c;
  dVar1 = RADIO_S_BASE1;
  param_1[2] = dVar1;
  uVar3 = DAT_230033e8;
  dVar1 = RADIO_S_PREFIX0;
  param_1[3] = dVar1;
  *(char *)((int)param_1 + 0x13) = (char)uVar2;
  *(char *)(param_1 + 6) = (char)uVar3;
  *(char *)((int)param_1 + 0x19) = (char)DAT_23003468;
  *(char *)((int)param_1 + 0x1a) = (char)DAT_230034b0;
  *(char *)((int)param_1 + 0x1b) = (char)DAT_230034b2;
  *(char *)(param_1 + 7) = (char)DAT_230034b4;
  *(char *)((int)param_1 + 0x1d) = (char)DAT_230034b6;
  *(char *)((int)param_1 + 0x1e) = (char)DAT_230034b8;
  return;
}


