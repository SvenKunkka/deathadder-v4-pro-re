/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b269a. Types and names are inferred; NOT original source. */

uint FUN_0e0b269a(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = FUN_0e0b0260();
  uVar2 = FUN_0e0b0270();
  if (iVar1 != 0) {
    uVar3 = *(uint *)(iVar1 + 0x10) - uVar2;
    iVar1 = (*(int *)(iVar1 + 0x14) - ((int)uVar2 >> 0x1f)) -
            (uint)(*(uint *)(iVar1 + 0x10) < uVar2);
    if (iVar1 < (int)(uint)(uVar3 < 0x80000000)) {
      if (-1 < iVar1) {
        return uVar3;
      }
      return 0;
    }
  }
  return 0x7fffffff;
}


