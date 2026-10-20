/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e077044. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_0e077044(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  char cVar2;
  code *pcVar3;
  
  cVar2 = DAT_23007746;
  if (DAT_23007746 != '\0') {
    if (DAT_23007745 == '\0') {
      FUN_0e0773dc(param_1,param_3);
    }
    if ((DAT_2300707c & 0x80) == 0) {
      pcVar3 = (code *)&DAT_23026369;
    }
    else {
      pcVar3 = (code *)&DAT_230263bd;
    }
    (*pcVar3)();
    *_DAT_230004d8 = 1;
    do {
    } while (_DAT_230004d8[0x42] == 0);
    if ((DAT_2300707c & 0x80) == 0) {
      pcVar3 = (code *)&DAT_230263bd;
    }
    else {
      pcVar3 = (code *)&DAT_23026369;
    }
    (*pcVar3)();
    puVar1 = _DAT_230004d8;
    _DAT_230004d8[0x42] = 0;
    thunk_FUN_0e09739c(param_2,0x2fc13002,param_3,puVar1[0x42]);
  }
  return cVar2;
}


