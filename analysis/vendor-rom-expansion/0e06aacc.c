
uint FUN_0e06aacc(int param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = (uint)(byte)(&DAT_23006e60)[param_1 * 0xc];
  if (uVar4 == 0xff) {
    return 0;
  }
  uVar3 = 0;
  if ((*(uint *)(**(int **)(&DAT_23006e58 + param_1 * 0xc) + 0x500) >> uVar4 & 1) != 0) {
    uVar3 = *(uint *)(**(int **)(&DAT_23006e5c + param_1 * 0xc) + 0x500) >> uVar4 & 1;
    if ((uVar3 != 0) && (iVar1 = FUN_0e06a0d4(), iVar1 != 0)) {
      piVar2 = (int *)FUN_0e06ab78();
      return *(uint *)(*piVar2 + 0x500) >> uVar4 & 1;
    }
  }
  return uVar3;
}


