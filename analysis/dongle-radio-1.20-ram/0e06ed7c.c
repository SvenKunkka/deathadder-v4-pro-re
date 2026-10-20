/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06ed7c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06ed7c(int param_1,int *param_2)

{
  uint uVar1;
  
  uVar1 = param_2[1] & *(uint *)(param_1 + 100);
  if ((*(uint *)(param_1 + 0x68) & 1) == 0) {
    if (uVar1 != 0) {
LAB_0e06ed9c:
      *(undefined1 *)(param_1 + 0x6c) = 1;
      *(int *)(param_1 + 0x60) = *param_2;
      *param_2 = param_1;
      FUN_0e06e768(param_1 + 0x18);
      return 0;
    }
  }
  else if (*(uint *)(param_1 + 100) == uVar1) goto LAB_0e06ed9c;
  return 0;
}


