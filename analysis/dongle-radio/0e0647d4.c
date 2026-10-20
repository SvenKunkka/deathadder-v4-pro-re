/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0647d4. Types and names are inferred; NOT original source. */

uint * FUN_0e0647d4(int param_1,uint param_2)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = param_2 & 0xf;
  if ((int)(param_2 << 0x18) < 0) {
    uVar3 = uVar3 + 0x10;
  }
  piVar1 = *(int **)(*(int *)(param_1 + 0x10) + uVar3 * 4);
  if (piVar1 != (int *)0x0) {
    puVar2 = (uint *)*piVar1;
    if ((puVar2 != (uint *)0x0) && ((*puVar2 & 3) != 0)) {
      puVar2 = (uint *)puVar2[1];
    }
    return puVar2;
  }
  return (uint *)0x0;
}


