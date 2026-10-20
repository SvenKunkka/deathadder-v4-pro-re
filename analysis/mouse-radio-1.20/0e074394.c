/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e074394. Types and names are inferred; NOT original source. */

void FUN_0e074394(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  uint uVar2;
  
  if (DAT_23006775 != '\0') {
    cVar1 = DAT_23006774;
    if (DAT_23006774 == '\0') {
      FUN_0e07390c(0,6,param_3,DAT_23006775,param_4);
      DAT_23006775 = cVar1;
    }
  }
  if (DAT_23006777 != '\0') {
    cVar1 = DAT_23006776;
    if (DAT_23006776 == '\0') {
      FUN_0e07390c(0,7);
      DAT_23006777 = cVar1;
    }
  }
  if (0x31 < DAT_23007778) {
    DAT_23007778 = 0;
    uVar2 = (uint)DAT_2300776a;
    if (uVar2 != 0) {
      if ((int)(uVar2 << 0x1f) < 0) {
        DAT_23007789 = DAT_23007789 + -1;
      }
      else if ((int)(uVar2 << 0x1e) < 0) {
        DAT_23007789 = DAT_23007789 + '\x01';
      }
      DAT_230076d2 = DAT_230076d2 | 2;
    }
  }
  return;
}


