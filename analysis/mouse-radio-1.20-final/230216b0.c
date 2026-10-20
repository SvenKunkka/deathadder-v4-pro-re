/* Automatically decompiled from Suit2FWData__radio_radio.bin at 230216b0. Types and names are inferred; NOT original source. */

undefined4 FUN_230216b0(int param_1)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar2 = (char *)(param_1 * 0xee0 + 0x23002ad5);
  do {
    pcVar1 = pcVar2 + 7;
    pcVar2 = pcVar2 + 1;
    if (*pcVar2 != *pcVar1) {
      return 0;
    }
  } while (pcVar2 != (char *)(param_1 * 0xee0 + 0x23002adb));
  return 1;
}


