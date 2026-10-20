/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05cd0c. Types and names are inferred; NOT original source. */

void FUN_0e05cd0c(undefined4 param_1,char *param_2)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  
  if (*param_2 == '\x03') {
    DAT_230071e0 = 1;
    FUN_0e05cbb8(param_2[1],(int)param_2[4],DAT_230071e1);
    bVar3 = param_2[5];
    bVar1 = param_2[6];
    cVar2 = param_2[7];
  }
  else {
    if (*param_2 != '\x04') {
      FUN_0e05d634("Unexpected test type: %d\n");
      return;
    }
    DAT_230071e0 = 1;
    FUN_0e05cc4c(param_2[1],DAT_230071e1,param_2[4]);
    bVar3 = param_2[4];
    bVar1 = param_2[5];
    cVar2 = param_2[6];
  }
  if ((byte)(cVar2 + DAT_230071e1) <= bVar1) {
    bVar3 = cVar2 + DAT_230071e1;
  }
  DAT_230071e1 = bVar3;
  DAT_230071e0 = 0;
  return;
}


