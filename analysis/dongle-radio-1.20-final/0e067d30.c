/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e067d30. Types and names are inferred; NOT original source. */

undefined4 FUN_0e067d30(int param_1,uint param_2,uint *param_3)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(param_1 + 4);
  *param_3 = uVar2;
  if (uVar2 + (uint)*(byte *)(param_1 + 8) * 8 <= uVar2) {
    return 0xfffffffe;
  }
  if (*(byte *)(uVar2 + 5) == param_2) {
    return 0;
  }
  do {
    uVar3 = uVar2 + 8;
    *param_3 = uVar3;
    if (*(int *)(param_1 + 4) + (uint)*(byte *)(param_1 + 8) * 8 <= uVar3) {
      return 0xfffffffe;
    }
    pbVar1 = (byte *)(uVar2 + 0xd);
    uVar2 = uVar3;
  } while (*pbVar1 != param_2);
  return 0;
}


