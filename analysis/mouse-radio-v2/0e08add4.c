/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08add4. Types and names are inferred; NOT original source. */

uint FUN_0e08add4(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined1 auStack_20 [4];
  uint local_1c;
  uint local_18;
  uint local_14;
  
  if ((param_1 < 5) && (iVar2 = *(int *)(DAT_0e08ae74 + param_1 * 4), iVar2 != 0)) {
    local_14 = (*DAT_0e08ae78 & 7) >> 2;
    if ((int)(*DAT_0e08ae78 << 0x1d) < 0) {
      uVar1 = 0xfffffffb;
    }
    else {
      local_1c = (uint)*DAT_0e08ae7c;
      if (local_1c == 0) {
        local_18 = 1;
        local_14 = local_1c;
        uVar1 = FUN_0e086784(iVar2,auStack_20);
        if (-1 < (int)uVar1) {
          do {
          } while ((local_18 & 3) != 0);
          return local_14;
        }
      }
      else {
        local_1c = DAT_0e08ae80;
        iVar3 = iVar2 + 0x24;
        local_18 = 3;
        FUN_0e094d84(iVar3,DAT_0e08ae80,0xffffffff,0xffffffff);
        uVar4 = FUN_0e086784(iVar2,auStack_20);
        uVar1 = (uint)uVar4;
        if ((int)uVar1 < 0) {
          FUN_0e094e80(iVar3);
        }
        else {
          FUN_0e0950f0(iVar2 + 0x38,(int)((ulonglong)uVar4 >> 0x20),0xffffffff,0xffffffff);
          uVar1 = *(uint *)(iVar2 + 0x48);
          FUN_0e094e80(iVar3);
        }
      }
    }
  }
  else {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}


