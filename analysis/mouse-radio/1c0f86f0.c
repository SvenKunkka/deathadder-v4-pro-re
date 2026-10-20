/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f86f0. Types and names are inferred; NOT original source. */

int FUN_1c0f86f0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  code *pcVar4;
  uint uVar5;
  
  pcVar4 = *(code **)(*(int *)(param_1 + 8) + 0x30);
  if ((pcVar4 != (code *)0x0) && (iVar1 = (*pcVar4)(), iVar1 != 0)) {
    iVar2 = 0;
    puVar3 = (undefined4 *)(iVar1 + -4);
    while( true ) {
      puVar3 = puVar3 + 1;
      if (((byte *)*puVar3 == (byte *)0x0) || (uVar5 = (uint)*(byte *)*puVar3, uVar5 == 0)) break;
      iVar2 = iVar2 + uVar5;
    }
    return iVar2;
  }
  return 0;
}


