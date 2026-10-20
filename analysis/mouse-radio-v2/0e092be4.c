/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e092be4. Types and names are inferred; NOT original source. */

undefined4 FUN_0e092be4(int *param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  
  iVar1 = FUN_0e092b60();
  if (iVar1 != 0xf) {
    return DAT_0e092c18;
  }
  bVar5 = 0;
  do {
    uVar3 = FUN_0e092bc0();
    uVar4 = (uint)bVar5;
    bVar5 = bVar5 + 1;
    if (uVar3 <= uVar4) {
      return 0;
    }
    piVar2 = (int *)FUN_0e092bc4(uVar4);
  } while (*piVar2 != *param_1);
  return 0;
}


