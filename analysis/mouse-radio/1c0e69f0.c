/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e69f0. Types and names are inferred; NOT original source. */

void FUN_1c0e69f0(undefined4 param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  byte bVar6;
  byte bVar7;
  
  puVar5 = DAT_1c0e6a54;
  pbVar4 = DAT_1c0e6a50;
  if (*param_2 == '\x03') {
    bVar6 = *DAT_1c0e6a50;
    cVar1 = param_2[1];
    cVar2 = param_2[4];
    *DAT_1c0e6a54 = 1;
    FUN_1c0e689c(cVar1,(int)cVar2,bVar6);
    bVar6 = param_2[5];
    bVar3 = param_2[6];
    cVar1 = param_2[7];
  }
  else {
    if (*param_2 != '\x04') {
      FUN_1c0f1ff8(DAT_1c0e6a58);
      return;
    }
    cVar1 = param_2[4];
    cVar2 = param_2[1];
    bVar6 = *DAT_1c0e6a50;
    *DAT_1c0e6a54 = 1;
    FUN_1c0e6930(cVar2,bVar6,cVar1);
    bVar6 = param_2[4];
    bVar3 = param_2[5];
    cVar1 = param_2[6];
  }
  bVar7 = cVar1 + *pbVar4;
  if (bVar7 <= bVar3) {
    bVar6 = bVar7;
  }
  *pbVar4 = bVar6;
  *puVar5 = 0;
  return;
}


