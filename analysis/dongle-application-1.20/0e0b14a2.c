/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b14a2. Types and names are inferred; NOT original source. */

int FUN_0e0b14a2(int *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = *param_1;
  uVar1 = *(uint *)(iVar6 + 0x20);
  uVar3 = (param_3 + uVar1 + 3) / uVar1;
  iVar4 = param_2;
  if (-1 < param_4) {
    uVar5 = (param_4 + 3 + uVar1) / uVar1;
    if (uVar3 < uVar5) {
      return -0x16;
    }
    uVar3 = uVar3 - uVar5;
    *(int *)(*(int *)(iVar6 + 0x1c) + param_2 * uVar1) = param_4;
    iVar4 = param_2 + uVar5;
  }
  iVar2 = param_2;
  if ((uVar3 != 0) &&
     (iVar2 = FUN_0e0b0f46(*(undefined4 *)(iVar6 + 0x28),uVar3,iVar4,param_4,param_4), -1 < iVar2))
  {
    FUN_0e0af700(param_1 + 0x27);
    iVar2 = param_2;
  }
  return iVar2;
}


