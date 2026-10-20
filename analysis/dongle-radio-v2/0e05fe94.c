/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05fe94. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05fe94(uint param_1,undefined4 *param_2)

{
  int iVar1;
  byte *pbVar2;
  
  pbVar2 = (byte *)*DAT_0e05fedc;
  if (pbVar2 == (byte *)0x0) {
    return 0xfffffff3;
  }
  if (0 < *DAT_0e05fee0) {
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      if (*pbVar2 == param_1) {
        if ((*(int *)(pbVar2 + 0xc) != 0) && (iVar1 = FUN_0e06c75c(), iVar1 != 0)) {
          *param_2 = pbVar2;
          return 0;
        }
        return 0xffffffed;
      }
      pbVar2 = pbVar2 + 0x10;
    } while (*DAT_0e05fee0 != iVar1);
  }
  return 0xfffffffe;
}


