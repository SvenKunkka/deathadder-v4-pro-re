/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e6f3a. Types and names are inferred; NOT original source. */

int FUN_0e0e6f3a(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1[1];
  if (((code *)*param_1 == (code *)0x0) || (iVar1 = (*(code *)*param_1)(iVar2), iVar1 == 0)) {
    iVar1 = 0;
  }
  else {
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    if (0xfe < iVar1) {
      iVar1 = 0xff;
    }
    **(undefined1 **)(iVar2 + 0xc) = (char)iVar1;
  }
  *(byte *)(*(int *)(iVar2 + 0xc) + 1) = *(byte *)(*(int *)(iVar2 + 0xc) + 1) | 1;
  return iVar1;
}


