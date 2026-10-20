/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08a0c4. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0e08a0c4(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  if (param_2 != 0) {
    iVar5 = 0;
    iVar4 = param_1;
    do {
      uVar3 = *(uint *)(iVar4 + 4);
      if (uVar3 != 0) {
        if (uVar3 < 0x20) {
          return 0xffffffea;
        }
        if ((uVar3 & 0x1f) != 0) {
          return 0xffffffea;
        }
        uVar6 = *(uint *)(param_1 + iVar5 * 4);
        if ((uVar6 & 0x1f) != 0) {
          return 0xffffffea;
        }
        uVar1 = FUN_0e08a020(uVar6);
        uVar3 = FUN_0e08a020((uVar6 - 1) + uVar3);
        if (uVar1 != uVar3) {
          return 0xffffffea;
        }
        if (uVar1 == 0xffffffea) {
          return 0xffffffea;
        }
        if ((int)param_3 <= (int)uVar1) {
          return 0xffffffea;
        }
        uVar3 = *(uint *)(param_1 + iVar5 * 4);
        uVar6 = *(int *)(iVar4 + 4) + uVar3;
        uVar7 = _DAT_e000eda0 | 0x1f;
        uVar8 = uVar6 - 1;
        _DAT_e000ed98 = uVar1;
        if ((_DAT_e000ed9c & 0xffffffe0) == uVar3) {
          if (uVar7 == uVar8) {
            FUN_0e08a070(uVar1 & 0xff,iVar4,uVar6,0xe000ed00,param_4);
          }
          else {
            _DAT_e000ed9c = uVar6 & 0xffffffe0 | _DAT_e000ed9c & 0x1f;
            iVar2 = FUN_0e08a070(param_3 & 0xff,iVar4,_DAT_e000ed9c,0xe000ed00,param_4);
joined_r0x0e08a1e4:
            if (iVar2 == -0x16) {
              return 0xffffffea;
            }
            param_3 = iVar2 + 1;
          }
        }
        else {
          _DAT_e000eda0 = _DAT_e000eda0 & 0x1f | uVar3 - 1 & 0xffffffe0;
          if (uVar7 == uVar8) {
            iVar2 = FUN_0e08a070(param_3 & 0xff,iVar4,_DAT_e000eda0,0xe000ed00,param_4);
            goto joined_r0x0e08a1e4;
          }
          iVar2 = FUN_0e08a070(param_3 & 0xff,iVar4,_DAT_e000eda0,0xe000ed00,param_4);
          if (iVar2 == -0x16) {
            return 0xffffffea;
          }
          uVar3 = *(int *)(param_1 + iVar5 * 4) + *(int *)(iVar4 + 4) & 0xffffffe0;
          _DAT_e000ed98 = iVar2 + 1U & 0xff;
          if (((_DAT_e000ed90 & 0xffff) >> 8) - 1 < _DAT_e000ed98) {
            _DAT_e000ed98 = uVar1;
            return 0xffffffea;
          }
          _DAT_e000ed9c = _DAT_e000ed9c & 0x1f | uVar3;
          _DAT_e000eda0 = _DAT_e000eda0 & 0xe | ((uVar7 - 1) + uVar3) - uVar8 & 0xffffffe0 | 1;
          param_3 = _DAT_e000ed98 + 1;
        }
      }
      iVar5 = iVar5 + 3;
      iVar4 = iVar4 + 0xc;
    } while (iVar5 != param_2 * 3);
  }
  return param_3;
}


