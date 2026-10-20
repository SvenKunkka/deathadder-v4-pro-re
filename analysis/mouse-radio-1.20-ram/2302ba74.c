/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302ba74. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2302ba74(void)

{
  undefined4 uVar1;
  
  _DAT_5f9c2540 = 0;
  _DAT_5f9c2544 = 0;
  _DAT_5f9c2548 = 0;
  _DAT_5f9c254c = 0;
  _DAT_5f9c2550 = 0;
  _DAT_5f9c2554 = 0;
  _DAT_5f9c2200 = _DAT_5f9c2200 & 0xff00ff00;
  _DAT_5f9c2308 = 0xff0000;
  if (DAT_23004a5f == '\x01') {
    uVar1 = FUN_23029e1c(&DAT_0e099248,0x5a);
    FUN_23029ca4(&DAT_0e099248,0,uVar1,0x80008,1);
    uVar1 = FUN_23029e1c(&DAT_0e099248,0xd7);
    FUN_23029ca4(&DAT_0e099248,1,uVar1,0x80008,1);
    uVar1 = FUN_23029e1c(&DAT_0e099248,0x154);
    FUN_23029ca4(&DAT_0e099248,2,uVar1,0x80008,1);
    uVar1 = 0x1d1;
  }
  else {
    if (DAT_23004a5f != '\x02') {
      uVar1 = FUN_23029e1c(&DAT_0e099248,10);
      FUN_23029ca4(&DAT_0e099248,3,uVar1,0x80008,1);
      return;
    }
    uVar1 = FUN_23029e1c(&DAT_0e099248,10);
    FUN_23029ca4(&DAT_0e099248,0,uVar1,0x80008,1);
    uVar1 = 0x104;
  }
  uVar1 = FUN_23029e1c(&DAT_0e099248,uVar1);
  FUN_23029ca4(&DAT_0e099248,3,uVar1,0x80008,1);
  return;
}


