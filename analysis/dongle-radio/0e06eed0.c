/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06eed0. Types and names are inferred; NOT original source. */

int * FUN_0e06eed0(uint param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  int extraout_r3;
  int iVar3;
  int iVar4;
  
  iVar1 = FUN_0e06d8cc();
  iVar3 = extraout_r3;
  iVar4 = DAT_0e06ef24;
  if (iVar1 == 0) {
    iVar3 = *(int *)(DAT_0e06ef20 + 8);
    iVar4 = *(int *)(iVar3 + 0x80);
    if (*(int *)(iVar3 + 0x80) == 0) {
      return (int *)0x0;
    }
  }
  if ((param_2 < 0xfffffffc) &&
     (piVar2 = (int *)FUN_0e06ca6c(iVar4,param_1 | 4,param_2 + 4,iVar3,0,0), piVar2 != (int *)0x0))
  {
    *piVar2 = iVar4;
    return piVar2 + 1;
  }
  return (int *)0x0;
}


