/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06da68. Types and names are inferred; NOT original source. */

void FUN_0e06da68(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  bool bVar4;
  
  iVar1 = DAT_0e06daa4;
  piVar3 = *(int **)(DAT_0e06daa4 + 0x18);
  if ((piVar3 == (int *)(DAT_0e06daa4 + 0x18)) || (piVar3 == (int *)0x0)) {
    piVar3 = *(int **)(DAT_0e06daa4 + 0xc);
  }
  iVar2 = *(int *)(DAT_0e06daa4 + 8);
  if (((((param_1 != 0) || ((*(byte *)(iVar2 + 0xd) & 0x1f) != 0)) ||
       (*(int *)((int)piVar3 + 0x18) != 0)) || (*(ushort *)(iVar2 + 0xe) < 0x80)) &&
     (bVar4 = piVar3 != (int *)iVar2, iVar2 = (int)piVar3, bVar4)) {
    FUN_0e06e588(piVar3);
    *(int **)(iVar1 + 0x14) = piVar3;
    return;
  }
  *(int *)(DAT_0e06daa4 + 0x14) = iVar2;
  return;
}


