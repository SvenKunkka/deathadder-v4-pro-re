/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e078d4c. Types and names are inferred; NOT original source. */

void thunk_FUN_0e07d6d8(int param_1)

{
  uint uVar1;
  undefined4 unaff_r4;
  
  if (param_1 == 0) {
    DAT_2300768e = 0;
    while (DAT_23007726 != 0) {
      FUN_0e07d590();
    }
    goto LAB_0e07d6f0;
  }
  if (DAT_23007733 < 6) {
    if (DAT_230077a2 != '\0') goto joined_r0x0e07d72e;
  }
  else {
    if ((0x3c < DAT_230076c8) && (DAT_230076c6 == 0)) {
      FUN_0e07d590();
      DAT_230076c6 = 0x3c;
      goto LAB_0e07d6f0;
    }
joined_r0x0e07d72e:
    if (DAT_23007729 != 0) {
      FUN_0e07d590();
      if (DAT_23007726 == 0) {
        DAT_23007729 = DAT_23007726;
      }
      goto LAB_0e07d6f0;
    }
    if (-1 < (int)((uint)DAT_23007726 << 0x1e)) goto LAB_0e07d6f0;
  }
  FUN_0e07d590();
LAB_0e07d6f0:
  uVar1 = (uint)DAT_23007727;
  if ((uVar1 != 0) && ((int)(uVar1 << 0x1f) < 0)) {
    DAT_23007727 = (byte)(uVar1 & 0xfffffffe);
    FUN_0e094c5c(&DAT_23006788,uVar1 << 0x1f,0x9d,0,uVar1 & 0xfffffffe,unaff_r4);
    FUN_0e097698(0x48,(undefined1)DAT_23006bc4);
    FUN_0e097698(0x49,DAT_23006bc4 >> 8);
    FUN_0e097698(0x4a,(undefined1)DAT_23006bc6);
    FUN_0e097698(0x4b,DAT_23006bc6 >> 8);
    FUN_0e097698(0x47,1);
    FUN_0e094d58(&DAT_23006788);
    return;
  }
  return;
}


