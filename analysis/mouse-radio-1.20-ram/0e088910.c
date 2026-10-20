/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e088910. Types and names are inferred; NOT original source. */

undefined4 FUN_0e088910(uint param_1,undefined4 *param_2)

{
  int iVar1;
  byte *pbVar2;
  
  if (DAT_23000e9c == (byte *)0x0) {
    return 0xfffffff3;
  }
  iVar1 = 0;
  pbVar2 = DAT_23000e9c;
  while (iVar1 = iVar1 + 1, *pbVar2 != param_1) {
    pbVar2 = pbVar2 + 0x10;
    if (iVar1 == 8) {
      return 0xfffffffe;
    }
  }
  if ((*(int *)(pbVar2 + 0xc) != 0) && (iVar1 = FUN_0e094560(), iVar1 != 0)) {
    *param_2 = pbVar2;
    return 0;
  }
  return 0xffffffed;
}


