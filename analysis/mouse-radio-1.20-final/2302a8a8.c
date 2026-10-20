/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302a8a8. Types and names are inferred; NOT original source. */

char FUN_2302a8a8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  char cVar2;
  code *pcVar3;
  
  cVar2 = DAT_23007746;
  if (DAT_23007746 != '\0') {
    if (DAT_23007745 == '\0') {
      FUN_2302ac40(param_1,param_3);
    }
    if ((DAT_2300707c & 0x80) == 0) {
      pcVar3 = (code *)0x23026369;
    }
    else {
      pcVar3 = (code *)0x230263bd;
    }
    (*pcVar3)();
    *DAT_230004d8 = 1;
    do {
    } while (DAT_230004d8[0x42] == 0);
    if ((DAT_2300707c & 0x80) == 0) {
      pcVar3 = (code *)0x230263bd;
    }
    else {
      pcVar3 = (code *)0x23026369;
    }
    (*pcVar3)();
    puVar1 = DAT_230004d8;
    DAT_230004d8[0x42] = 0;
    thunk_FUN_0e09739c(param_2,&DAT_2fc13002,param_3,puVar1[0x42]);
  }
  return cVar2;
}


