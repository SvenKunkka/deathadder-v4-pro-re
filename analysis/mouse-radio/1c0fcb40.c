/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0fcb40. Types and names are inferred; NOT original source. */

int FUN_1c0fcb40(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  *DAT_1c0fcbbc = param_1;
  iVar2 = FUN_1c10108c(DAT_1c0fcbc0,8);
  if (-1 < iVar2) {
    *DAT_1c0fcbc4 = 0xff000000;
    FUN_1c100bd8(DAT_1c0fcbcc,DAT_1c0fcbc8,8,2);
    uVar1 = DAT_1c0fcbd8;
    iVar5 = DAT_1c0fcbd0 + 0x1b0;
    iVar2 = DAT_1c0fcbd0;
    iVar4 = DAT_1c0fcbd4;
    do {
      iVar3 = iVar2 + 0x90;
      FUN_1c1018d0(iVar2,iVar4,0x400,uVar1,0,0,0,2,0);
      iVar4 = iVar4 + 0x400;
      iVar2 = iVar3;
    } while (iVar3 != iVar5);
    iVar2 = 0;
  }
  return iVar2;
}


