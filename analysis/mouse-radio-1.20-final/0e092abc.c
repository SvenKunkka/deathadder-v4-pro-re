/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e092abc. Types and names are inferred; NOT original source. */

undefined4 * FUN_0e092abc(int *param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  
  iVar1 = FUN_0e092a38();
  if (iVar1 != 0xf) {
    return &DAT_0e09b800;
  }
  bVar5 = 0;
  do {
    uVar3 = FUN_0e092a98();
    uVar4 = (uint)bVar5;
    bVar5 = bVar5 + 1;
    if (uVar3 <= uVar4) {
      return (undefined4 *)0x0;
    }
    piVar2 = (int *)FUN_0e092a9c(uVar4);
  } while (*piVar2 != *param_1);
  return (undefined4 *)0x0;
}


