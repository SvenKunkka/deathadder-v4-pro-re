/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23020750. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ram_candidate_23020750(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  short *psVar6;
  
  if (_DAT_5f982104 == 0) {
    if (_DAT_5f982110 == 0) {
      return;
    }
    _DAT_5f982000 = 1;
    _DAT_5f982004 = 1;
    _DAT_5f982008 = 1;
    _DAT_5f982110 = _DAT_5f982104;
    return;
  }
  uVar5 = 1;
  uVar4 = (uint)DAT_230002f8;
  _DAT_5f982104 = 0;
  _DAT_5f982008 = 1;
  _DAT_5f982500 = 0;
  if ((uVar4 & DAT_230002c8) != 0) {
    uVar3 = DAT_230002c8 & 0xff;
    psVar6 = _DAT_5f98262c;
    do {
      if ((uVar3 & uVar5) != 0) {
        if (((uVar4 & uVar5) != 0) && (*psVar6 < 0)) {
          *psVar6 = 0;
        }
        psVar6 = psVar6 + 1;
      }
      uVar5 = (uVar5 & 0x7fff) << 1;
    } while (uVar5 <= uVar4);
  }
  uVar4 = (uint)DAT_23000304;
  if (DAT_230002d4 != '\b') {
    uVar4 = uVar4 << 1;
  }
  thunk_FUN_0e09739c(DAT_23000300,DAT_230002fc,uVar4);
  if (DAT_230002c4 == 0) goto LAB_230207b0;
  if (DAT_230002dc == (code *)0x0) {
LAB_230207d2:
    if (DAT_230002e8 < (ushort)DAT_230002e4) {
      DAT_230002e8 = DAT_230002e8 + 1;
      uVar4 = _DAT_5f982634 & 0xffff;
      if ((_DAT_5f9825f0 & 0xff) != 0) {
        uVar4 = uVar4 >> 1;
      }
      if (DAT_230002d4 != '\b') {
        uVar4 = uVar4 << 1;
      }
      DAT_23000300 = DAT_23000300 + uVar4;
LAB_2302080a:
      if ((DAT_230002d8 != 0) &&
         (iVar2 = DAT_23000260 + -1, bVar1 = DAT_23000260 < 2, DAT_23000260 = iVar2, bVar1)) {
        return;
      }
      _DAT_5f982500 = 1;
      if (DAT_230002d6 == '\0') {
        _DAT_5f982000 = 1;
        _DAT_5f982004 = 1;
        return;
      }
      _DAT_5f98200c = 1;
      return;
    }
  }
  else {
    iVar2 = (*DAT_230002dc)(param_1,&DAT_230002c4,DAT_230002e8);
    if (iVar2 == 1) goto LAB_2302080a;
    if (iVar2 != 2) goto LAB_230207d2;
  }
  if (DAT_230002d8 != 0) {
    thunk_FUN_0e096ac4(&DAT_23000268);
    thunk_FUN_0e094f80(&DAT_230002b0);
    return;
  }
LAB_230207b0:
  thunk_FUN_0e094f80(&DAT_230002b0);
  return;
}


