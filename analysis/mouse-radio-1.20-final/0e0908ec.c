/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0908ec. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0908ec(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = *(undefined4 *)(param_1 + 4);
  iVar2 = *(int *)(param_1 + 0x10);
  iVar1 = FUN_0e091e1c(uVar3);
  if (iVar1 == 0xbad0000) {
    FUN_0e091db8(uVar3);
    if (*(byte *)(iVar2 + 0x24) != 0) {
      FUN_0e0973ea(iVar2,0,(uint)*(byte *)(iVar2 + 0x24) << 2);
    }
    *(undefined2 *)(iVar2 + 0x24) = 0;
    return 0;
  }
  return 0xfffffff2;
}


