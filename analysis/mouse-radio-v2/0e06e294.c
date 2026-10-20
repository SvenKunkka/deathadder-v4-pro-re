/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e06e294. Types and names are inferred; NOT original source. */

void FUN_0e06e294(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (param_1 == 2) {
    *(undefined4 *)(DAT_0e06e304 + 0x500) = 4;
  }
  else if (param_1 == 4) {
    *(undefined4 *)(DAT_0e06e304 + 0x500) = 9;
  }
  if ((*(int *)(DAT_0e06e304 + 0x8a0) == -0x80000000) ||
     (*(int *)(DAT_0e06e304 + 0x8a0) == DAT_0e06e308)) {
    *(undefined4 *)(DAT_0e06e304 + 0x8a0) = DAT_0e06e328;
  }
  uVar4 = DAT_0e06e318;
  uVar3 = DAT_0e06e314;
  uVar2 = DAT_0e06e310;
  iVar1 = DAT_0e06e304;
  *(undefined4 *)(DAT_0e06e304 + 0x8a4) = DAT_0e06e30c;
  *(undefined4 *)(iVar1 + 0x8a8) = uVar2;
  uVar2 = DAT_0e06e31c;
  *(undefined4 *)(iVar1 + 0x8ac) = uVar3;
  uVar3 = DAT_0e06e320;
  *(undefined4 *)(iVar1 + 0x7ac) = uVar4;
  uVar4 = DAT_0e06e324;
  *(undefined4 *)(iVar1 + 0x7b0) = uVar2;
  *(undefined4 *)(iVar1 + 0x7b4) = uVar3;
  *(undefined4 *)(iVar1 + 0x7e4) = uVar4;
  return;
}


