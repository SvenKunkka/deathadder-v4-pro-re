/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068584. Types and names are inferred; NOT original source. */

void FUN_0e068584(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint local_18;
  int local_14;
  
  if (param_1 == 0xffffffff) {
    param_1 = 0x7fffffff;
  }
  else {
    param_1 = param_1 & ~((int)param_1 >> 0x1f);
  }
  FUN_0e069644(&local_18);
  uVar1 = (local_18 - DAT_23002840) + param_1;
  iVar2 = ((local_14 - DAT_23002844) - (uint)(local_18 < DAT_23002840)) +
          ((int)param_1 >> 0x1f) + (uint)CARRY4(local_18 - DAT_23002840,param_1);
  if (uVar1 == 0 && iVar2 == 0) {
    uVar1 = 1;
    iVar2 = 0;
  }
  FUN_0e069760(&DAT_23000958,1,uVar1 + DAT_23002840,
               DAT_23002844 + iVar2 + (uint)CARRY4(uVar1,DAT_23002840),1);
  return;
}


