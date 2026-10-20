/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ae034. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0ae034(uint *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  *param_1 = uVar2 & 0x1f;
  if (uVar2 < 0x140) {
    uVar1 = *(undefined4 *)(&DAT_0e0b3c9c + (uVar2 >> 5) * 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


