/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c102dcc. Types and names are inferred; NOT original source. */

int * FUN_1c102dcc(uint param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  int extraout_r3;
  int iVar3;
  int iVar4;
  
  iVar1 = FUN_1c101808();
  iVar3 = extraout_r3;
  iVar4 = DAT_1c102e20;
  if (iVar1 == 0) {
    iVar3 = *(int *)(DAT_1c102e1c + 8);
    iVar4 = *(int *)(iVar3 + 0x80);
    if (*(int *)(iVar3 + 0x80) == 0) {
      return (int *)0x0;
    }
  }
  if ((param_2 < 0xfffffffc) &&
     (piVar2 = (int *)FUN_1c1009c4(iVar4,param_1 | 4,param_2 + 4,iVar3,0,0), piVar2 != (int *)0x0))
  {
    *piVar2 = iVar4;
    return piVar2 + 1;
  }
  return (int *)0x0;
}


