/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230254a0. Types and names are inferred; NOT original source. */

void FUN_230254a0(uint param_1,undefined1 param_2,undefined4 param_3,uint param_4,ushort param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (uint)param_5;
  FUN_23025004(param_1 & 0xff,param_2,param_3,param_4 & 0xff,param_4);
  if ((uVar4 != 0) && (uVar4 != 0xff)) {
    *(uint *)(&DAT_23006590 + (param_1 + 4) * 2) =
         *(int *)(&DAT_23006590 + (param_1 + 4) * 2) + uVar4;
    *(int *)(&DAT_23006590 + (param_1 + 6) * 2) = *(int *)(&DAT_23006590 + (param_1 + 6) * 2) + 1;
    iVar1 = (param_1 + 8) * 4;
    iVar2 = (param_1 + 10) * 4;
    iVar3 = *(int *)(&DAT_23006598 + iVar2);
    *(uint *)(&DAT_23006598 + iVar1) = uVar4 + *(int *)(&DAT_23006598 + iVar1);
    *(int *)(&DAT_23006598 + iVar2) = iVar3 + 1;
  }
  DAT_230065e6 = 5;
  return;
}


