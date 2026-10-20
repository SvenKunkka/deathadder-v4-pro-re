/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07f1e4. Types and names are inferred; NOT original source. */

void FUN_0e07f1e4(void)

{
  code *pcVar1;
  undefined4 unaff_r4;
  undefined4 unaff_lr;
  
  if (DAT_2300777c == '\0') {
    return;
  }
  if (0xfa < DAT_230076cc) {
    DAT_230076cc = 0;
    switch(DAT_23007756) {
    case '\0':
    case '\x02':
      FUN_0e07f000();
      DAT_23007756 = DAT_23007756 + '\x01';
      break;
    case '\x01':
      DAT_23007743 = 0;
      DAT_23007741 = 0;
      DAT_23007742 = 0;
      DAT_23007756 = 2;
      return;
    case '\x03':
      DAT_2300777c = 0;
      FUN_0e097678();
      DAT_23007743 = 0;
      DAT_23007742 = 0;
      DAT_23007741 = 0;
      FUN_0e079990();
      if (DAT_23007070 << 0x1a < 0) {
        pcVar1 = (code *)&DAT_230263bd;
      }
      else {
        pcVar1 = (code *)&DAT_23026369;
      }
      (*pcVar1)(&DAT_0e097818,0x20);
      if (DAT_23007070 << 0x1d < 0) {
        pcVar1 = (code *)&DAT_230263bd;
      }
      else {
        pcVar1 = (code *)&DAT_23026369;
      }
      (*pcVar1)(&DAT_0e097818,4);
      if (DAT_23007070 << 0x1c < 0) {
        pcVar1 = (code *)&DAT_230263bd;
      }
      else {
        pcVar1 = (code *)&DAT_23026369;
      }
      (*pcVar1)(&DAT_0e097818,8,DAT_23007070 << 0x1c,pcVar1,unaff_r4,unaff_lr);
      if (DAT_23007070 << 0x1b < 0) {
        FUN_230263bc(&DAT_0e097818,0x10);
        return;
      }
      FUN_23026368(&DAT_0e097818,0x10);
      return;
    default:
      DAT_23007756 = 0;
      return;
    }
  }
  return;
}


