/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23026a00. Types and names are inferred; NOT original source. */

void FUN_23026a00(void)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  
  sVar1 = DAT_230076c0;
  uVar2 = (uint)DAT_23007722;
  uVar3 = (uint)DAT_230077a2 | (uint)DAT_230077a1 << 1;
  if (uVar2 == uVar3) {
    if ((DAT_23007721 != uVar2) && (DAT_230076c0 == 0)) {
      if (uVar2 == 3) {
        if (DAT_23007723 != '\x04') {
          DAT_23007723 = '\x04';
          DAT_2300771f = 0;
          FUN_2302b944();
          FUN_2302ba44();
          FUN_2302b678();
          FUN_2302b864();
          thunk_FUN_0e0844c0();
          DAT_230076c8 = sVar1;
          FUN_2302133c();
          FUN_2302b970();
          FUN_23026bd0();
          FUN_2302b5c8();
          FUN_2302b778();
          DAT_23007787 = 0;
          DAT_23007786 = 0;
          DAT_23007785 = 0;
          DAT_23007792 = 0;
          DAT_230076de = sVar1;
          DAT_230076dc = sVar1;
          thunk_FUN_0e07ec9c();
          FUN_2302b70c();
          FUN_2302bb98();
          DAT_2300771f = 1;
        }
      }
      else if (DAT_23007723 != '\x01') {
        DAT_23007723 = '\x01';
        DAT_2300771f = 0;
        FUN_2302b944();
        FUN_2302ba44();
        FUN_2302b678();
        FUN_2302b864();
        thunk_FUN_0e0844c0();
        FUN_2302869c(1);
        if (DAT_2300777f == '\0') {
          thunk_FUN_0e07eee8();
        }
      }
      thunk_FUN_0e084de4(DAT_23007723);
      DAT_23007721 = DAT_23007722;
      return;
    }
  }
  else {
    DAT_23007722 = (byte)uVar3;
    DAT_230076c0 = 200;
  }
  return;
}


