/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23024db4. Types and names are inferred; NOT original source. */

void FUN_23024db4(uint param_1)

{
  ushort uVar1;
  undefined1 local_30;
  ushort local_2f;
  
  if ((DAT_2300659a & 0xffff) != param_1) {
    uVar1 = (ushort)((param_1 & 0xff) << 8) | (ushort)(param_1 >> 8) & 0xff;
    DAT_2300659a = param_1 & 0xffff | param_1 << 0x10;
    local_30 = 0xac;
    DAT_2300659e = 0;
    DAT_230065b0 = 0;
    local_2f = uVar1;
    FUN_230251e4(0,3,&local_30);
    if ((DAT_2300659a & 0xffff) == 0) {
      if (DAT_23006598 != '\0') {
        DAT_23006598 = (char)DAT_2300659a;
        thunk_FUN_0e06ec54(&DAT_23001ad8);
        return;
      }
    }
    else if (DAT_23006598 == '\0') {
      DAT_23006598 = '\x01';
      thunk_FUN_0e06ebe0(&DAT_23001ad8,1,100000,0,1000,0,uVar1);
    }
  }
  return;
}


