/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068454. Types and names are inferred; NOT original source. */

undefined4
FUN_0e068454(byte param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_r1;
  undefined4 uVar3;
  uint uVar4;
  undefined4 local_2c;
  undefined4 local_28;
  byte local_24;
  
  uVar1 = DAT_23006db0;
  uVar4 = 1 << (uint)param_1;
  DAT_23006db0 = DAT_23006db0 & ~uVar4;
  FUN_0e069808(param_1);
  local_2c = param_5;
  local_28 = param_6;
  local_24 = param_1;
  iVar2 = FUN_0e069760(&local_2c,extraout_r1,param_3,param_4,1);
  uVar3 = 0;
  if (iVar2 != 0xbad0000) {
    uVar3 = 0xffffffff;
  }
  if ((uVar4 & uVar1) != 0) {
    DAT_23006db0 = DAT_23006db0 | uVar4;
    FUN_0e069850(param_1);
    return uVar3;
  }
  return uVar3;
}


