/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b2216. Types and names are inferred; NOT original source. */

int FUN_0e0b2216(undefined4 *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  
  iVar3 = param_1[1];
  if ((code *)*param_1 == (code *)0x0) {
    *(byte *)(*(int *)(iVar3 + 0xc) + 1) = *(byte *)(*(int *)(iVar3 + 0xc) + 1) | 1;
  }
  else {
    iVar1 = (*(code *)*param_1)(iVar3);
    puVar2 = *(undefined1 **)(iVar3 + 0xc);
    if (iVar1 != 0) {
      if (iVar1 < 0) {
        iVar1 = -iVar1;
      }
      if (0xfe < iVar1) {
        iVar1 = 0xff;
      }
      *puVar2 = (char)iVar1;
      *(byte *)(*(int *)(iVar3 + 0xc) + 1) = *(byte *)(*(int *)(iVar3 + 0xc) + 1) | 1;
      return iVar1;
    }
    puVar2[1] = puVar2[1] | 1;
  }
  FUN_0e0b1cda(iVar3);
  return 0;
}


