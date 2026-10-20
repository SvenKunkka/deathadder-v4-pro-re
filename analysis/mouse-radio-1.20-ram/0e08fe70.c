/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08fe70. Types and names are inferred; NOT original source. */

undefined4 FUN_0e08fe70(int param_1,int param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *local_20;
  int local_1c;
  
  iVar3 = *(int *)(param_1 + 8);
  *param_3 = 0;
  param_3[2] = 0;
  (**(code **)(iVar3 + 0x10))(param_1,&local_20,&local_1c);
  if (local_1c != 0) {
    iVar3 = param_3[2];
    iVar4 = *param_3;
    do {
      local_1c = local_1c + -1;
      uVar2 = local_20[1];
      param_3[1] = uVar2;
      if (param_2 == 0) {
        uVar1 = -iVar3;
      }
      else {
        uVar1 = (uint)(param_2 - iVar4) / uVar2;
      }
      if (*local_20 <= uVar1) {
        uVar1 = *local_20;
      }
      iVar4 = uVar1 * uVar2 + iVar4;
      iVar3 = iVar3 + uVar1;
      param_3[2] = iVar3;
      *param_3 = iVar4;
      if (uVar1 < *local_20) {
        return 0;
      }
      local_20 = local_20 + 2;
    } while (local_1c != 0);
  }
  return 0xffffffea;
}


