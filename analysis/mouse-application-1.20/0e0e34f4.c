/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e34f4. Types and names are inferred; NOT original source. */

void FUN_0e0e34f4(short param_1,char param_2,undefined4 param_3,undefined1 *param_4)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  uVar2 = (uint)param_1;
  bVar4 = -1 < (int)uVar2;
  if (bVar4) {
    uVar2 = uVar2 + 0xe0000000;
  }
  else {
    param_4 = &DAT_e000ed14;
  }
  cVar1 = (param_2 + '\x01') * ' ';
  if (bVar4) {
    uVar3 = uVar2 + 0xe100;
    *(char *)(uVar2 + 0xe400) = cVar1;
  }
  else {
    uVar3 = uVar2 & 0xf;
  }
  if (!bVar4) {
    param_4[uVar3] = cVar1;
  }
  return;
}


