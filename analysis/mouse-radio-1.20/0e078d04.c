/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e078d04. Types and names are inferred; NOT original source. */

uint FUN_0e078d04(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  
  uVar5 = param_1 << 1;
  bVar8 = uVar5 == 0;
  if (!bVar8) {
    param_4 = param_2 << 1;
    bVar8 = param_4 == 0;
  }
  if (!bVar8) {
    bVar8 = uVar5 == param_4;
  }
  iVar1 = (int)uVar5 >> 0x18;
  if (!bVar8) {
    bVar8 = iVar1 == -1;
  }
  if (!bVar8) {
    bVar8 = (int)param_4 >> 0x18 == -1;
  }
  if (bVar8) {
    iVar2 = (int)(param_2 << 1) >> 0x18;
    if (iVar1 == -1 || iVar2 == -1) {
      uVar5 = param_2;
      if (iVar1 == -1) {
        uVar5 = param_1;
      }
      if (iVar1 != -1 || iVar2 != -1) {
        param_2 = uVar5;
      }
      if (((uVar5 & 0x7fffff) != 0 || (param_2 & 0x7fffff) != 0) || uVar5 != param_2) {
        uVar5 = uVar5 | 0x400000;
      }
      return uVar5;
    }
    if (((param_1 ^ param_2) & 0x7fffffff) != 0) {
      if (uVar5 == 0) {
        param_1 = param_2;
      }
      return param_1;
    }
    if (param_1 != param_2) {
      return 0;
    }
    if ((uVar5 & 0xff000000) == 0) {
      uVar5 = param_1 << 1;
      if ((param_1 & 0x80000000) != 0) {
        uVar5 = uVar5 | 0x80000000;
      }
      return uVar5;
    }
    if (uVar5 < 0xfe000000) {
      return param_1 + 0x800000;
    }
    param_1 = param_1 & 0x80000000;
LAB_0e0794b2:
    return param_1 | 0x7f800000;
  }
  uVar6 = (param_1 & 0x7fffffff) >> 0x17;
  param_4 = param_4 >> 0x18;
  uVar5 = param_4 - uVar6;
  uVar3 = param_2;
  uVar7 = uVar6;
  if (uVar5 != 0 && uVar6 <= param_4) {
    uVar7 = uVar6 + uVar5;
    uVar3 = param_1;
    param_1 = param_2;
  }
  if (param_4 < uVar6) {
    uVar5 = -uVar5;
  }
  if (0x19 < uVar5) {
    return param_1;
  }
  uVar6 = param_1 & 0xffffff | 0x800000;
  if ((param_1 & 0x80000000) != 0) {
    uVar6 = -uVar6;
  }
  uVar4 = uVar3 & 0xffffff | 0x800000;
  if ((uVar3 & 0x80000000) != 0) {
    uVar4 = -uVar4;
  }
  if (uVar7 == uVar5) {
    uVar4 = uVar4 ^ 0x800000;
    if (uVar7 == 0) {
      uVar6 = uVar6 ^ 0x800000;
      uVar7 = 1;
    }
    else {
      uVar5 = uVar5 - 1;
    }
  }
  uVar6 = uVar6 + ((int)uVar4 >> (uVar5 & 0xff));
  uVar4 = uVar4 << (0x20 - uVar5 & 0xff);
  param_1 = uVar6 & 0x80000000;
  if ((int)uVar6 < 0) {
    bVar8 = uVar4 != 0;
    uVar4 = -uVar4;
    uVar6 = -uVar6 - (uint)bVar8;
  }
  if (uVar6 < 0x800000) {
    uVar5 = uVar4 & 0x80000000;
    uVar4 = uVar4 << 1;
    uVar6 = uVar6 * 2 + (uint)(uVar5 != 0);
    uVar5 = uVar7 - 2;
    if (uVar7 - 1 == 0 || uVar6 < 0x800000) {
      uVar7 = LZCOUNT(uVar6) - 8;
      uVar6 = uVar6 << (uVar7 & 0xff);
      if ((int)uVar5 < (int)uVar7) {
        uVar6 = uVar6 >> (-(uVar5 - uVar7) & 0xff);
      }
      else {
        uVar6 = uVar6 + (uVar5 - uVar7) * 0x800000;
      }
      return uVar6 | param_1;
    }
  }
  else {
    uVar5 = uVar7 - 1;
    if (0xffffff < uVar6) {
      uVar5 = uVar6 & 1;
      uVar6 = uVar6 >> 1;
      uVar4 = (uint)(uVar5 != 0) << 0x1f | uVar4 >> 1;
      uVar5 = uVar7;
      if (0xfd < uVar7) goto LAB_0e0794b2;
    }
  }
  uVar6 = uVar6 + uVar5 * 0x800000 + (uint)(0x7fffffff < uVar4);
  if (uVar4 == 0x80000000) {
    uVar6 = uVar6 & 0xfffffffe;
  }
  return uVar6 | param_1;
}


