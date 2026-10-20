/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23024cd4. Types and names are inferred; NOT original source. */

void FUN_23024cd4(void)

{
  uint uVar1;
  undefined1 local_28 [32];
  
  uVar1 = (uint)DAT_23006590;
  if ((int)(uVar1 << 0x1f) < 0) {
    local_28[0] = 0xa3;
    FUN_230251e4(0,3,local_28,1);
    uVar1 = (uint)DAT_23006590;
  }
  if ((int)(uVar1 << 0x1e) < 0) {
    local_28[0] = 0xa3;
    FUN_230251e4(1,3,local_28);
  }
  thunk_FUN_0e06ebe0(&DAT_23001aa0,0,2000000,0,0,0);
  thunk_FUN_0e06ec54(&DAT_23001a68);
  thunk_FUN_0e06ec54(&DAT_23001ad8);
  thunk_FUN_0e06ec54(&DAT_23001b10);
  return;
}


