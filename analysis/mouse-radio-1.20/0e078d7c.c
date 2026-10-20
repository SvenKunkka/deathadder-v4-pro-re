/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e078d7c. Types and names are inferred; NOT original source. */

void thunk_FUN_0e0855fc(void)

{
  int iVar1;
  char cVar2;
  undefined1 auStack_11 [5];
  
  cVar2 = '\v';
  do {
    auStack_11[0] = 0x30;
    iVar1 = FUN_0e0851d4(8,auStack_11,1);
    if (iVar1 != 0) {
      FUN_0e096164(0x271,0);
      auStack_11[0] = 0xf0;
      iVar1 = FUN_0e0851d4(8,auStack_11,1);
      if (iVar1 != 0) {
        FUN_0e096164(0x271,0);
        return;
      }
    }
    FUN_0e096164(0x9d,0);
    cVar2 = cVar2 + -1;
  } while (cVar2 != '\0');
  return;
}


