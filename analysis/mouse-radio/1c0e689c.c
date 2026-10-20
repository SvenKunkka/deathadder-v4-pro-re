/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e689c. Types and names are inferred; NOT original source. */

void FUN_1c0e689c(int param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  char *pcVar2;
  
  puVar1 = DAT_1c0e6924;
  DAT_1c0e6924[0x100] = 0;
  puVar1[0x124] = 0xffffffff;
  puVar1[0x88] = 0;
  puVar1[4] = 1;
  do {
  } while (puVar1[0x88] == 0);
  puVar1[0x88] = 0;
  puVar1[0x140] = param_1;
  puVar1[0x100] = puVar1[0x100] | 1;
  FUN_1c0e65e0(param_2);
  pcVar2 = DAT_1c0e6928;
  if (param_1 == 0xf) {
    if (param_3 - 0xbU < 0x10) {
      param_3 = param_3 * 5 + -0x32;
    }
    else {
      param_3 = 5;
    }
  }
  DAT_1c0e6924[0x1c2] = param_3;
  if ((*pcVar2 != '\0') && (FUN_1c0e6828(0), *pcVar2 != '\0')) {
    *DAT_1c0e692c = 1;
    return;
  }
  *DAT_1c0e6924 = 1;
  return;
}


