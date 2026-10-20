/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0684dc. Types and names are inferred; NOT original source. */

undefined8 FUN_0e0684dc(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  uint local_20;
  int iStack_1c;
  
  FUN_0e069644(&local_20);
  uVar3 = FUN_0e06e928();
  iVar1 = (-1 - param_2) - (uint)(0xfffffffe < param_1);
  if (iVar1 < 0) {
    if (param_2 < 0x100000) {
      return CONCAT44(iStack_1c + param_2 + (uint)CARRY4(param_1,local_20),param_1 + local_20);
    }
  }
  else {
    uVar2 = (-param_1 - 2) - (uint)uVar3;
    iVar1 = (iVar1 - (int)((ulonglong)uVar3 >> 0x20)) - (uint)(-param_1 - 2 < (uint)uVar3);
    if (iVar1 < 0x100000) {
      return CONCAT44(iVar1 + iStack_1c + (uint)CARRY4(uVar2,local_20),uVar2 + local_20);
    }
  }
  return 0xffffffffffffffea;
}


