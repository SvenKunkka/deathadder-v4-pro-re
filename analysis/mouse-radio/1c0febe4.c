/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0febe4. Types and names are inferred; NOT original source. */

undefined4 FUN_1c0febe4(int *param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  
  iVar1 = FUN_1c0feb60();
  if (iVar1 != 0xf) {
    return DAT_1c0fec18;
  }
  bVar5 = 0;
  do {
    uVar3 = FUN_1c0febc0();
    uVar4 = (uint)bVar5;
    bVar5 = bVar5 + 1;
    if (uVar3 <= uVar4) {
      return 0;
    }
    piVar2 = (int *)FUN_1c0febc4(uVar4);
  } while (*piVar2 != *param_1);
  return 0;
}


