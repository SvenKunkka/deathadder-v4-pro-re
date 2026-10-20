/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e073664. Types and names are inferred; NOT original source. */

void FUN_0e073664(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint local_1c [2];
  
  if (DAT_230077a2 == '\0') {
    iVar3 = FUN_230263ac(&DAT_0e097840,local_1c);
    cVar1 = DAT_2300777c;
    if ((iVar3 == 0) && (((local_1c[0] ^ DAT_23007088) & 8) == 0)) {
      if (DAT_2300777e == '\0') {
        DAT_2300777e = '\x01';
        if (DAT_2300777c == '\0') {
          DAT_230076ce = 500;
        }
        else {
          DAT_230076ce = 2000;
        }
        DAT_2300777d = '\0';
      }
      else if ((DAT_230076ce == 0) && (DAT_2300777d == '\0')) {
        DAT_2300777d = '\x01';
        if (DAT_2300777c == '\0') {
          DAT_2300777c = '\x01';
          DAT_2300776e = cVar1;
          DAT_2300777b = cVar1;
          DAT_23007723 = cVar1;
          DAT_230076c4 = 0;
          DAT_23007722 = cVar1;
          DAT_23007721 = 0xff;
          DAT_230076c8 = DAT_230076c4;
          thunk_FUN_0e07ec9c();
          thunk_FUN_0e07d6bc(0x5a5a5a5a);
        }
        else if (DAT_2300777b == '\0') {
          DAT_2300772b = DAT_2300777b;
          thunk_FUN_0e07f1f4();
        }
      }
    }
    else {
      if (DAT_2300777c == '\0') {
        cVar1 = DAT_2300777c;
        if (DAT_23007720 != '\0') goto LAB_0e0736e2;
        if (DAT_2300776e != '\0') {
          DAT_2300777e = DAT_23007720;
          return;
        }
        thunk_FUN_0e085198(2);
        DAT_2300776e = '\x01';
      }
      DAT_2300777e = '\0';
    }
  }
  else if ((DAT_2300777c == '\0') && (DAT_23007779 == '\0')) {
    DAT_2300777b = DAT_23007779;
    DAT_2300776e = DAT_23007779;
    DAT_2300777c = '\x01';
    thunk_FUN_0e07d6bc(0x5a5a5a5a);
  }
  cVar1 = DAT_2300777e;
  if (DAT_23007720 == '\0') {
    return;
  }
LAB_0e0736e2:
  DAT_2300777e = cVar1;
  uVar2 = FUN_230263ac(&DAT_0e097840,local_1c);
  if (uVar2 == 0) {
    uVar2 = (uint)(((local_1c[0] ^ DAT_23007088) & 8) != 0);
  }
  if (((uVar2 == 1) || ((DAT_23007720 != '\0' && (DAT_23007779 != '\0')))) && (499 < DAT_230076c2))
  {
    DAT_230076c2 = 0;
    thunk_FUN_0e07d6bc(0);
    DAT_2300771f = 0;
    if (DAT_2300777f != '\0') {
      FUN_0e06dad8();
    }
    FUN_0e0780e0();
    FUN_0e0781e0();
    FUN_0e077e14();
    FUN_0e078000();
    thunk_FUN_0e096164(0xc35,0);
    if (DAT_23007779 == '\0') {
      FUN_0e078c24();
    }
    else {
      FUN_0e078b2c(2);
      thunk_FUN_0e079990();
      thunk_FUN_0e0855fc();
    }
    DAT_2300776e = '\0';
    DAT_23007720 = '\0';
    DAT_2300777c = '\0';
    DAT_2300777b = '\0';
    iVar3 = thunk_FUN_0e085198(2);
    if (iVar3 == 0) {
      do {
        do {
          thunk_FUN_0e096164(0x20,0);
          thunk_FUN_0e07e09c();
        } while (DAT_23007779 != '\0');
        iVar3 = thunk_FUN_0e084d3c();
      } while (iVar3 == 0);
                    /* WARNING: Subroutine does not return */
      thunk_FUN_0e085ed0(0);
    }
  }
  return;
}


