/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f3cb0. Types and names are inferred; NOT original source. */

uint FUN_1c0f3cb0(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  
  iVar1 = *param_1;
  iVar8 = *(int *)(iVar1 + 0x1c);
  uVar7 = *(uint *)(iVar1 + 0x20);
  uVar4 = (uint)(param_2 - iVar8) / uVar7;
  if (uVar4 < *(uint *)(iVar1 + 0x24)) {
    iVar10 = uVar4 * uVar7;
    iVar5 = uVar7 * *(uint *)(iVar1 + 0x24);
    uVar9 = *(uint *)(iVar8 + iVar10);
    uVar6 = iVar5 + iVar8;
    if (((uVar9 <= iVar5 - 4U) && (uVar9 + 4 + iVar8 + iVar10 <= uVar6)) &&
       (param_2 == iVar8 + iVar10 + 4)) {
      uVar2 = uVar4;
      if (-1 < (int)uVar4) {
        uVar3 = (uVar7 + 3 + uVar9) / uVar7;
        uVar9 = uVar4;
        if (-1 < param_3) {
          uVar6 = (param_3 + 3 + uVar7) / uVar7;
          if (uVar3 < uVar6) {
            return 0xffffffea;
          }
          *(int *)(iVar8 + iVar10) = param_3;
          uVar9 = uVar4 + uVar6;
          uVar3 = uVar3 - uVar6;
        }
        if ((uVar3 != 0) &&
           (uVar2 = FUN_1c0f2410(*(undefined4 *)(iVar1 + 0x28),uVar3,uVar9,uVar6,param_4),
           -1 < (int)uVar2)) {
          FUN_1c1010a8(param_1 + 0x27);
          return uVar4;
        }
      }
      return uVar2;
    }
  }
  return 0xffffffea;
}


