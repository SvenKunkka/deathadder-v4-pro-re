/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b00b0. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e0b00b0(int param_1,int param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_2 == -1 && param_1 == -1) {
    FUN_0e0b24ea(_DAT_2f011ba0);
    uVar2 = 0xffffffff;
  }
  else {
    iVar3 = FUN_0e0b0028();
    lVar1 = (longlong)iVar3 * 1000 + 0x7a11;
    uVar2 = FUN_0e0ab7a0((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),0x7a12,0);
  }
  return uVar2;
}


