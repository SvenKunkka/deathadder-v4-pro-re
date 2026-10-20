/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0686a4. Types and names are inferred; NOT original source. */

int FUN_0e0686a4(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  *DAT_0e068720 = param_1;
  iVar2 = FUN_0e06d150(DAT_0e068724,8);
  if (-1 < iVar2) {
    *DAT_0e068728 = 0xff000000;
    FUN_0e06cc54(DAT_0e068730,DAT_0e06872c,8,2);
    uVar1 = DAT_0e06873c;
    iVar5 = DAT_0e068734 + 0x1b0;
    iVar2 = DAT_0e068734;
    iVar4 = DAT_0e068738;
    do {
      iVar3 = iVar2 + 0x90;
      FUN_0e06d994(iVar2,iVar4,0x400,uVar1,0,0,0,2,0);
      iVar4 = iVar4 + 0x400;
      iVar2 = iVar3;
    } while (iVar3 != iVar5);
    iVar2 = 0;
  }
  return iVar2;
}


