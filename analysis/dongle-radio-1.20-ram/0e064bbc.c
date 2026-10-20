/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064bbc. Types and names are inferred; NOT original source. */

uint FUN_0e064bbc(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1 + 8);
  (*(code *)puVar3[0xf])();
  uVar1 = *(uint *)(*(int *)(param_1 + 0x10) + 0xa0);
  uVar2 = (uVar1 & 3) >> 1;
  if ((int)(uVar1 << 0x1e) < 0) {
    if ((code *)*puVar3 == (code *)0x0) {
      (*(code *)puVar3[0x10])(param_1);
      return 1;
    }
    uVar2 = (*(code *)*puVar3)(param_1);
  }
  (*(code *)puVar3[0x10])(param_1);
  return uVar2;
}


