/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05fd94. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05fd94(uint param_1,undefined4 *param_2)

{
  int iVar1;
  byte *pbVar2;
  
  if (DAT_230004f8 == (byte *)0x0) {
    return 0xfffffff3;
  }
  iVar1 = 0;
  pbVar2 = DAT_230004f8;
  while (iVar1 = iVar1 + 1, *pbVar2 != param_1) {
    pbVar2 = pbVar2 + 0x10;
    if (iVar1 == 4) {
      return 0xfffffffe;
    }
  }
  if ((*(int *)(pbVar2 + 0xc) != 0) && (iVar1 = FUN_0e06c6c0(), iVar1 != 0)) {
    *param_2 = pbVar2;
    return 0;
  }
  return 0xffffffed;
}


