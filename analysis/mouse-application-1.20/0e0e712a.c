/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e712a. Types and names are inferred; NOT original source. */

bool FUN_0e0e712a(void)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = getCurrentExceptionNumber();
    uVar2 = uVar2 & 0x1ff;
  }
  return uVar2 != 0;
}


