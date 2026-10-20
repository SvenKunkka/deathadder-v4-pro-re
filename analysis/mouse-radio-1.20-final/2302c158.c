/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302c158. Types and names are inferred; NOT original source. */

void ram_candidate_2302c158(void)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  
  if (DAT_2300771f != '\0') {
    FUN_23026b4c();
  }
  pcVar1 = (char *)&DAT_23006bbc;
  pcVar3 = (char *)&DAT_23006bb8;
  do {
    pcVar2 = pcVar3 + 1;
    if (*pcVar3 != '\0') {
      if (*pcVar1 == '\0') {
        *pcVar3 = '\0';
      }
      else {
        *pcVar1 = *pcVar1 + -1;
      }
    }
    pcVar1 = pcVar1 + 1;
    pcVar3 = pcVar2;
  } while (pcVar2 != &DAT_23006bbb);
  return;
}


