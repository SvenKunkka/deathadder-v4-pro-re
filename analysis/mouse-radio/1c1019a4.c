/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c1019a4. Types and names are inferred; NOT original source. */

void FUN_1c1019a4(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  bool bVar4;
  
  iVar1 = DAT_1c1019e0;
  piVar3 = *(int **)(DAT_1c1019e0 + 0x1c);
  if ((piVar3 == (int *)(DAT_1c1019e0 + 0x1c)) || (piVar3 == (int *)0x0)) {
    piVar3 = *(int **)(DAT_1c1019e0 + 0xc);
  }
  iVar2 = *(int *)(DAT_1c1019e0 + 8);
  if (((((param_1 != 0) || ((*(byte *)(iVar2 + 0xd) & 0x1f) != 0)) ||
       (*(int *)((int)piVar3 + 0x18) != 0)) || (*(ushort *)(iVar2 + 0xe) < 0x80)) &&
     (bVar4 = piVar3 != (int *)iVar2, iVar2 = (int)piVar3, bVar4)) {
    FUN_1c102440(piVar3);
    *(int **)(iVar1 + 0x18) = piVar3;
    return;
  }
  *(int *)(DAT_1c1019e0 + 0x18) = iVar2;
  return;
}


