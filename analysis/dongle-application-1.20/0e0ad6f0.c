/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ad6f0. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0e0ad6f0(uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  uint uStack_20;
  undefined1 *local_1c;
  uint local_18;
  uint local_14;
  
  if ((param_1 < 5) && (iVar2 = *(int *)(&DAT_0e0b3b88 + param_1 * 4), iVar2 != 0)) {
    local_14 = (_DAT_2f0119f0 & 7) >> 2;
    if ((int)(_DAT_2f0119f0 << 0x1d) < 0) {
      uVar1 = 0xfffffffb;
    }
    else {
      local_1c = (undefined1 *)(uint)DAT_2f011bd9;
      uStack_20 = param_1;
      if (local_1c == (undefined1 *)0x0) {
        local_18 = 1;
        local_14 = (uint)local_1c;
        uVar1 = FUN_0e0b1076(iVar2,&uStack_20);
        if (-1 < (int)uVar1) {
          do {
            uVar1 = local_14;
          } while ((local_18 & 3) != 0);
        }
      }
      else {
        local_1c = &LAB_0e0b1da4_1;
        local_18 = 3;
        FUN_0e0af598(iVar2 + 0x24,_DAT_2f0119f0 << 0x1d,0xffffffff,0xffffffff);
        uVar3 = FUN_0e0b1076(iVar2,&uStack_20);
        uVar1 = (uint)uVar3;
        if (-1 < (int)uVar1) {
          FUN_0e0af748(iVar2 + 0x38,(int)((ulonglong)uVar3 >> 0x20),0xffffffff,0xffffffff);
          uVar1 = *(uint *)(iVar2 + 0x48);
        }
        FUN_0e0af688(iVar2 + 0x24);
      }
    }
  }
  else {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}


