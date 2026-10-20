/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b2210. Types and names are inferred; NOT original source. */

int FUN_0e0b2210(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  
  puVar1 = (undefined4 *)FUN_0e0b2200();
  iVar4 = puVar1[1];
  if ((code *)*puVar1 == (code *)0x0) {
    *(byte *)(*(int *)(iVar4 + 0xc) + 1) = *(byte *)(*(int *)(iVar4 + 0xc) + 1) | 1;
  }
  else {
    iVar2 = (*(code *)*puVar1)(iVar4);
    puVar3 = *(undefined1 **)(iVar4 + 0xc);
    if (iVar2 != 0) {
      if (iVar2 < 0) {
        iVar2 = -iVar2;
      }
      if (0xfe < iVar2) {
        iVar2 = 0xff;
      }
      *puVar3 = (char)iVar2;
      *(byte *)(*(int *)(iVar4 + 0xc) + 1) = *(byte *)(*(int *)(iVar4 + 0xc) + 1) | 1;
      return iVar2;
    }
    puVar3[1] = puVar3[1] | 1;
  }
  FUN_0e0b1cda(iVar4);
  return 0;
}


