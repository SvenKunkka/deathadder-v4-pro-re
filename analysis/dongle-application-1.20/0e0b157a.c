/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b157a. Types and names are inferred; NOT original source. */

int FUN_0e0b157a(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 0x10);
  iVar1 = FUN_0e0b14f2(uVar2,param_3,param_4,param_4,param_1,param_2);
  if (iVar1 < 0) {
    FUN_0e0b14f2(uVar2,param_3,0xffffffff);
  }
  else {
    iVar1 = FUN_0e0b1532(uVar2,0,*(undefined1 *)(param_2 + 0xc),iVar1,param_4);
  }
  return iVar1;
}


