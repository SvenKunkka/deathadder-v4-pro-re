/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07a89c. Types and names are inferred; NOT original source. */

void FUN_0e07a89c(int param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  char *pcVar2;
  
  puVar1 = DAT_0e07a924;
  DAT_0e07a924[0x100] = 0;
  puVar1[0x124] = 0xffffffff;
  puVar1[0x88] = 0;
  puVar1[4] = 1;
  do {
  } while (puVar1[0x88] == 0);
  puVar1[0x88] = 0;
  puVar1[0x140] = param_1;
  puVar1[0x100] = puVar1[0x100] | 1;
  FUN_0e07a5e0(param_2);
  pcVar2 = DAT_0e07a928;
  if (param_1 == 0xf) {
    if (param_3 - 0xbU < 0x10) {
      param_3 = param_3 * 5 + -0x32;
    }
    else {
      param_3 = 5;
    }
  }
  DAT_0e07a924[0x1c2] = param_3;
  if ((*pcVar2 != '\0') && (FUN_0e07a828(0), *pcVar2 != '\0')) {
    *DAT_0e07a92c = 1;
    return;
  }
  *DAT_0e07a924 = 1;
  return;
}


