/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e090f80. Types and names are inferred; NOT original source. */

undefined4 FUN_0e090f80(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4 [12];
  uint local_74;
  undefined4 local_6c [24];
  
  if (param_1 == (undefined4 *)0x0) {
    return 0xffffffea;
  }
  if (param_2 == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    FUN_0e097512(&local_ac,0,0x40);
    local_74 = param_2 - 1;
    if (local_74 < 7) {
      local_ac = *param_1;
      local_a8 = param_1[1];
      if (local_74 != 0) {
        puVar5 = &local_ac;
        puVar4 = param_1 + param_2 * 2 + -2;
        do {
          puVar1 = param_1 + 2;
          uVar3 = param_1[3];
          param_1 = param_1 + 2;
          puVar5[2] = *puVar1;
          puVar5[3] = uVar3;
          puVar5 = puVar5 + 2;
        } while (param_1 != puVar4);
      }
      iVar2 = FUN_0e088d38(DAT_0e090ff0,&local_ac,local_6c,0);
      uVar3 = DAT_0e090ff4;
      if (iVar2 == 0) {
        uVar3 = local_6c[0];
      }
    }
    else {
      uVar3 = 0xfffffff4;
    }
  }
  return uVar3;
}


