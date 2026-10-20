/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23025954. Types and names are inferred; NOT original source. */

void FUN_23025954(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  
  uVar1 = param_1 - 1U & 0xff;
  if (uVar1 < 4) {
    uVar4 = (&DAT_0e06f78c)[uVar1];
    uVar3 = (&DAT_0e06f784)[uVar1];
    uVar5 = (&DAT_0e06f788)[uVar1];
  }
  else {
    uVar4 = 0;
    uVar3 = uVar4;
    uVar5 = uVar4;
  }
  uVar1 = 0;
  do {
    uVar2 = uVar1 & 0xff;
    uVar1 = uVar1 + 1;
    FUN_23025ce0(uVar2,uVar4,uVar5,uVar3,param_4);
  } while (uVar1 != 3);
  return;
}


