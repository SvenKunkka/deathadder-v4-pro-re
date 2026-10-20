/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0884ec. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0884ec(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *param_1;
  iVar1 = FUN_0e088488(iVar2);
  if (iVar1 == 0) {
    param_1[1] = 0;
    param_1[2] = 0;
    **(int **)(iVar2 + 4) = param_1[1];
    **(int **)*param_1 = param_1[2];
    DataMemoryBarrier(0x1b);
    FUN_0e097638(*(undefined4 *)(*param_1 + 4),4);
    FUN_0e097638(*(undefined4 *)*param_1,4);
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffea;
  }
  return uVar3;
}


