/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05cc44. Types and names are inferred; NOT original source. */

void FUN_0e05cc44(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  sbyte *psVar1;
  uint *puVar2;
  undefined4 extraout_r1;
  uint uVar3;
  
  psVar1 = DAT_0e05cca0;
  FUN_0e05c8f4();
  if (param_1 == 0) {
    FUN_0e06a7fc(*psVar1,DAT_0e05cca8,DAT_0e05ccb4);
    uVar3 = 4;
  }
  else {
    FUN_0e06a7fc(*psVar1,DAT_0e05cca8,DAT_0e05cca4);
    uVar3 = 0x10;
  }
  puVar2 = DAT_0e05ccac;
  *DAT_0e05ccac = *DAT_0e05ccac | uVar3;
  FUN_0e06a73c(*psVar1,DAT_0e05ccb0);
  *puVar2 = *puVar2 | 0x10000;
  FUN_0e06abc4(1 << *psVar1,extraout_r1,0,param_4);
  return;
}


