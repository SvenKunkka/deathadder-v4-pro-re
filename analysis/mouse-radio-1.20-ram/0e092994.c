/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e092994. Types and names are inferred; NOT original source. */

uint FUN_0e092994(int param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = (uint)(byte)(&DAT_23007340)[param_1 * 0xc];
  if (uVar4 == 0xff) {
    return 0;
  }
  uVar3 = 0;
  if ((*(uint *)(**(int **)(&DAT_23007338 + param_1 * 0xc) + 0x500) >> uVar4 & 1) != 0) {
    uVar3 = *(uint *)(**(int **)(&DAT_2300733c + param_1 * 0xc) + 0x500) >> uVar4 & 1;
    if ((uVar3 != 0) && (iVar1 = FUN_0e091f9c(), iVar1 != 0)) {
      piVar2 = (int *)FUN_0e092a40();
      return *(uint *)(*piVar2 + 0x500) >> uVar4 & 1;
    }
  }
  return uVar3;
}


