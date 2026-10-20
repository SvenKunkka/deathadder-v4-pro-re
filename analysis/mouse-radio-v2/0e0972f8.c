/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0972f8. Types and names are inferred; NOT original source. */

longlong FUN_0e0972f8(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  longlong lVar12;
  
  if ((DAT_0e097468 & ~param_2) == 0) {
    if ((-1 < (int)param_2) || (iVar1 = FUN_0e09746c(), iVar1 == 0)) {
      lVar12 = FUN_0e0791ac(param_1,param_2,param_1,param_2);
      return lVar12;
    }
LAB_0e097316:
    FUN_0e09746c(param_1,param_2);
    return (ulonglong)DAT_0e0974c0 << 0x20;
  }
  if ((int)param_2 < 1) {
    if ((param_2 & 0x7fffffff) == 0 && param_1 == 0) {
      return CONCAT44(param_2,param_1);
    }
    if (param_2 != 0) goto LAB_0e097316;
  }
  else {
    iVar1 = (int)param_2 >> 0x14;
    if (iVar1 != 0) goto LAB_0e09736c;
  }
  iVar1 = 0;
  while (param_2 == 0) {
    iVar1 = iVar1 + -0x15;
    param_2 = param_1 >> 0xb;
    param_1 = param_1 << 0x15;
  }
  uVar2 = 0;
  for (; -1 < (int)(param_2 << 0xb); param_2 = param_2 << 1) {
    uVar2 = uVar2 + 1;
  }
  iVar1 = iVar1 - (uVar2 - 1);
  if (uVar2 != 0) {
    param_2 = param_2 | param_1 >> (0x20 - uVar2 & 0xff);
  }
  param_1 = param_1 << (uVar2 & 0xff);
LAB_0e09736c:
  bVar11 = -1 < iVar1 << 0x1f;
  iVar8 = 0;
  uVar2 = param_2 & 0xfffff | 0x100000;
  iVar10 = 0x16;
  iVar9 = 0;
  if (bVar11) {
    uVar2 = uVar2 << 1;
  }
  uVar4 = 0x200000;
  if (bVar11) {
    uVar2 = uVar2 - ((int)param_1 >> 0x1f);
    param_1 = param_1 << 1;
  }
  iVar6 = uVar2 * 2 - ((int)param_1 >> 0x1f);
  param_1 = param_1 << 1;
  do {
    iVar3 = iVar9 + uVar4;
    if (iVar3 <= iVar6) {
      iVar6 = iVar6 - iVar3;
      iVar9 = uVar4 + iVar3;
      iVar8 = iVar8 + uVar4;
    }
    iVar10 = iVar10 + -1;
    uVar4 = uVar4 >> 1;
    iVar6 = iVar6 * 2 - ((int)param_1 >> 0x1f);
    param_1 = param_1 << 1;
  } while (iVar10 != 0);
  iVar3 = 0x20;
  uVar4 = 0x80000000;
  uVar2 = 0;
  iVar10 = 0;
  do {
    uVar5 = uVar4 + iVar10;
    iVar7 = iVar9;
    if (iVar9 < iVar6) {
      if (((int)uVar5 < 0) && (-1 < (int)(uVar4 + uVar5))) {
LAB_0e097452:
        iVar7 = iVar9 + 1;
      }
      iVar6 = iVar6 - iVar9;
      if (param_1 < uVar5) {
        iVar6 = iVar6 + -1;
      }
LAB_0e0973ec:
      iVar10 = uVar4 + uVar5;
      param_1 = param_1 - uVar5;
      uVar2 = uVar2 + uVar4;
    }
    else if ((iVar9 == iVar6) && (uVar5 <= param_1)) {
      if (((int)uVar5 < 0) && (-1 < (int)(uVar4 + uVar5))) goto LAB_0e097452;
      iVar6 = 0;
      goto LAB_0e0973ec;
    }
    iVar3 = iVar3 + -1;
    uVar4 = uVar4 >> 1;
    iVar6 = iVar6 * 2 - ((int)param_1 >> 0x1f);
    param_1 = param_1 << 1;
    iVar9 = iVar7;
    if (iVar3 == 0) {
      if (iVar6 != 0 || param_1 != 0) {
        if (uVar2 == 0xffffffff) {
          iVar8 = iVar8 + 1;
          uVar2 = 0;
        }
        else {
          uVar2 = uVar2 + 1 & 0xfffffffe;
        }
      }
      uVar2 = uVar2 >> 1;
      if (iVar8 << 0x1f < 0) {
        uVar2 = uVar2 | 0x80000000;
      }
      return CONCAT44((iVar8 >> 1) + 0x3fe00000 + (iVar1 + -0x3ff >> 1) * 0x100000,uVar2);
    }
  } while( true );
}


