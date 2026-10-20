/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07e228. Types and names are inferred; NOT original source. */

undefined4 FUN_0e07e228(void)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_0e07e24c;
  uVar3 = *DAT_0e07e24c;
  *DAT_0e07e24c = uVar3 + 1;
  if (0x1d < uVar3 + 1) {
    uVar2 = (**(code **)(*(int *)(*DAT_0e07e250 + 8) + 0xc))(*DAT_0e07e250,DAT_0e07e250[1]);
    *puVar1 = 0;
    return uVar2;
  }
  return 0;
}


