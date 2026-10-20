/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e085324. Types and names are inferred; NOT original source. */

undefined4 FUN_0e085324(byte param_1)

{
  int iVar1;
  char cVar2;
  byte local_11 [5];
  
  cVar2 = '\v';
  do {
    local_11[0] = param_1 | 0x30;
    iVar1 = FUN_0e084ce8(0x18,local_11,1);
    if (iVar1 != 0) {
      return 0;
    }
    FUN_0e09628c(0x9d,0);
    cVar2 = cVar2 + -1;
  } while (cVar2 != '\0');
  return 0xffffffff;
}


