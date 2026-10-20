/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08d65c. Types and names are inferred; NOT original source. */

int FUN_0e08d65c(int param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  (**(code **)(iVar2 + 0x3c))();
  iVar1 = FUN_0e08a50c(&DAT_23001758,param_3,0,0,param_4);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x18) = 0;
    *(undefined4 *)(iVar1 + 0x1c) = 0;
    *(undefined2 *)(iVar1 + 0x20) = 0;
    *(undefined1 *)(iVar1 + 0x18) = param_2;
  }
  (**(code **)(iVar2 + 0x40))(param_1);
  return iVar1;
}


