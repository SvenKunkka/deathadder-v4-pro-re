/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0acaec. Types and names are inferred; NOT original source. */

undefined4 vector_11(void)

{
  undefined4 uVar1;
  uint unaff_lr;
  
  if ((unaff_lr & 4) == 0) {
    uVar1 = getMainStackPointer();
  }
  else {
    uVar1 = getProcessStackPointer();
  }
  FUN_0e0b1d04();
  return uVar1;
}


