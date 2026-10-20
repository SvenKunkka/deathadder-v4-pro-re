/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23029d04. Types and names are inferred; NOT original source. */

int FUN_23029d04(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  
  uVar3 = (uint)*(byte *)(param_1 + 4);
  if ((&DAT_23007298)[uVar3 * 0xc] == '\0') {
    *(undefined4 *)(&DAT_23007290 + uVar3 * 0xc) = param_3;
    if (param_2 == 0) {
      bVar2 = true;
      iVar1 = 0xbad0000;
    }
    else {
      *(undefined4 *)(&DAT_23007294 + uVar3 * 0xc) = *(undefined4 *)(param_2 + 8);
      iVar1 = FUN_23029e88();
      bVar2 = iVar1 == 0xbad0000;
    }
    (&DAT_23007298)[uVar3 * 0xc] = bVar2;
    return iVar1;
  }
  return 0xbad000c;
}


