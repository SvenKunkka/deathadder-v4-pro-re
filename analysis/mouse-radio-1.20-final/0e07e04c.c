/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07e04c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e07e04c(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0e094560(DAT_230004dc);
  if (iVar1 == 0) {
    return 0xffffffed;
  }
  DAT_230004e0 = (**(code **)(*(int *)(DAT_230004dc + 8) + 8))(DAT_230004dc,&DAT_0e099268);
  if (-1 < DAT_230004e0) {
                    /* WARNING: Could not recover jumptable at 0x0e07e074. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*(code *)**(undefined4 **)(DAT_230004dc + 8))(DAT_230004dc,2);
    return uVar2;
  }
  return 0xfffffff2;
}


