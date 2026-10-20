/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b0fb2. Types and names are inferred; NOT original source. */

int FUN_0e0b0fb2(int *param_1)

{
  int iVar1;
  ushort uVar2;
  
  uVar2 = *(ushort *)(param_1 + 6) & 7;
  if ((*(ushort *)(param_1 + 6) & 7) == 0) {
    if (*param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = 3;
    }
    return iVar1;
  }
  if (uVar2 != 2) {
    if (uVar2 != 1) {
      return 0;
    }
    if (*param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = 5;
    }
    return iVar1;
  }
  return (uint)(*(short *)((int)param_1 + 0x1a) == 0) << 2;
}


