/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07a8d0. Types and names are inferred; NOT original source. */

void FUN_0e07a8d0(undefined4 param_1,char *param_2)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  
  if (*param_2 == '\x03') {
    DAT_23007712 = 1;
    FUN_0e07a77c(param_2[1],(int)param_2[4],DAT_23007713);
    bVar3 = param_2[5];
    bVar1 = param_2[6];
    cVar2 = param_2[7];
  }
  else {
    if (*param_2 != '\x04') {
      FUN_0e085e6c("Unexpected test type: %d\n");
      return;
    }
    DAT_23007712 = 1;
    FUN_0e07a810(param_2[1],DAT_23007713,param_2[4]);
    bVar3 = param_2[4];
    bVar1 = param_2[5];
    cVar2 = param_2[6];
  }
  if ((byte)(cVar2 + DAT_23007713) <= bVar1) {
    bVar3 = cVar2 + DAT_23007713;
  }
  DAT_23007713 = bVar3;
  DAT_23007712 = 0;
  return;
}


