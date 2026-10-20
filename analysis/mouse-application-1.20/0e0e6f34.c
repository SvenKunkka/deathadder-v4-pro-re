/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e6f34. Types and names are inferred; NOT original source. */

int FUN_0e0e6f34(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)FUN_0e0e6f24();
  iVar3 = puVar1[1];
  if (((code *)*puVar1 == (code *)0x0) || (iVar2 = (*(code *)*puVar1)(iVar3), iVar2 == 0)) {
    iVar2 = 0;
  }
  else {
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    if (0xfe < iVar2) {
      iVar2 = 0xff;
    }
    **(undefined1 **)(iVar3 + 0xc) = (char)iVar2;
  }
  *(byte *)(*(int *)(iVar3 + 0xc) + 1) = *(byte *)(*(int *)(iVar3 + 0xc) + 1) | 1;
  return iVar2;
}


