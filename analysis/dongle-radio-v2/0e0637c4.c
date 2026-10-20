/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0637c4. Types and names are inferred; NOT original source. */

int FUN_0e0637c4(int param_1)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  int *piVar4;
  
  uVar3 = (*(byte *)(*(int *)(*(int *)(param_1 + 0x18) + 0x10) + 0x80) & 0x7f) >> 5;
  if (uVar3 == 2) {
    uVar2 = 0x20;
  }
  else if (uVar3 == 3) {
    uVar2 = 0x40;
  }
  else if (uVar3 == 1) {
    uVar2 = 0x10;
  }
  else {
    uVar2 = 8;
  }
  *(undefined1 *)(*(int *)(param_1 + 100) + 7) = uVar2;
  for (piVar4 = *(int **)(param_1 + 0x58); piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
    iVar1 = FUN_0e063588(param_1,1,piVar4);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  piVar4 = *(int **)(param_1 + 0x50);
  while( true ) {
    if (piVar4 == (int *)0x0) {
      return 0;
    }
    iVar1 = FUN_0e063588(param_1,0,piVar4);
    if (iVar1 != 0) break;
    piVar4 = (int *)*piVar4;
  }
  return iVar1;
}


