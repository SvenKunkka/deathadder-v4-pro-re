/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020160. Types and names are inferred; NOT original source. */

bool FUN_23020160(undefined4 param_1,int param_2,char *param_3,uint param_4)

{
  char *pcVar1;
  char *pcVar2;
  
  if (param_2 == 1) {
    if (param_4 != 0) {
      pcVar2 = param_3;
      do {
        pcVar1 = pcVar2 + 1;
        if (*pcVar2 != '\0') {
          return true;
        }
        pcVar2 = pcVar1;
      } while (param_3 + param_4 != pcVar1);
      return false;
    }
  }
  else if (param_2 == 2) {
    if (param_4 != 0) {
      pcVar2 = param_3;
      do {
        pcVar1 = pcVar2 + 1;
        if (*pcVar2 != '\0') {
          return true;
        }
        pcVar2 = pcVar1;
      } while (pcVar1 != param_3 + param_4);
      return false;
    }
  }
  else if ((param_2 == 4) && (*param_3 == '\x01')) {
    return 1 < param_4;
  }
  return false;
}


