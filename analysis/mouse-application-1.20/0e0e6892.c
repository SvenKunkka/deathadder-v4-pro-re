/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e6892. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0e6892(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if ((((param_1 == 0) || (param_2 == (int *)0x0)) || (*param_2 == 0)) || (param_2[1] == 0)) {
    uVar1 = 0xffffffea;
  }
  else {
    FUN_0e0e74d0(param_1,0,0x1c,param_2[1],param_4);
    uVar1 = 0;
    *(int **)(param_1 + 0x10) = param_2;
  }
  return uVar1;
}


