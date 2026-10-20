/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b1f30. Types and names are inferred; NOT original source. */

void FUN_0e0b1f30(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 4);
  iVar1 = FUN_0e0b1ef0();
  if (-1 < iVar1) {
    *(uint *)(iVar2 + 4) = param_3 & param_2;
    *(uint *)(iVar2 + 8) = param_2 & ~(param_3 & param_2);
    FUN_0e0b1f0c(*(undefined4 *)(param_1 + 4),param_2,0x20000,param_4);
    return;
  }
  return;
}


