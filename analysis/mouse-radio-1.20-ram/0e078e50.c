/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e078e50. Types and names are inferred; NOT original source. */

uint FUN_0e078e50(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  bool bVar9;
  bool bVar10;
  
  uVar3 = param_1 >> 0x17 & 0xff;
  bVar9 = uVar3 == 0;
  if (!bVar9) {
    param_4 = param_2 >> 0x17 & 0xff;
    bVar9 = param_4 == 0;
  }
  if (!bVar9) {
    bVar9 = uVar3 == 0xff;
  }
  if (!bVar9) {
    bVar9 = param_4 == 0xff;
  }
  if (bVar9) {
    param_4 = param_2 >> 0x17 & 0xff;
    if (uVar3 == 0xff || param_4 == 0xff) {
      bVar9 = param_1 == 0 || param_1 == 0x80000000;
      uVar2 = param_2;
      if (param_1 != 0 && param_1 != 0x80000000) {
        bVar9 = param_2 == 0;
        uVar2 = param_1;
      }
      if (!bVar9) {
        bVar9 = param_2 == 0x80000000;
      }
      uVar5 = uVar2;
      if (((bVar9) || ((uVar3 == 0xff && ((uVar2 & 0x7fffff) != 0)))) ||
         ((param_4 == 0xff && (uVar5 = param_2, (param_2 & 0x7fffff) != 0)))) {
        return uVar5 | 0x7fc00000;
      }
      uVar2 = uVar2 ^ param_2;
      goto LAB_0e078fa0;
    }
    if ((param_1 & 0x7fffffff) == 0 || (param_2 & 0x7fffffff) == 0) {
      return (param_1 ^ param_2) & 0x80000000;
    }
    bVar9 = uVar3 == 0;
    uVar2 = param_1 & 0x80000000;
    while( true ) {
      if (bVar9) {
        param_1 = param_1 << 1;
        bVar9 = (param_1 & 0x800000) == 0;
      }
      if (!bVar9) break;
      uVar3 = uVar3 - 1;
    }
    param_1 = param_1 | uVar2;
    bVar9 = param_4 == 0;
    uVar2 = param_2 & 0x80000000;
    while( true ) {
      if (bVar9) {
        param_2 = param_2 << 1;
        bVar9 = (param_2 & 0x800000) == 0;
      }
      if (!bVar9) break;
      param_4 = param_4 - 1;
    }
    param_2 = param_2 | uVar2;
  }
  iVar4 = uVar3 + param_4;
  uVar3 = param_1 ^ param_2;
  bVar9 = param_1 << 9 == 0;
  if (!bVar9) {
    param_2 = param_2 << 9;
    bVar9 = param_2 == 0;
  }
  if (bVar9) {
    if (param_1 << 9 == 0) {
      param_2 = param_2 << 9;
    }
    uVar2 = uVar3 & 0x80000000 | param_1 & 0x7fffff | param_2 >> 9;
    bVar10 = SBORROW4(iVar4,0x7f);
    iVar6 = iVar4 + -0x7f;
    bVar9 = iVar6 == 0;
    iVar7 = iVar6;
    if (!bVar9 && 0x7e < iVar4) {
      bVar10 = SBORROW4(0xff,iVar6);
      iVar7 = 0xff - iVar6;
      bVar9 = iVar6 == 0xff;
    }
    if (!bVar9 && iVar7 < 0 == bVar10) {
      return uVar2 | iVar6 * 0x800000;
    }
    uVar2 = uVar2 | 0x800000;
    uVar8 = 0;
    bVar10 = SBORROW4(iVar6,1);
    uVar5 = iVar4 - 0x80;
    bVar9 = uVar5 == 0;
    uVar3 = uVar5;
  }
  else {
    lVar1 = (ulonglong)((param_1 & 0x7fffff) << 4 | 0x8000000) *
            (ulonglong)(param_2 >> 5 | 0x8000000);
    bVar9 = (uint)((ulonglong)lVar1 >> 0x20) < 0x800000;
    if (bVar9) {
      lVar1 = lVar1 * 2;
    }
    uVar8 = (uint)lVar1;
    uVar2 = uVar3 & 0x80000000 | (uint)((ulonglong)lVar1 >> 0x20);
    uVar5 = (iVar4 + -0x7f) - (uint)bVar9;
    bVar10 = SBORROW4(uVar5,0xfd);
    bVar9 = uVar5 == 0xfd;
    uVar3 = uVar5 - 0xfd;
    if (uVar5 < 0xfe) {
      uVar2 = uVar2 + uVar5 * 0x800000 + (uint)(0x7fffffff < uVar8);
      if (uVar8 == 0x80000000) {
        uVar2 = uVar2 & 0xfffffffe;
      }
      return uVar2;
    }
  }
  if (bVar9 || (int)uVar3 < 0 != bVar10) {
    if (-0x19 < (int)uVar5) {
      uVar3 = (uVar2 << 1) >> (-uVar5 & 0xff);
      uVar5 = uVar2 << (uVar5 + 0x20 & 0xff);
      uVar3 = ((uint)((uVar2 & 0x80000000) != 0) << 0x1f | uVar3 >> 1) + (uint)((byte)uVar3 & 1);
      if (uVar8 == 0 && (uVar5 & 0x7fffffff) == 0) {
        uVar3 = uVar3 & ~(uVar5 >> 0x1f);
      }
      return uVar3;
    }
    return uVar2 & 0x80000000;
  }
LAB_0e078fa0:
  return uVar2 & 0x80000000 | 0x7f800000;
}


