/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08d1e8. Types and names are inferred; NOT original source. */

int FUN_0e08d1e8(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined8 uVar5;
  
  uVar2 = param_2 & 0xf;
  if ((int)(param_2 << 0x18) < 0) {
    uVar2 = uVar2 + 0x10;
  }
  piVar3 = *(int **)(*(int *)(param_1 + 0x10) + uVar2 * 4);
  if (piVar3 != (int *)0x0) {
    uVar5 = FUN_0e094ee8(piVar3,param_2 << 0x18,0,0);
    iVar1 = (int)uVar5;
    if (iVar1 != 0) {
      do {
        iVar4 = (int)uVar5;
        if (*piVar3 == 0) {
          return iVar1;
        }
        uVar5 = FUN_0e094ee8(piVar3,(int)((ulonglong)uVar5 >> 0x20),0,0);
        *(int *)(iVar4 + 4) = (int)uVar5;
      } while ((int)uVar5 != 0);
      return iVar1;
    }
  }
  return 0;
}


