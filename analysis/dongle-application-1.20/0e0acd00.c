/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0acd00. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0e0acd00(uint *param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint local_38 [2];
  byte local_30;
  uint local_2c;
  
  iVar3 = 0;
  do {
    if (param_2 <= iVar3) {
      return param_3;
    }
    uVar4 = param_1[1];
    if (uVar4 != 0) {
      if (uVar4 < 0x20) {
        return 0xffffffea;
      }
      if ((uVar4 & 0x1f) != 0) {
        return 0xffffffea;
      }
      uVar5 = *param_1;
      if ((uVar5 & 0x1f) != 0) {
        return 0xffffffea;
      }
      uVar1 = FUN_0e0b1d52(uVar5);
      uVar4 = FUN_0e0b1d52(uVar4 + uVar5 + -1);
      if (uVar1 != uVar4) {
        return 0xffffffea;
      }
      if (uVar1 == 0xffffffea) {
        return 0xffffffea;
      }
      if ((int)param_3 <= (int)uVar1) {
        return 0xffffffea;
      }
      uVar6 = _DAT_e000eda0 | 0x1f;
      uVar4 = *param_1;
      uVar5 = (param_1[1] + uVar4) - 1;
      _DAT_e000ed98 = uVar1;
      if ((_DAT_e000ed9c & 0xffffffe0) == uVar4) {
        if (uVar6 == uVar5) {
          FUN_0e0b1d64(uVar1 & 0xff,param_1);
          goto LAB_0e0acd90;
        }
        _DAT_e000ed9c = _DAT_e000ed9c & 0x1f | param_1[1] + uVar4 & 0xffffffe0;
LAB_0e0acdb2:
        iVar2 = FUN_0e0b1d64(param_3 & 0xff,param_1);
      }
      else {
        _DAT_e000eda0 = uVar4 - 1 & 0xffffffe0 | _DAT_e000eda0 & 0x1f;
        if (uVar6 == uVar5) goto LAB_0e0acdb2;
        iVar2 = FUN_0e0b1d64(param_3 & 0xff,param_1);
        if (iVar2 == -0x16) {
          return 0xffffffea;
        }
        local_30 = (byte)_DAT_e000ed9c & 0x1f | (byte)((_DAT_e000eda0 >> 1 & 7) << 5);
        local_38[0] = *param_1 + param_1[1];
        local_2c = ((local_38[0] & 0xffffffe0) + (uVar6 - 1)) - uVar5 & 0xffffffe0;
        _DAT_e000ed98 = uVar1;
        iVar2 = FUN_0e0accdc(iVar2 + 1U & 0xff,local_38);
      }
      if (iVar2 == -0x16) {
        return 0xffffffea;
      }
      param_3 = iVar2 + 1;
    }
LAB_0e0acd90:
    iVar3 = iVar3 + 1;
    param_1 = param_1 + 3;
  } while( true );
}


