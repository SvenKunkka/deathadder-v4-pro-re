/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e085d08. Types and names are inferred; NOT original source. */

int FUN_0e085d08(int *param_1,uint param_2,uint param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  uVar8 = param_2 - 1 & param_2;
  iVar6 = *param_1;
  if (uVar8 == 0) {
    if (param_2 < 5) {
      iVar6 = FUN_0e085cb8(param_1,param_3);
      return iVar6;
    }
    uVar4 = 0;
    uVar3 = 4;
    uVar8 = param_2;
  }
  else {
    uVar4 = -param_2 & param_2;
    uVar3 = uVar4;
    if (3 < uVar4) {
      uVar3 = 4;
    }
  }
  if (((param_3 != 0) && (param_3 >> 3 < *(uint *)(iVar6 + 8))) &&
     (uVar3 = FUN_0e085bb4(iVar6,(param_3 + 0xb + uVar8) - uVar3 >> 3), uVar3 != 0)) {
    iVar5 = ((uVar4 + uVar3 * 8 + iVar6 + uVar8 + 3) / uVar8) * uVar8 - uVar4;
    uVar4 = (iVar5 + -4) - iVar6;
    uVar8 = (int)((param_3 + iVar5 + 7 & 0xfffffff8) - iVar6) >> 3;
    uVar9 = uVar4 >> 3;
    if (uVar3 < uVar4 >> 3) {
      uVar2 = FUN_0e085ab0(iVar6,uVar3,uVar9);
      iVar7 = iVar6 + uVar9 * 8;
      FUN_0e085b14(uVar2,uVar3);
      uVar1 = *(ushort *)(iVar7 + 2);
    }
    else {
      iVar7 = iVar6 + uVar9 * 8;
      uVar1 = *(ushort *)(iVar7 + 2);
    }
    if (uVar8 < uVar9 + (uVar1 >> 1)) {
      uVar2 = FUN_0e085ab0(iVar6,uVar9,uVar8);
      FUN_0e085b14(uVar2,uVar8);
    }
    *(ushort *)(iVar7 + 2) = *(ushort *)(iVar7 + 2) | 1;
    return iVar5;
  }
  return 0;
}


