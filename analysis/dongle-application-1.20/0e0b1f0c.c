/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b1f0c. Types and names are inferred; NOT original source. */

uint FUN_0e0b1f0c(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  bool bVar2;
  
  if (*(char *)(param_1 + 0x18) == '\x01') {
    param_3 = param_3 << 0xe;
    bVar2 = param_3 < 0;
    if (bVar2) {
      param_3 = *(int *)(param_1 + 4);
    }
    if (bVar2) {
      *(undefined4 *)(param_3 + 0x44) = param_2;
    }
    uVar1 = FUN_0e0ad794(1);
    uVar1 = uVar1 & (int)uVar1 >> 0x1f;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


