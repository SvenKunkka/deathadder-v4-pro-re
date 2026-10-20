/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05ce0c. Types and names are inferred; NOT original source. */

void FUN_0e05ce0c(undefined4 param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  byte bVar6;
  byte bVar7;
  
  puVar5 = DAT_0e05ce70;
  pbVar4 = DAT_0e05ce6c;
  if (*param_2 == '\x03') {
    bVar6 = *DAT_0e05ce6c;
    cVar1 = param_2[1];
    cVar2 = param_2[4];
    *DAT_0e05ce70 = 1;
    FUN_0e05ccb8(cVar1,(int)cVar2,bVar6);
    bVar6 = param_2[5];
    bVar3 = param_2[6];
    cVar1 = param_2[7];
  }
  else {
    if (*param_2 != '\x04') {
      FUN_0e05d734(DAT_0e05ce74);
      return;
    }
    cVar1 = param_2[4];
    cVar2 = param_2[1];
    bVar6 = *DAT_0e05ce6c;
    *DAT_0e05ce70 = 1;
    FUN_0e05cd4c(cVar2,bVar6,cVar1);
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


