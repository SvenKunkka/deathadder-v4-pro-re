/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e088850. Types and names are inferred; NOT original source. */

int FUN_0e088850(undefined4 param_1,int param_2)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  int local_1c;
  
  if (param_2 == -1) {
    uVar8 = 0xffffffff;
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = param_2 << 5;
    uVar8 = 0;
  }
  sVar1 = FUN_0e0887b4(param_1,&local_1c);
  if (DAT_23006d14 != 0) {
    uVar2 = FUN_0e097620();
    uVar7 = 0;
    uVar6 = *(uint *)(DAT_23006d14 + 4) - uVar2;
    if (uVar2 < *(uint *)(DAT_23006d14 + 4)) {
      if (uVar6 == 0) goto LAB_0e088902;
    }
    else {
      bVar9 = uVar6 != 0;
      uVar6 = uVar6 - 1;
      uVar7 = (uint)bVar9;
    }
    if ((uVar8 == 0xffffffff && uVar4 == 0xffffffff) ||
       ((int)((uVar8 - uVar7) - (uint)(uVar4 < uVar6)) < 0 ==
        (SBORROW4(uVar8,uVar7) != SBORROW4(uVar8 - uVar7,(uint)(uVar4 < uVar6)))))
    goto joined_r0x0e0888aa;
  }
LAB_0e088902:
  uVar7 = uVar8;
  uVar6 = uVar4;
joined_r0x0e0888aa:
  while( true ) {
    do {
      sVar1 = sVar1 + -1;
      iVar3 = (int)sVar1;
      if (iVar3 == -1) {
        return 0;
      }
      iVar5 = local_1c + iVar3 * 0xc;
      iVar3 = FUN_0e088800(*(undefined1 *)(local_1c + iVar3 * 0xc),*(undefined1 *)(iVar5 + 1));
    } while ((iVar3 != 0) || ((-1 < (int)DAT_23000e88 && (DAT_23000e88 <= *(uint *)(iVar5 + 8)))));
    if (uVar7 == 0xffffffff && uVar6 == 0xffffffff) break;
    if ((int)(uint)(uVar6 < *(uint *)(iVar5 + 8) + *(int *)(iVar5 + 4)) <= (int)uVar7) {
      return iVar5;
    }
  }
  return iVar5;
}


