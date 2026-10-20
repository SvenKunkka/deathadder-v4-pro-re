/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0806c4. Types and names are inferred; NOT original source. */

void FUN_0e0806c4(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = DAT_0e080718;
  FUN_0e094d84(DAT_0e08071c,param_2,0x9d,0);
  FUN_0e08068c();
  FUN_0e0977f8(0x7f,0x18);
  FUN_0e0977f8(0x7a,*pcVar2);
  FUN_0e0977f8(0x7f,0);
  FUN_0e094e80(DAT_0e08071c);
  cVar1 = *pcVar2;
  if (cVar1 == '\0') {
    *DAT_0e080720 = 0;
  }
  else {
    if (cVar1 == -0x7b) {
      *DAT_0e080720 = 1;
      return;
    }
    if (cVar1 == -0x71) {
      *DAT_0e080720 = 2;
      return;
    }
  }
  return;
}


