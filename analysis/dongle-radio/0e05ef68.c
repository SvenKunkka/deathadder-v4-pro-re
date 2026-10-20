/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05ef68. Types and names are inferred; NOT original source. */

uint * FUN_0e05ef68(int *param_1,uint param_2,uint *param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar4 = param_1[2];
  if (param_2 < uVar4) {
    iVar3 = *param_1;
    iVar2 = param_1[1];
    puVar5 = (uint *)(iVar2 * param_2 + iVar3);
    if (param_3 == (uint *)0x0) {
      return puVar5 + 1;
    }
    if (param_4 != 0) {
      FUN_0e067414(puVar5,4);
      DataMemoryBarrier(0x1b);
      iVar3 = *param_1;
      iVar2 = param_1[1];
      uVar4 = param_1[2];
    }
    uVar1 = *puVar5;
    if ((uVar1 <= iVar2 * uVar4 - 4) && (uVar1 + 4 + (int)puVar5 <= iVar3 + iVar2 * uVar4)) {
      *param_3 = uVar1;
      puVar5 = puVar5 + 1;
      if (param_4 == 0) {
        return puVar5;
      }
      FUN_0e067414(puVar5);
      DataMemoryBarrier(0x1b);
      return puVar5;
    }
  }
  return (uint *)0x0;
}


