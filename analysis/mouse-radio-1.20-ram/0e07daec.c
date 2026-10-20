/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07daec. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e07daec(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 in_r3;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar6 = DAT_23004cc0;
  if (DAT_23003f03 < 6) {
    if (DAT_23003f03 != 0) {
      switch(DAT_23003f03) {
      case 1:
        iVar2 = FUN_0e088910(3,&DAT_23004cd0);
        if (iVar2 != 0) {
          DAT_23003efc = 3;
          DAT_23004cd0 = 0;
          return;
        }
        if (*(uint *)(DAT_23004cd0 + 8) < DAT_23004cc8) {
          DAT_23003efc = 3;
          return;
        }
        DAT_23004cbc = FUN_0e0889d4();
        uVar3 = FUN_0e0889e4(DAT_23004cd0);
        DAT_23007739 = (undefined1)uVar3;
        DAT_23004cc0 = iVar2;
        DAT_23004cc4 = iVar2;
        FUN_0e0973ea(&DAT_23004abc,uVar3,0x200);
        DAT_23007738 = '\0';
        cVar1 = DAT_2300779e;
        if ((DAT_2300779e == '\x01') && (DAT_23004a5d < 8)) {
          DAT_23007737 = DAT_23004a5d;
          thunk_FUN_23026ce0(4,8);
          DAT_23007738 = cVar1;
        }
        DAT_23004cc8 = DAT_23003f08 << 0x18 | (DAT_23003f08 >> 8 & 0xff) << 0x10 |
                       (DAT_23003f08 >> 0x10 & 0xff) << 8 | DAT_23003f08 >> 0x18;
        DAT_23004ccc = 0;
        DAT_23004ab0 = 0xffffffff;
        return;
      case 2:
        uVar5 = (uint)_DAT_23003f05 << 0x18 | ((_DAT_23003f05 & 0xff00) >> 8) << 0x10 |
                (uint)(_DAT_23003f05 >> 0x10) << 8 | DAT_23003f08 & 0xff;
        uVar7 = _DAT_23003f04 & 0xff;
        if (DAT_23004ab0 == uVar5) {
          return;
        }
        DAT_23004ccc = uVar5 + uVar7;
        DAT_23004ab0 = uVar5;
        FUN_0e09739c(&DAT_23004abc + DAT_23004cc0,0x23003f09,uVar7);
        DAT_23004cc0 = uVar6 + uVar7;
        if (DAT_23004cc0 == 0x200) {
          iVar4 = 0x200 - DAT_23004cbc * (0x200 / DAT_23004cbc);
          iVar2 = 0x200;
          if (iVar4 != 0) {
            iVar2 = (DAT_23004cbc + 0x200) - iVar4;
          }
          iVar2 = FUN_0e08899c(DAT_23004cd0,DAT_23004cc4,&DAT_23004abc,iVar2);
          if (iVar2 == 0) {
            DAT_23004cc4 = DAT_23004cc4 + 0x200;
            DAT_23004cc0 = iVar2;
            FUN_0e0973ea(&DAT_23004abc,DAT_23007739,0x200,in_r3);
            return;
          }
          FUN_0e088960(DAT_23004cd0);
          DAT_23004cd0 = 0;
          DAT_23003efc = 3;
          DAT_23004cc0 = 0;
          DAT_23004cc4 = 0;
          return;
        }
        return;
      case 4:
        if (DAT_23007738 != '\0') {
          thunk_FUN_23026ce0(4,DAT_23007737);
          DAT_23007738 = '\0';
        }
        FUN_0e088960(DAT_23004cd0);
        DAT_23004cd0 = 0;
        DAT_23004cc0 = 0;
        DAT_23004cc4 = 0;
        return;
      case 5:
        if (DAT_23004ccc == DAT_23004cc8) {
          DAT_23004ab4 = FUN_0e090f94(0x100000);
          DAT_23004ab8 = DAT_23004cc8;
        }
        FUN_0e088960(DAT_23004cd0);
        DAT_23004cd0 = 0;
        DAT_23004cc0 = 0;
        DAT_23004cc4 = 0;
        if (((DAT_23004ab4 != 0) && (DAT_23004ab8 != 0)) && (DAT_23004ccc == DAT_23004cc8)) {
          FUN_0e090e58(&DAT_23004ab4,1);
        }
                    /* WARNING: Subroutine does not return */
        FUN_0e085ed0(0);
      }
    }
    DAT_23003efc = 5;
    return;
  }
  if (DAT_23003f03 == 0x80) {
    DAT_23003f08 = 0;
    _DAT_23003f04 = 0x103b07;
    DAT_23003f0c._0_1_ = 0xbe;
    return;
  }
  if (DAT_23003f03 == 0x83) {
    if (DAT_23004cc0 != 0) {
      iVar2 = DAT_23004cc0 - DAT_23004cbc * (DAT_23004cc0 / DAT_23004cbc);
      if (iVar2 != 0) {
        uVar6 = (DAT_23004cc0 + DAT_23004cbc) - iVar2;
      }
      iVar2 = FUN_0e08899c(DAT_23004cd0,DAT_23004cc4,&DAT_23004abc,uVar6);
      if (iVar2 != 0) {
        DAT_23003efc = 3;
        return;
      }
      DAT_23004cc0 = 0;
    }
    iVar2 = FUN_0e088964(DAT_23004cd0,
                         (uint)_DAT_23003f05 << 0x18 | ((_DAT_23003f05 & 0xff00) >> 8) << 0x10 |
                         (uint)(_DAT_23003f05 >> 0x10) << 8 | DAT_23003f08 & 0xff,0x23003f09,
                         _DAT_23003f04 & 0xff);
    if (iVar2 != 0) {
      DAT_23003efc = 3;
      return;
    }
    return;
  }
  DAT_23003efc = 5;
  return;
}


