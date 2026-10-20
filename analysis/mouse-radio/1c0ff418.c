/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0ff418. Types and names are inferred; NOT original source. */

int FUN_1c0ff418(int param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  
  if (param_2 == 0) {
    return 0;
  }
  iVar2 = 0;
  pcVar1 = (char *)(param_1 + -1);
  do {
    pcVar1 = pcVar1 + 1;
    if (*pcVar1 == '\0') {
      return iVar2;
    }
    iVar2 = iVar2 + 1;
  } while (param_2 != iVar2);
  return param_2;
}


