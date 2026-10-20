/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e080724. Types and names are inferred; NOT original source. */

void FUN_0e080724(undefined4 param_1,undefined4 param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  
  pbVar2 = DAT_0e080784;
  pbVar1 = DAT_0e080780;
  if (0x19 < *DAT_0e080780) {
    *DAT_0e080780 = 1;
  }
  if (0x19 < *pbVar2) {
    *pbVar2 = 1;
  }
  FUN_0e094d84(DAT_0e080788,param_2,0x9d,0);
  FUN_0e08068c();
  FUN_0e0977f8(0x7f,0x18);
  FUN_0e0977f8(0x41,*pbVar1);
  FUN_0e0977f8(0x43,*pbVar2);
  FUN_0e0977f8(0x7a,0);
  FUN_0e0977f8(0x7f,0);
  FUN_0e094e80(DAT_0e080788);
  return;
}


