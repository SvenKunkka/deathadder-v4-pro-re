/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d830. Types and names are inferred; NOT original source. */

bool FUN_0e06d830(void)

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


