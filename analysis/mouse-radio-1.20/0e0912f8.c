/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0912f8. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0912f8(void)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (_DAT_5f9a4110 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0x10;
  }
  _DAT_5f9a4110 = 0;
  if (_DAT_5f9a4114 != 0) {
    uVar3 = uVar3 | 0x20;
  }
  _DAT_5f9a4114 = 0;
  if (_DAT_5f9a411c != 0) {
    uVar3 = uVar3 | 0x80;
  }
  _DAT_5f9a411c = 0;
  bVar1 = _DAT_5f9a4104 != 0;
  if (bVar1) {
    _DAT_5f9a4104 = 0;
    uVar3 = uVar3 | 2;
  }
  uVar2 = _DAT_5f9a4110;
  if ((((int)(uVar3 << 0x1b) < 0) && (uVar2 = 0, (int)(DAT_23007288 << 0x1d) < 0)) &&
     (DAT_2300727c != (code *)0x0)) {
    (*DAT_2300727c)(1,DAT_23007280);
    uVar2 = _DAT_5f9a4110;
  }
  _DAT_5f9a4110 = uVar2;
  if ((((int)(uVar3 << 0x1a) < 0) && ((int)(DAT_23007288 << 0x1c) < 0)) &&
     (DAT_2300727c != (code *)0x0)) {
    (*DAT_2300727c)(2,DAT_23007280);
  }
  if ((((int)(uVar3 << 0x18) < 0) && ((DAT_23007288 & 0x10) == 0)) && (DAT_2300727c != (code *)0x0))
  {
    (*DAT_2300727c)(0,DAT_23007280);
  }
  if (bVar1) {
    _DAT_5f9a4500 = 0;
    DAT_23007284 = 1;
    if (DAT_2300727c != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0e091364. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*DAT_2300727c)(3,DAT_23007280);
      return;
    }
  }
  return;
}


