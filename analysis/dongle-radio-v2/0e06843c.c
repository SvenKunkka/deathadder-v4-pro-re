/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06843c. Types and names are inferred; NOT original source. */

void FUN_0e06843c(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  uint local_18;
  uint uStack_14;
  
  FUN_0e0696e0(&local_18);
  puVar1 = DAT_0e06846c;
  if (param_4 < uStack_14 || uStack_14 - param_4 < (uint)(param_3 <= local_18)) {
    uVar2 = *DAT_0e06846c;
    DAT_0e06846c[1] = param_4;
    *puVar1 = param_3;
    FUN_0e06e898(param_3 - uVar2);
    return;
  }
  return;
}


