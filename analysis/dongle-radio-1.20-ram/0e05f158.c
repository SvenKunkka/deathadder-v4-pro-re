/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05f158. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05f158(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  piVar1 = *(int **)(param_1 + 0x10);
  if (DAT_230071e7 == '\0') {
    FUN_0e06d524(&DAT_23002250);
    FUN_0e06d530(&DAT_23002250,&DAT_23010800,0x200,0xffffffff,0);
    DAT_230071e7 = '\x01';
  }
  *piVar1 = iVar2;
  *(bool *)(piVar1 + 0x3f) = *(uint *)(iVar2 + 0x10) < *(uint *)(iVar2 + 0x1c);
  FUN_0e06cd9c(piVar1 + 0x1e);
  FUN_0e06d3f0(piVar1 + 0x23,&LAB_0e05f618_1);
  FUN_0e06d0b4(piVar1 + 0x27,0,1);
  piVar1[0x3c] = -1;
  piVar1[0x3d] = -1;
  piVar1[0x3b] = -1;
  return 0;
}


