/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e092abc. Types and names are inferred; NOT original source. */

uint FUN_0e092abc(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = DAT_0e092b14 + param_1 * 0xc;
  uVar4 = (uint)*(byte *)(iVar2 + 8);
  if (uVar4 == 0xff) {
    return 0;
  }
  uVar3 = 0;
  if ((*(uint *)(**(int **)(DAT_0e092b14 + param_1 * 0xc) + 0x500) >> uVar4 & 1) != 0) {
    uVar3 = *(uint *)(**(int **)(iVar2 + 4) + 0x500) >> uVar4 & 1;
    if ((uVar3 != 0) && (iVar2 = FUN_0e0920c4(), iVar2 != 0)) {
      piVar1 = (int *)FUN_0e092b68();
      return *(uint *)(*piVar1 + 0x500) >> uVar4 & 1;
    }
  }
  return uVar3;
}


