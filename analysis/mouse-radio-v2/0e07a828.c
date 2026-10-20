/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07a828. Types and names are inferred; NOT original source. */

void FUN_0e07a828(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  sbyte *psVar1;
  uint *puVar2;
  undefined4 extraout_r1;
  uint uVar3;
  
  psVar1 = DAT_0e07a884;
  FUN_0e07a4d8();
  if (param_1 == 0) {
    FUN_0e092750(*psVar1,DAT_0e07a88c,DAT_0e07a898);
    uVar3 = 4;
  }
  else {
    FUN_0e092750(*psVar1,DAT_0e07a88c,DAT_0e07a888);
    uVar3 = 0x10;
  }
  puVar2 = DAT_0e07a890;
  *DAT_0e07a890 = *DAT_0e07a890 | uVar3;
  FUN_0e092690(*psVar1,DAT_0e07a894);
  *puVar2 = *puVar2 | 0x10000;
  FUN_0e092b18(1 << *psVar1,extraout_r1,0,param_4);
  return;
}


