/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b27ba. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0b27ba(int param_1,int *param_2)

{
  uint uVar1;
  
  uVar1 = param_2[1] & *(uint *)(param_1 + 100);
  if (*(int *)(param_1 + 0x68) << 0x1f < 0) {
    if (*(uint *)(param_1 + 100) != uVar1) {
      return 0;
    }
  }
  else if (uVar1 == 0) {
    return 0;
  }
  *(undefined1 *)(param_1 + 0x6c) = 1;
  *(int *)(param_1 + 0x60) = *param_2;
  *param_2 = param_1;
  FUN_0e0b26cc(param_1 + 0x18);
  return 0;
}


