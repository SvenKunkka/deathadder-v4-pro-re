/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08c8c8. Types and names are inferred; NOT original source. */

int FUN_0e08c8c8(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  uint uVar4;
  
  iVar1 = FUN_0e08c5ac();
  if ((iVar1 != 0) && (param_2 < 0x10)) {
    uVar4 = (uint)*(byte *)(param_1 + param_2 + 0x36);
    if (param_3 == uVar4) {
      return 0;
    }
    iVar2 = FUN_0e08c75c(param_1,iVar1,0,param_2,param_3);
    if (iVar2 == 0) {
      iVar2 = FUN_0e08c75c(param_1,iVar1,2,param_2,uVar4);
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar2 = FUN_0e08c75c(param_1,iVar1,1,param_2,param_3);
      if (iVar2 != 0) {
        return iVar2;
      }
      pcVar3 = *(code **)(*(int *)(*(int *)(iVar1 + 4) + 8) + 4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(*(int *)(iVar1 + 4),param_2,param_3);
      }
      *(char *)(param_1 + param_2 + 0x36) = (char)param_3;
      return 0;
    }
  }
  return -2;
}


