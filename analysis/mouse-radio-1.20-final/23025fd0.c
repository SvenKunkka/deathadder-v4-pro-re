/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23025fd0. Types and names are inferred; NOT original source. */

undefined4 ram_candidate_23025fd0(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar4 = *(int *)(param_1 + 0x10);
  puVar5 = *(undefined4 **)(iVar4 + 4);
  if (puVar5 == (undefined4 *)0x0) {
LAB_23025fec:
    if (param_3 == 0) {
      return 0xffffffea;
    }
  }
  else {
    puVar2 = puVar5;
    if (puVar5 == param_2) {
      uVar3 = *param_2;
      *(undefined4 *)(iVar4 + 4) = uVar3;
      if (param_2 == *(undefined4 **)(iVar4 + 8)) {
        *(undefined4 *)(iVar4 + 8) = uVar3;
      }
    }
    else {
      do {
        puVar1 = puVar2;
        puVar2 = (undefined4 *)*puVar1;
        if (puVar2 == (undefined4 *)0x0) goto LAB_23025fec;
      } while (param_2 != puVar2);
      *puVar1 = *param_2;
      if (param_2 == *(undefined4 **)(iVar4 + 8)) {
        *(undefined4 **)(iVar4 + 8) = puVar1;
      }
    }
    *param_2 = 0;
    if (param_3 == 0) {
      return 0;
    }
    puVar5 = *(undefined4 **)(iVar4 + 4);
  }
  *param_2 = puVar5;
  *(undefined4 **)(iVar4 + 4) = param_2;
  if (*(int *)(iVar4 + 8) == 0) {
    *(undefined4 **)(iVar4 + 8) = param_2;
  }
  return 0;
}


