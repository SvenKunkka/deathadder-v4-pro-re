/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d580. Types and names are inferred; NOT original source. */

int FUN_0e05d580(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_r2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *param_1;
  if ((param_2 != 0) && (param_2 >> 3 < *(uint *)(iVar4 + 8))) {
    uVar3 = param_2 + 0xb >> 3;
    iVar1 = FUN_0e05d47c(iVar4,uVar3,param_3,*(uint *)(iVar4 + 8),param_4);
    if (iVar1 != 0) {
      iVar5 = iVar4 + iVar1 * 8;
      if (uVar3 < *(ushort *)(iVar5 + 2) >> 1) {
        uVar2 = FUN_0e05d378(iVar4,iVar1,iVar1 + uVar3);
        FUN_0e05d3dc(uVar2,extraout_r2);
      }
      *(ushort *)(iVar5 + 2) = *(ushort *)(iVar5 + 2) | 1;
      return iVar4 + iVar1 * 8 + 4;
    }
  }
  return 0;
}


