/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e078e44. Types and names are inferred; NOT original source. */

undefined4 thunk_FUN_0e085198(byte param_1)

{
  int iVar1;
  char cVar2;
  byte abStack_11 [5];
  
  cVar2 = '\v';
  do {
    abStack_11[0] = param_1 | 0x30;
    iVar1 = FUN_0e084b5c(0x18,abStack_11,1);
    if (iVar1 != 0) {
      return 0;
    }
    FUN_0e096164(0x9d,0);
    cVar2 = cVar2 + -1;
  } while (cVar2 != '\0');
  return 0xffffffff;
}


