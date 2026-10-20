/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23025fe0. Types and names are inferred; NOT original source. */

void FUN_23025fe0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = 0;
  uVar5 = (uint)(param_1 * 100) / 0xff;
  iVar1 = uVar5 * 4;
  uVar4 = (&DAT_0e06f7d4)[uVar5 * 4];
  uVar2 = (&DAT_0e06f7d5)[iVar1];
  uVar3 = (&DAT_0e06f7d6)[iVar1];
  do {
    uVar5 = uVar6 & 0xff;
    uVar6 = uVar6 + 1;
    FUN_23025ce0(uVar5,uVar4,uVar2,uVar3,param_4);
  } while (uVar6 != 3);
  return;
}


