/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302aa40. Types and names are inferred; NOT original source. */

undefined1 FUN_2302aa40(byte param_1)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  code *pcVar3;
  
  if (DAT_23007746 != '\0') {
    if ((DAT_2300707c & 0x80) == 0) {
      pcVar3 = (code *)0x23026369;
    }
    else {
      pcVar3 = (code *)0x230263bd;
    }
    (*pcVar3)();
    puVar1 = DAT_230004d8;
    DAT_2fc13040 = param_1 & 0x7f;
    DAT_23004ce0 = 3;
    DAT_2fc13042 = 0xff;
    DAT_2fc13041 = 0;
    DAT_230004d8[0x1cf] = &DAT_2fc13040;
    puVar1[0x1d0] = 3;
    puVar1[0x1c1] = 0x2fc13000;
    puVar1[0x1c2] = 3;
    *puVar1 = 1;
    DAT_23004cdc = 3;
    DAT_23007692 = 0;
    DAT_23007745 = 0;
    do {
      if (DAT_230004d8[0x42] != 0) {
        DAT_230004d8[0x42] = 0;
        if ((DAT_2300707c & 0x80) == 0) {
          pcVar3 = (code *)0x230263bd;
        }
        else {
          pcVar3 = (code *)0x23026369;
        }
        (*pcVar3)();
        uVar2 = DAT_2fc13002;
        thunk_FUN_0e094554(3);
        return uVar2;
      }
      thunk_FUN_0e094554(1);
      DAT_23007692 = DAT_23007692 + 1;
    } while (DAT_23007692 < 0x65);
    if ((DAT_2300707c & 0x80) == 0) {
      pcVar3 = (code *)0x230263bd;
    }
    else {
      pcVar3 = (code *)0x23026369;
    }
    (*pcVar3)();
    thunk_FUN_0e094554(3);
  }
  return 0xff;
}


