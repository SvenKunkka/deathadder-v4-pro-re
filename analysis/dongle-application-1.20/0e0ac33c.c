/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ac33c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0e0ac33c(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if ((_DAT_2f0119c4 == 0) || (iVar3 = *(int *)(_DAT_2f0119c4 + 4), iVar3 == 0)) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = FUN_0e0b2050();
    uVar2 = iVar3 - iVar1;
    uVar2 = (uVar2 & ~((int)uVar2 >> 0x1f)) >> 5;
  }
  return uVar2;
}


