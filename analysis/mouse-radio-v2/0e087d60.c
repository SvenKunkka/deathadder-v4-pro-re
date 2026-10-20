/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e087d60. Types and names are inferred; NOT original source. */

uint FUN_0e087d60(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  iVar1 = *param_1;
  if (param_2 < *(uint *)(iVar1 + 0x24)) {
    iVar6 = *(int *)(iVar1 + 0x1c);
    uVar3 = *(uint *)(iVar1 + 0x20);
    iVar4 = uVar3 * *(uint *)(iVar1 + 0x24);
    uVar7 = *(uint *)(iVar6 + uVar3 * param_2);
    uVar5 = iVar4 + iVar6;
    if ((uVar7 <= iVar4 - 4U) && (iVar6 + uVar3 * param_2 + uVar7 + 4 <= uVar5)) {
      uVar7 = uVar3 + 3 + uVar7;
      uVar2 = param_2;
      if ((uVar3 <= uVar7) &&
         (uVar2 = FUN_0e086410(*(undefined4 *)(iVar1 + 0x28),uVar7 / uVar3,param_2,uVar5,param_4),
         -1 < (int)uVar2)) {
        FUN_0e0950a8(param_1 + 0x27);
        uVar2 = param_2;
      }
      return uVar2;
    }
  }
  return 0xffffffea;
}


