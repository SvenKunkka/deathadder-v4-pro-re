/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08ca2c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e08ca2c(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 4);
  if ((*(char *)(param_2 + 0x18) < '\0') && (iVar2 = FUN_0e08ae78(iVar3), iVar2 != 0)) {
    return 0xffffffff;
  }
  *(int *)(param_2 + 0x1a) = param_1;
  uVar1 = FUN_0e08d5ac(*(undefined4 *)(iVar3 + 0x18),param_2);
  return uVar1;
}


