/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061b98. Types and names are inferred; NOT original source. */

int FUN_0e061b98(int *param_1,undefined1 param_2)

{
  ushort uVar1;
  int iVar2;
  
  uVar1 = *(ushort *)(param_1 + 1);
  iVar2 = *param_1;
  *(ushort *)(param_1 + 1) = uVar1 + 1;
  *(undefined1 *)(iVar2 + (uint)uVar1) = param_2;
  return iVar2 + (uint)uVar1;
}


