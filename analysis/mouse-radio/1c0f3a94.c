/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f3a94. Types and names are inferred; NOT original source. */

int FUN_1c0f3a94(int param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  
  if (3 < param_2) {
    return 0;
  }
  uVar4 = (uint)*(byte *)(param_2 + param_1 + 0xec);
  if (uVar4 < 4) {
    iVar6 = uVar4 * 0x10;
    puVar2 = (uint *)(iVar6 + 0xb0 + param_1);
    uVar1 = *puVar2 & 0xff;
    if (uVar1 == 3) {
      if (*(int *)(param_1 + iVar6 + 0xb4) == 0) goto LAB_1c0f3adc;
    }
    else if (uVar1 == 2) {
      *puVar2 = 3;
      iVar3 = *(int *)(param_1 + uVar4 * 0x10 + 0xac);
      pcVar5 = *(code **)(iVar3 + 8);
      if (pcVar5 != (code *)0x0) {
        (*pcVar5)(*(undefined4 *)(iVar3 + 0x14));
      }
LAB_1c0f3adc:
      return param_1 + iVar6 + 0xac;
    }
  }
  return 0;
}


