/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e090b40. Types and names are inferred; NOT original source. */

int FUN_0e090b40(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  *DAT_0e090bbc = param_1;
  iVar2 = FUN_0e09508c(DAT_0e090bc0,8);
  if (-1 < iVar2) {
    *DAT_0e090bc4 = 0xff000000;
    FUN_0e094bd8(DAT_0e090bcc,DAT_0e090bc8,8,2);
    uVar1 = DAT_0e090bd8;
    iVar5 = DAT_0e090bd0 + 0x1b0;
    iVar2 = DAT_0e090bd0;
    iVar4 = DAT_0e090bd4;
    do {
      iVar3 = iVar2 + 0x90;
      FUN_0e0958d0(iVar2,iVar4,0x400,uVar1,0,0,0,2,0);
      iVar4 = iVar4 + 0x400;
      iVar2 = iVar3;
    } while (iVar3 != iVar5);
    iVar2 = 0;
  }
  return iVar2;
}


