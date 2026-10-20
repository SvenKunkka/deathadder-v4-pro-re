/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b212a. Types and names are inferred; NOT original source. */

void FUN_0e0b212a(int *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_0e0ae0d8(param_2);
  if (((int)uVar3 != 0) && (uVar3 = FUN_0e0ae0c0((int)((ulonglong)uVar3 >> 0x20)), (int)uVar3 == 0))
  {
    uVar1 = FUN_0e0ae0a8((int)((ulonglong)uVar3 >> 0x20));
    *(int *)(*param_1 + 0x338) = 1 << (uVar1 & 0xff);
    iVar2 = *param_1 + (short)uVar1 * 4;
    *(uint *)(iVar2 + 0x510) = *(uint *)(iVar2 + 0x510) & 0xfffffffc;
    return;
  }
  FUN_0e0b210c(param_2,0);
  return;
}


