/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0889dc. Types and names are inferred; NOT original source. */

int FUN_0e0889dc(undefined4 param_1,int param_2)

{
  uint *puVar1;
  int *piVar2;
  uint *puVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  int local_1c;
  
  if (param_2 == -1) {
    uVar11 = 0xffffffff;
    uVar7 = 0xffffffff;
  }
  else {
    uVar7 = param_2 << 5;
    uVar11 = 0;
  }
  sVar4 = FUN_0e088940(param_1,&local_1c);
  piVar2 = DAT_0e088a94;
  if (*DAT_0e088a94 != 0) {
    uVar5 = FUN_0e0977a0();
    uVar10 = 0;
    uVar9 = *(uint *)(*piVar2 + 4) - uVar5;
    if (uVar5 < *(uint *)(*piVar2 + 4)) {
      if (uVar9 == 0) goto LAB_0e088a8e;
    }
    else {
      bVar12 = uVar9 != 0;
      uVar9 = uVar9 - 1;
      uVar10 = (uint)bVar12;
    }
    puVar1 = DAT_0e088a98;
    puVar3 = DAT_0e088a98;
    if ((uVar11 == 0xffffffff && uVar7 == 0xffffffff) ||
       ((int)((uVar11 - uVar10) - (uint)(uVar7 < uVar9)) < 0 ==
        (SBORROW4(uVar11,uVar10) != SBORROW4(uVar11 - uVar10,(uint)(uVar7 < uVar9)))))
    goto joined_r0x0e088a36;
  }
LAB_0e088a8e:
  puVar1 = DAT_0e088a98;
  puVar3 = DAT_0e088a98;
  uVar10 = uVar11;
  uVar9 = uVar7;
joined_r0x0e088a36:
  while( true ) {
    do {
      do {
        DAT_0e088a98 = puVar3;
        puVar3 = DAT_0e088a98;
        sVar4 = sVar4 + -1;
        iVar6 = (int)sVar4;
        if (iVar6 == -1) {
          DAT_0e088a98 = puVar1;
          return 0;
        }
        iVar8 = local_1c + iVar6 * 0xc;
        DAT_0e088a98 = puVar1;
        iVar6 = FUN_0e08898c(*(undefined1 *)(local_1c + iVar6 * 0xc),*(undefined1 *)(iVar8 + 1));
        puVar1 = DAT_0e088a98;
      } while (iVar6 != 0);
    } while ((-1 < (int)*puVar3) && (*puVar3 <= *(uint *)(iVar8 + 8)));
    if (uVar10 == 0xffffffff && uVar9 == 0xffffffff) break;
    if ((int)(uint)(uVar9 < *(uint *)(iVar8 + 8) + *(int *)(iVar8 + 4)) <= (int)uVar10) {
      return iVar8;
    }
  }
  return iVar8;
}


