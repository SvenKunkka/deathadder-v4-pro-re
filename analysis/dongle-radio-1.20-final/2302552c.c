/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302552c. Types and names are inferred; NOT original source. */

void FUN_2302552c(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 != 0) && (param_2 != 0xff)) {
    *(int *)(&DAT_23006590 + (param_1 + 4) * 2) =
         *(int *)(&DAT_23006590 + (param_1 + 4) * 2) + param_2;
    *(int *)(&DAT_23006590 + (param_1 + 6) * 2) = *(int *)(&DAT_23006590 + (param_1 + 6) * 2) + 1;
    iVar1 = (param_1 + 8) * 4;
    *(int *)(&DAT_23006598 + iVar1) = *(int *)(&DAT_23006598 + iVar1) + param_2;
    iVar1 = (param_1 + 10) * 4;
    DAT_230065e6 = 5;
    *(int *)(&DAT_23006598 + iVar1) = *(int *)(&DAT_23006598 + iVar1) + 1;
    return;
  }
  DAT_230065e6 = 5;
  return;
}


