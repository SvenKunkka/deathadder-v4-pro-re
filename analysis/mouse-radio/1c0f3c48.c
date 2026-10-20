/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f3c48. Types and names are inferred; NOT original source. */

uint FUN_1c0f3c48(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined2 local_1c;
  undefined1 local_1a;
  
  piVar4 = *(int **)(param_1 + 0x10);
  iVar3 = *piVar4;
  uVar2 = *(uint *)(iVar3 + 0x14);
  uVar1 = (uint)(param_3 - *(int *)(iVar3 + 0x10)) / uVar2;
  if ((uVar1 < *(uint *)(iVar3 + 0x18)) && (param_3 == uVar1 * uVar2 + *(int *)(iVar3 + 0x10) + 4))
  {
    if (-1 < (int)uVar1) {
      local_1a = (undefined1)uVar1;
      local_1c = 1;
      FUN_1c100d84(piVar4 + 0x1e,uVar2,0xffffffff,0xffffffff);
      uVar1 = FUN_1c0f440c(iVar3,piVar4 + 2,&local_1c,3);
      FUN_1c100e80(piVar4 + 0x1e);
    }
    return uVar1;
  }
  return 0xffffffea;
}


