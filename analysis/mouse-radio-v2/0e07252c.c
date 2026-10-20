/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07252c. Types and names are inferred; NOT original source. */

void FUN_0e07252c(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int local_84 [31];
  
  uVar1 = DAT_0e072558;
LAB_0e072532:
  thunk_FUN_0e094cb4(uVar1,local_84,0xffffffff,0xffffffff);
  uVar2 = 1;
  if (local_84[0] != 1) goto code_r0x0e072548;
  goto LAB_0e07254e;
code_r0x0e072548:
  if (local_84[0] == 2) {
    uVar2 = 0;
LAB_0e07254e:
    FUN_0e06d618(1,uVar2);
  }
  goto LAB_0e072532;
}


